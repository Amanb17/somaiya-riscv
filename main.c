#include <ch32v00x.h>
#include <debug.h>

void GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0}; //structure variable used for the GPIO configuration

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); // to Enable the clock for Port D

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_4 ; // Defines which Pin to configure
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Defines Output Type
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 ; // Defines which Pin to configure
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Defines Output Type
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Defines speed
    GPIO_Init(GPIOD, &GPIO_InitStructure);

}


int main(void)
{
    uint8_t echo = 0;
    uint8_t status = 1;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config();

    while(1)
    {
        status = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_0);
        if (status == 0)
        {
            while(1)
            {
                GPIO_WriteBit(GPIOD, GPIO_Pin_2, SET);
                Delay_Ms(10);
                echo = GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_4);
                if (echo == 1){
                    GPIO_WriteBit(GPIOD, GPIO_Pin_3, SET);
                    Delay_Ms(2000);
                    GPIO_WriteBit(GPIOD, GPIO_Pin_3, RESET);
                    Delay_Ms(2000);
                }
                GPIO_WriteBit(GPIOD, GPIO_Pin_2, RESET);
                Delay_Ms(2);
            }
        }
    }
}
