#define Y_LED 18 // 첫 번째 LED 
#define G_LED 5  // 두 번째 LED
#define LDR_PIN 34  // 조도센서 아날로그 연결 핀 (ESP32의 34번)

void setup() {
  Serial.begin(115200);  // 시리얼 통신을 115200을 설정 -> 잘 연결되었는지 확인용

  pinMode(Y_LED, OUTPUT);  // 노란색 LED 출력
  pinMode(G_LED, OUTPUT);  // 초록색 LED 출력
}

void loop() {
  int lbrValue = analogRead(LDR_PIN);  // 조도센서 값(0 ~ 4095)을 변수에 저장
  Serial.print("LDR Value:");  // 시니얼 모니터에 출력
  Serial.println("lbrValue");  // 조도센서 값을 시리얼 모니터에 출력 후 한 줄 띄어쓰기

  if (lbrValue < 2000) {  // 만약 조도센서의 값이 2000 미만일 경우 (빛의 세기가 2000보다 약할 경우) 
    digitalWrite (Y_LED, HIGH); // 노란색 LED 켜기
    digitalWrite (G_LED, LOW);  // 초록색 LED 끄기
  }
  else {  // 그렇지 않다면 (빛의 세기가 강할 경우)
    digitalWrite(G_LED, HIGH); // 초록색 LED 켜기
    digitalWrite(Y_LED, LOW);  // 노란색 LED 끄기
  }
  delay(500);  // 0.5초마다 LED 상태 변환
}