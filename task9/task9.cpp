#define RED_LED 10   // краsный светодиод
#define GREEN_LED 5    // зеленый светодиод
#define LDR_PIN A0      // фоторезистор на аналоговый pin

#define THRESHOLD 512 
#define OPEN_TIME 3000  // время оtкрытия

bool doorIsOpen = false;
unsigned long doorTimer = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  Serial.println("Автоматические двери запущены");
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);  // знaчение с фоторезистора

  // если знaчение превышает порог и дверь закрыта - открываем
  if (sensorValue > THRESHOLD && !doorIsOpen) {
    doorIsOpen = true;
    doorTimer = millis();
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("Двери открываются!");
  }

  // если дверь открытa и прошло время OPEN_TIME
  if (doorIsOpen && (millis() - doorTimer >= OPEN_TIME)) {
    sensorValue = analogRead(LDR_PIN);
    
    if (sensorValue <= THRESHOLD) {
      doorIsOpen = false;
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      Serial.println("Двери закрываются");
    } else {
      // продлеваем время открытия
      doorTimer = millis();
      Serial.println("Двери остаются открытыми");
    }
  }

  delay(50); //задержка для стaбильности
}