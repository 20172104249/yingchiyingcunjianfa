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
		cout << feet << " feet " << inches << " inches " << endl;
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
		int i;
		inches = inches + feet * 12;
		o.inches = o.inches + o.feet * 12;
		i = inches - o.inches;
		CFeet temp;
		if (i<0)
		{
			if (i <= -12)
			{
				i = -1 * i;
				temp.setvalue(-1 * (i / 12), i % 12);
			}
			else
			{
				temp.setvalue(i / 12, (i % 12));
			}
		}
		else
		{
			temp.setvalue(i / 12, i % 12);
		}

		return temp;
	}
};

int main()
{
	CFeet A, B, C, D;
	A.setvalue(-1, 1);
	B.setvalue(-3, 1);

	C = A - B;
	C.display();

	A.setvalue(2, 0);
	B.setvalue(3, 1);
	D = A + B;
	D.display();
	return 0;
}
