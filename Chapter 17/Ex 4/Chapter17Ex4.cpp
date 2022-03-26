#include <iostream>
#include <fstream>
const int stringMax = 1000;
int main()
{
    std::ifstream finOne;
    std::ifstream finTwo;
    std::ofstream fout;
    finOne.open("InputOne.txt");
    if (!finOne.is_open()) {
        std::cerr << "Error in opening first input file!";
        std::exit(EXIT_FAILURE);
    }
    finTwo.open("InputTwo.txt");
    if (!finTwo.is_open()) {
        std::cerr << "Error in opening second input file!";
        std::exit(EXIT_FAILURE);
    }
    fout.open("Output.txt");
    if (!fout.is_open()) {
        std::cerr << "Error in opening Output file!";
        std::exit(EXIT_FAILURE);
    }
    char ch;
    char buff[stringMax];

    while (!(finOne.eof()&&finTwo.eof())) {
        if (finOne.getline(buff, stringMax)) {
            fout<<buff;
            if (!finTwo.eof()) {
                fout.put(' ');
            }
        }

        
        if (finTwo.getline(buff, stringMax)) {
            fout << buff;
            
        }
        fout.put('\n');
    }
    finOne.close();
    finTwo.close();
    fout.close();
    return 0;
}
