/*
=====================================================================================================
Name:			Jefferson Crelia		JeffersonCrelia@my.unt.edu
Instructor:		David Keathly
Date:			April 12, 2017
Description:		Program used for book-keeping in a library
=====================================================================================================
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include "functions.h"
#include "patron.h"
#include "patrons.h"
#include "borrow.h"
#include "borrows.h"
#include "libitem.h"
#include "catalog.h"


using namespace std;

int main(int argc, const char * argv[])
{
	patrons pats;
	items inventory;
	borrows transactions;

	int choice = -1;
	int id = 0;
	float fines;

	prtinfo();//print course and personal info
	pats.load();//load from file
	inventory.load();//load from file
	transactions.load();//load from file

	while (choice != 0)// creating menu
	{
		cout << "What do you want to do?\n";
		cout << " 0  - quit\n 1  - Add patron\n 2  - Edit patron\n 3  - Remove patron\n 4  - Print list of patrons\n 5  - Print list of a patrons fines\n 6  - Add new item\n 7  - Edit item\n 8  - Remove item\n 9  - Print list of a patrons items\n 10 - Check out a item\n 11 - Check in a item\n 12 - Pay fines\n 13 - Print overdues\n 14 - Print adress mailing labels\n\n";
		cout << "Enter your selection: ";
		cin  >> choice;

		switch (choice)
		{

		case 1: pats.addpat(); break; //add patron
		case 2: {
				cout << "Patron ID: ";
				cin >> id;
				pats.editpat(id);
				break;
			 }//edit patron

		case 3:  {
				cout << "Patron ID: ";
				cin >> id;
				pats.delpat(id);
				break;
			}//remove patron

		case 4: pats.prtlist() ; break; //print patrons
		case 5: transactions.prtfines(); break; //print patron fines
		case 6: inventory.additem(); break; //add item
		case 7: {
				cout << "Item ID: ";
				cin >> id;
				inventory.edititem(id);
				break;
			 }//edit item

		case 8:  {
                                cout << "Item ID: ";
                                cin >> id;
                                inventory.delitem(id);
                                break;
                        }//remove item

		case 9:  {
				cout << "Patron ID: ";
				cin >> id;
				transactions.prtlist(id);
				break;
			  }//print list of patrons items
		case 10: transactions.addborrow(); break; //check out item
		case 11: {
				cout << "Borrow ID: ";
				cin >> id;
				transactions.delborrow(id, fines);
				break;
			 }//record returned item
		case 12: transactions.payfines(); break; //pay fines
		case 13: transactions.prtoverdues(); break; //print overdues
		case 14: pats.prtlabels();; break; //print mailing labels
		}
	}

	//save to drive
	pats.save();
	inventory.save();
	transactions.save();

	//clear nodes
	pats.cleanup();
	inventory.cleanup();
	transactions.cleanup();


	return 0;
}
