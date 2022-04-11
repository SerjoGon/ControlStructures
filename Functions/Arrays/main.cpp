#include<iostream>
using namespace std;
#define tab "\t"
#define delimetr "\n___________________________\n"
const int ROWS = 3;
const int COLS = 4;

void Fillrand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Fillrand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void Fillrand(double arr[], const int n, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(double arr[], const int n);

void Sort(int arr[], const int n);
void Sort(double arr[], const int n);

int Sum(int arr[], const int n);
double Sum(double arr[], const int n);

double AVG(int arr[], const int n);
double AVG(double arr[], const int n);

int MIN(int arr[], const int n);
double MIN(double arr[], const int n);

int MAX(int arr[], const int n);
double MAX(double arr[], const int n);

void ShiftR(int arr[], const int n, int shiftsR);
void ShiftL(int arr[], const int n, int shiftsL);

void main()
{
	setlocale(LC_ALL, "RU");
	const int n = 5;
	int arr[n];
	Fillrand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(arr, n) << endl;
	cout << "Минимальное значение массива: " << MIN(arr, n) << endl;
	cout << "Максимальное значение массива: " << MAX(arr, n) << endl;
	int shiftsR;
	int shiftsL;
	cout << "Введите количесвто сдвигов массива вправо:"; cin >> shiftsR;
	cout << "Введите количество сдвигов:"; cin >> shiftsL;
	ShiftR(arr, n, shiftsR);
	Print(arr, n);
	ShiftL(arr, n, shiftsL);
	ShiftL(arr, n, shiftsL);
	Print(arr, n);
	cout << delimetr << endl;

	const int m = 10;
	double brr[m];
	Fillrand(brr, m, 0, 30);
	Print(brr, m);
	Sort(brr, m);
	Print(brr, m);
	cout << "Сумма элементов массива: " << Sum(brr, m) << endl;
	cout << "Среднее арифметическое элементов массива :" << AVG(brr, m) << endl;
	cout << "Минимальное значение массива: " << MIN(brr, m) << endl;
	cout << "Максимальное значение массива: " << MAX(brr, m) << endl;
	cout << delimetr << endl;

	int arr2[ROWS][COLS];
	Fillrand(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
}
void Fillrand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void Fillrand(double arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void Fillrand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
		arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
		cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}


void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}

int Sum(int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Sum(double arr[], const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double AVG(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double AVG(double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

int MIN(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}
double MIN(double arr[], const int n)
{
	double min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

int MAX(int arr[], const int n)
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
double MAX(double arr[], const int n)
{
	double max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void ShiftR(int arr[], const int n, int shiftsR)
{
	for (int j = 0; j < shiftsR;j++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}

void ShiftL(int arr[], const int n, int shiftsL)
{
	for (int i = 0; i < shiftsL; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}

}