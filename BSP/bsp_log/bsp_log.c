#include "bsp_log.h"
#include "string.h"

//
UART_HandleTypeDef muart1;
GPIO_InitTypeDef GPIO_LOG_Init;

//初始化
void bsp_log_init(void)
{
	//TX GPIO初始化
	GPIO_LOG_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_LOG_Init.Pin=PIN_LOG_TX;
	GPIO_LOG_Init.Pull=GPIO_NOPULL;
	GPIO_LOG_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_LOG_TX,&GPIO_LOG_Init);
	//RX GPIO初始化
	GPIO_LOG_Init.Mode=GPIO_MODE_INPUT;
	GPIO_LOG_Init.Pin=PIN_LOG_RX;
	HAL_GPIO_Init(GPIO_LOG_RX,&GPIO_LOG_Init);
	//串口初始化
	muart1.Instance=USART_NUM;
	muart1.Init.BaudRate=115200;
	muart1.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	muart1.Init.Mode=UART_MODE_TX_RX;
	muart1.Init.OverSampling=UART_OVERSAMPLING_16;
	muart1.Init.Parity=UART_PARITY_NONE;
	muart1.Init.StopBits=UART_STOPBITS_1;
	muart1.Init.WordLength=UART_WORDLENGTH_8B;
	HAL_UART_Init(&muart1);		
}

//打印int数组
void bsp_log_int_array(int data[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d\r\n",data[i]);//单纯/r或/n不起作用
	}
}

//打印uchar数组
void bsp_log_uchar_array(uint8_t data[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d\r\n",(int)data[i]);
	}
}

//printf必须函数
int fputc(int ch,FILE *f)
{
	uint8_t temp[1]={ch};
	HAL_UART_Transmit(&muart1,temp,1,2);
	return ch;
}


