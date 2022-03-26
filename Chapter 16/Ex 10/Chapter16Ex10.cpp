#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//-------------------------------------------------------------------------------------------------
struct Review {
	std::string title;
	int rating;
	double price;
};
//-------------------------------------------------------------------------------------------------
bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(shared_ptr<Review> & rr);
void ShowReview(const shared_ptr<Review> & rr);
//-------------------------------------------------------------------------------------------------
int main()
{

	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " books:\n";
		char ch;
		vector<shared_ptr<Review>> booksSorted = books;
		cout << "Please, select preferable way to display the list of books:\n";
		cout << "a. original order" << '\t' << "b. alphabetical order\n";
		cout << "c. sorted by rating(increasing)" << '\t' << "d.sorted by rating(decreasing)\n";
		cout << "e. sorted by price(increasing)" << '\t' << "f.sorted by price(decreasing)\n";
		cout << "q. quit\n";
		while (cin >> ch && ch != 'q') {
			switch (ch)
			{
			case 'a':
				cout << "Books in original order: \n";
				cout <<"Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case 'b':
				cout << "Books in alphabetical order: \n";
				cout << "Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				sort(booksSorted.begin(), booksSorted.end());
				for_each(booksSorted.begin(), booksSorted.end(), ShowReview);
				break;
			case 'c':
				cout << "Books sorted by rating(increasing): \n";
				cout << "Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				sort(booksSorted.begin(), booksSorted.end(), worseThan);
				for_each(booksSorted.begin(), booksSorted.end(), ShowReview);
				break;
			case 'd':
				cout << "Books sorted by rating(decreasing): \n";
				cout << "Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				sort(booksSorted.rbegin(), booksSorted.rend(), worseThan);
				for_each(booksSorted.begin(), booksSorted.end(), ShowReview);
				break;
			case 'e':
				cout << "Books sorted by price(increasing): \n";
				cout << "Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				sort(booksSorted.begin(), booksSorted.end(), cheaperThan);
				for_each(booksSorted.begin(), booksSorted.end(), ShowReview);
				break;
			case 'f':
				cout << "Books sorted by price(decreasing): \n";
				cout << "Rating" << "\t" << "Price" << "\t" << "Title" << endl;
				sort(booksSorted.rbegin(), booksSorted.rend(), cheaperThan);
				for_each(booksSorted.begin(), booksSorted.end(), ShowReview);
				break;
			case 'q':
				break;
			default:
				cout << "Wrong choice, try again\n";
				break;
			}
			if (ch == 'q') {
				break;
			}
			cout << endl;

			
			cout << "Please, select preferable way to display the list of books:\n";
			cout << "a. original order" << '\t' << "b. alphabetical order\n";
			cout << "c. sorted by rating(increasing)" << '\t' << "d.sorted by rating(decreasing)\n";
			cout << "e. sorted by price(increasing)" << '\t' << "f.sorted by price(decreasing)\n";
			cout << "q. quit\n";
		}
	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";

	
	return 0;
}
//-------------------------------------------------------------------------------------------------
bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------

bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
bool FillReview(shared_ptr<Review> & rr)
{
	rr = shared_ptr<Review>(new Review);
	cout << "Enter book title (quit to quit): ";
	std::getline(cin, rr->title);
	if (rr->title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr->rating;
	if (!std::cin)
		return false;
	cout << "Enter book price: ";
	cin >> rr->price;
	if (!cin)
		return false;
	// Избавиться от остальной части строки ввода 
	while (cin.get() != '\n')
		continue;
	return true;
}
//-------------------------------------------------------------------------------------------------
void ShowReview(const shared_ptr<Review> & rr)
{
	cout << rr->rating << "\t" << rr->price << "\t" << rr->title  <<endl;
}
//-------------------------------------------------------------------------------------------------
