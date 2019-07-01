#include "mbed.h"

Serial PC(USBTX, USBRX);

int main() {
	while(1) {
		// 수신 버퍼에 데이터가 있을 때 컴퓨터로부터 수신한 데이터를 다시 컴퓨터로 보냄
		if(PC.readable()){
			PC.putc(PC.getc());
		}
	}
}