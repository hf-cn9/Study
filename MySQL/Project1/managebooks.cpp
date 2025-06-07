#include<mysql_driver.h>
#include<mysql_connection.h>
#include<cppconn/prepared_statement.h>
#include<cppconn/statement.h>
#include<cppconn/resultset.h>
#include<cppconn/exception.h>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#if 1
void addBook(sql::Connection* con);
void viewBook(sql::Connection* con);
void deleteBook(sql::Connection* con);
void updateBook(sql::Connection* con);

int main() {
	try {
		//��������
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;
		//����ʵ��
		driver = sql::mysql::get_driver_instance();
		//�������ݿ�
		con = driver->connect("tcp://127.0.0.1:3306", "root", "1");
		//�������ݿ�
		con->setSchema("testdb");
		int choice = 0;
		do {
			std::cout << "====ͼ�����ϵͳ====" << std::endl;
			std::cout << "====1 . ���ͼ��====" << std::endl;
			std::cout << "====2 . �鿴ͼ��====" << std::endl;
			std::cout << "====3 . ����ͼ��====" << std::endl;
			std::cout << "====4 . ɾ��ͼ��====" << std::endl;
			std::cout << "====0 . �˳�ϵͳ====" << std::endl;
			std::cin >> choice;
			switch (choice) {
			case 1:
				addBook(con);
				system("pause");
				system("cls");
				break;
			case 2:
				viewBook(con);
				system("pause");
				system("cls");
				break;
			case 3:
				updateBook(con);
				system("pause");
				system("cls");
				break;
			case 4:
				deleteBook(con);
				system("pause");
				system("cls");
				break;
			case 0:
				std::cout << "�˳��ɹ�\n";
				break;
			default:
				std::cout << "�������\n";
				system("pause");
				system("cls");
				break;
			}
		} while (choice);

	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}
	
	return 0;
}
void addBook(sql::Connection* con){
	try {
		std::string title, author, published_date;
		std::cout << "��������\n";
		cin.ignore();
		getline(cin, title);
		std::cout << "��������\n";
		getline(cin, author);
		std::cout << "�����������(YYYY-MM-DD)\n";
		getline(cin, published_date);
		sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO books(title,author,published_date) VALUES (?,?,?)");
		pstmt->setString(1, title);
		pstmt->setString(2, author);
		pstmt->setString(3, published_date);
		pstmt->execute();
		cout << "�鼮��ӳɹ�\n";
		delete pstmt;
	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}
}
void viewBook(sql::Connection* con){
	try {
		sql::Statement* stmt = con->createStatement();
		sql::ResultSet* res = stmt->executeQuery("select * from books");
		cout << left << setfill(' ');
		cout << setw(10) << "���" << setw(10) << "����" << setw(10) << "����" << "��������\n";
		while (res->next()) {
			cout << setw(10)
				<< res->getInt("book_id") << setw(10)
				<< res->getString("title") << setw(10)
				<< res->getString("author")
				<< res->getString("published_date") << "\n";
		}
		delete stmt;
		delete res;
	}
	catch (sql::SQLException& e) {
		cerr << "ERROR��" << e.what() << endl;
	}
}
void deleteBook(sql::Connection* con){
	try {
		int book_id;
		cout << "������Ҫɾ����ͼ����\n";
		cin >> book_id;
		sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM books WHERE book_id = ?");
		pstmt->setInt(1,book_id);
		pstmt->execute();
		cout << "ɾ���ɹ�\n";
		delete pstmt;
	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}

}
void updateBook(sql::Connection* con){
	try {
		int book_id;
		cout << "������Ҫ���µ�ͼ����\n";
		cin >> book_id;

		std::string title, author, published_date;

		std::cout << "��������\n";
		cin.ignore();
		getline(cin, title);

		std::cout << "��������\n";
		getline(cin, author);

		std::cout << "�����������(YYYY-MM-DD)\n";
		getline(cin, published_date);
		 
		sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE books SET title = ?,author = ?, published_date = ?  WHERE book_id = ?");
		pstmt->setString(1, title);
		pstmt->setString(2, author);
		pstmt->setString(3, published_date);
		pstmt->setInt(4, book_id);
		pstmt->execute();
		cout << "�鼮���³ɹ�\n";
		delete pstmt;
	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}
}
#endif 