#include<iostream>
using namespace std;


#if 1
//����һ����������:
class Cube
{
public:
	//д��Ȩ��
	void set_length(double len)
	{
		length = len;
	}
	void set_width(double wid)
	{
		width = wid;
	}
	void set_height(double high)
	{
		height = high;
	}
	//��ȡȨ��
	double get_length()
	{
		return length;
	}
	double get_width()
	{
		return width;
	}
	double get_height()
	{
		return height;
	}
private:
	double length;
	double width;
	double height;
public:
	//��ȡ������������
	double getVolume()
	{
		return length * width * height;
	}
	//��ȡ������ı����:
	double getArea()
	{
		return 2 * (length * width + length * height + width * height);
	}
	bool isEqual(Cube& other)
	{
		if (length == other.length && width == other.width && height == other.height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//ȫ�ֺ����ж������������Ƿ���ȣ�
bool global_isEqual(Cube& other, Cube& other2)
{ 
	if (other.get_length() == other2.get_length() && 
		other.get_width() == other2.get_width() && 
		other.get_height() == other2.get_height())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Cube cube1;
	cube1.set_length(10);
	cube1.set_width(20);
	cube1.set_height(30);
	Cube cube2;
	cube2.set_length(10);
	cube2.set_width(20);
	cube2.set_height(40);
	cout<<cube1.getArea()<<endl;
	cout<<cube1.getVolume()<<endl;
	cout<<cube2.getArea()<<endl;
	cout<<cube2.getVolume()<<endl;
	if (cube1.isEqual(cube2))
	{
		cout << "�������������" << endl;
	}
	else
	{
		cout << "���������岻���" << endl;
	}
	if (global_isEqual(cube1, cube2))
	{
		cout << "�������������" << endl;
	}
	else
	{
		cout << "���������岻���" << endl;
	}

	system("pause");
	return 0;
}
#endif