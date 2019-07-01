#include "mbed.h"

AnalogIn sensor(A0);

int main() {
	while(1){
		float voltage = sensor.read() * 3.3;	// 입력 전압
		float distance = 27.86 * pow((double)voltage, -1.15);

		printf("Read = %5.2f, Distance = %.2f Cm\n", voltage, distance);
		wait(1);
	}
}