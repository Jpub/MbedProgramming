int LED_pin = pinNametoDigitalPin(PA_10); 	// D2 핀

void setup() {
}

void loop() {
	for(int i = 0; i < 256; i++){			// 점점 밝게
		analogWrite(LED_pin, i);
		delay(5);
	}
	for(int i = 255; i >= 0; i--){			// 점점 어둡게
		analogWrite(LED_pin, i);
		delay(5);
	}
}