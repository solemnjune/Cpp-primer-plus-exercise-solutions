//------------------------------------------------------------------------------------------------------------------------------------------------
// Методы Wine
//------------------------------------------------------------------------------------------------------------------------------------------------
// Инициализация label значением l, количество лет - у,
  // годы урожая - yr[], количество бутылок - bot[]
Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:std::string(l), years(y) {
	PairArray::operator = (PairArray(ArrayInt(yr, y), ArrayInt(bot, y)));


}


//------------------------------------------------------------------------------------------------------------------------------------------------
void Wine::GetBottles() {
	PairArray::operator = (PairArray(ArrayInt(years), ArrayInt(years)));
	int temp;
	std::cout << "Enter " << Label() << " data for " << years << " year(s): " << std::endl;
	for (int i = 0; i < years; i++) {
		std::cout << "Enter year: ";
		std::cin >> temp;
		PairArray::first()[i] = temp;
		std::cout << "Enter bottles for that year: ";
		std::cin >> temp;
		PairArray::second()[i] = temp;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------
int Wine::sum() const {
	return (PairArray::second()).sum();
}

//------------------------------------------------------------------------------------------------------------------------------------------------
void Wine::Show()  {
	using std::cout;
	using std::endl;
	cout << "Wine: " << Label() << endl;
	cout << '\t' << "Year" << '\t' << "Bottles" << endl;
	for (int i = 0; i < years; i++) {
		cout << '\t' << PairArray::first()[i] << '\t' << PairArray::second()[i] << endl;
	}

}
