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
    
    if (vm.count("help")) {
      cout << "Usage: options_description [options]\n";
      cout << desc;
      return 0;
    }

    if (vm.count("address")){
      relay r1{vm["address"].as<string>()};
      if( vm["turn"].as<string>() == "on") {
	r1.on();
      } else {
	r1.off();
      }
    }

  } catch(std::exception& e){
    cout << e.what() << '\n';
  }

}


