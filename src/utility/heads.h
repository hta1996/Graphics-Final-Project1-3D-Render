#ifndef HEADS_H
#define HEADS_H
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include "yaml-cpp/eventhandler.h"
#include "yaml-cpp/yaml.h"

using std::max;
using std::min;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::abs;
using std::ifstream;
using std::ofstream;
using std::to_string;
//using std::abs;

typedef unsigned long long uint64;
typedef long long int64;
typedef double data_type;
typedef double other_data;

void operator >> (const YAML::Node& x, int &y);
void operator >> (const YAML::Node& x, float &y);
void operator >> (const YAML::Node& x, double &y);
void operator >> (const YAML::Node& x, int64 &y);
void operator >> (const YAML::Node& x, uint64 &y);
void operator >> (const YAML::Node& x, string &y);

#endif
