#include "relay.h"
#include <iostream>
using namespace std; 
using namespace std;
relay::relay(const std::string address): address{address} {
    counter++;
    std::string url = address + "/STATUS";
    if(h.connect(url) == "on") {
      currentStatus = RelayStatus::on;
    }
    if(h.connect(url) == "off") {
      currentStatus = RelayStatus::off;
    }
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
    std::cout << "Current status: On\n ";
  } else {
    std::cout << "Current status: Of.\n";
  }
}


bool relay::isOn() const {
  if(currentStatus == RelayStatus::on){
    return true;
  } else {
    return false;
  }
}
