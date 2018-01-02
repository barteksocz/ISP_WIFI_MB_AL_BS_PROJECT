#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

const char wifi_SSID[] = "UPC1131478";
const char wifi_PSW[] = "UERGPQCM";

const char server_address[] = "192.168.0.19";
const int server_port = 99;

const String httpRequest = "POST /sensors_data HTTP/1.1\r\n"
                           "Host: 192.168.0.19\r\n"
                           "Transfer-Encoding: chunked\r\n"
                           "Connection: close\r\n\r\n";

static int temperature_value = 2;
static int magnetic_value = 3;
static int distance_value = 4;

static ESP8266Client client;

enum {
  CLIENT_DELAY = 2000,
};

bool esp8266Connect() {
  uint8_t i = 0;

  while (esp8266.connect(wifi_SSID, wifi_PSW) < 0)
    delay(1000);

  return true;
}

String buildHttpBody() {
  String httpBody;

     httpBody.concat("temperature=");
     httpBody.concat(temperature_value);

     httpBody.concat("&magnetic=");
     httpBody.concat(magnetic_value);

     httpBody.concat("&distance=");
     httpBody.concat(distance_value);  

   return httpBody;
}

void setup() {
  Serial.begin(115200);
  while (esp8266.begin(115200) != true)
  {
    delay(1000);
  }
  esp8266.echo(true);
  esp8266Connect(); 
}

void loop() {

      client.connect(server_address, server_port);
       String httpBody = buildHttpBody();
  
       client.print(httpRequest + httpBody.length() + "\r\n" + httpBody + "\r\n0\r\n\r\n");
  
       delay(500);
       
       if (client.connected())
          client.stop(); 

     
  delay(CLIENT_DELAY);
}
