#include <Stepper.h>

const int stepsPerRevolution = 200; // Stepper motorun adım sayısı
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // Stepper motorun bağlı olduğu pinler

const int clockwiseButtonPin = 2; // Saat yönü dönüşü için kullanılacak tuş pin'i
const int counterclockwiseButtonPin = 3; // Ters yönde dönüş için kullanılacak tuş pin'i

void setup() {
  Serial.begin(9600); // Seri haberleşmeyi başlat

  pinMode(clockwiseButtonPin, INPUT_PULLUP); // Saat yönü tuşu pin'ini giriş olarak ayarla
  pinMode(counterclockwiseButtonPin, INPUT_PULLUP); // Ters yönde tuşu pin'ini giriş olarak ayarla
}

void loop() {
  if (digitalRead(clockwiseButtonPin) == LOW) { // Saat yönü tuşuna basıldığında
    while (digitalRead(clockwiseButtonPin) == LOW) { // Tuş basılı olduğu sürece devam et
      myStepper.setSpeed(100); // Motor hızını ayarla (rpm cinsinden)
      myStepper.step(stepsPerRevolution); // Saat yönünde adım at
    }
  }

  if (digitalRead(counterclockwiseButtonPin) == LOW) { // Ters yönde tuşa basıldığında
    while (digitalRead(counterclockwiseButtonPin) == LOW) { // Tuş basılı olduğu sürece devam et
      myStepper.setSpeed(100); // Motor hızını ayarla (rpm cinsinden)
      myStepper.step(-stepsPerRevolution); // Ters yönde adım at
    }
  }
}
