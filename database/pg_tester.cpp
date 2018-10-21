#include <iostream>
#include "pg_tester.hpp"
#include "randomizer.hpp"



PGtester::PGtester(const std::string& dbname, const std::string& user, const std::string& password) :
    _dbname(dbname),
    _user(user),
    _password(password)
{
}

PGtester::~PGtester() 
{
}


void PGtester::test() {
    connect();

    std::cout << "Do you want to create new table? (y/n) ";
    char ans;
    std::cin >> ans;

    if (ans == 'y')
        create_table();

    std::cout << "Do you want to add data? (y/n) ";
    std::cin >> ans;

    if (ans == 'y')
        insert_value();

    disconnect();
}


void PGtester::connect() {
    _conninfo = std::string("dbname=") + _dbname + 
                std::string(" user=") + _user + 
                std::string(" password=") + _password;
    
    _conn = PQconnectdb(_conninfo.c_str());

    if (PQstatus(_conn) == CONNECTION_OK) {
        std::cout << std::endl;
        std::cout << "Connect to" << std::endl;
        std::cout << "host     = " << PQhost(_conn) << std::endl;
        std::cout << "port     = " << PQport(_conn) << std::endl;
        std::cout << "db       = " << PQdb(_conn) << std::endl;
        std::cout << "user     = " << PQuser(_conn) << std::endl;
        std::cout << "pass     = " << PQpass(_conn) << std::endl;
        std::cout << "encoding = " << PQclientEncoding(_conn) << std::endl;
        std::cout << std::endl;
    }
}

void PGtester::create_table() {
    _query = "CREATE TABLE test_table(id bigserial primary key, descr varchar(50) NOT NULL)";
    _res = PQprepare(_conn, "new_table", _query.c_str(), 0, NULL);
    std::cout << "PQprepare result = " << PQresultStatus(_res) << std::endl;
    std::cout << "PQprepare error  = " << PQresultErrorMessage(_res) << std::endl;

    if (PQresultStatus(_res) == PGRES_COMMAND_OK) {
        PQclear(_res);
        _res = PQexecPrepared(_conn, "new_table", 0, NULL, NULL, NULL, 0);
        std::cout << "PQexecPrepared result = " << PQresultStatus(_res) << std::endl;
        std::cout << "PQexecPrepared error  = " << PQresultErrorMessage(_res) << std::endl;
        PQclear(_res);
    }
}

void PGtester::insert_value() {
    _query = std::string("INSERT INTO test_table VALUES ($1, $2)");
    _res = PQprepare(_conn, "add_value", _query.c_str(), 2, NULL);
    std::cout << "PQprepare result = " << PQresultStatus(_res) << std::endl;
    std::cout << "PQprepare error  = " << PQresultErrorMessage(_res) << std::endl;

    if (PQresultStatus(_res) == PGRES_COMMAND_OK) {
        PQclear(_res);
        const char* vals[2];
        vals[0] = "102";
        vals[1] = Randomizer::timestamp().c_str();
        int lens[2];
        lens[0] = std::string(vals[0]).length();
        lens[1] = std::string(vals[1]).length();
        int forms[2];
        forms[0] = 0;
        forms[1] = 0;
        _res = PQexecPrepared(_conn, "add_value", 2, vals, lens, forms, 0);
        std::cout << "PQexecPrepared result = " << PQresultStatus(_res) << std::endl;
        std::cout << "PQexecPrepared error  = " << PQresultErrorMessage(_res) << std::endl;
        PQclear(_res);
    }
}

void PGtester::disconnect() {
    PQfinish(_conn);
}

