#include <iostream>;
using namespace std;
const int ROW = 3;
const int COL = 3;
template<typename T>
void Fillrand(T arr[ROW][COL], const int ROW, const int COL, int MIN = 1, int MAX = 100)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = rand() % (MAX - MIN) + (MIN * 1.1);
		}
	}
}
template<typename T>
void Print(T arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void main()
{
	setlocale(LC_ALL, "RU");
	int arr[ROW][COL];
	Fillrand(arr, ROW, COL);
	Print(arr, ROW, COL);
	double arr1[ROW][COL];
	Fillrand(arr1, ROW, COL);
	Print(arr1, ROW, COL);
}
