#pragma once
template<class T> T* push_back(T* arr, int& n, int num);
template<class T> T* push_front(T* arr, int& n, int num);
template<class T> T** push_row_back(T** arr, int& rows, int& cols);
template<class T> T** push_row_front(T** arr, int& rows, int& cols);
template<class T> T** push_col_back(T** arr, const int rows, int& cols);
template<class T> T** push_col_front(T** arr, const int rows, int& cols);