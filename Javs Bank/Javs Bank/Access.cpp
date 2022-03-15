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
#include <string>

// headers
#include "Javs_Bank.h"

using namespace std;

// prototypes
bool logIn();
void signUp();
string return_Username();

// global variables
string globalUsername = " ";

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
*		Return: no return
*/
bool logIn() {

	// variable to hold username and password entered by user
	string username;
	string password;
	string directory = "C:\\Users\\Cardo\\Desktop\\Personal Projects\\Using C++\\Javs_Bank\\Javs Bank\\Javs Bank\\Credentials\\";

	// asks and gets username and password

	cout << "Username: ";
	cin >> username;

	cout << "Password: ";
	cin >> password;

	// file object and variables to store the real credentials
	ifstream readFile;
	string usernameInfo;
	string passwordInfo;

	// bool variable to know if the files where found
	bool usernameFound, passwordFound;

	// open the file with the user and password
	string usernameFile = username + "_Username.txt";
	readFile.open(directory + usernameFile);

	// if statement to check file is open 
	if (readFile) {

		// reads the username file
		readFile >> usernameInfo;

		// close the username file
		readFile.close();

		// makes usernameFound true
		usernameFound = true;
	}

	else {

		usernameFound = false;
	}

	// same code but for password file
	string passwordFile = username + "_Password.txt";
	readFile.open(directory + passwordFile);

	// if statement to check file is open 
	if (readFile) {

		// reads the password file
		readFile >> passwordInfo;

		// close the username file
		readFile.close();

		// makes passwordFound true
		passwordFound = true;
	}

	else {

		passwordFound = false;
	}

	// if the files do not exist, return false and display an error message.
	if (usernameFound == false && passwordFound == false) {

		cout << "\nThe account does not exist. Sign up or contact customer service." << endl;

		return false;
	}

	else {

		// if statement to compare username and password entered by the user with
		// information in the system

		if ((username == usernameInfo) && (password == passwordInfo)) {

			// calls the return_Username function to send the username info to
			// Bank_System.
			globalUsername = username;
			return_Username();
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
					globalUsername = username;
					return_Username();
					access = true;
					return 1;
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

}

/*
* Function name: signUp
*
* Function Description:
*	This function will responsible of create a new username and password
*	for new users.
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: no return
*/
void signUp() {

	// asks the user to enter an username and password
	string newUsername, newPassword;
	string directory = "C:\\Users\\Cardo\\Desktop\\Personal Projects\\Using C++\\Javs_Bank\\Javs Bank\\Javs Bank\\Credentials\\";

	// creates a new balance equal to 0 since it is a new account
	double newBalance = 0.0;
	cout << "Enter an username: ";
	cin >> newUsername;

	cout << "Enter a password: ";
	cin >> newPassword;

	// creates the new files names to store the credentials.
	// also creates a balance file at the name of the user.
	string usernameFile = directory + newUsername + "_Username.txt";
	string passwordFile = directory + newUsername + "_Password.txt";
	string balanceFile = directory + newUsername + "_Balance.txt";

	// file object to save username and password in a text file.
	ofstream writeFile;

	// opens, writes, and close the username file.
	writeFile.open(usernameFile);

	writeFile << newUsername;

	writeFile.close();

	// opens, writes, and closes the password file.
	writeFile.open(passwordFile);

	writeFile << newPassword;

	writeFile.close();

	// opens, writes a balance (0), closes the balance file
	writeFile.open(balanceFile);

	writeFile << 0.0; // sets the balance of the account to 0.

	writeFile.close();

	// opens the files just created to confirm they are successfully created.
	ifstream readFile;
	string checkUsername, checkPassword;
	int checkBalance = 1;

	// opens, reads and close the file with username
	readFile.open(usernameFile);

	if (readFile) {

		readFile >> checkUsername;

		readFile.close();
	}

	else {

		cout << "\nUsername not found" << endl;
	}

	// opens, reads, and closes the file with the password
	readFile.open(passwordFile);

	if (readFile) {

		readFile >> checkPassword;

		readFile.close();
	}

	else {
		cout << "\nPassword not found" << endl;
	}

	// opens, reads, and closes the balance file
	readFile.open(balanceFile);

	if (readFile) {

		readFile >> checkBalance;

		readFile.close();

	}

	// compare the passwords and usernames to make sure the credentials where seccessfully created.
	if ((checkUsername == newUsername) && (checkPassword == newPassword) && (checkBalance == newBalance)) {

		cout << "\nAccount succesfully created. Login to access your account." << endl;
	}

	else {

		cout << "\nSomething went wrong. Try again later." << endl;
	}

}


/*
* Function name: return_Username
*
* Function Description:
*	This function will responsible to return the username using a global variable. So, the balance file is
*	usable after log in and sign up.
*
*	Information:
*		Type: string
*		Parameters: None.
*		Return: string username.
*/
string return_Username() {

	string username = globalUsername;

	return username;
}



