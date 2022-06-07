#include<iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;
void Allocate(int**& arr, int& rows, int& cols);
void Clear(int**& arr, int& rows, int& cols);
void Print(int* arr, int& n);
void Print(int** arr, const int rows, const int cols);
void PRINTING_WITH_THE_MAGIC_OF_PONTERS(int** arr, const int rows, const int cols);
void Fillrand(int* arr, int& n);
void Fillrand(int** arr, const int rows, const int cols);
int* push_back(int* arr, int& n, int num);
int* push_front(int* arr, int& n, int num);
int** push_row_back(int** arr, int& rows, int& cols);
int** push_row_front(int** arr, int& rows, int& cols);
int* Insert(int* arr, int& n, int num, int& index);
int** InsertRow(int** arr, int& rows, int& cols, int& index);
int* Erase(int* arr, int& n, int& index);
int** erase_row(int** arr, int& rows, int& cols, int& index);
int* PoP_back(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, int& cols);
int* PoP_front(int* arr, int& n);
int** pop_row_front(int** arr, int& rows, int& cols);
int** push_col_back(int** arr, const int rows, int& cols);
int** push_col_front(int** arr, const int rows, int& cols);
int** insert_cols(int** arr, const int rows, int& cols, int& index);
int** erase_cols(int** arr, const int rows, int& cols, int& index);
int** pop_cols_back(int** arr, const int rows, int& cols);
int** pop_cols_front(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef DYNAMIC_MEMORY_1
	int n;
	int num;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* arr = new int[n];
	Fillrand(arr, n);
	Print(arr, n);
	cout << "Введите дополнительный элемент массива. "; cin >> num;

	arr = push_back(arr, n, num);
	Print(arr, n);

	cout << "Введите дополнительный элемент массива. "; cin >> num;
	arr = push_front(arr, n, num);
	Print(arr, n);

	int index;
	cout << "Введите дополнительный элемент массива. "; cin >> num;
	cout << "Укажите ячейку массива в которую разместить доп. элемент число от ( 0 до " << n << ")";cin >> index;
	arr = Insert(arr, n, num, index);
	Print(arr, n);
	cout << "Удаляю последний элемент массива:";
	arr = PoP_back(arr, n);
	Print(arr, n);
	cout << "Удаляю первый элемент массива:";
	arr = PoP_front(arr, n);
	Print(arr, n);
	cout << "Укажите ячейку массива которую хотите удалить число от ( 0 до " << n << " ) ";cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов в стоках: "; cin >> cols;cout << endl;
	int** arr;
	Allocate(arr, rows, cols);
	Fillrand(arr, rows, cols);
	cout << "Массив выведен на экран при помощи арифметики указателей:" << endl;
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Добавление строки в конец массива:" << endl;
	arr = push_row_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Добавление строки в начало массива:" << endl;
	arr = push_row_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Введите индекс добавочной строки массива от ( 0 до " << rows << " )"; cin >> index;cout << endl;
	arr = InsertRow(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Удаление последней строки массива:" << endl;
	arr = pop_row_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Удаление первой строки массива:" << endl;
	arr = pop_row_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Введите индекс строки для удаления из массива от ( 0 до " << rows << " )"; cin >> index;cout << endl;
	arr = erase_row(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = push_col_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = push_col_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Введите индекс добавочного столбца от ( 0 до " << cols << " )"; cin >> index;cout << endl;
	arr = insert_cols(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = pop_cols_back(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	arr = pop_cols_front(arr, rows, cols);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	cout << "Введите индекс удаляемого столбца от ( 0 до " << cols - 1 << " )"; cin >> index;cout << endl;
	arr = erase_cols(arr, rows, cols, index);
	PRINTING_WITH_THE_MAGIC_OF_PONTERS(arr, rows, cols);
	//4) удаляю динамический массив
	Clear(arr, rows, cols);
	// Для проверки функции можно активировать печать массива
	//Print(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2
}
void Allocate(int**& arr, int& rows, int& cols)
{
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
}
void Clear(int**& arr, int& rows, int& cols)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
	arr = nullptr;
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
			arr[i][j] = rand() % 10;
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
	cout << endl;
}
void PRINTING_WITH_THE_MAGIC_OF_PONTERS(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << '\t';
		}
		cout << '\n';
	}
	cout << endl;
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
int** push_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [++rows];
	for (int i = 0; i < rows; i++)
	{
		//buffer[i] = arr[i];
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			if (i < rows - 1)buffer[i][j] = arr[i][j];
			else buffer[i][j] = rand() % 50;
		}
	}
	delete[] arr;
	arr = buffer;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [++rows];

	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i != 0) buffer[i][j] = arr[i - 1][j];
			else buffer[i][j] = rand() % 22;
		}
	}
	delete[] arr;
	return buffer;
}
int* push_front(int* arr, int& n, int num)
{
	int* parr = arr;
	parr = new int[++n]{};
	for (int i = 1; i <= n;i++)
	{
		parr[i] = arr[i - 1];
	}
	delete[] arr;
	parr[0] = num;
	arr = parr;
	return arr;
}
int* Insert(int* arr, int& n, int num, int& index)
{
	int* buffer = arr;
	buffer = new int[++n]{};
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
	return arr;
}
int** InsertRow(int** arr, int& rows, int& cols, int& index)
{
	int** buffer = arr;
	buffer = new int* [++rows];
	/*for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
	}*/
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i < index) buffer[i][j] = arr[i][j];
			else if (i == index) buffer[i][j] = rand() % 22;
			else buffer[i][j] = arr[i - 1][j];
		}
	}
	delete[] arr;
	return buffer;
}
int* Erase(int* arr, int& n, int& index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n;i++)
	{
		if (i < index) buffer[i] = arr[i];
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, int& cols, int& index)
{
	delete[] arr[index];
	int** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows;i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols;j++)
		{
			if (i < index) buffer[i][j] = arr[i][j];
			else buffer[i][j] = arr[i + 1][j];
		}
	}
	delete[] arr;
	return buffer;
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
int* PoP_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	delete[] arr;
	return buffer;
}
int** push_col_back(int** arr, const int rows, int& cols)
{
	cols++;
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = cols - 1; j < cols; j++)
		{
			buffer[i][j] = rand() / 100;
		}
	}
	delete[] arr;
	return buffer;
}
int** push_col_front(int** arr, const int rows, int& cols)
{
	cols++;
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			buffer[i][j] = rand() / 100;
		}
	}
	delete[] arr;
	return buffer;
}
int** insert_cols(int** arr, const int rows, int& cols, int& index)
{
	cols++;
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < index)buffer[i][j] = arr[i][j];
			else if (j == index)buffer[i][j] = rand() / 100;
			else if (j > index)buffer[i][j] = arr[i][j - 1];

		}
	}
	delete[] arr;
	return buffer;
}
int** pop_cols_back(int** arr, const int rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	cols--;
	delete[] arr;
	return buffer;
}
int** pop_cols_front(int** arr, const int rows, int& cols)
{
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}
	cols--;
	delete[] arr;
	return buffer;
}
int** erase_cols(int** arr, const int rows, int& cols, int& index)
{
	int** buffer = arr;
	buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
		for (int j = 0; j < cols; j++)
		{
			if (j < index)buffer[i][j] = arr[i][j];
			else if (j >= index)buffer[i][j] = arr[i][j + 1];

		}
	}
	cols--;
	delete[] arr;
	return buffer;
}