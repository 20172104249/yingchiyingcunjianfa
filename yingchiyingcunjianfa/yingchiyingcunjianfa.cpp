// yingchiyingcunjianfa.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CFeet
{
private:
	int feet;
	int inches;
public:
	void setvalue(int foot, int inch)
	{
		feet = foot;
		inches = inch;
	}
	void display()
	{
		cout << feet << " feet " << inches << "inches" << endl;
	}
	CFeet operator +(CFeet&o)
	{
		CFeet te;
		inches = feet * 12 + inches;
		o.inches = o.feet * 12 + o.inches;
		te.setvalue((inches + o.inches) / 12, (inches + o.inches) % 12);
		return te;
	}
	CFeet operator -(CFeet&o)
	{
		CFeet temp;
		if (feet < 0)
		{
			inches = -1 * inches;
			inches = feet * 12 + inches;
			o.inches = o.feet * 12 + o.inches;
			temp.setvalue((inches - o.inches) / 12, labs(inches - o.inches) % 12);
		}
		else
		{
			inches = feet * 12 + inches;
			o.inches = o.feet * 12 + o.inches;
			if ((inches - o.inches) / 12 == 0)
			{
				temp.setvalue((inches - o.inches) / 12, (inches - o.inches) % 12);
			}
			else
			{
				temp.setvalue((inches - o.inches) / 12, labs(inches - o.inches) % 12);
			}

		}

		return temp;
	}
};

int main()
{
	CFeet A, B, C, D;
	A.setvalue(2, 0);
	B.setvalue(3, 1);

	C = A - B;
	C.display();

	A.setvalue(2, 0);
	B.setvalue(3, 1);
	D = A + B;
	D.display();
	return 0;
}
