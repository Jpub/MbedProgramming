#include "mbed.h"

Serial PC(USBTX, USBRX);

int main() {
	while(1) {
		// 컴퓨터로부터 수신한 데이터를 다시 컴퓨터로 보냄
		PC.putc(PC.getc());
	}
}