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

void Decryption(ELEMENTS* crypt) // Deshifrovane
{
	int n, converter;
	char decryptedText[200];
	cout << "Enter the number of words: "; cin >> n;
	cout << "Text ->: ";
	bool check = true;
	for (int i = 0; i < n; i++)
	{
		cin >> crypt[i].Text;
	}

	for (int i = 0; i < n; i++)
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

	for (int i = 0; i < n; i++)
	{
		//Tuk shte slojim pisaneto na notepad dokumenta
		cout << decryptedText[i];
	}

	cout << endl;
}

void Encryption(ELEMENTS* crypt) // Shifrovane
{
	int n, converter;
	char encryptedText[200];
	cout << "Enter the number of words: "; cin >> n;
	cout << "Text ->: ";
    bool check = true;
	for (int i = 0; i < n; i++)
	{	
		cin >> crypt[i].Text;
	}

	for (int i = 0; i < n; i++)
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

	for (int i = 0; i < n; i++)
	{
		//Tuk shte slojim pisaneto na notepad dokumenta
		cout << encryptedText[i];
	}

	cout << endl;
}

bool MainMenu(ELEMENTS* crypt)
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

int main()
{
	ELEMENTS crypt[100];
	int maxId = 0;

    do {
        showMainMenu = MainMenu(crypt);
    } while (showMainMenu != false);
}