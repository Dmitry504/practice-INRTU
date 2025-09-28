#include <Servo.h>

Servo servo;
int currentPos = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(currentPos);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    bool validInput = true;
    for (unsigned int i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        validInput = false;
        break;
      }
    }

    if (validInput) {
      int targetAngle = input.toInt();

      if (targetAngle >= 0 && targetAngle <= 180) {
        if (targetAngle != currentPos) {
          Serial.print("Поворот на: ");
          Serial.println(targetAngle);

          if (targetAngle > currentPos) {
            for (int pos = currentPos; pos <= targetAngle; pos++) {
              servo.write(pos);
              delay(10);
            }
          } else {
            for (int pos = currentPos; pos >= targetAngle; pos--) {
              servo.write(pos);
              delay(10);
            }
          }

          currentPos = targetAngle;
        }
      } else {
        Serial.println("Ошибка: допустимый диапазон 0-180");
      }
    } else {
      Serial.println("Ошибка: вводите только цифры");
    }

    Serial.println("Введите угол от 0 до 180:");
  }
}