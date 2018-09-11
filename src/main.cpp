#include <iostream>
#include "relay.h"
using namespace std;

int main() {
  relay r1{"192.168.1.51"};
  r1.off();
  sleep(1000); 
  r1.on();
  cout << r1 << endl;
}


