#define LED_PIN1 5  // LED1을 연결한 핀 번호는 GPIO 5
#define LED_PIN2 19  // LED2을 연결한 핀 번호는 GPIO 19

void setup() {
  pinMode(LED_PIN1, OUTPUT);  // LED1을 출력 모드로 설정
  pinMode(LED_PIN2, OUTPUT);  // LED2를 출력 모드로 설정
}

void loop() {
  digitalWrite(LED_PIN1, HIGH);  // LED1 켜기
  digitalWrite(LED_PIN2, LOW);   // LED2 끄기
  delay(1000);                   // 1초 동안 유지

  digitalWrite(LED_PIN1, LOW);   // LED1 끄기
  digitalWrite(LED_PIN2, HIGH);  // LED2 켜기
  delay(1000);                   // 1초 동안 유지
}



