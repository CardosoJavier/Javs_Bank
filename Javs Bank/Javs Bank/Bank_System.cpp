// libraries
#include <iostream>

// headers
#include "Javs_Bank.h"
using namespace std;

void run_System() {

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
			// calls the signUp function to let the user create an account.
			signUp();

			// once the user creates an account, the user needs to log in or exit
			// the program.
			cout << "1 - Login\n0 - exit" << endl;
			cout << "Selection: ";
			cin >> selection;

			// if else statement to make sure the user enters the right input
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

}