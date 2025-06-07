#include<iostream>
using namespace std;

//产品接口
class Transport {
public:
	virtual ~Transport() {}
	virtual void deliver() const = 0;//const 防止修改内部成员
};
//产品A
class Truck:public Transport {
public:
	virtual ~Truck() {}
	void deliver() const override {
		cout << "卡车运输" << endl;
	}
};
//产品A
class Ship :public Transport {
public:
	virtual ~Ship() {}
	void deliver() const override {
		cout << "轮船运输" << endl;
	}
};
//创造者
class Logistics {
public:
	virtual ~Logistics(){}
	//工厂方法
	virtual Transport* factoryMethod() const = 0;
	void doSometing() {
		Transport* transport = factoryMethod();
		transport->deliver();
		delete transport;
	}
};
//具体创造者A
class TruckLogistics : public Logistics {
	virtual ~TruckLogistics() {}
	virtual Transport* factoryMethod() const override{
		return new Truck();
	}
};
//具体创造者B
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