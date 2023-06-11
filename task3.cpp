#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class pay
{
	private:
		double payment = 0;
		int numberOfgood = 0;
		double price = 0;
		double YearOfLoyal = 0;
		string name;
	public:
		pay() {};
		pay(string name,int num, double price)
		{
			this->name = name;
			this->numberOfgood = num;
			this->price = price;
		}
		pay(string name,int num, double price,double year)
		{
			this->numberOfgood = num;
			this->price = price;
			this->name = name;
			YearOfLoyal = year;
		}
		double ordinary()	//type A
		{
			payment = (numberOfgood * price) * 1.1;
			return payment;
		}
		double loyal()
		{
			double promotion = min(YearOfLoyal * 0.05, 0.5);
			payment = ((numberOfgood * price) * (1 - promotion)) * 1.1;
			return payment;
		}
		double special()
		{
			payment = ((numberOfgood * price) * 0.5) * 1.1;
			return payment;
		}
		double paym()
		{
			return payment;
		}
		string Nam()
		{
			return name;
		}
};
ifstream open("customer.imp");
ofstream out("payment.out");
void data(pay* type, int num,int t=0)
{
	for (int i = 0; i < num; i++)
	{
		string name;
		open >> name;
		int number,price;
		open >> number;
		open >> price;
		switch (t)
		{
			case 0:
				type[i] = pay(name, number, price);
				type[i].ordinary();
				break;
			case 1:
				int yearofloyal;
				open >> yearofloyal;
				type[i] = pay(name, number, price, yearofloyal);
				type[i].loyal();
				break;
			case 2:
				type[i] = pay(name, number, price);
				type[i].special();
				break;
			default:
				break;
		}
	}
}
int main()
{
	if (!open)
	{
		cout << "can't open!";
		return -1;
	}
	int size_a, size_b, size_c;
	open >> size_a;
	if (size_a < 0 || size_a > 1000)
	{
		cout << "x is wrong.";
		return -1;
	}
	pay* A = new pay[size_a];	
	open >> size_b;
	if (size_b < 0 || size_b > 1000)
	{
		cout << "y is wrong.";
		return -1;
	}
	pay* B = new pay[size_b];
	open >> size_c;
	if (size_c < 0 || size_c > 1000)
	{
		cout << "z is wrong.";
		return -1;
	}
	pay* C = new pay[size_c];
	data(A, size_a);
	data(B, size_b,1);
	data(C, size_c,2);
	open.close();
	out << size_a << " " << size_b << " " << size_c<<"\n";
	double total=0;
	for (int i = 0; i < size_a + size_b + size_c; i++)
	{
		if (i < size_a)
		{
			out << A[i].Nam() << "\n";
			out << A[i].paym() << "\n";
			total += A[i].paym();
		}
		else if (i < size_a + size_b)
		{
			out << B[i-size_a].Nam() << "\n";
			out << B[i - size_a].paym() << "\n";
			total += B[i - size_a].paym();
		}
		else
		{
			out << C[i - size_a - size_b].Nam() << "\n";
			out << C[i - size_a - size_b].paym() << "\n";
			total += C[i - size_a - size_b].paym();
		}
	}
	out << "TotalPayment" << "\n" << total;
	out.close();
}