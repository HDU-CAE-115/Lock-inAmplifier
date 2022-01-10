#ifndef AD719X_H_ 
#define AD719X_H_

#define V_REF 2.5

#include "stdio.h"
#include "stm32g4xx_hal.h"
#include "spi.h"
#include "Usermain.h"

void AD7190_RST();
void AD7190_WR_ConfigReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);
void AD7190_WR_ModeReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);
void AD7190_WaitRDYGoLow(void);
double AD7190_ReadDataC(void);

#endif