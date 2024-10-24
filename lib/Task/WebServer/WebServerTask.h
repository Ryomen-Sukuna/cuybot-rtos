#ifndef WEBSERVERTASK_H
#define WEBSERVERTASK_H

#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <freertos/semphr.h>

class WebServerTask {
public:
    WebServerTask();
    ~WebServerTask();
    
    void startTask();
    void stopTask();

    static void triggerDNSServer();

private:
    static void webServerTaskFunction(void *parameter);
    const uint32_t _stackSize = 6096;
    TaskHandle_t _taskHandle;

    static AsyncWebServer server;
    static DNSServer dnsServer;

    static SemaphoreHandle_t dnsSemaphore;
};

#endif