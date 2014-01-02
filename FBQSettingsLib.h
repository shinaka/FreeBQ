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
	byte probe1blower;
	byte probe2blower;
	byte probe3blower;
	char configVer[4];
};

class CFBQSettingsLib
{
public:
	CFBQSettingsLib(void);
	~CFBQSettingsLib(void);

	void SaveConfig();
	void LoadConfig();

	void SetIPAddress(char ip[4]);
	void SetGatewayAddress(char addr[4]);
	void SetSubnetAddress(char addr[4]);
	void SetProbeName(int probe, const char* name);
	void SetBlowerName(int blower, const char* name);
	void SetProbeBlower(int probe, int blower);

	void GetIPAddress(byte *ip);
	void GetGatewayAddress(byte *addr);
	void GetSubnetAddress(byte *addr);
	const char* GetProbeName(int probe);
	const char* GetBlowerName(int blower);
	int GetProbeBlower(int probe);

protected:
	FreeBQSettingsStruct m_settings;

};

