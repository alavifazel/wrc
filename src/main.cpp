#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "relay.h"
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

using namespace std;
using namespace boost;

int main(int ac, char* av[]) {
  try {
    po::options_description desc("Allowed options");
    desc.add_options()
      ("help", "produce help message")
      ("address,a", po::value<string>(),
       "relay's address")

      ("turn,t", po::value<string>(),
       "turn relay on and off")
      ;

    po::variables_map vm;
    po::store(po::command_line_parser(ac, av).
	      options(desc).run(), vm);
    po::notify(vm);
    

    if (vm.count("address")) {
      relay r1{vm["address"].as<string>()};
      if(!vm.count("turn")){	
	if(r1.isOn()){
	  r1.off();
	  cout << "Relay turned off.\n";
	} else {
	  r1.on();
	  cout << "Relay turned on.\n";
	}
      } else {
	if( vm["turn"].as<string>() == "on") {
	  r1.on();
	} else {
	  r1.off();
	}
      }
    }

  } catch(std::exception& e){
    cout << e.what() << '\n';
  }

}


