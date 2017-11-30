#include "utility/color.h"
#include "utility/Vector3D.h"
#include "utility/constant.h"
#include "yaml-cpp/eventhandler.h"
#include "yaml-cpp/yaml.h"
#include <typeinfo>

//Color a;
struct node
{
	int x, y;
	int &r = x; 
	node(): x(0), y(0) {}
	node(int x,int y):x(x), y(y){}
	node operator * (const int& z) const
	{
		return node(x * z, y * z);
	}
	node& operator = (const node &p) 
	{
		x = p.x, y = p.y;
		return *this;
	}
};

void operator >> (const YAML::Node& nodep, node& p) { 
  nodep["x"] >> p.x;
  nodep["y"] >> p.y;
 	cout << typeid( nodep["x"]).name() << ' '  << typeid( nodep).name();
} 

void debug1(void)
{
	
ifstream fin("input.yaml"); 
YAML::Node K = YAML::LoadFile("input.yaml"); 
for (auto x : K)
{
	cout << x.first << ' ' << x.second << endl;
}
node x;
K >> x;
cout << x.x << x.y;
}

int main(void)
{
	//int *a = new int [10];
	
/*	int a[10];
	for (auto &x: a) x = 7;
	for (auto x: a)
	{ 
		std::cout << x << std::endl;
	}
	//Color::Col_T t = 0.5;
	node tt;
	int s = 11; 
	tt = node(1, 1);
	tt = tt * (s+2);
	std::cout << tt.x << ' ' << tt.y;
	tt.r= 1;
	std::cout << tmp;
	std::cout << tt.x << ' ' << tt.y;*/
	//td::cout << tt.x << std::endl;
//std::cout << (a * 10).r << std::endl;
	//std::cout << (1LL << 60) << std::endl;

	debug1();
	return 0;
}
