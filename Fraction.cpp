using namespace std;
class Fraction
{
	private:
		int Den;
		int Num;
	public:
		Fraction() { Num = 0; Den = 0; }
		Fraction(int Num, int Den) { this->Den = Den; this->Num = Num; }
		void setDen(int Den) { if (Den != 0)this->Den = Den; }
		void setNum(int Num) { this->Num = Num; }
		int getDen() { return Den; }
		int getNum() { return Num; }
		Fraction operator-()
		{
			setNum(-getNum());
			return *this;
		}
		Fraction operator+(const Fraction& f)
		{
			Fraction F;
			F.setNum(f.Num + this->getNum());
			F.setDen(f.Den);
			return F;
		}
		Fraction operator=(const Fraction &f)
		{
			this->setDen(f.Den);
			this->setNum(f.Num);
			return *this;
		}
		Fraction operator-(const Fraction& f)
		{
			Fraction F;
			F.setNum(this->getNum() - f.Num);
			F.setDen(this->getDen());
			return F;
		}
		Fraction operator*(const Fraction& f)
		{
			Fraction F;
			F.setNum(this->getNum() * f.Num);
			F.setDen(this->getDen() * f.Den);
			return F;
		}
		Fraction operator/(const Fraction &f)
		{
			Fraction F;
			F.setNum(this->getNum() * f.Den);
			F.setDen(this->getDen() * f.Num);
			return F;
		}
		bool operator<(const Fraction f)
		{
			if (this->getNum() < f.Num)
				return true;
			return false;
		}
		bool operator>(const Fraction f)
		{
			if (this->getNum() > f.Num)
				return true;
			return false;
		}
		bool operator==(const Fraction f)
		{
			if (!(this->getNum() > f.Num) && !(this->getNum() < f.Num))
				return true;
			return false;
		}
		bool operator<=(const Fraction f)
		{
			if ((this->getNum() < f.Num) || (this->getNum() == f.Num))
				return true;
			return false;
		}
		bool operator>=(const Fraction f)
		{
			if ((this->getNum() > f.Num) || (this->getNum() == f.Num))
				return true;
			return false;
		}
		bool operator!=(const Fraction f)
		{
			if (!(this->getNum() == f.Num))
				return true;
			return false;
		}
		Fraction operator++(int)
		{
			this->setNum(this->getDen() + this->getNum());
			return *this;
		}
		Fraction operator--(int)
		{
			this->setNum(this->getNum() - this->getDen());
			return *this;
		}
		Fraction& operator++()
		{
			this->setNum(this->getDen() + this->getNum());
			return *this;
		}
		Fraction& operator--()
		{
			this->setNum(this->getNum() - this->getDen());
			return *this;
		}
		Fraction& operator+=(const Fraction& f)
		{
			this->setNum(this->getNum() + f.Num);
			return *this;
		}
		Fraction& operator-=(const Fraction& f)
		{
			this->setNum(this->getNum() - f.Num);
			return *this;
		}
		Fraction simplify()
		{
			if (this->getDen() >= this->getNum())
			{
				for (int i = this->getDen(); i > 1; i--)
				{
					if ((this->getDen() % i == 0 && (this->getNum() % i == 0)))
					{
						this->setDen(this->getDen() / i);
						this->setNum(this->getNum() / i);
					}
				}
			}
			else 
			{
				for (int i = this->getNum(); i > 1; i--)
				{
					if ((this->getDen() % i == 0 && (this->getNum() % i == 0)))
					{
						this->setDen(this->getDen() / i);
						this->setNum(this->getNum() / i);
					}
				}
			}
			return *this;
		}

} ;
