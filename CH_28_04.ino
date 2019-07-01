void setup() {
	Serial.begin(9600);			// 컴퓨터와 시리얼 통신 초기화
}

void loop() {
	int value = analogRead(A0);		// 가변저항 값 읽기
	Serial.println(value);			// 시리얼 모니터로 가변저항 값 출력
	delay(500);
}