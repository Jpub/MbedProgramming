int button_pin = pinNametoDigitalPin(PC_13);	// 내장 버튼 연결 핀
int LED_pin = pinNametoDigitalPin(PA_5);		// 내장 LED 연결 핀

void setup() {
	pinMode(button_pin, INPUT);			// 버튼 연결 핀을 입력으로 설정
	pinMode(LED_pin, OUTPUT);			// LED 연결 핀을 출력으로 설정
}

void loop() {
	int state = digitalRead(button_pin);		// 버튼 상태 읽기
	digitalWrite(LED_pin, !state);			// LED로 상태 출력
}