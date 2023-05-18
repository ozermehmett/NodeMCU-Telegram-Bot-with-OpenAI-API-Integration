#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFiClientSecureBearSSL.h>
#include <ChatGPT.hpp>

BearSSL::WiFiClientSecure client;
ChatGPT<BearSSL::WiFiClientSecure> chat_gpt(&client, "v1", "YOUR_OPENAI_KEY");

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
 
#define BOTtoken "YOUR_BOT_API_KEY"
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
 
UniversalTelegramBot bot(BOTtoken, client);
 
int botRequestDelay = 500;
unsigned long lastTimeBotRan;
 
void handleNewMessages(int numNewMessages) {
  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;
    String from_name = bot.messages[i].from_name;
 
    if (text == "/start") {
      String welcome = "Welcome " + from_name;
      welcome += ", this bot is actively running on a NodeMCU.";
      welcome += "It generates responses using the OpenAI API key and the 'gpt-3.5-turbo-0301' model."; 
      welcome += "Feel free to ask anything you want."; 
      bot.sendMessage(chat_id, welcome, "");
    }else{
      String result;
      if (chat_gpt.simple_message("gpt-3.5-turbo-0301", "user", text, result)) {
          bot.sendMessage(chat_id, result, "");
    } else{
      bot.sendMessage(chat_id, "I'm sorry, we encountered an error. Please try again.");
      }
    } 
  }
}

void setup() {
  Serial.begin(115200);
 
  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());
  
  client.setInsecure();
}
 
void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
 
    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}