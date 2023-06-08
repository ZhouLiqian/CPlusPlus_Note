//  associative_container.hpp
//  Associative_container
//  Created by Qian on 6/7/23.

#ifndef associative_container_hpp
#define associative_container_hpp
#include <stdio.h>
#include <map>
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>
using namespace::std;

map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const map<string, string> &m);
void word_transform(ifstream &map_life, ifstream &input);
#endif
/* associative_container_hpp */
