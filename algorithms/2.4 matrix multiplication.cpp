#include<iostream>
#include<cstdio>
using namespace std;
class matrix //класс матрица, в книге Скиены явно не написано, но по коду понятно, что функция принимает именно его
{
public:
	int rows; //кол-во строк
	int columns; //кол-во столбцов
	double** mat; //двумерный массив, представляет матрицу
	matrix()
	{
		rows = 3;
		columns = 3;
		mat = new double* [3];
		for (int i = 0; i < 3; i++)
		{
			mat[i] = new double[3];
		}
	}
	matrix(int sze)
	{
		rows = sze;
		columns = sze;
		mat = new double* [sze];
		for (int i = 0; i < sze; i++)
		{
			mat[i] = new double[sze];
		}
	}
	matrix(int r, int c) //конструктор, первым элементом передаём кол-во строк, вторым - столбцов
	{
		rows = r;
		columns = c;
		mat = new double* [r];
		for (int i = 0; i < r; i++)
		{
			mat[i] = new double [c];
		}
	}
	~matrix() //деструктор, освобождает динамическую память
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;

	}
	void fillMat(double numb) //метод для заполнения матрицы
	{
		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				mat[i][y] = numb;
			}
		}
	}
	void print() //метод для выводы элементов матрицы
	{
		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				cout << mat[i][y] << ' ';
			}
			cout << endl; 
		}
	}
};
//такто это не самое лучшее представление матрицы в виде класса, но для работы с алгоритмом и его тестирования нам хватит
matrix * matMult(matrix *frstMat, matrix  *scndMat) /*алгоритм перемножения матриц, принимает указатели на два объекта типа матрица
возвращает указатель на матрицу-результат произведения*/
{
	if (frstMat->columns != scndMat->rows) //добавил проверку кол-ва столбцов первой матрицы и строк второй
	{
		return nullptr; 
	}
	matrix* reMat = new matrix(frstMat->rows, scndMat->columns); //создаём матрицу-результат
	for (int i = 0; i < frstMat->rows; i++)  //цикл по строкам первой матрицы
	{
		for (int y = 0; y < scndMat->columns; y++) //цикл по столбцам второй матрицы
		{
			reMat->mat[i][y] = 0; //задаём значение пустой ячейки результирующей матрицы, чтобы ниже мы могли использовать "+="
			for (int k = 0; k < scndMat->rows; k++) // цикл по строкам второй матрицы
			{
				reMat->mat[i][y] += (frstMat->mat[i][k] * scndMat->mat[k][y]); //складываем произведения столбца первой матрицы на строки второй
			}
		}
	}
	return reMat; //по оканчании цикла получаем указатель на заполненную матрицу-результат, возвращаем его
}
int main()
{
	system("chcp 1251>nul");
	matrix* frstMa = new matrix(3, 4);
	matrix* scndMa = new matrix(4, 3);
	frstMa->fillMat(3);
	scndMa->fillMat(2);
	matrix * re = matMult(frstMa, scndMa);
	re->print();
	delete frstMa;
	delete scndMa;
	delete re;
	return 0;
}
//dead butterflies - embers
