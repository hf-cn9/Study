#include <iostream>
#include <memory>

using namespace std;
#if 1
class CPU
{
public:
    virtual void calculate() = 0;
    virtual ~CPU() {}  // 添加虚析构函数，确保通过基类指针删除时正确析构
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
        cout << "Intel的cpu开始计算" << endl;
    }
    void display() override
    {
        cout << "Intel的gpu开始显示" << endl;
    }
    void storage() override
    {
        cout << "Intel的内存开始存储" << endl;
    }
};

class AMD : public CPU, public GPU, public RAM
{
public:
    void calculate() override
    {
        cout << "AMD的cpu开始计算" << endl;
    }
    void display() override
    {
        cout << "AMD的gpu开始显示" << endl;
    }
    void storage() override
    {
        cout << "AMD的内存开始存储" << endl;
    }
};

class Computer
{
public:
    // 构造函数接受三个 shared_ptr，这样三个指针可以共享同一个对象（或者各自独立）
    Computer(shared_ptr<CPU> cpu, shared_ptr<GPU> gpu, shared_ptr<RAM> ram)
        : m_cpu(cpu), m_gpu(gpu), m_ram(ram)
    {
    }

    void dowork()
    {
        cout << "电脑开始工作了" << endl;
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
    auto intel = make_shared<Intel>(); // 使用 C++11 的 shared_ptr
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