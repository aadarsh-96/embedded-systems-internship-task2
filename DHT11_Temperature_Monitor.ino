#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int led = 13;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(led, OUTPUT);
}

void loop() {

  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Sensor Error");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 30) {
    digitalWrite(led, HIGH);
    Serial.println("ALERT: High Temperature!");
  }
  else {
    digitalWrite(led, LOW);
  }

  delay(2000);
}
