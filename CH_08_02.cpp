#include "mbed.h"

AnalogIn v_register(A0);				// 가변저항
DigitalOut R1(D2), R2(D3), R3(D4), R4(D5);		// LED

int main() {
	while(1) {
		unsigned short value = v_register.read_u16();	// 0x0~0xFFFF 가변저항 값 얻기
		int count = value >> 14;			// 0~3의 값으로 변환

		switch(count){
		case 0:
			R1 = 1;
			R2 = R3 = R4 = 0;
			break;
		case 1:
			R1 = R2 = 1;
			R3 = R4 = 0;
			break;
		case 2:
			R1 = R2 = R3 = 1;
			R4 = 0;
			break;
		case 3:
			R1 = R2 = R3 = R4 = 1;
			break;
		}
		wait(0.5);
	}
}