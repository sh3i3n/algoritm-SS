#include<iostream>
#include<cstdlib>
using namespace std;
template<typename T>void selection_sort(T arr[], int n) //сортировка методом выбора(от начала к концу)
{
	int min; //создаём переменную, которая будет указывать нам на индекс минимального элемента
	for (int i = 0; i < n; i++)
	{
		min = i; //изначально указывает на тот, элемент, с которого начинаем проверку
		for (int y = i + 1; y < n; y++)
		{
			if (arr[min] > arr[y]) //если значение элемента с индексом y < значение изначального минимального
			{
				min = y; //меняем индекс минимального элемента
			}
		}
		swap(arr[i], arr[min]); //когда прошли весь массив меняем значение i-го элемента на минимальное
		//таким образов при каждом проходе в i-ую ячейку будет помещаться наименьший элемент из оставшихся
	}
}
template<typename T> void print(T* arr, int n) //функция для вывода элементов массива
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main()
{
	system("chcp 1251>nul");
	cout << "массив до сортировки:" << endl;
	double arr[] = { 5, 4, 6, 7, 2, 10, 0 };
	print(arr, 7);
	selection_sort(arr, 7);
	cout << "массив после сортировки:" << endl;
	print(arr, 7);
	return 0;
}
