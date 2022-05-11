#pragma once
template<class T> T* Insert(T* arr, int& n, int num, int& index);
template<class T> T** InsertRow(T** arr, int& rows, int& cols, int& index);
template<class T> T** insert_cols(T** arr, const int rows, int& cols, int& index);