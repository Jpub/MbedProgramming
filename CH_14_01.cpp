#include "mbed.h"
#include "DS1820.h"

Serial serial(USBTX, USBRX);

int main() {
	DS1820 ds1820(D2);			// DS1820 센서 객체 생성

	if(ds1820.begin()) {			// 1-Wire 통신과 센서 초기화
		while(1) {
			ds1820.startConversion();		// 온도 변환 시작
			wait(1.0);				// 온도 변환 대기
			// 온도를 읽어서 출력
			printf("Temperature = %3.1f\n", ds1820.read());
		}
	} else {
		printf("No DS1820 sensor found!\n");
	}
}
