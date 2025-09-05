#define LED_PIN1 5 // 첫 번째 LED 핀 번호 5
#define LED_PIN2 19 // 두 번째 LED 핀 번호 19
#define BUTTON_PIN 4  // 버튼 핀 4번

bool ledState = false; // LED 꺼짐 상태 저장 변수

void setup() {
  pinMode(LED_PIN1, OUTPUT);   // LED1 출력 설정
  pinMode(LED_PIN2, OUTPUT);   // LED2 출력 설정
  pinMode(BUTTON_PIN, INPUT_PULLUP;  // 버튼 입력(풀업 저항 활성화 - 기본 HIGH, 누르면 LOW)

  digitalWrite(LED_PIN1, LOW);  // 초기 LED 꺼짐
  digitalWrite(LED_PIN2, LOW);  // 초기 LED2 꺼짐
}

void loop() {
  // 버튼을 풀업 상태이므로 누르면 LOW, 안 누르면 HIGH
  if (digitalRead(BUTTON_PIN) == LOW) {  // 만약 버튼핀이 LOW일 경우(버튼이 눌러졌을 경우)
    delay(50);  // 단순 디바운스(HIGH/LOW가 여러번 바뀌는 것을 0.005초만큼 기다리기)

    // 버튼이 눌린 순간 LED 상태를 켰다 껐다 반복
    ledState = !ledState;  // 아까 위에서 ledState = false라 선언했기 때문에 여기서는 false를 true로 바꾸는 것

    digitalWrite(LED_PIN1, ledState);  // 버튼을 누르면 경우 LED가 둘 다 켜짐
    digitalWrite(LED_PIN2, ledState);  // LED1, LED2가 둘 다 동일한 상태이기 때문에 버튼을 누르면 켜지는 것을 할 수 있지만 LED 2개를 번갈아 켜고 싶다면 (LED_PIN2, !ledState)로 변경하면 됌

    while (digitalRead(BUTTON_PIN) == LOW); // 버튼이 HIGH로 바뀔 때까지 기다리기
    delay(50);  // 추가 디바운
  }
}
