#pragma once
template<class T> T* PoP_back(T* arr, int& n);
template<class T> T** pop_row_back(T** arr, int& rows, int& cols);
template<class T> T* PoP_front(T* arr, int& n);
template<class T> T** pop_row_front(T** arr, int& rows, int& cols);
template<class T> T** pop_cols_back(T** arr, const int rows, int& cols);
template<class T> T** pop_cols_front(T** arr, const int rows, int& cols);
