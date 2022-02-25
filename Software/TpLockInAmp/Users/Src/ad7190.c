#include "ad7190.h"

//#define CS_H HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET)
//#define CS_L HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET)
int flag = 0;
int adc_data = 0x00;
unsigned char ad7190_ID[1] = {0};
unsigned char reg_status = 0;
static AD7190_REG_T ad7190_obj; 
void init_AD7190_reg_cmds(AD7190_REG_Ptr ad7190_reg_ptr);
 
unsigned char SPIDEV1_single_transfer(unsigned char data_byte){
	uint8_t data=0;
	//CS_L;
	//HAL_Delay(1);
	HAL_SPI_TransmitReceive(&hspi1, &data_byte, &data, 1, 1000);
	//HAL_Delay(1);
	//CS_H;
	return 0;
	}
	 
int SPIDEV1_transfer(unsigned char *send, unsigned char *receive, unsigned char bytes_num){
	//uint8_t i=0;
	//CS_L;
	//HAL_Delay(1);
	HAL_SPI_TransmitReceive(&hspi1, send, receive, bytes_num, 5000);
	//HAL_Delay(1);
	//CS_H;
	return 0;
}

/****************************************************************
 * Function Name : init_AD7190_reg_cmds
 * Description   : API to initialize the AD7190 commands structure ³õÊ¼»¯AD7190ÃüÁî½á¹¹
 *                 for communication
 * Returns       : None
 * Params        @ad7190_reg_ptr: Pointer to commands structure
 ****************************************************************/
void init_AD7190_reg_cmds(AD7190_REG_Ptr ad7190_reg_ptr){
	ad7190_reg_ptr->cmd_rd_ID_reg = COM_READ_ID_REG_CMD;
	ad7190_reg_ptr->cmd_rd_config_reg = COM_READ_CONFIG_REG_CMD;
	ad7190_reg_ptr->cmd_rd_data_reg = COM_READ_DATA_REG_CMD;
	ad7190_reg_ptr->cmd_rd_full_scale_reg = COM_READ_FULL_SCALE_REG_CMD;
	ad7190_reg_ptr->cmd_rd_gpocon_reg = COM_READ_GPCON_REG_CMD;
	ad7190_reg_ptr->cmd_rd_mode_reg = COM_READ_MODE_REG_CMD;
	ad7190_reg_ptr->cmd_rd_offset_reg = COM_READ_OFFSET_REG_CMD;
	ad7190_reg_ptr->cmd_rd_status_reg = COM_READ_STATUS_REG_CMD;
	ad7190_reg_ptr->cmd_wr_gpocon_reg = COM_WRITE_GPCON_RED_CMD;
	ad7190_reg_ptr->cmd_wr_config_reg = COM_WRITE_CONFIG_REG_CMD;
	ad7190_reg_ptr->cmd_wr_mode_reg = COM_WRITE_MODE_REG_CMD;
}

/****************************************************************
 * Function Name : init_AD7190_cmds
 * Description   : Initialize the AD7190 commands structure
 *                 for communication
 * Returns       : None
 * Params        : None
 ****************************************************************/
void init_AD7190_cmds(){ 
	init_AD7190_reg_cmds(&ad7190_obj);
}

/****************************************************************
 * Function Name : AD7190_configure
 * Description   : Configure/Write to the configuration register ÅäÖÃ/Ð´ÈëÅäÖÃ¼Ä´æÆ÷
 *                 for communication
 * Returns       : (-1) typecast for error, 0 for success
 * Params        @cbyte_2: Data to write to Most Significant Byte
 *               @cbyte_1: Data to write to Middle Byte
 *               @cbyte_0: Data to write to Least Significant Byte
 ****************************************************************/
char AD7190_configure(unsigned char cbyte_2, unsigned char cbyte_1, unsigned char cbyte_0){
	char check_ret = 0x00;
	unsigned char ad7190_id = 0x00;
	ad7190_id = AD7190_get_ID();
	//printf("Initializing AD7190 ADC    Device ID    = 0x%x\r\n", ad7190_id);
	/* Go to write to configuration register */ 
	check_ret = SPIDEV1_single_transfer(ad7190_obj.cmd_wr_config_reg); 
	/* Write to Most Significant Byte */
	check_ret = SPIDEV1_single_transfer(cbyte_2);
	/* Write to Mid Byte */
	check_ret = SPIDEV1_single_transfer(cbyte_1);
	/* Write to Least Significant Byte */
	check_ret = SPIDEV1_single_transfer(cbyte_0);
	return (check_ret);
}

/****************************************************************
 * Function Name : AD7190_mode
 * Description   : Configure/Write to the mode register ÅäÖÃ/Ð´ÈëÄ£Ê½¼Ä´æÆ÷
 *                 for communication
 * Returns       : (-1) typecast for error, 0 for success
 * Params        @mbyte_2: Data to write to Most Significant Byte
 *               @mbyte_1: Data to write to Middle Byte
 *               @mbyte_fs: Data to write to Least Significant Byte
 ****************************************************************/
char AD7190_mode(unsigned char mbyte_2, unsigned char mbyte_1, unsigned char mbyte_fs){
	char check_ret = 0x00;
	 
	/* Go to write to configuration register */
	check_ret = SPIDEV1_single_transfer(ad7190_obj.cmd_wr_mode_reg);
	 
	/* Write to Most Significant Byte */
	check_ret = SPIDEV1_single_transfer(mbyte_2);
	 
	/* Write to Mid Byte */
	check_ret = SPIDEV1_single_transfer(mbyte_1);

	/* Write to Least Significant Byte */
	check_ret = SPIDEV1_single_transfer(mbyte_fs);

	//add new gpocon ´ò¿ªswitch
	check_ret = SPIDEV1_single_transfer(ad7190_obj.cmd_wr_gpocon_reg);
	check_ret = SPIDEV1_single_transfer(0x40);
	return (check_ret);
}

/****************************************************************
 * Function Name : AD7190_read_status_reg
 * Description   : Read the status register ¶Á×´Ì¬¼Ä´æÆ÷
 * Returns       : Contents of the status register
 * Params        : None
 ****************************************************************/
unsigned char AD7190_read_status_reg(){
	unsigned char status_reg = 0x00;
	SPIDEV1_single_transfer(ad7190_obj.cmd_rd_status_reg);
	status_reg = SPIDEV1_single_transfer(0x00);
	return (status_reg);
}

/****************************************************************
 * Function Name : AD7190_get_ID
 * Description   : Read the ID register ¶ÁID
 * Returns       : Contents of the ID register
 * Params        : None
 ****************************************************************/
unsigned char AD7190_get_ID(){
	int get_ID_result = 0;
	SPIDEV1_single_transfer(ad7190_obj.cmd_rd_ID_reg);
	if(HAL_SPI_Receive(&hspi1,ad7190_ID,1,5000) == HAL_OK) get_ID_result = 1;
	else get_ID_result = 0;
//	ad7190_ID = SPIDEV1_single_transfer(0x00);
	return (ad7190_ID[0]);
}

/****************************************************************
 * Function Name : AD7190_reset
 * Description   : Resets the AD7190 ÖØÖÃAD7190
 * Returns       : None
 * Params        : None
 ****************************************************************/
void AD7190_reset(){
	char cnt;
	for(cnt = 0 ; cnt < 55; cnt++)
	SPIDEV1_single_transfer(0xFF);
}

/****************************************************************
 * Function Name : AD7190_read_data
 * Description   : Read the data register ¶ÁÊý¾Ý¼Ä´æÆ÷
 * Returns       : Contents of the data register
 * Params        : None
 ****************************************************************/
int AD7190_read_data(void){
	unsigned char Tx_bytes[]={0xff,0xff,0xff}, Rx_bytes[3] = {0,0,0}, drdy_bit; //reg_status = 0,
//	int adc_data = 0x00;
	//memset(Tx_bytes, 0xFF, sizeof(Tx_bytes));
	//memset(Rx_bytes, 0, sizeof(Rx_bytes));
	drdy_bit = 1;
	reg_status = AD7190_read_status_reg();
	drdy_bit = reg_status & 0x80;
	if (drdy_bit == 0x00){
		flag = 1;
		SPIDEV1_single_transfer(ad7190_obj.cmd_rd_data_reg);
		if(HAL_SPI_Receive(&hspi1,Rx_bytes,3,5000) == HAL_OK){
//		if (SPIDEV1_transfer(Tx_bytes, Rx_bytes, 3) == 0){
			adc_data = (adc_data | Rx_bytes[0]) << 8;
			adc_data = (adc_data | Rx_bytes[1]) << 8;
			adc_data = adc_data | Rx_bytes[2];
			//printf("%lu\r\n",adc_data);
		}
		else{
			flag = 2;
			//printf("(AD7190_read_test)Transaction Failed\r\n");
			adc_data = 0xffffffff;
		}	
	}
	else{
		flag = 3;
		adc_data = 0xffffffff;
	}
return (adc_data);
}

/****************************************************************
 * Function Name : AD7190_dump_regs
 * Description   : Dump the contents of the registers ×ª´¢¼Ä´æÆ÷µÄÄÚÈÝ
 * Returns       : None
 * Params        @regs_to_dump: Registers to dump
 ****************************************************************/
void AD7190_dump_regs(REG_DumpT regs_to_dump){
	unsigned char Tx_bytes[3]={0xff,0xff,0xff}, Rx_bytes[3] = {0,0,0}, reg_status_id = 0;
	unsigned long read_config_mode = 0x00;
	//memset(Tx_bytes, 0xFF, sizeof(Tx_bytes));
	//memset(Rx_bytes, 0, sizeof(Rx_bytes));
	switch(regs_to_dump){
		case DUMP_CONFIG_REG_CONTENTS:
		SPIDEV1_single_transfer(ad7190_obj.cmd_rd_config_reg);
//		if (SPIDEV1_transfer(Tx_bytes, Rx_bytes, 3) == 0){
		if(HAL_SPI_Receive(&hspi1,Rx_bytes,3,1000) == HAL_OK){
			read_config_mode = (read_config_mode | Rx_bytes[0]) << 8;
			read_config_mode = (read_config_mode | Rx_bytes[1]) << 8;
			read_config_mode = read_config_mode | Rx_bytes[2];
			//printf("Dump - Configuration Register  = 0X%x\r\n",read_config_mode);
		}
		else{
				//printf("(AD7190_dump_regs)Transaction Failed\r\n");
		}
		break;
		case DUMP_MODE_REG_CONTENTS:
		SPIDEV1_single_transfer(ad7190_obj.cmd_rd_mode_reg);
		if (SPIDEV1_transfer(Tx_bytes, Rx_bytes, 3) == 0){
			read_config_mode = (read_config_mode | Rx_bytes[0]) << 8;
			read_config_mode = (read_config_mode | Rx_bytes[1]) << 8;
			read_config_mode = read_config_mode | Rx_bytes[2];
			//printf("Dump - Mode Register  = 0X%x\r\n",read_config_mode);
		}
		else{
			//printf("(AD7190_dump_regs)Transaction Failed\r\n");
		}
		break;
		case DUMP_STATUS_REG_CONTENTS:
		reg_status_id = AD7190_read_status_reg();
		//printf("Dump - Status Register  = 0X%x\r\n",reg_status_id);
		break;
		case DUMP_ID_REG_CONTENTS:
		reg_status_id = AD7190_get_ID(); 
		//printf("Dump - ID Register  = 0X%x\r\n",reg_status_id);
		break;
		case DUMP_CONFIG_AND_MODE_REG_CONTENTS:
		default:
		//SPIDEV1_single_transfer(ad7190_obj.cmd_rd_config_reg);
		//if (SPIDEV1_transfer(Tx_bytes, Rx_bytes, 3) == 0)
		//{
		//      read_config_mode = (read_config_mode | Rx_bytes[0]) << 8;
		//      read_config_mode = (read_config_mode | Rx_bytes[1]) << 8;
		//      read_config_mode = read_config_mode | Rx_bytes[2];
		//      //printf("Dump - Configuration Register  = 0X%x\r\n",read_config_mode);
		//}
		//else
		//{
		//      //printf("(AD7190_dump_regs)Transaction Failed\r\n");
		//}
		//
		memset(Rx_bytes, 0, sizeof(Rx_bytes));
		//read_config_mode = 0x00;
		SPIDEV1_single_transfer(ad7190_obj.cmd_rd_mode_reg);
		if(SPIDEV1_transfer(Tx_bytes, Rx_bytes, 3) == 0){
			read_config_mode = (read_config_mode | Rx_bytes[0]) << 8;
			read_config_mode = (read_config_mode | Rx_bytes[1]) << 8;
			read_config_mode = read_config_mode | Rx_bytes[2];
			//printf("Dump - Mode Register  = 0X%x\r\n",read_config_mode);
		}
		else{
						//printf("(AD7190_dump_regs)Transaction Failed\r\n");
		}
		break;
	}
}