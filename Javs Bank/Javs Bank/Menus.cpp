/*
*	Developer: Javier Cardoso.
*	File Name: Menus
*
*	Description:
*		A specific file to create all the functions related 
*		to the menus used in the bank interface.
*/

// libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// headers
#include "Javs_Bank.h"


/*
* Function name: userAccess
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

int userAccess() {

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