#include "EFQBEvent.h"

class IFBQDevice
{
public:
	virtual ~IFBQDevice() {}
	virtual bool IsRegularlyUpdated() = 0;
	virtual void Update() = 0;
	virtual void OnEvent(EFBQEvent event) = 0;
};