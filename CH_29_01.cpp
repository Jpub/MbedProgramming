#include "mbed.h"

// 아두이노와 연결하는 UART1 포트 (TX, RX)
Serial ArduinoSerial(PA_9, PA_10);
// 컴퓨터와 연결하는 UART2 포트
Serial PC(SERIAL_TX, SERIAL_RX);

int main() {
	while(1) {
		if(PC.readable()){			// 컴퓨터로부터의 수신 데이터 확인
			char ch = PC.getc();
			ArduinoSerial.putc(ch);		// 아두이노로 송신
		}
		if(ArduinoSerial.readable()){		// 아두이노로부터의 수신 데이터 확인
			char ch = ArduinoSerial.getc();
			PC.putc(ch);			// 컴퓨터로 송신
		}
	}
}