#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// IR Receiver Pin
#define IR_PIN 2

// LED Pins
#define LED1 7
#define LED2 8
#define LED3 9

// Your Remote Codes
#define BUTTON_1 0xF50A7F80
#define BUTTON_2 0xE41B7F80
#define BUTTON_3 0xE01F7F80
#define BUTTON_POWER 0xED127F80

bool state1 = false;
bool state2 = false;
bool state3 = false;

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Home");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (IrReceiver.decode()) {

    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(code, HEX);

    if (code == BUTTON_1) {
      state1 = !state1;
      digitalWrite(LED1, state1);

      lcd.clear();
      lcd.print("Light 1:");
      lcd.print(state1 ? " ON" : " OFF");
    }

    else if (code == BUTTON_2) {
      state2 = !state2;
      digitalWrite(LED2, state2);

      lcd.clear();
      lcd.print("Light 2:");
      lcd.print(state2 ? " ON" : " OFF");
    }

    else if (code == BUTTON_3) {
      state3 = !state3;
      digitalWrite(LED3, state3);

      lcd.clear();
      lcd.print("Fan:");
      lcd.print(state3 ? " ON" : " OFF");
    }

    else if (code == BUTTON_POWER) {
      state1 = state2 = state3 = false;

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);

      lcd.clear();
      lcd.print("All Devices");
      lcd.setCursor(0, 1);
      lcd.print("Turned OFF");
    }

    IrReceiver.resume();
  }
} 