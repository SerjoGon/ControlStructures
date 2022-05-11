#pragma once
template<class T>  T* Erase(T* arr, int& n, int& index);
template<class T> T** erase_row(T** arr, int& rows, int& cols, int& index);
template<class T> T** erase_cols(T** arr, const int rows, int& cols, int& index);
