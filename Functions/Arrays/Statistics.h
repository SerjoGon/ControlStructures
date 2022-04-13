#pragma once
#include"Conctants.h"

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