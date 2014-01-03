#include "FreeBQMain.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
#include "FBQUtils.h"
CFreeBQ::CFreeBQ()
{
	m_settingsLib = new CFBQSettingsLib();
	LogTrace(PSTR("FreeBQ Main started."));
}

CFreeBQ::~CFreeBQ() 
{ 
	delete[] m_settingsLib;
}
