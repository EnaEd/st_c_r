#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <exception>
#include <string>

class BaseException : public std::exception {
protected:
    std::string message;
public:
    BaseException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class MathException : public BaseException {
public:
    MathException(const std::string& msg) : BaseException("Math Error: " + msg) {}
};

class OverflowException : public MathException {
public:
    OverflowException() : MathException("Integer overflow") {}
};

class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero") {}
};

class MemoryException : public BaseException {
public:
    MemoryException(const std::string& msg) : BaseException("Memory Error: " + msg) {}
};

class FileException : public BaseException {
public:
    FileException(const std::string& msg) : BaseException("File Error: " + msg) {}
};

class ListException : public BaseException {
public:
    ListException(const std::string& msg) : BaseException("List Error: " + msg) {}
};

class StackException : public BaseException {
public:
    StackException(const std::string& msg) : BaseException("Stack Error: " + msg) {}
};

#endif // CUSTOM_EXCEPTIONS_H
