#include<iostream>
using namespace std;
#define tab "\t"
#define delimetr "\n___________________________\n"
const int ROW = 4;
const int COL = 4;
const int ROWS = 3;
const int COLS = 3;

void Fillrand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Fillrand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void Fillrand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void Fillrand(double arr[ROW][COL], const int ROW, const int COL, int minRand = 0, int maxRand = 100);
void Fillrand(char arr[ROW][COL], const int ROW, const int COL);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(double arr[ROW][COL], const int ROW, const int COL);
void Print(char arr[ROW][COL], const int ROW, const int COL);

void Sort(int arr[], const int n);
void Sort(double arr[], const int n);
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Sort(double arr[ROW][COL], const int ROW, const int COL);

int Sum(int arr[], const int n);
double Sum(double arr[], const int n);
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);
double Sum(double arr[ROW][COL], const int ROW, const int COL);

double AVG(int arr[], const int n);
double AVG(double arr[], const int n);
double AVG(int arr[ROWS][COLS], const int ROWS, const int COLS);
double AVG(double arr[ROW][COL], const int ROW, const int COL);

int MIN(int arr[], const int n);
double MIN(double arr[], const int n);
int MIN(int arr[ROWS][COLS], const int ROWS, const int COLS);
double MIN(double arr[ROW][COL], const int ROW, const int COL);

int MAX(int arr[], const int n);
double MAX(double arr[], const int n);
int MAX(int arr[ROWS][COLS], const int ROWS, const int COLS);
double MAX(double arr[ROW][COL], const int ROW, const int COL);

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

	const int m = 5;
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
	double arr3[ROW][COL];
	char arr4[ROW][COL];
	Fillrand(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	Sort(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
	cout << "Сумма элементов массива:" << Sum(arr2, ROWS, COLS)<< endl;
	cout << "Среднее арифметическое элементов массива:" << AVG(arr2, ROWS, COLS) << endl;
	cout << "Минимальное значение массива:" << MIN(arr2, ROWS, COLS)<< endl;
	cout << "Максимальное значение массива:" << MAX(arr2, ROWS, COLS)<< endl;
	cout << delimetr << endl;

	Fillrand(arr3, ROW, COL);
	Print(arr3, ROW, COL);
	Sort(arr3, ROW, COL);
	cout << delimetr << endl;
	Print(arr3, ROW, COL);
	cout << "Сумма элементов массива:" << Sum(arr3, ROW, COL) << endl;
	cout << "Среднее арифметическое элементов массива:" << AVG(arr3, ROW, COL) << endl;
	cout << "Минимальное значение массива:" << MIN(arr3, ROW, COL)<< endl;
	cout << "Максимальное значение массива:" << MAX(arr3, ROW, COL)<< endl;
	cout << delimetr << endl;
	Fillrand(arr4, ROW, COL);
	Print(arr4, ROW, COL);
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
		arr[i] = (double)rand() / maxRand;
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
void Fillrand(double arr[ROW][COL], const int ROW, const int COL, int minRand, int maxRand)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = (double)rand() / maxRand;
		}
	}
}
void Fillrand(char arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % (120 - 50) + 50;
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
void Print(double arr[], const int n)
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
void Print(double arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void Print(char arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
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
void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i <= (ROWS * COLS); i++)// общий цикл для строк и столбцов
	{
		for (int j = 0; j < ROWS; j++)
		{
			for (int k = 0;k < COLS - 1; k++)
			{
				if (arr[j][k] > arr[j][k + 1]) // сортировка строк
				{
					int buffer = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = buffer;
				}
			}
		}
		for (int j = 0; j < COLS;j++)
		{
			for (int k = 0;k < ROWS - 1; k++)
			{
				if (arr[k][j] > arr[k][j + 1])// сортировка столбцов
				{
					int buffer = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = buffer;
				}
			}
		}
	}
}
void Sort(double arr[ROW][COL], const int ROW, const int COL) // сортировка массива double
{
	for (int i = 0; i < (ROW * COL);i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			for (int k = 0; k < COL - 1; k++)
			{
				if (arr[j][k] > arr[j][k + 1])
				{
					double buff = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = buff;
				}
			}
		}
		for (int j = 0; j < COL;j++)
		{
			for (int k = 0;k < ROW - 1; k++)
			{
				if (arr[k][j] > arr[k][j + 1])
				{
					double buff = arr[k][j];
					arr[k][j] = arr[k][j + 1];
					arr[k][j + 1] = buff;
				}
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
	for (int i = 0; i < n; i++)sum += arr[i];
	return sum;
}
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)sum += arr[i][j];
	}
	return sum;
}
double Sum(double arr[ROW][COL], const int ROW, const int COL)
{
	double sum = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)sum += arr[i][j];
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
double AVG(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr,ROWS,COLS) / (ROWS*COLS);
}
double AVG(double arr[ROW][COL], const int ROW, const int COL)
{
	return Sum(arr,ROW,COL) / (ROW*COL);
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
double MIN(double arr[ROW][COL], const int ROW, const int COL)
{
	double min = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL;j++)
		{
		if (arr[i][j] < min) min = arr[i][j];
		}
	}
	return min;
}
int MIN(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS;j++)
		{
		if (arr[i][j] < min) min = arr[i][j];
		}
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
int MAX(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	return max;
}
double MAX(double arr[ROW][COL], const int ROW, const int COL)
{
	double max = arr[0][0];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] > max) max = arr[i][j];
		}
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