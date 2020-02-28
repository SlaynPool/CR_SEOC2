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

   Serial.println("");
   Serial.println("Informations locales :"); // Affichage d'infos sur le système local
   Serial.print("Adresse IP locale : ");
   Serial.print(WiFi.localIP());
   Serial.println("");
   Serial.print("Nom de domaine : ");
   Serial.print(WiFi.getHostname());
   Serial.println("");
   Serial.print("Adresse MAC : ");
   Serial.print(WiFi.macAddress());
   Serial.println("");

    Serial.println("");
    Serial.println("Informations sur le réseau WiFi :"); // Affichage d'infos sur le serveur WiFi
    Serial.print("SSID : ");
    Serial.print(WiFi.SSID());
    Serial.println("");
    Serial.print("Force du signal : ");
    Serial.print(WiFi.RSSI());
    Serial.println("");
    Serial.print("Adresse IP du DNS : ");
    Serial.print(WiFi.dnsIP());
    Serial.println("");
    Serial.print("Adresse IP de la passerelle : ");
    Serial.print(WiFi.gatewayIP());
    Serial.println("");
    Serial.print("Masque de sous-réseau : ");
    Serial.print(WiFi.subnetMask());
    Serial.println("");
    Serial.print("MAC : ");
    Serial.print(WiFi.BSSIDstr());
    Serial.println("");   
    Serial.print("Canal : ");
    Serial.print(WiFi.channel());
    Serial.println("");

  
    HTTPClient http;
    http.begin("https://api.openweathermap.org/data/2.5/weather?id=");
    int HttpRetCode = http.GET();
    if(HttpRetCode > 0)
 {
  Serial.println("Données reçues...");
  String Contents = http.getString();
  http.end();
 const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(13) + 300;
DynamicJsonDocument doc(capacity);

const char* json = "{\"coord\":{\"lon\":3.83,\"lat\":43.67},\"weather\":[{\"id\":800,\"main\":\"Clear\",\"description\":\"clear sky\",\"icon\":\"01d\"}],\"base\":\"stations\",\"main\":{\"temp\":295,\"feels_like\":292.7,\"temp_min\":293.15,\"temp_max\":296.48,\"pressure\":1020,\"humidity\":49},\"visibility\":10000,\"wind\":{\"speed\":3.6,\"deg\":200},\"clouds\":{\"all\":0},\"dt\":1582555157,\"sys\":{\"type\":1,\"id\":6518,\"country\":\"FR\",\"sunrise\":1582525852,\"sunset\":1582565128},\"timezone\":3600,\"id\":2992165,\"name\":\"Arrondissement of Montpellier\",\"cod\":200}";

deserializeJson(doc, json);

float coord_lon = doc["coord"]["lon"]; // 3.83
float coord_lat = doc["coord"]["lat"]; // 43.67

JsonObject weather_0 = doc["weather"][0];
int weather_0_id = weather_0["id"]; // 800
const char* weather_0_main = weather_0["main"]; // "Clear"
const char* weather_0_description = weather_0["description"]; // "clear sky"
const char* weather_0_icon = weather_0["icon"]; // "01d"

const char* base = doc["base"]; // "stations"

JsonObject main = doc["main"];
int main_temp = main["temp"]; // 295
float main_feels_like = main["feels_like"]; // 292.7
float main_temp_min = main["temp_min"]; // 293.15
float main_temp_max = main["temp_max"]; // 296.48
int main_pressure = main["pressure"]; // 1020
int main_humidity = main["humidity"]; // 49

int visibility = doc["visibility"]; // 10000

float wind_speed = doc["wind"]["speed"]; // 3.6
int wind_deg = doc["wind"]["deg"]; // 200

int clouds_all = doc["clouds"]["all"]; // 0

long dt = doc["dt"]; // 1582555157

JsonObject sys = doc["sys"];
int sys_type = sys["type"]; // 1
int sys_id = sys["id"]; // 6518
const char* sys_country = sys["country"]; // "FR"
long sys_sunrise = sys["sunrise"]; // 1582525852
long sys_sunset = sys["sunset"]; // 1582565128

int timezone = doc["timezone"]; // 3600
long id = doc["id"]; // 2992165
const char* name = doc["name"]; // "Arrondissement of Montpellier"
int cod = doc["cod"]; // 200
  Serial.println("City :");
  Serial.println(name);
  Serial.println("temp :");
  Serial.println(main_temp);
  
 }
 delay(5000);

    WiFi.disconnect(true);
     Serial.println("Déconnexion."); // On se déconnecte.
   }
  

void loop() {
 
}
