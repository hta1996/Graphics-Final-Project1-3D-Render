#include "color.h"

Color a;

struct node
{
	int x, y;
	node(int x = 0,int y = 0):x(x), y(y){}
	node operator * (const int& z) const
	{
		return node(x * z, y * z);
	}
};
  

int main(void)
{
	Color::ColT t = 0.5;
	node tt;
	int s = 11; 
	tt = node(1, 1);
	tt = tt * (s+2);
	std::cout << tt.x << std::endl;
	std::cout << (a * 10).r << std::endl;
	std::cout << (1LL << 60) << std::endl;
	return 0;
}
