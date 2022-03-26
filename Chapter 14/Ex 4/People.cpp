#include "pch.h"
#include "People.h"
//----------------------------------------------------------------------------------------------------------------------------
//методы Card
//----------------------------------------------------------------------------------------------------------------------------

Card::Card() {
	CardSuit = static_cast<Suits> (std::rand() % 4);
	CardRank = static_cast<Ranks> (std::rand() % 13);
}
//----------------------------------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &os, const Card &c) {
	os << "Card suit: ";
	switch (c.CardSuit) {
	case Card::CLUBS:
		os << "Clubs";
		break;
	case Card::DIAMONDS:
		os << "Diamonds";
		break;
	case Card::HEARTS:
		os << "Hearts";
		break;
	case Card::SPADES:
		os << "Spades";
		break;
	default:
		os << "SUIT ERROR";
		break;
	}
	os << '\t' << "Card rank: ";
	switch (c.CardRank) {
	case Card::ACE:
		os << "Ace";
		break;
	case Card::TWOc:
		os << "Two";
		break;
	case Card::THREEc:
		os << "Three";
		break;
	case Card::FOURc:
		os << "Four";
		break;
	case Card::FIVEc:
		os << "Five";
		break;
	case Card::SIXc:
		os << "Six";
		break;
	case Card::SEVENc:
		os << "Seven";
		break;
	case Card::EIGHTc:
		os << "Eight";
		break;
	case Card::NINEc:
		os << "Nine";
		break;
	case Card::TENc:
		os << "Ten";
		break;
	case Card::JACK:
		os << "Jack";
		break;
	case Card::QUEEN:
		os << "Queen";
		break;
	case Card::KING:
		os << "King";
		break;
	default:
		os << "RANK ERROR";
		break;
	}
	return os;
 }
//----------------------------------------------------------------------------------------------------------------------------
//методы Person
//----------------------------------------------------------------------------------------------------------------------------

void Person::Data() const {
	std::cout << "Name: " << fullname << std::endl;
}
//----------------------------------------------------------------------------------------------------------------------------
void Person::Show() const {
	std::cout << "Person's info: " << std::endl;
	Data();
}
//----------------------------------------------------------------------------------------------------------------------------
void Person::Get() {
	std::getline(std::cin, fullname);
}
//----------------------------------------------------------------------------------------------------------------------------
void Person::Set() {
	std::cout << "Enter Person's name: ";
	Get();
}
//----------------------------------------------------------------------------------------------------------------------------
//методы Gunslinger
//----------------------------------------------------------------------------------------------------------------------------
void Gunslinger::Data() const {
	std::cout << "Notches: " << notches<<std::endl;
	std::cout << "Weapon draw time: " << Draw() << std::endl;
}
//----------------------------------------------------------------------------------------------------------------------------
double Gunslinger::Draw() const {
	return 5.0 / notches;
}
//----------------------------------------------------------------------------------------------------------------------------
void Gunslinger::Show() const {
	std::cout << "Gunslinger's info: " << std::endl;
	Person::Data();
	Data();
}
//----------------------------------------------------------------------------------------------------------------------------
void Gunslinger::Get() {
	std::cin >> notches;
	std::cin.get();
}
//----------------------------------------------------------------------------------------------------------------------------
void Gunslinger::Set() {
	std::cout << "Enter Gunslinger's name: ";
	Person::Get();
	std::cout << "Enter Gunslinger's notches: ";
	Get();
}
//----------------------------------------------------------------------------------------------------------------------------
//методы PokerPlayer
//----------------------------------------------------------------------------------------------------------------------------
void PokerPlayer::Data() const {
	std::cout << "Last card: " << Draw() << std::endl;
}
//----------------------------------------------------------------------------------------------------------------------------
const Card  PokerPlayer::Draw() const {
	Card lastCard;
	return lastCard;
}
//----------------------------------------------------------------------------------------------------------------------------
void PokerPlayer::Show() const {
	std::cout << "Poker player's info: " << std::endl;
	Person::Data();
	Data();
}
//----------------------------------------------------------------------------------------------------------------------------
void PokerPlayer::Set() {
	std::cout << "Enter Poker player's name: ";
	Person::Get();;
}
//----------------------------------------------------------------------------------------------------------------------------
//методы BadDude
//----------------------------------------------------------------------------------------------------------------------------

void BadDude::Show() const {
	std::cout << "Bad dude's info: " << std::endl;
	Person::Data();
	Gunslinger::Data();
	PokerPlayer::Data();
}
//----------------------------------------------------------------------------------------------------------------------------
void BadDude::Set() {
	std::cout << "Enter Bad dude's name: ";
	Person::Get();
	std::cout << "Enter Bad dude's notches: ";
	Gunslinger::Get();
}
