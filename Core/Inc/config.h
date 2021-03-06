/* LORA I/O definition */



/* PINES PARA LA PLACA ST*/

/* SPI1 */

#ifdef PCB_SPI_SX

#define RADIO_RESET_PORT                          GPIOC
#define RADIO_RESET_PIN                           GPIO_PIN_4

#define RADIO_MOSI_PORT                           GPIOA
#define RADIO_MOSI_PIN                            GPIO_PIN_7

#define RADIO_MISO_PORT                           GPIOA
#define RADIO_MISO_PIN                            GPIO_PIN_6

#define RADIO_SCLK_PORT                           GPIOA
#define RADIO_SCLK_PIN                            GPIO_PIN_5

#define RADIO_NSS_PORT                            GPIOA
#define RADIO_NSS_PIN                             GPIO_PIN_4

#define RADIO_DIO_0_PORT                          GPIOE
#define RADIO_DIO_0_PIN                           GPIO_PIN_13

#define RADIO_DIO_1_PORT                          GPIOE
#define RADIO_DIO_1_PIN                           GPIO_PIN_12

#endif

#ifdef PCB_SPI_SA

#define RADIO_RESET_PORT                          GPIOC
#define RADIO_RESET_PIN                           GPIO_PIN_6

#define RADIO_MOSI_PORT                           GPIOE
#define RADIO_MOSI_PIN                            GPIO_PIN_6

#define RADIO_MISO_PORT                           GPIOE
#define RADIO_MISO_PIN                            GPIO_PIN_5

#define RADIO_SCLK_PORT                           GPIOE
#define RADIO_SCLK_PIN                            GPIO_PIN_2

#define RADIO_NSS_PORT                            GPIOE
#define RADIO_NSS_PIN                             GPIO_PIN_4

#define RADIO_DIO_0_PORT                          GPIOA
#define RADIO_DIO_0_PIN                           GPIO_PIN_1

#define RADIO_DIO_1_PORT                          GPIOA
#define RADIO_DIO_1_PIN                           GPIO_PIN_0

#endif

/*PINES PARA EL READER*/

#define RADIO_DIO_2_PORT                          GPIOB
#define RADIO_DIO_2_PIN                           GPIO_PIN_5

#define RADIO_DIO_3_PORT                          GPIOB
#define RADIO_DIO_3_PIN                           GPIO_PIN_4

#ifdef RADIO_DIO_4
#define RADIO_DIO_4_PORT                          GPIOA
#define RADIO_DIO_4_PIN                           GPIO_PIN_5
#endif

#ifdef RADIO_DIO_5
#define RADIO_DIO_5_PORT                          GPIOA
#define RADIO_DIO_5_PIN                           GPIO_PIN_4
#endif

#define RADIO_ANT_SWITCH_PORT                     GPIOC
#define RADIO_ANT_SWITCH_PIN                      GPIO_PIN_1

#define RADIO_TCXO_VCC_PORT                       GPIOA
#define RADIO_TCXO_VCC_PIN                        GPIO_PIN_12

#define RADIO_ANT_SWITCH_PORT_RX                  GPIOA //CRF1
#define RADIO_ANT_SWITCH_PIN_RX                   GPIO_PIN_1

#define RADIO_ANT_SWITCH_PORT_TX_BOOST            GPIOC //CRF3
#define RADIO_ANT_SWITCH_PIN_TX_BOOST             GPIO_PIN_1

#define RADIO_ANT_SWITCH_PORT_TX_RFO              GPIOC //CRF2
#define RADIO_ANT_SWITCH_PIN_TX_RFO               GPIO_PIN_2

/*  SPI MACRO redefinition */

#define SPI_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()

#define SPI1_AF                          GPIO_AF5_SPI1

/* ADC MACRO redefinition */

#ifdef USE_STM32L0XX_NUCLEO
#define ADC_READ_CHANNEL                 ADC_CHANNEL_4
#define ADCCLK_ENABLE()                 __HAL_RCC_ADC1_CLK_ENABLE() ;
#define ADCCLK_DISABLE()                __HAL_RCC_ADC1_CLK_DISABLE() ;
#endif


/* --------------------------- RTC HW definition -------------------------------- */

#define RTC_OUTPUT       DBG_RTC_OUTPUT

//#define RTC_Alarm_IRQn              RTC_IRQn

/* --------------------------- USART HW definition -------------------------------*/
#define USARTX                           USART2
#define USARTX_CLK_ENABLE()              __USART2_CLK_ENABLE();
#define USARTX_RX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define USARTX_TX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()

#define USARTX_FORCE_RESET()             __USART2_FORCE_RESET()
#define USARTX_RELEASE_RESET()           __USART2_RELEASE_RESET()


#define USARTX_TX_PIN                  GPIO_PIN_2
#define USARTX_TX_GPIO_PORT            GPIOA
#define USARTX_TX_AF                   GPIO_AF7_USART2
#define USARTX_RX_PIN                  GPIO_PIN_3
#define USARTX_RX_GPIO_PORT            GPIOA
#define USARTX_RX_AF                   GPIO_AF7_USART2

/* Definition for USARTx's NVIC */
#define USARTX_IRQn                      USART2_IRQn
#define USARTX_IRQHandler                USART2_IRQHandler

/* Definition for USARTx's DMA */
#define USARTX_TX_DMA_CHANNEL             DMA1_Stream7

/* Definition for USARTx's DMA Request */
#define USARTX_TX_DMA_REQUEST             DMA_REQUEST_4

/* Definition for USARTx's NVIC */
#define USARTX_DMA_TX_IRQn                DMA1_Stream7_IRQn
//#define USARTx_DMA_TX_IRQHandler          DMA1_Channel4_5_6_7_IRQHandler

#define USARTX_Priority 0
#define USARTx_DMA_Priority 0

#define LED_Toggle( x )
#define LED_On( x )
#define LED_Off( x )

#ifdef __cplusplus
}
#endif


#define RCC_GPIO_CLK_ENABLE( __GPIO_PORT__ )              \
do {                                                    \
    switch( __GPIO_PORT__)                                \
    {                                                     \
      case GPIOA_BASE: __HAL_RCC_GPIOA_CLK_ENABLE(); break;    \
      case GPIOB_BASE: __HAL_RCC_GPIOB_CLK_ENABLE(); break;    \
      case GPIOC_BASE: __HAL_RCC_GPIOC_CLK_ENABLE(); break;    \
      case GPIOD_BASE: __HAL_RCC_GPIOD_CLK_ENABLE(); break;    \
      case GPIOH_BASE: default:  __HAL_RCC_GPIOH_CLK_ENABLE(); \
    }                                                    \
  } while(0)

#define RCC_GPIO_CLK_DISABLE( __GPIO_PORT__ )              \
do {                                                    \
    switch( __GPIO_PORT__)                                \
    {                                                     \
      case GPIOA_BASE: __HAL_RCC_GPIOA_CLK_DISABLE(); break;    \
      case GPIOB_BASE: __HAL_RCC_GPIOB_CLK_DISABLE(); break;    \
      case GPIOC_BASE: __HAL_RCC_GPIOC_CLK_DISABLE(); break;    \
      case GPIOD_BASE: __HAL_RCC_GPIOD_CLK_DISABLE(); break;    \
      case GPIOH_BASE: default:  __HAL_RCC_GPIOH_CLK_ENABLE(); \
    }                                                    \
  } while(0)

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

