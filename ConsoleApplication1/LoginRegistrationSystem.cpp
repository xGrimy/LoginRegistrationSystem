//======================================================================================================
// Name        : LoginRegistrationSystem
// Author      : xGrimy
// Version     : 1.1
// Copyright   : Copyright, 2023
// Description : This is one of the simplest projects to start with to learn about file systems in C++.
//				 The project involves a user registration process by asking username and password.
//				 Upon successful registration, a user file is created with the credentials.
//				 If the user does not exist, upon login, an error will be shown.
//				 You will also learn how to use Visual Studio to create a simple project.
// Sources	   : https://firebase.google.com/docs/storage/cpp/start
//======================================================================================================

//#include "firebase/app.h" //for cloud access
#include <string>
#include <iostream> //input/output
#include <fstream> //file handling
using namespace std;


string logid = "login";
string regid = "register";
fstream file;


int main()
{

	cout << "Welcome to LoginRegistrationSystem";
	cout.flush();

	cout << "\n Would you like to login or register?";
	string usrchoice;
	cin >> usrchoice;


	if (usrchoice == regid)
	{
		file.open("file.txt", ios::out);		//opens file and writes to it
		cout << "\n Enter your desired username";
		cout.flush();

		string usrname;
		cin >> usrname;
		cout << "\n Enter your desired password";
		cout.flush();

		string passwd;
		cin >> passwd;
		if (file.is_open())
		{
			file << usrname << " " << passwd << "\n";
		}
		file.close();
	}
	else if (usrchoice == logid)
	{
		file.open("file.txt", ios::in);		//opens file and reads from it
		cout << "Enter your username";
		cout.flush();

		string usrname;
		cin >> usrname;
		cout << "\n Enter your password";
		cout.flush();

		string passwd;
		cin >> passwd;
		string credentials = usrname + " " + passwd;
		if (file.is_open())
		{
			cout << "\n Checking database..5%";
			cout.flush();

			cout << "\n Checking database.70%";
			cout.flush();

			cout << "\n Checking database.99%";
			cout.flush();


			string readtxt;
			while (getline(file, readtxt))
			{
				if (readtxt == credentials)
				{
					cout << "\n Your information is correct, you have succesfully logged into the LoginRegistrationSystem." << endl;
				}
				else
				{
					cout << "\n Either your username or password was incorrect.";
				}
				file.close();
			}
		}

	}
	else
	{
		cout << "\n Error, please write either: login or register";
	}


	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
