#include "mbed.h"
#include "ds3231m.h"

I2C myI2C(D14, D15);
DS3231M myRTC(myI2C);			// (SDA, SCL)

DigitalOut myLED(D9);			// LED 연결 핀
InterruptIn RTC_SQ(D8);			// 구형파를 통한 인터럽트 사용

void blink(void) { 			// 하강 에지에서의 콜백 함수
	myLED = !myLED ;
}

int main() {
	RTC_SQ.fall(blink);			// 콜백 함수 설정

	struct tm initialTime = { 0, 0, 8, 1, 0, 119, 2 };
	myRTC.setTime(&initialTime);		// 현재 시간 설정
	
	myRTC.SQWSetFreq(_RTC::FREQ_1);	// 1Hz 주파수 설정
	myRTC.SQWEnable(true);		// 구형파 출력 설정

	while(1) {
	}
}