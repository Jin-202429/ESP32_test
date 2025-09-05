#define LED_PIN1 5  // LED 연결된 GPIO 5번
#define LED_PIN2 19 // LED 연결된 GPIO 19번

// millis()를 이용해 시간 간격을 제어하기 위한 변수
unsigned long previousMillis = 0; // 마지막으로 LED 상태를 바꾼 시간 저장
const long interval = 2000;       // LED 전환 간격(2초)

// LED의 현재 상태를 저장하는 변수
bool ledState1 = false; // LED1은 처음에 꺼진 상태
bool ledState2 = true;  // LED2은 처음에 켜진 상태

void setup() {
  pinMode(LED_PIN1, OUTPUT);   // LED1 핀 출력
  pinMode(LED_PIN2, OUTPUT);   // LED2 핀 출력

  digitalWrite(LED_PIN1, ledState1);  // digitalWrite()는 켜짐 또는 꺼짐으로 설정하는 함수이며 bool ledState1에서 LED의 상태를 정의했으므로 LED1은 꺼진 상태
  digitalWrite(LED_PIN2, ledState2);  // LED2는 켜진 상태
}

void loop() {
  usingned long currentMillis = millis();  // 실행 후 흐른 시간(ms) 읽기

  if (currentMillis - previousMillis >= interval) {  // 만약 지금시간(currentMillis) - 마지막으로 LED를 바꾼 시간(previousMillis) >= 2000(아까 위에서 2초로 정의함)이면
    preivousMillis = currentMillis;    // 마지막 시간 갱신 (LED를 바꿨으므로 바꾼 시간을 previousMillis에 저장)

    // LED 상태를 토글
    ledState1 = !ledState1;  // !는 논리 연산자로 LED1은 꺼져 있었으므로 켠 상태로 변경
    ledState2 = !ledState2;  // LED2는 켠 상태였으므로 꺼진 상태로 변경

    digitalWrite (LED_PIN1, ledState1);  // LED가 바뀐 상태를 적용 -> 2초마다 LED1과 LED2가 번갈아 가면 깜빡임
    digitalWrite (LED_PIN2, ledState2);
  }
}



