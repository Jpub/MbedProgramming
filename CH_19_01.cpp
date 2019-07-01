#include "mbed.h"
#include "HCSR04.h"

HCSR04 sensor(D2, D3);			// (Trig, Echo)

int main() {
	while(1){
		long distance = sensor.distance(CM);	// 거리 측정
		printf("Distance : %d\n", distance);
		wait(1);
	}
}