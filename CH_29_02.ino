#include <SoftwareSerial.h>

SoftwareSerial NeucleoSerial(2, 3);

void setup() {
	// 컴퓨터와 연결하는 하드웨어 UART 포트 초기화
	Serial.begin(9600);
	// 누클레오 보드와 연결하는 소프트웨어 UART 포트 초기화
	NeucleoSerial.begin(9600);
}

void loop() {
	if(Serial.available()){			// 컴퓨터로부터의 수신 데이터 확인
		char ch = Serial.read();
		NeucleoSerial.write(ch);		// 누클레오 보드로 송신
	}

	if(NeucleoSerial.available()){		// 누클레오 보드로부터의 수신 데이터 확인
		char ch = NeucleoSerial.read();
		Serial.write(ch);			// 컴퓨터로 송신
	}
}