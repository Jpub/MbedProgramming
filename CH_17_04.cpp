#include "mbed.h"

DigitalOut LED(LED1);			// 내장 LED로 감지 표시
DigitalIn detector(D2);			// PIR 센서 출력

int m_count = 0;				// 감지 횟수

void move_detect() {			// 상승 에지 처리
    m_count++;
    printf("Movement detected : %d\n", m_count);
}

void move_stop() {			// 하강 에지 처리
    printf("Movement stopped...\n");
}

int main() {
    detector.mode(PullDown);
    
    detector.rise(&move_detect);		// 상승 에지 콜백 함수
    detector.fall(&move_stop);		// 하강 에지 콜백 함수
    
    while (1) {
    }
}