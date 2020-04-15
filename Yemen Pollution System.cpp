

//// Programmer : Yeo Yee Wen
//// Yemen pollution solution system

/////////////     Includes    /////////////
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




HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);



/////////////     Data types    /////////////
int Pollutionid = 1000;
int searchPollutionid;


// Function Modules



struct Inventory_Record // Inventory record

{
	int Pollutionid = 0;
	string causeofwaterpollution;
	string year;
	double phlevelwater;
	string waterdensity;
	string clearityofwater;
	string temperature;
	string Oxygen;
	string OrganicMaterials;
	string Remarkofwater;
	int temp, tempCon;
	char unit;
	int i;
	string choice;
	string username;
	string password;
	int y = 1;
	string save_delete;
	int Enter;
	void timer(int sec)

	{

		Sleep(sec * 5);

	}

	string choice2;
	string keyinby;
	string remark;


	//Dont touch after this line

	bool deleted;

};

Inventory_Record Inventory;



/////////////     Variable Declarations & Constants /////////////



#define INVENTORY_FILE_NAME  "Inventory.txt" // name of the database file to store Inventory informations
char choice; // for choice in menu
char piece[2];




fstream *fs = NULL, *fs1 = NULL;// file streams for files : fs -> 'Inventory', fs1 -> 'temp'

bool deletion = false; // if any record has been deleted



char ch;
string pass = "";
string uname = "";
string password = "12345";
string username = "Yeo";




/////////////     Function Prototypes    /////////////


void closeFile(fstream *); // closes a file with its pointer, then deletes the file pointer
bool isFileExist(const char *); // check if a file exists





								/////////////     Main    /////////////



int main()

{

	ifstream input;
	input.open("ID.txt"), ios::in;
	input >> Pollutionid;
	ofstream output;
	char date[10];
	_strdate(date);
	int recs_num;






	system("cls");
	cout << "\n";
	cout << "\n";
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t################################################################################" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "												" << endl;
	cout << "												" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t			Welcome To Yemen Pollution Solution						" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "\t\t\t\t\t\t\t\t			      Inventory Management System " << endl;
	cout << "												" << endl;
	cout << "												" << endl;
	cout << "												" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "\t\t\t\t\t\t\t\t################################################################################" << endl;




	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;


	int totalSeconds = time(0);
	int currentSecond = totalSeconds % 60;
	int totalMinutes = totalSeconds / 60;
	int currentMinute = totalMinutes % 60;
	long totalHours = totalMinutes / 60;
	int currentHour = (int)(totalHours % 24);

	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t\t\t\t\t\tCurrent time is " << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;

	cout << "\n" << endl;
	cout << "\n" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	system("pause");

	{


		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);
		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);
	}
A:






	system("cls");
	SetConsoleTextAttribute(y, 0);
	cout << "\n";
	cout << "\n";
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t#################################################################" << endl;
	cout << "\t\t\t\t\t\t\t\t #								#" << endl;
	cout << "\t\t\t\t\t\t\t\t #								#" << endl;
	cout << "\t\t\t\t\t\t\t\t #				LOG IN 				#" << endl;
	cout << "\t\t\t\t\t\t\t\t #								#" << endl;
	cout << "\t\t\t\t\t\t\t\t #								#" << endl;
	cout << "\t\t\t\t\t\t\t\t#################################################################" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;







	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t\t\t\t\t1)\t LOG IN\n" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t\t\t\t\t2)\t EXIT\n" << endl;
	cout << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED);
	cout << "\t\t\t\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE: \t";
	cin >> Inventory.choice;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << endl;



	while (true)

	{

		if

			(Inventory.choice == "1" || Inventory.choice == "2")


			break;



		else

			"========ERROR===================================================\n";
		system("color 04");						//red
		SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t\t\t\t\t\t\t\t InCORRECT! Please Enter Again!" << endl;
		SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t\t\t\t\t\t\t\n\t PLEASE ENTER YOUR choice :\t";
		SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cin >> Inventory.choice;
		cout << endl;



	}

	if (Inventory.choice == "1")

	{

		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);
		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);

		bool IsLoggedIn();

		{

		START:



			system("color 03");
			system("cls");
			SetConsoleTextAttribute(y, 0);
			cout << "\n";
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t\t\t\t#################################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #		LOG IN BY KEYING USERMANE AND PASSWORD		#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t#################################################################" << endl;
			cout << "\n" << endl;
			cout << "\n" << endl;



			cout << endl;

			{

				int totalSeconds = time(0);
				int currentSecond = totalSeconds % 60;
				int totalMinutes = totalSeconds / 60;
				int currentMinute = totalMinutes % 60;
				long totalHours = totalMinutes / 60;
				int currentHour = (int)(totalHours % 24);





				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\tCurrent time is " << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;

			}

			do

			{

			START9:


				pass = "12345";
				uname = "Yeo";





				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\t\n\tUsername   :\t";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> uname;
				cout << endl;



				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\t\n\tPassword   :\t";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_RED);
				char pass[32];//to store password.
				int i = 0;
				char a;//a Temp char
				for (i = 0;;)//infinite loop
				{
					a = getch();//stores char typed in a
					if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
						//check if a is numeric or alphabet
					{
						pass[i] = a;//stores a in pass
						++i;
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "*";
					}
					if (a == '\b'&&i >= 1)//if user typed backspace
										  //i should be greater than 1.
					{
						cout << "\b \b";//rub the character behind the cursor.
						--i;
					}
					if (a == '\r')//if enter is pressed
					{
						pass[i] = '\0';//null means end of string.
						break;//break the loop
					}
				}





				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n\n\tYou Entered : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t " << pass;
				cout << "\n\n";
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << endl;

				if (pass == password && uname == username)
				{
					system("color 02");//green

					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					"========SUCCESS===================================================\n";
					cout << "\t Successfully logged in !" << endl;
					{
						int totalSeconds = time(0);
						int currentSecond = totalSeconds % 60;
						int totalMinutes = totalSeconds / 60;
						int currentMinute = totalMinutes % 60;
						long totalHours = totalMinutes / 60;
						int currentHour = (int)(totalHours % 24);


						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
						cout << "\t\n\n\tLogged In time is " << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;

						cout << "\n";
						system("color 01");
						Inventory.timer(1);
						system("color 02");
						Inventory.timer(1);
						system("color 03");
						Inventory.timer(1);
						system("color 04");
						Inventory.timer(1);
						system("color 05");
						Inventory.timer(1);
						system("color 06");
						Inventory.timer(1);
						system("color 07");
						Inventory.timer(1);
						system("color 08");
						Inventory.timer(1);
						system("color 09");
						Inventory.timer(1);
						system("color 0A");
						Inventory.timer(1);
						system("color 0B");
						Inventory.timer(1);
						system("color 0C");
						Inventory.timer(1);
						system("color 0D");
						Inventory.timer(1);
						system("color 0E");
						Inventory.timer(1);
						system("color 0F");
						Inventory.timer(1);
						system("color 01");
						Inventory.timer(1);
						system("color 02");
						Inventory.timer(1);
						system("color 03");
						Inventory.timer(1);
						system("color 04");
						Inventory.timer(1);
						system("color 05");
						Inventory.timer(1);
						system("color 06");
						Inventory.timer(1);
						system("color 07");
						Inventory.timer(1);
						system("color 08");
						Inventory.timer(1);
						system("color 09");
						Inventory.timer(1);
						system("color 0A");
						Inventory.timer(1);
						system("color 0B");
						Inventory.timer(1);
						system("color 0C");
						Inventory.timer(1);
						system("color 0D");
						Inventory.timer(1);
						system("color 0E");
						Inventory.timer(1);
						system("color 0F");
						Inventory.timer(1);





					}
					cout << endl;
					Inventory.timer(1);

					break;

				}

				else

				{
					system("color 04"); //red
					"========ERROR===================================================\n";
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "\n";
					cout << "\t Mistake in Username or Password 1 !" << endl << endl;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t Please Enter Again" << endl << endl;
					goto START9;

				}

			}


			while (pass != password && uname != username);
			system("cls");

			if (Inventory.y >= 5)
			{
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "NO MORE ATTEMPTS !!!";
				return false;
			}

		}

	}

	else if (Inventory.choice == "2")

	{
		SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		system("cls");

		//Exit Splash Screen
		cout << "\n";
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t" << endl;
		cout << "\t\t\t\t\t\t\t\t                                                                                                            " << endl;
		cout << "\t\t\t\t\t\t\t\t                             This Inventory system                         " << endl;
		cout << "\t\t\t\t\t\t\t\t                                is created  by                                       " << endl;
		cout << "\t\t\t\t\t\t\t\t                                Mr. Yeo Yee Wen                               " << endl;
		cout << "\t\t\t\t\t\t\t\t                                    TQ for using                                      " << endl;
		cout << "\t\t\t\t\t\t\t\t                                                                         " << endl;
		cout << "\t\t\t\t\t\t\t\t\t Goodbye ^_^";



		int totalSeconds = time(0);
		int currentSecond = totalSeconds % 60;
		int totalMinutes = totalSeconds / 60;
		int currentMinute = totalMinutes % 60;
		long totalHours = totalMinutes / 60;
		int currentHour = (int)(totalHours % 24);


		SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
		cout << "\t\n\n\tExit time is " << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;
		cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);
		system("color 01");
		Inventory.timer(1);
		system("color 02");
		Inventory.timer(1);
		system("color 03");
		Inventory.timer(1);
		system("color 04");
		Inventory.timer(1);
		system("color 05");
		Inventory.timer(1);
		system("color 06");
		Inventory.timer(1);
		system("color 07");
		Inventory.timer(1);
		system("color 08");
		Inventory.timer(1);
		system("color 09");
		Inventory.timer(1);
		system("color 0A");
		Inventory.timer(1);
		system("color 0B");
		Inventory.timer(1);
		system("color 0C");
		Inventory.timer(1);
		system("color 0D");
		Inventory.timer(1);
		system("color 0E");
		Inventory.timer(1);
		system("color 0F");
		Inventory.timer(1);
		system("pause");


		return 0;
	}
	while (true)

	{


		do////// Menu //////

		{
			system("cls"); // clear screen
			system("color 09");
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t#################################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t #			MAIN MENU 				#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t #								#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t#################################################################" << endl;
			cout << "\n" << endl;
			cout << "\n" << endl;
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);


		mainmenu:

			system("cls"); // clear screen
			system("color 09");
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\t\t\t\t\t\t\t\t\t\t  THIS IS YEMEN SOLUTION \n\t\t\t\t\t\t\t\t\t\t\tINVENTORY MANAGEMENT SYSTEM  \n\n";

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t(1) Add a new Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t(2) Search an existing Record\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t(3) Delete an existing Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t(4) Display Latest Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t(5) Update Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t(6) Exit \n\n";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "    \t\t\t\t\t\t\t\t\t\tEnter a choice (1-6) :\t\t\t\t\t\t " << flush;
			choice = _getch();
			system("color 01");
			Inventory.timer(1); system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);


		} while (choice < '1' || choice > '6'); // while we have no good(between 1 and 5), show menu again




		system("cls");


		// to modify, delete or display records, database file should exist, then we have some records          



		if (choice == '2' || choice == '3' || choice == '4' || choice == '5')

		{


			if (!isFileExist(INVENTORY_FILE_NAME)) // if database file doesn't exist


			{
				cout << "\n Database file ('" << INVENTORY_FILE_NAME << "') doesn't exist, then there are no records." << endl;
				system("pause");
				continue; // show the menu again

			}
		}



		time_t now = time(0);
		tm *ltm = localtime(&now);



		switch (choice)

		{




			int recs_num; // number of records before the record for modifying(deletion)
			int id;




		case '1': ////// Add Record //////






			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *			Input  1 to continue		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *				OR			*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *			any	       key	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *		  to go back to the main menu		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			cin >> Inventory.Enter;







			while (true)

				if (Inventory.Enter == 1)
				{
					goto loopaddcase;

				}

				else
				{

					goto mainmenu;

				}





		loopaddcase:

			Inventory.Pollutionid = ++Pollutionid;
			cout << "\t\t\t\n\t\t Pollution ID :" << Inventory.Pollutionid << endl;
			if (output.open("ID.txt"), ios::out)//create"id.txt"to store id
			{
				output << Pollutionid;
			}
			else cout << "the file is empty.";
			output.close();






			system("cls"); // clear screen
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n----------[ ADD RECORD ]-------------------------------------------------------\n";
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t Pollution ID :" << Inventory.Pollutionid << endl;
			cout << "\n";
			cout << "Please Input Space for Year before typing";
			cout << "\n\n";


			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tCause of Pollution :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t\t";
				getchar();
				getline(cin, Inventory.causeofwaterpollution);
				while (Inventory.causeofwaterpollution.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Pollution!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tCause of Pollution :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					getline(cin, Inventory.causeofwaterpollution);
				}

			}

			cout << "\n";

			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tYear :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
				getchar();
				getline(cin, Inventory.year);
				while (Inventory.year.find_first_of("0123456789") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Year!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tYear :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
					getline(cin, Inventory.year);
				}

			}


			cout << "\n";
			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tEnter Ph Level Of Water in integer :";				
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t";
				cin >> Inventory.phlevelwater;
				if (Inventory.phlevelwater >= 7.0)
				{

					if (Inventory.phlevelwater == 7.0)
					{
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\n\t\tPh Level is Neutral";
						cout << "\n";
					}

					else
					{
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\n\t\tPh Level is Alkaline";
						cout << "\n";
					}
				}
				else
				{
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n\t\tPh Level is Acidic";
					cout << "\n";
				}
			}


			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\tWater Density (use this unit 1g/cc) :";					
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t\t\t";
			cin >> Inventory.waterdensity;

			cout << "\n";

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\tClearity of Water :";				
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t\t\t\t\t\t\t";
			cin >> Inventory.clearityofwater;

			cout << "\n";

			{


				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tPlease enter the temperature :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t";
				cin >> Inventory.temp;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n";
				cout << "\tPlease enter the measurement system (c or f) :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t";
				cin >> Inventory.unit;

				if (isupper(Inventory.unit))
				{
					Inventory.unit = tolower(Inventory.unit);
				}

				if (Inventory.unit == 'f')
				{
					Inventory.temp = (Inventory.temp - 32) / 9.0 * 5.0;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n\tWater is " << Inventory.temp << " degrees Fahrenheit\n";
				}
				else if (Inventory.unit == 'c')
				{
					Inventory.temp = 9.0 / 5.0 * Inventory.temp + 32;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n\tWater is " << Inventory.temp << " degrees Celsius\n";
				}
				else
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "\n\tSorry that unit of measuring water isn't recognized around here.\n";

				}
			}


			cout << "\n";

			{
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tOxygen Quantity :";
				cout << "\n\t\t\t 1) GOOD";
				cout << "\n\t\t\t 2) BAD";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t\t";
				cin >> Inventory.Oxygen;
				if (Inventory.Oxygen == "1")
				{
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n";
					cout << "\tOxygen Quantity is Good for drinking.";
				}
				else if (Inventory.Oxygen == "2")
				{
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n";
					cout << "\tOxygen Quantity is Bad for drinking.";
				}
				else
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "\n\tInvalid Input.\n";

				}
			}




			{
				cout << "\n";
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n\tOrganic Materials in Water :";			
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t";
				getchar();
				getline(cin, Inventory.OrganicMaterials);
				while (Inventory.OrganicMaterials.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In valid Organic Materials in Water!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n\tOrganic Materials in Water :";			
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t";
					getline(cin, Inventory.OrganicMaterials);
				}

			}





			cout << "\n";

			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tRemark of Water :(Press Space before typing remark)";			
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t";
				getchar();
				getline(cin, Inventory.Remarkofwater);
				while (Inventory.Remarkofwater.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Remark!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tRemark of Water :";			
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t";
					getline(cin, Inventory.Remarkofwater);
				}

			}




			cout << "\n";




			//Dont touch after this line


			Inventory.deleted = 0;
			fs = new fstream(INVENTORY_FILE_NAME, ios::out | ios::app | ios::binary);
			if (!fs)

			{
				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << "' file" << endl;
				system("pause");
				break;
			}





			cout << " \nDo you want to save this record?\n\n\n (1=Yes, 2=No, 3=Save and Add): ";
			char confirm;




		loopadd:


			cin >> confirm;
			cin.ignore();
			system("cls");

			if (confirm == '1')

			{

				fs->write((char *)&Inventory, sizeof(Inventory));
				closeFile(fs);

				cout << "\n Record added." << endl;
				{
					int totalSeconds = time(0);
					int currentSecond = totalSeconds % 60;
					int totalMinutes = totalSeconds / 60;
					int currentMinute = totalMinutes % 60;
					long totalHours = totalMinutes / 60;
					int currentHour = (int)(totalHours % 24);

					cout << "Current time is" << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;
				}



				system("pause");
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				goto mainmenu;
				break;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);



			}

			if (confirm == '2')

			{


				cout << " \n Record not added." << endl;
				system("pause");
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				goto mainmenu;
				break;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


			}

			if (confirm == '3')

			{



				fs->write((char *)&Inventory, sizeof(Inventory));
				closeFile(fs);
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "==============================================================================================================================================" << endl;
				goto loopaddcase;
			}

			else

			{
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "\n\n Invalid Input!\n\n Please enter (1=Yes, 2=No, 3=Save and Add) To Confirm Add Record.";
				cout << "\n Do you want to add this record?\n\n\n(1=Yes, 2=No, 3=Save and Add): ";
				goto loopadd;
			}


		case '2': ////// Search Record //////




			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *			Input  1 to continue		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *				OR			*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *			any	       key	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *		  to go back to the main menu		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			cin >> Inventory.Enter;






			while (true)

				if (Inventory.Enter == 1)
				{
					goto g;

				}

				else
				{

					goto mainmenu;

				}





		g:

			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n----------[ SEARCH RECORD ]-----------------------------------------------------\n";

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #		Search an Existing Record		#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << endl;

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Pollution ID that you want to search: ";
			cin >> searchPollutionid;
			cin.ignore();


			fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::binary);
			if (!fs)
			{
				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << "file" << endl;
				system("pause");
				break;
			}

			recs_num = -1;
			while (fs->read((char*)&Inventory, sizeof(Inventory)))

			{

				recs_num++;
				if (searchPollutionid == Inventory.Pollutionid && !Inventory.deleted)
					break;

			}

			if (fs->eof())

			{
				cout << "The specific Pollution  does not exist in file." << endl;
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;
			}
			fs->seekp(sizeof(Inventory) * recs_num, ios::beg);
			fs->read((char*)&Inventory, sizeof(Inventory));

			if (!Inventory.deleted)

			{

				system("cls"); // clear screen to go to a new page
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n----------[ SEARCHED RECORD ]---------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t Pollution ID :" << Inventory.Pollutionid << endl;


				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tCause of Pollution :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.causeofwaterpollution;


				}

				cout << "\n";

				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tYear :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Inventory.year;


				}


				cout << "\n";
				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tEnter Ph Level Of Water in integer :";				
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t" << Inventory.phlevelwater;

				}



				cout << "\n";
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tWater Density (use this unit 1g/cc) :";					
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t" << Inventory.waterdensity;


				cout << "\n";

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\tClearity of Water :";				
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.clearityofwater;


				cout << "\n";

				{


					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tPlease enter the temperature :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t" << Inventory.temp;

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n";
					cout << "\tPlease enter the measurement system (c or f) :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t" << Inventory.unit;



				}


				cout << "\n";

				{
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tOxygen Quantity :";
					cout << "\n\t\t\t 1) GOOD";
					cout << "\n\t\t\t 2) BAD";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Oxygen;

				}




				{
					cout << "\n";
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n\tOrganic Materials in Water :";			
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t" << Inventory.OrganicMaterials;


				}





				cout << "\n";

				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tRemark of Water :";			
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Remarkofwater;


				}




				cout << "\n";


			}


			cout << "\n To return to menu,";
			cout << "\n Record has been searched." << endl;
			system("pause");
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			goto mainmenu;
			break;

		case '3': ////// Delete Record //////




			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *			Input  1 to continue		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *				OR			*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *			any	       key	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *		  to go back to the main menu		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			cin >> Inventory.Enter;




			while (true)

				if (Inventory.Enter == 1)
				{
					goto f;

				}

				else
				{

					goto mainmenu;

				}

		f:

			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

			cout << "\n----------[ DELETE RECORD ]----------------------------------------------------\n";

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #		Delete an Existing Record		#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << endl;


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Pollution ID, for deletion : ";
			cin >> searchPollutionid;
			cin.ignore();


			fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::out | ios::binary);
			if (!fs)
			{
				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << "' file." << endl;
				system("pause");
				break;
			}

			recs_num = -1;
			while (fs->read((char*)&Inventory, sizeof(Inventory)))
			{
				recs_num++;
				if (Inventory.Pollutionid == searchPollutionid && !Inventory.deleted)
					break;
			}

			if (fs->eof())
			{
				cout << "The specific Pollution does not exist in file." << endl;
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;
			}

			Inventory.deleted = 1;
			fs->seekp(sizeof(Inventory) * recs_num, ios::beg);
			fs->write((char*)&Inventory, sizeof(Inventory));
			closeFile(fs);
			deletion = true;



			system("cls"); // clear screen

			cout << "\n----------[ DELETED RECORD ]---------------------------------------------------\n";
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\t Pollution ID :" << Inventory.Pollutionid << endl;






			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\n\n\t\t\t The Following Record is deleted." << endl;
			system("pause");
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			goto mainmenu;
			break;


		case '4': ////// Display LATEST RECORD/////////



			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *			Input  1 to continue		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *				OR			*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *			any	       key	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *		  to go back to the main menu		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			cin >> Inventory.Enter;






			while (true)

				if (Inventory.Enter == 1)
				{
					goto d;

				}

				else
				{

					goto mainmenu;

				}





		d:


			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\n----------[ DISPLAY LATEST RECORD ]---------------------------------------------------\n";


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #		Display Latest Record										#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << endl;


			system("pause");



			fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::binary);

			if (!fs)
			{
				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << " file." << endl;
				system("pause");
				break;
			}


			while (fs->read((char *)&Inventory, sizeof(Inventory))) // display latest record
			{
				if (!Inventory.deleted)
				{

					{

						system("cls"); // clear screen
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n----------[ LATEST RECORD ]---------------------------------------------------\n";
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t Pollution ID :" << Inventory.Pollutionid << endl;
						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tCause of Pollution :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.causeofwaterpollution;


						}

						cout << "\n";

						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tYear :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Inventory.year;


						}


						cout << "\n";
						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tEnter Ph Level Of Water in integer :";				
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t" << Inventory.phlevelwater;

						}



						cout << "\n";
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tWater Density (use this unit 1g/cc) :";					
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t" << Inventory.waterdensity;


						cout << "\n";

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tClearity of Water :";			
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.clearityofwater;


						cout << "\n";

						{


							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tPlease enter the temperature :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t" << Inventory.temp;

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n";
							cout << "\tPlease enter the measurement system (c or f) :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t" << Inventory.unit;



						}


						cout << "\n";

						{
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tOxygen Quantity :";
							cout << "\n\t\t\t 1) GOOD";
							cout << "\n\t\t\t 2) BAD";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Oxygen;

						}




						{
							cout << "\n";
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n\tOrganic Materials in Water :";			
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t" << Inventory.OrganicMaterials;


						}





						cout << "\n";

						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tRemark of Water :";		
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Remarkofwater;


						}




						cout << "\n";


					}

				}
			}

			cout << "\n To return to menu, ";
			system("pause");
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			closeFile(fs);
			goto mainmenu;
			break;



		case '5': ////// Update Record //////




			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *			Input  1 to continue		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *				OR			*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *			any	       key	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t *		  to go back to the main menu		*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t\t\t\t\t\t\t\t *							*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t\t ********************************************************" << endl;
			cin >> Inventory.Enter;




			while (true)

				if (Inventory.Enter == 1)
				{
					goto r;

				}

				else
				{

					goto mainmenu;

				}

		r:

			system("cls");

			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\n----------[ UPDATE RECORD ]-----------------------------------------------------\n";


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #		Update an Existing Record		#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << endl;



			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Pollution ID to update : ";
			cin >> searchPollutionid;
			cout << endl << endl;



			fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::out | ios::binary);



			if (!fs)

			{

				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << "' file" << endl;
				system("pause");
				break;

			}



			recs_num = -1;
			while (fs->read((char *)&Inventory, sizeof(Inventory)))

			{

				recs_num++;
				if (Inventory.Pollutionid == searchPollutionid && !Inventory.deleted) //if user delete an Pollution then added another one with the same Name in the same
																					  //instance of program runs, delete Pollution is still there, then we should go through all the file

					break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{

				cout << "\n Your specified Pollution ID doesn't exist in file." << endl;
				closeFile(fs);
				system("pause");

				goto mainmenu;
				break;

			}

			fs->seekp(sizeof(Inventory)*recs_num, ios::beg);//go to searched record
			fs->read((char*)&Inventory, sizeof(Inventory));//display the seached record
			if (!Inventory.deleted)


			{
				{

				UpdateList:



					system("cls");
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					system("cls"); // clear screen

					cout << "\n----------[ UPDATE RECORD ]-----------------------------------------------------\n";
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t Pollution ID :" << Inventory.Pollutionid << endl;
					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tCause of Pollution :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.causeofwaterpollution;


					}

					cout << "\n";

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tYear :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << Inventory.year;


					}


					cout << "\n";
					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tEnter Ph Level Of Water in integer :";				//int
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t" << Inventory.phlevelwater;

					}



					cout << "\n";
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tWater Density (use this unit 1g/cc) :";					//ss
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t" << Inventory.waterdensity;


					cout << "\n";

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tClearity of Water :";				//string
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.clearityofwater;


					cout << "\n";

					{


						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tPlease enter the temperature :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t" << Inventory.temp;

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n";
						cout << "\tPlease enter the measurement system (c or f) :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t" << Inventory.unit;



					}


					cout << "\n";

					{
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tOxygen Quantity :";
						cout << "\n\t\t\t 1) GOOD";
						cout << "\n\t\t\t 2) BAD";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Oxygen;

					}




					{
						cout << "\n";
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n\tOrganic Materials in Water :";			//string
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t" << Inventory.OrganicMaterials;


					}





					cout << "\n";

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tRemark of Water :";			//string
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t" << Inventory.Remarkofwater;


					}
				}


				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\n\tEnter specific number to update record\n" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << " * 0 * Update Information " << endl;
				cout << " * 1 * Return" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\nEnter your selection :";
				char choice;
				cin >> choice;
				switch (choice)

				{


				InvoiceInformation:
				case '1': system("pause");
					system("cls");
					goto mainmenu;
					break;

				case '0':
					cout << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n--------------------------------------------------------------------------------\n";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "a) Cause of water Pollution" << endl;
					cout << "b) Year" << endl;
					cout << "C) Ph Level Water" << endl;
					cout << "d) Water density" << endl;
					cout << "e) Clearity of Water" << endl;
					cout << "f) Temperature" << endl;
					cout << "g) Oxygen" << endl;
					cout << "h) Organic Materials" << endl;
					cout << "i) Remark of water" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "Enter ur selection :";
					char XXXXX;
					cin >> XXXXX;
					cout << endl;
					switch (XXXXX)
					{
					case 'a': system("cls");

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tCause of Pollution :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t";
						getchar();
						getline(cin, Inventory.causeofwaterpollution);
						while (Inventory.causeofwaterpollution.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "========ERROR===================================================";
							cout << "\n\t Invalid Input! Please Enter In A Valid Pollution!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tCause of Pollution :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							getline(cin, Inventory.causeofwaterpollution);
						}

					}

					cout << "\n";

					system("pause");
					system("cls");
					goto updatefile;
					break;


					case 'b': system("cls");

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tYear :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
						getchar();
						getline(cin, Inventory.year);
						while (Inventory.year.find_first_of("0123456789") == string::npos)
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "========ERROR===================================================";
							cout << "\n\t Invalid Input! Please Enter In A Valid Year!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tYear :";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t\t\t";
							getline(cin, Inventory.year);
						}

					}


					cout << "\n";

					cout << endl;


					system("pause");
					system("cls");
					goto updatefile;
					break;


					case 'c': system("pause");
						system("cls");
						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tEnter Ph Level Of Water in integer :";				//int
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t";
							cin >> Inventory.phlevelwater;
							if (Inventory.phlevelwater >= 7.0)
							{

								if (Inventory.phlevelwater == 7.0)
								{
									SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
									cout << "\n\t\tPh Level is Neutral";
									cout << "\n";
								}

								else
								{
									SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
									cout << "\n\t\tPh Level is Alkaline";
									cout << "\n";
								}
							}
							else
							{
								SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								cout << "\n\t\tPh Level is Acidic";
								cout << "\n";
							}
						}


						system("cls");
						goto updatefile;
						break;

					case 'd': system("cls");

						cout << "\n";
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tWater Density (use this unit 1g/cc) :";					//ss
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t";
						cin >> Inventory.waterdensity;

						system("pause");
						system("cls");
						goto updatefile;
						break;




					case 'e': system("cls");

						cout << "\n";

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tClearity of Water :";				//string
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t";
						cin >> Inventory.clearityofwater;

						cout << "\n";

						system("pause");
						system("cls");
						goto updatefile;
						break;

					case 'f': system("cls");

					{


						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tPlease enter the temperature :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t";
						cin >> Inventory.temp;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n";
						cout << "\tPlease enter the measurement system (c or f) :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t";
						cin >> Inventory.unit;

						if (isupper(Inventory.unit))
						{
							Inventory.unit = tolower(Inventory.unit);
						}

						if (Inventory.unit == 'f')
						{
							Inventory.temp = (Inventory.temp - 32) / 9.0 * 5.0;
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\n\tWater is " << Inventory.temp << " degrees Fahrenheit\n";
						}
						else if (Inventory.unit == 'c')
						{
							Inventory.temp = 9.0 / 5.0 * Inventory.temp + 32;
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\n\tWater is " << Inventory.temp << " degrees Celsius\n";
						}
						else
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "\n\tSorry that unit of measuring water isn't recognized around here.\n";

						}
					}

					system("pause");
					system("cls");
					goto updatefile;
					break;



					case 'g': system("cls");

						cout << "\n";

						{
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tOxygen Quantity :";
							cout << "\n\t\t\t 1) GOOD";
							cout << "\n\t\t\t 2) BAD";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							cin >> Inventory.Oxygen;
							if (Inventory.Oxygen == "1")
							{
								SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								cout << "\n";
								cout << "\tOxygen Quantity is Good for drinking.";
							}
							else if (Inventory.Oxygen == "2")
							{
								SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								cout << "\n";
								cout << "\tOxygen Quantity is Bad for drinking.";
							}
							else
							{
								SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
								cout << "\n\tInvalid Input.\n";

							}
						}

						system("pause");
						system("cls");
						goto updatefile;
						break;


					case 'h': system("cls");

					{
						cout << "\n";
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n\tOrganic Materials in Water :";			//string
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t";
						getchar();
						getline(cin, Inventory.OrganicMaterials);
						while (Inventory.OrganicMaterials.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "========ERROR===================================================";
							cout << "\n\t Invalid Input! Please Enter In valid Organic Materials in Water!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n\tOrganic Materials in Water :";			//string
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t";
							getline(cin, Inventory.OrganicMaterials);
						}

					}





					cout << "\n";



					system("pause");
					system("cls");
					goto updatefile;
					break;



					case 'i': system("cls");

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\tRemark of Water :";			//string
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\t\t\t\t\t\t\t\t\t\t";
						getchar();
						getline(cin, Inventory.Remarkofwater);
						while (Inventory.Remarkofwater.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "========ERROR===================================================";
							cout << "\n\t Invalid Input! Please Enter In A Valid Remark!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\tRemark of Water :";			//string
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\t\t\t\t\t\t\t\t\t\t";
							getline(cin, Inventory.Remarkofwater);
						}

					}




					cout << "\n";

					system("pause");
					system("cls");
					goto updatefile;
					break;






					default:system("pause");
						system("cls");
						goto InvoiceInformation;
						break;

					}
					break;


				}

			updatefile:

				fs->seekp(sizeof(Inventory) * recs_num, ios::beg); // go to the first of the record to be modified
				fs->write((char*)&Inventory, sizeof(Inventory));
				closeFile(fs);
				system("cls");
				goto UpdateList;

			}

			cout << "\n To return to menu, ";
			system("pause");
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "==============================================================================================================================================" << endl;

			closeFile(fs);
			goto mainmenu;
			break;


		case '6': // Exit


			system("cls");

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << "\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t #		Exit System?              		#" << endl;
			cout << "\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t #							#" << endl;
			cout << "\t\t\t\t\t\t\t\t ########################################################" << endl;
			cout << endl;
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n----------[ EXIT ]--------------------------------------------------------------------------------------\n";
			cout << "Instruction = Input 1 to Exit System and Input other key to return mainmenu";
			cout << "\nInput = ";
			cin >> Inventory.Enter;

			while (true)

				if (Inventory.Enter == 1)
				{
					goto t;

				}

				else
				{

					goto mainmenu;

				}
		t:





			if (deletion) // if there is any deletion, then update database file (create a new temp file that doesn't have deleted records, then remove the old database file and rename temp file to database file name)

			{

				cout << "\n Updating '" << INVENTORY_FILE_NAME << "' File..." << endl;
				fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::binary);

				if (!fs)

				{

					cout << "\n Can't open '" << INVENTORY_FILE_NAME << "' file, then Updating is incomplete." << endl;
					system("pause");

					system("cls");
					return 1;

				}

				fs1 = new fstream("temp", ios::out | ios::binary);
				{

					cout << "\nUpdating database file completed." << endl;
					system("pause");
					goto B;

				}

				//while nondeleted records to the temp file
				while (fs->read((char *)&Inventory, sizeof(Inventory)))

					if (!Inventory.deleted)
						fs->write((char *)&Inventory, sizeof(Inventory));

				closeFile(fs);
				closeFile(fs1);


				if (remove(INVENTORY_FILE_NAME) == -1) // if there is an error
				{

					cout << "\nCan't delete  " << INVENTORY_FILE_NAME << "file, then updating is incomplete." << endl;
					system("pause");

					system("cls");
					return 1;

				}

				struct stat st; // to check size of the temp file
				int res = stat("temp", &st);
				if (st.st_size == 0) // if all of records are deleted then the temp file size is zero                       
					remove("temp"); // we have no records, then no database file is needed, just delete the temp file

				else
					if (rename("temp", INVENTORY_FILE_NAME))

					{
						cout << "\nCan't create temps file, then updating is incomplete." << endl;
						system("pause");

						closeFile(fs);
						system("cls");
						return 1;

					}

				cout << "\n Can't rename temp file, then Updating is incomplete." << endl;
				system("pause");



				system("cls");
				return 1;

			}
		B:

			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			//Exit Splash Screen
			cout << "\n";
			cout << "\n";
			cout << "\t" << endl;
			cout << "\t                                                                                                            " << endl;
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t                           Thank you for using this system                         " << endl;
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t                                It will log out now                                    " << endl;
			Inventory.timer(2);
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t												2				                               " << endl;
			Inventory.timer(2);
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t												1			                                      " << endl;
			Inventory.timer(2);
			cout << "\t                                                                         " << endl;
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
			cout << "\t You have successfully logged out. Thank you :]";

			int totalSeconds = time(0);
			int currentSecond = totalSeconds % 60;
			int totalMinutes = totalSeconds / 60;
			int currentMinute = totalMinutes % 60;
			long totalHours = totalMinutes / 60;
			int currentHour = (int)(totalHours % 24);


			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\n\n\tLog Out time is " << currentHour + 8 << ":" << currentMinute << ":" << currentSecond << "GMT" << endl;
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

			system("pause");

			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);
			system("color 01");
			Inventory.timer(1);
			system("color 02");
			Inventory.timer(1);
			system("color 03");
			Inventory.timer(1);
			system("color 04");
			Inventory.timer(1);
			system("color 05");
			Inventory.timer(1);
			system("color 06");
			Inventory.timer(1);
			system("color 07");
			Inventory.timer(1);
			system("color 08");
			Inventory.timer(1);
			system("color 09");
			Inventory.timer(1);
			system("color 0A");
			Inventory.timer(1);
			system("color 0B");
			Inventory.timer(1);
			system("color 0C");
			Inventory.timer(1);
			system("color 0D");
			Inventory.timer(1);
			system("color 0E");
			Inventory.timer(1);
			system("color 0F");
			Inventory.timer(1);


			system("cls");
			goto A;


		}// end 'switch'

	} // end 'while'

	return 0;

}
// end 'main()'

/////////////     Function Definitions    /////////////


void closeFile(fstream *fs)

{
	fs->close(); // close the file
	delete fs;
	fs = NULL;
}



bool isFileExist(const char * file_name)
{
	struct stat st; // to check status of file
	int res = stat(file_name, &st);
	return (res == 0); // if file exists    
}
