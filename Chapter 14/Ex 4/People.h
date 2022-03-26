#pragma once
#include <string>
#include <iostream>

class Card {
	enum Suits {
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
	enum Ranks {
		ACE,
		TWOc,
		THREEc,
		FOURc,
		FIVEc,
		SIXc,
		SEVENc,
		EIGHTc,
		NINEc,
		TENc,
		JACK,
		QUEEN,
		KING
	};
	Suits CardSuit;
	Ranks CardRank;
public:
	Card();
	friend std::ostream& operator<<(std::ostream &os, const Card & c);
};

class Person {
	std::string fullname;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Person(std::string name = "Empty"):fullname(name){}
	virtual void Show() const;
	virtual void Set();
	virtual ~Person(){}
};


class Gunslinger :virtual public Person {
	int notches;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Gunslinger(std::string name = "Empty", int n= 0)
		:Person(name), notches(n){}
	virtual ~Gunslinger() {}

	double Draw() const;
	virtual void Show() const;
	virtual void Set();
};

class PokerPlayer : virtual public Person {
protected:
	virtual void Data() const;
	virtual void Get(){}
public:
	PokerPlayer(std::string name = "Empty") : Person(name){}
	const Card  Draw() const;
	virtual ~PokerPlayer(){}
	virtual void Show() const;
	virtual void Set();
};

class BadDude : public Gunslinger, public PokerPlayer {
protected:
	 void Data() const{}
	 void Get(){}
public:
	BadDude(std::string name = "Empty", int n = 0):Person(name),Gunslinger(name,n),PokerPlayer(name){}
	void Show() const;
	~BadDude() {}
	double Gdraw() const { PokerPlayer::Draw(); }
	const Card  Cdraw() const { PokerPlayer::Draw(); }
	void Set();
};
