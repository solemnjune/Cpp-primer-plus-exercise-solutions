#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

//-------------------------------------------------------------------------------------------------
class bad_hmean:public std::logic_error
{

public:
	bad_hmean(const std::string what_arg= "Error in hmean: Both values should be equal!\n") :logic_error(what_arg) {}
	//void mesg();
};
//-------------------------------------------------------------------------------------------------
class bad_gmean :public std::logic_error
{
public:
	bad_gmean(const std::string what_arg = "Error in gmean: Both values should be positive!\n") : logic_error(what_arg) {}
	//const char * mesg();
};
//-------------------------------------------------------------------------------------------------
