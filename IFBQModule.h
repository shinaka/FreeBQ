#ifndef __IFBQMODULE_H__
#define __IFBQMODULE_H__
#include "EFQBEvent.h"

class IFBQModule
{
public:
	virtual ~IFBQModule() {}
	virtual bool IsRegularlyUpdated() = 0;
	virtual void Update() = 0;
	virtual void OnEvent(EFBQEvent event) = 0;
};
#endif