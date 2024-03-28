#include <HTTPClient.h>
#include <WiFi.h>

int btn = 19;

HTTPClient http;
int Click = 0; // Contador de cliques

const char* ssid     = "CHOCOLATRA";
const char* password = "sa2nd3y40";

void setup() {

  Serial.begin(115200);

  // Conecte-se à rede Wi-Fi
  Serial.print("Conectando-se à ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Imprima o endereço IP local quando conectado
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  
  // Inicialize o cliente HTTP e defina o cabeçalho de conteúdo como JSON
  http.begin("http://192.168.1.13:8081/clicks");
  http.addHeader("Content-Type", "application/json");

  pinMode(19, INPUT);
}

void loop() {
  if(digitalRead(btn)){
    Click++;
  }

  // Crie um objeto JSON com a variável Click
  String jsonPayload = "{\"clicks\":" + String(Click) + "}";

  // Faça a solicitação POST
  int httpResponseCode = http.POST(jsonPayload);

  // Verifique o código de resposta HTTP
  if (httpResponseCode>0) {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  } else {
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
  }

  // Aguarde um pouco antes da próxima iteração
  delay(1000);
}
