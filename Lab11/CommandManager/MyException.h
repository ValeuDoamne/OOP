#pragma once

#include <exception>
#include <string>

class MyException: public std::exception
{
	std::string error;
public:
	MyException(): error("") { } 
	MyException(std::string err): error(err) { } 
	virtual const char* what() const throw () { return error.c_str(); }
	void SetError(std::string err)
	{
		error = err;
	}
};

class OpenFileException: public MyException
{

public:
	OpenFileException(std::string fileName)
	{
		this->MyException::SetError("Can't open this file " + fileName);
	}
};

class ReadFileException: public MyException
{

public:
	ReadFileException(std::string fileName)
	{
		this->MyException::SetError("Can't read file " + fileName);
	}
};

class WriteFileException: public MyException
{

public:
	WriteFileException(std::string fileName)
	{
		this->MyException::SetError("Can't write file " + fileName);
	}
};
