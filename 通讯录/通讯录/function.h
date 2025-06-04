#include<iostream>
#include<string>

using namespace std;
#define MAX 1000
//创建联系人结构体
struct Person
{
	string name;
	string sex;
	int age = 0;
	string phone;
	string address;
};
struct PersonAddressBook
{
	struct Person personArray[MAX];
	int size = 0;
};

void showMenu();
void addperson(PersonAddressBook* personbook);
void showperson(PersonAddressBook* personbook);
void delectperson(PersonAddressBook* personbook);
void findperson(PersonAddressBook* personbook);
int findperson_1(PersonAddressBook* personbook);
void modifyperson(PersonAddressBook* personbook);
void clearperson(PersonAddressBook* personbook);