#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main1() {
    try {
        // ���� MySQL ��������
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::Statement* stat;
        sql::ResultSet* res;
        // ��ʼ�� MySQL ����
        driver = sql::mysql::get_driver_instance();
        // ���ӵ� testdb ���ݿ⣬�����û���Ϊ "root" ������Ϊ "password"
        con = driver->connect("tcp://127.0.0.1:3306", "root", "1");
        // ѡ�� testdb ���ݿ�
        con->setSchema("testdb");
        // ���� SQL ��ѯ���
        stat = con->createStatement();
        res = stat->executeQuery("select * from books");
        // ������������
        while (res->next()) {
            std::cout << "book_id:" << res->getInt("book_id") << "\n"
                << "title:" << res->getString("title") << "\n"
                << "author:" << res->getString("author") << "\n"
                << "date:" << res->getString("published_date") << "\n"
                << "----------------------------------------" << "\n"
                << "----------------------------------------" << std::endl;
            
        }
        // �ͷ���Դ
        //delete driver;��������ö��ٴ���������������᷵��ͬһ������ʵ������Ӧ��ɾ������Ϊ���ɿ��ڲ�����
        delete con;
        delete stat;
        delete res;
        //�����쳣����ֹ�쳣����
    }
    catch (sql::SQLException& e) {
        std::cerr << "ERROR" << e.what() << std::endl;
    }
    return 0;
}