#define BLYNK_TEMPLATE_ID "TMPL3_-tQQj6v"
#define BLYNK_TEMPLATE_NAME "Temperature Monitor with XIAO ESP32 C6"
#define BLYNK_AUTH_TOKEN "_CPk4HIsdiImQWpjAAMtrsgTCs0Ynds562rxJdk"

#define BLYNK_PRINT Serial
#include <WiFi.h> 
#include <BlynkSimpleEsp32.h>

#include <DHT.h>


char auth[] = BLYNK_AUTH_TOKEN;


char ssid[] = "WiFi Username";  // type your wifi name
char pass[] = "WiFi Password";  // type your wifi password

BlynkTimer timer;


#define DHTPIN D2 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{   
  
  Serial.begin(115200);
  

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }
