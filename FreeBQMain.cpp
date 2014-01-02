#include "FreeBQMain.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
#include "FreeBQModule.h"

CFreeBQ::CFreeBQ()
{
	Serial.write("Init'd FreeBQMain.\n");
	m_settingsLib = new CFBQSettingsLib();
	
}

CFreeBQ::~CFreeBQ() { }
