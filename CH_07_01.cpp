#include "mbed.h"

int main() {
	int sec = 1;

	printf("Hello World !\n");

	while(1) {
		wait(1);
		printf("This program runs since %d seconds.\n", sec++);
	}
}