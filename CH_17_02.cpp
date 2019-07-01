#include "mbed.h"

AnalogIn CdS(A0);			// 조도 센서 연결 핀

int main() {
	while(1) {
		float t = CdS.read();			// 0~1 사이 값 반환

		printf("%f\n", t);

		wait(1);					// 1초에 한 번 출력
	}
}