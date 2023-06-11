#include "Fraction.cpp"
using namespace std;
template <typename T> 
class tem
{
	public:
		T Min(T x, T y)
		{
			if (x < y)
				return x;
			else
				return y;
		}
		T Max(T x, T y)
		{
			if (x > y)
				return x;
			else
				return y;
		}
		T Smallest(T x[])
		{
			int smallest = x[0];
			for (int i = 1; i < x.size; i++)
				if (smallest > x[i])
					smallest = x[i];
			return smallest;
		}
		T Largest(T x[], int size)
		{
			T largest = x[0];
			for (int i = 1; i < size; i++)
				if (largest < x[i])
					largest = x[i];
			return largest;
		}
		void Sort(T x[], int size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (x[i] > x[j])
					{
						T tem = x[i];
						x[i] = x[j];
						x[j] = tem;
					}
				}
			}
		}
};