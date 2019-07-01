#include "mbed.h"

// UART1 포트, 블루투스 모듈 연결
Serial BLUETOOTH(PA_9, PA_10, 9600);
// UART2 포트, 컴퓨터 연결
Serial PC(USBTX, USBRX);

int main() {
	while(1) {
		// 터미널 프로그램 → 누클레오 보드 → 블루투스 모듈
		if(PC.readable()){
			BLUETOOTH.putc(PC.getc());
		}

		// 블루투스 모듈 → 누클레오 보드 → 터미널 프로그램
		if(BLUETOOTH.readable()){
			PC.putc(BLUETOOTH.getc());
		}
	}
}