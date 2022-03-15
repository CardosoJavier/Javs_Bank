/*
*	Developer: Javier Cardoso.
*	File Name: Bank_System.cpp
*
*	Description:
*		A specific file to join together all the functions and logistic of the program
*		in one single function called run_System().
*/

// libraries
#include <iostream>

// headers
#include "Javs_Bank.h"

using namespace std;

// prototypes
void run_UserInterface(int& selection);

/*
* Function name: run_System
*
* Function Description:
*	Join together all the functions and logic to run the whole program.
*
*	Information:
*		Type: int
*		Parameters: None
*		Return: login(1) or sign up(2)
*/
void run_System() {

	// variable initialized with the returning value of userAccess to 
	// login or sign up

	int selection = userSelection();

	while (selection != 0) {

		// if statements to either login or sign up
		if (selection == 1) {

			// runs the user accont interface.
			run_UserInterface(selection);

		}

		else {
			// calls the signUp function to let the user create an account.
			signUp();

			// once the user creates an account, the user needs to log in or exit
			// the program.
			cout << "1 - Login\n0 - exit" << endl;
			cout << "Selection: ";
			cin >> selection;

			if (!(selection == 0 || selection == 1)) {

				while (selection != 1 && selection != 0) {

					cout << "\nInvalid option. Enter an option from the menu." << endl;

					cout << "1 - Login\n0 - exit" << endl;
					cout << "Selection: ";
					cin >> selection;
					cout << endl;
				}
			}

			// if else statement to make sure the user enters the right input
			if (selection == 1) {

				run_UserInterface(selection);
			}

			else {

				selection = 0;
			}

		}

		// stops the system
		selection = 0;
	}

}

/*
* Function name: run_UserInterface
*
* Function Description:
*	When called, run the user inteface, where the user can deposit, withdraw, etc.
*
*	Information:
*		Type: void
*		Parameters: int &selection: The user desired actions. (0 - 3)
*		Return: None
*/
void run_UserInterface(int &selection) {

	// if statement to check if access was granted
	bool checkAccess = false;
	checkAccess = logIn();

	if (checkAccess == 1) {

		int userAction = account_Interface();

		// while loop to let the user make several transactions into the account.
		while (userAction != -1) {

			string current_Username = return_Username();

			// switch statements to let the user pick an option
			switch (userAction) {

			// deposit
			case 1:

				return_Username();
				deposit();
				userAction = account_Interface();
				break;

			// withdraw
			case 2:

				return_Username();
				withdraw();
				userAction = account_Interface();
				break;

			// check balance
			case 3:

				return_Username();
				check_Balance();
				userAction = account_Interface();
				break;

			// exit
			case 0:

				return_Username();
				exit();
				userAction = -1;
				break;
			}
		}

	}

	else {
		// if login function return false, returns 0 to ented the program.
		selection = 0;
	}

}