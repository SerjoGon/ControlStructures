#include<iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Ru");
	const int n = 4;
	int arr[n][n] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			arr[i][j] = rand() % (n * n);
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			bool already_there = false;
			for (int k = 0; k < i;k++)
			{
				for (int l = 0; l < n; l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						already_there = true;
						break;
					}
				}
			}
			for (int f = 0; f < j; f++)
			{
				if (arr[i][j] == arr[i][f])
				{
					already_there = true;
					break;
				}
			}
			if (already_there) continue;
			int count = 1;
			for (int k = i; k < n;k++)
			{
				for (int l = (k == i ? j + 1 : 0); l < n;l++) // условие для корректного перебора массива
				{
					if (arr[i][j] == arr[k][l])count++; 
				}
			}
			if (count > 1) cout << arr[i][j] << " Повторяется " << count << "раза" << endl;
		}
	}
}
