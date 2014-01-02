#include "FreeBQMain.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
#include "FreeBQModule.h"
#include "FBQUtils.h"
CFreeBQ::CFreeBQ()
{
	m_settingsLib = new CFBQSettingsLib();
	LogTrace(PSTR("FreeBQ Main started."));
}

CFreeBQ::~CFreeBQ() { }
