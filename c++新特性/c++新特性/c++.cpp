#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include <functional>
using namespace std;
//c++ 11:

class Test {
public:
	//ֱ�ӳ�ʼ��
	int a = 0;
	//ί�й��캯��
	Test(int n) {}
	Test():Test(0){}
};
//ö��
enum Number{One = 1 ,Two,Three};
//ö����:���ⷢ����ʽת����������ָ���ײ���������
enum class Day: char {Mon = 1 ,Tues,Wednes,Thurs,Fri,Satur,Sun};
//auto�Զ������Ƶ�
template <typename A, typename B>
auto add(A x, B y) { return x + y; }
//�������ʽconstexpr
constexpr int Pow(int a ,int b)
{
	for (int i = 0;i < b;i++) {
		a *= a;
	}
	return a;
}
int main() {
	//NULL����ֱ�Ӹ�ֵ������ֵ
	int* i = nullptr;//�Կ�ָ��Ӧ��ʹ��nullptr;
	//ö��
	enum Number num;
	num = Two;
	std::cout << num << "\n";
	//�Զ������Ƶ�
	vector<int> v;
	for (auto it = v.begin();it != v.end();it++) {};
	//�������ʽconstexpr
	int a[Pow(2, 2)];
	//��׼��������ʼ��
	vector<int>test = { 1,2,3,4 };
	//�����㷨�Ż�
	for (auto num : test) {};
	//����ָ�룬��ֹ�ڴ�й¶(����������unique_ptrָ��ͬһ������)
	//���Ҫ����ָ��ָ��ͬһ������ʹ��shared_ptr
	auto p1 = make_unique<Test>();//memoryͷ�ļ�,�������뿪�������ڴ���Զ��ͷ�;
	unique_ptr<Test> p2(new Test);
	//lambda���ʽ��������������
	auto it = find_if(test.begin(), test.end(), [](int x) {return x % 2 == 0;});
	cout << *it << endl;
	//lambda���ʽ�ĵݹ�
	// ���� std::function ���͵ı��������� Lambda ���ʽ
	std::function<int(int)> factorial = [&](int n) -> int {
		if (n <= 1)
			return 1;
		else
			return n * factorial(n - 1);  // �� Lambda �ڲ��ݹ��������
		};

	std::cout << "5! = " << factorial(5) << std::endl;
	return 0;
}