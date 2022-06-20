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
		cout << "Машина едет на четырех колесах(как минимум)" << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Мотоцикл едет на двух колесах!!!" << endl;
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
	void move() { cout << "Верталет летит ОТ ВИНТА!!!)))" << endl; }
	void take_off() { cout << "Вертикальный взлет!!!" << endl; }
};

int main()
{
	setlocale(LC_ALL, "RU");
	//Vehicle v; // Невозможно создать экземпляр абстрактного класса
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