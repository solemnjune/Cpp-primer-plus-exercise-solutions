// use_tv.cpp — использование классов Тѵ и Remote 
// компилировать вместе с файлом TvR.cpp

#include "pch.h"
#include <iostream>
#include "TvR.h"

using namespace std;

//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";		// начальные настройки телевизора 42 
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";		// отрегулированные настройки телевизора 42 

	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";	// настройки телевизора 42 после использования пульта 

	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";		// настройки телевизора 58 
	s58.settings();

	cout << "\nShowing remote interaction mode:\n";
	grey.show_interaction();

	s42.set_reminter(grey);
	cout << "Showing changed remote interaction mode:\n";
	grey.show_interaction();

	
	return 0;
}
//-------------------------------------------------------------------------------------------------
