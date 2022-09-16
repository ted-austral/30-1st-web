/*
 *  Project 30-1st-web - main.cpp
 *      Simple Web Page
 *          Only greetings in window
 */

#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>

#define HelloMsg        "Hello from ESP32 !"

#include "wifi_ruts.h"

WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80 

/*
 *  handleRoot:
 *      Function to manage requirements to root page
 */

static void
handleRoot( void )
{
    Serial.println( __FUNCTION__ );
    server.send(200, "text/plain", HelloMsg );  // Send HTTP status 200 (Ok) and send some text to the browser/client
}

/*
 *  handleNotFound:
 *      Function to manage requirements to non existent pages
 */

static void
handleNotFound( void )
{
    Serial.println( __FUNCTION__ );

//  Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
    server.send(404, "text/plain", "404: Not found");
}

void
setup( void )
{
    Serial.begin(SERIAL_BAUD);
    delay(10);
    Serial.println();

    wifi_connect();
/*
 *  Register functions on page requirements (only one page active in this example)
 */

// Call the 'handleRoot' function when a client requests URI "/"
    server.on("/", handleRoot);
// When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
    server.onNotFound( handleNotFound);

    server.begin(); // Actually start the server
    Serial.println("HTTP server started");
}

void
loop(void)
{
    server.handleClient(); // Listen for HTTP requests from clients
}
