#include<iostream>
#include<cstdlib>
using namespace std;
double power(double numb, int po) /*рекурсивный алгоритм, который упрощает возведение в степень
за счёт рекурсии оценка алгоритма вместо n-1 будет lg(n), алгоритм делит степень пополам, пока
не доходит до 0, после этого мы идём назад по рекурсии, в итоге получая число,
возведённое в степень*/
{
	if (po == 0)
	{
		return 1;
	}
	double re = power(numb, po / 2); 
	if (po % 2 == 0)
	{
		return re * re;
	}
	else
	{
		return re * re * numb;
	}
}
int main()
{
	system("chcp 1251>nul");
	int number = 10;
	int pwr = 100000000000000;
	cout << power(number, pwr) << endl;
	return 0;
}
