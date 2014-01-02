#pragma once
#define MAX_NAME_SIZE 10
#define CONFIG_START 32
#include <string.h>
#include "Arduino.h"
#include <Ethernet.h>

struct FreeBQSettingsStruct
{
	IPAddress ip;
	IPAddress subnet;
	IPAddress gateway;
	char probe1name[MAX_NAME_SIZE];
	char probe2name[MAX_NAME_SIZE];
	char probe3name[MAX_NAME_SIZE];
	char blower1name[MAX_NAME_SIZE];
	char blower2name[MAX_NAME_SIZE];
	char blower3name[MAX_NAME_SIZE];
	int probe1blower;
	int probe2blower;
	int probe3blower;
	char configVer[4];
};

class CFBQSettingsLib
{
public:
	CFBQSettingsLib(void);
	~CFBQSettingsLib(void);

	void SaveConfig();
	void LoadConfig();

	inline void SetIPAddress(IPAddress ip) { m_settings.ip = ip; SaveConfig(); };
	inline void SetGatewayAddress(IPAddress ip) { m_settings.gateway = ip; SaveConfig(); };
	inline void SetSubnetAddress(IPAddress ip) { m_settings.subnet = ip; SaveConfig(); };
	void SetProbeName(int probe, const char* name);
	void SetBlowerName(int blower, const char* name);
	void SetProbeBlower(int probe, int blower);

	inline IPAddress GetIPAddress() { return m_settings.ip;	}
	inline IPAddress GetGatewayAddress() { return m_settings.gateway; }
	inline IPAddress GetSubnetAddress() { return m_settings.subnet; }
	const char* GetProbeName(int probe);
	const char* GetBlowerName(int blower);
	int GetProbeBlower(int probe);

protected:
	FreeBQSettingsStruct m_settings;

};

