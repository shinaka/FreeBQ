
#include <utility.h>
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>
#include <EEPROMex.h>
#include <VM_Boards.h>
#include <SPI.h>
//#include <util.h>
//#include <EthernetUdp.h>
#include <EthernetServer.h>
#include <EthernetClient.h>
#include <Ethernet.h>
//#include <Dns.h>
//#include <Dhcp.h>
#include "FreeBQMain.h"
#include "FBQWebServer.h"
//#include <LiquidCrystal.h>
#include "IFBQModule.h"
#include "FBQUtils.h"

enum
{
	MODULE_WEBSERVER = 0,
	MODULE_COUNT,
};

CFreeBQ mainModule;
IFBQModule *modules[MODULE_COUNT];

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
	Serial.begin(9600);
	LogTrace("Testing");
	modules[MODULE_WEBSERVER] = new CFBQWebServer();
	
}

void loop()
{
	for(int i = 0; i < MODULE_COUNT; ++i)
	{
		if(modules[i] != NULL && modules[i]->IsRegularlyUpdated())
		{
			modules[i]->Update();
		}
	}
	//mainModule->GetSettingsLibrary()->SetProbeBlower(1, random(1, 3));
}
