//#include "color.h"
#include "Vector3D.h"
#include "constant.h"

//Color a;
struct node
{
	int x, y;
	int &r = x; 
	node(int x = 0,int y = 0):x(x), y(y){}
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

Vec3D tmp;

int main(void)
{
	//int *a = new int [10];
	int a[10];
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
	std::cout << tt.x << ' ' << tt.y;
	//td::cout << tt.x << std::endl;
//std::cout << (a * 10).r << std::endl;
	//std::cout << (1LL << 60) << std::endl;
	return 0;
}
