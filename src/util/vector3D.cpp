#include "vector3D.h"

template < typename Coor_T >
auto Vector3D<Coor_T>::refract(const Vector3D<Coor_T>& n, Constant::other_data re_index) const
{
	Coor_T ni = 1 / re_index, cosI = this->dot(n), cosT2; //I->T 
	cosT2 = 1 - ni * ni * (1 - cosI * cosI);
	if (cosT2 >= 0)
		return (*this) * ni - n * (sqrt(cosT2) + cosI * ni);
	else return Vector3D<Coor_T>(); //È«·´Éä
}
template < typename Coor_T >    
auto Vector3D<Coor_T>::genVert(void) const
{
	return Vector3D<Coor_T>(y, -x, 0).unit(); 
	/*
	Vector3D v = (*this) * (Vector3D(0, 0, 1));
	if (v.mod2() < Const::EPS) Vector3D v = (*this) * (Vector3D(1, 0, 0));
	return v.unit();*/
}
/*
Vector3D Vector3D::diffuse() const
{
	
    double theta = acos(sqrt(Const::randDouble())), phi = 2 * Const::PI * Const::randDouble();
    Vector3 dir(cos(phi) * sin(theta), sin(phi) * sin(theta), cos(theta));
    Vector3 dx = getAnVerticalVector(), dy = (*this) * (dx);
    return dx * dir.x + dy * dir.y + operator*(dir.z);
}*/

template < typename Coor_T >
auto Vector3D<Coor_T>::unit(void) const
{
	Coor_T len = mod();
	return *(this) / (len < Constant::EPS ? 1 : len);
}

template < typename Coor_T >
auto Vector3D<Coor_T>::normal(void) const
{
	return Vector3D<Coor_T>(std::max(std::min(r, 1.0), 0.0), std::max(std::min(g, 1.0), 0.0), std::max(std::min(b, 1.0), 0.0));
}

template < typename Coor_T >
auto Vector3D<Coor_T>::mix(const Vector3D<Coor_T> &a, const Vector3D<Coor_T> &b, const Vector3D<Coor_T> &c)
{ return a.dot(b * c); }

template < typename Coor_T >
auto Vector3D<Coor_T>::rand(void)
{
	Vector3D<Coor_T> v;
	while (true)
	{
		v.x = Constant::randD();
		v.y = Constant::randD();
		v.z = Constant::randD();
		if (v.mod2() > Constant::EPS) break;
	}
    return v.unit();
}

