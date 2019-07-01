#include "mbed.h"

AnalogIn v_registor(A0);			// A0 핀에 가변저항 연결
PwmOut pwm1(D2), pwm2(D3);		// D2, D3 핀에 LED 연결

int main() {
	while(1) {
		float adc = v_registor.read();		// 가변저항 값 읽기, [0.0 1.0]
		
		pwm1.write(adc);			// D2 핀에 연결된 LED 밝기 조절
		pwm2.write(1 - adc);			// D3 핀에 연결된 LED 밝기 조절
		
		wait(0.1);
	}
}