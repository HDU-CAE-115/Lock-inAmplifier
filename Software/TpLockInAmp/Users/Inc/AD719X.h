#ifndef AD719X_H_ 
#define AD719X_H_

#include "stdio.h"
#include "stm32g4xx_hal.h"
#include "spi.h"
#include "Usermain.h"

#define V_REF 2.5
#define MAXDATASIZE 2048
/*     ͨѶ�Ĵ���8λ��ֻд,RS2,RS1,RS0=0,0,0;                                       */
/*     ͨѶ�Ĵ���λ���ܲ����궨��                                                   */
/*     +------------+------------+------------+------------+------------+---------------+------------+------------+     */
/*     |  CR7  |  CR6  |  CR5  |  CR4  |  CR3  |  CR2    |  CR1  |  CR0  |     */
/*     +------------+------------+------------+------------+------------+---------------+------------+------------+     */
/*     | WEN(0)| R/W(0) | RS2(0) | RS1(0)| RS0(0) |CREAD(0)|   0(0)  |  0(0)  |     */
/*     +------------+------------+------------+------------+------------+---------------+------------+------------+     */


/*     ״̬�Ĵ���8λ��ֻ��,RS2,RS1,RS0=0,0,0;�ϵ�/��λ=0x80                       */
/*     ״̬�Ĵ���λ����ȡֵ�궨��                                                 */
/*     +------------+------------+-------------+----------------+-----------+------------+------------+------------+   */
/*     |  SR7  |  SR6  |  SR5   |  SR4    |  SR3  |  SR2  |  SR1  |  SR0  |   */
/*     +------------+------------+-------------+----------------+-----------+------------+------------+------------+   */
/*     | RDY(1)| ERR(0)|NOREF(0)|PARITY(0) | 0(0)   |CHD2(0)|CHD1(0)|CHD0(0)|   */
/*     +------------+------------+-------------+----------------+-----------+------------+------------+------------+   */


/*   ģʽ�Ĵ���24λ���ɶ���д,RS2,RS1,RS0=0,0,1;�ϵ�/��λ=0x080060            */
/*   ģʽ�Ĵ���λ���ܲ����궨��                                               */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   |  MR23  | MR22 |  MR21  |  MR20    |   MR19  |  MR18  | MR17 | MR16 |   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   | MD2(0)  |MD1(0) | MD0(0) |DAT_STA(0)| CLK1(0)  | CLK0(0)  | 0(0)   | 0(0)  |   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   |  MR15  | MR14 |  MR13  |  MR12    |   MR11  |  MR10  | MR9  | MR8  |   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   |SINC3(0) | 0(0)   |ENPAR(0)|CLK_DIV(0) |SINGLE(0)|REJ60(0) |FS9(0)  |FS8(0)|   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   |  MR7   | MR6  |  MR5   |  MR4     |   MR3   |   MR2  | MR1  | MR0  |   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   | FS7(0)  |FS6(0) | FS5(0)   |  FS4(0)  |  FS3(0)   | FS2(0)  | FS1(0) |FS0(0)|   */
/*   +--------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */


/*    ���üĴ�����24λ���ɶ���д,RS2,RS1,RS0=0,1,0;�ϵ�/��λ=0x000117         */
/*    ���üĴ���λ���ܲ����궨��                                              */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    | CON23 | CON22 | CON21 |  CON20   | CON19   | CON18 | CON17| CON16|    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    |CHOP(0) |   0(0) | 0(0)     |REFSEL(0)|  0(0)     |  0(0)    |  0(0)  |  0(0)  |    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    | CON15 | CON14 | CON13 |  CON12  | CON11    | CON10 | CON9  | CON8  |    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    | CH7(0) | CH6(0) | CH5(0) |   CH4(0)  |  CH3(0)  | CH2(0)  | CH1(0)| CH0(0)|    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    | CON7  | CON6 |  CON5  |   CON4   |  CON3   |  CON2  | CON1 | CON0 |    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*    |BURN(0)|REFDET(0) | 0(0) |  BUF(0)   |  U/B(0)   |  G2(0)  | G1(0) | G0(0) |    */
/*    +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */	


/*    GPOCON�Ĵ�����8λ��ֻ��,RS2,RS1,RS0=1,0,1;�ϵ�/��λ=0x00                */
/*    ���ݼĴ���λ���ܲ����궨��                                              */
/*   +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   | GP7    |  GP6 |   GP5   |   GP4    |    GP3  |   GP2  |  GP1  |  GP0 |  */
/*   +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */
/*   | 0(0) |BPDSW(0)|GP32EN(0)|GP10EN(0)|P3DAT(0)|P2DAT(0)|P1DAT(0)|P0DAT(0)|  */
/*   +-------------+-----------+--------------+-----------------+----------------+--------------+-----------+-----------+  */


void AD7190_RST(void); //��λ
void AD7190_WR_ConfigReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);//д���üĴ���
void AD7190_WR_ModeReg(unsigned char cbyte_2,unsigned char cbyte_1,unsigned char cbyte_0);//дģʽ�Ĵ���
void AD7190_WaitRDYGoLow(void);//�ȴ�ת������
double AD7190_ReadDataOnce(void);//��һ������
void AD7190_ReadDataContinous(int length);//����������
void AD7190_ValueConversion(float *Value,int length);//����ת�� //double
#endif