// yingchiyingcunjianfa.cpp : �������̨Ӧ�ó������ڵ㡣
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
	void setvalue(int foot,int inch)
	{
		feet = foot;
		inches = inch;
	}
	void display()
	{
		cout << feet <<" feet "<< inches <<"inches"<< endl;
	}
	CFeet operator +(CFeet&o)
	{
		CFeet temp;
		inches = feet * 12 + inches;
		o.inches = o.feet * 12 + o.inches;
		temp.setvalue((inches + o.inches) / 12, (inches + o.inches) % 12);
		return temp;
	}
	CFeet operator -(CFeet&o)
	{
		CFeet temp;
		if (feet < 0)
		{
			inches = -1*inches;
			inches = feet * 12 + inches;
			o.inches = o.feet * 12 + o.inches;
			temp.setvalue((inches - o.inches) / 12, labs(inches - o.inches ) % 12);
		}
		else 
		{
			inches = feet * 12 + inches;
			o.inches = o.feet * 12 + o.inches;
			temp.setvalue((inches - o.inches) / 12, labs(inches - o.inches) % 12);
		}

		return temp;
	}
};

int main()
{
	CFeet A, B, C;
	A.setvalue(5, 5);
	B.setvalue(2, 11);
	C = A + B;
	C.display();
	C = A - B;
	C.display();
    return 0;
}

