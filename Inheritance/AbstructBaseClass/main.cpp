#include<iostream>
using namespace std;

class Vehicle
{
protected:
	int speed;
public:
	virtual void move() = 0;
};

class GroundVehicle : public Vehicle{};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� ������� �������(��� �������)" << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "�������� ���� �� ���� �������!!!" << endl;
	}
};

class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
};

class Helicopter :public AirVehicle
{
public:
	void move() { cout << "�������� ����� �� �����!!!)))" << endl; }
	void take_off() { cout << "������������ �����!!!" << endl; }
};

int main()
{
	setlocale(LC_ALL, "RU");
	//Vehicle v; // ���������� ������� ��������� ������������ ������
	//GroundVehicle GV; // 
	Car bmv;
	Bike harley;
	bmv.move();
	harley.move();
	Helicopter LCPDCopter;
	LCPDCopter.take_off();
	LCPDCopter.move();


	return 0;	
}