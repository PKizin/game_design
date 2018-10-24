#ifndef PG_TESTER_HPP
#define PG_TESTER_HPP

#include "libpq-fe.h"
#include <string>


class PGtester {
public:
    PGtester(const std::string& dbname, const std::string& user, const std::string& password);
    ~PGtester();

    void test();

private:
    PGtester();
    PGtester(const PGtester&);
    PGtester& operator=(const PGtester&);
    PGtester& operator=(const PGtester&) const;

    void connect();
    void create_table();
    void insert_value();
    void disconnect();

    PGconn* _conn = nullptr;
    PGresult* _res = nullptr;
    
    std::string _conninfo;
    std::string _dbname;
    std::string _user;
    std::string _password;
    std::string _query;
};


#endif // PG_TESTER_HPP
