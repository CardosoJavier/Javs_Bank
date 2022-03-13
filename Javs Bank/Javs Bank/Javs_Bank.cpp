/*
*	Developer: Javier Cardoso.
*	Project Name: Javs Bank
*
*	Description:
*		A bank system and interface where the user will be able to
*		make basic bank transactions:
*
*			Fist stage:
*				- sign in or login.
*				- deposit.
*				- withdraw.
*				- consult balance.
*/

// libraries
#include <iostream>
#include <string>
#include <fstream>

// files 
#include "Javs_Bank.h"

using namespace std;


// main function
int main(void) {

	// variable initialized with the returning value of userAccess to 
	// login or sign up

	int selection = userSelection();

	while (selection != 0) {

		// if statements to either login or sign up
		if (selection == 1) {

			// if statement to check if access was granted
			bool checkAccess = false;
			checkAccess = logIn();

			if (checkAccess == true) {

				cout << "\nWelcome back" << endl;
				selection = 0;

			}

			else {

				selection = 0;
			}

		}

		else {

			signUp();

			cout << "1 - Login\n0 - exit" << endl;
			cout << "Selection: ";
			cin >> selection;

			if ((selection == 1) || (selection == 0)) {

				selection == selection;
			}

			else {
				
				while (selection != 1 && selection != 0) {

					cout << "\nInvalid option. Enter an option from the menu." << endl;

					cout << "1 - Login\n0 - exit" << endl;
					cout << "Selection: ";
					cin >> selection;
				}
			}
		}

	}

	cout << "\nGood bye!" << endl;

	return 0;
}


