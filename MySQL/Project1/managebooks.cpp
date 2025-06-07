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
		//创建驱动
		sql::mysql::MySQL_Driver* driver;
		sql::Connection* con;
		//创建实例
		driver = sql::mysql::get_driver_instance();
		//连接数据库
		con = driver->connect("tcp://127.0.0.1:3306", "root", "1");
		//操纵数据库
		con->setSchema("testdb");
		int choice = 0;
		do {
			std::cout << "====图书管理系统====" << std::endl;
			std::cout << "====1 . 添加图书====" << std::endl;
			std::cout << "====2 . 查看图书====" << std::endl;
			std::cout << "====3 . 更新图书====" << std::endl;
			std::cout << "====4 . 删除图书====" << std::endl;
			std::cout << "====0 . 退出系统====" << std::endl;
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
				std::cout << "退出成功\n";
				break;
			default:
				std::cout << "输入错误\n";
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
		std::cout << "输入书名\n";
		cin.ignore();
		getline(cin, title);
		std::cout << "输入作者\n";
		getline(cin, author);
		std::cout << "输入出版日期(YYYY-MM-DD)\n";
		getline(cin, published_date);
		sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO books(title,author,published_date) VALUES (?,?,?)");
		pstmt->setString(1, title);
		pstmt->setString(2, author);
		pstmt->setString(3, published_date);
		pstmt->execute();
		cout << "书籍添加成功\n";
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
		cout << setw(10) << "编号" << setw(10) << "标题" << setw(10) << "作者" << "出版日期\n";
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
		cerr << "ERROR：" << e.what() << endl;
	}
}
void deleteBook(sql::Connection* con){
	try {
		int book_id;
		cout << "输入你要删除的图书编号\n";
		cin >> book_id;
		sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM books WHERE book_id = ?");
		pstmt->setInt(1,book_id);
		pstmt->execute();
		cout << "删除成功\n";
		delete pstmt;
	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}

}
void updateBook(sql::Connection* con){
	try {
		int book_id;
		cout << "输入你要更新的图书编号\n";
		cin >> book_id;

		std::string title, author, published_date;

		std::cout << "输入书名\n";
		cin.ignore();
		getline(cin, title);

		std::cout << "输入作者\n";
		getline(cin, author);

		std::cout << "输入出版日期(YYYY-MM-DD)\n";
		getline(cin, published_date);
		 
		sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE books SET title = ?,author = ?, published_date = ?  WHERE book_id = ?");
		pstmt->setString(1, title);
		pstmt->setString(2, author);
		pstmt->setString(3, published_date);
		pstmt->setInt(4, book_id);
		pstmt->execute();
		cout << "书籍更新成功\n";
		delete pstmt;
	}
	catch (sql::SQLException& e) {
		std::cerr << "ERROR:" << e.what() << std::endl;
	}
}
#endif 