#include "WiFi.h" 
#include <HTTPClient.h>
#include "ArduinoJson.h"

const char* ssid="SlaynPool";
const char* password="123456789";

void setup() {
  Serial.begin(115200); // Pour afficher via la laison série
  Serial.println("");
  
  WiFi.mode(WIFI_STA); // Configurer en Station WiFi
 
  WiFi.disconnect(); 
   WiFi.setHostname("Mon_systeme"); // Le nom avec lequel le système sera vu sur le réseau
  WiFi.begin(ssid,password); // Demande de connexion au réseau WiFi
  while(WiFi.status() != WL_CONNECTED)
    { Serial.println("Tentative de connexion...");
      delay(1000);
    }
    Serial.println("");
   Serial.println("Connecté au réseau WiFi !");


  
    HTTPClient http;
    http.begin("https://api.openweathermap.org/data/2.5/forecast?id=2992165&appid=bfa8739375836a21624754dafe5fce73");
    int HttpRetCode = http.GET();
    if(HttpRetCode > 0)
 {
  Serial.println("Données reçues...");
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

JsonObject list_2 = list[2];
long list_2_dt = list_2["dt"]; // 1582837200

JsonObject list_2_main = list_2["main"];
float list_2_main_temp = list_2_main["temp"]; // 287.28
float list_2_main_feels_like = list_2_main["feels_like"]; // 282.4
float list_2_main_temp_min = list_2_main["temp_min"]; // 286.33
float list_2_main_temp_max = list_2_main["temp_max"]; // 287.28
int list_2_main_pressure = list_2_main["pressure"]; // 1015
int list_2_main_sea_level = list_2_main["sea_level"]; // 1015
int list_2_main_grnd_level = list_2_main["grnd_level"]; // 1014
int list_2_main_humidity = list_2_main["humidity"]; // 74
float list_2_main_temp_kf = list_2_main["temp_kf"]; // 0.95

JsonObject list_2_weather_0 = list_2["weather"][0];
int list_2_weather_0_id = list_2_weather_0["id"]; // 802
const char* list_2_weather_0_main = list_2_weather_0["main"]; // "Clouds"
const char* list_2_weather_0_description = list_2_weather_0["description"]; // "scattered clouds"
const char* list_2_weather_0_icon = list_2_weather_0["icon"]; // "03n"

int list_2_clouds_all = list_2["clouds"]["all"]; // 44

float list_2_wind_speed = list_2["wind"]["speed"]; // 6.87
int list_2_wind_deg = list_2["wind"]["deg"]; // 253

const char* list_2_sys_pod = list_2["sys"]["pod"]; // "n"

const char* list_2_dt_txt = list_2["dt_txt"]; // "2020-02-27 21:00:00"

JsonObject list_3 = list[3];
long list_3_dt = list_3["dt"]; // 1582848000

JsonObject list_3_main = list_3["main"];
float list_3_main_temp = list_3_main["temp"]; // 284.25
float list_3_main_feels_like = list_3_main["feels_like"]; // 279.67
float list_3_main_temp_min = list_3_main["temp_min"]; // 283.77
float list_3_main_temp_max = list_3_main["temp_max"]; // 284.25
int list_3_main_pressure = list_3_main["pressure"]; // 1019
int list_3_main_sea_level = list_3_main["sea_level"]; // 1019
int list_3_main_grnd_level = list_3_main["grnd_level"]; // 1018
int list_3_main_humidity = list_3_main["humidity"]; // 72
float list_3_main_temp_kf = list_3_main["temp_kf"]; // 0.48

JsonObject list_3_weather_0 = list_3["weather"][0];
int list_3_weather_0_id = list_3_weather_0["id"]; // 801
const char* list_3_weather_0_main = list_3_weather_0["main"]; // "Clouds"
const char* list_3_weather_0_description = list_3_weather_0["description"]; // "few clouds"
const char* list_3_weather_0_icon = list_3_weather_0["icon"]; // "02n"

int list_3_clouds_all = list_3["clouds"]["all"]; // 22

float list_3_wind_speed = list_3["wind"]["speed"]; // 5.3
int list_3_wind_deg = list_3["wind"]["deg"]; // 25

const char* list_3_sys_pod = list_3["sys"]["pod"]; // "n"

const char* list_3_dt_txt = list_3["dt_txt"]; // "2020-02-28 00:00:00"

JsonObject list_4 = list[4];
long list_4_dt = list_4["dt"]; // 1582858800

JsonObject list_4_main = list_4["main"];
float list_4_main_temp = list_4_main["temp"]; // 282.07
float list_4_main_feels_like = list_4_main["feels_like"]; // 278.43
float list_4_main_temp_min = list_4_main["temp_min"]; // 282.07
float list_4_main_temp_max = list_4_main["temp_max"]; // 282.07
int list_4_main_pressure = list_4_main["pressure"]; // 1020
int list_4_main_sea_level = list_4_main["sea_level"]; // 1020
int list_4_main_grnd_level = list_4_main["grnd_level"]; // 1019
int list_4_main_humidity = list_4_main["humidity"]; // 69
int list_4_main_temp_kf = list_4_main["temp_kf"]; // 0

JsonObject list_4_weather_0 = list_4["weather"][0];
int list_4_weather_0_id = list_4_weather_0["id"]; // 800
const char* list_4_weather_0_main = list_4_weather_0["main"]; // "Clear"
const char* list_4_weather_0_description = list_4_weather_0["description"]; // "clear sky"
const char* list_4_weather_0_icon = list_4_weather_0["icon"]; // "01n"

int list_4_clouds_all = list_4["clouds"]["all"]; // 10

float list_4_wind_speed = list_4["wind"]["speed"]; // 3.2
int list_4_wind_deg = list_4["wind"]["deg"]; // 37

const char* list_4_sys_pod = list_4["sys"]["pod"]; // "n"

const char* list_4_dt_txt = list_4["dt_txt"]; // "2020-02-28 03:00:00"

JsonObject list_5 = list[5];
long list_5_dt = list_5["dt"]; // 1582869600

JsonObject list_5_main = list_5["main"];
float list_5_main_temp = list_5_main["temp"]; // 280.33
float list_5_main_feels_like = list_5_main["feels_like"]; // 273.97
float list_5_main_temp_min = list_5_main["temp_min"]; // 280.33
float list_5_main_temp_max = list_5_main["temp_max"]; // 280.33
int list_5_main_pressure = list_5_main["pressure"]; // 1021
int list_5_main_sea_level = list_5_main["sea_level"]; // 1021
int list_5_main_grnd_level = list_5_main["grnd_level"]; // 1020
int list_5_main_humidity = list_5_main["humidity"]; // 68
int list_5_main_temp_kf = list_5_main["temp_kf"]; // 0

JsonObject list_5_weather_0 = list_5["weather"][0];
int list_5_weather_0_id = list_5_weather_0["id"]; // 801
const char* list_5_weather_0_main = list_5_weather_0["main"]; // "Clouds"
const char* list_5_weather_0_description = list_5_weather_0["description"]; // "few clouds"
const char* list_5_weather_0_icon = list_5_weather_0["icon"]; // "02n"

int list_5_clouds_all = list_5["clouds"]["all"]; // 12

float list_5_wind_speed = list_5["wind"]["speed"]; // 6.62
int list_5_wind_deg = list_5["wind"]["deg"]; // 14

const char* list_5_sys_pod = list_5["sys"]["pod"]; // "n"

const char* list_5_dt_txt = list_5["dt_txt"]; // "2020-02-28 06:00:00"

JsonObject list_6 = list[6];
long list_6_dt = list_6["dt"]; // 1582880400

JsonObject list_6_main = list_6["main"];
float list_6_main_temp = list_6_main["temp"]; // 280.9
float list_6_main_feels_like = list_6_main["feels_like"]; // 277.12
float list_6_main_temp_min = list_6_main["temp_min"]; // 280.9
float list_6_main_temp_max = list_6_main["temp_max"]; // 280.9
int list_6_main_pressure = list_6_main["pressure"]; // 1020
int list_6_main_sea_level = list_6_main["sea_level"]; // 1020
int list_6_main_grnd_level = list_6_main["grnd_level"]; // 1020
int list_6_main_humidity = list_6_main["humidity"]; // 65
int list_6_main_temp_kf = list_6_main["temp_kf"]; // 0

JsonObject list_6_weather_0 = list_6["weather"][0];
int list_6_weather_0_id = list_6_weather_0["id"]; // 800
const char* list_6_weather_0_main = list_6_weather_0["main"]; // "Clear"
const char* list_6_weather_0_description = list_6_weather_0["description"]; // "clear sky"
const char* list_6_weather_0_icon = list_6_weather_0["icon"]; // "01d"

int list_6_clouds_all = list_6["clouds"]["all"]; // 0

float list_6_wind_speed = list_6["wind"]["speed"]; // 2.92
int list_6_wind_deg = list_6["wind"]["deg"]; // 358

const char* list_6_sys_pod = list_6["sys"]["pod"]; // "d"

const char* list_6_dt_txt = list_6["dt_txt"]; // "2020-02-28 09:00:00"

JsonObject list_7 = list[7];
long list_7_dt = list_7["dt"]; // 1582891200

JsonObject list_7_main = list_7["main"];
float list_7_main_temp = list_7_main["temp"]; // 282.34
float list_7_main_feels_like = list_7_main["feels_like"]; // 279.83
float list_7_main_temp_min = list_7_main["temp_min"]; // 282.34
float list_7_main_temp_max = list_7_main["temp_max"]; // 282.34
int list_7_main_pressure = list_7_main["pressure"]; // 1019
int list_7_main_sea_level = list_7_main["sea_level"]; // 1019
int list_7_main_grnd_level = list_7_main["grnd_level"]; // 1019
int list_7_main_humidity = list_7_main["humidity"]; // 59
int list_7_main_temp_kf = list_7_main["temp_kf"]; // 0

JsonObject list_7_weather_0 = list_7["weather"][0];
int list_7_weather_0_id = list_7_weather_0["id"]; // 800
const char* list_7_weather_0_main = list_7_weather_0["main"]; // "Clear"
const char* list_7_weather_0_description = list_7_weather_0["description"]; // "clear sky"
const char* list_7_weather_0_icon = list_7_weather_0["icon"]; // "01d"

int list_7_clouds_all = list_7["clouds"]["all"]; // 1

float list_7_wind_speed = list_7["wind"]["speed"]; // 1.1
int list_7_wind_deg = list_7["wind"]["deg"]; // 59

const char* list_7_sys_pod = list_7["sys"]["pod"]; // "d"

const char* list_7_dt_txt = list_7["dt_txt"]; // "2020-02-28 12:00:00"

JsonObject list_8 = list[8];
long list_8_dt = list_8["dt"]; // 1582902000

JsonObject list_8_main = list_8["main"];
float list_8_main_temp = list_8_main["temp"]; // 284.34
float list_8_main_feels_like = list_8_main["feels_like"]; // 280.56
float list_8_main_temp_min = list_8_main["temp_min"]; // 284.34
float list_8_main_temp_max = list_8_main["temp_max"]; // 284.34
int list_8_main_pressure = list_8_main["pressure"]; // 1018
int list_8_main_sea_level = list_8_main["sea_level"]; // 1018
int list_8_main_grnd_level = list_8_main["grnd_level"]; // 1018
int list_8_main_humidity = list_8_main["humidity"]; // 52
int list_8_main_temp_kf = list_8_main["temp_kf"]; // 0

JsonObject list_8_weather_0 = list_8["weather"][0];
int list_8_weather_0_id = list_8_weather_0["id"]; // 802
const char* list_8_weather_0_main = list_8_weather_0["main"]; // "Clouds"
const char* list_8_weather_0_description = list_8_weather_0["description"]; // "scattered clouds"
const char* list_8_weather_0_icon = list_8_weather_0["icon"]; // "03d"

int list_8_clouds_all = list_8["clouds"]["all"]; // 33

float list_8_wind_speed = list_8["wind"]["speed"]; // 2.94
int list_8_wind_deg = list_8["wind"]["deg"]; // 152

const char* list_8_sys_pod = list_8["sys"]["pod"]; // "d"

const char* list_8_dt_txt = list_8["dt_txt"]; // "2020-02-28 15:00:00"

JsonObject list_9 = list[9];
long list_9_dt = list_9["dt"]; // 1582912800

JsonObject list_9_main = list_9["main"];
float list_9_main_temp = list_9_main["temp"]; // 285.21
float list_9_main_feels_like = list_9_main["feels_like"]; // 281.84
float list_9_main_temp_min = list_9_main["temp_min"]; // 285.21
float list_9_main_temp_max = list_9_main["temp_max"]; // 285.21
int list_9_main_pressure = list_9_main["pressure"]; // 1018
int list_9_main_sea_level = list_9_main["sea_level"]; // 1018
int list_9_main_grnd_level = list_9_main["grnd_level"]; // 1017
int list_9_main_humidity = list_9_main["humidity"]; // 68
int list_9_main_temp_kf = list_9_main["temp_kf"]; // 0

JsonObject list_9_weather_0 = list_9["weather"][0];
int list_9_weather_0_id = list_9_weather_0["id"]; // 803
const char* list_9_weather_0_main = list_9_weather_0["main"]; // "Clouds"
const char* list_9_weather_0_description = list_9_weather_0["description"]; // "broken clouds"
const char* list_9_weather_0_icon = list_9_weather_0["icon"]; // "04n"

int list_9_clouds_all = list_9["clouds"]["all"]; // 67

float list_9_wind_speed = list_9["wind"]["speed"]; // 3.61
int list_9_wind_deg = list_9["wind"]["deg"]; // 197

const char* list_9_sys_pod = list_9["sys"]["pod"]; // "n"

const char* list_9_dt_txt = list_9["dt_txt"]; // "2020-02-28 18:00:00"

JsonObject list_10 = list[10];
long list_10_dt = list_10["dt"]; // 1582923600

JsonObject list_10_main = list_10["main"];
float list_10_main_temp = list_10_main["temp"]; // 285.89
float list_10_main_feels_like = list_10_main["feels_like"]; // 284.78
float list_10_main_temp_min = list_10_main["temp_min"]; // 285.89
float list_10_main_temp_max = list_10_main["temp_max"]; // 285.89
int list_10_main_pressure = list_10_main["pressure"]; // 1017
int list_10_main_sea_level = list_10_main["sea_level"]; // 1017
int list_10_main_grnd_level = list_10_main["grnd_level"]; // 1017
int list_10_main_humidity = list_10_main["humidity"]; // 86
int list_10_main_temp_kf = list_10_main["temp_kf"]; // 0

JsonObject list_10_weather_0 = list_10["weather"][0];
int list_10_weather_0_id = list_10_weather_0["id"]; // 804
const char* list_10_weather_0_main = list_10_weather_0["main"]; // "Clouds"
const char* list_10_weather_0_description = list_10_weather_0["description"]; // "overcast clouds"
const char* list_10_weather_0_icon = list_10_weather_0["icon"]; // "04n"

int list_10_clouds_all = list_10["clouds"]["all"]; // 100

float list_10_wind_speed = list_10["wind"]["speed"]; // 1.83
int list_10_wind_deg = list_10["wind"]["deg"]; // 177

const char* list_10_sys_pod = list_10["sys"]["pod"]; // "n"

const char* list_10_dt_txt = list_10["dt_txt"]; // "2020-02-28 21:00:00"

JsonObject list_11 = list[11];
long list_11_dt = list_11["dt"]; // 1582934400

JsonObject list_11_main = list_11["main"];
float list_11_main_temp = list_11_main["temp"]; // 286.03
float list_11_main_feels_like = list_11_main["feels_like"]; // 282.93
float list_11_main_temp_min = list_11_main["temp_min"]; // 286.03
float list_11_main_temp_max = list_11_main["temp_max"]; // 286.03
int list_11_main_pressure = list_11_main["pressure"]; // 1015
int list_11_main_sea_level = list_11_main["sea_level"]; // 1015
int list_11_main_grnd_level = list_11_main["grnd_level"]; // 1015
int list_11_main_humidity = list_11_main["humidity"]; // 87
int list_11_main_temp_kf = list_11_main["temp_kf"]; // 0

JsonObject list_11_weather_0 = list_11["weather"][0];
int list_11_weather_0_id = list_11_weather_0["id"]; // 804
const char* list_11_weather_0_main = list_11_weather_0["main"]; // "Clouds"
const char* list_11_weather_0_description = list_11_weather_0["description"]; // "overcast clouds"
const char* list_11_weather_0_icon = list_11_weather_0["icon"]; // "04n"

int list_11_clouds_all = list_11["clouds"]["all"]; // 100

float list_11_wind_speed = list_11["wind"]["speed"]; // 4.8
int list_11_wind_deg = list_11["wind"]["deg"]; // 161

const char* list_11_sys_pod = list_11["sys"]["pod"]; // "n"

const char* list_11_dt_txt = list_11["dt_txt"]; // "2020-02-29 00:00:00"

JsonObject list_12 = list[12];
long list_12_dt = list_12["dt"]; // 1582945200

JsonObject list_12_main = list_12["main"];
float list_12_main_temp = list_12_main["temp"]; // 286.23
float list_12_main_feels_like = list_12_main["feels_like"]; // 279.96
float list_12_main_temp_min = list_12_main["temp_min"]; // 286.23
float list_12_main_temp_max = list_12_main["temp_max"]; // 286.23
int list_12_main_pressure = list_12_main["pressure"]; // 1012
int list_12_main_sea_level = list_12_main["sea_level"]; // 1012
int list_12_main_grnd_level = list_12_main["grnd_level"]; // 1012
int list_12_main_humidity = list_12_main["humidity"]; // 86
int list_12_main_temp_kf = list_12_main["temp_kf"]; // 0

JsonObject list_12_weather_0 = list_12["weather"][0];
int list_12_weather_0_id = list_12_weather_0["id"]; // 500
const char* list_12_weather_0_main = list_12_weather_0["main"]; // "Rain"
const char* list_12_weather_0_description = list_12_weather_0["description"]; // "light rain"
const char* list_12_weather_0_icon = list_12_weather_0["icon"]; // "10n"

int list_12_clouds_all = list_12["clouds"]["all"]; // 96

float list_12_wind_speed = list_12["wind"]["speed"]; // 9.33
int list_12_wind_deg = list_12["wind"]["deg"]; // 135

float list_12_rain_3h = list_12["rain"]["3h"]; // 0.13

const char* list_12_sys_pod = list_12["sys"]["pod"]; // "n"

const char* list_12_dt_txt = list_12["dt_txt"]; // "2020-02-29 03:00:00"

JsonObject list_13 = list[13];
long list_13_dt = list_13["dt"]; // 1582956000

JsonObject list_13_main = list_13["main"];
float list_13_main_temp = list_13_main["temp"]; // 286.49
float list_13_main_feels_like = list_13_main["feels_like"]; // 278.14
float list_13_main_temp_min = list_13_main["temp_min"]; // 286.49
float list_13_main_temp_max = list_13_main["temp_max"]; // 286.49
int list_13_main_pressure = list_13_main["pressure"]; // 1010
int list_13_main_sea_level = list_13_main["sea_level"]; // 1010
int list_13_main_grnd_level = list_13_main["grnd_level"]; // 1009
int list_13_main_humidity = list_13_main["humidity"]; // 86
int list_13_main_temp_kf = list_13_main["temp_kf"]; // 0

JsonObject list_13_weather_0 = list_13["weather"][0];
int list_13_weather_0_id = list_13_weather_0["id"]; // 500
const char* list_13_weather_0_main = list_13_weather_0["main"]; // "Rain"
const char* list_13_weather_0_description = list_13_weather_0["description"]; // "light rain"
const char* list_13_weather_0_icon = list_13_weather_0["icon"]; // "10n"

int list_13_clouds_all = list_13["clouds"]["all"]; // 98

float list_13_wind_speed = list_13["wind"]["speed"]; // 12.41
int list_13_wind_deg = list_13["wind"]["deg"]; // 148

float list_13_rain_3h = list_13["rain"]["3h"]; // 0.5

const char* list_13_sys_pod = list_13["sys"]["pod"]; // "n"

const char* list_13_dt_txt = list_13["dt_txt"]; // "2020-02-29 06:00:00"

JsonObject list_14 = list[14];
long list_14_dt = list_14["dt"]; // 1582966800

JsonObject list_14_main = list_14["main"];
float list_14_main_temp = list_14_main["temp"]; // 286.62
float list_14_main_feels_like = list_14_main["feels_like"]; // 278.39
float list_14_main_temp_min = list_14_main["temp_min"]; // 286.62
float list_14_main_temp_max = list_14_main["temp_max"]; // 286.62
int list_14_main_pressure = list_14_main["pressure"]; // 1009
int list_14_main_sea_level = list_14_main["sea_level"]; // 1009
int list_14_main_grnd_level = list_14_main["grnd_level"]; // 1008
int list_14_main_humidity = list_14_main["humidity"]; // 87
int list_14_main_temp_kf = list_14_main["temp_kf"]; // 0

JsonObject list_14_weather_0 = list_14["weather"][0];
int list_14_weather_0_id = list_14_weather_0["id"]; // 500
const char* list_14_weather_0_main = list_14_weather_0["main"]; // "Rain"
const char* list_14_weather_0_description = list_14_weather_0["description"]; // "light rain"
const char* list_14_weather_0_icon = list_14_weather_0["icon"]; // "10d"

int list_14_clouds_all = list_14["clouds"]["all"]; // 100

float list_14_wind_speed = list_14["wind"]["speed"]; // 12.37
int list_14_wind_deg = list_14["wind"]["deg"]; // 156

float list_14_rain_3h = list_14["rain"]["3h"]; // 0.88

const char* list_14_sys_pod = list_14["sys"]["pod"]; // "d"

const char* list_14_dt_txt = list_14["dt_txt"]; // "2020-02-29 09:00:00"

JsonObject list_15 = list[15];
long list_15_dt = list_15["dt"]; // 1582977600

JsonObject list_15_main = list_15["main"];
float list_15_main_temp = list_15_main["temp"]; // 286.96
float list_15_main_feels_like = list_15_main["feels_like"]; // 280.73
float list_15_main_temp_min = list_15_main["temp_min"]; // 286.96
float list_15_main_temp_max = list_15_main["temp_max"]; // 286.96
int list_15_main_pressure = list_15_main["pressure"]; // 1008
int list_15_main_sea_level = list_15_main["sea_level"]; // 1008
int list_15_main_grnd_level = list_15_main["grnd_level"]; // 1007
int list_15_main_humidity = list_15_main["humidity"]; // 86
int list_15_main_temp_kf = list_15_main["temp_kf"]; // 0

JsonObject list_15_weather_0 = list_15["weather"][0];
int list_15_weather_0_id = list_15_weather_0["id"]; // 500
const char* list_15_weather_0_main = list_15_weather_0["main"]; // "Rain"
const char* list_15_weather_0_description = list_15_weather_0["description"]; // "light rain"
const char* list_15_weather_0_icon = list_15_weather_0["icon"]; // "10d"

int list_15_clouds_all = list_15["clouds"]["all"]; // 100

float list_15_wind_speed = list_15["wind"]["speed"]; // 9.57
int list_15_wind_deg = list_15["wind"]["deg"]; // 165

float list_15_rain_3h = list_15["rain"]["3h"]; // 0.75

const char* list_15_sys_pod = list_15["sys"]["pod"]; // "d"

const char* list_15_dt_txt = list_15["dt_txt"]; // "2020-02-29 12:00:00"

JsonObject list_16 = list[16];
long list_16_dt = list_16["dt"]; // 1582988400

JsonObject list_16_main = list_16["main"];
float list_16_main_temp = list_16_main["temp"]; // 286.45
float list_16_main_feels_like = list_16_main["feels_like"]; // 285.22
float list_16_main_temp_min = list_16_main["temp_min"]; // 286.45
float list_16_main_temp_max = list_16_main["temp_max"]; // 286.45
int list_16_main_pressure = list_16_main["pressure"]; // 1007
int list_16_main_sea_level = list_16_main["sea_level"]; // 1007
int list_16_main_grnd_level = list_16_main["grnd_level"]; // 1006
int list_16_main_humidity = list_16_main["humidity"]; // 90
int list_16_main_temp_kf = list_16_main["temp_kf"]; // 0

JsonObject list_16_weather_0 = list_16["weather"][0];
int list_16_weather_0_id = list_16_weather_0["id"]; // 804
const char* list_16_weather_0_main = list_16_weather_0["main"]; // "Clouds"
const char* list_16_weather_0_description = list_16_weather_0["description"]; // "overcast clouds"
const char* list_16_weather_0_icon = list_16_weather_0["icon"]; // "04d"

int list_16_clouds_all = list_16["clouds"]["all"]; // 100

float list_16_wind_speed = list_16["wind"]["speed"]; // 2.51
int list_16_wind_deg = list_16["wind"]["deg"]; // 115

const char* list_16_sys_pod = list_16["sys"]["pod"]; // "d"

const char* list_16_dt_txt = list_16["dt_txt"]; // "2020-02-29 15:00:00"

JsonObject list_17 = list[17];
long list_17_dt = list_17["dt"]; // 1582999200

JsonObject list_17_main = list_17["main"];
float list_17_main_temp = list_17_main["temp"]; // 286.86
float list_17_main_feels_like = list_17_main["feels_like"]; // 281.91
float list_17_main_temp_min = list_17_main["temp_min"]; // 286.86
float list_17_main_temp_max = list_17_main["temp_max"]; // 286.86
int list_17_main_pressure = list_17_main["pressure"]; // 1009
int list_17_main_sea_level = list_17_main["sea_level"]; // 1009
int list_17_main_grnd_level = list_17_main["grnd_level"]; // 1009
int list_17_main_humidity = list_17_main["humidity"]; // 68
int list_17_main_temp_kf = list_17_main["temp_kf"]; // 0

JsonObject list_17_weather_0 = list_17["weather"][0];
int list_17_weather_0_id = list_17_weather_0["id"]; // 500
const char* list_17_weather_0_main = list_17_weather_0["main"]; // "Rain"
const char* list_17_weather_0_description = list_17_weather_0["description"]; // "light rain"
const char* list_17_weather_0_icon = list_17_weather_0["icon"]; // "10n"

int list_17_clouds_all = list_17["clouds"]["all"]; // 96

float list_17_wind_speed = list_17["wind"]["speed"]; // 6.38
int list_17_wind_deg = list_17["wind"]["deg"]; // 327

float list_17_rain_3h = list_17["rain"]["3h"]; // 0.56

const char* list_17_sys_pod = list_17["sys"]["pod"]; // "n"

const char* list_17_dt_txt = list_17["dt_txt"]; // "2020-02-29 18:00:00"

JsonObject list_18 = list[18];
long list_18_dt = list_18["dt"]; // 1583010000

JsonObject list_18_main = list_18["main"];
float list_18_main_temp = list_18_main["temp"]; // 285.58
float list_18_main_feels_like = list_18_main["feels_like"]; // 280.37
float list_18_main_temp_min = list_18_main["temp_min"]; // 285.58
float list_18_main_temp_max = list_18_main["temp_max"]; // 285.58
int list_18_main_pressure = list_18_main["pressure"]; // 1011
int list_18_main_sea_level = list_18_main["sea_level"]; // 1011
int list_18_main_grnd_level = list_18_main["grnd_level"]; // 1010
int list_18_main_humidity = list_18_main["humidity"]; // 68
int list_18_main_temp_kf = list_18_main["temp_kf"]; // 0

JsonObject list_18_weather_0 = list_18["weather"][0];
int list_18_weather_0_id = list_18_weather_0["id"]; // 804
const char* list_18_weather_0_main = list_18_weather_0["main"]; // "Clouds"
const char* list_18_weather_0_description = list_18_weather_0["description"]; // "overcast clouds"
const char* list_18_weather_0_icon = list_18_weather_0["icon"]; // "04n"

int list_18_clouds_all = list_18["clouds"]["all"]; // 100

float list_18_wind_speed = list_18["wind"]["speed"]; // 6.35
int list_18_wind_deg = list_18["wind"]["deg"]; // 304

const char* list_18_sys_pod = list_18["sys"]["pod"]; // "n"

const char* list_18_dt_txt = list_18["dt_txt"]; // "2020-02-29 21:00:00"

JsonObject list_19 = list[19];
long list_19_dt = list_19["dt"]; // 1583020800

JsonObject list_19_main = list_19["main"];
float list_19_main_temp = list_19_main["temp"]; // 285.1
float list_19_main_feels_like = list_19_main["feels_like"]; // 281.38
float list_19_main_temp_min = list_19_main["temp_min"]; // 285.1
float list_19_main_temp_max = list_19_main["temp_max"]; // 285.1
int list_19_main_pressure = list_19_main["pressure"]; // 1011
int list_19_main_sea_level = list_19_main["sea_level"]; // 1011
int list_19_main_grnd_level = list_19_main["grnd_level"]; // 1010
int list_19_main_humidity = list_19_main["humidity"]; // 63
int list_19_main_temp_kf = list_19_main["temp_kf"]; // 0

JsonObject list_19_weather_0 = list_19["weather"][0];
int list_19_weather_0_id = list_19_weather_0["id"]; // 804
const char* list_19_weather_0_main = list_19_weather_0["main"]; // "Clouds"
const char* list_19_weather_0_description = list_19_weather_0["description"]; // "overcast clouds"
const char* list_19_weather_0_icon = list_19_weather_0["icon"]; // "04n"

int list_19_clouds_all = list_19["clouds"]["all"]; // 100

float list_19_wind_speed = list_19["wind"]["speed"]; // 3.75
int list_19_wind_deg = list_19["wind"]["deg"]; // 278

const char* list_19_sys_pod = list_19["sys"]["pod"]; // "n"

const char* list_19_dt_txt = list_19["dt_txt"]; // "2020-03-01 00:00:00"

JsonObject list_20 = list[20];
long list_20_dt = list_20["dt"]; // 1583031600

JsonObject list_20_main = list_20["main"];
float list_20_main_temp = list_20_main["temp"]; // 283.94
float list_20_main_feels_like = list_20_main["feels_like"]; // 280.88
float list_20_main_temp_min = list_20_main["temp_min"]; // 283.94
float list_20_main_temp_max = list_20_main["temp_max"]; // 283.94
int list_20_main_pressure = list_20_main["pressure"]; // 1010
int list_20_main_sea_level = list_20_main["sea_level"]; // 1010
int list_20_main_grnd_level = list_20_main["grnd_level"]; // 1009
int list_20_main_humidity = list_20_main["humidity"]; // 70
int list_20_main_temp_kf = list_20_main["temp_kf"]; // 0

JsonObject list_20_weather_0 = list_20["weather"][0];
int list_20_weather_0_id = list_20_weather_0["id"]; // 804
const char* list_20_weather_0_main = list_20_weather_0["main"]; // "Clouds"
const char* list_20_weather_0_description = list_20_weather_0["description"]; // "overcast clouds"
const char* list_20_weather_0_icon = list_20_weather_0["icon"]; // "04n"

int list_20_clouds_all = list_20["clouds"]["all"]; // 100

float list_20_wind_speed = list_20["wind"]["speed"]; // 2.92
int list_20_wind_deg = list_20["wind"]["deg"]; // 345

const char* list_20_sys_pod = list_20["sys"]["pod"]; // "n"

const char* list_20_dt_txt = list_20["dt_txt"]; // "2020-03-01 03:00:00"

JsonObject list_21 = list[21];
long list_21_dt = list_21["dt"]; // 1583042400

JsonObject list_21_main = list_21["main"];
float list_21_main_temp = list_21_main["temp"]; // 283.76
float list_21_main_feels_like = list_21_main["feels_like"]; // 281.3
float list_21_main_temp_min = list_21_main["temp_min"]; // 283.76
float list_21_main_temp_max = list_21_main["temp_max"]; // 283.76
int list_21_main_pressure = list_21_main["pressure"]; // 1009
int list_21_main_sea_level = list_21_main["sea_level"]; // 1009
int list_21_main_grnd_level = list_21_main["grnd_level"]; // 1008
int list_21_main_humidity = list_21_main["humidity"]; // 66
int list_21_main_temp_kf = list_21_main["temp_kf"]; // 0

JsonObject list_21_weather_0 = list_21["weather"][0];
int list_21_weather_0_id = list_21_weather_0["id"]; // 804
const char* list_21_weather_0_main = list_21_weather_0["main"]; // "Clouds"
const char* list_21_weather_0_description = list_21_weather_0["description"]; // "overcast clouds"
const char* list_21_weather_0_icon = list_21_weather_0["icon"]; // "04n"

int list_21_clouds_all = list_21["clouds"]["all"]; // 100

float list_21_wind_speed = list_21["wind"]["speed"]; // 1.77
int list_21_wind_deg = list_21["wind"]["deg"]; // 313

const char* list_21_sys_pod = list_21["sys"]["pod"]; // "n"

const char* list_21_dt_txt = list_21["dt_txt"]; // "2020-03-01 06:00:00"

JsonObject list_22 = list[22];
long list_22_dt = list_22["dt"]; // 1583053200

JsonObject list_22_main = list_22["main"];
float list_22_main_temp = list_22_main["temp"]; // 284.09
float list_22_main_feels_like = list_22_main["feels_like"]; // 282.08
float list_22_main_temp_min = list_22_main["temp_min"]; // 284.09
float list_22_main_temp_max = list_22_main["temp_max"]; // 284.09
int list_22_main_pressure = list_22_main["pressure"]; // 1008
int list_22_main_sea_level = list_22_main["sea_level"]; // 1008
int list_22_main_grnd_level = list_22_main["grnd_level"]; // 1008
int list_22_main_humidity = list_22_main["humidity"]; // 59
int list_22_main_temp_kf = list_22_main["temp_kf"]; // 0

JsonObject list_22_weather_0 = list_22["weather"][0];
int list_22_weather_0_id = list_22_weather_0["id"]; // 804
const char* list_22_weather_0_main = list_22_weather_0["main"]; // "Clouds"
const char* list_22_weather_0_description = list_22_weather_0["description"]; // "overcast clouds"
const char* list_22_weather_0_icon = list_22_weather_0["icon"]; // "04d"

int list_22_clouds_all = list_22["clouds"]["all"]; // 100

float list_22_wind_speed = list_22["wind"]["speed"]; // 0.79
int list_22_wind_deg = list_22["wind"]["deg"]; // 181

const char* list_22_sys_pod = list_22["sys"]["pod"]; // "d"

const char* list_22_dt_txt = list_22["dt_txt"]; // "2020-03-01 09:00:00"

JsonObject list_23 = list[23];
long list_23_dt = list_23["dt"]; // 1583064000

JsonObject list_23_main = list_23["main"];
float list_23_main_temp = list_23_main["temp"]; // 284.44
float list_23_main_feels_like = list_23_main["feels_like"]; // 280.54
float list_23_main_temp_min = list_23_main["temp_min"]; // 284.44
float list_23_main_temp_max = list_23_main["temp_max"]; // 284.44
int list_23_main_pressure = list_23_main["pressure"]; // 1006
int list_23_main_sea_level = list_23_main["sea_level"]; // 1006
int list_23_main_grnd_level = list_23_main["grnd_level"]; // 1006
int list_23_main_humidity = list_23_main["humidity"]; // 63
int list_23_main_temp_kf = list_23_main["temp_kf"]; // 0

JsonObject list_23_weather_0 = list_23["weather"][0];
int list_23_weather_0_id = list_23_weather_0["id"]; // 804
const char* list_23_weather_0_main = list_23_weather_0["main"]; // "Clouds"
const char* list_23_weather_0_description = list_23_weather_0["description"]; // "overcast clouds"
const char* list_23_weather_0_icon = list_23_weather_0["icon"]; // "04d"

int list_23_clouds_all = list_23["clouds"]["all"]; // 93

float list_23_wind_speed = list_23["wind"]["speed"]; // 3.83
int list_23_wind_deg = list_23["wind"]["deg"]; // 177

const char* list_23_sys_pod = list_23["sys"]["pod"]; // "d"

const char* list_23_dt_txt = list_23["dt_txt"]; // "2020-03-01 12:00:00"

JsonObject list_24 = list[24];
long list_24_dt = list_24["dt"]; // 1583074800

JsonObject list_24_main = list_24["main"];
float list_24_main_temp = list_24_main["temp"]; // 284.33
float list_24_main_feels_like = list_24_main["feels_like"]; // 280.7
float list_24_main_temp_min = list_24_main["temp_min"]; // 284.33
float list_24_main_temp_max = list_24_main["temp_max"]; // 284.33
int list_24_main_pressure = list_24_main["pressure"]; // 1003
int list_24_main_sea_level = list_24_main["sea_level"]; // 1003
int list_24_main_grnd_level = list_24_main["grnd_level"]; // 1003
int list_24_main_humidity = list_24_main["humidity"]; // 65
int list_24_main_temp_kf = list_24_main["temp_kf"]; // 0

JsonObject list_24_weather_0 = list_24["weather"][0];
int list_24_weather_0_id = list_24_weather_0["id"]; // 803
const char* list_24_weather_0_main = list_24_weather_0["main"]; // "Clouds"
const char* list_24_weather_0_description = list_24_weather_0["description"]; // "broken clouds"
const char* list_24_weather_0_icon = list_24_weather_0["icon"]; // "04d"

int list_24_clouds_all = list_24["clouds"]["all"]; // 58

float list_24_wind_speed = list_24["wind"]["speed"]; // 3.54
int list_24_wind_deg = list_24["wind"]["deg"]; // 146

const char* list_24_sys_pod = list_24["sys"]["pod"]; // "d"

const char* list_24_dt_txt = list_24["dt_txt"]; // "2020-03-01 15:00:00"

JsonObject list_25 = list[25];
long list_25_dt = list_25["dt"]; // 1583085600

JsonObject list_25_main = list_25["main"];
float list_25_main_temp = list_25_main["temp"]; // 285.95
float list_25_main_feels_like = list_25_main["feels_like"]; // 279.86
float list_25_main_temp_min = list_25_main["temp_min"]; // 285.95
float list_25_main_temp_max = list_25_main["temp_max"]; // 285.95
int list_25_main_pressure = list_25_main["pressure"]; // 1006
int list_25_main_sea_level = list_25_main["sea_level"]; // 1006
int list_25_main_grnd_level = list_25_main["grnd_level"]; // 1005
int list_25_main_humidity = list_25_main["humidity"]; // 68
int list_25_main_temp_kf = list_25_main["temp_kf"]; // 0

JsonObject list_25_weather_0 = list_25["weather"][0];
int list_25_weather_0_id = list_25_weather_0["id"]; // 500
const char* list_25_weather_0_main = list_25_weather_0["main"]; // "Rain"
const char* list_25_weather_0_description = list_25_weather_0["description"]; // "light rain"
const char* list_25_weather_0_icon = list_25_weather_0["icon"]; // "10n"

int list_25_clouds_all = list_25["clouds"]["all"]; // 78

float list_25_wind_speed = list_25["wind"]["speed"]; // 7.71
int list_25_wind_deg = list_25["wind"]["deg"]; // 272

float list_25_rain_3h = list_25["rain"]["3h"]; // 1.56

const char* list_25_sys_pod = list_25["sys"]["pod"]; // "n"

const char* list_25_dt_txt = list_25["dt_txt"]; // "2020-03-01 18:00:00"

JsonObject list_26 = list[26];
long list_26_dt = list_26["dt"]; // 1583096400

JsonObject list_26_main = list_26["main"];
float list_26_main_temp = list_26_main["temp"]; // 284.61
float list_26_main_feels_like = list_26_main["feels_like"]; // 276.71
float list_26_main_temp_min = list_26_main["temp_min"]; // 284.61
float list_26_main_temp_max = list_26_main["temp_max"]; // 284.61
int list_26_main_pressure = list_26_main["pressure"]; // 1009
int list_26_main_sea_level = list_26_main["sea_level"]; // 1009
int list_26_main_grnd_level = list_26_main["grnd_level"]; // 1008
int list_26_main_humidity = list_26_main["humidity"]; // 61
int list_26_main_temp_kf = list_26_main["temp_kf"]; // 0

JsonObject list_26_weather_0 = list_26["weather"][0];
int list_26_weather_0_id = list_26_weather_0["id"]; // 802
const char* list_26_weather_0_main = list_26_weather_0["main"]; // "Clouds"
const char* list_26_weather_0_description = list_26_weather_0["description"]; // "scattered clouds"
const char* list_26_weather_0_icon = list_26_weather_0["icon"]; // "03n"

int list_26_clouds_all = list_26["clouds"]["all"]; // 39

float list_26_wind_speed = list_26["wind"]["speed"]; // 9.45
int list_26_wind_deg = list_26["wind"]["deg"]; // 295

const char* list_26_sys_pod = list_26["sys"]["pod"]; // "n"

const char* list_26_dt_txt = list_26["dt_txt"]; // "2020-03-01 21:00:00"

JsonObject list_27 = list[27];
long list_27_dt = list_27["dt"]; // 1583107200

JsonObject list_27_main = list_27["main"];
float list_27_main_temp = list_27_main["temp"]; // 283.62
float list_27_main_feels_like = list_27_main["feels_like"]; // 279.17
float list_27_main_temp_min = list_27_main["temp_min"]; // 283.62
float list_27_main_temp_max = list_27_main["temp_max"]; // 283.62
int list_27_main_pressure = list_27_main["pressure"]; // 1008
int list_27_main_sea_level = list_27_main["sea_level"]; // 1008
int list_27_main_grnd_level = list_27_main["grnd_level"]; // 1006
int list_27_main_humidity = list_27_main["humidity"]; // 59
int list_27_main_temp_kf = list_27_main["temp_kf"]; // 0

JsonObject list_27_weather_0 = list_27["weather"][0];
int list_27_weather_0_id = list_27_weather_0["id"]; // 801
const char* list_27_weather_0_main = list_27_weather_0["main"]; // "Clouds"
const char* list_27_weather_0_description = list_27_weather_0["description"]; // "few clouds"
const char* list_27_weather_0_icon = list_27_weather_0["icon"]; // "02n"

int list_27_clouds_all = list_27["clouds"]["all"]; // 20

float list_27_wind_speed = list_27["wind"]["speed"]; // 4.16
int list_27_wind_deg = list_27["wind"]["deg"]; // 308

const char* list_27_sys_pod = list_27["sys"]["pod"]; // "n"

const char* list_27_dt_txt = list_27["dt_txt"]; // "2020-03-02 00:00:00"

JsonObject list_28 = list[28];
long list_28_dt = list_28["dt"]; // 1583118000

JsonObject list_28_main = list_28["main"];
int list_28_main_temp = list_28_main["temp"]; // 284
float list_28_main_feels_like = list_28_main["feels_like"]; // 280.38
int list_28_main_temp_min = list_28_main["temp_min"]; // 284
int list_28_main_temp_max = list_28_main["temp_max"]; // 284
int list_28_main_pressure = list_28_main["pressure"]; // 1006
int list_28_main_sea_level = list_28_main["sea_level"]; // 1006
int list_28_main_grnd_level = list_28_main["grnd_level"]; // 1006
int list_28_main_humidity = list_28_main["humidity"]; // 58
int list_28_main_temp_kf = list_28_main["temp_kf"]; // 0

JsonObject list_28_weather_0 = list_28["weather"][0];
int list_28_weather_0_id = list_28_weather_0["id"]; // 803
const char* list_28_weather_0_main = list_28_weather_0["main"]; // "Clouds"
const char* list_28_weather_0_description = list_28_weather_0["description"]; // "broken clouds"
const char* list_28_weather_0_icon = list_28_weather_0["icon"]; // "04n"

int list_28_clouds_all = list_28["clouds"]["all"]; // 73

float list_28_wind_speed = list_28["wind"]["speed"]; // 3.01
int list_28_wind_deg = list_28["wind"]["deg"]; // 241

const char* list_28_sys_pod = list_28["sys"]["pod"]; // "n"

const char* list_28_dt_txt = list_28["dt_txt"]; // "2020-03-02 03:00:00"

JsonObject list_29 = list[29];
long list_29_dt = list_29["dt"]; // 1583128800

JsonObject list_29_main = list_29["main"];
float list_29_main_temp = list_29_main["temp"]; // 284.61
float list_29_main_feels_like = list_29_main["feels_like"]; // 281.42
float list_29_main_temp_min = list_29_main["temp_min"]; // 284.61
float list_29_main_temp_max = list_29_main["temp_max"]; // 284.61
int list_29_main_pressure = list_29_main["pressure"]; // 1005
int list_29_main_sea_level = list_29_main["sea_level"]; // 1005
int list_29_main_grnd_level = list_29_main["grnd_level"]; // 1005
int list_29_main_humidity = list_29_main["humidity"]; // 63
int list_29_main_temp_kf = list_29_main["temp_kf"]; // 0

JsonObject list_29_weather_0 = list_29["weather"][0];
int list_29_weather_0_id = list_29_weather_0["id"]; // 804
const char* list_29_weather_0_main = list_29_weather_0["main"]; // "Clouds"
const char* list_29_weather_0_description = list_29_weather_0["description"]; // "overcast clouds"
const char* list_29_weather_0_icon = list_29_weather_0["icon"]; // "04n"

int list_29_clouds_all = list_29["clouds"]["all"]; // 86

float list_29_wind_speed = list_29["wind"]["speed"]; // 2.85
int list_29_wind_deg = list_29["wind"]["deg"]; // 202

const char* list_29_sys_pod = list_29["sys"]["pod"]; // "n"

const char* list_29_dt_txt = list_29["dt_txt"]; // "2020-03-02 06:00:00"

JsonObject list_30 = list[30];
long list_30_dt = list_30["dt"]; // 1583139600

JsonObject list_30_main = list_30["main"];
float list_30_main_temp = list_30_main["temp"]; // 284.94
float list_30_main_feels_like = list_30_main["feels_like"]; // 282.73
float list_30_main_temp_min = list_30_main["temp_min"]; // 284.94
float list_30_main_temp_max = list_30_main["temp_max"]; // 284.94
int list_30_main_pressure = list_30_main["pressure"]; // 1005
int list_30_main_sea_level = list_30_main["sea_level"]; // 1005
int list_30_main_grnd_level = list_30_main["grnd_level"]; // 1004
int list_30_main_humidity = list_30_main["humidity"]; // 65
int list_30_main_temp_kf = list_30_main["temp_kf"]; // 0

JsonObject list_30_weather_0 = list_30["weather"][0];
int list_30_weather_0_id = list_30_weather_0["id"]; // 804
const char* list_30_weather_0_main = list_30_weather_0["main"]; // "Clouds"
const char* list_30_weather_0_description = list_30_weather_0["description"]; // "overcast clouds"
const char* list_30_weather_0_icon = list_30_weather_0["icon"]; // "04d"

int list_30_clouds_all = list_30["clouds"]["all"]; // 100

float list_30_wind_speed = list_30["wind"]["speed"]; // 1.67
int list_30_wind_deg = list_30["wind"]["deg"]; // 346

const char* list_30_sys_pod = list_30["sys"]["pod"]; // "d"

const char* list_30_dt_txt = list_30["dt_txt"]; // "2020-03-02 09:00:00"

JsonObject list_31 = list[31];
long list_31_dt = list_31["dt"]; // 1583150400

JsonObject list_31_main = list_31["main"];
float list_31_main_temp = list_31_main["temp"]; // 285.29
float list_31_main_feels_like = list_31_main["feels_like"]; // 280.08
float list_31_main_temp_min = list_31_main["temp_min"]; // 285.29
float list_31_main_temp_max = list_31_main["temp_max"]; // 285.29
int list_31_main_pressure = list_31_main["pressure"]; // 1006
int list_31_main_sea_level = list_31_main["sea_level"]; // 1006
int list_31_main_grnd_level = list_31_main["grnd_level"]; // 1005
int list_31_main_humidity = list_31_main["humidity"]; // 60
int list_31_main_temp_kf = list_31_main["temp_kf"]; // 0

JsonObject list_31_weather_0 = list_31["weather"][0];
int list_31_weather_0_id = list_31_weather_0["id"]; // 500
const char* list_31_weather_0_main = list_31_weather_0["main"]; // "Rain"
const char* list_31_weather_0_description = list_31_weather_0["description"]; // "light rain"
const char* list_31_weather_0_icon = list_31_weather_0["icon"]; // "10d"

int list_31_clouds_all = list_31["clouds"]["all"]; // 100

float list_31_wind_speed = list_31["wind"]["speed"]; // 5.72
int list_31_wind_deg = list_31["wind"]["deg"]; // 269

float list_31_rain_3h = list_31["rain"]["3h"]; // 0.38

const char* list_31_sys_pod = list_31["sys"]["pod"]; // "d"

const char* list_31_dt_txt = list_31["dt_txt"]; // "2020-03-02 12:00:00"

JsonObject list_32 = list[32];
long list_32_dt = list_32["dt"]; // 1583161200

JsonObject list_32_main = list_32["main"];
float list_32_main_temp = list_32_main["temp"]; // 286.35
float list_32_main_feels_like = list_32_main["feels_like"]; // 280.35
float list_32_main_temp_min = list_32_main["temp_min"]; // 286.35
float list_32_main_temp_max = list_32_main["temp_max"]; // 286.35
int list_32_main_pressure = list_32_main["pressure"]; // 1004
int list_32_main_sea_level = list_32_main["sea_level"]; // 1004
int list_32_main_grnd_level = list_32_main["grnd_level"]; // 1003
int list_32_main_humidity = list_32_main["humidity"]; // 55
int list_32_main_temp_kf = list_32_main["temp_kf"]; // 0

JsonObject list_32_weather_0 = list_32["weather"][0];
int list_32_weather_0_id = list_32_weather_0["id"]; // 804
const char* list_32_weather_0_main = list_32_weather_0["main"]; // "Clouds"
const char* list_32_weather_0_description = list_32_weather_0["description"]; // "overcast clouds"
const char* list_32_weather_0_icon = list_32_weather_0["icon"]; // "04d"

int list_32_clouds_all = list_32["clouds"]["all"]; // 94

float list_32_wind_speed = list_32["wind"]["speed"]; // 6.78
int list_32_wind_deg = list_32["wind"]["deg"]; // 294

const char* list_32_sys_pod = list_32["sys"]["pod"]; // "d"

const char* list_32_dt_txt = list_32["dt_txt"]; // "2020-03-02 15:00:00"

JsonObject list_33 = list[33];
long list_33_dt = list_33["dt"]; // 1583172000

JsonObject list_33_main = list_33["main"];
float list_33_main_temp = list_33_main["temp"]; // 285.32
float list_33_main_feels_like = list_33_main["feels_like"]; // 277.08
float list_33_main_temp_min = list_33_main["temp_min"]; // 285.32
float list_33_main_temp_max = list_33_main["temp_max"]; // 285.32
int list_33_main_pressure = list_33_main["pressure"]; // 1006
int list_33_main_sea_level = list_33_main["sea_level"]; // 1006
int list_33_main_grnd_level = list_33_main["grnd_level"]; // 1005
int list_33_main_humidity = list_33_main["humidity"]; // 55
int list_33_main_temp_kf = list_33_main["temp_kf"]; // 0

JsonObject list_33_weather_0 = list_33["weather"][0];
int list_33_weather_0_id = list_33_weather_0["id"]; // 803
const char* list_33_weather_0_main = list_33_weather_0["main"]; // "Clouds"
const char* list_33_weather_0_description = list_33_weather_0["description"]; // "broken clouds"
const char* list_33_weather_0_icon = list_33_weather_0["icon"]; // "04n"

int list_33_clouds_all = list_33["clouds"]["all"]; // 71

float list_33_wind_speed = list_33["wind"]["speed"]; // 9.73
int list_33_wind_deg = list_33["wind"]["deg"]; // 289

const char* list_33_sys_pod = list_33["sys"]["pod"]; // "n"

const char* list_33_dt_txt = list_33["dt_txt"]; // "2020-03-02 18:00:00"

JsonObject list_34 = list[34];
long list_34_dt = list_34["dt"]; // 1583182800

JsonObject list_34_main = list_34["main"];
float list_34_main_temp = list_34_main["temp"]; // 283.36
float list_34_main_feels_like = list_34_main["feels_like"]; // 276.65
float list_34_main_temp_min = list_34_main["temp_min"]; // 283.36
float list_34_main_temp_max = list_34_main["temp_max"]; // 283.36
int list_34_main_pressure = list_34_main["pressure"]; // 1008
int list_34_main_sea_level = list_34_main["sea_level"]; // 1008
int list_34_main_grnd_level = list_34_main["grnd_level"]; // 1007
int list_34_main_humidity = list_34_main["humidity"]; // 68
int list_34_main_temp_kf = list_34_main["temp_kf"]; // 0

JsonObject list_34_weather_0 = list_34["weather"][0];
int list_34_weather_0_id = list_34_weather_0["id"]; // 804
const char* list_34_weather_0_main = list_34_weather_0["main"]; // "Clouds"
const char* list_34_weather_0_description = list_34_weather_0["description"]; // "overcast clouds"
const char* list_34_weather_0_icon = list_34_weather_0["icon"]; // "04n"

int list_34_clouds_all = list_34["clouds"]["all"]; // 99

float list_34_wind_speed = list_34["wind"]["speed"]; // 7.86
int list_34_wind_deg = list_34["wind"]["deg"]; // 288

const char* list_34_sys_pod = list_34["sys"]["pod"]; // "n"

const char* list_34_dt_txt = list_34["dt_txt"]; // "2020-03-02 21:00:00"

JsonObject list_35 = list[35];
long list_35_dt = list_35["dt"]; // 1583193600

JsonObject list_35_main = list_35["main"];
float list_35_main_temp = list_35_main["temp"]; // 282.89
float list_35_main_feels_like = list_35_main["feels_like"]; // 274.86
float list_35_main_temp_min = list_35_main["temp_min"]; // 282.89
float list_35_main_temp_max = list_35_main["temp_max"]; // 282.89
int list_35_main_pressure = list_35_main["pressure"]; // 1009
int list_35_main_sea_level = list_35_main["sea_level"]; // 1009
int list_35_main_grnd_level = list_35_main["grnd_level"]; // 1008
int list_35_main_humidity = list_35_main["humidity"]; // 69
int list_35_main_temp_kf = list_35_main["temp_kf"]; // 0

JsonObject list_35_weather_0 = list_35["weather"][0];
int list_35_weather_0_id = list_35_weather_0["id"]; // 804
const char* list_35_weather_0_main = list_35_weather_0["main"]; // "Clouds"
const char* list_35_weather_0_description = list_35_weather_0["description"]; // "overcast clouds"
const char* list_35_weather_0_icon = list_35_weather_0["icon"]; // "04n"

int list_35_clouds_all = list_35["clouds"]["all"]; // 98

float list_35_wind_speed = list_35["wind"]["speed"]; // 9.68
int list_35_wind_deg = list_35["wind"]["deg"]; // 286

const char* list_35_sys_pod = list_35["sys"]["pod"]; // "n"

const char* list_35_dt_txt = list_35["dt_txt"]; // "2020-03-03 00:00:00"

JsonObject list_36 = list[36];
long list_36_dt = list_36["dt"]; // 1583204400

JsonObject list_36_main = list_36["main"];
float list_36_main_temp = list_36_main["temp"]; // 282.52
float list_36_main_feels_like = list_36_main["feels_like"]; // 273.15
float list_36_main_temp_min = list_36_main["temp_min"]; // 282.52
float list_36_main_temp_max = list_36_main["temp_max"]; // 282.52
int list_36_main_pressure = list_36_main["pressure"]; // 1009
int list_36_main_sea_level = list_36_main["sea_level"]; // 1009
int list_36_main_grnd_level = list_36_main["grnd_level"]; // 1007
int list_36_main_humidity = list_36_main["humidity"]; // 60
int list_36_main_temp_kf = list_36_main["temp_kf"]; // 0

JsonObject list_36_weather_0 = list_36["weather"][0];
int list_36_weather_0_id = list_36_weather_0["id"]; // 800
const char* list_36_weather_0_main = list_36_weather_0["main"]; // "Clear"
const char* list_36_weather_0_description = list_36_weather_0["description"]; // "clear sky"
const char* list_36_weather_0_icon = list_36_weather_0["icon"]; // "01n"

int list_36_clouds_all = list_36["clouds"]["all"]; // 0

float list_36_wind_speed = list_36["wind"]["speed"]; // 10.99
int list_36_wind_deg = list_36["wind"]["deg"]; // 300

const char* list_36_sys_pod = list_36["sys"]["pod"]; // "n"

const char* list_36_dt_txt = list_36["dt_txt"]; // "2020-03-03 03:00:00"

JsonObject list_37 = list[37];
long list_37_dt = list_37["dt"]; // 1583215200

JsonObject list_37_main = list_37["main"];
float list_37_main_temp = list_37_main["temp"]; // 281.6
float list_37_main_feels_like = list_37_main["feels_like"]; // 272.79
float list_37_main_temp_min = list_37_main["temp_min"]; // 281.6
float list_37_main_temp_max = list_37_main["temp_max"]; // 281.6
int list_37_main_pressure = list_37_main["pressure"]; // 1010
int list_37_main_sea_level = list_37_main["sea_level"]; // 1010
int list_37_main_grnd_level = list_37_main["grnd_level"]; // 1008
int list_37_main_humidity = list_37_main["humidity"]; // 61
int list_37_main_temp_kf = list_37_main["temp_kf"]; // 0

JsonObject list_37_weather_0 = list_37["weather"][0];
int list_37_weather_0_id = list_37_weather_0["id"]; // 800
const char* list_37_weather_0_main = list_37_weather_0["main"]; // "Clear"
const char* list_37_weather_0_description = list_37_weather_0["description"]; // "clear sky"
const char* list_37_weather_0_icon = list_37_weather_0["icon"]; // "01n"

int list_37_clouds_all = list_37["clouds"]["all"]; // 0

float list_37_wind_speed = list_37["wind"]["speed"]; // 10.05
int list_37_wind_deg = list_37["wind"]["deg"]; // 306

const char* list_37_sys_pod = list_37["sys"]["pod"]; // "n"

const char* list_37_dt_txt = list_37["dt_txt"]; // "2020-03-03 06:00:00"

JsonObject list_38 = list[38];
long list_38_dt = list_38["dt"]; // 1583226000

JsonObject list_38_main = list_38["main"];
float list_38_main_temp = list_38_main["temp"]; // 282.15
float list_38_main_feels_like = list_38_main["feels_like"]; // 277.21
float list_38_main_temp_min = list_38_main["temp_min"]; // 282.15
float list_38_main_temp_max = list_38_main["temp_max"]; // 282.15
int list_38_main_pressure = list_38_main["pressure"]; // 1009
int list_38_main_sea_level = list_38_main["sea_level"]; // 1009
int list_38_main_grnd_level = list_38_main["grnd_level"]; // 1008
int list_38_main_humidity = list_38_main["humidity"]; // 54
int list_38_main_temp_kf = list_38_main["temp_kf"]; // 0

JsonObject list_38_weather_0 = list_38["weather"][0];
int list_38_weather_0_id = list_38_weather_0["id"]; // 804
const char* list_38_weather_0_main = list_38_weather_0["main"]; // "Clouds"
const char* list_38_weather_0_description = list_38_weather_0["description"]; // "overcast clouds"
const char* list_38_weather_0_icon = list_38_weather_0["icon"]; // "04d"

int list_38_clouds_all = list_38["clouds"]["all"]; // 100

float list_38_wind_speed = list_38["wind"]["speed"]; // 4.26
int list_38_wind_deg = list_38["wind"]["deg"]; // 326

const char* list_38_sys_pod = list_38["sys"]["pod"]; // "d"

const char* list_38_dt_txt = list_38["dt_txt"]; // "2020-03-03 09:00:00"

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
     Serial.println("Déconnexion."); // On se déconnecte.
   }
  

void loop() {
 
}
