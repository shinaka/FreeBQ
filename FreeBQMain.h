#ifndef __FREEBQMAIN_H__
#define __FREEBQMAIN_H__

#include "strings.h"
#include "FBQSettingsLib.h"

class CFreeBQ
{
public:
	CFreeBQ();
	~CFreeBQ();
protected:
	CFBQSettingsLib* m_settingsLib;
};

#endif