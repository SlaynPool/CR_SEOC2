#include "WiFi.h" 
#include <HTTPClient.h>
#include "ArduinoJson.h"
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 23     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid="SlaynPool";
const char* password="123456789";
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  
  WiFi.mode(WIFI_STA); // Configurer en Station WiFi
 
  WiFi.disconnect(); 
  WiFi.setHostname("Mon_systeme"); // Le nom avec lequel le systeme sera vu sur le reseau
  WiFi.begin(ssid,password); // Demande de connexion au reseau WiFi
  while(WiFi.status() != WL_CONNECTED)
    { Serial.println("Tentative de connexion...");
      delay(1000);
    }
    Serial.println("");
   Serial.println("Connecte au reseau WiFi !");

  lcd.init();                      // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
}


void loop() {
  delay(2000);
  
    HTTPClient http;
    http.begin("https://api.openweathermap.org/data/2.5/weather?id=MaCleAPI");
    int HttpRetCode = http.GET();
    if(HttpRetCode > 0)
 {
  Serial.println("Donnees recues...");
  String json = http.getString();
  http.end();


  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);



const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(13);
DynamicJsonDocument doc(capacity);
deserializeJson(doc, json);

float coord_lon = doc["coord"]["lon"]; // 3.25
float coord_lat = doc["coord"]["lat"]; // 43.35

JsonObject weather_0 = doc["weather"][0];
int weather_0_id = weather_0["id"]; // 804
const char* weather_0_main = weather_0["main"]; // "Clouds"
const char* weather_0_description = weather_0["description"]; // "overcast clouds"
const char* weather_0_icon = weather_0["icon"]; // "04d"

const char* base = doc["base"]; // "stations"

JsonObject main = doc["main"];
float main_temp = main["temp"]; // 288.75
float main_feels_like = main["feels_like"]; // 281.68
float main_temp_min = main["temp_min"]; // 286.48
float main_temp_max = main["temp_max"]; // 291.15
int main_pressure = main["pressure"]; // 1010
int main_humidity = main["humidity"]; // 59

int visibility = doc["visibility"]; // 10000

JsonObject wind = doc["wind"];
float wind_speed = wind["speed"]; // 9.3
int wind_deg = wind["deg"]; // 270
float wind_gust = wind["gust"]; // 14.9

int clouds_all = doc["clouds"]["all"]; // 90

long dt = doc["dt"]; // 1582817395

JsonObject sys = doc["sys"];
int sys_type = sys["type"]; // 1
int sys_id = sys["id"]; // 6519
const char* sys_country = sys["country"]; // "FR"
long sys_sunrise = sys["sunrise"]; // 1582784879
long sys_sunset = sys["sunset"]; // 1582824723

int timezone = doc["timezone"]; // 3600
long id = doc["id"]; // 6455063
const char* name = doc["name"]; // "Béziers"
int cod = doc["cod"]; // 200

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.println("");
  Serial.println("-----OPENWEATHERMAP DATA-----");
  Serial.print(F("Humidity: "));
  Serial.print(main_humidity);

  Serial.print(F("%  Temperature: "));
  Serial.println       (main_temp - 273,15 );
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Humi:");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("HumiOWM: ");
  lcd.print(main_humidity);
}
}
