#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main(int argc, char** argv) {
	cout << "-Testing getter and setter....." << endl;
	Fraction f1;
	f1.setDen(97);
	f1.setNum(3);
	
	cout << "\tCase 1 normal:";
	
	if (f1.getDen() == 97 && f1.getNum() == 3) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 2 set deminator 0: ";
	
	f1.setDen(0);
	f1.setNum(3);
	
	if (f1.getDen() != 0 && f1.getNum() == 3) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "-Testing unary operator-.....";
	
	Fraction f2(2, 83);
	f2 = -f2;
	if (f2.getDen() == 83 && f2.getNum() == -2) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "-Testing binary operator+,-,*,/....." << endl;
	
	Fraction f3(2, 89);
	Fraction f4(7, 89);
	Fraction f5;
	
	cout << "\tCase 1 Operator +:";
	f5 = f3 + f4;
	if (f5.getDen() == 89 && f5.getNum() == 9) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "\tCase 2 Operator -:";
	f5 = f4 - f3;
	if (f5.getDen() == 89 && f5.getNum() == 5) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 3 Operator *:";
	f4.setDen(89);
	f3.setDen(83);
	f5 = f4 * f3;
	if (f5.getDen() == 89 * 83 && f5.getNum() == 14) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 4 Operator /:";
	f5 = f4 / f3;
	if (f5.getDen() == 2 * 89 && f5.getNum() == 7 * 83) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}

	cout << "-Testing relational operator<,>,==,<=,>=,!=....." << endl;
	
	Fraction f6(2, 73);
	Fraction f7(7, 73);
	
	cout << "\tCase 1 Operator <:";
	if (f6 < f7) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "\tCase 2 Operator >:";
	if (f7 > f6) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 3 Operator ==:";
	if (f7 == f7) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 4 Operator <=:";
	if (f6 <= f7 && f6 <=  f6) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 5 Operator >=:";
	if (f7 >= f6 && f7 >=  f7) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 7 Operator !=:";
	if (f6 != f7) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "-Testing operator ++,--,-=,+=....." << endl;
	
	Fraction f8(2, 67);
	Fraction f9(4, 67);
	
	cout << "\tCase 1 Operator ++ postfix:";
	f8++;
	if (f8.getNum() == 69 && f8.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "\tCase 2 Operator -- postfix:";
	f8--;
	if (f8.getNum() == 2 && f8.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 3 Operator ++ prefix:";
	++f8;
	if (f8.getNum() == 69 && f8.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "\tCase 4 Operator -- prefix:";
	--f8;
	if (f8.getNum() == 2 && f9.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "\tCase 3 Operator +=:";
	f8 += f9;
	if (f8.getNum() == 6 && f8.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "\tCase 4 Operator -=:";
	f8 -= f9;
	if (f8.getNum() == 2 && f8.getDen() == 67) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" << endl;
	}
	
	cout << "-Testing assignment operator...";
	
	Fraction f10(2, 61);
	Fraction f11 = f10;

	if (f11.getNum() == 2 && f11.getDen() == 61) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	cout << "-Testing simplify method...";
	
	Fraction f12(3, 6);
	f12 = f12.simplify();

	if (f12.getNum() == 1 && f12.getDen() == 2) {
		cout << " passed!" << endl;
	} else {
		cout << " failed!" <<endl;
	}
	
	return 1;
}
