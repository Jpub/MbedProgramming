#include "mbed.h"

PwmOut pwm1(D2), pwm2(D3);

int main() {
	pwm1.period(1);			// 주기 1초
	pwm2.period(2);			// 주기 2초
	
	pwm1.pulsewidth(0.5);			// 펄스 폭 0.5초, 듀티 사이클 50%
	pwm2.pulsewidth(1);			// 펄스 폭 1초, 듀티 사이클 50%
	
	while(1) {
	}
}