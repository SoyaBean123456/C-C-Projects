/*
//// Last Build : 8_19_08
//// Compiler   : VS2015
//// Programmer : Tan Soon Jian
//// Capability : Implementing a variable size record.
//// Function   : add, delete, modify, display records
*/


/////////////     Includes    /////////////

#include <cstdlib> // system()
#include <conio.h> // getch()
#include <fstream>
#include <sys\stat.h> // stat(status of a file)
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

HANDLE y = GetStdHandle(STD_OUTPUT_HANDLE);

/////////////     Data types    /////////////

int employeeid = 1000;

struct Employee_Record // Employee record
{
	//Declare all variables after this line
	int employeeID;
	string employee_Name;
	string IC;
	int Date_of_birth;
	string gender;
	string phone_number;
	string E_Mail;
	string position;
	string address;
	double salary;
	string working_hours;
	string nationality;
	string month;
	string year;
	string date;
	int month_no;
	string year_no;
	int date_no;
	string gender_no;
	string choice;
	string username;
	string password;
	int y = 1;





	//dont touch after this line
	bool deleted;
};


/////////////     Variable Declarations & Constants /////////////

#define Employee_FILE_NAME "Employees.txt" // name of the database file to store Employees informations

Employee_Record Employee;
char     choice; // for choice in menu
fstream *fs = NULL, *fs1 = NULL;// file streams for files : fs -> 'Employee', fs1 -> 'temp'
bool     deletion = false; // if any record has been deleted


						   /////////////     Function Prototypes    /////////////

void closeFile(fstream *); // closes a file with its pointer, then deletes the file pointer
bool isFileExist(const char *); // check if a file exists


								/////////////     Main    /////////////
int main()
{
	ifstream input;
	input.open("id.txt"), ios::in;
	input >> Employee.employeeID;
	ofstream output;

	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\t\t EMPLOYEE REGISTRATION FOR MC DONALD FRANCHISE";
	SetConsoleTextAttribute(y, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n\n1)\t LOG IN" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n\n2)\t EXIT" << endl;
	SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t PLEASE ENTER YOUR CHOICE:";
	SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cin >> Employee.choice;
	cout << endl;

	while (true)
	{
		if
			(Employee.choice == "1" || Employee.choice == "2")

			break;

		else
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\t Invalid! Please Enter Again!" << endl;
		cout << "\n\t PLEASE ENTER YOUR CHOICE :";
		SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cin >> Employee.choice;
		cout << endl;

	}
	if (Employee.choice == "1")
	{

		bool IsLoggedIn();
		{
			system("cls");
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\t LOG IN";
			cout << endl;

			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\t Username:";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cin >> Employee.username;
			cout << endl;

			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\n\t Password:";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cin >> Employee.password;
			cout << endl;

			while (true)

				if (Employee.password == "12345" && Employee.username == "Derek")
				{
					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t Successfully logged in !" << endl;
					cout << endl;

					break;

				}

				else if (Employee.password != "12345" || Employee.username != "Derek")
				{
					SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << "\t Wrong Username or Password!" << endl << endl;
					cout << "\t Please Enter Again" << endl << endl;

					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t Username:";
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
					cin >> Employee.username;
					cout << endl;

					SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\t Password";
					SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
					cin >> Employee.password;
					cout << endl;

				}

			if (Employee.y >= 5)
			{
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "NO MORE ATTEMPTS !!!";
				return false;
			}

		}
	}
	else if (Employee.choice == "2")
	{
		return false;
	}

	while (true)
	{

		do ////// Menu //////
		{
			system("cls"); // clear screen
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n    < Employees Database > \n\n";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "(1) Add     a new Record \n";
			cout << "(2) Modify an existing Record\n";
			cout << "(3) Delete an existing Record \n";
			cout << "(4) Display Records \n";
			cout << "(5) Exit \n\n";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << " Enter a choice (1-5) : " << flush;
			choice = _getch();
		} while (choice < '1' || choice > '5'); // while we have no good(between 1 and 5), show menu again

		system("cls");

		// to modify, delete or display records, database file should exist, then we have some records           
		if (choice == '2' || choice == '3' || choice == '4')
		{
			if (!isFileExist(Employee_FILE_NAME)) // if database file doesn't exist
			{
				cout << "\n Database file ('" << Employee_FILE_NAME << "') doesn't exist, then there are no records." << endl;
				system("pause");
				continue; // show the menu again
			}
		}

		switch (choice)
		{
			int recs_num; // number of records before the record for modifying(deletion)
			int id;

		case '1': ////// Add Record //////
			SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\n\t\t < Entering a new record > ";
			cout << "\n   Enter the following informations for the new record : ";

			Employee.employeeID = ++employeeid;
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\nEmployee ID:" << Employee.employeeID;
			if (output.open("id.txt"), ios::out)
			{
				output << employeeid;
			}
			else

			{
				cout << "the file is empty.\n\n";
			}

			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\n\nEmployee Name:";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			getchar();
			getline(cin, Employee.employee_Name);

			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\nEmployee IC:";
			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cin >> Employee.IC;

			while ((Employee.IC.find_first_of("1234567890") == string::npos) || (Employee.IC.size() != 12))
			{

				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "\n\t Invalid! Please Enter Again!" << endl;

				SetConsoleTextAttribute;
				SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
				cout << " IC Number    :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> Employee.IC;
				cout << endl;

			}

			Employee.gender_no = Employee.IC.substr(11, 1);
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			if (stoi(Employee.gender_no) % 2 == 0)
				Employee.gender = "FEMALE";
			else
				Employee.gender = "MALE";

			Employee.date_no = stoi(Employee.IC.substr(4, 2));

			switch (Employee.date_no)
			{
			case 1: Employee.date = "1";
				break;

			case 2: Employee.date = "2";
				break;

			case 3: Employee.date = "3";
				break;

			case 4: Employee.date = "4";
				break;

			case 5: Employee.date = "5";
				break;

			case 6: Employee.date = "6";
				break;

			case 7: Employee.date = "7";
				break;

			case 8: Employee.date = "8";
				break;

			case 9: Employee.date = "9";
				break;

			case 10: Employee.date = "10";
				break;

			case 11: Employee.date = "11";
				break;

			case 12: Employee.date = "12";
				break;

			case 13: Employee.date = "13";
				break;

			case 14: Employee.date = "14";
				break;

			case 15: Employee.date = "15";
				break;

			case 16: Employee.date = "16";
				break;

			case 17: Employee.date = "17";
				break;

			case 18: Employee.date = "18";
				break;

			case 19: Employee.date = "19";
				break;

			case 20: Employee.date = "20";
				break;

			case 21: Employee.date = "21";
				break;

			case 22: Employee.date = "22";
				break;

			case 23: Employee.date = "23";
				break;

			case 24: Employee.date = "24";
				break;

			case 25: Employee.date = "25";
				break;

			case 26: Employee.date = "26";
				break;

			case 27: Employee.date = "27";
				break;

			case 28: Employee.date = "28";
				break;

			case 29: Employee.date = "29";
				break;

			case 30: Employee.date = "30";
				break;

			case 31: Employee.date = "31";
				break;

			default: Employee.date = "N/A";
			}

			Employee.month_no = stoi(Employee.IC.substr(2, 2));

			switch (Employee.month_no)
			{
			case 1: Employee.month = "January";
				break;

			case 2: Employee.month = "February";
				break;

			case 3: Employee.month = "March";
				break;

			case 4: Employee.month = "April";
				break;

			case 5: Employee.month = "May";
				break;

			case 6: Employee.month = "June";
				break;

			case 7: Employee.month = "July";
				break;

			case 8: Employee.month = "August";
				break;

			case 9: Employee.month = "September";
				break;

			case 10: Employee.month = "October";
				break;

			case 11: Employee.month = "November";
				break;

			case 12: Employee.month = "December";
				break;

			default: Employee.month = "N/A";
			}

			Employee.year_no = Employee.IC.substr(0, 2);

			if (stoi(Employee.year_no) >= 00 && stoi(Employee.year_no) <= 30)
				Employee.year = "20";
			else if (stoi(Employee.year_no) >= 19 && stoi(Employee.year_no) <= 99)
				Employee.year = "19";


			SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
			cout << "\nEmployee Gender:" << Employee.gender << endl;

			SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
			cout << "\nEmployee DOB:" << Employee.date << "-" << Employee.month << "-" << Employee.year << Employee.IC.substr(0, 2) << endl;

			SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
			cout << "\nEmployee Phone Number:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Employee.phone_number;

			while ((Employee.phone_number.find_first_of("1234567890") == string::npos) || (Employee.phone_number.size() < 10) || (Employee.phone_number.size() > 11))
			{
				SetConsoleTextAttribute;
				SetConsoleTextAttribute(y, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "\n\t Invalid Input! Please Enter Again." << endl;

				SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
				cout << " PHONE NUMBER :";
				SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cin >> Employee.phone_number;
				cout << endl;
			}

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "\nEmployee E Mail:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Employee.E_Mail;

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "\nJob Position:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			getchar();
			getline(cin, Employee.position);

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "\nEmployee Address:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			getchar();
			getline(cin, Employee.address);

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "\nEmployee Salary:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Employee.salary;

			SetConsoleTextAttribute(y, FOREGROUND_INTENSITY);
			cout << "\nEmployee Working Hours:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			getchar();
			getline(cin, Employee.working_hours);

			SetConsoleTextAttribute(y,  FOREGROUND_INTENSITY);
			cout << "\nEmployee Nationality:";
			SetConsoleTextAttribute(y, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cin >> Employee.nationality;








			//Don't touch after this line
			Employee.deleted = 0;

			fs = new fstream(Employee_FILE_NAME, ios::out | ios::app | ios::binary);

			if (!fs)
			{
				cout << "\n Can't open or create '" << Employee_FILE_NAME << "' file" << endl;
				system("pause");
				break;
			}

			fs->write((char *)&Employee, sizeof(Employee));

			closeFile(fs);

			cout << "\n Record added." << endl;
			system("pause");

			break;
			/*
			case '2': ////// Modify Record //////

			cout << "\n Enter Employee ID, that you want modify its informatin : ";
			cin >> id;

			fs = new fstream(Employee_FILE_NAME, ios::in | ios::out | ios::binary);

			if (!fs)
			{
			cout << "\n Can't open or create '" << Employee_FILE_NAME << "' file" << endl;
			system("pause");

			break;
			}

			recs_num = -1;

			while (fs->read((char *)&Employee, sizeof(Employee)))
			{
			recs_num++;

			if (Employee.ID == id && !Employee.deleted)
			break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{
			cout << "\n Your specified Employee doesn't exist in file." << endl;
			closeFile(fs);
			system("pause");
			break;
			}


			cout << "\n   Enter new informations for this record : ";
			cout << "\n\n PAY_TYPE ( SALARIED : 0, HOURLY : 1 ) : ";
			cin >> Employee.PAY_TYPE;

			cout << "\n ID : ";
			cin >> Employee.ID;
			cout << "\n AGE : ";
			cin >> Employee.AGE;
			cout << "\n DEPT (one character) : ";
			cin >> Employee.DEPT;

			if (Employee.PAY_TYPE == SALARIED)
			{
			cout << "\n MONTHLY_RATE : ";
			cin >> Employee.MONTHLY_RATE;
			cout << "\n START_DATE : ";
			cin >> Employee.START_DATE;
			}

			if (Employee.PAY_TYPE == HOURLY)
			{
			cout << "\n RATE_PER_HOUR : ";
			cin >> Employee.RATE_PER_HOUR;
			cout << "\n REG_HOURS : ";
			cin >> Employee.REG_HOURS;
			cout << "\n OVERTIME_HOURS : ";
			cin >> Employee.OVERTIME_HOURS;
			}


			fs->seekp(sizeof(Employee) * recs_num, ios::beg); // go to the first of the record to be modified
			fs->write((char *)&Employee, sizeof(Employee));

			closeFile(fs);

			cout << "\n Record is modified." << endl;
			system("pause");

			break;


			case '3': ////// Delete Record //////

			cout << "\n Enter Employee's ID, for deletion : ";
			cin >> id;

			fs = new fstream(Employee_FILE_NAME, ios::in | ios::out | ios::binary);

			if (!fs)
			{
			cout << "\n Can't open or create '" << Employee_FILE_NAME << "' file." << endl;
			system("pause");
			break;
			}

			recs_num = -1;

			while (fs->read((char *)&Employee, sizeof(Employee)))
			{
			recs_num++;

			if (Employee.ID == id && !Employee.deleted) // if user deleted an Employee then added another one with the same ID in the same instance of program runs, deleted Employee is still there, then we should go through all the file
			break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{
			cout << "\n Your specified Employee doesn't exist in database file." << endl;
			closeFile(fs);
			system("pause");
			break;
			}

			Employee.deleted = 1;

			fs->seekp(sizeof(Employee) * recs_num, ios::beg);
			fs->write((char *)&Employee, sizeof(Employee));

			closeFile(fs);

			deletion = true; // we have some deleted records

			cout << "\n Record is deleted." << endl;
			system("pause");

			break;


			case '4': // Display Records

			////// Print Salaried records...
			fs = new fstream(Employee_FILE_NAME, ios::in | ios::binary);

			if (!fs)
			{
			cout << "\n Can't open or create '" << Employee_FILE_NAME << "' file." << endl;
			system("pause");
			break;
			}

			// display column titles
			cout << "\n\t\t < Salaried >\n\n";
			cout << "ID\tAGE\tDEPT\tMONTHLY_RATE\tSTART_DATE\n"
			<< "-------------------------------------------------- \n";

			while (fs->read((char *)&Employee, sizeof(Employee))) // display records
			{
			if (Employee.PAY_TYPE == SALARIED && !Employee.deleted)
			{
			cout << Employee.ID << '\t';
			cout << Employee.AGE << '\t';
			cout << Employee.DEPT << '\t';
			cout << Employee.MONTHLY_RATE << "\t\t";
			cout << Employee.START_DATE << '\n';
			}
			}

			cout << "\n To see Hourly records, "; system("pause");

			closeFile(fs);

			////// Print Hourly records...
			system("cls");

			fs = new fstream(Employee_FILE_NAME, ios::in | ios::binary);

			if (!fs)
			{
			cout << "\n Can't open or create '" << Employee_FILE_NAME << "' file." << endl;
			system("pause");
			break;
			}

			cout << "\n\t\t\t < Hourly > \n\n";
			cout << "ID\tAGE\tDEPT\tRATE_PER_HOUR\tREG_HOURS\tOVERTIME_HOURS\n"
			<< "---------------------------------------------------------------------- \n";

			while (fs->read((char *)&Employee, sizeof(Employee_Record)))
			{
			if (Employee.PAY_TYPE == HOURLY && !Employee.deleted)
			{
			cout << Employee.ID << '\t';
			cout << Employee.AGE << '\t';
			cout << Employee.DEPT << '\t';
			cout << Employee.RATE_PER_HOUR << "\t\t";
			cout << Employee.REG_HOURS << "\t\t";
			cout << Employee.OVERTIME_HOURS << '\n';
			}
			}

			cout << "\n To see menu, "; system("pause");

			closeFile(fs);

			break;

			*/
		case '5': // Exit

			if (deletion) // if there is any deletion, then update database file (create a new temp file that doesn't have deleted records, then remove the old database file and rename temp file to database file name)
			{
				cout << "\n Updating '" << Employee_FILE_NAME << "' File..." << endl;

				fs = new fstream(Employee_FILE_NAME, ios::in | ios::binary);
				if (!fs)
				{
					cout << "\n Can't open '" << Employee_FILE_NAME << "' file, then Updating is incomplete." << endl;
					system("pause");

					system("cls");
					return 1;
				}

				fs1 = new fstream("temp", ios::out | ios::binary);
				if (!fs1)
				{
					cout << "\n Can't create temp file, then Updating is incomplete." << endl;
					system("pause");

					closeFile(fs);
					system("cls");
					return 1;
				}

				// write nondeleted records to the temp file
				while (fs->read((char *)&Employee, sizeof(Employee)))
					if (!Employee.deleted)
						fs1->write((char *)&Employee, sizeof(Employee));

				closeFile(fs);
				closeFile(fs1);

				if (remove(Employee_FILE_NAME) == -1) // if there is an error
				{
					cout << "\n Can't delete '" << Employee_FILE_NAME << "' file, then Updating is incomplete." << endl;
					system("pause");

					system("cls");
					return 1;
				}


				struct stat st; // to check size of the temp file
				int res = stat("temp", &st);

				if (st.st_size == 0) // if all of records are deleted then the temp file size is zero                        
					remove("temp"); // we have no records, then no database file is needed, just delete the temp file
				else
					if (rename("temp", Employee_FILE_NAME))
					{
						cout << "\n Can't rename temp file, then Updating is incomplete." << endl;
						system("pause");

						system("cls");
						return 1;
					}

				cout << "\n Updating database file completed." << endl;
				system("pause");
			}

			system("cls");
			return main();

			break;
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