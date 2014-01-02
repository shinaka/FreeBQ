#include "FBQSettingsLib.h"
#include <EEPROM.h>
#include "FBQUtils.h"

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
