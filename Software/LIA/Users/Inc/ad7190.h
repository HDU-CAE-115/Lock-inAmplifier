#ifndef AD7190_H_ 
#define AD7190_H_

#include "stm32g4xx_hal.h"
#include "spi.h"
#include "gpio.h"
#include "main.h" 
  
/* Commands to write to specific registers */
 
#define COM_WRITE_CONFIG_REG_CMD                  0x10
#define COM_WRITE_MODE_REG_CMD                    0x08
#define COM_WRITE_GPCON_RED_CMD                   0x28 
 
/* Commands to read from specific registers */
 
#define COM_READ_CONFIG_REG_CMD                   0x50
#define COM_READ_STATUS_REG_CMD                   0x40
#define COM_READ_MODE_REG_CMD                     0x48
#define COM_READ_DATA_REG_CMD                     0x58
#define COM_READ_GPCON_REG_CMD                    0x68
#define COM_READ_ID_REG_CMD                       0x60
#define COM_READ_OFFSET_REG_CMD                   0x70
#define COM_READ_FULL_SCALE_REG_CMD               0x78

/* Sampling Rates */
 
#define FS_60_HZ                                 0x50
#define FS_300_HZ                                 0x10
#define FS_960_HZ                                 0x05
#define FS_2400_HZ                                0x02 
#define FS_4800_HZ                                0x01

/* Register settings commands for Configuration Register */
 
#define CONFIG_REG_CMD_MSB                        0x00 
#define CONFIG_REG_CMD_MID                        0x01
 
/*May have to change Gain depending on input signal voltage
See Table 19 in AD7190 datasheet for more information*/
 
#define CONFIG_REG_CMD_LSB                        0x01//0x1F 

/* Register settings commands for Mode Register */
 
#define MODE_REG_CMD_MSB                          0x08 
#define MODE_REG_CMD_MID                          0x00
#define MODE_REG_CMD_LSB                          FS_4800_HZ

/* Read the data register continously and place the data on DOUT */
 
//#define COMM_REG_CREAD                            0x5C
 
 
 
 
 
/* Structure Map of AD7190 internal registers
 * for read and write operations
 */
 
typedef struct{
         unsigned char cmd_rd_status_reg; 
         unsigned char cmd_wr_mode_reg;
         unsigned char cmd_rd_mode_reg;
         unsigned char cmd_wr_config_reg;
         unsigned char cmd_rd_config_reg;
         unsigned char cmd_rd_data_reg;
         unsigned char cmd_rd_ID_reg;
         unsigned char cmd_rd_gpocon_reg;
         unsigned char cmd_wr_gpocon_reg;
         unsigned char cmd_rd_offset_reg;
         unsigned char cmd_rd_full_scale_reg;
}AD7190_REG_T, *AD7190_REG_Ptr;

/* Enum commands to dump register contents */
 
typedef enum{ 
         DUMP_CONFIG_REG_CONTENTS,
         DUMP_MODE_REG_CONTENTS,
         DUMP_STATUS_REG_CONTENTS,
         DUMP_ID_REG_CONTENTS,
         DUMP_CONFIG_AND_MODE_REG_CONTENTS
}REG_DumpT;

/* AD7190 API's */
 
void init_AD7190_reg_cmds(AD7190_REG_Ptr ad7190_reg_ptr); 
void init_AD7190_cmds(void);
char AD7190_configure(unsigned char cbyte_2, unsigned char cbyte_1, unsigned char cbyte_0);
char AD7190_mode(unsigned char mbyte_2, unsigned char mbyte_1, unsigned char mbyte_fs);
unsigned char AD7190_read_status_reg(void);
unsigned char AD7190_get_ID(void);
void AD7190_reset(void);
int AD7190_read_data(void);
void AD7190_dump_regs(REG_DumpT regs_to_dump);

#endif 
 