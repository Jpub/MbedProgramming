#include "mbed.h"
#include "ds3231m.h"

I2C myI2C(D14, D15);
DS3231M myRTC(myI2C);			// (SDA, SCL)

DigitalOut myLED(D9);			// LED 연결 핀
InterruptIn RTC_SQ(D8);			// 구형파를 통한 인터럽트 사용

volatile int sq_count = 0;			// 펄스 카운트

void count_square_wave(void) {		// 하강 에지에서의 콜백 함수
	sq_count++;
}

int main() {
	RTC_SQ.fall(count_square_wave);	// 콜백 함수 설정

	struct tm initialTime = { 0, 0, 8, 1, 0, 119, 2 };
	myRTC.setTime(&initialTime);		// 현재 시간 설정
	
	myRTC.Osc32kHzEnable(true);		// 32.768kHz 구형파 출력 설정

	while(1) {
		if(sq_count == 32768){		// 1초 경과
			sq_count = 0;
			myLED = !myLED;
		}
	}
}