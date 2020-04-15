#include <iostream>
#include <string.h>
using namespace std;

int main() 
{
	char password[] = "Password123"; char input[12]; int i, signal = 0;

	cout << "Please Guess the password.\n";

	for (i = 3; i>0; --i) {
		cout << "\nAttemp Left : " << int(i) << "\n";
		cin >> input;
		if (strcmp(input, password) != 0 && i >1)
		{
			cout << "\nSorry, Try Again.";
		}
		else if (strcmp(input, password) == 0)
		{
			cout << "\nCorrect Guess!!!";
			break;
		}
		else
			signal = 1;
	}
	if (signal == 1)
		cout << "\nSorry, no access to the system.\a\n";
}

