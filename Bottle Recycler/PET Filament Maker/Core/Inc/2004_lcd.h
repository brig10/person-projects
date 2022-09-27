/*
 * 2004_lcd.h
 *
 *  Created on: Sep 4, 2022
 *      Author: galla
 */

#ifndef INC_2004_LCD_H_
#define INC_2004_LCD_H_



#endif /* INC_2004_LCD_H_ */

#include "stm32f1xx_hal.h"

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_char(char cmd);
void lcd_send_string(char *str);
void lcd_clear(void);

#define RS_Pin GPIO_PIN_12
#define RS_GPIO_Port GPIOB
#define R_W_Pin GPIO_PIN_13
#define R_W_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_14
#define E_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_15
#define D4_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOA
#define D6_Pin GPIO_PIN_9
#define D6_GPIO_Port GPIOA
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_11
#define D3_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_12
#define D2_GPIO_Port GPIOA
#define D1_Pin GPIO_PIN_15
#define D1_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_3
#define D0_GPIO_Port GPIOB
