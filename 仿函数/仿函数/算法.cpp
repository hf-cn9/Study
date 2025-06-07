#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#if 0
using namespace std;
//for_each(迭代器，迭代器，函数或仿函数)用于遍历
void print01(int v)
{
	cout << v << " ";
}
class print02
{
public:
	void operator()(int v)
	{
		cout << v << " ";
	}
};
void MyPrint(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test41()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	for_each(v1.begin(), v1.end(), print01);//传递一个函数名
	for_each(v1.begin(), v1.end(), print02());//传递一个对象
}
//transform(迭代器，迭代器，函数或仿函数)搬运容器到另一个容器
int func1(int v)
{
	return v;
}
void test42()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(40);
	vector<int>v2;
	v2.resize(v1.size());//reserve是容器预留空间，但并不真正创建元素对象
						 //resize是改变容器的大小，并且创建对象，所以应该用resize
	transform(v1.begin(), v1.end(), v2.begin(), func1);
	for_each(v2.begin(), v2.end(), print01);
}
//查找算法
class find1//谓词
{
public:
	bool operator()(int val)
	{
		return val > 10;
	}
};
void test43()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	// find查找,找到返回对应迭代器，没找到返回end();
	// 自定义类型需要重载返回bool的==号，用于告诉底层代码如何判断
	vector<int>::iterator it = find(v1.begin(), v1.end(), 10);
	cout << *it << endl;
	// find_if查找,条件查找，找到返回对应迭代器，没找到返回end()，第三个参数需要一个谓词
	it = find_if(v1.begin(), v1.end(), find1());
	cout << *it << endl;
	// adjacent_find,查找相邻重复元素，找到返回相邻重复的第一个元素的迭代器，没找到返回end；
	it = adjacent_find(v1.begin(), v1.end());
	cout << *it << endl;
	// binary_search,二分查找法，是否存在这个元素，返回bool，不能用于查找无序的序列
	bool ret = binary_search(v1.begin(), v1.end(), 20);
	if (ret)
	{
		cout << "ok!" << endl;
	}
	// count统计元素个数
	// 自定义类型需要重载返回bool的==号，用于告诉底层代码如何判断
	int num = count(v1.begin(), v1.end(), 10);
	cout << num << endl;
	// count_if按条件查找符合要求的元素的个数
	// 需要一个谓词
	num = count_if(v1.begin(), v1.end(), find1());
	cout << num << endl;
}
//排序
void test44()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	//random_shuffle 打乱元素，使得整个元素乱序
	random_shuffle(v1.begin(), v1.end());
	MyPrint(v1);
	//sort 对元素排序,最后元素不填默认升序，填的话需要填一个谓词
	sort(v1.begin(), v1.end());
	MyPrint(v1);
	//merge 将两个有序的序列合并成一个有序的序列,必须是同序（即同为升序或降序）
	vector<int>v2;
	vector<int>targe1;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), func1);
	targe1.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(),targe1.begin());
	MyPrint(targe1);
	//reverse 反转整个容器，实现逆序（非排序）
	reverse(v1.begin(), v1.end());
	MyPrint(v1);
}
//拷贝和替换
void test45()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int>v2;
	v2.resize(v1.size());//提前开辟空间
	//copy 复制
	copy(v1.begin(), v1.end(), v2.begin());
	MyPrint(v2);
	//replace 替换旧元素为新元素
	replace(v1.begin(), v1.end(), 10, 30);//所有的10换成30（没找到不会替换，也不会报错）
	MyPrint(v1);
	//replace_if 满足条件的元素换成新元素
	replace_if(v1.begin(), v1.end(), find1(), 10);//所有大于10的都换成10;
	MyPrint(v1);
	//swap 互换两个容器(同类型才可以)
	swap(v1, v2);
	MyPrint(v1);
}
//常用算术生成算法(numeric里的算法)
void test46()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	//accumulate 计算累加和(第三个参数是启始累加值)
	int num = accumulate(v1.begin(), v1.end(), 0);
	cout << num << endl;
	//fill 将指定区域内的元素，填充为指定数据
	fill(v1.begin(), v1.end(), 10);
	MyPrint(v1);
}
//常用集合算法
void test47()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	vector<int>v2;
	vector<int>v3;
	v2.push_back(20);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	//三目运算取最小
	v3.resize((v2.size() > v1.size() ? v1.size() : v2.size()));
	//min算法取最小
	v3.resize(min(v1.size(), v2.size()));
	//set_intersection 获取两个集合的交集,返回一个迭代器
	//必须是有序序列
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),v3.begin());
	//遍历时，结束的迭代器使用获取的迭代器，因为开辟空间时，有可能存在未被使用而填充为0的空间
	for_each(v3.begin(), itend, print01);
	cout << endl;
	// set_union 获取两个集合的并集，返回一个迭代器
	// 必须是有序序列
	v3.clear();
	v3.resize(v1.size() + v2.size());
	itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itend, print01);
	cout << endl;
	// set_difference 获取两个集合的差集,返回一个迭代器
	// 必须是有序序列
	v3.clear();
	v3.resize(v1.size());
	itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());//v1 - v2（差集）
	for_each(v3.begin(), itend, print01);
	cout << endl;
}
int main()
{
	srand((unsigned int)time(NULL));
	test47();
	system("pause");
	return 0;
}
#endif