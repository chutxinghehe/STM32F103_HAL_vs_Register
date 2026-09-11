#include "stm32f10x.h"


int main()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;
	
	GPIOC->CRH &= ~(0xFU << ((13 - 8) * 4)); 
	// Clear 4 bit 
	
    GPIOC->CRH |=  (0x3U << ((13 - 8) * 4)); 
	// MODE13 = 11 (Output 50MHz), CNF13 = 00 (Push-Pull)
	
	while(1) {
        // Toggle PC13 dùng ODR
        GPIOC->ODR ^= GPIO_ODR_ODR13;
    }
}	








