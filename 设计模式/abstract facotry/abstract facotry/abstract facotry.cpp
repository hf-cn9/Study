#include <iostream>

using namespace std;


class Chair {//产品
public:
    virtual ~Chair() {}
    virtual void chair_uesd() = 0;
};
class ModernChair : public Chair {
public:
    virtual ~ModernChair() {}
    virtual void chair_uesd() override{
        cout << "ModernChair is used" << endl;
    }
};
class OldChair : public Chair {
public:
    virtual ~OldChair() {}
    virtual void chair_uesd() override{
        cout << "OldChair is used" << endl;
    }
};
class Desktop {//产品
public:
    virtual ~Desktop() {}
    virtual void Desktop_uesd() = 0;
};
class ModernDesktop : public Desktop {
public:
    virtual ~ModernDesktop() {}
    virtual void Desktop_uesd() override {
        cout << "ModernDesktop is used" << endl;
    }
};
class OldDesktop : public Desktop {
public:
    virtual ~OldDesktop() {}
    virtual void Desktop_uesd() override {
        cout << "OldDesktop is used" << endl;
    }
};
class Furniture_Factory {//抽象工厂
public:
    virtual ~Furniture_Factory() {}
    virtual Chair* Chair_created() = 0;
    virtual Desktop* Desktop_created() = 0;

};
class ModernFurniture:public Furniture_Factory {//产品组A
public:
    virtual ~ModernFurniture(){}
    virtual Chair* Chair_created() override{
        return new ModernChair();
    }
    virtual Desktop* Desktop_created() override{
        return new ModernDesktop();
    }
};
class OldFurniture :public Furniture_Factory {//产品组B
public:
    virtual ~OldFurniture() {}
    virtual Chair* Chair_created() {
        return new OldChair();
    }
    virtual Desktop* Desktop_created() {
        return new OldDesktop();
    }
};
class Clint {
private:
    Furniture_Factory* m_factory = nullptr;
public:
    Clint(Furniture_Factory* factory) {
        setStyle(factory);
    }
    virtual ~Clint(){}
    void buyFurniture() {
        Chair* chair = m_factory->Chair_created();
        Desktop* desktop = m_factory->Desktop_created();
        chair->chair_uesd();
        desktop->Desktop_uesd();
    }
    void setStyle(Furniture_Factory* factory) {
        m_factory = factory;
    }
};
int main()
{
    Furniture_Factory* modern = new ModernFurniture();
    Furniture_Factory* old = new OldFurniture();
    Clint clint(modern);
    clint.buyFurniture();
    clint.setStyle(old);
    clint.buyFurniture();
    delete modern;
    delete old;
    return 0;
}

