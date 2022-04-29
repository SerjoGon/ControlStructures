#include<iostream>
using namespace std;
void Loop_rand(int arr[], int n); // заполн€ю массив случайными числами. числа завис€т от введенного количества €чеек массива
void Print(int arr[], int n);
int Even(int arr[], int n);// определ€ю четные числа в массиве, игнорирую "0" 
void Fill_even(int arr[], int arr2[], int n); // копирую четные числа во второй массив 
int Odd(int arr[], int n);
void Fill_odd(int arr[], int oddarr[], int n);

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "¬ведите количество элементов массива: "; cin >> n;
	int* arr = new int[n];
	/*int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}*/
	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;*/
	Loop_rand(arr, n);
	Print(arr, n);
	int ev = Even(arr, n);// присвоил переменной результат функции определени€ четных чисел 
	int odd = Odd(arr, n);
	int* evenarr = new int[ev];// количество €чеек зависит от количества четных чисел
	int* oddarr = new int[odd];
	cout << " оличество четных чисел в массиве: " << Even(arr, n) << endl;
	cout << " оличество нечетных чисел в массиве: " << Odd(arr, n) << endl;
	Fill_even(arr, evenarr, n);
	Fill_odd(arr, oddarr, n);
	cout << "„етные числа из массива:" << endl;
	Print(evenarr, ev);
	cout << "Ќечетные числа из массива: " << endl;
	Print(oddarr, odd);
	const int SIZE = 5;
	int brr[SIZE];
	cout << typeid(brr).name() << endl;
	Loop_rand(brr, SIZE);
	Print(brr, SIZE);
	cout << sizeof(int64_t) << endl;
}
void Loop_rand(int arr[], int n)
{
	for (int i = 0; i < n;i++)
	{
		arr[i] = rand() % (n * n);
	}
}
void Print(int arr[], int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int Even(int arr[], int n)
{
	int even = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] % 2 == 0)even++;
		}
	}
	return even;
}
void Fill_even(int arr[], int arr2[], int n)
{
	//int ;
	for (int i = 0, j = 0; i < n; i++)
	{
		
		if (arr[i] != 0)
		{
			if (arr[i] % 2 == 0)
			{
				arr2[j++] = arr[i];
				//j++;
			}
		}
	}
}
int Odd(int arr[], int n)
{
	int odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] % 2 != 0)odd++;
		}
	}
	return odd;
}
void Fill_odd(int arr[], int oddarr[], int n)
{
	int ;
	for (int i = 0,j = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			if (arr[i] % 2 != 0)
			{
				oddarr[j++] = arr[i];
				//j++;
			}
		}
	}
}