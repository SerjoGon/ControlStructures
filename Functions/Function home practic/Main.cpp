#include <iostream>;
using namespace std;
const int ROW = 3;
const int COL = 3;
void fillrand(char arr[ROW][COL], const int ROW, const int COL);
void Print(char arr[ROW][COL], const int ROW, const int COL);
void main()
{
	setlocale(LC_ALL, "RU");
	char arr2[ROW][COL];
	fillrand(arr2, ROW, COL);
	Print(arr2, ROW, COL);

}
void fillrand(char arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL;j++)
		{
			arr[i][j] = rand() % (120 - 60) + 60;
		}
	}
}

void Print(char arr[ROW][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}