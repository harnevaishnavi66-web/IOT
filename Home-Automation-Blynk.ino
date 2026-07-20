#define BLYNK_TEMPLATE_ID "TMPL3uBZRRuwG"
#define BLYNK_TEMPLATE_NAME "Home Automation IOT"
#define BLYNK_AUTH_TOKEN "IUhZeFqGS6q083E-Sa6MqraLaH1_8YUe"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Vaishnavi's A17";
char pass[] = "vaishnavi'sA17";

// Output Pins
#define LED1 D0
#define LED2 D1
#define LED3 D2

// Control D0 using Switch V0
BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if (value == 1)
    digitalWrite(LED1, HIGH);
  else
    digitalWrite(LED1, LOW);
}

// Control D1 using Switch V1
BLYNK_WRITE(V1)
{
  int value = param.asInt();

  if (value == 1)
    digitalWrite(LED2, HIGH);
  else
    digitalWrite(LED2, LOW);
}

// Control D2 using Switch V2
BLYNK_WRITE(V2)
{
  int value = param.asInt();

  if (value == 1)
    digitalWrite(LED3, HIGH);
  else
    digitalWrite(LED3, LOW);
}

void setup()
{
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}