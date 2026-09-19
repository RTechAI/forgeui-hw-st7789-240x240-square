#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// ForgeUI Hardware Lab
// ST7789 240x240 physical bring-up

#define TFT_SCLK 12
#define TFT_MOSI 11
#define TFT_DC    9
#define TFT_RST   10
#define TFT_CS    8

#define SCREEN_W 240
#define SCREEN_H 240

Arduino_DataBus *bus = new Arduino_ESP32SPI(
    TFT_DC,
    TFT_CS,
    TFT_SCLK,
    TFT_MOSI,
    GFX_NOT_DEFINED,
    HSPI
);

Arduino_GFX *gfx = new Arduino_ST7789(
    bus,
    TFT_RST,
    0,
    true,
    SCREEN_W,
    SCREEN_H
);

void showColour(uint16_t colour, const char *name)
{
    gfx->fillScreen(colour);

    gfx->setTextColor(WHITE);
    gfx->setTextSize(2);
    gfx->setCursor(12, 12);
    gfx->println(name);

    gfx->drawRect(0, 0, 240, 240, WHITE);

    delay(1200);
}

void drawPassScreen()
{
    gfx->fillScreen(BLACK);

    gfx->drawRect(2, 2, 236, 236, CYAN);
    gfx->drawRect(6, 6, 228, 228, BLUE);

    gfx->setTextColor(CYAN);
    gfx->setTextSize(4);
    gfx->setCursor(38, 38);
    gfx->println("FORGEUI");

    gfx->setTextColor(WHITE);
    gfx->setTextSize(3);
    gfx->setCursor(61, 92);
    gfx->println("ST7789");

    gfx->setTextSize(2);
    gfx->setCursor(70, 130);
    gfx->println("240 x 240");

    gfx->setCursor(63, 158);
    gfx->println("ESP32-S3");

    gfx->setTextColor(GREEN);
    gfx->setTextSize(2);
    gfx->setCursor(22, 202);
    gfx->println("PHYSICAL DISPLAY PASS");
}

void setup()
{
    Serial.begin(115200);
    delay(300);

    Serial.println();
    Serial.println("FORGEUI HARDWARE LAB");
    Serial.println("ST7789 240x240 BRING-UP");

    if (!gfx->begin())
    {
        Serial.println("DISPLAY INIT FAILED");
        while (true)
            delay(1000);
    }

    Serial.println("DISPLAY INIT PASS");

    showColour(RED,   "RED");
    showColour(GREEN, "GREEN");
    showColour(BLUE,  "BLUE");
    showColour(CYAN,  "CYAN");
    showColour(YELLOW,"YELLOW");

    drawPassScreen();

    Serial.println("FORGEUI ST7789 240x240 PHYSICAL TEST READY");
}

void loop()
{
    // Hold final physical-pass screen.
    delay(1000);
}