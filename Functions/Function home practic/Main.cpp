#include <iostream>;
using namespace std;
void Print(int arr[], const int n);
void main()
{
	setlocale(LC_ALL, "RU");
	const int n = 5;
	int arr[n] = { 1,2,3,4,5 };
	Print(arr, n);
	int shifts;
	cout << "¬ведите количесвто сдвигов массива:"; cin >> shifts;
	/*for (int j = 0; j < shifts;j++)
	{
	int buffer = arr[0];
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = buffer;
	}
	Print(arr, n);*/
	for (int i = 0; i < shifts;i++)
	{
		int buffer = arr[n - 1];
		for (int j = n - 1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
	
	Print(arr, n);
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}