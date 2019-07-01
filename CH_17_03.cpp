#include "mbed.h"

DigitalOut LED(LED1);			// 내장 LED로 감지 표시
DigitalIn detector(D2);			// PIR 센서 출력

int previous = 0 ;			// 이전 감지 상태
int m_count = 0;				// 감지 횟수

int main() {
	detector.mode(PullDown);
	LED = 0;					// LED는 꺼진 상태로 시작
	
	while (1) {
		if(detector == 1){			// 움직임 감지
			LED = 1;				// LED 켜기
			if (previous == 0) {			// 움직임이 감지되기 시작
				m_count++;
				previous = 1;
				printf("Movement detected : %d\n", m_count);
			}
		}
		else{						// 움직임이 감지되지 않음
			LED = 0;				// LED 끄기
			if(previous == 1){
				previous = 0;
				printf("Movement stopped...\n");
			}
		}
	}
}