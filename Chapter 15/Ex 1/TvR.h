//tvr.h -- классы Тѵ и Remote и дружественная функция-член 
#pragma once
//-------------------------------------------------------------------------------------------------
class Remote;
//-------------------------------------------------------------------------------------------------
class Tv
{
public:
	friend class Remote;   // Remote имеет доступ к закрытой части Тѵ 
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const; // display all settings
	void set_reminter(Remote & r) const;
private:
	int state;             // On или Off 
	int volume;            // дискретные уровни громкости 
	int maxchannel;        // максимальное количество каналов 
	int channel;           // текущие настройки канала
	int mode;              // эфирное или кабельное телевидение 
	int input;             // TV или DVD 
};
//-------------------------------------------------------------------------------------------------
class Remote
{
private:
	int mode;              // управление TV или DVD 
	int interactionMode; //режим управление Normal или Interactive 
public:
	friend class Tv;  
	enum { Normal, Interactive };


	Remote(int m = Tv::TV, int inter = Normal) : mode(m),interactionMode(inter) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
	void show_interaction();
};
//------------------------------------------------------------------------------------------------
