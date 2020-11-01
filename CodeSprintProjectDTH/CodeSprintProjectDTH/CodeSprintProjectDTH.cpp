#include <iostream>
using namespace std;

bool showMainMenu = true;

struct ELEMENTS
{
	char Text;
};


int generateId(int& maxId)
{
	maxId++;
	return maxId;
}

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

void Decryption(ELEMENTS* crypt, int brCrypt) // Deshifrovane
{
	int converter;
	char decryptedText[100];
	bool check = true;

	for (int i = 0; i < brCrypt; i++)
	{
		converter = int(crypt[i].Text);

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
	cout << "-----------------------------------" << endl;

	for (int i = 1; i < brCrypt; i++)
	{
		//Tuk shte slojim pisaneto na notepad dokumenta
		cout << decryptedText[i];
	}

	cout << endl;
}

void Encryption(ELEMENTS* crypt, int brCrypt) // Shifrovane
{
	int converter;
	char encryptedText[100];
    bool check = true;

	for (int i = 0; i < brCrypt; i++)
	{
		converter = int(crypt[i].Text);

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

	cout << "-----------------------------------" << endl;
	cout << "Encrypted elements: ";

	for (int i = 1; i <= brCrypt-1; i++)
	{
		//Tuk shte slojim pisaneto na notepad dokumenta
		cout << encryptedText[i];
		Decryption(crypt, brCrypt);
	}

	cout << endl;
}
/*
bool MainMenuCrypt(ELEMENTS* crypt)
{
    cout << endl;
    cout << "|======================|" << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Encryption" << endl;
    cout << "2. Decryption" << endl;
    cout << "3. Exit" << endl;
    cout << "|======================|" << endl;

retry1:

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        Encryption(crypt);
        break;

    case 2:
        Decryption(crypt);
        break;

    case 3:
        exit();
        return 0;

    default:
        cout << "Incorrect input" << endl;
        goto retry1;
    }
    return true;
}
*/
void differenceOfSets(ELEMENTS* crypt, int brCrypt)
{
	int converter;
	char b[100];
	int countB = 0;

	cout << "-----------------------------------" << endl;
	cout << "Enter the lenght of the array1: "; cin >> brCrypt;
	cout << "Enter the lenght of the array2: "; cin >> countB;
	cout << "-----------------------------------" << endl;

	cout << "First Elementns: ";
	for (int i = 0; i < brCrypt; i++)
	{
		cin >> crypt[i].Text;
	}

	cout << "Second Elementns: ";
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

	for (int i = 0; i < brCrypt; i++)
	{
		if (crypt[i].Text != '`')
			Encryption(crypt, brCrypt);
	}
}

bool MainMenu(ELEMENTS* crypt, int brCrypt)
{
	cout << endl;
	cout << "|======================|" << endl;
	cout << "Choose an option: " << endl;
	cout << "1. Difference Of Sets" << endl;
	cout << "2. Decryption" << endl;
	cout << "3. Exit" << endl;
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
		// Sechenie - v progress
		break;

	case 3:
		// Obedinenie - napravih papka v komita - na ime obedinenie vutre ima notepad s koda
		break;

	case 4:
		//exit();
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
	int maxId = 0;

    do {
        showMainMenu = MainMenu(crypt, brCrypt);
    } while (showMainMenu != false);
}