#ifndef __BSP_LOG_H
#define __BSP_LOG_H
#include "stm32f1xx.h"
#include "stdio.h"

//����ʱ�޸�����
#define GPIO_LOG_TX    GPIOA				//TX IO��
#define PIN_LOG_TX     GPIO_PIN_9		//TX IO�˿�
#define GPIO_LOG_RX    GPIOA				//RX IO��
#define PIN_LOG_RX     GPIO_PIN_10	//RX IO�˿�
#define USART_NUM      USART1				//���ں�

//�ɱ�궨��
#define DEBUG_MODE	//LOG�������

#ifdef DEBUG_MODE
#define log(format,...) printf(format "\r\n", ##__VA_ARGS__)
#define logInfo(format,...) printf(" [Info]:  " format "\r\n", ##__VA_ARGS__)
#define logDebug(format,...) printf(" [Debug]:  " format "\r\n", ##__VA_ARGS__)
#define logErr(format,...) printf(" [Error]:  " format "\r\n", ##__VA_ARGS__)
#define logIntArray(...) bsp_log_int_array(__VA_ARGS__)
#define logUcharArray(...) bsp_log_uchar_array(__VA_ARGS__)
#else
#define log(format,...)
#define logIntArray(...)
#define logUcharArray(...)
#define logInfo(format,...)
#define logDebug(format,...)
#define logErr(format,...)
#endif

void bsp_log_init(void);
int fputc(int ch,FILE *f);
void bsp_log_int_array(int data[],int size);
void bsp_log_uchar_array(uint8_t data[],int size);
#endif
