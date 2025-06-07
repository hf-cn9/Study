#include<iostream>
using namespace std;

//��Ʒ�ӿ�
class Transport {
public:
	virtual ~Transport() {}
	virtual void deliver() const = 0;//const ��ֹ�޸��ڲ���Ա
};
//��ƷA
class Truck:public Transport {
public:
	virtual ~Truck() {}
	void deliver() const override {
		cout << "��������" << endl;
	}
};
//��ƷA
class Ship :public Transport {
public:
	virtual ~Ship() {}
	void deliver() const override {
		cout << "�ִ�����" << endl;
	}
};
//������
class Logistics {
public:
	virtual ~Logistics(){}
	//��������
	virtual Transport* factoryMethod() const = 0;
	void doSometing() {
		Transport* transport = factoryMethod();
		transport->deliver();
		delete transport;
	}
};
//���崴����A
class TruckLogistics : public Logistics {
	virtual ~TruckLogistics() {}
	virtual Transport* factoryMethod() const override{
		return new Truck();
	}
};
//���崴����B
class ShipLogistics : public Logistics {
	virtual ~ShipLogistics() {}
	virtual Transport* factoryMethod() const override {
		return new Ship();
	}
};
int main() {
	Logistics* truckmethod = new TruckLogistics();
	Logistics* shipmethod = new ShipLogistics();
	truckmethod->doSometing();
	shipmethod->doSometing();
	delete truckmethod;
	delete shipmethod;
	return 0;
}