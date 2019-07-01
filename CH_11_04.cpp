#include "mbed.h"

Timer t;

int main() {
	t.start();						// 타이머 시작
	printf("Hello World!\n");
	t.stop();						// 타이머 중지
	printf("The time taken was %f seconds.\n", t.read());
}