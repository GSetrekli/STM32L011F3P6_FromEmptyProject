
#include <stdint.h>
#include <stdio.h>

#define GPIOA_BASE_ADDR			0x50000000UL
#define GPIO_MODER_OFFSET		0x00
#define GPIO_TYPER_OFFSET		0x04
#define GPIO_OSPEEDR_OFFSET		0x08
#define GPIO_PUPDR_OFFSET		0x0C
#define GPIO_ODR_OFFSET			0x14
#define RCC_BASE_ADDR			0x40021000UL
//#define RCC_AHB1RSTR_OFFSET	0x10
#define RCC_IOPENR_OFFSET		0x2C


void delay(uint32_t n)
{
	for(uint32_t i=0; i<n; i++);
}

int main(void)
{

  //uint32_t pRccAhb1rstrReg=(uint32_t)(RCC_BASE_ADDR+RCC_AHB1RSTR_OFFSET);
 // *pRccAhb1rstrReg |=(1<<3);

  uint32_t *pRccIOPEnrReg=(uint32_t*)(RCC_BASE_ADDR+RCC_IOPENR_OFFSET);
  *pRccIOPEnrReg |=(1<<0);

  uint32_t *pGPIOAModeReg=(uint32_t*)(GPIOA_BASE_ADDR+GPIO_MODER_OFFSET);
  *pGPIOAModeReg &= ~(0x3<<4);
  *pGPIOAModeReg |= (0x1<<4); //PA2 as Output.

  uint32_t *pGPIOATypeReg=(uint32_t*)(GPIOA_BASE_ADDR+GPIO_TYPER_OFFSET);
  *pGPIOATypeReg &= ~(1<<2); //push pull

  uint32_t *pGPIOAOSpeedReg=(uint32_t*)(GPIOA_BASE_ADDR+GPIO_OSPEEDR_OFFSET);
  *pGPIOAOSpeedReg &= ~(0x3<<4);
  *pGPIOAOSpeedReg |= (0x2<<4); //Fast

  uint32_t *pGPIOAPupdrReg=(uint32_t*)(GPIOA_BASE_ADDR+GPIO_PUPDR_OFFSET);
  *pGPIOAPupdrReg &= ~(0x3<<4); //no pull-up pull-down

  uint32_t *pGPIOAOdrReg=(uint32_t*)(GPIOA_BASE_ADDR+GPIO_ODR_OFFSET);
  *pGPIOAOdrReg &= ~(1<<2);
  *pGPIOAOdrReg |= (1<<2);
  delay(700000);
  while(1)
  {

	  *pGPIOAOdrReg ^= (1<<2);
	  delay(50000);
  }

	return 0;
}
