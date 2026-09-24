#include<iostream>
#include<cstdio>

using namespace std;
template<typename T>void insertion_sort(T s[], int n)
{
	int j; //счётчик
	for (int i = 1; i < n; i++) /*при проходе идёт от i назад, до того момента,
	пока не найдёт элемент меньше i-го,
	таким образом алгоритм вписывает неотсортированный элeмент в отсортированную часть*/
	{
		j = i;
		while ((j > 0) && (s[j] < s[j - 1]))
		{
			swap(s[j], s[j - 1]);
			j = j - 1;
		}
	}
}
// [5, 3, 2, 10, 7]
void fill_rnd(double arr[], int sze)
{
	for (int i = 0; i < sze; i++)
	{
		arr[i] = rand() % 100;
	}
}
template<typename T>void show_arr_elements(T arr[], int sze)
{
	for (int i = 0; i < sze; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	srand(time(0));
	system("chcp 1251>nul");
	double ar[10];
	fill_rnd(ar, 10);
	cout << "неотсортированный массив чисел:" << endl;
	show_arr_elements(ar, 10);
	cout << "отсортированный массив чисел:" << endl;
	insertion_sort(ar, 10);
	show_arr_elements(ar, 10);
	return 0;
}
//люблю людей
