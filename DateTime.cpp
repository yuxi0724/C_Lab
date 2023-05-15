#ifndef DATE_H
#define DATE_H
#include "Time.cpp"
#include <cmath>

using namespace std;

class DateTime {
private:
    int date;
    int month;
    int year;
    Time time;
public:
    DateTime() 
    { 
        date = 1; 
        month = 1;
        year = 1900;
    }
    DateTime(int date, int month, int year)
    {
        this->date = date;
        this->month = month;
        this->year=year;
    }
    DateTime(int date, int month, int year, Time time)
    {
        this->date = date;
        this->month = month;
        this->year = year;
        this->time = time;
    }
    DateTime(int date, int month, int year, int hour, int min, int second)
    {
        this->date = date;
        this->month = month;
        this->year = year;
        time = Time(hour, min, second);
    }
    int getDate() { return date; }
    int getMonth() 
    { 
        return month; 
    }
    int getYear() { return year; }
    int getSecond() { return time.getSecond(); }
    int getMinute() { return time.getMinute(); }
    int getHour() { return time.getHour(); }
    void setDate(int date) { this->date = date; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
    void setSecond(int second) { this->time.setSecond(second); }
    void setMinute(int minute) { this->time.setMinute(minute); }
    void setHour(int hour) { this->time.setHour(hour); }
    bool leap_year(int year)
    {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return true;
        return false;
    }
    int dateOfMonth()
    {
        if (month == 2)
        {
            if (leap_year(year))
                return 29;
            else
                return 28;
        }
        if (month < 8)
        {
            if (month % 2 == 0)
                return 30;
            else
                return 31;
        }
        else
        {
            if (month % 2 == 0)
                return 31;
            else
                return 30;
        }
    }
    void add(int amount, string unit)
    {
        if (unit == "year")
            this->setYear(year + amount);
        else if (unit == "month")
        {
            this->setMonth(month + amount);
            while (this->month >= 13)
            {
                this->setMonth(month % 12);
                if (this->month == 0)
                    this->setMonth(1);
            }
            while (this->month <= 0)
            {
                this->setMonth(month + 12);
                this->setYear(year--);
            }

        }
        else if (unit == "date")
        {
            this->setDate(date + amount);
            while (this->dateOfMonth() < date)
            {
                this->setDate(date - this->dateOfMonth());
                this->add(1, "month");
            }
            while (date <= 0)
            {
                this->add(-1, "month");
                this->setDate(this->dateOfMonth() + date);

            }
        }
        else if (unit == "week")
        {
            this->setDate(date + 14 * amount);
            while (this->getDate() <= 0)
            {
                this->add(-1, "month");
                this->setDate(this->dateOfMonth() + date);
            }
            while (this->getDate() > this->dateOfMonth())
            {
                this->add(1, "month");
                this->setDate(date - this->dateOfMonth());

            }
        }
        else if (unit == "second")
            this->time.add(amount, "second");
        else if (unit == "minute")
            this->time.add(amount, "minute");
        else
            this->time.add(amount, "hour");

    }
    int dateOfYear()
    {
        int day = 0,M=this->getMonth();
        for (int i = 1; i <= M; i++)
        {
            this->setMonth(i);
            if (i != M)
                day += this->dateOfMonth();
            else
            {
                day += date;
                return day;
            }
        }
    }
    string dateOfWeek()  
    {
        //基姆拉爾森計算公式
        int W = -1;
        if (this->getMonth() != 1 && this->getMonth() != 2)
            W = (date + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
        else
        {
            int w = (date + 2 * (month + 12) + 3 * (month + 1 + 12) / 5 + year + year / 4 - year / 100 + year / 400 + 1) / 7;
            W = w % 7;
        }
        switch (W)
        {
            case 1:
                return "Monday";
            case 2:
                return "Tuesday";
            case 3:
                return "Wednesday";
            case 4:
                return "Thursday";
            case 5:
                return "Friday";
            case 6:
                return "Saturday";
            case 0:
                return "Sunday";
            default:
                break;
        }
    }
    int weekOfYear()
    {
        //計算1/1星期幾
        int W = (1 + 2 * 1 + 3 * (1 + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        int week = (date + W) / 7;
        if ((date + W) % 7 != 0)
            week++;
        return week;
    }
    int quaterOfYear()
    {
        if (this->getMonth() < 4)
            return 1;
        if (this->getMonth() < 7)
            return 2;
        if (this->getMonth() < 10)
            return 3;
        return 4;
    }
    bool operator>(const DateTime T)
    {
        if (this->year > T.year)
            return true;
        else if (this->year < T.year)
            return false;
        else
        {
            if (this->month > T.month)
                return true;
            else if (this->month < T.month)
                return false;
            else
            {
                if (this->date > T.date)
                    return true;
                else if (this->date < T.date)
                    return false;
                else
                {   
                    if (this->time > T.time)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    bool operator<(const DateTime T)
    {
        if (this->year < T.year)
            return true;
        else if (this->year > T.year)
            return false;
        else
        {
            if (this->month < T.month)
                return true;
            else if (this->month > T.month)
                return false;
            else
            {
                if (this->date < T.date)
                    return true;
                else if (this->date > T.date)
                    return false;
                else
                {
                    if (this->time < T.time)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    bool operator==(const DateTime T)
    {
        if (!(*this > T) && !(*this < T))
            return true;
        return false;
    }
    bool operator<=(const DateTime T)
    {
        if (*this < T || *this == T)
            return true;
        return false;
    }
    bool operator>=(const DateTime T)
    {
        if (*this > T || *this == T)
            return true;
        return false;
    }
    bool operator!=(const DateTime T)
    {
        if (!(*this == T))
            return true;
        return false;
    }
    DateTime& operator++()
    {
        this->add(1, "date");
        return *this;
    }
    DateTime& operator--()
    {
        this->add(-1, "date");
        return *this;
    }
    DateTime operator++(int)
    {
        this->add(1, "date");
        return *this;
    }
    DateTime operator--(int)
    {
        this->add(-1, "date");
        return *this;
    }
    float duration(DateTime T)
    {
        float day ;
        if (*this >= T)
        {
            day = (this->dateOfYear()-T.dateOfYear());
            for (int i = T.year; i < year; i++)
            {
                if (leap_year(i))
                    day += 366;
                else
                    day += 365;
            }
            day += (float)(this->time - T.time) / 86400;
        }
        else
        {
            day = T.dateOfYear() - this->dateOfYear();
            for (int i = year; i < T.year; i++)
            {
                if (leap_year(i))
                    day += 366;
                else
                    day += 365;
            }
            day += (float)(T.time - this->time) / 86400;
        }
        return day;
    }
    float operator-(const DateTime T)
    {
        if (*this >= T)
            return this->duration(T);
        else
            return -(this->duration(T));
    }
};
#endif
