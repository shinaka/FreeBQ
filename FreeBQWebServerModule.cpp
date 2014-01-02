#include "FreeBQWebServerModule.h"
#include "Arduino.h"
#include "FBQUtils.h"

CFreeBQWebServerModule::CFreeBQWebServerModule()
	: server(32)
{
	m_bRegularlyUpdated = true;
	m_macAddr[0] = 0xDE;
	m_macAddr[1] = 0xAD; 
	m_macAddr[2] = 0xBE;
	m_macAddr[3] = 0xEF;
	m_macAddr[4] = 0xFE;
	m_macAddr[5] = 0xED;
	LogTrace(PSTR("Init'd FreeBQWebServerModule."));
}

CFreeBQWebServerModule::~CFreeBQWebServerModule() { }

void CFreeBQWebServerModule::DoUpdate()
{
	
}
