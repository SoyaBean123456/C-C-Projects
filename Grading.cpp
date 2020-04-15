/***
//// Last Build : 9_11_17
//// Compiler   : VS2017
//// Programmer : Yeo Yee Wen
//// Capability : Implementing a variable size record
//// Function   : add, delete, update, search, display records
***/


/////////////     Includes    /////////////

#include <cstdlib> // system()
#include <conio.h> // getch()
#include <fstream>
#include <istream>
#include <string>
#include <sys\stat.h> // stat(status of a file) 
#include <iostream>
#include <ctime> //time()
#include <iomanip>
#pragma warning(disable: 4996)
using namespace std;


/////////////     Data types    /////////////
int StudentID = 0;
int searchStudentID;


struct Grade_Record // Grade record
{
	int StudentID;
	string staffID;
	string studentID;
	int menuchoice;
	string name;
	char address[40];
	string nationality;
	string IC;
	char slash;
	string passportno;
	string session;
	string modeofstudy = "FULL TIME";
	int year = 1;
	string school;
	int level;
	string program;
	char major_no;
	char major[80];
	int section;
	int coursecode;
	string description;
	int credithours;
	string grade;
	int gradepoints;
	int creditpoints;
	double GPA;
	double CGPA;
	string awards;
	double quiz;
	int attendance;
	double test;
	double assignment;
	double examination;
	string gender;
	string gender_no;
	string campus;
	int age;
	string age_no;
	string contactno;
	char email[40];
	int state_no;
	string state;
	string race;
	string religion;
	int package;
	int currentYear;
	int currentMonth;
	int currentDay;
	int currentHour;
	int currentMinute;
	int currentSecond;
	int now_year;
	int birth_year;
	int MGT1210;
	int MAT1215;
	int MGT1211;
	int PDC1107;
	int CSC1208;
	int CSC1214;
	int COM1210;
	int GNS1204;
	int ENL1211;
	int ENL1216;
	int COM1211;
	int ENL1212;
	int PDC1108;
	int COM1212;
	int COM1214;
	int ECO1207;
	int ECO1208;
	int PSY1201;
	int SOC1201;
	int CSC1213;
	int ACC1201;
	int STA1203;
	int CSC1211;
	int CSC1212;
	int MAT1214;
	int MAT1210;
	int PHY1203;
	int BIO1203;
	int MAT1211;
	int CHM1203;
	int CHM1204;
	int EGR1203;
	int BIO1204;
	int STA1202;
	int PHY1204;
	bool deleted;
};


/////////////     Variable Declarations & Constants /////////////

#define GRADE_FILE_NAME "Grades.txt" // name of the database file to store Grades informations

Grade_Record Grade;
char     choice; // for choice in menu
fstream *fs = NULL, *fs1 = NULL;// file streams for files : fs -> 'Grade', fs1 -> 'temp'
bool     deletion = false; // if any record has been deleted


						   /////////////     Function Prototypes    /////////////

void closeFile(fstream *); // closes a file with its pointer, then deletes the file pointer
bool isFileExist(const char *); // check if a file exists
string grade(int marks); // Grade calculation
double point(int marks); // GPA calculation
void current_time(); // Current time


					 /////////////     Main    /////////////
int main()
{
	ifstream input; //declaration for the "id.txt"
	input.open("id.txt"), ios::in;
	input >> StudentID;
	ofstream output;



	while (true)
	{
		do ////// Menu //////
		{
		mainmenu:
			system("cls"); // clear screen

			cout << " \n\t-----------[ Grades Database ]-----------\n";
			cout << "\t\t     Designed by TAN\n\n";
			cout << " \t[1] Add a new Record \n";
			cout << " \t[2] Search an existing Record\n";
			cout << " \t[3] Modify and update an existing Record\n";
			cout << " \t[4] Delete an existing Record \n";
			cout << " \t[5] Display Records \n";
			cout << " \t[6] Exit \n\n";
			cout << " \t\tEnter a choice (1-6) : " << flush;
			choice = _getch();

		} while (choice < '1' || choice > '6'); // while we have no good(between 1 and 6), show menu again

		system("cls");

		// to search, modify, delete or display records, database file should exist, then we have some records           
		if (choice == '2' || choice == '3' || choice == '4' || choice == '5')
		{
			if (!isFileExist(GRADE_FILE_NAME)) // if database file doesn't exist
			{
				cout << "\n-----------------------------------------------------------------------------------------------------------------" << endl;
				cout << "\t Database file ('" << GRADE_FILE_NAME << "') doesn't exist, then there are no records.";
				cout << "\n-----------------------------------------------------------------------------------------------------------------" << endl;

				system("pause");
				continue; // show the menu again
			}
		}

		time_t now = time(0); // time
		tm *ltm = localtime(&now); // time

		switch (choice)
		{
			int recs_num; // number of records before the record for modifying(deletion)
			int id;

		case '1': ////// Add Record //////
		loopaddcase:
			cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
			cout << "\t Enter the following information for the new record.";
			cout << "\n-----------------------------------------------------------------------------------------------------------------";
			Grade.StudentID = ++StudentID;
			cout << "\nStudentID\t\t\t\t\t: " << Grade.StudentID << endl;
			if (output.open("id.txt"), ios::out) //Create "id.txt" to store id
			{
				output << StudentID;
			}
			else
			{
				cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
				cout << "\t Sorry, the file is empty. :[";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			}

			output.close();

			cout << "Name\t\t\t\t\t\t: ";
			cin.ignore();
			getline(cin, Grade.name);

			while (Grade.name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid name" << endl;
				cout << "================================================================" << endl;
				cout << "Name\t\t\t\t\t\t: ";
				getline(cin, Grade.name);
			}

			cout << "Address\t\t\t\t\t\t: ";
			cin.ignore();
			cin.getline(Grade.address, 40);

			cout << "========Nationality=============================================" << endl;
			cout << " \t[1] for Malaysian\n";
			cout << " \t[2] for Others\n";
			cout << "================================================================" << endl;
			cout << "Enter Nationality code\t\t\t\t: ";
			cin >> Grade.menuchoice;

			while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid nationality code:" << endl;
				cout << "========Nationality=============================================" << endl;
				cout << " \t[1] for Malaysian\n";
				cout << " \t[2] for Others\n";
				cout << "================================================================" << endl;
				cout << "Enter Nationality code\t\t\t\t: ";
				cin.clear();
				cin >> Grade.menuchoice;
			}

			switch (Grade.menuchoice)
			{
			case 1:
				Grade.nationality = "Malaysian";
				cout << "Nationality\t\t\t\t\t: " << Grade.nationality << endl;
				cout << "IC\t\t\t\t\t\t: ";

				cin >> Grade.IC;

				while (Grade.IC.find_first_of("1234567890") == string::npos || (Grade.IC.size() != 12))
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid IC" << endl;
					cout << "================================================================" << endl;
					cout << "IC\t\t\t\t\t\t: ";
					cin >> Grade.IC;
				}



				Grade.now_year = 1900 + ltm->tm_year;
				Grade.age_no = Grade.IC.substr(0, 2);
				Grade.birth_year = stoi(Grade.age_no);
				if (Grade.now_year - (2000 + Grade.birth_year) < 0 && Grade.birth_year > (2000 - Grade.now_year))
				{
					Grade.age = Grade.now_year - (Grade.birth_year + 1900);
				}
				else
				{
					Grade.age = Grade.now_year - (Grade.birth_year + 2000);
				}
				cout << "Age\t\t\t\t\t\t: " << Grade.age << endl;

				Grade.state_no = stoi(Grade.IC.substr(6, 2));

				switch (Grade.state_no)
				{
				case 1:
					Grade.state = "Johor";
					break;
				case 2:
					Grade.state = "Kedah";
					break;
				case 3:
					Grade.state = "Kelantan";
					break;
				case 4:
					Grade.state = "Malacca";
					break;
				case 5:
					Grade.state = "Negeri Sembilan";
					break;
				case 6:
					Grade.state = "Pahang";
					break;
				case 7:
					Grade.state = "Penang";
					break;
				case 8:
					Grade.state = "Perak";
					break;
				case 9:
					Grade.state = "Perlis";
					break;
				case 10:
					Grade.state = "Selangor";
					break;
				case 11:
					Grade.state = "Terengganu";
					break;
				case 12:
					Grade.state = "Sabah";
					break;
				case 13:
					Grade.state = "Sarawak";
					break;
				case 14:
					Grade.state = "Federal Territory of Kuala Lumpur";
					break;
				case 15:
					Grade.state = "Federal Territory of Labuan";
					break;
				case 16:
					Grade.state = "Federal Territory of Putrajaya";
					break;
				default:
					Grade.state = "N/A";
				}

				cout << "State\t\t\t\t\t\t: " << Grade.state << endl;

				Grade.gender_no = Grade.IC.substr(11, 1);

				if (stoi(Grade.gender_no) % 2 == 0)
					Grade.gender = "Female";
				else
					Grade.gender = "Male";

				cout << "Gender\t\t\t\t\t\t: " << Grade.gender << endl;

				break;

			case 2:
				Grade.nationality = "Others";
				cout << "Nationality\t\t\t\t\t: ";
				cin >> Grade.nationality;

				while (Grade.nationality.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid nationality" << endl;
					cout << "================================================================" << endl;
					cout << "Nationality\t\t\t\t\t: ";
					cin >> Grade.nationality;
				}

				cout << "Passport No\t\t\t\t\t: ";
				cin >> Grade.passportno;
				cout << "Age\t\t\t\t\t\t: ";
				cin >> Grade.age;

				cout << "State\t\t\t\t\t\t: ";
				cin >> Grade.state;

				while (Grade.state.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid state" << endl;
					cout << "================================================================" << endl;
					cout << "State\t\t\t\t\t\t: ";
					cin >> Grade.state;
				}

				cout << "========GENDER==================================================" << endl;
				cout << "\t[1] for Male\n";
				cout << "\t[2] for Female\n";
				cout << "================================================================" << endl;
				cout << "Enter Gender Code\t\t\t\t: ";
				cin >> Grade.menuchoice;

				while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2))
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid gender" << endl;
					cout << "========GENDER==================================================" << endl;
					cout << "\t[1] for Male\n";
					cout << "\t[2] for Female\n";
					cout << "================================================================" << endl;
					cout << "Enter Gender Code\t\t\t\t: ";
					cin.clear();
					cin >> Grade.menuchoice;
				}

				switch (Grade.menuchoice)
				{
				case 1:
					Grade.gender = "Male";
					break;
				case 2:
					Grade.gender = "Female";
					break;
				default:
					Grade.gender = "N/A";
				}

				cout << "Gender\t\t\t\t\t\t: " << Grade.gender << endl;

				break;

			default:
				Grade.nationality = "N/A";
			}

			cout << "========RACE====================================================" << endl;
			cout << " \t[1] for Malay\n";
			cout << " \t[2] for Chinese\n";
			cout << " \t[3] for Indian\n";
			cout << " \t[4] for Others\n";
			cout << "================================================================" << endl;
			cout << "Enter race code\t\t\t\t\t: ";
			cin >> Grade.menuchoice;

			while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid race" << endl;
				cout << "========RACE====================================================" << endl;
				cout << " \t[1] for Malay\n";
				cout << " \t[2] for Chinese\n";
				cout << " \t[3] for Indian\n";
				cout << " \t[4] for Others\n";
				cout << "================================================================" << endl;
				cout << "Enter race code\t\t\t\t\t: ";
				cin.clear();
				cin >> Grade.menuchoice;
			}

			switch (Grade.menuchoice)
			{
			case 1:
				Grade.race = "Malay";
				break;
			case 2:
				Grade.race = "Chinese";
				break;
			case 3:
				Grade.race = "Indian";
				break;
			case 4:
				Grade.race = "Others";
				break;
			}

			cout << "Race\t\t\t\t\t\t: ";
			cout << Grade.race << endl;

			cout << "========RELIGION================================================" << endl;
			cout << " \t[1] for Islam\n";
			cout << " \t[2] for Buddhism\n";
			cout << " \t[3] for Christianity\n";
			cout << " \t[4] for Hinduism\n";
			cout << " \t[5] for Others\n";
			cout << "================================================================" << endl;
			cout << "Enter religion code\t\t\t\t: ";
			cin >> Grade.menuchoice;

			while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3) && (Grade.menuchoice != 4) && (Grade.menuchoice != 5))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid religion" << endl;
				cout << "========RELIGION================================================" << endl;
				cout << " \t[1] for Islam\n";
				cout << " \t[2] for Buddhism\n";
				cout << " \t[3] for Christianity\n";
				cout << " \t[4] for Hinduism\n";
				cout << " \t[5] for Others\n";
				cout << "================================================================" << endl;
				cout << "Enter religion code\t\t\t\t: ";
				cin.clear();
				cin >> Grade.menuchoice;
			}

			switch (Grade.menuchoice)
			{
			case 1:
				Grade.religion = "Islam";
				break;
			case 2:
				Grade.religion = "Buddhism";
				break;
			case 3:
				Grade.religion = "Christianity";
				break;
			case 4:
				Grade.religion = "Hinduism";
				break;
			case 5:
				Grade.religion = "Others";
				break;
			default:
				Grade.religion = "N/A";
			}

			cout << "Religion\t\t\t\t\t: ";
			cout << Grade.religion << endl;

			cout << "Contact number\t\t\t\t\t: ";
			cin >> Grade.contactno;

			while (Grade.contactno.find_first_of("1234567890") == string::npos || (Grade.contactno.size() != 10))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid contact number" << endl;
				cout << "================================================================" << endl;
				cout << "Contact number\t\t\t\t\t: ";
				cin >> Grade.contactno;
			}

			cout << "E-mail\t\t\t\t\t\t: ";
			cin.ignore();
			cin.getline(Grade.email, sizeof(Grade.email));

			while (strlen(Grade.email) < 15)
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid e-mail" << endl;
				cout << "================================================================" << endl;
				cout << "E-mail\t\t\t\t\t\t: ";
				cin.getline(Grade.email, sizeof(Grade.email));
			}
			cout << "Mode of Study\t\t\t\t\t: " << Grade.modeofstudy << endl;

			cout << "Year\t\t\t\t\t\t: " << Grade.year << endl;

			cout << "========CAMPUS==================================================" << endl;
			cout << " \t[1] for INTI International University\n";
			cout << " \t[2] for INTI International College Subang\n";
			cout << " \t[3] for INTI International College Penang\n";
			cout << " \t[4] for INTI International College Kuala Lumpur\n";
			cout << " \t[5] for INTI College Sabah\n";
			cout << " \t[6] for INTI College Nilai\n";
			cout << "================================================================" << endl;
			cout << "Enter Campus code\t\t\t\t: ";
			cin >> Grade.menuchoice;

			while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3) && (Grade.menuchoice != 4) && (Grade.menuchoice != 5) && (Grade.menuchoice != 6))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid campus code" << endl;
				cout << "========CAMPUS==================================================" << endl;
				cout << " \t[1] for INTI International University\n";
				cout << " \t[2] for INTI International College Subang\n";
				cout << " \t[3] for INTI International College Penang\n";
				cout << " \t[4] for INTI International College Kuala Lumpur\n";
				cout << " \t[5] for INTI College Sabah\n";
				cout << " \t[6] for INTI College Nilai\n";
				cout << "================================================================" << endl;
				cout << "Enter Campus code\t\t\t\t: ";
				cin.clear();
				cin >> Grade.menuchoice;
			}

			switch (Grade.menuchoice)
			{
			case 1:
				Grade.campus = "IU";
				break;
			case 2:
				Grade.campus = "IICS";
				break;
			case 3:
				Grade.campus = "IICP";
				break;
			case 4:
				Grade.campus = "IICKL";
				break;
			case 5:
				Grade.campus = "ICS";
				break;
			case 6:
				Grade.campus = "ICN";
				break;
			default:
				Grade.campus = "N/A";
			}

			cout << "Campus\t\t\t\t\t\t: " << Grade.campus << endl;

			cout << "Level\t\t\t\t\t\t: " << "Foundation" << endl;

			cout << "========PROGRAM=================================================" << endl;
			cout << "\t[1] for Foundation in Arts\n";
			cout << "\t[2] for Foundation in Business & IT\n";
			cout << "\t[3] for Foundation in Science\n";
			cout << "================================================================" << endl;
			cout << "Enter Program Code\t\t\t\t: ";
			cin >> Grade.menuchoice;

			while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
			{
				cout << "========ERROR===================================================" << endl;
				cout << "\t Invalid Input! Please enter a valid program" << endl;
				cout << "========PROGRAM=================================================" << endl;
				cout << "\t[1] for Foundation in Arts\n";
				cout << "\t[2] for Foundation in Business & IT\n";
				cout << "\t[3] for Foundation in Science\n";
				cout << "================================================================" << endl;
				cout << "Enter Program Code\t\t\t\t: ";
				cin.clear();
				cin >> Grade.menuchoice;
			}



			switch (Grade.menuchoice)
			{
			case 1:
				Grade.program = "CFAI";
				cout << "Program\t\t\t\t\t\t: " << Grade.program << endl;

				cout << "========MAJOR===================================================" << endl;
				cout << "\t[1] for Mass Communication\n";
				cout << "\t[2] for Finance\n";
				cout << "\t[3] for Psychology\n";
				cout << "================================================================" << endl;
				cout << "Enter Major Code\t\t\t\t: ";
				cin >> Grade.menuchoice;

				while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid major" << endl;
					cout << "========MAJOR===================================================" << endl;
					cout << "\t[1] for Mass Communication\n";
					cout << "\t[2] for Finance\n";
					cout << "\t[3] for Psychology\n";
					cout << "================================================================" << endl;
					cout << "Enter Major Code\t\t\t\t: ";
					cin >> Grade.menuchoice;
				}

				if (Grade.menuchoice == 1)
				{
					Grade.major_no = 'M';
					strncpy(Grade.major, "Mass Communication", sizeof(Grade.major));
				}
				else if (Grade.menuchoice == 2)
				{
					Grade.major_no = 'F';
					strncpy(Grade.major, "Finance", sizeof(Grade.major));
				}
				else if (Grade.menuchoice == 3)
				{
					Grade.major_no = 'P';
					strncpy(Grade.major, "Psychology", sizeof(Grade.major));
				}
				else
				{
					strncpy(Grade.major, "N/A", sizeof(Grade.major));
				}

				cout << "Major\t\t\t\t\t\t: " << Grade.major << endl;

				cout << "========SEMESTER 1==============================================" << endl;
				cout << "MGT1210 Fundamentals of Business Management\t\t: ";
				cin >> Grade.MGT1210;
				cout << "MGT1211 Introduction to Business Studies\t\t: ";
				cin >> Grade.MGT1211;
				cout << "PDC1107 Self-Development Skills\t\t\t\t: ";
				cin >> Grade.PDC1107;
				cout << "========SEMESTER 2==============================================" << endl;
				cout << "CSC1208 Basic Computing\t\t\t\t\t: ";
				cin >> Grade.CSC1208;
				cout << "COM1210 Introduction to Intercultural Communication\t: ";
				cin >> Grade.COM1210;
				cout << "GNS1204 General Studies\t\t\t\t\t: ";
				cin >> Grade.GNS1204;
				cout << "ENL1211 English Language Skills 1\t\t\t: ";
				cin >> Grade.ENL1211;
				cout << "ENL1216 Introduction to Creating Writing\t\t: ";
				cin >> Grade.ENL1216;
				cout << "========SEMESTER 3==============================================" << endl;
				cout << "COM1211 Introduction to Mass Media\t\t\t: ";
				cin >> Grade.COM1211;
				cout << "ENL1212 Englsih Language Skills 2\t\t\t: ";
				cin >> Grade.ENL1212;
				cout << "PDC1108 Skills for Creative Thinking\t\t\t: ";
				cin >> Grade.PDC1108;

				if (Grade.major_no == 'M')
				{
					cout << "COM1212 Digital Communication\t\t\t\t: ";
					cin >> Grade.COM1212;
					cout << "COM1214 Visual Communication\t\t\t\t: ";
					cin >> Grade.COM1214;
				}
				else if (Grade.major_no == 'F')
				{
					cout << "ECO1207 Microeconomics\t\t\t\t\t: ";
					cin >> Grade.ECO1207;
					cout << "ECO1208 Macroeconomics\t\t\t\t\t: ";
					cin >> Grade.ECO1208;
				}
				else if (Grade.major_no == 'P')
				{
					cout << "PSY1201 Psychology\t\t\t\t\t: ";
					cin >> Grade.PSY1201;
					cout << "SOC1201 Basic Sociology\t\t\t\t\t: ";
					cin >> Grade.SOC1201;
				}

				break;

			case 2:
				Grade.program = "CFPI";
				cout << "Program\t\t\t\t\t\t: " << Grade.program << endl;
				cout << "========MAJOR===================================================" << endl;
				cout << "\t[1] for Business\n";
				cout << "\t[2] for Information Technology\n";
				cout << "================================================================" << endl;
				cout << "Enter Major Code\t\t\t\t: ";
				cin >> Grade.menuchoice;

				while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2))
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid major" << endl;
					cout << "========MAJOR===================================================" << endl;
					cout << "\t[1] for Business\n";
					cout << "\t[2] for Information Technology\n";
					cout << "================================================================" << endl;
					cout << "Enter Major Code\t\t\t\t: ";
					cin.clear();
					cin >> Grade.menuchoice;
				}

				if (Grade.menuchoice == 1)
				{
					Grade.major_no = 'B';
					strncpy(Grade.major, "Business", sizeof(Grade.major));
				}
				else if (Grade.menuchoice == 2)
				{
					Grade.major_no = 'I';
					strncpy(Grade.major, "Information Technology", sizeof(Grade.major));
				}
				else
				{
					strncpy(Grade.major, "N/A", sizeof(Grade.major));
				}

				cout << "Major\t\t\t\t\t\t: " << Grade.major << endl;
				cout << "========SEMESTER 1==============================================" << endl;
				cout << "MGT1210 Fundamentals of Business Management\t: ";
				cin >> Grade.MGT1210;
				cout << "MGT1211 Introduction to Mathematics\t\t: ";
				cin >> Grade.MAT1215;
				cout << "PDC1107 Self-Development Skills\t\t\t: ";
				cin >> Grade.PDC1107;
				cout << "========SEMESTER 2==============================================" << endl;
				cout << "CSC1208 Basic Computing\t\t\t\t: ";
				cin >> Grade.CSC1208;
				cout << "ENL1211 English Language Skills 1\t\t: ";
				cin >> Grade.ENL1211;
				cout << "GNS1204 General Studies\t\t\t\t: ";
				cin >> Grade.GNS1204;

				if (Grade.major_no == 'I')
				{
					cout << "CSC1213 Introduction to Database Management\t: ";
					cin >> Grade.CSC1213;
					cout << "STA1203 Business Statistics\t\t\t: ";
					cin >> Grade.STA1203;
				}
				else if (Grade.major_no == 'B')
				{
					cout << "ECO1207 Microeconomics\t\t\t\t: ";
					cin >> Grade.ECO1207;
					cout << "MGT1211 Introduction to Business Studies\t: ";
					cin >> Grade.MGT1211;
				}

				cout << "========SEMESTER 3==============================================" << endl;
				cout << "ENL1212 English Language Skills 2\t\t: ";
				cin >> Grade.ENL1212;
				cout << "PDC1108 Skills for Creative Thinking\t\t: ";
				cin >> Grade.PDC1108;

				if (Grade.major_no == 'I')
				{
					cout << "MAT1214 Advanced Mathematics\t\t\t: ";
					cin >> Grade.MAT1214;
					cout << "CSC1211 Programming Techniques\t\t\t: ";
					cin >> Grade.CSC1211;
					cout << "CSC1212 Data Communications and Networking\t: ";
					cin >> Grade.CSC1212;
				}
				else if (Grade.major_no == 'B')
				{
					cout << "ECO1208 Macroeconomics\t\t\t\t: ";
					cin >> Grade.ECO1208;
					cout << "STA1203 Business Statistics\t\t\t: ";
					cin >> Grade.STA1203;
					cout << "ACC1201 Fundamentals of Accounting\t\t: ";
					cin >> Grade.ACC1201;

				}
				break;

			case 3:
				Grade.program = "CFSI";
				cout << "Program\t\t\t\t\t\t: " << Grade.program << endl;

				cout << "========MAJOR===================================================" << endl;
				cout << "\t[1] for Enginerring\n";
				cout << "\t[2] for Pure Science\n";
				cout << "\t[3] for Bio Science\n";
				cout << "================================================================" << endl;
				cout << "Enter Major Code\t\t\t\t: ";
				cin >> Grade.menuchoice;

				while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
				{
					cout << "========ERROR===================================================" << endl;
					cout << "\t Invalid Input! Please enter a valid major" << endl;
					cout << "========MAJOR===================================================" << endl;
					cout << "\t[1] for Enginerring\n";
					cout << "\t[2] for Pure Science\n";
					cout << "\t[3] for Bio Science\n";
					cout << "================================================================" << endl;
					cout << "Enter Major Code\t\t\t\t: ";
					cin.clear();
					cin >> Grade.menuchoice;
				}

				if (Grade.menuchoice == 1)
				{
					Grade.major_no = 'E';
					strncpy(Grade.major, "Engineering", sizeof(Grade.major));
				}
				else if (Grade.menuchoice == 2)
				{
					Grade.major_no = 'R';
					strncpy(Grade.major, "Pure Science", sizeof(Grade.major));
				}
				else if (Grade.menuchoice == 3)
				{
					Grade.major_no = 'O';
					strncpy(Grade.major, "Bio Science", sizeof(Grade.major));
				}

				cout << "Major\t\t\t\t\t\t: " << Grade.major << endl;
				cout << "========SEMESTER 1==============================================" << endl;
				cout << "MAT1210 Mathematics 1\t\t\t\t: ";
				cin >> Grade.MAT1210;
				cout << "PDC1107 Self-Development Skills\t\t\t: ";
				cin >> Grade.PDC1107;

				if (Grade.major_no == 'E' || Grade.major_no == 'R')
				{
					cout << "PHY1203 General Physics 1\t\t\t: ";
					cin >> Grade.PHY1203;
				}
				else if (Grade.major_no == 'O')
				{
					cout << "BIO1203 Biology 1\t\t\t\t: ";
					cin >> Grade.BIO1203;
				}

				cout << "========SEMESTER 2==============================================" << endl;
				cout << "ENL1211 English Language Skills 1\t\t: ";
				cin >> Grade.ENL1211;
				cout << "GNS1204 General Studies\t\t\t\t: ";
				cin >> Grade.GNS1204;
				cout << "MAT1211 Mathematics 2\t\t\t\t: ";
				cin >> Grade.MAT1211;
				cout << "CHM1203 Chemistry 1\t\t\t\t: ";
				cin >> Grade.CHM1203;

				if (Grade.major_no == 'E' || Grade.major_no == 'O')
				{
					cout << "CSC1208 Basic Computing\t\t\t\t: ";
					cin >> Grade.CSC1208;
				}
				else if (Grade.major_no == 'O')
				{
					cout << "BIO1203 Biology 1\t\t\t\t: ";
					cin >> Grade.BIO1203;
				}

				cout << "========SEMESTER 3==============================================" << endl;
				cout << "PDC1108 Skills for Creative Thinking\t\t: ";
				cin >> Grade.PDC1108;
				cout << "ENL1212 English Language Skills 2\t\t: ";
				cin >> Grade.ENL1212;
				cout << "CHM1204 Chemistry 2\t\t\t\t: ";
				cin >> Grade.CHM1204;

				if (Grade.major_no == 'E')
				{
					cout << "CSC1208 Basic Computing\t\t\t\t: ";
					cin >> Grade.CSC1208;
					cout << "EGR1203 Engineering Mechanics\t\t\t: ";
					cin >> Grade.EGR1203;
				}
				else if (Grade.major_no == 'O')
				{
					cout << "BIO1204 Biology 2\t\t\t\t: ";
					cin >> Grade.BIO1204;
					cout << "STA1202 Statistics\t\t\t\t: ";
					cin >> Grade.STA1202;
				}
				else if (Grade.major_no == 'R')
				{
					cout << "BIO1204 Biology 2\t\t\t\t: ";
					cin >> Grade.BIO1204;
					cout << "PHY1204 General Physics 2\t\t\t: ";
					cin >> Grade.PHY1204;
				}
				break;
			}

			current_time(); // Get current time

			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			cout << "This record was created on " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << Grade.currentYear << "\t" << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;

			Grade.deleted = 0;

			fs = new fstream(GRADE_FILE_NAME, ios::out | ios::app | ios::binary);

			if (!fs)
			{
				cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
				cout << " Can't open or create '" << GRADE_FILE_NAME << "' file";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("pause");
				break;
			}

			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			cout << " Do you want to save this record? (1=Yes, 2=No, 3=Save and Add): " << flush;

			char confirm;

		loopadd:
			confirm = getch();
			cin.ignore();
			system("cls");

			if (confirm == '1')
			{
				fs->write((char*)&Grade, sizeof(Grade));
				system("cls");
				cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
				cout << "\t Record is added. :]" << endl;
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("paused");
				closeFile(fs);
				break;
			}
			if (confirm == '2')
			{
				system("cls");
				cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
				cout << "\t Record is not added. :[" << endl;
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("paused");
				break;
			}
			if (confirm == '3')
			{
				fs->write((char*)&Grade, sizeof(Grade));
				system("cls");
				cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
				cout << "\t Record is added. :]" << endl;
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("paused");
				closeFile(fs);

				goto loopaddcase;
			}
			else
			{
				cout << "========ERROR===================================================\n";
				cout << "\t Invalid Input! Please enter again" << endl;
				cout << "================================================================";
				cout << "\n Do you want to add this record? (1=Yes, 2=No, 3=Save and Add): " << flush;
				goto loopadd;
			}

			fs->write((char*)&Grade, sizeof(Grade));

			closeFile(fs);

			cout << "\n----------[ ADD RECORD ]-----------------------------------------------------------------------------------------\n";
			cout << "\n Record added. :]" << endl;
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

			system("pause");

			break;

		case '2': ////// Search Record //////

			cout << "\n----------[ SEARCH RECORD ]--------------------------------------------------------------------------------------\n";
			cout << "\t Search an existing student's information.";
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\tEnter Student ID: ";
			cin >> searchStudentID;
			cin.ignore();

			fs = new fstream(GRADE_FILE_NAME, ios::in | ios::out | ios::binary);

			if (!fs)
			{
				system("cls");
				cout << "\n----------[ SEARCH RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t Can't open or create '" << GRADE_FILE_NAME << "' file";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("pause");
				goto mainmenu;
				break;
			}

			recs_num = -1;

			while (fs->read((char *)&Grade, sizeof(Grade)))
			{
				recs_num++;
				if (Grade.StudentID == searchStudentID && !Grade.deleted) //if user deleted an Student then added another one with the same ID in the same instance of program runs, deleted Student is still there, then we should go through all the file
					break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{
				system("cls");
				cout << "\n----------[ SEARCH RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t The specified Student doesn't exist in file.";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;
			}

			fs->seekp(sizeof(Grade)*recs_num, ios::beg); //go to the searched record
			fs->read((char*)&Grade, sizeof(Grade)); //display the searched record

			if (!Grade.deleted)
			{
				system("cls");
				cout << "\n----------[ SEARCH RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\tStudent ID\t: " << Grade.StudentID << endl;
				cout << "\tName\t\t: " << Grade.name << endl;
				cout << "\tAddress\t\t: " << Grade.address << endl;
				cout << "\tNationality\t: " << Grade.nationality << endl;
				if (Grade.nationality == "Malaysian")
				{
					cout << "\tIC\t\t: " << Grade.IC << endl;
				}
				else
				{
					cout << "\tPassport no\t: " << endl;
				}
				cout << "\tAge\t\t: " << Grade.age << endl;
				cout << "\tState\t\t: " << Grade.state << endl;
				cout << "\tGender\t\t: " << Grade.gender << endl;
				cout << "\tRace\t\t: " << Grade.race << endl;
				cout << "\tReligion\t: " << Grade.religion << endl;
				cout << "\tContact number\t: " << Grade.contactno << endl;
				cout << "\tE-mail\t\t: " << Grade.email << endl;
				cout << "\tMode of Study\t: " << Grade.modeofstudy << endl;
				cout << "\tYear\t\t: " << Grade.year << endl;
				cout << "\tCampus\t\t: " << Grade.campus << endl;
				cout << "\tProgram\t\t: " << Grade.program << endl;
				cout << "\tMajor\t\t: " << Grade.major << endl;
				cout << "\tDate Modified\t: " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << Grade.currentYear << endl;
				cout << "\tTime Modified\t: " << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;
				cout << "\n";
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
				cout << "CODE    COURSE DESCRIPTION\t\t\t\tCredit HOURS\tGRADE\tGRADE POINTS\tCREDIT POINTS" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

				if (Grade.program == "CFAI")
				{
					cout << "MGT1210 Fundamentals of Business Management\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
					cout << "MGT1211 Introduction to Business Studies\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
					cout << "CSC1208 Basic Computing\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
					cout << "COM1210 Introduction to Intercultural Communication\t";
					cout << "4.0" << "\t\t" << grade(Grade.COM1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1210) << "\t\t" << point(Grade.COM1210)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "ENL1216 Introduction to Creating Writing\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1216) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1216) << "\t\t" << point(Grade.ENL1216)*4.0 << endl;
					cout << "COM1211 Introduction to Mass Media\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.COM1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1211) << "\t\t" << point(Grade.COM1211)*4.0 << endl;
					cout << "ENL1212 Englsih Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

					if (Grade.major_no == 'M')
					{
						cout << "COM1212 Digital Communication\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1212) << "\t\t" << point(Grade.COM1212)*4.0 << endl;
						cout << "COM1214 Visual Communication\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1214) << "\t\t" << point(Grade.COM1214)*4.0 << endl;
					}
					else if (Grade.major_no == 'F')
					{
						cout << "ECO1207 Microeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
						cout << "ECO1208 Macroeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
					}
					else if (Grade.major_no == 'P')
					{
						cout << "PSY1201 Psychology\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PSY1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PSY1201) << "\t\t" << point(Grade.PSY1201)*4.0 << endl;
						cout << "SOC1201 Basic Sociology\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.SOC1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.SOC1201) << "\t\t" << point(Grade.SOC1201)*4.0 << endl;
					}
				}
				else if (Grade.program == "CFPI")
				{
					cout << "MGT1210 Fundamentals of Business Management\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
					cout << "MAT1215 Fundamentals of Mathematics\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1215) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1215) << "\t\t" << point(Grade.MAT1215)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
					cout << "CSC1208 Basic Computing\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "ENL1212 Englsih Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;
					cout << "STA1203 Business Statistics\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

					if (Grade.major_no == 'B')
					{
						cout << "MGT1211 Introduction to Business Studies\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
						cout << "ECO1207 Microeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
						cout << "ACC1201 Fundamentals of Accounting\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ACC1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ACC1201) << "\t\t" << point(Grade.ACC1201)*4.0 << endl;
						cout << "ECO1208 Macroeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
					}
					else if (Grade.major_no == 'I')
					{
						cout << "CSC1213 Introduction to Database Management\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1213) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1213) << "\t\t" << point(Grade.CSC1213)*4.0 << endl;
						cout << "CSC1211 Programming Techniques\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1211) << "\t\t" << point(Grade.CSC1211)*4.0 << endl;
						cout << "CSC1212 Data Communications and Networking\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1212) << "\t\t" << point(Grade.CSC1212)*4.0 << endl;
						cout << "MAT1214 Advanced Mathematics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1214) << "\t\t" << point(Grade.MAT1214)*4.0 << endl;
					}
				}
				else if (Grade.program == "CFSI")
				{
					cout << "MAT1210 Mathematics 1\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1210) << "\t\t" << point(Grade.MAT1210)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*4.0 << endl;

					if (Grade.major_no == 'E' || Grade.major_no == 'R')
					{
						cout << "PHY1203 General Physics 1\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1203) << "\t\t" << point(Grade.PHY1203)*4.0 << endl;
					}
					else if (Grade.major_no == 'O')
					{
						cout << "BIO1203 Biology 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
					}

					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "MAT1211 Mathematics 2\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;
					cout << "CHM1203 Chemistry 1\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CHM1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CHM1203) << "\t\t" << point(Grade.CHM1203)*4.0 << endl;

					if (Grade.major_no == 'O' || Grade.major_no == 'E')
					{
						cout << "CSC1214 Basic Computing\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1214) << "\t\t" << point(Grade.CSC1214)*4.0 << endl;
					}
					else if (Grade.major_no == 'R')
					{
						cout << "BIO1203 Biology 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
					}

					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "ENL1212 English Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "CHM1204 Chemistry 2\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;

					if (Grade.major_no == 'E')
					{
						cout << "EGR1203 Engineering Mechanics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.EGR1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.EGR1203) << "\t\t" << point(Grade.EGR1203)*4.0 << endl;
						cout << "PHY1204 General Physics 2\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;

					}
					else if (Grade.major_no == 'O')
					{
						cout << "BIO1204 Biology 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
						cout << "STA1202 Statistics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.STA1203)*4.0 << endl;
					}
					else if (Grade.major_no == 'R')
					{
						cout << "BIO1203 Biology 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
						cout << "PHY1204 General Physics 2\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;
					}
				}

				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			}
			system("pause");
			closeFile(fs);
			break;

		case '3': ////// Update Record //////
			cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
			cout << "\t Modify an existing student's information.";
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\tEnter Student ID: ";
			cin >> searchStudentID;
			cin.ignore();

			fs = new fstream(GRADE_FILE_NAME, ios::in | ios::out | ios::binary);

			if (!fs)
			{
				system("cls");
				cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t Can't open or create '" << GRADE_FILE_NAME << "' file";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("pause");
				goto mainmenu;
				break;
			}

			recs_num = -1;

			while (fs->read((char *)&Grade, sizeof(Grade)))
			{
				recs_num++;

				if (Grade.StudentID == searchStudentID && !Grade.deleted) //if user deleted an Student then added another one with the same ID in the same instance of program runs, deleted Student is still there, then we should go through all the file
					break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{
				system("cls");
				cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t The specified Student doesn't exist in file.";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				closeFile(fs);
				system("pause");
				goto mainmenu;
				break;
			}

			fs->seekp(sizeof(Grade)*recs_num, ios::beg); //go to the searched record
			fs->read((char*)&Grade, sizeof(Grade)); //display the searched record

			if (!Grade.deleted)
			{
			update:
				system("cls");
				cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\tStudent ID\t: " << Grade.StudentID << endl;
				cout << "\tName\t\t: " << Grade.name << endl;
				cout << "\tAddress\t\t: " << Grade.address << endl;
				cout << "\tNationality\t: " << Grade.nationality << endl;
				if (Grade.nationality == "Malaysian")
					cout << "\tIC\t\t: " << Grade.IC << endl;
				else
					cout << "\tPassport no\t: " << endl;
				cout << "\tAge\t\t: " << Grade.age << endl;
				cout << "\tState\t\t: " << Grade.state << endl;
				cout << "\tGender\t\t: " << Grade.gender << endl;
				cout << "\tRace\t\t: " << Grade.race << endl;
				cout << "\tReligion\t: " << Grade.religion << endl;
				cout << "\tContact number\t: " << Grade.contactno << endl;
				cout << "\tE-mail\t\t: " << Grade.email << endl;
				cout << "\tMode of Study\t: " << Grade.modeofstudy << endl;
				cout << "\tYear\t\t: " << Grade.year << endl;
				cout << "\tCampus\t\t: " << Grade.campus << endl;
				cout << "\tProgram\t\t: " << Grade.program << endl;
				cout << "\tMajor\t\t: " << Grade.major << endl;
				cout << "\tDate Modified\t: " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << Grade.currentYear << endl;
				cout << "\tTime Modified\t: " << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;
				cout << "\n";
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
				cout << "CODE    COURSE DESCRIPTION\t\t\t\tCredit HOURS\tGRADE\tGRADE POINTS\tCREDIT POINTS" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

				if (Grade.program == "CFAI")
				{
					cout << "MGT1210 Fundamentals of Business Management\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
					cout << "MGT1211 Introduction to Business Studies\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
					cout << "CSC1208 Basic Computing\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
					cout << "COM1210 Introduction to Intercultural Communication\t";
					cout << "4.0" << "\t\t" << grade(Grade.COM1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1210) << "\t\t" << point(Grade.COM1210)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "ENL1216 Introduction to Creating Writing\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1216) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1216) << "\t\t" << point(Grade.ENL1216)*4.0 << endl;
					cout << "COM1211 Introduction to Mass Media\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.COM1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1211) << "\t\t" << point(Grade.COM1211)*4.0 << endl;
					cout << "ENL1212 Englsih Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

					if (Grade.major_no == 'M')
					{
						cout << "COM1212 Digital Communication\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1212) << "\t\t" << point(Grade.COM1212)*4.0 << endl;
						cout << "COM1214 Visual Communication\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1214) << "\t\t" << point(Grade.COM1214)*4.0 << endl;
					}
					else if (Grade.major_no == 'F')
					{
						cout << "ECO1207 Microeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
						cout << "ECO1208 Macroeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
					}
					else if (Grade.major_no == 'P')
					{
						cout << "PSY1201 Psychology\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PSY1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PSY1201) << "\t\t" << point(Grade.PSY1201)*4.0 << endl;
						cout << "SOC1201 Basic Sociology\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.SOC1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.SOC1201) << "\t\t" << point(Grade.SOC1201)*4.0 << endl;
					}
				}
				else if (Grade.program == "CFPI")
				{
					cout << "MGT1210 Fundamentals of Business Management\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
					cout << "MAT1215 Fundamentals of Mathematics\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1215) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1215) << "\t\t" << point(Grade.MAT1215)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
					cout << "CSC1208 Basic Computing\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;

					if (Grade.major_no == 'B')
					{
						cout << "ECO1207 Microeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
						cout << "MGT1211 Introduction to Business Studies\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
					}
					else if (Grade.major_no == 'I')
					{
						cout << "CSC1213 Introduction to Database Management\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1213) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1213) << "\t\t" << point(Grade.CSC1213)*4.0 << endl;
						cout << "STA1203 Business Statistics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.STA1203)*4.0 << endl;
					}

					cout << "ENL1212 Englsih Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

					if (Grade.major_no == 'B')
					{
						cout << "ACC1201 Fundamentals of Accounting\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ACC1201) << "\t" << setprecision(2) << showpoint << point(Grade.ACC1201) << "\t\t" << point(Grade.ACC1201)*4.0 << endl;
						cout << "ECO1208 Macroeconomics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
						cout << "STA1203 Business Statistics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;
					}
					else if (Grade.major_no == 'I')
					{
						cout << "CSC1211 Programming Techniques\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1211) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1211) << "\t\t" << point(Grade.CSC1211)*4.0 << endl;
						cout << "CSC1212 Data Communications and Networking\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1212) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1212) << "\t\t" << point(Grade.CSC1212)*4.0 << endl;
						cout << "MAT1214 Advanced Mathematics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1214) << "\t" << setprecision(2) << showpoint << point(Grade.MAT1214) << "\t\t" << point(Grade.MAT1214)*4.0 << endl;
					}
				}
				else if (Grade.program == "CFSI")
				{
					cout << "MAT1210 Mathematics 1\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1210) << "\t\t" << point(Grade.MAT1210)*4.0 << endl;
					cout << "PDC1107 Self-Development Skills\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*4.0 << endl;

					if (Grade.major_no == 'E' || Grade.major_no == 'R')
					{
						cout << "PHY1203 General Physics 1\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1203) << "\t\t" << point(Grade.PHY1203)*4.0 << endl;
					}
					else if (Grade.major_no == 'O')
					{
						cout << "BIO1203 Biology 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
					}

					cout << "ENL1211 English Language Skills 1\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "GNS1204 General Studies\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "MAT1211 Mathematics 2\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;
					cout << "CHM1203 Chemistry 1\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.CHM1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CHM1203) << "\t\t" << point(Grade.CHM1203)*4.0 << endl;

					if (Grade.major_no == 'O' || Grade.major_no == 'E')
					{
						cout << "CSC1214 Basic Computing\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1214) << "\t\t" << point(Grade.CSC1214)*4.0 << endl;
					}
					else if (Grade.major_no == 'R')
					{
						cout << "BIO1203 Biology 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
					}

					cout << "PDC1108 Skills for Creative Thinking\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
					cout << "ENL1212 English Language Skills 2\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
					cout << "CHM1204 Chemistry 2\t\t\t\t\t";
					cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;

					if (Grade.major_no == 'E')
					{
						cout << "EGR1203 Engineering Mechanics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.EGR1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.EGR1203) << "\t\t" << point(Grade.EGR1203)*4.0 << endl;
						cout << "PHY1204 General Physics 2\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;

					}
					else if (Grade.major_no == 'O')
					{
						cout << "BIO1204 Biology 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
						cout << "STA1202 Statistics\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.STA1203)*4.0 << endl;
					}
					else if (Grade.major_no == 'R')
					{
						cout << "BIO1203 Biology 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
						cout << "PHY1204 General Physics 2\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;
					}
				}

				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
				cout << "[1]Name\t\t[2]Address\t[3]Nationality\t[4]IC/Passport\t[5]Age\t\t";
				cout << "[6]State\n[7]Gender\t[8]Race\t\t[9]Religion\t[10]Contact No\t";
				cout << "[11]E-mail\t[12]Campus\n[13]Program\t[14]Major\t";

				if (Grade.program == "CFAI")
				{
					cout << "[15]MGT1210\t[16]MGT1211\t[17]PDC1107\t[18]CSC1208\n[19]COM1210\t[20]GNS1204\t";
					cout << "[21]ENL1211\t[22]ENL1216\t[23]COM1211\t[24]ENL1212\t[25]PDC1108\n";

					if (Grade.major_no == 'M')
					{
						cout << "[26]COM1212\t[27]COM1214\t";
					}
					else if (Grade.major_no == 'F')
					{
						cout << "[26]ECO1207\t[27]ECO1208\t";
					}
					else if (Grade.major_no == 'P')
					{
						cout << "[26]PSY1201\t[27]SOC1201\t";
					}

				}
				else if (Grade.program == "CFPI")
				{
					cout << "[15]MGT1210\t[16]MAT1215\t[17]PDC1107\t[18]CSC1208\n[19]ENL1211\t[20]GNS1204\t";

					if (Grade.major_no == 'B')
					{
						cout << "[21]ECO1207\t[22]MGT1211\t";
					}
					else if (Grade.major_no == 'I')
					{
						cout << "[21]CSC1213\t[22]STA1203\t";
					}

					cout << "[23]ENL1212\t[24]PDC1108\n";

					if (Grade.major_no == 'B')
					{
						cout << "[25]ACC1201\t[26]ECO1208\t[27]STA1203\t";
					}
					else if (Grade.major_no == 'I')
					{
						cout << "[25]CSC1211\t[26]CSC1212\t[27]MAT1214\t";
					}
				}
				else if (Grade.program == "CFSI")
				{
					cout << "[15]MAT1210\t[16]PDC1107\t";

					if ((Grade.major_no == 'E') || (Grade.major_no == 'R'))
					{
						cout << "[17]PHY1203\t";
					}
					else if (Grade.major_no == 'O')
					{
						cout << "[17]BIO1203\t";
					}

					cout << "[18]ENL1211\n[19]GNS1204\t[20]MAT1211\t[21]CHM1203\t";

					if ((Grade.major_no == 'E') || (Grade.major_no == 'O'))
					{
						cout << "[22]CSC1214\t";
					}
					else if (Grade.major_no == 'R')
					{
						cout << "[22]BIO1203\t";
					}

					cout << "[23]PDC1108\t[24]ENL1212\n[25]CHM1204\t";

					if (Grade.major_no == 'E')
					{
						cout << "[26]EGR1203\t";
						cout << "[27]PHY1204\t";
					}
					else if (Grade.major_no == 'O')
					{
						cout << "[26]BIO1204\t";
						cout << "[27]STA1202\t";
					}
					else if (Grade.major_no == 'R')
					{
						cout << "[26]BIO1204\t";
						cout << "[27]PHY1204\t";
					}

				}
				cout << "\n";

				cout << "\nWhich details do you want to edit? (Press 0 to save and return to main menu): ";
				cin >> Grade.menuchoice;

				if (Grade.menuchoice == 0)
				{
					goto updatefile;
				}

				switch (Grade.menuchoice)
				{
				case 1:
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tName: ";
					cin.ignore();
					getline(cin, Grade.name);

					while (Grade.name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						cout << "========ERROR===================================================" << endl;
						cout << "\tInvalid Input! Please enter a valid name" << endl;
						cout << "================================================================" << endl;
						cout << "\t\tName: ";
						getline(cin, Grade.name);
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 2:
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tAddress: ";
					cin.ignore();
					cin.getline(Grade.address, 40);
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 3:
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tNationality: ";
					cin >> Grade.nationality;

					while (Grade.nationality.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						cout << "========ERROR===================================================" << endl;
						cout << "\tInvalid Input! Please enter a valid nationality" << endl;
						cout << "================================================================" << endl;
						cout << "\t\tNationality: ";
						cin >> Grade.nationality;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 4: //Modify IC/Passport
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					if (Grade.nationality == "Malaysian")
					{
						cout << "\t\tIC: ";
						cin >> Grade.IC;

						while (Grade.IC.find_first_of("1234567890") == string::npos || (Grade.IC.size() != 12))
						{
							cout << "========ERROR===================================================" << endl;
							cout << "\tInvalid Input! Please enter a valid IC" << endl;
							cout << "================================================================" << endl;
							cout << "\t\tIC: ";
							cin >> Grade.IC;
						}

					}
					else
					{
						cout << "\t\tPassport No: ";
						cin >> Grade.passportno;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 5: //Modify age
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					cout << "\t\tAge: ";
					cin >> Grade.age;

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 6: //Modify state
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tState: ";
					cin >> Grade.state;

					while (Grade.name.find_first_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM") == string::npos)
					{
						cout << "========ERROR===================================================" << endl;
						cout << "\tInvalid Input! Please enter a valid state" << endl;
						cout << "================================================================" << endl;
						cout << "\t\tState: ";
						cin >> Grade.state;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 7: //Modify gender
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "========GENDER==================================================" << endl;
					cout << "\t[1] for Male\n";
					cout << "\t[2] for Female\n";
					cout << "================================================================" << endl;
					cout << "\t\tEnter Gender Code: ";
					cin >> Grade.menuchoice;

					while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid gender" << endl;
						cout << "========GENDER==================================================" << endl;
						cout << "\t[1] for Male\n";
						cout << "\t[2] for Female\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Gender Code: ";
						cin.clear();
						cin >> Grade.menuchoice;
					}

					switch (Grade.menuchoice)
					{
					case 1:
						Grade.gender = "Male";
						break;
					case 2:
						Grade.gender = "Female";
						break;
					default:
						Grade.gender = "N/A";
					}

					cout << "\t\tGender: " << Grade.gender << endl;

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 8: //Modify race
					system("cls"); // clear screen
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "========RACE====================================================" << endl;
					cout << " \t[1] for Malay\n";
					cout << " \t[2] for Chinese\n";
					cout << " \t[3] for Indian\n";
					cout << " \t[4] for Others\n";
					cout << "================================================================" << endl;
					cout << "\t\tEnter race code: ";
					cin >> Grade.menuchoice;

					while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid race" << endl;
						cout << "========RACE====================================================" << endl;
						cout << " \t[1] for Malay\n";
						cout << " \t[2] for Chinese\n";
						cout << " \t[3] for Indian\n";
						cout << " \t[4] for Others\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter race code: ";
						cin.clear();
						cin >> Grade.menuchoice;
					}

					switch (Grade.menuchoice)
					{
					case 1:
						Grade.race = "Malay";
						break;
					case 2:
						Grade.race = "Chinese";
						break;
					case 3:
						Grade.race = "Indian";
						break;
					case 4:
						Grade.race = "Others";
						break;
					}

					cout << "\t\tRace: ";
					cout << Grade.race << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 9: // Modify religion
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "========RELIGION================================================" << endl;
					cout << " \t[1] for Islam\n";
					cout << " \t[2] for Buddhism\n";
					cout << " \t[3] for Christianity\n";
					cout << " \t[4] for Hinduism\n";
					cout << " \t[5] for Others\n";
					cout << "================================================================" << endl;
					cout << "\t\tEnter religion code: ";
					cin >> Grade.menuchoice;

					while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3) && (Grade.menuchoice != 4) && (Grade.menuchoice != 5))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid religion" << endl;
						cout << "========RELIGION================================================" << endl;
						cout << " \t[1] for Islam\n";
						cout << " \t[2] for Buddhism\n";
						cout << " \t[3] for Christianity\n";
						cout << " \t[4] for Hinduism\n";
						cout << " \t[5] for Others\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter religion code: ";
						cin.clear();
						cin >> Grade.menuchoice;
					}


					switch (Grade.menuchoice)
					{
					case 1:
						Grade.religion = "Islam";
						break;
					case 2:
						Grade.religion = "Buddhism";
						break;
					case 3:
						Grade.religion = "Christianity";
						break;
					case 4:
						Grade.religion = "Hinduism";
						break;
					case 5:
						Grade.religion = "Others";
						break;
					default:
						Grade.religion = "N/A";
					}

					cout << "\t\tReligion: ";
					cout << Grade.religion << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 10: //Modify contact no.
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tContact number: ";
					cin >> Grade.contactno;

					while (Grade.contactno.find_first_of("1234567890") == string::npos || (Grade.contactno.size() != 10))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid contact number" << endl;
						cout << "================================================================" << endl;
						cout << "\t\tContact number: ";
						cin >> Grade.contactno;
					}
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 11: // Modify e-mail
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "\t\tE-mail: ";
					//cin.ignore;
					cin.getline(Grade.email, sizeof(Grade.email));

					while (strlen(Grade.email) < 15)//E-mail restriction
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid e-mail" << endl;
						cout << "================================================================" << endl;
						cout << "\t\tE-mail: ";
						cin.getline(Grade.email, sizeof(Grade.email));
					}
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 12: // Modify campus
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "========CAMPUS==================================================" << endl;
					cout << " \t[1] for INTI International University\n";
					cout << " \t[2] for INTI International College Subang\n";
					cout << " \t[3] for INTI International College Penang\n";
					cout << " \t[4] for INTI International College Kuala Lumpur\n";
					cout << " \t[5] for INTI College Sabah\n";
					cout << " \t[6] for INTI College Nilai\n";
					cout << "================================================================" << endl;
					cout << "\t\tEnter Campus code: ";
					cin >> Grade.menuchoice;

					while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3) && (Grade.menuchoice != 4) && (Grade.menuchoice != 5) && (Grade.menuchoice != 6))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid campus code" << endl;
						cout << "========CAMPUS==================================================" << endl;
						cout << " \t[1] for INTI International University\n";
						cout << " \t[2] for INTI International College Subang\n";
						cout << " \t[3] for INTI International College Penang\n";
						cout << " \t[4] for INTI International College Kuala Lumpur\n";
						cout << " \t[5] for INTI College Sabah\n";
						cout << " \t[6] for INTI College Nilai\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Campus code: ";
						cin.clear();
						cin >> Grade.menuchoice;
					}

					switch (Grade.menuchoice)
					{
					case 1:
						Grade.campus = "IU";
						break;
					case 2:
						Grade.campus = "IICS";
						break;
					case 3:
						Grade.campus = "IICP";
						break;
					case 4:
						Grade.campus = "IICKL";
						break;
					case 5:
						Grade.campus = "ICS";
						break;
					case 6:
						Grade.campus = "ICN";
						break;
					default:
						Grade.campus = "N/A";
					}

					cout << "\t\tCampus: " << Grade.campus << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 13: // Modify program
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					cout << "========PROGRAM=================================================" << endl;
					cout << "\t[1] for Foundation in Arts\n";
					cout << "\t[2] for Foundation in Business & IT\n";
					cout << "\t[3] for Foundation in Science\n";
					cout << "================================================================" << endl;
					cout << "\t\tEnter Program Code: ";
					cin >> Grade.menuchoice;

					while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
					{
						cout << "========ERROR===================================================" << endl;
						cout << "Invalid Input! Please enter a valid program" << endl;
						cout << "========PROGRAM=================================================" << endl;
						cout << "\t[1] for Foundation in Arts\n";
						cout << "\t[2] for Foundation in Business & IT\n";
						cout << "\t[3] for Foundation in Science\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Program Code: ";
						cin.clear();
						cin >> Grade.menuchoice;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 14: // Modify major
					system("cls");

					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					if (Grade.program == "CFAI")
					{
						cout << "========MAJOR===================================================" << endl;
						cout << "\t[1] for Mass Communication\n";
						cout << "\t[2] for Finance\n";
						cout << "\t[3] for Psychology\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Major Code: ";
						cin >> Grade.menuchoice;

						while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
						{
							cout << "========ERROR===================================================" << endl;
							cout << "\t Invalid Input! Please enter a valid major" << endl;
							cout << "========MAJOR===================================================" << endl;
							cout << "\t[1] for Mass Communication\n";
							cout << "\t[2] for Finance\n";
							cout << "\t[3] for Psychology\n";
							cout << "================================================================" << endl;
							cout << "\t\tEnter Major Code: ";
							cin >> Grade.menuchoice;
						}

						if (Grade.menuchoice == 1)
						{
							Grade.major_no = 'M';
							strncpy(Grade.major, "Mass Communication", sizeof(Grade.major));
						}
						else if (Grade.menuchoice == 2)
						{
							Grade.major_no = 'F';
							strncpy(Grade.major, "Finance", sizeof(Grade.major));
						}
						else if (Grade.menuchoice == 3)
						{
							Grade.major_no = 'P';
							strncpy(Grade.major, "Psychology", sizeof(Grade.major));
						}
						else
						{
							strncpy(Grade.major, "N/A", sizeof(Grade.major));
						}

						cout << "\t\tMajor: " << Grade.major << endl;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "========MAJOR===================================================" << endl;
						cout << "\t[1] for Business\n";
						cout << "\t[2] for Information Technology\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Major Code: ";
						cin >> Grade.menuchoice;

						while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2))
						{
							cout << "========ERROR===================================================" << endl;
							cout << "Invalid Input! Please enter a valid major" << endl;
							cout << "========MAJOR===================================================" << endl;
							cout << "\t[1] for Business\n";
							cout << "\t[2] for Information Technology\n";
							cout << "================================================================" << endl;
							cout << "\t\tEnter Major Code: ";
							cin.clear();
							cin >> Grade.menuchoice;
						}


						if (Grade.menuchoice == 1)
						{
							Grade.major_no = 'B';
							strncpy(Grade.major, "Business", sizeof(Grade.major));
						}
						else if (Grade.menuchoice == 2)
						{
							Grade.major_no = 'I';
							strncpy(Grade.major, "Information Technology", sizeof(Grade.major));
						}
						else
						{
							strncpy(Grade.major, "N/A", sizeof(Grade.major));
						}

						cout << "Major\t\t\t\t\t\t: " << Grade.major << endl;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "========MAJOR===================================================" << endl;
						cout << "\t[1] for Enginerring\n";
						cout << "\t[2] for Pure Science\n";
						cout << "\t[3] for Bio Science\n";
						cout << "================================================================" << endl;
						cout << "\t\tEnter Major Code: ";
						cin >> Grade.menuchoice;

						while ((Grade.menuchoice != 1) && (Grade.menuchoice != 2) && (Grade.menuchoice != 3))
						{
							cout << "========ERROR===================================================" << endl;
							cout << "\t Invalid Input! Please enter a valid major" << endl;
							cout << "========MAJOR===================================================" << endl;
							cout << "\t[1] for Enginerring\n";
							cout << "\t[2] for Pure Science\n";
							cout << "\t[3] for Bio Science\n";
							cout << "================================================================" << endl;
							cout << "\t\tEnter Major Code: ";
							cin.clear();
							cin >> Grade.menuchoice;
						}

						if (Grade.menuchoice == 1)
						{
							Grade.major_no = 'E';
							strncpy(Grade.major, "Engineering", sizeof(Grade.major));
						}
						else if (Grade.menuchoice == 2)
						{
							Grade.major_no = 'R';
							strncpy(Grade.major, "Pure Science", sizeof(Grade.major));
						}
						else if (Grade.menuchoice == 3)
						{
							Grade.major_no = 'O';
							strncpy(Grade.major, "Bio Science", sizeof(Grade.major));
						}

						cout << "\t\tMajor: " << Grade.major << endl;
					}


					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 15:
					system("cls");

					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					if (Grade.program == "CFAI" || Grade.program == "CFPI")
					{
						cout << "MGT1210 Fundamentals of Business Management\t\t: ";
						cin >> Grade.MGT1210;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "MAT1210 Mathematics 1\t\t\t\t: ";
						cin >> Grade.MAT1210;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 16:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						cout << "MGT1211 Introduction to Business Studies\t\t: ";
						cin >> Grade.MGT1211;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "\t\tMAT1215 Fundamentals of Mathematics: ";
						cin >> Grade.MAT1215;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "PDC1107 Self-Development Skills\t\t\t: ";
						cin >> Grade.PDC1107;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 17:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if ((Grade.program == "CFPI") || (Grade.program == "CFAI"))
					{
						cout << "PDC1107 Self-Development Skills\t\t\t\t: ";
						cin >> Grade.PDC1107;
					}
					else if (Grade.program == "CFSI")
					{
						if (Grade.major_no == 'E' || Grade.major_no == 'R')
						{
							cout << "\t\tPHY1203 General Physics 1: ";
							cin >> Grade.PHY1203;
						}
						else if (Grade.major_no == 'O')
						{
							cout << "BIO1203 Biology 1\t\t\t\t: ";
							cin >> Grade.BIO1203;
						}
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 18:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if ((Grade.program == "CFPI") || (Grade.program == "CFAI"))
					{
						cout << "CSC1208 Basic Computing\t\t\t\t\t: ";
						cin >> Grade.CSC1208;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "ENL1211 English Language Skills 1\t\t: ";
						cin >> Grade.ENL1211;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 19:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						cout << "COM1210 Introduction to Intercultural Communication\t: ";
						cin >> Grade.COM1210;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "ENL1211 English Language Skills 1\t\t: ";
						cin >> Grade.ENL1211;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "GNS1204 General Studies\t\t\t\t: ";
						cin >> Grade.GNS1204;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 20:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI" || Grade.program == "CFPI")
					{
						cout << "GNS1204 General Studies\t\t\t\t\t: ";
						cin >> Grade.GNS1204;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "MAT1211 Mathematics 2\t\t\t\t: ";
						cin >> Grade.MAT1211;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 21:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						cout << "ENL1211 English Language Skills 1\t\t\t: ";
						cin >> Grade.ENL1211;
					}
					else if (Grade.program == "CFPI")
					{
						if (Grade.major_no == 'B')
						{
							cout << "\t\tECO1207 Microeconomics: ";
							cin >> Grade.ECO1207;
						}
						else if (Grade.major_no == 'I')
						{
							cout << "\t\tCSC1213 Introduction to Database Management: ";
							cin >> Grade.CSC1213;
						}
					}
					else if (Grade.program == "CFSI")
					{
						cout << "CHM1203 Chemistry 1\t\t\t\t: ";
						cin >> Grade.CHM1203;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 22:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						cout << "\t\tENL1216 Introduction to Creative Writing: ";
						cin >> Grade.ENL1211;
					}
					else if (Grade.program == "CFPI")
					{
						if (Grade.major_no == 'B')
						{
							cout << "\t\tMGT1211 Introduction to Business Studies: ";
							cin >> Grade.MGT1211;
						}
						else if (Grade.major_no == 'I')
						{
							cout << "\t\tSTA1203 Business Statistics: ";
							cin >> Grade.STA1203;
						}
					}
					else if (Grade.program == "CFSI")
					{
						if (Grade.major_no == 'E' || Grade.major_no == 'O')
						{
							cout << "\t\tCSC1208 Basic Computing: ";
							cin >> Grade.CSC1208;
						}
						else if (Grade.major_no == 'O')
						{
							cout << "\t\tBIO1203 Biology 1: ";
							cin >> Grade.BIO1203;
						}
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 23:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					if (Grade.program == "CFAI")
					{
						cout << "\t\tCOM1211 Introduction to Mass Media: ";
						cin >> Grade.COM1211;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "\t\tENL1212 English Language Skills 2: ";
						cin >> Grade.ENL1212;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "\t\tPDC1108 Skills for Creative Thinking: ";
						cin >> Grade.PDC1108;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 24:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";

					if (Grade.program == "CFAI")
					{
						cout << "\t\tENL1212 English Language Skills 2: ";
						cin >> Grade.ENL1212;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "\t\tPDC1108 Skills for Creative Thinking: ";
						cin >> Grade.PDC1108;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "\t\tENL1212 English Language Skills 2: ";
						cin >> Grade.ENL1212;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 25:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						cout << "\t\tPDC1108 Skills for Creative Thinking: ";
						cin >> Grade.PDC1108;
					}
					else if (Grade.program == "CFPI")
					{
						cout << "\t\tCSC1211 Programming Techniques: ";
						cin >> Grade.CSC1211;
					}
					else if (Grade.program == "CFSI")
					{
						cout << "\t\tCHM1204 Chemistry 2: ";
						cin >> Grade.CHM1204;
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;
				case 26:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						if (Grade.major_no == 'M')
						{
							cout << "\t\tCOM1212 Digital Communication: ";
							cin >> Grade.COM1212;
						}
						else if (Grade.major_no == 'F')
						{
							cout << "\t\tECO1207 Microeconomics: ";
							cin >> Grade.ECO1207;
						}
						else if (Grade.major_no == 'P')
						{
							cout << "\t\tPSY1201 Fundamentals of Psychology: ";
							cin >> Grade.PSY1201;
						}
					}
					else if (Grade.program == "CFPI")
					{
						if (Grade.major_no == 'B')
						{
							cout << "\t\tECO1208 Macroeconomics: ";
							cin >> Grade.ECO1208;
						}
						else if (Grade.major_no == 'I')
						{
							cout << "\t\tCSC1212 Data Communications and Networking: ";
							cin >> Grade.CSC1212;
						}
					}
					else if (Grade.program == "CFSI")
					{
						if (Grade.major_no == 'E')
						{
							cout << "\t\tEGR1203 Engineering Mechanics: ";
							cin >> Grade.EGR1203;
						}
						else if ((Grade.major_no == 'O') || (Grade.major_no == 'R'))
						{
							cout << "\t\tBIO1204 Biology 2: ";
							cin >> Grade.BIO1204;
						}
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				case 27:
					system("cls");
					cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
					if (Grade.program == "CFAI")
					{
						if (Grade.major_no == 'M')
						{
							cout << "\t\tCOM1214 Visual Communication: ";
							cin >> Grade.COM1214;
						}
						else if (Grade.major_no == 'F')
						{
							cout << "\t\tECO1208 Macroeconomics: ";
							cin >> Grade.ECO1208;
						}
						else if (Grade.major_no == 'P')
						{
							cout << "\t\tSOC1201 Basic Sociology: ";
							cin >> Grade.SOC1201;
						}
					}
					else if (Grade.program == "CFPI")
					{
						if (Grade.major_no == 'B')
						{
							cout << "\t\tSTA1203 Business Statistics: ";
							cin >> Grade.STA1203;
						}
						else if (Grade.major_no == 'I')
						{
							cout << "\t\tMAT1214 Advanced Mathematics: ";
							cin >> Grade.MAT1214;
						}
					}
					else if (Grade.program == "CFSI")
					{
						if (Grade.major_no == 'E')
						{
							cout << "\t\tEGR1203 Engineering Mechanics: ";
							cin >> Grade.EGR1203;
						}
						else if (Grade.major_no == 'O')
						{
							cout << "\t\tSTA1202 Statistics: ";
							cin >> Grade.STA1202;
						}
						else if (Grade.major_no == 'R')
						{
							cout << "\t\tPHY1204 General Physics 2: ";
							cin >> Grade.PHY1204;
						}
					}

					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					current_time();
					system("pause");
					goto update;
					break;

				default:
					goto update;
				}
			}

		updatefile:
			fs->seekp(sizeof(Grade) * recs_num, ios::beg); // go to the first of the record to be modified
			fs->write((char*)&Grade, sizeof(Grade));
			closeFile(fs);
			system("cls");
			current_time();

			cout << "\n----------[ UPDATE RECORD ]--------------------------------------------------------------------------------------\n";
			cout << "\t Your record is updated. THANK YOU :]\t";
			cout << " Last modified on " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << setfill('0') << setw(2) << Grade.currentYear << "\t";
			cout << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			system("pause");


			break;

		case '4': ////// Delete Record //////
			cout << "\n----------[ DELETE RECORD ]--------------------------------------------------------------------------------------\n";
			cout << "\t Delete an exisitng student's information.";
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			cout << "\t\tEnter Student ID: ";
			cin >> searchStudentID;

			while (cin.fail())
			{
				system("cls");
				cout << "\n Enter Grade's ID, for deletion : ";
				cin.clear();
				cin.ignore();
				cin >> searchStudentID;
			}

			fs = new fstream(GRADE_FILE_NAME, ios::in | ios::out | ios::binary);

			if (!fs)
			{
				system("cls");
				cout << "\n----------[ DELETE RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t Can't open or create '" << GRADE_FILE_NAME << "' file." << endl;
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("pause");
				break;
			}

			recs_num = -1;

			while (fs->read((char *)&Grade, sizeof(Grade)))
			{
				recs_num++;
				if (Grade.StudentID == searchStudentID && !Grade.deleted) // if user deleted an Grade then added another one with the same ID in the same instance of program runs, deleted Grade is still there, then we should go through all the file
					break;
			}

			if (fs->eof()) // if (the record is not in the file || it's there but it's deleted)
			{
				system("cls");
				cout << "\n----------[ DELETE RECORD ]--------------------------------------------------------------------------------------\n";
				cout << "\t The specified Grade doesn't exist in database file.";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				closeFile(fs);
				system("pause");
				break;
			}

			Grade.deleted = 1;
			fs->seekp(sizeof(Grade) * recs_num, ios::beg);
			fs->write((char *)&Grade, sizeof(Grade));
			closeFile(fs);
			deletion = true; // we have some deleted records
			system("cls");

			cout << "\n----------[ DELETE RECORD ]--------------------------------------------------------------------------------------\n";
			cout << "\t Your specified Grade is deleted successfully.";
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			system("pause");
			break;

		case '5': // Display Records
			fs = new fstream(GRADE_FILE_NAME, ios::in | ios::binary);

			if (!fs)
			{
				cout << "\n----------[ DISPLAY RECORD ]-------------------------------------------------------------------------------------\n";
				cout << "\t Can't open or create '" << GRADE_FILE_NAME << "' file." << endl;
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
				system("pause");
				break;
			}
			fs->read((char *)&Grade, sizeof(Grade));
			if (Grade.deleted && !Grade.deleted > 0)
			{
				cout << "\n----------[ DISPLAY RECORD ]-------------------------------------------------------------------------------------\n";
				cout << "\t Sorry, no record is found. :[ You can try enter a new record :]";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
			}

			while (fs->read((char *)&Grade, sizeof(Grade))) // display records
			{


				if (!Grade.deleted)
				{
					cout << "\n----------[ DISPLAY RECORD ]-------------------------------------------------------------------------------------\n";
					cout << "\tStudent ID\t: " << Grade.StudentID << endl;
					cout << "\tName\t\t: " << Grade.name << endl;
					cout << "\tAddress\t\t: " << Grade.address << endl;
					cout << "\tNationality\t: " << Grade.nationality << endl;
					if (Grade.nationality == "Malaysian")
						cout << "\tIC\t\t: " << Grade.IC << endl;
					else
						cout << "\tPassport no\t: " << endl;
					cout << "\tAge\t\t: " << Grade.age << endl;
					cout << "\tState\t\t: " << Grade.state << endl;
					cout << "\tGender\t\t: " << Grade.gender << endl;
					cout << "\tRace\t\t: " << Grade.race << endl;
					cout << "\tReligion\t: " << Grade.religion << endl;
					cout << "\tContact Number\t: " << Grade.contactno << endl;
					cout << "\tE-mail\t\t: " << Grade.email << endl;
					cout << "\tMode of Study\t: " << Grade.modeofstudy << endl;
					cout << "\tYear\t\t: " << Grade.year << endl;
					cout << "\tCampus\t\t: " << Grade.campus << endl;
					cout << "\tProgram\t\t: " << Grade.program << endl;
					cout << "\tMajor\t\t: " << Grade.major << endl;
					cout << "\tDate Modified\t: " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << Grade.currentYear << endl;
					cout << "\tTime Modified\t: " << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;
					cout << "\n";
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
					cout << "CODE    COURSE DESCRIPTION\t\t\t\tCredit HOURS\tGRADE\tGRADE POINTS\tCREDIT POINTS" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

					if (Grade.program == "CFAI")
					{
						cout << "MGT1210 Fundamentals of Business Management\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
						cout << "MGT1211 Introduction to Business Studies\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
						cout << "PDC1107 Self-Development Skills\t\t\t\t";
						cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
						cout << "CSC1208 Basic Computing\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
						cout << "COM1210 Introduction to Intercultural Communication\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1210) << "\t\t" << point(Grade.COM1210)*4.0 << endl;
						cout << "GNS1204 General Studies\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
						cout << "ENL1211 English Language Skills 1\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
						cout << "ENL1216 Introduction to Creating Writing\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1216) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1216) << "\t\t" << point(Grade.ENL1216)*4.0 << endl;
						cout << "COM1211 Introduction to Mass Media\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.COM1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1211) << "\t\t" << point(Grade.COM1211)*4.0 << endl;
						cout << "ENL1212 Englsih Language Skills 2\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
						cout << "PDC1108 Skills for Creative Thinking\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

						if (Grade.major_no == 'M')
						{
							cout << "COM1212 Digital Communication\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.COM1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1212) << "\t\t" << point(Grade.COM1212)*4.0 << endl;
							cout << "COM1214 Visual Communication\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.COM1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.COM1214) << "\t\t" << point(Grade.COM1214)*4.0 << endl;
						}
						else if (Grade.major_no == 'F')
						{
							cout << "ECO1207 Microeconomics\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
							cout << "ECO1208 Macroeconomics\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
						}
						else if (Grade.major_no == 'P')
						{
							cout << "PSY1201 Psychology\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.PSY1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PSY1201) << "\t\t" << point(Grade.PSY1201)*4.0 << endl;
							cout << "SOC1201 Basic Sociology\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.SOC1201) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.SOC1201) << "\t\t" << point(Grade.SOC1201)*4.0 << endl;
						}
					}
					else if (Grade.program == "CFPI")
					{
						cout << "MGT1210 Fundamentals of Business Management\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MGT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1210) << "\t\t" << point(Grade.MGT1210)*4.0 << endl;
						cout << "MAT1215 Fundamentals of Mathematics\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1215) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1215) << "\t\t" << point(Grade.MAT1215)*4.0 << endl;
						cout << "PDC1107 Self-Development Skills\t\t\t\t";
						cout << "2.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*2.0 << endl;
						cout << "CSC1208 Basic Computing\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CSC1208) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1208) << "\t\t" << point(Grade.CSC1208)*4.0 << endl;
						cout << "ENL1211 English Language Skills 1\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
						cout << "GNS1204 General Studies\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
						cout << "ENL1212 Englsih Language Skills 2\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1212) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1212) << "\t\t" << point(Grade.ENL1212)*4.0 << endl;
						cout << "PDC1108 Skills for Creative Thinking\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PDC1108) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1108) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;
						cout << "STA1203 Business Statistics\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.PDC1108)*4.0 << endl;

						if (Grade.major_no == 'B')
						{
							cout << "MGT1211 Introduction to Business Studies\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.MGT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MGT1211) << "\t\t" << point(Grade.MGT1211)*4.0 << endl;
							cout << "ECO1207 Microeconomics\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.ECO1207) << "\t" << setprecision(2) << showpoint << point(Grade.ECO1207) << "\t\t" << point(Grade.ECO1207)*4.0 << endl;
							cout << "ACC1201 Fundamentals of Accounting\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.ACC1201) << "\t" << setprecision(2) << showpoint << point(Grade.ACC1201) << "\t\t" << point(Grade.ACC1201)*4.0 << endl;
							cout << "ECO1208 Macroeconomics\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.ECO1208) << "\t" << setprecision(2) << showpoint << point(Grade.ECO1208) << "\t\t" << point(Grade.ECO1208)*4.0 << endl;
						}
						else if (Grade.major_no == 'I')
						{
							cout << "CSC1213 Introduction to Database Management\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.CSC1213) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1213) << "\t\t" << point(Grade.CSC1213)*4.0 << endl;
							cout << "CSC1211 Programming Techniques\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.CSC1211) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1211) << "\t\t" << point(Grade.CSC1211)*4.0 << endl;
							cout << "CSC1212 Data Communications and Networking\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.CSC1212) << "\t" << setprecision(2) << showpoint << point(Grade.CSC1212) << "\t\t" << point(Grade.CSC1212)*4.0 << endl;
							cout << "MAT1214 Advanced Mathematics\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.MAT1214) << "\t" << setprecision(2) << showpoint << point(Grade.MAT1214) << "\t\t" << point(Grade.MAT1214)*4.0 << endl;
						}
					}
					else if (Grade.program == "CFSI")
					{
						cout << "MAT1210 Mathematics 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1210) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1210) << "\t\t" << point(Grade.MAT1210)*4.0 << endl;
						cout << "PDC1107 Self-Development Skills\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.PDC1107) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PDC1107) << "\t\t" << point(Grade.PDC1107)*4.0 << endl;

						if (Grade.major_no == 'E' || Grade.major_no == 'R')
						{
							cout << "PHY1203 General Physics 1\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.PHY1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1203) << "\t\t" << point(Grade.PHY1203)*4.0 << endl;
						}
						else if (Grade.major_no == 'O')
						{
							cout << "BIO1203 Biology 1\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
						}

						cout << "ENL1211 English Language Skills 1\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
						cout << "GNS1204 General Studies\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
						cout << "MAT1211 Mathematics 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;
						cout << "CHM1203 Chemistry 1\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.CHM1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CHM1203) << "\t\t" << point(Grade.CHM1203)*4.0 << endl;

						if (Grade.major_no == 'O' || Grade.major_no == 'E')
						{
							cout << "CSC1214 Basic Computing\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.CSC1214) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.CSC1214) << "\t\t" << point(Grade.CSC1214)*4.0 << endl;
						}
						else if (Grade.major_no == 'R')
						{
							cout << "BIO1203 Biology 1\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.BIO1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1203) << "\t\t" << point(Grade.BIO1203)*4.0 << endl;
						}

						cout << "PDC1108 Skills for Creative Thinking\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.ENL1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.ENL1211) << "\t\t" << point(Grade.ENL1211)*4.0 << endl;
						cout << "ENL1212 English Language Skills 2\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.GNS1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.GNS1204) << "\t\t" << point(Grade.GNS1204)*4.0 << endl;
						cout << "CHM1204 Chemistry 2\t\t\t\t\t";
						cout << "4.0" << "\t\t" << grade(Grade.MAT1211) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.MAT1211) << "\t\t" << point(Grade.MAT1211)*4.0 << endl;

						if (Grade.major_no == 'E')
						{
							cout << "EGR1203 Engineering Mechanics\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.EGR1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.EGR1203) << "\t\t" << point(Grade.EGR1203)*4.0 << endl;
							cout << "PHY1204 General Physics 2\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;

						}
						else if (Grade.major_no == 'O')
						{
							cout << "BIO1204 Biology 2\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
							cout << "STA1202 Statistics\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.STA1203) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.STA1203) << "\t\t" << point(Grade.STA1203)*4.0 << endl;
						}
						else if (Grade.major_no == 'R')
						{
							cout << "BIO1203 Biology 2\t\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.BIO1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.BIO1204) << "\t\t" << point(Grade.BIO1204)*4.0 << endl;
							cout << "PHY1204 General Physics 2\t\t\t\t";
							cout << "4.0" << "\t\t" << grade(Grade.PHY1204) << "\t" << fixed << setprecision(2) << showpoint << point(Grade.PHY1204) << "\t\t" << point(Grade.PHY1204)*4.0 << endl;
						}
					}
					cout << "-----------------------------------------------------------------------------------------------------------------\n";
				}
			}

			system("pause");
			closeFile(fs);
			break;

		case '6': // Exit
			if (deletion) // if there is any deletion, then update database file (create a new temp file that doesn't have deleted records, then remove the old database file and rename temp file to database file name)
			{
				cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
				cout << "\t Updating '" << GRADE_FILE_NAME << "' File..." << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------\n";

				fs = new fstream(GRADE_FILE_NAME, ios::in | ios::binary);
				if (!fs)
				{
					cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
					cout << "\n Can't open '" << GRADE_FILE_NAME << "' file, then Updating is incomplete." << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------\n";
					system("pause");

					system("cls");
					return 1;
				}

				fs1 = new fstream("temp", ios::out | ios::binary);
				if (!fs1)
				{
					cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
					cout << "\n Can't create temp file, then Updating is incomplete." << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------\n";
					system("pause");

					closeFile(fs);
					system("cls");
					return 1;
				}

				// write nondeleted records to the temp file
				while (fs->read((char *)&Grade, sizeof(Grade)))
					if (!Grade.deleted)
						fs1->write((char *)&Grade, sizeof(Grade));

				closeFile(fs);
				closeFile(fs1);

				if (remove(GRADE_FILE_NAME) == -1) // if there is an error
				{
					cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
					cout << "\n Can't delete '" << GRADE_FILE_NAME << "' file, then Updating is incomplete.";
					cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
					system("pause");
					system("cls");
					return 1;
				}


				struct stat st; // to check size of the temp file
				int res = stat("temp", &st);

				if (st.st_size == 0) // if all of records are deleted then the temp file size is zero                        
					remove("temp"); // we have no records, then no database file is needed, just delete the temp file
				else
					if (rename("temp", GRADE_FILE_NAME))
					{
						cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
						cout << "\t Can't rename temp file, then Updating is incomplete.";
						cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

						system("pause");

						system("cls");
						return 1;
					}

				cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
				cout << "\t Updating database file completed.";
				cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

				system("pause");
			}
			cout << "\n----------[ EXIT ]-----------------------------------------------------------------------------------------------\n";
			cout << "\t You have successfully logged out. Thank you :]";
			current_time();
			cout << "\n\t Logout Date Time: " << setfill('0') << setw(2) << Grade.currentDay << "/" << setfill('0') << setw(2) << Grade.currentMonth << "/" << setfill('0') << setw(2) << Grade.currentYear << "\t";
			cout << setfill('0') << setw(2) << Grade.currentHour << ":" << setfill('0') << setw(2) << Grade.currentMinute << ":" << setfill('0') << setw(2) << Grade.currentSecond;
			cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

			return 0;

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

string grade(int marks) // Calculate grade
{
	string grade;
	if (marks >= 90)
		grade = "A+";
	else if (marks >= 80)
		grade = "A";
	else if (marks >= 75)
		grade = "A-";
	else if (marks >= 70)
		grade = "B+";
	else if (marks >= 65)
		grade = "B";
	else if (marks >= 60)
		grade = "B-";
	else if (marks >= 55)
		grade = "C+";
	else if (marks >= 50)
		grade = "C";
	else if (marks >= 45)
		grade = "C-";
	else if (marks >= 40)
		grade = "D";
	else
		grade = "F";

	return grade;
}

double point(int marks) //Calculate GPA
{
	double point;
	if (marks >= 90)
		point = 4.00;
	else if (marks >= 80)
		point = 4.00;
	else if (marks >= 75)
		point = 3.67;
	else if (marks >= 70)
		point = 3.33;
	else if (marks >= 65)
		point = 3.00;
	else if (marks >= 60)
		point = 2.67;
	else if (marks >= 55)
		point = 2.33;
	else if (marks >= 50)
		point = 2.00;
	else if (marks >= 45)
		point = 1.50;
	else if (marks >= 40)
		point = 1.00;
	else
		point = 0.00;

	return point;
}

void current_time()
{
	time_t now = time(0); //time
	tm *ltm = localtime(&now); //time

	Grade.currentYear = 1900 + ltm->tm_year;
	Grade.currentMonth = 1 + ltm->tm_mon;
	Grade.currentDay = ltm->tm_mday;
	Grade.currentHour = ltm->tm_hour;
	Grade.currentMinute = 1 + ltm->tm_min;
	Grade.currentSecond = 1 + ltm->tm_sec;
}
