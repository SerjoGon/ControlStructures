#include<iostream>


using namespace std;

//#define TASK_1
//#define TASK_2
//#define TASK_2V2
#define TASK_3
void main()
{
	setlocale(LC_ALL, "Russian");
	
#ifdef TASK_1
	int n;
	double f  = 0;
	cout << "������� �����:"; cin >> f;
	cout << "������� ������� �����:"; cin >> n ;
	const int z = f;
	switch (n) {
	case 1: cout << f <<" � ������� "<< n << " = " << f << endl; break;
	case 0: cout << f << " � ������� "<< n << " = " << 1 << endl; break;
	}
	// ��� ������� ������������� ������� ������ �� ������ ���������� ���������
	if (n < 0) {
		int i = -2;
		double a;
		while (i >= n)
		{
		i--;
		f = f * z;
		}
		cout << z << " � ������� " << n << " = ";
		a = 1 / f;
		cout << a << endl;
	}

	for (int i = 2;
		i <= n;
		i++)
	{
		cout << z << " � ������� " << i << " = ";
		f = f * z;
		cout << f << endl;
	}
	cout << endl;
#endif 

#ifdef TASK_2
	int simb = 0;
	cout << " ������� ASCII ��������." << endl;
	for ( ;simb < 256; )
	{
		cout << " | " << (char)simb << " | ";
		simb++;
		// ������ ��� ������ � ������, ���������� ������� �� ����� ������ � ������� switch
		switch (simb) {
		case 16: cout << endl;break;
		case 32: cout << endl;break;
		case 48: cout << endl;break;
		case 64: cout << endl;break;
		case 80: cout << endl;break;
		case 96: cout << endl;break;
		case 112: cout << endl;break;
		case 128: cout << endl;break;
		case 144: cout << endl;break;
		case 160: cout << endl;break;
		case 176: cout << endl;break;
		case 192: cout << endl;break;
		case 208: cout << endl;break;
		case 224: cout << endl;break;
		case 240: cout << endl;break;
		case 256: cout << endl;break;
		}
	}
#endif

#ifdef TASK_2V2
	int s = 0;
	cout << " ������� ASCII ��������." << endl;
	while (s < 256) {
		cout << " | " << (char)s << " | ";
		s++;
		if (s % 16 == 0) cout << endl;
	}
#endif

#ifdef TASK_3
	double a =0, b = 1, c;
	cout << "������� ���������� �������� ��� ���� ���������:";cin >> c;
	cout << endl;
	cout << a <<" | " << b <<" | ";
	for ( ;c > a || c > b ; ) {		
		a += b;
		b += a;
		if (c >= a||c >= b) {
			cout << a << " | " << b << " | ";
		}			
	}
#endif
}