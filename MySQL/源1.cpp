#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main1() {
    try {
        // 创建 MySQL 驱动对象
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::Statement* stat;
        sql::ResultSet* res;
        // 初始化 MySQL 驱动
        driver = sql::mysql::get_driver_instance();
        // 连接到 testdb 数据库，假设用户名为 "root" 和密码为 "password"
        con = driver->connect("tcp://127.0.0.1:3306", "root", "1");
        // 选择 testdb 数据库
        con->setSchema("testdb");
        // 创建 SQL 查询语句
        stat = con->createStatement();
        res = stat->executeQuery("select * from books");
        // 遍历并输出结果
        while (res->next()) {
            std::cout << "book_id:" << res->getInt("book_id") << "\n"
                << "title:" << res->getString("title") << "\n"
                << "author:" << res->getString("author") << "\n"
                << "date:" << res->getString("published_date") << "\n"
                << "----------------------------------------" << "\n"
                << "----------------------------------------" << std::endl;
            
        }
        // 释放资源
        //delete driver;无论你调用多少次这个函数，它都会返回同一个驱动实例；不应该删除，因为它由库内部管理
        delete con;
        delete stat;
        delete res;
        //捕获异常，防止异常崩溃
    }
    catch (sql::SQLException& e) {
        std::cerr << "ERROR" << e.what() << std::endl;
    }
    return 0;
}