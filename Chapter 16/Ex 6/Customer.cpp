#include "pch.h"
#include "Customer.h"
#include <cstdlib>

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
//-------------------------------------------------------------------------------------------------