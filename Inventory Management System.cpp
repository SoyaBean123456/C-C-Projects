
/*
//// Last Build : 8_19_08
//// Compiler   : VS2015
//// Programmer : Yeo Yee Wen
//// Capability : Implementing a variable size record.
//// Function   : add, delete, search, display records ( hourly or salaried )
*/




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
# pragma warning(disable : 4996)

using namespace std;




HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);



/////////////     Data types    /////////////
int invoiceid = 1000;
int searchinvoiceid;


// Function Modules



struct Inventory_Record // Inventory record

{
	int invoiceid = 0;
	int Type_Categories;
	string Product_Name;
	int Product_Categories;
	string Product_Selection;
	int i;
	int numberofproductstoInput;
	int no_productinput;
	string Name;
	string SecondName[12];
	string ThirdName[12];
	string ForthName[12];
	string fifthname[12];
	string IC_Number;
	string SecondIC_Number[12];
	int State_no;
	int now_year, birth_year;
	string Age_no;
	int Age;
	int SecondAge[12];
	string Gender_no;
	string Gender;
	string SecondGender[12];
	string State;
	string SecondState[12];
	string Phone_Number;
	string SecondPhone_Number[12];
	string choice;
	string username;
	string password;
	string Receiveddate;
	int y = 1;
	string Product_Type;
	string Supplier;
	int Price;
	string save_delete;
	int Enter;
	void timer(int sec)

	{

		Sleep(sec * 10);

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
	input >> invoiceid;
	ofstream output;
	char date[10];
	_strdate(date);
	int recs_num;






	system("cls");
	cout << "\n";
	cout << "\n";
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "################################################################################" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "												" << endl;
	cout << "												" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "				Welcome To 7 						" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "			Eleven Inventory Management System " << endl;
	cout << "												" << endl;
	cout << "												" << endl;
	cout << "												" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << "################################################################################" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
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

A:






	system("cls");
	SetConsoleTextAttribute(y, 0);
	cout << "\n";
	cout << "\n";
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\t#################################################################" << endl;
	cout << "\t #																		#" << endl;
	cout << "\t #																		#" << endl;
	cout << "\t #				LOG IN 														#" << endl;
	cout << "\t #																		#" << endl;
	cout << "\t #																		#" << endl;
	cout << "\t#################################################################" << endl;
	cout << "\n" << endl;
	cout << "\n" << endl;







	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n1)\t LOG IN" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n2)\t EXIT" << endl;
	cout << endl;
	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED);
	cout << "\n\t PLEASE ENTER YOUR CHOICE: \t";
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
		cout << "\t InCORRECT! Please Enter Again!" << endl;
		SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n\t PLEASE ENTER YOUR choice :\t";
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
			cout << "\t#################################################################" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #		LOG IN BY KEYING USERMANE AND PASSWORD		#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t#################################################################" << endl;
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
		cout << "\t" << endl;
		cout << "\t                                                                                                            " << endl;
		cout << "\t                             This Inventory system                         " << endl;
		cout << "\t                                is created  by                                       " << endl;
		cout << "\t                                Mr. Yeo Yee Wen                               " << endl;
		cout << "\t                                    TQ for using                                      " << endl;
		cout << "\t                                                                         " << endl;
		cout << "\t\t Goodbye ^_^";



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
			cout << "\t#################################################################" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #			MAIN MENU 														#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t #																		#" << endl;
			cout << "\t#################################################################" << endl;
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
			cout << "--------------------------------------------------------------------------------\n\n";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\t\t  THIS IS 7 ELEVEN (SEREMBAN BRANCH)\n\t\t\tINVENTORY MANAGEMENT SYSTEM  \n\n";

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t(1) Add a new Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t\t\t(2) Search an existing Record\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t(3) Delete an existing Record \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t(4) Display Records \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t\t\t(5) Update Records \n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t\t\t(6) Exit \n\n";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "    \t\tEnter a choice (1-6) :\t\t\t\t\t\t " << flush;
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
			cout << "\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t *			Input  1 to continue												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *				OR													*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *			any	       key												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *		  to go back to the main menu												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
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

			Inventory.invoiceid = ++invoiceid;
			cout << "\t\t\t\n\t\t Invoice ID :" << Inventory.invoiceid << endl;
			if (output.open("ID.txt"), ios::out)//create"id.txt"to store id
			{
				output << invoiceid;
			}
			else cout << "the file is empty.";
			output.close();






			system("cls"); // clear screen
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n----------[ ADD RECORD ]-------------------------------------------------------\n";
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\t\t\t Invoice ID :" << Inventory.invoiceid << endl;


		SUPPLIER:

			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "1)Supplier\t\t : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				getchar();
				getline(cin, Inventory.Supplier);
				while (Inventory.Supplier.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Supplier!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n1)Supplier\t\t :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					getline(cin, Inventory.Supplier);
				}

			}

			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n2)Receive Date \t\t : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				getline(cin, Inventory.Receiveddate);

				while (Inventory.Receiveddate.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Date!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "2)Receive Date     \t   : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Receiveddate;
				}
			}

			cout << endl;

			goto RECEIVER;




		RECEIVER:



			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "--------------------------------------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\tPlease enter Receiver Details" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n1)Product Receiver       : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> Inventory.Name;

				while (Inventory.Name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Receiver!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n1)Product Receiver        : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Name;
				}






				Inventory.SecondName[Inventory.i] = Inventory.Name;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "2)Product Receiver IC    : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> Inventory.IC_Number;

				while ((Inventory.IC_Number.find_first_of("1234567890") == string::npos) || (Inventory.IC_Number.size() != 12))
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid input!Please Enter Your Receiver IC Again!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n2)Product Receiver IC     : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.IC_Number;
				}







				Inventory.SecondIC_Number[Inventory.i] = Inventory.IC_Number;
				Inventory.now_year = 1900 + ltm->tm_year;
				Inventory.Age_no = Inventory.IC_Number.substr(0, 2);
				Inventory.birth_year = stoi(Inventory.Age_no);
				if (Inventory.now_year - (2000 + Inventory.birth_year) < 0 && Inventory.birth_year > (2000 - Inventory.now_year))
				{
					Inventory.Age = Inventory.now_year - (Inventory.birth_year + 1900);
				}
				else
				{
					Inventory.Age = Inventory.now_year - (Inventory.birth_year + 2000);
				}
				Inventory.SecondAge[Inventory.i] = Inventory.Age;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n3) Age    \t         : " << Inventory.SecondAge[Inventory.i] << endl;
				Inventory.State_no = stoi(Inventory.IC_Number.substr(6, 2));
				switch (Inventory.State_no)
				{
				case 1:

					Inventory.State = "Johor";
					break;

				case 2:

					Inventory.State = "Kedah";
					break;

				case 3:

					Inventory.State = "Kelantan";
					break;

				case 4:

					Inventory.State = "Malacca";
					break;

				case 5:

					Inventory.State = "Negeri Sembilan";
					break;

				case 6:

					Inventory.State = "Pahang";
					break;

				case 7:

					Inventory.State = "Penang";
					break;

				case 8:

					Inventory.State = "Perak";
					break;

				case 9:

					Inventory.State = "Perlis";
					break;

				case 10:

					Inventory.State = "Selangor";
					break;

				case 11:

					Inventory.State = "Terengganu";
					break;

				case 12:

					Inventory.State = "Sabah";
					break;

				case 13:

					Inventory.State = "Sarawak";
					break;

				case 14:

					Inventory.State = "Federal Territory of Kuala Lumpur";
					break;

				case 15:

					Inventory.State = "Federal Territory of Labuan";
					break;

				case 16:

					Inventory.State = "Federal Territory of Putrajaya";
					break;

				default:

					Inventory.State = "N/A";
				}
				Inventory.SecondState[Inventory.i] = Inventory.State;
				cout << "4) State      \t\t : " << Inventory.SecondState[Inventory.i] << endl;
				Inventory.Gender_no = Inventory.IC_Number.substr(11, 1);
				if (stoi(Inventory.Gender_no) % 2 == 0)
					Inventory.Gender = "Female";
				else
					Inventory.Gender = "Male";
				Inventory.SecondGender[Inventory.i] = Inventory.Gender;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "5) Gender     \t\t : " << Inventory.SecondGender[Inventory.i] << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);






				cout << "\n6) Phone number \t : ";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> Inventory.Phone_Number;


				while ((Inventory.Phone_Number.find_first_of("1234567890") == string::npos) || (Inventory.Phone_Number.size() != 10))
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid input!Please Enter Your Phone Number Again!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n6)Phone Number \t\t :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Phone_Number;

				}
				Inventory.SecondPhone_Number[Inventory.i] = Inventory.Phone_Number;
			}




			goto Section;


		Section:

			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\nSELECT PRODUCT CATEGORIES" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n1)\t Mobile Recharges " << endl;
			cout << "\n2)\t Stationaries And Gifts" << endl;
			cout << "\n3)\t Newspapers And Magazines" << endl;
			cout << "\n4)\t Game Cards" << endl;
			cout << "\n5)\t Cigarrettes" << endl;
			cout << "\n6)\t Utilities" << endl;
			cout << "\n7)\t Food" << endl;
			cout << "\n8)\t Beverage" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\nSelection :\t";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Inventory.Product_Categories;

			while (true)
			{
				if (Inventory.Product_Categories == 1)
				{
					cout << "Good Job!!! Your Selection is Mobile Recharges.";
					break;
				}

				if (Inventory.Product_Categories == 2)
				{
					cout << "Good Job!!! Your Selection is Stationaries And Gifts.";
					break;
				}

				if (Inventory.Product_Categories == 3)
				{
					cout << "Good Job!!! Your Selection is Newspapers And Magazines.";
					break;
				}

				if (Inventory.Product_Categories == 4)
				{
					cout << "Good Job!!! Your Selection is Game Cards.";
					break;
				}

				if (Inventory.Product_Categories == 5)
				{
					cout << "Good Job!!! Your Selection is Cigarrettes.";
					break;
				}

				if (Inventory.Product_Categories == 6)
				{
					cout << "Good Job!!! Your Selection is Utilities.";
					break;
				}
				if (Inventory.Product_Categories == 7)
				{
					cout << "Good Job!!! Your Selection is Food.";
					break;
				}
				if (Inventory.Product_Categories == 8)
				{
					cout << "Good Job!!! Your Selection is Beverage.";
					break;
				}

				else
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\t\t\nInvalid Selection. Please Select Again.\n";
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "SELECT PRODUCT CATEGORIES" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n1)\t Mobile Recharges " << endl;
					cout << "\n2)\t Stationaries And Gifts" << endl;
					cout << "\n3)\t Newspapers And Magazines" << endl;
					cout << "\n4)\t Game Cards" << endl;
					cout << "\n5)\t Cigarrettes" << endl;
					cout << "\n6)\t Utilities" << endl;
					cout << "\n7)\t Food" << endl;
					cout << "\n8)\t Beverage" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\nSelection :\t";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Product_Categories;
				}
			}





			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\n\n\t\tPlease enter Product Quantity" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		InventoryInfo:
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\tQuantity of data to input = 1 to 10" << endl;
			cout << "Input to store :\t";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Inventory.numberofproductstoInput;
			switch (Inventory.numberofproductstoInput)
			{
			case 1: Inventory.no_productinput = 1; break;
			case 2: Inventory.no_productinput = 2; break;
			case 3: Inventory.no_productinput = 3; break;
			case 4: Inventory.no_productinput = 4; break;
			case 5: Inventory.no_productinput = 5; break;
			case 6: Inventory.no_productinput = 6; break;
			case 7: Inventory.no_productinput = 7; break;
			case 8: Inventory.no_productinput = 8; break;
			case 9: Inventory.no_productinput = 9; break;
			case 10: Inventory.no_productinput = 10; break;
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "--------------------------------------------------------------------------------\n";
				cout << "========ERROR===================================================";
			default: cout << "Number of data you can choose to input must be between 1 to 10!! " << endl; goto InventoryInfo;
			}
			cout << endl;
			if (Inventory.no_productinput >= 1 && Inventory.no_productinput <= 10)
			{
				goto PRODUCT;
			}
			else
			{
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "========ERROR===================================================";
				cout << "Sorry , the quantity you wish to input is not valid." << endl;
				goto InventoryInfo;

			}






		PRODUCT:

			for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)

			{

				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << " Please enter Product " << Inventory.i + 1 << " information" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "1) Product Name           : ";
				cin.get();
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				getline(cin, Inventory.Product_Name);

				while (Inventory.Product_Name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "========ERROR===================================================";
					cout << "\n\t Invalid Input! Please Enter In A Valid Name!" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "1) Name         : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					getline(cin, Inventory.Product_Name);
				}

				Inventory.ThirdName[Inventory.i] = Inventory.Product_Name;






				{
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "2) Product Type           : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					getline(cin, Inventory.Product_Type);

					while (Inventory.Product_Type.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << "========ERROR===================================================";
						cout << "\n\t Invalid Input! Please Enter In A Valid Type!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "2) Type         : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						getline(cin, Inventory.Product_Type);
					}
					Inventory.ForthName[Inventory.i] = Inventory.Product_Type;







					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "3) Enter price\t\t  : RM";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Price;

					while (true)
					{
						if ((Inventory.Price >= 1) && (Inventory.Price <= 9999999999)) {
							break;
						}
						else
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							cout << "========ERROR===================================================";
							cout << "\n\t Invalid Price! The range is from RM 1 to RM9999999999!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "3) Enter price\t\t  : RM";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cin >> Inventory.Price;
						}
					}



				}
			}




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



				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\nKEY IN BY      : Yeo SoYa";
				getline(cin, Inventory.keyinby);
				cout << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\nREMARK         :";
				getline(cin, Inventory.remark);
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

				system("pause");
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				break;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);



			}

			if (confirm == '2')

			{


				cout << " \n Record not added." << endl;
				system("pause");
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);	SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				break;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


			}

			if (confirm == '3')

			{



				fs->write((char *)&Inventory, sizeof(Inventory));
				closeFile(fs);
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "===============================================================================" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
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
			cout << "\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t *			Input  1 to continue												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *				OR													*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *			any	       key												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *		  to go back to the main menu												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
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
			cout << "\t ########################################################" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #		Search an Existing Record												#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t ########################################################" << endl;
			cout << endl;

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Invoice ID that you want to search: ";
			cin >> searchinvoiceid;
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
				if (searchinvoiceid == Inventory.invoiceid && !Inventory.deleted)
					break;

			}

			if (fs->eof())

			{
				cout << "The specific Invoice  does not exist in file." << endl;
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;
			}
			fs->seekp(sizeof(Inventory) * recs_num, ios::beg);
			fs->read((char*)&Inventory, sizeof(Inventory));

			if (!Inventory.deleted)




			{

				system("cls"); // clear screen

				cout << "\n----------[ SEARCHED RECORD ]---------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\t Invoice ID :" << Inventory.invoiceid << endl;


				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n1)Supplier\t\t :" << Inventory.Supplier;


				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n2)Receive Date \t\t :" << Inventory.Receiveddate;
				cout << endl;


				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\tPlease enter Receiver Details" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n1)Product Receiver       : " << Inventory.Name;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n2)Product Receiver IC    : " << Inventory.IC_Number;
				Inventory.SecondAge[Inventory.i] = Inventory.Age;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n3) Age    \t         : " << Inventory.SecondAge[Inventory.i] << endl;
				Inventory.SecondState[Inventory.i] = Inventory.State;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "4) State      \t\t : " << Inventory.SecondState[Inventory.i] << endl;
				Inventory.SecondGender[Inventory.i] = Inventory.Gender;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "5) Gender     \t\t : " << Inventory.SecondGender[Inventory.i] << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n6) Phone number \t : " << Inventory.Phone_Number;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);




				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\t\tSELECT PRODUCT CATEGORIES" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\n1)\t Mobile Recharges " << endl;
				cout << "\n2)\t Stationaries And Gifts" << endl;
				cout << "\n3)\t Newspapers And Magazines" << endl;
				cout << "\n4)\t Game Cards" << endl;
				cout << "\n5)\t Cigarrettes" << endl;
				cout << "\n6)\t Utilities" << endl;
				cout << "\n7)\t Food" << endl;
				cout << "\n8)\t Beverage" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\nSelection :\t" << Inventory.Product_Categories;



				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\t Product Quantity" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);


				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\tQuantity of data to input = 1 to 10" << endl;
				cout << "Input to store :\t" << Inventory.numberofproductstoInput;


				for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)
				{
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

					cout << "\n\tPlease enter Product " << Inventory.i + 1 << " information" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "1) Product Name           : " << Inventory.Product_Name;


					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n2) Product Type           : " << Inventory.Product_Type;

						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n3) Enter price\t\t  : RM" << Inventory.Price;

						}

					}

				}

				cout << "\n\n" << endl;

			}



			cout << "\n To return to menu,";
			cout << "\n Record is searched." << endl;
			system("pause");

			goto mainmenu;
			break;

		case '3': ////// Delete Record //////




			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t *			Input  1 to continue												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *				OR													*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *			any	       key												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *		  to go back to the main menu												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
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
			cout << "\t ########################################################" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #		Delete an Existing Record												#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t ########################################################" << endl;
			cout << endl;


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Invoice ID, for deletion : ";
			cin >> searchinvoiceid;
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
				if (Inventory.invoiceid == searchinvoiceid && !Inventory.deleted)
					break;
			}

			if (fs->eof())
			{
				cout << "The specific invoice does not exist in file." << endl;
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
			cout << "\t\t Invoice ID :" << Inventory.invoiceid << endl;




			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n1)Supplier\t\t :" << Inventory.Supplier;


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n2)Receive Date \t\t :" << Inventory.Receiveddate;
			cout << endl;


			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\tPlease enter Receiver Details" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n1)Product Receiver       : " << Inventory.Name;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n2)Product Receiver IC    : " << Inventory.IC_Number;
			Inventory.SecondAge[Inventory.i] = Inventory.Age;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n3) Age    \t         : " << Inventory.SecondAge[Inventory.i] << endl;
			Inventory.SecondState[Inventory.i] = Inventory.State;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "4) State      \t\t : " << Inventory.SecondState[Inventory.i] << endl;
			Inventory.SecondGender[Inventory.i] = Inventory.Gender;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "5) Gender     \t\t : " << Inventory.SecondGender[Inventory.i] << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n6) Phone number \t : " << Inventory.Phone_Number;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);




			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\n\t\tSELECT PRODUCT CATEGORIES" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n1)\t Mobile Recharges " << endl;
			cout << "\n2)\t Stationaries And Gifts" << endl;
			cout << "\n3)\t Newspapers And Magazines" << endl;
			cout << "\n4)\t Game Cards" << endl;
			cout << "\n5)\t Cigarrettes" << endl;
			cout << "\n6)\t Utilities" << endl;
			cout << "\n7)\t Food" << endl;
			cout << "\n8)\t Beverage" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\nSelection :\t" << Inventory.Product_Categories;



			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\t Product Quantity" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);


			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\t\tQuantity of data to input = 1 to 10" << endl;
			cout << "Input to store :\t" << Inventory.numberofproductstoInput;


			for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)
			{
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

				cout << "\n\tPlease enter Product " << Inventory.i + 1 << " information" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "1) Product Name           : " << Inventory.Product_Name;


				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n2) Product Type           : " << Inventory.Product_Type;

					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n3) Enter price\t\t  : RM" << Inventory.Price;

					}

				}

			}

			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\n\n\t\t\t The Following Record is deleted." << endl;
			system("pause");

			break;


		case '4': // Display Records



			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t *			Input  1 to continue												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *				OR													*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *			any	       key												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *		  to go back to the main menu												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
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
			cout << "\n----------[ DISPLAY RECORDS ]---------------------------------------------------\n";


			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ########################################################" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #		Display all Records												        #" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t ########################################################" << endl;
			cout << endl;


			system("pause");



			fs = new fstream(INVENTORY_FILE_NAME, ios::in | ios::binary);

			if (!fs)
			{
				cout << "\n Can't open or create '" << INVENTORY_FILE_NAME << " file." << endl;
				system("pause");
				break;
			}


			while (fs->read((char *)&Inventory, sizeof(Inventory))) // display records
			{
				if (!Inventory.deleted)
				{


					cout << "\n----------[ DISPLAYED RECORDS ]--------------------------------------------------\n";
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\t\t Invoice ID :" << Inventory.invoiceid << endl;



					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n1)Supplier\t\t :" << Inventory.Supplier;


					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n2)Receive Date \t\t :" << Inventory.Receiveddate;
					cout << endl;


					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\t\tPlease enter Receiver Details" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n1)Product Receiver       : " << Inventory.Name;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n2)Product Receiver IC    : " << Inventory.IC_Number;
					Inventory.SecondAge[Inventory.i] = Inventory.Age;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n3) Age    \t         : " << Inventory.SecondAge[Inventory.i] << endl;
					Inventory.SecondState[Inventory.i] = Inventory.State;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "4) State      \t\t : " << Inventory.SecondState[Inventory.i] << endl;
					Inventory.SecondGender[Inventory.i] = Inventory.Gender;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "5) Gender     \t\t : " << Inventory.SecondGender[Inventory.i] << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n6) Phone number \t : " << Inventory.Phone_Number;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);




					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\n\t\tSELECT PRODUCT CATEGORIES" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n1)\t Mobile Recharges " << endl;
					cout << "\n2)\t Stationaries And Gifts" << endl;
					cout << "\n3)\t Newspapers And Magazines" << endl;
					cout << "\n4)\t Game Cards" << endl;
					cout << "\n5)\t Cigarrettes" << endl;
					cout << "\n6)\t Utilities" << endl;
					cout << "\n7)\t Food" << endl;
					cout << "\n8)\t Beverage" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\nSelection :\t" << Inventory.Product_Categories;



					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\t\t Product Quantity" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);


					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "\t\tQuantity of data to input = 1 to 10" << endl;
					cout << "Input to store :\t" << Inventory.numberofproductstoInput;


					for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)
					{
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

						cout << "\n\tPlease enter Product " << Inventory.i + 1 << " information" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "1) Product Name           : " << Inventory.Product_Name;


						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n2) Product Type           : " << Inventory.Product_Type;

							{

								SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
								cout << "\n3) Enter price\t\t  : RM" << Inventory.Price;

							}

						}



						cout << "\n\n\n\n\n\n\n" << endl;

					}

				}

				cout << "\n To return to menu, ";
				system("pause");
				closeFile(fs);
				goto mainmenu;
				break;




		case '5': ////// Update Record //////




			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			cout << "\t *			Input  1 to continue												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *				OR													*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *			any	       key												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "\t *		  to go back to the main menu												*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "\t *																	*" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ********************************************************" << endl;
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
			cout << "\t ########################################################" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #		Update an Existing Record												#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t #																	#" << endl;
			cout << "\t ########################################################" << endl;
			cout << endl;



			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\n Enter Invoice ID to update : ";
			cin >> searchinvoiceid;
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
				if (Inventory.invoiceid == searchinvoiceid && !Inventory.deleted) //if user delete an Invoice then added another one with the same Name in the same
																				  //instance of program runs, delete Invoice is still there, then we should go through all the file

					break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{

				cout << "\n Your specified Invoice ID doesn't exist in file." << endl;
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;

			}

			fs->seekp(sizeof(Inventory)*recs_num, ios::beg);//go to searched record
			fs->read((char*)&Inventory, sizeof(Inventory));//display the seached record
			if (!Inventory.deleted)

			{

			UpdateList:



				system("cls");
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
				system("cls"); // clear screen

				cout << "\n----------[ UPDATE RECORD ]-----------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\t\tInvoice ID :" << Inventory.invoiceid << endl;




				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n1)Supplier\t\t :" << Inventory.Supplier;


				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n2)Receive Date \t\t :" << Inventory.Receiveddate;
				cout << endl;


				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\t\tPlease enter Receiver Details" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n1)Product Receiver       : " << Inventory.Name;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n2)Product Receiver IC    : " << Inventory.IC_Number;
				Inventory.SecondAge[Inventory.i] = Inventory.Age;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n3) Age    \t         : " << Inventory.SecondAge[Inventory.i] << endl;
				Inventory.SecondState[Inventory.i] = Inventory.State;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "4) State      \t\t : " << Inventory.SecondState[Inventory.i] << endl;
				Inventory.SecondGender[Inventory.i] = Inventory.Gender;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "5) Gender     \t\t : " << Inventory.SecondGender[Inventory.i] << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n6) Phone number \t : " << Inventory.Phone_Number;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);




				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\n\t\tSELECT PRODUCT CATEGORIES" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\n1)\t Mobile Recharges " << endl;
				cout << "\n2)\t Stationaries And Gifts" << endl;
				cout << "\n3)\t Newspapers And Magazines" << endl;
				cout << "\n4)\t Game Cards" << endl;
				cout << "\n5)\t Cigarrettes" << endl;
				cout << "\n6)\t Utilities" << endl;
				cout << "\n7)\t Food" << endl;
				cout << "\n8)\t Beverage" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\nSelection :\t" << Inventory.Product_Categories;



				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\n\t\tProduct Quantity\n" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);


				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\t\tQuantity of data to input = 1 to 10\n" << endl;
				cout << "\t\tInput to store :\t" << Inventory.numberofproductstoInput;


				for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)
				{
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

					cout << "\n\tPlease enter Product " << Inventory.i + 1 << " information" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "1) Product Name           : " << Inventory.Product_Name;


					{

						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n2) Product Type           : " << Inventory.Product_Type;

						{

							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\n3) Enter price\t\t  : RM" << Inventory.Price;

						}

					}

				}
			}


			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\tEnter specific number to update record\n" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " * 0 * Supplier Information " << endl;
			cout << " * 1 * Product information " << endl;
			cout << " * 2 * Receiver" << endl;
			cout << " * 3 * Return" << endl;
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			cout << "\nEnter your selection :";
			char choice;
			cin >> choice;
			switch (choice)

			{


			InvoiceInformation:
			case '3': system("pause");
				system("cls");
				goto mainmenu;
				break;

			case '0':
				cout << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n--------------------------------------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "a) Supplier" << endl;
				cout << "b) Received Date" << endl;
				cout << "C) Return" << endl;
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
					cout << "--------------------------------------------------------------------------------\n";
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n\n\tSupplier\t\t :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					getchar();
					getline(cin, Inventory.Supplier);
					while (Inventory.Supplier.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n\t Invalid Input! Please Enter In A Valid Date!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "\n\n\tSupplier\t\t :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						getline(cin, Inventory.Supplier);
					}

				}

				system("pause");
				system("cls");
				goto updatefile;
				break;


				case 'b': system("cls");

				{

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\tEnter Receive Date \t :";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin.get();
					getline(cin, Inventory.Receiveddate);
					while (Inventory.Receiveddate.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n\t Invalid Input! Please Enter In A Valid Date!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "1)\t Receive Date        : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						getline(cin, Inventory.Receiveddate);
					}
				}

				cout << endl;


				system("pause");
				system("cls");
				goto updatefile;
				break;


				case 'c': system("pause");
					system("cls");
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


					system("cls");
					goto updatefile;
					break;


				default:system("pause");
					system("cls");
					goto InvoiceInformation;
					break;

				}
				break;





			case '1': //Invoice information relating to product
				cout << endl;
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n--------------------------------------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "a) Product Name" << endl;
				cout << "b) Product Type" << endl;
				cout << "c) Product Price" << endl;
				cout << "d) Category Selection" << endl;
				cout << "e) Return" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "Enter ur selection :";
				char InvoiceInfo;
				cin >> InvoiceInfo;
				cout << endl;
				switch (InvoiceInfo)
				{
				case 'a': system("cls");


					for (Inventory.i = 0; Inventory.i < Inventory.no_productinput; Inventory.i++)
					{
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "--------------------------------------------------------------------------------\n";
						cout << " Please enter Product " << Inventory.i + 1 << " information" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "1)\t Product Name           : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cin.get();
						getline(cin, Inventory.Product_Name);


						while (Inventory.Product_Name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							"========ERROR===================================================\n";
							cout << "\n\t Invalid Input! Please Enter In A Valid Name!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "1)\t Name         : ";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							getline(cin, Inventory.Product_Name);
						}
						Inventory.ThirdName[Inventory.i] = Inventory.Product_Name;

						system("pause");
						system("cls");
						goto updatefile;
						break;

				case 'b': system("cls");
				{
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "1)\t Product Type           : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin.get();
					getline(cin, Inventory.Product_Type);


					while (Inventory.Product_Type.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n\t Invalid Input! Please Enter In A Valid Type!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "2)\t Type         : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						getline(cin, Inventory.Product_Type);
					}

					Inventory.ForthName[Inventory.i] = Inventory.Product_Type;

					system("pause");
					system("cls");
					goto updatefile;
					break;

				case 'c': system("cls");

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "3)\t Enter price\t\t: RM";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Price;

					while (true)
					{
						if ((Inventory.Price >= 1) && (Inventory.Price <= 9999999999)) {
							break;
						}
						else
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							"========ERROR===================================================\n";
							cout << "\n\t Invalid Price! The range is from RM 1 to RM9999999999!" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "3)\t Enter price\t\t: RM";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cin >> Inventory.Price;
						}
					}





				}

					}

					system("pause");
					system("cls");
					goto updatefile;
					break;


				case 'd': system("cls");
				SecondSection:
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\n--------------------------------------------------------------------------------\n";
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
					cout << "Selection Of Product Categories" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\n1)\t Mobile Recharges " << endl;
					cout << "\n2)\t Stationaries And Gifts" << endl;
					cout << "\n3)\t Newspapers And Magazines" << endl;
					cout << "\n4)\t Game Cards" << endl;
					cout << "\n5)\t Cigarrettes" << endl;
					cout << "\n6)\t Utilities" << endl;
					cout << "\n7)\t Food" << endl;
					cout << "\n8)\t Beverage" << endl;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "\nSelection :\t";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Product_Categories;

					while (true)
					{
						if (Inventory.Product_Categories == 1)
						{
							cout << "Good Job!!! Your Selection is Mobile Recharges.";
							break;
						}

						if (Inventory.Product_Categories == 2)
						{
							cout << "Good Job!!! Your Selection is Stationaries And Gifts.";
							break;
						}

						if (Inventory.Product_Categories == 3)
						{
							cout << "Good Job!!! Your Selection is Newspapers And Magazines.";
							break;
						}

						if (Inventory.Product_Categories == 4)
						{
							cout << "Good Job!!! Your Selection is Game Cards.";
							break;
						}

						if (Inventory.Product_Categories == 5)
						{
							cout << "Good Job!!! Your Selection is Cigarrettes.";
							break;
						}

						if (Inventory.Product_Categories == 6)
						{
							cout << "Good Job!!! Your Selection is Utilities.";
							break;
						}
						if (Inventory.Product_Categories == 7)
						{
							cout << "Good Job!!! Your Selection is Food.";
							break;
						}
						if (Inventory.Product_Categories == 8)
						{
							cout << "Good Job!!! Your Selection is Beverage.";
							break;
						}

						else
						{
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
							"========ERROR===================================================\n";
							cout << "\t\t\nInvalid Selection. Please Select Again.\n";
							SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
							cout << "Selection Of Product Categories" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cout << "\n1)\t Mobile Recharges " << endl;
							cout << "\n2)\t Stationaries And Gifts" << endl;
							cout << "\n3)\t Newspapers And Magazines" << endl;
							cout << "\n4)\t Game Cards" << endl;
							cout << "\n5)\t Cigarrettes" << endl;
							cout << "\n6)\t Utilities" << endl;
							cout << "\n7)\t Food" << endl;
							cout << "\n8)\t Beverage" << endl;
							SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							cout << "\nSelection :\t";
							SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							cin >> Inventory.Product_Categories;
						}
					}
					system("pause");
					system("cls");
					goto updatefile;
					break;

				case 'e': system("pause");


					system("cls");
					goto updatefile;
					break;


				default:system("pause");
					system("cls");
					goto InvoiceInformation;
					break;
				}

				break;


			case '2': //Inventory information

			InventoryInformation:
				SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				cout << "\n--------------------------------------------------------------------------------\n";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "Receiver details that need to update :";
				cout << "\na) Name";
				cout << "\nb) IC Number";
				cout << "\nc) Phone number";
				cout << "\nd) Return" << endl;
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
				cout << "\n\nEnter ur selection :";
				char InventoryInfo;
				cin >> InventoryInfo;
				cout << endl;
				switch (InventoryInfo)
				{

				case 'a':
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "Name         : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin.get();
					getline(cin, Inventory.Name);



					while (Inventory.Name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n Invalid Input! Please Enter In A Valid Name!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "Name         : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						getline(cin, Inventory.Name);
					}
					Inventory.SecondName[Inventory.i] = Inventory.Name;
					cout << endl;


					system("pause");
					system("cls");
					goto updatefile;
					break;



				case 'b':

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "IC Number    : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.IC_Number;
					//cin.ignore();


					while ((Inventory.IC_Number.find_first_of("1234567890") == string::npos) || (Inventory.IC_Number.size() != 12))
					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n Invalid input!Please Enter Your IC Number Again!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "IC Number    : ";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cin >> Inventory.IC_Number;
					}

					Inventory.SecondIC_Number[Inventory.i] = Inventory.IC_Number;
					Inventory.now_year = 1900 + ltm->tm_year;
					Inventory.Age_no = Inventory.IC_Number.substr(0, 2);
					Inventory.birth_year = stoi(Inventory.Age_no);
					if (Inventory.now_year - (2000 + Inventory.birth_year) < 0 && Inventory.birth_year > (2000 - Inventory.now_year))
					{
						Inventory.Age = Inventory.now_year - (Inventory.birth_year + 1900);

					}

					else

					{

						Inventory.Age = Inventory.now_year - (Inventory.birth_year + 2000);

					}

					Inventory.SecondAge[Inventory.i] = Inventory.Age;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "Age          : " << Inventory.SecondAge[Inventory.i] << endl;



					Inventory.State_no = stoi(Inventory.IC_Number.substr(6, 2));
					switch (Inventory.State_no)

					{

					case 1:

						Inventory.State = "Johor";
						break;

					case 2:

						Inventory.State = "Kedah";
						break;

					case 3:

						Inventory.State = "Kelantan";
						break;

					case 4:

						Inventory.State = "Malacca";
						break;

					case 5:

						Inventory.State = "Negeri Sembilan";
						break;

					case 6:

						Inventory.State = "Pahang";
						break;

					case 7:

						Inventory.State = "Penang";
						break;

					case 8:

						Inventory.State = "Perak";
						break;

					case 9:

						Inventory.State = "Perlis";
						break;

					case 10:

						Inventory.State = "Selangor";
						break;

					case 11:

						Inventory.State = "Terengganu";
						break;

					case 12:

						Inventory.State = "Sabah";
						break;

					case 13:

						Inventory.State = "Sarawak";
						break;

					case 14:

						Inventory.State = "Federal Territory of Kuala Lumpur";
						break;

					case 15:

						Inventory.State = "Federal Territory of Labuan";
						break;

					case 16:

						Inventory.State = "Federal Territory of Putrajaya";
						break;

					default:

						Inventory.State = "N/A";

					}

					Inventory.SecondState[Inventory.i] = Inventory.State;
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "State        : " << Inventory.SecondState[Inventory.i] << endl;


					Inventory.Gender_no = Inventory.IC_Number.substr(11, 1);
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					if (stoi(Inventory.Gender_no) % 2 == 0)
						Inventory.Gender = "Female";
					else
						Inventory.Gender = "Male";
					Inventory.SecondGender[Inventory.i] = Inventory.Gender;

					cout << "Gender       : " << Inventory.SecondGender[Inventory.i] << endl;

					system("pause");
					system("cls");
					goto updatefile;
					break;


				case 'c':

					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					cout << "6)\t Phone number : ";
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cin >> Inventory.Phone_Number;
					while ((Inventory.Phone_Number.find_first_of("1234567890") == string::npos) || (Inventory.Phone_Number.size() != 10))

					{
						SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
						"========ERROR===================================================\n";
						cout << "\n\t Invalid input!Please Enter Your Phone Number Again!" << endl;
						SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						cout << "6)\t Phone Number :";
						SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cin >> Inventory.Phone_Number;
					}

					Inventory.SecondPhone_Number[Inventory.i] = Inventory.Phone_Number;
					system("pause");
					system("cls");
					goto updatefile;
					break;




				case 'd':system("pause");
					system("cls");


					system("cls");
					goto updatefile;
					break;



				default:  system("pause");
					system("cls");
					goto InventoryInformation;
					break;

				}



				system("pause");
				system("cls");
				goto updatefile;
				break;

			}

		updatefile:

			fs->seekp(sizeof(Inventory) * recs_num, ios::beg); // go to the first of the record to be modified
			fs->write((char*)&Inventory, sizeof(Inventory));
			closeFile(fs);
			system("cls");
			goto UpdateList;

			}






		case '6': // Exit


			system("cls");

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "\t ########################################################" << endl;
			cout << "\t #																	 #" << endl;
			cout << "\t #																	 #" << endl;
			cout << "\t #		Exit System?              												#" << endl;
			cout << "\t #																	 #" << endl;
			cout << "\t #																	 #" << endl;
			cout << "\t ########################################################" << endl;
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


		} // end 'switch'

	} // end 'while'

	return 0;

} // end 'main()'

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
