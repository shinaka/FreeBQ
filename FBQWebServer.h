#pragma once
#include "IFBQModule.h"
#include <SPI.h>
#include <Ethernet.h>

class CFBQWebServer : public IFBQModule
{
public:
	CFBQWebServer();
	virtual ~CFBQWebServer();
	virtual void Update();
	virtual bool IsRegularlyUpdated();
	virtual void OnEvent(EFBQEvent event);
private:
	byte m_macAddr[6];
	IPAddress m_ip;
	EthernetServer m_server;
	void StartServer();
	void LoadSettings();

};

