#include"MyArry.hpp"

void test1()
{
	MyArry<Person> p(10);
	p.Push_Back({ "����",14 });
	p.Push_Back({ "����",15 });
	p.Push_Back({ "����",16 });
	p.Push_Back({ "��Ǯ",17 });
	p.Push_Back({ "����",18 });
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