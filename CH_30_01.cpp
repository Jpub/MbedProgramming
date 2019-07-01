#include "mbed.h"

DigitalOut myled(PC_13);			// 내장 LED

int main() {  
	int count = 0;				// 카운터

	while(1) {
		// 내장 LED는 풀업저항이 연결되어 있으므로 GND 연결 시 켜짐
		myled = 0;				// LED 켜기
		wait_ms(500);
		myled = 1;				// LED 끄기
		printf("%d\n", count++);		// 카운터 출력
		wait_ms(500);
	}
}