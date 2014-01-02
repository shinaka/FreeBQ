#ifndef __FREEBQWEBSERVERMODULE_H__
#define __FREEBQWEBSERVERMODULE_H__
#include "FreeBQModule.h"

#include <SPI.h>
#include <Ethernet.h>



class CFreeBQWebServerModule : public CFreeBQModule
{
public:
	CFreeBQWebServerModule();
	~CFreeBQWebServerModule();
	virtual void DoUpdate();
private:
	byte m_macAddr[6];
	IPAddress ip;
	EthernetServer server;
};
#endif