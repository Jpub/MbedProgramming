#include "mbed.h"

// 0에서 9까지 숫자 표현을 위한 세그먼트 a, b, c, d, e, f, g, dp의 패턴
char patterns[] = {
	0xFC,		// 0b11111100, ‘0’
	0x60,		// 0b01100000, ‘1’
	0xDA,		// 0b11011010, ‘2’
	0xF2,		// 0b11110010, ‘3’
	0x66,		// 0b01100110, ‘4’
	0xB6,		// 0b10110110, ‘5’
	0xBE,		// 0b10111110, ‘6’
	0xE0,		// 0b11100000, ‘7’
	0xFE,		// 0b11111110, ‘8’
	0xF6 		// 0b11110110, ‘9’
};

BusOut segment(D9, D8, D7, D6, D5, D4, D3, D2);

int main() {
	int no = 0;
	
	while(1) {
		segment.write(patterns[no]);		// 숫자 데이터 출력
		
		no = (no + 1) % 10;			// 0~9 반복
		
		wait(1);
	}
}