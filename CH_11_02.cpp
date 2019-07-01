#include "mbed.h"

DigitalOut LED_1(D2), LED_2(D3);

int main() {
	while(1) {
		LED_1 = true;			//  (ON, ON)
		LED_2 = true;
		wait(0.5);
		
		LED_1 = false;			// (OFF, ON)
		LED_2 = true;
		wait(0.5);
		
		LED_1 = true;			// (ON, OFF)
		LED_2 = false;
		wait(0.5);
		
		LED_1 = false;			// (OFF, OFF)
		LED_2 = false;
		wait(0.5);
	}
}