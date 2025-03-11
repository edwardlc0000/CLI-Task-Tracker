#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using std::string;
using std::exception;

class task_list_full : public exception {
public:
    task_list_full(const string& message) : msg_(message) {}
    virtual const char* what() const noexcept override
    {
        return msg_.c_str();
    }
private:
    string msg_;
};

class task_not_found : public exception {
public:
    task_not_found(const string& message) : msg_(message) {}
    virtual const char* what() const noexcept override
    {
        return msg_.c_str();
    }
private:
    string msg_;
};

#endif // EXCEPTIONS_H
