#include <iostream>
using namespace std;

//global variable
bool showMainMenu = true;

//Structure where we have a structure of type char
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

//function for decryption
void Decryption(char* crypt, int brCrypt)
{
	// import the variables for the function
	int converter;
	char decryptedText[100];
	bool check = true;

	//loop for the operation decrypt
	for (int i = 0; i < brCrypt; i++)
	{
		converter = int(crypt[i]);

		if (converter == '0')
		{
			check = false;
			converter = '0';
		}

		else if (converter == '1')
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

	//loop for printing the elements which are already decrypt
	for (int i = 0; i < brCrypt; i++)
	{
		//NotePad
		cout << decryptedText[i] << " ";
	}
	cout << endl;
	cout << "-----------------------------------" << endl;

	cout << endl;
}

//function for encryption
void Encryption(char* crypt, int brCrypt) 
{
	// import the variables and intialize them for the function
	int converter;
	char encryptedText[100] = {};
	bool check = true;

	//loop for the operation 
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

		//if check is true than the variable converter will be shifted with 3
		if (check) converter += 3;

		//the array encryptedText take the value from the variable converter after each loop action
		encryptedText[i] = char(converter);
		check = true;
	}

	cout << "Encrypted elements: ";

	//loop for printing the value from the array
	for (int i = 0; i < brCrypt; i++)
	{
		//NotePad
		cout << encryptedText[i] << " ";
	}
	cout << endl;

	//call the function "Decryption"
	Decryption(encryptedText, brCrypt);
}

//function for the merge of the sets
void mergeOfSets(ELEMENTS* crypt, int brCrypt)
{
	
	char b[100];
	int countB;

	//output messages 
	cout << "-----------------------------------" << endl;
	cout << "Enter the lenght of the array1: "; cin >> brCrypt;
	cout << "Enter the lenght of the array2: "; cin >> countB;
	cout << "-----------------------------------" << endl;

	cout << "First Elements: ";
	//loop for input the first element of the sets
	for (int i = 0; i < brCrypt; i++)
	{
		cin >> crypt[i].Text;
	}

	cout << "Second Elements: ";
	//loop for input the second element of the sets
	for (int i = 0; i < countB; i++)
	{
		cin >> b[i];
	}

	char c[100];
	int n = brCrypt + countB;

	//counter
	int br = 0;
	
	//loop where the array "c" take the values from the first set
	for (int i = 0; i < brCrypt; i++)
	{
		c[i] = crypt[i].Text;
		br++;
	}

	//loop where the array "c" take the values from the second set
	for (int i = 0; i < countB; i++)
	{
		c[br++] = b[i];
	}

	//loop where we isolate the repeating values
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

	//loop for printing the merge of sets
	for (int i = 0; i < n; i++)
	{
		if (c[i] != '~')
		{
			found[br1++] = c[i];
			cout << c[i] << " ";
		}
	}
	cout << endl;

	//call the function "Encryption"
	Encryption(found, br1);
}

//function for the difference of the sets
void differenceOfSets(ELEMENTS* crypt, int brCrypt)
{
	//import the variables
	int converter;
	char b[100];
	int countB = 0;

	//output messages
	cout << "-----------------------------------" << endl;
	cout << "Enter the lenght of the array1: "; cin >> brCrypt;
	cout << "Enter the lenght of the array2: "; cin >> countB;
	cout << "-----------------------------------" << endl;

	cout << "First Elements: ";
	
	//input the first set
	for (int i = 0; i < brCrypt; i++)
	{
		cin >> crypt[i].Text;
	}

	cout << "Second Elements: ";

	//input the seond set
	for (int i = 0; i < countB; i++)
	{
		cin >> b[i];
	}

	//loop for isolation the repeatable values
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

	//loop for printing the difference between the sets
	for (int i = 0; i < brCrypt; i++)
	{
		if (crypt[i].Text != '`')
		{
			found[br++] = crypt[i].Text;
			cout << crypt[i].Text << " ";
		}
			
	}
	cout << endl;

	//call the function "Encryption"
	Encryption(found, br);
}

//----------------------------------Functions---------------------------------------\\

//this is the function where we print all the menu and where we operate the things
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

//the main function this is the start of the program 
int main()
{
	ELEMENTS crypt[100];
	int brCrypt = 0;

	//while loop for the menu
    do {
        showMainMenu = MainMenu(crypt, brCrypt);
    } while (showMainMenu != false);
}