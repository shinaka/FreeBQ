#include "FBQSettingsLib.h"
#include <EEPROMex.h>
#include "FBQUtils.h"
#define FBQVersion "va3"

CFBQSettingsLib::CFBQSettingsLib(void)
{
	LoadConfig();
	
}


CFBQSettingsLib::~CFBQSettingsLib(void)
{

}

void CFBQSettingsLib::SetProbeBlower(int probe, int blower)
{
	
	switch (probe)
	{
	case 1:
		m_settings.probe1blower = blower;
		break;
	case 2:
		m_settings.probe2blower = blower;
		break;
	case 3:
		m_settings.probe3blower = blower;
		break;
	default:
		return;
	}
	SaveConfig();
	
}

void CFBQSettingsLib::SetBlowerName(int blower, const char * name)
{
	switch (blower)
	{
	case 1:
		strncpy(m_settings.blower1name, name, sizeof(m_settings.blower1name));
		break;
	case 2:
		strncpy(m_settings.blower2name, name, sizeof(m_settings.blower2name));
		break;
	case 3:
		strncpy(m_settings.blower3name, name, sizeof(m_settings.blower3name));
		break;
	default:
		return;
	}
	SaveConfig();
}

void CFBQSettingsLib::SetProbeName(int probe, const char * name)
{
	switch (probe)
	{
	case 1:
		strncpy(m_settings.probe1name, name, sizeof(m_settings.probe1name));
		break;
	case 2:
		strncpy(m_settings.probe2name, name, sizeof(m_settings.probe2name));
		break;
	case 3:
		strncpy(m_settings.probe3name, name, sizeof(m_settings.probe3name));
		break;
	default:
		LogError("Probe OOI");
		return;
	}
	SaveConfig();
}

void CFBQSettingsLib::SaveConfig()
{
	/*
	for(unsigned int t=0; t < sizeof(m_settings); t++)
	{
		EEPROM.write(CONFIG_START + t, *((char*)&m_settings + t));
		if(EEPROM.read(CONFIG_START + t) != *((char*)&m_settings + t))
		{
			LogError(PSTR("Failed to save EEPROM"));
			//return;
		}
	}*/
	EEPROM.writeBlock(CONFIG_START, m_settings);
	LogTrace(PSTR("Saved to EEPROM"));
}

void CFBQSettingsLib::LoadConfig()
{
	LogTrace(PSTR("Loading EEPROM Config."));

	EEPROM.readBlock(CONFIG_START, m_settings);
	if (strcmp(m_settings.configVer, FBQVersion) != 0)
	{
		m_settings.ip = IPAddress(192, 168, 1, 5);
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