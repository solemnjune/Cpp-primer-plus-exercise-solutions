#pragma once

class Customer
{
private:
	long arrive;	// момент появления клиента 
	int processtime; // время обслуживания клиента 
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
//-------------------------------------------------------------------------------------------------
typedef Customer Item;
