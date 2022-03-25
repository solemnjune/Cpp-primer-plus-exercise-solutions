// компилировать вместе с файлом Source.cpp
#include "pch.h"
#include "DMA.h"

const int DMAs = 4;
const int MAXSTRING = 256;
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	
	DMA * arrDMAs[DMAs];
	char * tempLabel = new char[MAXSTRING];
	char * tempStCol = new char[MAXSTRING];
	int tempRat;
	int choice;

	

	for (int i = 0; i < DMAs; i++)
	{
		cout << "Enter DMA's label: "; // ввод имени клиента 
		cin.getline(tempLabel, MAXSTRING);
		cout << "Enter DMA's rating: "; // ввод номера счета клиента 
		cin >> tempRat;
		cout << "Enter 1 for Base DMA, 2 for DMA with the choice of color or "
			<< "3 for DMA with the choice of style: "; // 1 — baseDMA; 2 — lacksDMA; 3 - hasDMA 
		while (cin >> choice && (choice != 1 && choice != 2&& choice != 3)) {
			cout << "Enter either 1, 2 or 3: ";
		}
		cin.get();
		if (choice == 1){
			arrDMAs[i] = new baseDMA(tempLabel, tempRat);
		}
		else if(choice ==2)
		{

			cout << "Enter color: "; // ввод предельного овердрафта 
			cin.getline(tempStCol, MAXSTRING);
			arrDMAs[i] = new lacksDMA(tempStCol, tempLabel, tempRat);
		}
		else if (choice == 3)
		{

			cout << "Enter style: "; // ввод предельного овердрафта 
			cin.getline(tempStCol, MAXSTRING);
			arrDMAs[i] = new hasDMA(tempStCol, tempLabel, tempRat);
		}
		//while (cin.get() != '\n')
			//continue;
	}
	for (int i = 0; i < DMAs; i++)
	{
		arrDMAs[i]->view();
		cout << endl;
	}

	

	for (int i = 0; i < DMAs; i++)
	{
		delete arrDMAs[i]; // освобождение памяти 
	}

	delete[] tempLabel;
	delete[] tempStCol;

	return 0;
}
