#include "FBQSettingsLib.h"
#include <EEPROM.h>
#include "FBQUtils.h"
#define FBQVersion "va1"

CFBQSettingsLib::CFBQSettingsLib(void)
{
	
}


CFBQSettingsLib::~CFBQSettingsLib(void)
{

}

void CFBQSettingsLib::SetIPAddress(char ip[4])
{

}

void CFBQSettingsLib::SaveConfig()
{
	for(unsigned int t=0; t< sizeof(m_settings); t++)
	{
		EEPROM.write(CONFIG_START + t, *((char*)&m_settings + t));
		if(EEPROM.read(CONFIG_START + t) != *((char*)&m_settings + t))
		{
			LogError("Writing settings to EEPROM failed");
		}
	}
}

void CFBQSettingsLib::LoadConfig()
{
	if (EEPROM.read(CONFIG_START + sizeof(m_settings)-2) == m_settings.configVer[2] &&
		EEPROM.read(CONFIG_START + sizeof(m_settings)-3) == m_settings.configVer[1] &&
		EEPROM.read(CONFIG_START + sizeof(m_settings)-4) == m_settings.configVer[0])
	{ // reads settings from EEPROM
		for (unsigned int t = 0; t<sizeof(m_settings); t++)
			*((char*)&m_settings + t) = EEPROM.read(CONFIG_START + t);
	}
	else 
	{
		m_settings.ip = IPAddress(192, 168, 1, 32);
		m_settings.subnet = IPAddress(255, 255, 255, 0);
		m_settings.gateway = IPAddress(192, 168, 1, 1);

		char ver[4] = FBQVersion;
		strcpy(m_settings.configVer, FBQVersion);

		strncpy(m_settings.blower1name, "Blower 1", sizeof(m_settings.blower1name));
		strncpy(m_settings.blower2name, "Blower 2", sizeof(m_settings.blower2name));
		strncpy(m_settings.blower3name, "Blower 3", sizeof(m_settings.blower3name));

		strncpy(m_settings.probe1name, "Probe 1", sizeof(m_settings.probe1name));
		strncpy(m_settings.probe2name, "Probe 2", sizeof(m_settings.probe2name));
		strncpy(m_settings.probe3name, "Probe 3", sizeof(m_settings.probe3name));

		m_settings.probe1blower = 1;
		m_settings.probe2blower = 2;
		m_settings.probe3blower = 3;

		SaveConfig();
	}
}