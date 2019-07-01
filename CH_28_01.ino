void setup() {
	pinMode(LED_BUILTIN, OUTPUT);	// LED 연결 핀을 출력으로 설정
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);	// LED 연결 핀에 HIGH 출력
	delay(1000);				// 1초 대기
	digitalWrite(LED_BUILTIN, LOW);	// LED 연결 핀에 LOW 출력
	delay(1000);
}