#ifndef RELAY_H
#define RELAY_H

#include <string>
#include "http.h"
#include <chrono>
#include <thread>

enum class RelayStatus{ off, on };

class relay
{
public:
    relay(const std::string address);
    ~relay();
    void on();
    void off();
    static int numberOfDevices();
    friend std::ostream& operator<<(std::ostream& os, relay const& r);
    bool isOn() const;
 private:
    std::string address;
    HTTP h;
    static int counter;
    RelayStatus currentStatus;
};

inline void sleep(int x) {
  std::this_thread::sleep_for(std::chrono::milliseconds(x));
}


#endif // RELAY_H
