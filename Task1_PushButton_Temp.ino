#include <LiquidCrystal.h>
#include <DHT.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

#define BUTTON_PIN 2     
#define DHTPIN 3         
#define DHTTYPE DHT11 //DHT SENSOR

DHT dht(DHTPIN, DHTTYPE);

int counter = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.begin(16, 2);
  dht.begin();
  
  lcd.setCursor(0, 0);
  lcd.print("Task 1 Ready!");
}

void loop() {
  int currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    counter++; 
    float temp = dht.readTemperature();
    
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Count: ");
    lcd.print(counter);
    
    lcd.setCursor(0, 1);
    if (isnan(temp)) {
      lcd.print("Temp Error!");
    } else {
      lcd.print("Temp: ");
      lcd.print(temp);
      lcd.print(" C");
    }
    delay(200); 
  }
  lastButtonState = currentButtonState;
}
