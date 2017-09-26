#include <stm32f10x.h>

void send_string(uint8_t *st, uint8_t *buffer, uint32_t len);
void string_to_buffer(char *str, uint32_t len);
void itoa(char *dst, uint32_t num);

uint32_t blink_ticks = 0;
uint32_t ticks = 0;
void delay_ms(uint32_t ms);
void RCC_Config(void);
void UART_Config(void);
void LED_Config(void);
void DMA_Config(uint8_t *buffer);

uint8_t transmit_buffer[50] = "hello world\r\n";

int main(void){
	SysTick_Config(SystemCoreClock/1000);
	RCC_Config();
	LED_Config();
	DMA_Config(transmit_buffer);
	UART_Config();
	while(1);
}


extern "C" void DMA1_Channel4_IRQHandler(){
	if(DMA_GetITStatus(DMA1_IT_TC4) == SET){
		DMA_Cmd(DMA1_Channel4, DISABLE);
		DMA_ClearFlag(DMA1_FLAG_TC4);
	}
}
extern "C" void SysTick_Handler(){
	if(blink_ticks == 100){
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
	}else if(blink_ticks == 200){
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		blink_ticks = 0;
		send_string((uint8_t *)"hello world\r\n", transmit_buffer, 13);
	}
	blink_ticks++;
	ticks++;
}

void delay_ms(uint32_t ms){
	uint32_t start_ticks = ticks;
	while(ticks - start_ticks < ms);
}



void RCC_Config(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
}

void LED_Config(void){
	GPIO_InitTypeDef gpio1;
	gpio1.GPIO_Mode =  GPIO_Mode_Out_PP;
	gpio1.GPIO_Pin = GPIO_Pin_13;
	gpio1.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio1);
}

void DMA_Config(uint8_t *buffer){
	
	DMA_DeInit(DMA1_Channel4);
	DMA_InitTypeDef dma1;
	NVIC_InitTypeDef nvic;
	
	dma1.DMA_PeripheralBaseAddr = (uint32_t)&(USART1->DR);
	dma1.DMA_MemoryBaseAddr = (uint32_t)buffer;
	dma1.DMA_DIR = DMA_DIR_PeripheralDST;
	dma1.DMA_BufferSize = 50;
	dma1.DMA_PeripheralInc =DMA_PeripheralInc_Disable;
	dma1.DMA_MemoryInc = DMA_MemoryInc_Enable;
	dma1.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma1.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma1.DMA_Mode = DMA_Mode_Normal;
	dma1.DMA_Priority = DMA_Priority_VeryHigh;
	dma1.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel4, &dma1);
	DMA_ITConfig(DMA1_Channel4,DMA_IT_TC | DMA_IT_TE,ENABLE);
	DMA_Cmd(DMA1_Channel4, ENABLE);
	
	nvic.NVIC_IRQChannel = DMA1_Channel4_IRQn;
	nvic.NVIC_IRQChannelPreemptionPriority = 0;
	nvic.NVIC_IRQChannelSubPriority = 0;
	nvic.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic);
}
void UART_Config(void){
	
	GPIO_InitTypeDef gpio1;
	USART_InitTypeDef uart1;
	gpio1.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio1.GPIO_Pin = GPIO_Pin_9;
	gpio1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio1);
	USART_Cmd(USART1, ENABLE);
	uart1.USART_BaudRate = 921600;
	uart1.USART_WordLength = USART_WordLength_8b;
	uart1.USART_StopBits = USART_StopBits_1;
	uart1.USART_Parity = USART_Parity_No;
	uart1.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	uart1.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, &uart1);
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
}
void send_string(uint8_t *st, uint8_t *buffer, uint32_t len){
	for(int i = 0; i < len;i++){
			buffer[i] = st[i];
	}
	DMA_SetCurrDataCounter(DMA1_Channel4, len);
	DMA_Cmd(DMA1_Channel4, ENABLE);
}
void string_to_buffer(uint8_t *src, uint8_t *dst, uint32_t len){
	for(int i = 0; i < 50;i++){
		if(i<len){
			dst[i] = src[i];
		}else{
			dst[i] = 0;
		}
	}
}

void itoa(char *dst, uint32_t num){
	uint32_t i = 0;
	while(num > 0){
		dst[i] = '0' + num % 10;
		num /= 10;
		i++;
	}
	for(int j = i-1; j > (i-1)/2 ; j--){
		int tmp = dst[j];
		dst[j] = dst[i-1-j];
		dst[i-1-j] = tmp;
	}
	dst[i] = '\r';
	dst[i+1] = '\n';
	for(int j = i+2; j < 50;j++){
		dst[j] = 0;
	}
}
