#include "mbed.h"

AnalogIn LM35(A1);			// 온도 센서 연결 핀

int main() {
	float t, voltage, tempC, tempF;

	while(1) {
		t = LM35.read(); 			// 0~1 사이 값 반환
		voltage = t * 3.3; 			// 실제 전압으로 변환
		tempC = voltage * 100; 		// 섭씨온도로 변환
		tempF = tempC * 1.8 + 32; 		// 화씨온도로 변환

		printf("%f C, %f F\n", tempC, tempF);

		wait(1); 					// 1초에 한 번 출력
	}
}