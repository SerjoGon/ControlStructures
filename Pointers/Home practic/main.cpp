#include<iostream>
using namespace std;
//#define SHIFTS
//#define WHILE_PRINT
struct node_t
{
	int data;
	node_t* next;
};
void go_through(node_t *p)
{
	while (p != nullptr)
	{
		cout << (*p).data << "\n";
		p = (*p).next;
	}
}
const int MAX_SIZE = 100;
int main()
{
	setlocale(LC_ALL, "Ru");
#ifdef SHIFTS
	const int N = 5;
	int A[N] = { 1,2,3,4,5 };

	for (int i = 0; i < N / 2; i++)
	{
		int tmp = A[i];
		A[i] = A[N - 1 - i];
		A[N - 1 - i] = tmp;
	}
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;
#endif
#ifdef WHILE_PRINT
	const int n = MAX_SIZE;
	int A[n];
	int x;
	int top = 0;
	cout << "¬ведите число:"; cin >> x;
	while (x != 0)
	{
		A[top++] = x;
		cin >> x;
	}
	while (top > 0)
	{
		cout << A[--top] << '\t';
	}
	cout << endl;
	/*for (int i = 0; i < top; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;*/
#endif

	node_t A[5];
	for (int i = 0; i < 5; i++)
	{
		A[i].data = i + 1;
		A[i].next = A + i + 1;
	}
	A[4].next = nullptr;
	node_t* p_begin = A;
	go_through(p_begin);
	return 0;
}