#include"MyArry.hpp"

void test1()
{
	MyArry<Person> p(10);
	p.Push_Back({ "张三",14 });
	p.Push_Back({ "李四",15 });
	p.Push_Back({ "王五",16 });
	p.Push_Back({ "赵钱",17 });
	p.Push_Back({ "孙子",18 });
	printMyArray(p);
	cout << p.get_capacity() << endl;
	cout << p.get_size() << endl;
	
}
int main()
{
	test1();

	system("pause");
	return 0;
}