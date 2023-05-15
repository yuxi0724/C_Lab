#ifndef TIME_H
#define TIME_H
#include<string>
using namespace std;

class Time{
	private:
		int hour;
		int minute;
		int second;
	public:
		Time() { hour = minute = second = 0; }
		Time(int hour, int minute, int second) 
		{
			this->hour = hour;
			this->minute = minute;
			this->second = second;
		}
		int getSecond()	{return second;	}
		int getMinute() { return minute; }
		int getHour() { return hour; }
		void setSecond(int second) { this->second = second; }
		void setMinute(int minute) { this->minute = minute; }
		void setHour(int hour) { this->hour = hour; }
		void add(int amount, string unit)
		{
			if (unit == "second")
			{
				second += amount;
				if (second >= 60)
				{
					minute += second / 60;
					second %= 60;
					if (minute >= 60)
					{
						hour += minute / 60;
						minute %= 60;
						if (hour >= 24)
							hour %= 24;
					}
				}
				while (second < 0)
				{
					second += 60;
					minute--;
					if (minute < 0)
					{
						hour--;
						minute += 60;
						if (hour < 0)
							hour += 24;
					}
				}
			}
			else if (unit == "minute")
			{
				minute += amount;
				if (minute >= 60)
				{
					hour += minute / 60;
					minute %= 60;
					if (hour >= 24)
						hour %= 24;
				}
				while (minute < 0)
				{
					minute += 60;
					hour--;
					if (hour < 0)
						hour += 24;
				}
			}
			else
			{
				hour += amount;
				if (hour >= 24)
					hour %= 24;
				if (hour < 0)
					hour += 24;
			}
		}
		int duration(Time T)
		{
			int difference = 0;
			if (*this == T)
				;
			else if (*this > T)
			{
				difference = (this->hour - T.hour) * 60 + this->minute;
				difference = (difference - T.minute) * 60 + this->second - T.second;
			}
			else
			{
				difference = (T.hour - this->hour) * 60 + T.minute;
				difference = (difference - this->minute) * 60 + T.second - this->second;
			}
			return difference;
		}
		bool operator<(const Time T)
		{
			if (this->hour < T.hour)
				return true;
			else if (this->hour > T.hour)
				return false;
			else
			{
				if (this->minute < T.minute)
					return true;
				else if (this->minute > T.minute)
					return false;
				if (this->second < T.second)
					return true;
				else
					return false;
			}
		}
		bool operator>(const Time T)
		{
			if (this->hour > T.hour)
				return true;
			else if (this->hour < T.hour)
				return false;
			else
			{
				if (this->minute > T.minute)
					return true;
				else if (this->minute < T.minute)
					return false;
				if (this->second > T.second)
					return true;
				else
					return false;
			}
		}
		bool operator==(const Time T)
		{
			if (!(*this < T) && !(*this > T))
				return true;
			return false;
		}
		bool operator<=(const Time T)
		{
			if (*this < T || *this == T)
				return true;
			return false;
		}
		bool operator>=(const Time T)
		{
			if (*this > T || *this == T)
				return true;
			return false;
		}
		bool operator!=(const Time T)
		{
			if (!(*this == T))
				return true;
			return false;
		}
		Time& operator ++()
		{
			this->add(1, "second");		
			return *this;
		}
		Time& operator --()
		{
			this->add(-1, "second");
			return *this;
		}
		Time operator ++(int)
		{
			this->add(1, "second");
			return *this;
		}
		Time operator --(int)
		{
			this->add(-1, "second");
			return *this;
		}
		void operator+=(int count)
		{
			this->add(count, "second");
		}
		void operator-=(int count)
		{
			this->add(-count, "second");
		}
		int operator-(const Time T)
		{
			int difference = 0;
			difference = this->duration(T);
			if (*this < T)
				difference = 0 - difference;
			return difference;
		}
};
#endif
