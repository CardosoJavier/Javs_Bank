/*
*	Developer: Javier Cardoso.
*	File Name: Access.cpp
*
*	Description:
*		File to store the functions related to grant access to
*		the user by login or sign up.
*/

// libraries
#include <iostream>
#include <cstdlib>
#include <fstream>

// headers
#include "Javs_Bank.h"

using namespace std;


/*
* Function name: logIn
*
* Function Description:
*	This function will responsible of the sign up and login
*	of the user.
*
*	Information:
*		Type: int
*		Parameters: None
*		Return: login(1) or sign up(2)
*/
bool logIn() {

	// variable to hold username and password entered by user
	string username;
	string password;

	// asks and gets username and password

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	// file object and variables to store the real credentials
	ifstream readFile;
	string usernameInfo;
	string passwordInfo;

	// open the file with the user and password
	readFile.open("Javs.txt");

	// if statement to check file is open 
	if (readFile) {

		// reads the username file
		readFile >> usernameInfo;

		// close the username file
		readFile.close();
	}

	else {

		cout << "Error opening the username file" << endl;
	}

	// same code but for password file
	readFile.open("password.txt");

	// if statement to check file is open 
	if (readFile) {

		// reads the password file
		readFile >> passwordInfo;

		// close the username file
		readFile.close();
	}

	else {

		cout << "Error opening the password file" << endl;
	}

	// if statement to compare username and password entered by the user with
	// information in the system

	if ((username == usernameInfo) && (password == passwordInfo)) {

		return true;
	}
	// display error message when credentials do not match

	else {

		// display error message
		cout << endl << "Wrong username or password. You have 3 remaining attempts." << endl;

		// while loop to let the user enter credentials three times
		int attempt = 1;
		bool access = false;
		char again = ' ';

		while (((attempt < 4) && (access == false))) {

			cout << "\nAttept #" << attempt << endl;

			// gets username and password again
			cout << "Username: ";
			cin >> username;

			cout << "Password: ";
			cin >> password;

			// checks for the right credentials with the new input
			if ((username == usernameInfo) && (password == passwordInfo)) {

				// set access to granted to stop the while loop and return true
				access = true;
				return true;
			}

			else {

				// decrease attempt by 1
				attempt++;

				// if statement to avoid ask the user to try again after the third attempt.
				if (attempt > 3) {

					return false;
				}

				// asks the user if wants to try again or exit the program
				cout << "\nWrong username or password." << endl;
				cout << "Do you want to try again? [y/n] ";
				cin >> again;
				cout << endl;

				//  if the user wants do not want to login, exit the program.
				if (again == 'n') {

					cout << "\nGood bye!" << endl;
					exit(0);
				}

			}

		}

		// displays a message if the user did not enter the correct credentials after
		// the third time.
		cout << "\nRemaining attepts: " << attempt << endl;
		cout << "Contact customer service. Good bye!" << endl;

	}

}