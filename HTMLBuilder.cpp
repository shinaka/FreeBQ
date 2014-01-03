
#include "HTMLBuilder.h"
#include <HardwareSerial.h>
#include <string>
#include "FBQUtils.h"

using namespace std;

CHTMLDocument::CHTMLDocument()
{
	char buffer[100];
	strcpy_P(buffer, PSTR("HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\r\n\r\n<!DOCTYPE html>\n<html>\n"));
	m_sHeader.append(buffer);
	strcpy_P(buffer, PSTR("</body></html>\n"));
	m_sFooter.append(buffer);
}

CHTMLDocument::~CHTMLDocument() {}

void CHTMLDocument::ClearBody()
{
	memset(&m_sBody[0], 0, sizeof(m_sBody));
}

void CHTMLDocument::SetTitle(const char * title)
{
	m_sTitle.append(title);
}

string CHTMLDocument::GetHTMLString()
{
	LogTrace(PSTR("Outputting HTML"));
	string htmlDoc;
	htmlDoc.append(m_sHeader);
	htmlDoc.append("\n<head>\n<title>");
	htmlDoc.append(m_sTitle);
	htmlDoc.append("</title>\n</head>\n");
	htmlDoc.append("<body> TESTING");
	htmlDoc.append(m_sBody);
	htmlDoc.append(m_sFooter);
	//Serial.println(htmlDoc.c_str());
	return htmlDoc;
}
