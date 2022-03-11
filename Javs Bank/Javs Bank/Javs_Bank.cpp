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
#include <iomanip>
#include <fstream>

// files 
#include "Javs_Bank.h"

using namespace std;


// main function
int main(void) {

	// variable initialized with the returning value of userAccess to 
	// login or sign up

	int accessTo = userAccess();

	// if statements to either login or sign up
	if (accessTo == 1) {

		cout << "Login" << endl;
	}

	else {

		cout << "Sign up" << endl;
	}


	return 0;
}


