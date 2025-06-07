#include <iostream>
#include <memory>

using namespace std;
#if 1
class CPU
{
public:
    virtual void calculate() = 0;
    virtual ~CPU() {}  // ���������������ȷ��ͨ������ָ��ɾ��ʱ��ȷ����
};

class GPU
{
public:
    virtual void display() = 0;
    virtual ~GPU() {}
};

class RAM
{
public:
    virtual void storage() = 0;
    virtual ~RAM() {}
};

class Intel : public CPU, public GPU, public RAM
{
public:
    void calculate() override
    {
        cout << "Intel��cpu��ʼ����" << endl;
    }
    void display() override
    {
        cout << "Intel��gpu��ʼ��ʾ" << endl;
    }
    void storage() override
    {
        cout << "Intel���ڴ濪ʼ�洢" << endl;
    }
};

class AMD : public CPU, public GPU, public RAM
{
public:
    void calculate() override
    {
        cout << "AMD��cpu��ʼ����" << endl;
    }
    void display() override
    {
        cout << "AMD��gpu��ʼ��ʾ" << endl;
    }
    void storage() override
    {
        cout << "AMD���ڴ濪ʼ�洢" << endl;
    }
};

class Computer
{
public:
    // ���캯���������� shared_ptr����������ָ����Թ���ͬһ�����󣨻��߸��Զ�����
    Computer(shared_ptr<CPU> cpu, shared_ptr<GPU> gpu, shared_ptr<RAM> ram)
        : m_cpu(cpu), m_gpu(gpu), m_ram(ram)
    {
    }

    void dowork()
    {
        cout << "���Կ�ʼ������" << endl;
        m_cpu->calculate();
        m_gpu->display();
        m_ram->storage();
    }

private:
    shared_ptr<CPU> m_cpu;
    shared_ptr<GPU> m_gpu;
    shared_ptr<RAM> m_ram;
};

void test()
{
    auto intel = make_shared<Intel>(); // ʹ�� C++11 �� shared_ptr
    Computer computer1(intel, intel, intel);
    computer1.dowork();

    cout << "-----------------" << endl;

    cout << "-----------------" << endl;

    auto amd = make_shared<AMD>();
    Computer computer3(amd, amd, amd);
    computer3.dowork();
}

int main()
{
    test();
    return 0;
}
#endif