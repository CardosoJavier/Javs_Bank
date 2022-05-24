/*
*	Developer: Javier Cardoso.
*	File Name: Menus.cpp
*
*	Description:
*		A specific file to create all the functions related 
*		to the menus used in the bank interface.
*/

// libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>

// headers
#include "Javs_Bank.h"

using namespace std;

// prototypes
int userSelection();
void show_Menu();
int account_Interface();

/*
* Function name: userAccess
* 
* Function Description:
*	This function will responsible of return the user selection of 
	sign up or login. The program will terminate if the user selects
	to exit.
*
*	Information:
*		Type: int
*		Parameters: None
*		Return: login(1) or sign up(2)
*/
int userSelection() {

	int userOption;

	// prints the user access menu and makes the user to login or sign up
	cout << setw(61) << "Welcome to Javs Bank" << endl << endl;
	cout << setw(71) << "Enter the option to login or sign up:" << endl << endl;

	cout << setw(55) << "1 - Login" << endl;
	cout << setw(57) << "2 - Sign up" << endl;
	cout << setw(54) << "0 - Exit" << endl << endl;
	cout << setw(46);
	cout << "Selection: ";

	cin >> userOption;

	// if statements to make sure the user enters a valid option.
	if ((userOption == 1) || (userOption == 2)) {

		return userOption;
	}

	// else if statement to exit the program and return -1
	else if (userOption == 0) {

		cout << endl << setw(55) << "Good bye!" << endl;
		exit(0);
	}

	// else statement with a while loop to make the user 
	else {

		// prints an error message and gets the user selection again.
		cout << endl << setw(80) << "Invalid option. Select an option from the menu." << endl;
		cout << setw(44);
		cout << "Selection: ";
		cin >> userOption;

		// returns userOption if enters valid option
		if (userOption >= 0 && userOption <= 2) {

			if (userOption != 0) {

				return userOption;
			}

			else {

				cout << endl << setw(55) << "Good bye!" << endl;
				exit(0);
			}
		}

		// else statement with while loop to get the user option
		else {

			while (!(userOption >= 0 && userOption <= 2)) {

				cout << endl << setw(80) << "Invalid option. Select an option from the menu." << endl;
				cout << setw(44);
				cout << "Selection: ";
				cin >> userOption;
			}

			// ends the program if 0
			if (userOption == 0) {

				cout << endl << setw(55) << "Good bye!" << endl;
				exit(0);
			}

			// returns option if not 0
			else {

				return userOption;
			}
		}
	}

	return 0;
}

/*
* Function name: show_Menu
*
* Function Description:
*	Displays the account menu:
*		1 - Deposit
*		2 - Withdraw
*		3 - Check Balance
*		0 - Exit
*
*	Information:
*		Type: void
*		Parameters: None
*		Return: None.
*/
void show_Menu() {

	// shows the user options
	cout << "\n\n-----------------------------------------------------------------------------------------------------------------------\n\n";
	cout << endl;
	cout << setw(49) << "Welcome back, " << return_Username() << endl << endl;
	cout << setw(64) << "Choose an option from below: " << endl << endl;
	cout << setw(52) << "1 - Deposit" << endl;
	cout << setw(53) << "2 - Withdraw" << endl;
	cout << setw(58) << "3 - Check Balance" << endl;
	cout << setw(49) << "0 - Exit" << endl;
	cout << endl;
	cout << setw(46) << "Selecting: ";

}

/*
* Function name: account_Interface
*
* Function Description:
*	After the user log in, displays a table with all the options, which are:
*		1 - Deposit
*		2 - Withdraw
*		3 - Check Balance
*		0 - Exit
*	So, the function will return the user action.
*
*	Information:
*		Type: int
*		Parameters: None
*		Return: 0 - 3, int
*/
int account_Interface() {

	// prints the menu of the account, where the user will select what to do
	show_Menu();

	// switch statements to get the user option from the munu and return it.
	int userOption;
	cin >> userOption;

	// if statement to make sure the user selects a correct action.
	if (!(userOption >= 0 && userOption <= 3)) {

		// while loop to get the right input.
		while (!(userOption >= 0 && userOption <= 3)) {

			cout << endl;
			cout << setw(85) << "Wrong option. Select a valid action from the menu." << endl;
			cout << setw(46) << "Selecting: ";
			cin >> userOption;
		}

		// return the user option after the right input
		return userOption;

	}

	else {

		switch (userOption) {

			// deposit
			case 1:
				return 1;
				break;

			// withdraw
			case 2:
				return 2;
				break;

			// check balance
			case 3:
				return 3;
				break;

			//exit
			case 0:
				return 0;
				break;
		}

	}
}