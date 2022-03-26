// компилировать вместе с файлом People.cpp
#include "People.h"

const int MAX = 10;

bool is_empty(std::fstream& File)
{
    return File.peek() == std::fstream::traits_type::eof();
}

int main()
{
    using  std::cin;
    using  std::cout;
    using  std::fstream;
    using  std::ios_base;

    char streamChoice;
    fstream file;
    abstr_emp* pc[MAX];
    int fileObjNum = 0;// количество объектов в файле на момент его открытия
    int totalObjNum = 0; // количество объектов в файле + созданные во время работы программы объекты
    char checkEof;


    cout << "This programm supports only up to " << MAX << " objects! \n";
    cout << "Do you want to erase all the previous information in the file? y/n: ";
    cin.get(streamChoice);
    while (streamChoice != 'y' && streamChoice != 'n') {
        
            cout << "You've entered a wrong choice, try again: ";
            cin.get(streamChoice);        
    }
    if (streamChoice == 'y') {
        file.open("Employee.dat", ios_base::in | ios_base::out|ios_base::trunc);
    }
    else if (streamChoice == 'n') {
        file.open("Employee.dat", ios_base::in | ios_base::out|ios_base::app);
    }
    if (!file.is_open()) {
        cout << "Error in opening file!";
        exit(EXIT_FAILURE);
    }
    if (!is_empty(file)) {
        for (int i = 0; i < MAX; i++) {
            file.get(checkEof); // запись каждого объекта заканчивается символом \n, поэтому, чтобы проверить file на eof, необходимо сперва убрать символ \n из буфера,
            if (file.peek() == std::fstream::traits_type::eof()) { // проверить file на eof, а затем, если конец файла не достигнут, вернуть символ \n в буффер
                break;
            }
            else {
                file.putback(checkEof);
            }
            fileObjNum++;
            fromFileEmp(pc[i], file);            
        }
        for (int i = 0; i < fileObjNum; i++) {
            pc[i]->ShowAll();
        }
    }
    file.clear();
    if (fileObjNum == MAX) {
        cout << "\nMaximum amount of objects, you can't add more!";
    }
    else {
        totalObjNum = fileObjNum;
        cout << std::endl;
        cout << "\nIf you want to quit entering new objects, just select \"Employee\" option and type \"quit\" \n";
        for (int i = fileObjNum; i < MAX; i++) {
            if (createEmp(pc[i])) {
                break;
            }
            totalObjNum++;
        }
        cout << std::endl;
        for (int i = 0; i < totalObjNum; i++) {
            pc[i]->ShowAll();
        }
        for (int i = fileObjNum; i < totalObjNum; i++) {
            pc[i]->WriteAll(file);
        }

        for (int i = 0; i < totalObjNum; i++) {
            delete pc[i];
        }
    }
    file.close();
    return 0;
}
