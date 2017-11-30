#include "heads.h"

void operator >> (const YAML::Node& x, int &y) { if (x) y = x.as<int>(); }
void operator >> (const YAML::Node& x, float &y) { if (x) y = x.as<float>(); }
void operator >> (const YAML::Node& x, double &y) { if (x) y = x.as<double>(); }
void operator >> (const YAML::Node& x, int64 &y) { if (x) y = x.as<int64>(); }
void operator >> (const YAML::Node& x, uint64 &y) { if (x) y = x.as<uint64>(); }
void operator >> (const YAML::Node& x, string &y) { if (x) y = x.as<string>(); }
