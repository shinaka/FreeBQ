#include "FBQWebServer.h"
#include "FBQUtils.h"
#include "FreeBQMain.h"
#include "HTMLBuilder.h"
#include <StandardCplusplus.h>
#include <string>

using namespace std;

extern CFreeBQ mainModule;

CFBQWebServer::CFBQWebServer() : m_server(80)
{
	m_macAddr[0] = 0xDE;
	m_macAddr[1] = 0xAD;
	m_macAddr[2] = 0xBE;
	m_macAddr[3] = 0xEF;
	m_macAddr[4] = 0xFE;
	m_macAddr[5] = 0xED;
	StartServer();
	LogTrace(PSTR("Init'd FreeBQWebServerModule."));

}

CFBQWebServer::~CFBQWebServer() { }

void CFBQWebServer::StartServer()
{
	LoadSettings();
}

void CFBQWebServer::LoadSettings()
{
	CFBQSettingsLib *settingsLib = mainModule.GetSettingsLibrary();
	m_ip = settingsLib->GetIPAddress();
	Ethernet.begin(m_macAddr, m_ip);
	m_server.begin();
}

bool CFBQWebServer::IsRegularlyUpdated() { return true; }

void CFBQWebServer::Update()
{
	EthernetClient client = m_server.available();  // try to get client

    if (client) 
	{
		CHTMLDocument doc;
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read();
                if (c == '\n' && currentLineIsBlank) 
				{
					doc.SetTitle("Test Page");
					doc.ClearBody();
					string html = doc.GetHTMLString();
					Serial.println(html.c_str());
					client.print(html.c_str());
					//client.write(doc.GetHTMLString());
					break;
                    /*
					// send a standard http response header
                    client.println(F("HTTP/1.1 200 OK"));
                    client.println(F("Content-Type: text/html"));
                    client.println(F("Connection: close"));
                    client.println();
                    // send web page
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title>FreeBQ Status</title>");
                    client.println("</head>");
                    client.println("<body>");
                    client.println("<h1>FreeBQ Status</h1>");
                    client.println("<h2>Probes</h2>");
					client.println(F("<p>Probe data goes here.</p>"));
                    client.println("</body>");
                    client.println("</html>");
                    break;*/
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}

void CFBQWebServer::OnEvent(EFBQEvent event)
{

}