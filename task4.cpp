#include<iostream>
#include<fstream>
using namespace std;
class room
{
	private:
		string name;
		int night;
		int service;
		int extra;
		double total;
	public:
		room() {};
		room(string name, int night)
		{
			this->name = name;
			this->night = night;
		}
		room(string name, int service, int night)
		{
			this->name = name;
			this->service = service;
			this->night = night;
		}
		room(string name, int service, int extra, int night)
		{
			this->name = name;
			this->extra = extra;
			this->service = service;
			this->night = night;
		}
		void deluxe_fee()
		{
			total = (night*7500+service)*1.15+extra;
		}
		void preminum_fee()
		{
			total = (night * 5000 + service) * 1.05;
		}
		void business_fee()
		{
			total = (night * 3000);
		}
		string NAME()
		{
			return name;
		}
		double TOTAL()
		{
			return total;
		}
		bool compare(room last)
		{
			return (this->total > last.total * 1.25) ? true : false;
		}
};
void input(string File,room **R_d, room **R_p, room **R_b, int *d,int *p,int *b)
{
	ifstream open(File);
	if (!open)
	{
		cout << "Can't open " << File << endl;
		return;
	}
	open >> *d >> *p >> *b;
	*R_d = new room[*d];
	*R_p = new room[*p];
	*R_b = new room[*b];
	for (int i = 0; i < *d; i++)
	{
		int service, extra, night;
		string name;
		open >> name >> service >> extra >> night;
		(*R_d)[i] = room(name, service, extra, night);
		(*R_d)[i].deluxe_fee();
	}
	for (int i = 0; i < *p; i++)
	{
		int service, night;
		string name;
		open >> name >> service >> night;
		(* R_p)[i] = room(name, service, night);
		(* R_p)[i].preminum_fee();
	}
	for (int i = 0; i < *b; i++)
	{
		int night;
		string name;
		open >> name >> night;
		(*R_b)[i] = room(name, night);
		(*R_b)[i].business_fee();
	}
	open.close();
}
int main()
{
	string File="room.imp";
	string File2 = "room_last.imp";
	room* R_d, * R_p, * R_b;
	int d = -1, p, b, d2 = -1, p2, b2;
	input(File, &R_d, &R_p, &R_b, &d, &p, &b);

	room* R_d_last, * R_p_last, * R_b_last;
	input(File2, &R_d_last, &R_p_last, &R_b_last, &d2, &p2, &b2);

	ofstream out("revenue.out");
	if (!out)
	{
		cout << "Can't open out";
		return 0;
	}
	if (d == -1 || d2 == -1)
		return 0;
	out << d << " " << p << " " << b << endl;
	for (int i = 0; i < d + p + b; i++)
	{
		if (i < d)
			out << R_d[i].NAME() << endl << R_d[i].TOTAL() << endl;
		else if (i < d + p)
			out << R_p[i - d].NAME() << endl << R_p[i - d].TOTAL() << endl;
		else
			out << R_b[i - d - p].NAME() << endl << R_b[i - d - p].TOTAL() << endl;
	}
	out << "=========\nExcellent Room:\n";
	for (int i = 0; i < d + p + b; i++)
	{
		if (i < d)
		{
			if (R_d[i].compare(R_d_last[i]))
				out << R_d[i].NAME() << endl;
		}
		else if (i < d + p)
		{
			if (R_p[i - d].compare(R_p_last[i - d]))
				out << R_p[i - d].NAME() << endl;
		}
		else
			if (R_b[i - d - p].compare(R_b_last[i - d - p]))
				out << R_b[i - d - p].NAME() << endl;
	}
	out.close();
}