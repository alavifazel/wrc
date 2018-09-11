#include "relay.h"
#include <iostream>

relay::relay(const std::string address): address{address} {
    counter++;
}

relay::~relay(){
    counter--;
}
void relay::on(){
    std::string url = address + "/RELAY=ON";
    h.connect(url);
    currentStatus = RelayStatus::on;
}

void relay::off(){
    std::string url = address + "/RELAY=OFF";
    h.connect(url);
    currentStatus = RelayStatus::off;
}

int relay::numberOfDevices(){
    return counter;
}

int relay::counter = 0;

std::ostream& operator<<(std::ostream& os, relay const& r) {
  std::cout << "Relay's ip: " << r.address << '\n';
  if(r.currentStatus == RelayStatus::on) {
    std::cout << "Current status: On.\n ";
  } else {
    std::cout << "Current status: Off.\n";
  }
}


bool relay::isOn() const {
  if(currentStatus == RelayStatus::on){
    return true;
  } else {
    return false;
  }
}
