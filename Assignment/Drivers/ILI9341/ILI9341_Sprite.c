#include "ILI9341_Sprite.h"
#include "stm32f7xx_hal.h"

/*วาด SPRITE ซึ่งเป็น bitmap array 1 มิติ เก็บค่าสีขนาด 16-bits ของ pixels ต่าง ๆ
จำนวน WIDTH x HEIGHT ค่า โดยวาดที่จุด (X, Y) ของหน้าจอ
ตำแหน่ง (X, Y) จะอยู่ด้านล่างขวาของภาพ
*/
void ILI9341_Draw_Image_Burst(const uint16_t *SPRITE, uint16_t Size)
{
    // SEND Colours
    uint32_t Buffer_Size = 0;
    uint32_t pixels = Size - 1;
    uint16_t chifted;
    if ((Size * 2) < 500)
    {
        Buffer_Size = Size;
    }
    else
    {
        Buffer_Size = 500;
    }
    HAL_GPIO_WritePin(GPIOC, DC_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOC, CS_Pin, GPIO_PIN_RESET);

    uint32_t Sending_Size = Size * 2;
    uint32_t Sending_in_Block = Sending_Size / Buffer_Size;
    uint32_t Remainder_from_block = Sending_Size % Buffer_Size;
    uint8_t burst_buffer[Sending_in_Block][Buffer_Size];
    uint8_t remaider_buffer[Remainder_from_block];
    for (uint16_t i = 0; i < Sending_in_Block; i++)
    {
        for (uint16_t j = 0; j < Buffer_Size; j += 2)
        {
            chifted = SPRITE[pixels] >> 8;
            burst_buffer[i][j] = chifted;
            burst_buffer[i][j + 1] = SPRITE[pixels];
            pixels--;
        }
    }

    if (Remainder_from_block)
    {
        for (uint16_t j = 0; j < Remainder_from_block; j += 2)
        {
            chifted = SPRITE[pixels] >> 8;
            remaider_buffer[j] = chifted;
            remaider_buffer[j + 1] = SPRITE[pixels];
            pixels--;
        }
    }
    if (Sending_in_Block != 0)
    {
        for (uint16_t i = 0; i < Sending_in_Block; i++)
        {
            // HAL_SPI_Transmit(&hspi5, &burst_buffer[i], Buffer_Size, 10);
            HAL_SPI_Transmit(&hspi5, burst_buffer[i], Buffer_Size, 10);
        }
    }

    if (Remainder_from_block)
        HAL_SPI_Transmit(&hspi5, remaider_buffer, Remainder_from_block, 10);

    HAL_GPIO_WritePin(GPIOC, CS_Pin, GPIO_PIN_SET);
}

void ILI9341_Draw_Sprite(const uint16_t *SPRITE, uint16_t WIDTH, uint16_t HEIGHT, uint16_t X, uint16_t Y)
{
    if ((X >= ILI9341_SCREEN_WIDTH) || (Y >= ILI9341_SCREEN_HEIGHT))
        return;
    if ((X + WIDTH - 1) >= ILI9341_SCREEN_WIDTH)
    {
        WIDTH = ILI9341_SCREEN_WIDTH - X;
    }
    if ((Y + HEIGHT - 1) >= ILI9341_SCREEN_HEIGHT)
    {
        HEIGHT = ILI9341_SCREEN_HEIGHT - Y;
    }
    ILI9341_Set_Address(X, Y, X + WIDTH - 1, Y + HEIGHT - 1);
    ILI9341_Draw_Image_Burst(SPRITE, WIDTH * HEIGHT);
}
