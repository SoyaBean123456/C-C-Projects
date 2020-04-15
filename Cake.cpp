//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors


#include <cstdlib> // system()
#include <conio.h> // getch()
#include <fstream>
#include <sstream>
#include <sys\stat.h> // stat(status of a file)
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <cctype>
# pragma warning(disable : 4996)
using namespace std;




int main()
{
	int i;
	char A = 2;
	HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	Sleep(7000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tFrom: Yeo Yee Wen\n";
	Sleep(1000);
	SetConsoleTextAttribute(y, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tTo  : STUPID LECTURER\n\n";
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
	for (i = 0; i<42; i++)
		cout << "_";
	cout << "\n\n";
	
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);

	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\ti i i i i\n";
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\ti i i i i\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY  | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t      __i_i_i_i_i__\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t     |" << A << "           " << A << "|\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t   __| " << A << "  28 / 1  " << A << " |__\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  | " << A << "   " << A << "       " << A << "   " << A << " |\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t__|" << A << "   HAPPY     " << A << "   " << A << "|__\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t       | " << A << "   " << A << "     BIRTADAY    " << A << " |\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t       |" << A << "  " << A << "     " << A << "    " << A << "     " << A << "   " << A << "|\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t       | " << A << " " << A << " " << A << " " << A << " AssHole " << A << " " << A << " " << A << " " << A << " |\n";

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	Sleep(1000);
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t       |_________________________|\n";

	

	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\n\n\n\n\n";
	Sleep(1000);
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t\t\tToday is your special day\n\n";
	Sleep(1000);
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t\t\tSo , Here is a surprise for you, a gift for you from me\n\n";
	Sleep(1000);
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t\t\tHave a Happy birtAday!\n\n";
	system("pause");
	return 0;
}


















	
