#include "mbed.h"

#define INTERVAL 0.002 			// 2밀리초 간격

// BusOut : LSB -> MSB 순서로 핀 지정
BusOut rows(D2, D3, D4, D5, D6, D7, D8, D9);	// 선택 행에는 VCC를 가함
BusOut cols(D10, D11, D12, D13, A0, A1, A2, A3);	// 선택 열에는 GND를 가함

// 행 데이터로 선택된 LED만 1의 값을 가짐
char row_data[] = {
	0b00000000, 0b11111111, 0b10001001, 0b10001001, 
	0b10001001, 0b10001001, 0b01110110, 0b00000000 };

int main(void) {
	while(1) {
		for(int i = 0; i < 8; i++){
			rows.write(0x00);			// 번짐 방지를 위해 LED 끄기
			cols.write(0xFF);
			
			char col_data = ~(0x01 << i);	// 하나의 열을 GND로 선택
			
			rows.write(row_data[i]);
			cols.write(col_data);
			
			wait(INTERVAL);
		}
	}
}