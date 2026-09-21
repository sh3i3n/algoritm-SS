#include<iostream>
#include<cstdio>
using namespace std;
//объявление структуры связонного списка
template<typename T> struct list /*написал темплейт, чтобы в качестве данных структуры
мы могли использовать, что угодно*/
{
	T item; //данные
	list* next; //указатель на следующий элемент
} ;
int main()
{
	return 0;
}
