
#pragma once
//Helper library for building webpages
#include <avr/pgmspace.h>
#include <StandardCplusplus.h>
#include <string>

using namespace std;

class CHTMLDocument
{
public:
	CHTMLDocument();
	virtual ~CHTMLDocument();
	void ClearBody();
	void SetTitle(const char * title);
	string GetHTMLString();
protected:
	string m_sBody;
	string m_sHeader;
	string m_sFooter;
	string m_sTitle;
};
