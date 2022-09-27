/*
 * 2004_lcd.c
 *
 *  Created on: Sep 4, 2022
 *      Author: galla
 */


#include "2004_lcd.h"



GPIO_TypeDef * alpha[] = {GPIOA, GPIOA, GPIOA, GPIOB, GPIOA, GPIOA, GPIOA, GPIOB};
uint16_t pin[] = {D7_Pin, D6_Pin, D5_Pin, D4_Pin, D3_Pin, D2_Pin, D1_Pin, D0_Pin};

void lcd_send_cmd(char cmd)
{
	int data[8];
	data[0] = cmd&0x80;
	data[1] = cmd&0x40;
	data[2] = cmd&0x20;
	data[3] = cmd&0x10;
	data[4] = cmd&0x08;
	data[5] = cmd&0x04;
	data[6] = cmd&0x02;
	data[7] = cmd&0x01;

	HAL_GPIO_WritePin(GPIOB, RS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, R_W_Pin, GPIO_PIN_RESET);

	for (int i=0; i<8; i++)
	{
		if (data[i] == 0) HAL_GPIO_WritePin(alpha[i], pin[i], GPIO_PIN_RESET);
		else HAL_GPIO_WritePin(alpha[i], pin[i], GPIO_PIN_SET);
	}

	HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_SET);

	HAL_Delay(1);

	HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_RESET);
}

void lcd_send_char(char cmd)
{
	int data[8];
	data[0] = cmd&0x80;
	data[1] = cmd&0x40;
	data[2] = cmd&0x20;
	data[3] = cmd&0x10;
	data[4] = cmd&0x08;
	data[5] = cmd&0x04;
	data[6] = cmd&0x02;
	data[7] = cmd&0x01;

	HAL_GPIO_WritePin(GPIOB, RS_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, R_W_Pin, GPIO_PIN_RESET);

	for (int i=0; i<8; i++)
	{
		if (data[i] == 0) HAL_GPIO_WritePin(alpha[i], pin[i], GPIO_PIN_RESET);
		else HAL_GPIO_WritePin(alpha[i], pin[i], GPIO_PIN_SET);
	}

	HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_SET);

	HAL_Delay(1);

	HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_RESET);
}

void lcd_send_string(char *str)
{
	while (*str) lcd_send_char(*str++);
}

void lcd_clear()
{
	lcd_send_cmd(0x01);
	lcd_send_cmd(0x80);
}

void lcd_init()
{
	HAL_Delay(50);
	lcd_send_cmd(0x30);
	HAL_Delay(5);
	lcd_send_cmd(0x30);
	HAL_Delay(1);
	lcd_send_cmd(0x30);
	HAL_Delay(10);
	lcd_send_cmd(0x38);
	HAL_Delay(10);
	lcd_send_cmd(0x08);
	HAL_Delay(10);
	lcd_send_cmd(0x01);
	HAL_Delay(10);
	lcd_send_cmd(0x01);
	HAL_Delay(10);
	lcd_send_cmd(0x06);
	HAL_Delay(10);
	lcd_send_cmd(0x0C);
	HAL_Delay(10);
}

