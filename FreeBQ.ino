#include <EEPROM.h>
#include <VM_Boards.h>
#include <WiFiUdp.h>
#include <WiFiServer.h>
#include <WiFiClient.h>
#include <WiFi.h>
#include <SPI.h>
#include <util.h>
#include <EthernetUdp.h>
#include <EthernetServer.h>
#include <EthernetClient.h>
#include <Ethernet.h>
#include <Dns.h>
#include <Dhcp.h>
#include "FreeBQMain.h"
#include "FreeBQModule.h"
#include "FreeBQWebServerModule.h"
#include <LiquidCrystal.h>

#define FREEBQSERIALBAUDRATE 115200

enum
{
	MODULE_WEBSERVER = 0,
	MODULE_COUNT,
};

CFreeBQ* mainModule;
CFreeBQModule *modules[MODULE_COUNT];

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.write("Test!");
	Serial.write("trying to init lcd");
	mainModule = new CFreeBQ();
	modules[MODULE_WEBSERVER] = new CFreeBQWebServerModule();
	Serial.begin(FREEBQSERIALBAUDRATE);
	
}

void loop()
{
	int test = 0;
	for(int i = 0; i < MODULE_COUNT; ++i)
	{
		test++;
		if(modules[i] != NULL && modules[i]->IsRegularlyUpdated())
		{
			modules[i]->DoUpdate();
		}
	}

}
