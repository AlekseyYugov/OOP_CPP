#include<iostream>
using namespace std;

class Binary
{
	int m_x;
public:
	Binary(int x)
	{
		m_x = x;
	}
	double get_binary()const { return m_x;}
	friend Binary operator+(const Binary& x, const Binary& y);
	friend Binary operator-(const Binary& x, const Binary& y);
	friend Binary operator*(const Binary& x, const Binary& y);
	friend Binary operator/(const Binary& x, const Binary& y);
	friend Binary operator~(const Binary& x);
	friend Binary operator&(const Binary& x, const Binary& y);
	friend Binary operator|(const Binary& x, const Binary& y);
	friend Binary operator^(const Binary& x, const Binary& y);
	void print()
	{
		cout << get_binary() << endl;
	}
};
Binary operator+(const Binary& x, const Binary& y)
{
	return Binary(x.m_x + y.m_x);
}
Binary operator-(const Binary& x, const Binary& y)
{
	return Binary(x.m_x - y.m_x);
}
Binary operator*(const Binary& x, const Binary& y)
{
	return Binary(x.m_x * y.m_x);
}
Binary operator/(const Binary& x, const Binary& y)
{
	return Binary(x.m_x / y.m_x);
}
Binary operator~(const Binary& x)
{
	return Binary(~x.m_x);
}
Binary operator&(const Binary& x, const Binary& y)
{
	return Binary(x.m_x & y.m_x);
}
Binary operator|(const Binary& x, const Binary& y)
{
	return Binary(x.m_x | y.m_x);
}
Binary operator^(const Binary& x, const Binary& y)
{
	return Binary(x.m_x ^ y.m_x);
}

void main()
{
	Binary number1(0b01);
	Binary number2(0b11);
	Binary sumnumber1 = number1 + number2;
	sumnumber1.print();
	Binary sumnumber2 = number1 - number2;
	sumnumber2.print();
	Binary sumnumber3 = number1 * number2;
	sumnumber3.print();
	Binary sumnumber4 = number1 / number2;
	sumnumber4.print();
	Binary sumnumber5 = ~(number1 + number2);
	sumnumber5.print();
	Binary sumnumber6 = (number1 & number2);
	sumnumber6.print();
	Binary sumnumber7 = (number1 | number2);
	sumnumber7.print();
	Binary sumnumber8 = (number1 ^ number2);
	sumnumber8.print();
	
}