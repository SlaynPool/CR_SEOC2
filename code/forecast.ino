#include "WiFi.h" 
#include <HTTPClient.h>
#include "ArduinoJson.h"

const char* ssid="SlaynPool";
const char* password="123456789";

void setup() {
  Serial.begin(115200); // Pour afficher via la laison serie
  Serial.println("");
  
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


  
    HTTPClient http;
    http.begin("https://api.openweathermap.org/data/2.5/forecast?id=MaCleAPI");
    int HttpRetCode = http.GET();
    if(HttpRetCode > 0)
 {
  Serial.println("Donnees recues...");
  String json = http.getString();
  http.end();
 const size_t capacity = 40*JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(40) + 87*JSON_OBJECT_SIZE(1) + 41*JSON_OBJECT_SIZE(2) + 40*JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + 34*JSON_OBJECT_SIZE(7) + 7*JSON_OBJECT_SIZE(8) + 40*JSON_OBJECT_SIZE(9) + 9500;
DynamicJsonDocument doc(capacity);


deserializeJson(doc, json);

const char* cod = doc["cod"]; // "200"
int message = doc["message"]; // 0
int cnt = doc["cnt"]; // 40

JsonArray list = doc["list"];

JsonObject list_0 = list[0];
long list_0_dt = list_0["dt"]; // 1582815600

JsonObject list_0_main = list_0["main"];
float list_0_main_temp = list_0_main["temp"]; // 289.43
float list_0_main_feels_like = list_0_main["feels_like"]; // 282.83
float list_0_main_temp_min = list_0_main["temp_min"]; // 287.53
float list_0_main_temp_max = list_0_main["temp_max"]; // 289.43
int list_0_main_pressure = list_0_main["pressure"]; // 1010
int list_0_main_sea_level = list_0_main["sea_level"]; // 1010
int list_0_main_grnd_level = list_0_main["grnd_level"]; // 1009
int list_0_main_humidity = list_0_main["humidity"]; // 68
float list_0_main_temp_kf = list_0_main["temp_kf"]; // 1.9

JsonObject list_0_weather_0 = list_0["weather"][0];
int list_0_weather_0_id = list_0_weather_0["id"]; // 804
const char* list_0_weather_0_main = list_0_weather_0["main"]; // "Clouds"
const char* list_0_weather_0_description = list_0_weather_0["description"]; // "overcast clouds"
const char* list_0_weather_0_icon = list_0_weather_0["icon"]; // "04d"

int list_0_clouds_all = list_0["clouds"]["all"]; // 100

float list_0_wind_speed = list_0["wind"]["speed"]; // 9.63
int list_0_wind_deg = list_0["wind"]["deg"]; // 269

const char* list_0_sys_pod = list_0["sys"]["pod"]; // "d"

const char* list_0_dt_txt = list_0["dt_txt"]; // "2020-02-27 15:00:00"

JsonObject list_1 = list[1];
long list_1_dt = list_1["dt"]; // 1582826400

JsonObject list_1_main = list_1["main"];
float list_1_main_temp = list_1_main["temp"]; // 288.27
float list_1_main_feels_like = list_1_main["feels_like"]; // 281.76
float list_1_main_temp_min = list_1_main["temp_min"]; // 286.84
float list_1_main_temp_max = list_1_main["temp_max"]; // 288.27
int list_1_main_pressure = list_1_main["pressure"]; // 1012
int list_1_main_sea_level = list_1_main["sea_level"]; // 1012
int list_1_main_grnd_level = list_1_main["grnd_level"]; // 1011
int list_1_main_humidity = list_1_main["humidity"]; // 72
float list_1_main_temp_kf = list_1_main["temp_kf"]; // 1.43

JsonObject list_1_weather_0 = list_1["weather"][0];
int list_1_weather_0_id = list_1_weather_0["id"]; // 803
const char* list_1_weather_0_main = list_1_weather_0["main"]; // "Clouds"
const char* list_1_weather_0_description = list_1_weather_0["description"]; // "broken clouds"
const char* list_1_weather_0_icon = list_1_weather_0["icon"]; // "04n"

int list_1_clouds_all = list_1["clouds"]["all"]; // 82

float list_1_wind_speed = list_1["wind"]["speed"]; // 9.41
int list_1_wind_deg = list_1["wind"]["deg"]; // 266

const char* list_1_sys_pod = list_1["sys"]["pod"]; // "n"

const char* list_1_dt_txt = list_1["dt_txt"]; // "2020-02-27 18:00:00"

//CODE DE PARSAGE DONC TRES LONG donc je ne les pas mis en entier ici 
JsonObject list_39 = list[39];
long list_39_dt = list_39["dt"]; // 1583236800

JsonObject list_39_main = list_39["main"];
float list_39_main_temp = list_39_main["temp"]; // 283.26
float list_39_main_feels_like = list_39_main["feels_like"]; // 277.93
float list_39_main_temp_min = list_39_main["temp_min"]; // 283.26
float list_39_main_temp_max = list_39_main["temp_max"]; // 283.26
int list_39_main_pressure = list_39_main["pressure"]; // 1007
int list_39_main_sea_level = list_39_main["sea_level"]; // 1007
int list_39_main_grnd_level = list_39_main["grnd_level"]; // 1008
int list_39_main_humidity = list_39_main["humidity"]; // 59
int list_39_main_temp_kf = list_39_main["temp_kf"]; // 0

JsonObject list_39_weather_0 = list_39["weather"][0];
int list_39_weather_0_id = list_39_weather_0["id"]; // 804
const char* list_39_weather_0_main = list_39_weather_0["main"]; // "Clouds"
const char* list_39_weather_0_description = list_39_weather_0["description"]; // "overcast clouds"
const char* list_39_weather_0_icon = list_39_weather_0["icon"]; // "04d"

int list_39_clouds_all = list_39["clouds"]["all"]; // 97

float list_39_wind_speed = list_39["wind"]["speed"]; // 5.34
int list_39_wind_deg = list_39["wind"]["deg"]; // 251

const char* list_39_sys_pod = list_39["sys"]["pod"]; // "d"

const char* list_39_dt_txt = list_39["dt_txt"]; // "2020-03-03 12:00:00"

JsonObject city = doc["city"];
long city_id = city["id"]; // 2992165
const char* city_name = city["name"]; // "Arrondissement of Montpellier"

float city_coord_lat = city["coord"]["lat"]; // 43.6667
float city_coord_lon = city["coord"]["lon"]; // 3.8333

const char* city_country = city["country"]; // "FR"
int city_timezone = city["timezone"]; // 3600
long city_sunrise = city["sunrise"]; // 1582784759
long city_sunset = city["sunset"]; // 1582824562

 
  

Serial.println("Date: ");
Serial.println(list_39_dt_txt);
Serial.println("main_temp: ");
Serial.println(list_39_main_temp) ;
Serial.println("Date: ");
Serial.println(list_39_main_feels_like );
Serial.println("feels_like: ");
Serial.println(list_39_main_temp_min );
Serial.println("main_temp_min: ");
Serial.println( list_39_main_temp_max );
Serial.println("main_temp_max: ");
Serial.println( list_39_main_pressure );
Serial.println("main_pressure: ");
Serial.println(list_39_main_sea_level );
Serial.println("main_sea_level: ");
Serial.println( list_39_main_grnd_level );
Serial.println("main_grnd_level: ");
Serial.println( list_39_main_humidity );
Serial.println("main_humidity: ");
Serial.println(list_39_main_temp_kf );
Serial.println("main_temp_kf: ");

/*  
  
  
  Serial.println("City :");
  Serial.println(list_3_main);
  Serial.println("temp :");
  //Serial.println(main_temp);
  */
 }
 delay(5000);

    WiFi.disconnect(true);
     Serial.println("Deconnexion."); // On se deconnecte.
   }
  

void loop() {
 
}
