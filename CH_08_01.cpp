#include "mbed.h"

AnalogIn v_registor(A0);			// A0 핀에 가변저항 연결

int main() {
	while(1) {
		printf("%f\n", v_registor.read());	// 가변저항 값 출력
		wait(1);
	}
}