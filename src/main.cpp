#include <iostream>
#include "relay.h"
using namespace std;

int main() {
    relay r1("192.168.1.51");
    r1.on();
    r1.off();
    cout << r1.numberOfDevices() << endl;
}

