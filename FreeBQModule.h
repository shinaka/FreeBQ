#ifndef __FREEBQMODULE_H__
#define __FREEBQMODULE_H__

class CFreeBQModule
{
public:
	CFreeBQModule();
	~CFreeBQModule();
	inline bool IsRegularlyUpdated() { return m_bRegularlyUpdated; }
	virtual void DoUpdate() = 0;
protected:
	bool m_bRegularlyUpdated;

};
#endif