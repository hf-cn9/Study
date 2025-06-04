#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include <functional>
using namespace std;
//c++ 11:

class Test {
public:
	//直接初始化
	int a = 0;
	//委托构造函数
	Test(int n) {}
	Test():Test(0){}
};
//枚举
enum Number{One = 1 ,Two,Three};
//枚举类:避免发生隐式转换，它允许指定底层数据类型
enum class Day: char {Mon = 1 ,Tues,Wednes,Thurs,Fri,Satur,Sun};
//auto自动类型推导
template <typename A, typename B>
auto add(A x, B y) { return x + y; }
//常量表达式constexpr
constexpr int Pow(int a ,int b)
{
	for (int i = 0;i < b;i++) {
		a *= a;
	}
	return a;
}
int main() {
	//NULL可以直接赋值给其他值
	int* i = nullptr;//对空指针应该使用nullptr;
	//枚举
	enum Number num;
	num = Two;
	std::cout << num << "\n";
	//自动类型推导
	vector<int> v;
	for (auto it = v.begin();it != v.end();it++) {};
	//常量表达式constexpr
	int a[Pow(2, 2)];
	//标准库容器初始化
	vector<int>test = { 1,2,3,4 };
	//遍历算法优化
	for (auto num : test) {};
	//智能指针，防止内存泄露(不会有两个unique_ptr指向同一个对象)
	//如果要求多个指针指向同一对象，则使用shared_ptr
	auto p1 = make_unique<Test>();//memory头文件,当程序离开作用域，内存会自动释放;
	unique_ptr<Test> p2(new Test);
	//lambda表达式，构造匿名函数
	auto it = find_if(test.begin(), test.end(), [](int x) {return x % 2 == 0;});
	cout << *it << endl;
	//lambda表达式的递归
	// 定义 std::function 类型的变量，保存 Lambda 表达式
	std::function<int(int)> factorial = [&](int n) -> int {
		if (n <= 1)
			return 1;
		else
			return n * factorial(n - 1);  // 在 Lambda 内部递归调用自身
		};

	std::cout << "5! = " << factorial(5) << std::endl;
	return 0;
}