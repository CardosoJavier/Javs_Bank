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

	// if statements to either login or sign up
	if (selection == 1) {
		
		// if statement to check if access was granted
		bool checkAccess = false;
		checkAccess = logIn();

		if (checkAccess == true) {

			cout << "\nWelcome back" << endl;
		}

		else {

			cout << "\nContact customer service." << endl;
		}

	}

	else {

		cout << "\nSign up" << endl;
	}

	return 0;
}


