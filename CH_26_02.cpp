#include "mbed.h"

#define WIDTH_MIN 750			// 최소 펄스 폭 (ms)
#define WIDTH_MAX 2250 		// 최대 펄스 폭 (ms)

PwmOut myServo(D2); 			// 서보 모터 연결 핀
AnalogIn v_resistor(A0); 			// 가변저항 연결 핀

int angle2width(int angle) { 		// 0~180도 각도를 펄스 폭으로 변환
	float width = angle * (WIDTH_MAX - WIDTH_MIN) / 180.0 + WIDTH_MIN;
	return int(width);
}

int main() {
	myServo.period_ms(20); 		// 50Hz 주파수 설정
	
	while(1) {
		float f = v_resistor.read();		// 가변저항 읽기 (0 ~ 1.0)
		int angle = f * 180;			// 각도로 변환 (0 ~ 180)
		int width = angle2width(angle);	// 펄스 폭으로 변환
		myServo.pulsewidth_us(width);
		wait_ms(5);
	}
}