#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
//алгоритм поиска строки в тексте
int findmatch(char *p, char *t) //p - строка, искомая нами, t - текст, в котором мы ищем строку
{
	int j; //счётчик для whil'a
	int plen = strlen(p), tlen = strlen(t); //длины строк
	for (int i = 0; i <= (tlen - plen); i++) //идём по тексту, пока i != размеру текста-размеру строки, пытаемся найти совпадение с первой буквой слова 
	{
		j = 0;
		while ((j < plen) && (t[i + j] == p[j])) //когда находим, сравниваем следующие буквы
		{
			j++;
		}
		if (j == plen) //если j равняется длине искомой строки => мы нашли искомое слово
		{
			return i; //возвращаем индекс первой буквы искомого слова в тексте
		}
	}
	return -1; //если по окончании цикла for мы не вышли из функции => строки в тексте нет, тогда возвращаем -1
}
int main()
{
	system("chcp 1251>nul");
	cout << "строка, в которой будем искать - ";
	char arr[] = { "maximantonsergey, vladimir, aleksey, sashaleshavlad" };
	cout << arr << endl << "строка, которую будем искать - ";
	char srchStr[] = { "lesha" };
	cout << srchStr << endl;
	int match = findmatch(srchStr, arr);
	cout << "кусок строки, начиная с нашего слова - ";
	cout << arr+match << endl;
	return 0;
}
