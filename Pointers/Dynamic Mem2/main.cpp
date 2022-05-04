#include<iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
void Print(int** arr, const int rows, const int cols);
void Print(int* arr, int& n);
void Fillrand(int* arr, int& n);
void Fillrand(int** arr, const int rows, const int cols);
int* push_back(int* arr, int& n, int num);
int* push_front(int* arr, int& n, int num);
int* Insert(int* arr, int& n, int num, int& insert);
int* PoP_back(int* arr, int& n);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef DYNAMIC_MEMORY_1
	int n;
	int num;
	cout << "¬ведите количество элементов массива: "; cin >> n;
	int* arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "¬ведите дополнительный элемент массива. "; cin >> num;

	arr = push_back(arr, n, num);
	Print(arr, n);

	cout << "¬ведите дополнительный элемент массива. "; cin >> num;
	arr = push_front(arr, n, num);
	Print(arr, n);

	int insert;
	cout << "¬ведите дополнительный элемент массива. "; cin >> num;
	cout << "”кажите €чейку массива в которую разместить доп. элемент число от ( 0 до " << n << ")";cin >> insert;
	arr = Insert(arr, n, num, insert);
	Print(arr, n);
	cout << "”дал€ю последний элемент массива:";
	arr = PoP_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif
	int rows;
	int cols;
	cout << "¬ведите количество строк: "; cin >> rows;
	cout << "¬ведите количество элементов в стоках: "; cin >> cols;
	//1) создаю массива указателей
	int** arr = new int* [rows];
	//2) создаю строки двум массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	//3) ќбращаюсь к элементам массива заполн€€ его функцией rand()
	Fillrand(arr, rows, cols);
	Print(arr, rows, cols);
	//4) удал€ю динамический массив
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}
void Fillrand(int* arr, int& n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (n * n);
	}
}
void Fillrand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int* arr, int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}
int* push_back(int* arr, int& n, int num)
{
	int* parr = arr;
	parr = new int[n + 1]{};
	for (int i = 0; i < n;i++)
	{
		parr[i] = arr[i];
	}
	delete[] arr;
	parr[n++] = num;
	arr = parr;
	return arr;
}
int* push_front(int* arr, int& n, int num)
{
	int* parr = arr;
	parr = new int[n + 1]{};
	for (int i = 1; i <= n;i++)
	{
		parr[i] = arr[i - 1];
	}
	delete[] arr;
	parr[0] = num;
	arr = parr;
	n++;
	return arr;
}
int* Insert(int* arr, int& n, int num, int& index)
{
	int* buffer = arr;
	buffer = new int[n + 1]{};
	for (int i = n - 1; i >= index - 1;i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i <= index - 1;i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;
	buffer[index] = num;
	arr = buffer;
	n++;
	return arr;
}
int* PoP_back(int* arr, int& n)
{
	//int* parr = arr;
	/*int* parr = new int[n -1]{};
	for (int i = 0; i < n -1;i++)
	{
		parr[i] = arr[i];
	}
	delete[] arr;
	n--;
	arr = parr;
	return arr;*/
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}