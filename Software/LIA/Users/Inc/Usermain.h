#include "stm32g4xx_hal.h"
#include "stdio.h"
#include "gpio.h"
#include "spi.h"
#include "usart.h"
#include "math.h"
#include "ad7190.h"

void AD7190_RST();
void AD7190_WR_ConfigReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);
void AD7190_WR_ModeReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);
