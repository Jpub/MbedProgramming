#include "mbed.h"

Serial PC(SERIAL_TX, SERIAL_RX);	// PC와 UART 연결

DigitalOut relayControl(D3);		// 릴레이 제어 핀

int main() {
	while(1){
		if(PC.readable()){			// 데이터 수신 여부 확인
			char ch = PC.getc();

			if(ch == 'O' || ch == 'o'){
				relayControl = true;		// 릴레이 ON
				PC.printf("* Relay is ON.\n");	// ON 메시지 출력
			}
			else{
				relayControl = false;		// 릴레이 OFF
				PC.printf("* Relay is OFF.\n");	// OFF 메시지 출력
			}
		}
	}
}