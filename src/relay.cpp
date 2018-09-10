#include "relay.h"

relay::relay(const std::string address): address{address} {
    counter++;
}

relay::~relay(){
    counter--;
}
void relay::on(){
    std::string url = address + "/RELAY=ON";
    h.connect(url);
}

void relay::off(){
    std::string url = address + "/RELAY=OFF";
    h.connect(url);
}

int relay::numberOfDevices(){
    return counter;
}

int relay::counter = 0;
