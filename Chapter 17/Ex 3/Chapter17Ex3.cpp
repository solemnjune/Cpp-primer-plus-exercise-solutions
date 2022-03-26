#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	using namespace std;

	char ch;
	ifstream fin;
	ofstream fout;
	
	fin.open(argv[1]);
	fout.open(argv[2]);
	if (!fin.is_open()) {
		cout << "Could not open " << argv[1] << ". Closing";
		exit(EXIT_FAILURE);
	}
	else if (!fout.is_open()) {
		cout << "Could not open " << argv[2] << ". Closing";
		exit(EXIT_FAILURE);
	}
	while (fin.get(ch)) {
		fout.put(ch);
	}
}
