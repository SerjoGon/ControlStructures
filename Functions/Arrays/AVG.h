#pragma once
#include"Constants.h"
#include"Sum.h"

template<typename T>
double AVG(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
template<typename T>
double AVG(T arr[ROW][COL], const int ROW, const int COL)
{
	return(double)Sum(arr, ROW, COL) / ROW / COL;
}