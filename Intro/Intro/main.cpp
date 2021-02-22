#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this-> x = x;
	}
	void set_y(double y)
	{
		/*if (y < 10)
		{
			this->y = y;
		}
		else
		{
			this->y = 10;
		}*/
		this->y = (y < 10) ? y : 10;
	}

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	void print()
	{
		cout << "X = " << this->x << "\tY = " << this->y << ";\n";
	}

	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - A.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}

class Fraktion
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}

	Fraktion(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor - " << this << endl;
	}
	~Fraktion()
	{
		cout << "Destructor - " << this << endl;
	}

	void Print()
	{
		cout << this->integer << "(" << this->numerator << "/" << this->denominator << ")" << endl;
	}
	
};





void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	Point A;//Объявление переменной А типо Point. Создание структуры Point
	A.set_x(2);
	A.set_y(5);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // BASICS
	Point A;	//Default constructor
	A.print();

	Point B(5, 2);
	B.print();

	Point C = 5;
	C.print();

	cout << "\n================================Method=============================\n" << endl;
	cout << A.distance(B) << endl;
	cout << B.distance(A) << endl;
	cout << "\n================================Function===========================\n" << endl;
	cout << distance(A, B) << endl;
	cout << "\n================================End================================\n" << endl;
	cout << "===============Fraction================" << endl;
	Fraktion Z(1, 2, 3);
	Z.Print();	
}