#include "mbed.h"

#define INTERVAL 0.1 			// 0.1초 간격

// BusOut : LSB -> MSB 순서로 핀 지정
BusOut rows(D2, D3, D4, D5, D6, D7, D8, D9);	// 선택 행에는 VCC를 가함
BusOut cols(D10, D11, D12, D13, A0, A1, A2, A3);	// 선택 열에는 GND를 가함

int main(void) {
	while(1) {
		for(int i = 0; i < 8; i++){
			char row_data = 0x01 << i;		// 하나의 행을 VCC로 선택
			for(int j = 0; j < 8; j++){
				char col_data = ~(0x01 << j);	// 하나의 열을 GND로 선택
				
				rows.write(0x00);			// 번짐 방지를 위해 LED 끄기
				cols.write(0xFF);
				
				rows.write(row_data);
				cols.write(col_data);
				
				wait(INTERVAL);
			}
		}
	}
}