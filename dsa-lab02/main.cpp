#include<iostream>

using namespace std;

int somesum(int n, int& count_assign, int& count_compare);
int squaresum_recursion(int n, int& count_assign, int& count_compare);

int main()
{
	cout << "Bài 1" << endl;

	for (size_t i = 0; i <= 500; i+=25)
	{
		int count_assign = 0, count_compare = 0;

		somesum(i, count_assign, count_compare);

		cout << i << "\t" << count_assign << "\t\t" << count_compare << endl;
	}

	cout << "Bài 2" << endl;

	for (size_t i = 0; i <= 500; i += 25)
	{
		int count_assign = 0, count_compare = 0;
		int n = 2;

		squaresum_recursion(i, count_assign, count_compare);

		cout << i << "\t" << count_assign << "\t\t\t" << count_compare << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

int somesum(int n, int &count_assign, int &count_compare)
{
	count_assign = 0;
	count_compare = 0;

	int sum = 0; ++count_assign;
	int i = 1; ++count_assign;
	int j;

	while (++count_compare && i <= n)
	{
		j = n - i; ++count_assign;

		while (++count_compare && j <= i*i)
		{
			sum = sum + i * j; ++count_assign;
			j += 1; ++count_assign;
		}

		i += 1; ++count_assign;
	}

	return sum;
}

//cần chú ý: ghi chú lại có xem truyền n-1 có xem là phép gán không?
int squaresum_recursion(int n, int& count_assign, int& count_compare)
{
	if (++count_compare && n < 1)
	{
		return 0;
	}
	else
	{
		return n * n + squaresum_recursion(n - 1, count_assign, count_compare);
	}
}