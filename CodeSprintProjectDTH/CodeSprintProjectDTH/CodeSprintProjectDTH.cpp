#include <iostream>
using namespace std;

bool showMainMenu = true;

struct ELEMENTS
{
	char Text;
};

//----------------------------------Structure---------------------------------------\\

//function for the end of the program
void exit()
{
    cout << endl;
    cout << "**************************************" << endl;
    cout << "**************************************" << endl;
    cout << "*******    T H A N K  Y O U    *******" << endl;
    cout << "*******    F O R  U S I N G    *******" << endl;
    cout << "*******  O U R  P R O G R A M  *******" << endl;
    cout << "**************************************" << endl;
    cout << "**************************************" << endl;
}

void Decryption(char* crypt, int brCrypt)
{
	int converter;
	char decryptedText[100];
	bool check = true;

	for (int i = 0; i < brCrypt; i++)
	{
		converter = int(crypt[i]);

		if (converter == '1')
		{
			check = false;
			converter = '1';
		}
		else if (converter == '2')
		{
			check = false;
			converter = '2';
		}

		if (converter == 'a')
		{
			check = false;
			converter = 'x';
		}
		else if (converter == 'A')
		{
			check = false;
			converter = 'X';
		}

		if (converter == 'b')
		{
			check = false;
			converter = 'y';
		}
		else if (converter == 'B')
		{
			check = false;
			converter = 'Y';
		}

		if (converter == 'c')
		{
			check = false;
			converter = 'z';
		}
		else if (converter == 'C')
		{
			check = false;
			converter = 'Z';
		}

		if (check) converter -= 3;

		decryptedText[i] = char(converter);
		check = true;
	}

	cout << "Decrypted elements: ";

	for (int i = 0; i < brCrypt; i++)
	{
		//NotePad
		cout << decryptedText[i] << " ";
	}
	cout << endl;
	cout << "-----------------------------------" << endl;

	cout << endl;
}

void Encryption(char* crypt, int brCrypt) 
{
	int converter;
	char encryptedText[100] = {};
	bool check = true;

	for (int i = 0; i < brCrypt; i++)
	{
		converter = int(crypt[i]);

		if (converter == 'x')
		{
			check = false;
			converter = 'a';
		}
		else if (converter == 'X')
		{
			check = false;
			converter = 'A';
		}

		if (converter == 'y')
		{
			check = false;
			converter = 'b';
		}
		else if (converter == 'Y')
		{
			check = false;
			converter = 'B';
		}

		if (converter == 'z')
		{
			check = false;
			converter = 'c';
		}
		else if (converter == 'Z')
		{
			check = false;
			converter = 'C';
		}

		if (check) converter += 3;

		encryptedText[i] = char(converter);
		check = true;
	}

	cout << "Encrypted elements: ";

	for (int i = 0; i < brCrypt; i++)
	{
		//NotePad
		cout << encryptedText[i] << " ";
	}
	cout << endl;

	Decryption(encryptedText, brCrypt);
}

void mergeOfSets(ELEMENTS* crypt, int brCrypt)
{
	char b[100];
	int countB;

	cout << "-----------------------------------" << endl;
	cout << "Enter the lenght of the array1: "; cin >> brCrypt;
	cout << "Enter the lenght of the array2: "; cin >> countB;
	cout << "-----------------------------------" << endl;

	cout << "First Elements: ";
	for (int i = 0; i < brCrypt; i++)
	{
		cin >> crypt[i].Text;
	}

	cout << "Second Elements: ";
	for (int i = 0; i < countB; i++)
	{
		cin >> b[i];
	}

	char c[100];
	int n = brCrypt + countB;

	int br = 0;

	for (int i = 0; i < brCrypt; i++)
	{
		c[i] = crypt[i].Text;
		br++;
	}
	for (int i = 0; i < countB; i++)
	{
		c[br++] = b[i];
	}

	for (int i = 0; i < brCrypt; i++)
	{
		for (int j = brCrypt; j < n; j++)
		{
			if (c[i] == c[j])
			{
				c[i] = '~';

			}
		}
	}

	char found[100];
	int br1 = 0;
	cout << "-----------------------------------" << endl;
	
	cout << "Merge of set: ";
	for (int i = 0; i < n; i++)
	{
		if (c[i] != '~')
		{
			found[br1++] = c[i];
			cout << c[i] << " ";
		}
	}
	cout << endl;

	Encryption(found, br1);
}

void differenceOfSets(ELEMENTS* crypt, int brCrypt)
{
	int converter;
	char b[100];
	int countB = 0;

	cout << "-----------------------------------" << endl;
	cout << "Enter the lenght of the array1: "; cin >> brCrypt;
	cout << "Enter the lenght of the array2: "; cin >> countB;
	cout << "-----------------------------------" << endl;

	cout << "First Elements: ";
	for (int i = 0; i < brCrypt; i++)
	{
		cin >> crypt[i].Text;
	}

	cout << "Second Elements: ";
	for (int i = 0; i < countB; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < brCrypt; i++)
	{
		for (int j = 0; j < countB; j++)
		{
			if (crypt[i].Text == b[j])
			{
				crypt[i].Text = '`';
			}
		}
	}

	char found[100];
	int br = 0;

	cout << "-----------------------------------" << endl;

	cout << "Difference of set: ";
	for (int i = 0; i < brCrypt; i++)
	{
		if (crypt[i].Text != '`')
		{
			found[br++] = crypt[i].Text;
			cout << crypt[i].Text << " ";
		}
			
	}
	cout << endl;

	Encryption(found, br);
}

//----------------------------------Functions---------------------------------------\\

bool MainMenu(ELEMENTS* crypt, int brCrypt)
{
	cout << endl;
	cout << "|======================|" << endl;
	cout << "Choose an option: " << endl;
	cout << "1. Difference Of Sets" << endl;
	cout << "2. Merge Of Sets" << endl;
	cout << "3. " << endl;
	cout << "4. Exit" << endl;
	cout << "|======================|" << endl;

retry1:

	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		differenceOfSets(crypt, brCrypt);
		break;

	case 2:
		mergeOfSets(crypt, brCrypt);
		break;

	case 3:
		// Sechenie
		break;

	case 4:
		exit();
		return 0;

	default:
		cout << "Incorrect input" << endl;
		goto retry1;
	}
	return true;
}

int main()
{
	ELEMENTS crypt[100];
	int brCrypt = 0;

    do {
        showMainMenu = MainMenu(crypt, brCrypt);
    } while (showMainMenu != false);
}