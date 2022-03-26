#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

void ShowStr(const std::string &s);

class Store {
	std::ofstream* os;
public:
	Store(std::ofstream& fout): os(&fout) {}
	void operator() (const std::string& s) {
		size_t len = s.size();
		os->write((char*)&len, sizeof size_t); // сохранить длину
		os->write(s.data(), len); // сохранить символы
	}
};

void GetStrs(std::ifstream &fin, std::vector<std::string> &s);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	// Получить строки
	cout << "Enter strings (empty line to quit) :\n"; // запрос на ввод строк
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input. \n"; // вывод введенных строк 
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// Сохранить в файле 
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// Восстановить содержимое файла 
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input. \n";
		//не удается открыть файл для ввода
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	// строки, прочитанные из файла
	for_each(vistr.begin(), vistr.end(), ShowStr);
	return 0;
}

void ShowStr(const std::string& s) {
	std::cout << s << std::endl;
}


void GetStrs(std::ifstream& fin, std::vector<std::string> &s) {
	size_t len = 0;
	std::string temp;
	char ch;
	while (fin.peek() && !fin.eof()) {
		fin.read((char*)&len, sizeof (size_t));
		for (size_t i = 0; i < len; i++) {
			fin.read(&ch, sizeof(char));
			temp.push_back(ch);
		}
		s.push_back(temp);
		temp.clear();
	}
	
	fin.clear();

}
