#include <iostream>
#include <fstream>
#include <cstring>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "json.hpp"



TEST_CASE("testing the json loading function") {
using json = nlohmann::json;
    std::ifstream f;
    f.open("house.compare");
    if(!f)
        MESSAGE("BOUFFON");
  
    json j;
    f >> j;
    std::cout << j["tasks"]<<std::endl;
    std::cout <<"iterations : "<< j["tasks"][0]["iterations"]<<std::endl;
    std::cout << "okay this is called"<< std::endl;
}