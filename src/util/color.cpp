#include "color.h"

Color Color::operator + (const Color& k) const
{
	return Color(r + k.r, g + k.g, b + k.b);
}

Color& Color::operator += (const Color& k)
{
	r += k.r, g += k.g, b += k.b;
	return *this;
}

Color Color::operator + (const Color::ColT& k) const
{
	return Color(r + k, g + k, b + k);
}

Color& Color::operator += (const Color::ColT& k)
{
	r += k, g += k, b += k;
	return *this;
}



Color Color::operator - (const Color& k) const
{
	return Color(r - k.r, g - k.g, b - k.b);
}

Color& Color::operator -= (const Color& k)
{
	r -= k.r, g -= k.g, b -= k.b;
	return *this;
}

Color Color::operator - (const Color::ColT& k) const
{
	return Color(r - k, g - k, b - k);
}

Color& Color::operator -= (const Color::ColT& k)
{
	r -= k, g -= k, b -= k;
	return *this;
}



Color Color::operator * (const Color& k) const
{
	return Color(r * k.r, g * k.g, b * k.b);
}

Color& Color::operator *= (const Color& k)
{
	r *= k.r, g *= k.g, b *= k.b;
	return *this;
}

Color Color::operator * (const Color::ColT& k) const
{
	return Color(r * k, g * k, b * k);
}

Color& Color::operator *= (const Color::ColT& k)
{
	r *= k, g *= k, b *= k;
	return *this;
}



Color Color::operator / (const Color::ColT& k) const
{
	return Color(r / k, g / k, b / k);
}

Color& Color::operator /= (const Color::ColT& k)
{
	r /= k, g /= k, b /= k;
	return *this;
}



Color::ColT Color::mod2(void) const { return r * r + g * g + b * b;}
Color Color::inverse(void) const { return Color(1 - r, 1 - g, 1 - b); }

Color Color::exp(void) const
{
	return Color(std::exp(r), std::exp(g), std::exp(b));
}
Color Color::normal(void) const
{
	return Color(std::max(std::min(r, 1.0), 0.0), std::max(std::min(g, 1.0), 0.0), std::max(std::min(b, 1.0), 0.0));
}

inline std::ostream& operator << (std::ostream& out, const Color& x)
{
    return out << '(' << x.r << ' ' << x.g << ' ' << x.b << ')';
}
