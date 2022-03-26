//tvr.cpp - методы для класса Тѵ (методы Remote являются встроенными) 
#include "pch.h"
#include <iostream>
#include "TvR.h"

//-------------------------------------------------------------------------------------------------
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}
//-------------------------------------------------------------------------------------------------
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
//-------------------------------------------------------------------------------------------------
void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;	// выключен или включен 
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;			// уровень громкости 
		cout << "Channel setting = " << channel << endl;		// номер канала 
		cout << "Mode = "
			<< (mode == Antenna ? "antenna" : "cable") << endl;	// антенна или кабель 
		cout << "Input = "
			<< (input == TV ? "TV" : "DVD") << endl;			// вход: TV или DVD 
	}
}
//-------------------------------------------------------------------------------------------------
void Tv::set_reminter(Remote & r) const {
	if (state == On) {
		r.interactionMode = (r.interactionMode == Remote::Normal) ? Remote::Interactive : Remote::Normal;
	}
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void Remote::show_interaction() {
	std::cout << "Remote interaction mode is "
		<< (interactionMode == Normal ? "normal" : "interactive") << std::endl;
}
//-------------------------------------------------------------------------------------------------
