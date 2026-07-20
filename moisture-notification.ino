#define BLYNK_TEMPLATE_ID "TMPL34I9OzB6U"
#define BLYNK_TEMPLATE_NAME "Receiver Data"
#define BLYNK_AUTH_TOKEN "E7lvd2kyCS5I2tv7ed5PwKFqXL2iPEKH"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Vaishnavi's A17";
char pass[] = "vaishnavi'sA17";

BlynkTimer timer;

#define SOIL_PIN A0

void sendSensor()
{
  int moisture = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  // Gauge on V2
  Blynk.virtualWrite(V2, moisture);

  // LED Widget on V1
 if (moisture < 500) {
    Blynk.logEvent("moisture_notification",
      String("Analog value high: ") + moisture);
  }
  else
  {
    Blynk.virtualWrite(V1, 0);
    Serial.println("Soil is Wet");
  }

  Serial.println("--------------------");
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}