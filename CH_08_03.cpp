#include "mbed.h"

AnalogIn v_register(A0);				// 가변저항
BusOut LEDs(D2, D3, D4, D5);			// LED 모음

int main() {
	// LED 표시 패턴
	int patterns[] = { 0b0001, 0b0011, 0b0111, 0b1111 };
	while(1) {
		unsigned short value = v_register.read_u16();	// 0x0~0xFFFF 가변저항 값 얻기
		int index = value >> 14;			// 0~3의 인덱스로 변환

		LEDs = patterns[index];			// LED 제어
		wait(0.5);
	}
}