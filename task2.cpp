#include<vector>
using namespace std;
template<typename T>
class sort
{
	public:
		void sort_ascending(T x[], int size)
		{
			for(int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (x[i] > x[j])
					{
						T X = x[i];
						x[i] = x[j];
						x[j] = X;
					}
				}
			}
		}
		void sort_descending(T x[], int size)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (abs(x[i]) < abs(x[j]))
					{
						T X = x[i];
						x[i] = x[j];
						x[j] = X;
					}
				}
			}
		}
		void sort_evenasc_odddes(int x[],int size)
		{
			vector<int> even, odd;
			for (int i = 0; i < size; i++)
			{
				if (x[i] % 2 == 0)
					even.push_back(x[i]);
				else
					odd.push_back(x[i]);
			}
			int* even_array = new int[even.size()];
			for (int i = 0; i < even.size(); i++)
				even_array[i] = even[i];
			int* odd_array = new int[odd.size()];
			for (int i = 0; i < odd.size(); i++)
				odd_array[i] = odd[i];
			sort_ascending(even_array, even.size());
			sort_descending(odd_array, odd.size());
			for (int i = 0; i < size; i++)
			{
				if (i < even.size())
					x[i] = even_array[i];
				else
					x[i] = odd_array[i - even.size()];
			}
		}
		void sort_negativedes_positiveasc(T x[], int size)
		{
			vector<T>neg, pos;
			for (int i = 0; i < size; i++)
			{
				if (x[i] < 0)
					neg.push_back(x[i]);
				else
					pos.push_back(x[i]);
			}
			T* neg_array = new T[neg.size()];
			T* pos_array = new T[pos.size()];
			for (int i = 0; i < neg.size(); i++)
				neg_array[i] = neg[i];
			for (int i = 0; i < pos.size(); i++)
				pos_array[i] = pos[i];
			sort_ascending(neg_array, neg.size());
			sort_ascending(pos_array, pos.size());
			for (int i = 0; i < size; i++)
			{
				if (i < neg.size())
					x[i] = neg_array[i];
				else
					x[i] = pos_array[i - neg.size()];
			}
		}
};