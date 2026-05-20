
#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 2     
#define DHTTYPE DHT11   
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.setCursor(0, 0);
  lcd.print("Task 3: Temp");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature(); 
  if (isnan(temp)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }
 lcd.setCursor(0, 0);
  lcd.print("System Active  ");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C   ");

  delay(2000); 
}
