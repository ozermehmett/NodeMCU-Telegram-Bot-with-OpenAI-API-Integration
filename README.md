# NodeMCU-Telegram-Bot-with-OpenAI-GPT-3-Integration

[Click here](https://t.me/nodemcuOzerBot) to try out the bot. (Will be available for a few days)

This project demonstrates how to create a Telegram bot using ESP8266 and integrate it with OpenAI's GPT-3.5 Turbo language model.
The Telegram bot runs on an ESP8266-based NodeMCU board and utilizes the UniversalTelegramBot library for interacting with the Telegram Bot API.

## Prerequisites
To run this project, you will need the following components:
- ESP8266-based NodeMCU board
- Wi-Fi network credentials (SSID and password)
- Telegram Bot token obtained from the BotFather on Telegram
- OpenAI API key for accessing the GPT-3.5 Turbo model

## Installation
Install the required libraries by navigating to Sketch -> Include Library -> Manage Libraries and search for the following libraries:
- ESP8266WiFi
- UniversalTelegramBot
- ArduinoJson
- WiFiClientSecureBearSSL
- ChatGPT

## Screenshots
![Ekran görüntüsü 2023-05-18 130709](https://github.com/ozermehmett/NodeMCU-Telegram-Bot-with-OpenAI-API-Integration/assets/115498182/6438766f-d49a-417e-ac9a-3c8eae77ef24)

## Usage
- Start the Telegram bot by sending the  command./start
- The bot will respond with a welcome message, indicating that it is ready to generate responses using the GPT-3.5 Turbo model.
- Send any text message to the bot, and it will use the GPT-3.5 Turbo model to generate a response.
- The bot will send the generated response back to the Telegram chat.
- Continue the conversation by sending additional messages to the bot.

# Did you find this repository helpful?
Do not forget to give a start

# Didn't you?
Then fork this repo, make it BETTER and do not forget to give a STAR
