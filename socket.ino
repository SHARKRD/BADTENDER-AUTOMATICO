// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "Pixel 7a";
const char* password = "ponunatuya";

int seleccion = 0;

bool enter = 0;
bool ledState = 0;  //
bool ledState1 = 0;
bool ledState2 = 0;
bool ledState3 = 0;
bool ledState4 = 0;
bool ledState5 = 0;
bool ledState6 = 0;
bool ledState7 = 0;
const int ledPin = 15; //primera bebida
const int ledPin1 = 2;  //Segunda Bebida
const int ledPin2 = 4;  //  Tercera Bebida
const int ledPin3 = 16; // Cuarta Bebida
const int ledPin4 = 17; //Quinta Bebida
const int ledPin5 = 5; //Sexta Bebida
const int ledPin6 = 18; //Septima Bebida
const int ledPin7 = 19; // Bebida

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(
)rawliteral";

void notifyClients() {
  ws.textAll(String(ledState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle") == 0) {
      ledState = !ledState;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle1") == 0){
      ledState1 = !ledState1;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle2") == 0){
      ledState2 = !ledState2;
      notifyClients();
    }
    
    if(strcmp((char*)data, "toggle3") == 0){
      ledState3 = !ledState3;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle4") == 0){
      ledState4 = !ledState4;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle5") == 0){
      ledState5 = !ledState5;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle6") == 0){
      ledState6 = !ledState6;
      notifyClients();
    }
    if(strcmp((char*)data, "toggle7") == 0){
      ledState7 = !ledState7;
      notifyClients();
    }


  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      notifyClients();
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin1, OUTPUT);
  digitalWrite(ledPin1, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);
  pinMode(ledPin3, OUTPUT);
  digitalWrite(ledPin3, LOW);
  pinMode(ledPin4, OUTPUT);
  digitalWrite(ledPin4, LOW);
    pinMode(ledPin5, OUTPUT);
  digitalWrite(ledPin5, LOW);
  pinMode(ledPin6, OUTPUT);
  digitalWrite(ledPin6, LOW);
  pinMode(ledPin7, OUTPUT);
  digitalWrite(ledPin7, LOW);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  initWebSocket();

  // Start server
  server.begin();
}

void loop() {

  ws.cleanupClients();
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  digitalWrite(ledPin3, ledState3);
  digitalWrite(ledPin4, ledState4);
  digitalWrite(ledPin5, ledState5);
  digitalWrite(ledPin6, ledState6);
  digitalWrite(ledPin7, ledState7);
}

