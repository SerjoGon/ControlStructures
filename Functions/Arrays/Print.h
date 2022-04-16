#pragma once
#include<iostream>
#include"Constants.h"
#include"Fillrand.h"
#include"MIN.h"
#include"MAX.h"
#include"Sort.h"
#include"ShiftR.h"
#include"ShiftL.h"
using namespace std;
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << arr[i] <<"\t";
	}
	cout << endl;
}
template <typename T1>
void Print(T1 arr[ROW][COL],const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

}