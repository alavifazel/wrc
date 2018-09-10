#ifndef RELAY_H
#define RELAY_H

#include <string>
#include "http.h"
class relay
{
public:
    relay(const std::string address);
    ~relay();
    void on();
    void off();
    static int numberOfDevices();
private:
    std::string address;
    HTTP h;
    static int counter;
};

#endif // RELAY_H
