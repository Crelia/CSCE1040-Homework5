#include "patrons.h"
#include "borrows.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//patrons methods
//patrons::patrons() {head = NULL; tail = NULL; patcnt = 0;}

int patrons::getcount() { return patcnt;}

patron* patrons::gettail() {return tail;}

patron* patrons::gethead() {return head;}

void patrons::inccount() {patcnt++;}

void patrons::deccount() { patcnt--;}

void patrons::settail(patron* tp) {tail = tp;}

void patrons::sethead(patron* hp) {head = hp;}

void patrons::addpat(){
	int id, num;
	string name, address;

	patron *temp = new patron();

	cout << "\n\nWhat is the patron name: " << endl;
	cin.ignore();
	getline(cin, name); //get patron name

	cout << "What is the patron address: " << endl;
	cin.ignore();
	getline(cin, address); //get patron address

	cout << "What is the phone number: " << endl;
	cin >> num; //get patron number

	cout << "What would you like the ID to be: " << endl;
	cin >> id; //get patron id

	temp->setid(id); //set id
	temp->setname(name); //set patron name
	temp->setaddress(address); //set address
	temp->setphone(num); //set phone

	if(patcnt == 0) //if there are no patrons
	{
		head = tail = temp; //set temp to haed and tail
	}
	else
	{
		tail->setnext(temp); //add temp to the tail
		tail = temp;
	}
	patcnt++; //add to count

	cout << endl << endl;
	return;
}


void patrons::editpat(int)
{
    int id, num;
    string name, address;

    patron *temp, *temp2;

    if (patcnt == 0 ) return; //if there arent any patrons, quit

    temp2 = head;
    temp = head->getnext();

    while (temp != tail) //while the head isnt the tail
    {
    	if (temp->getid() == id)
    	{
        	cout << "\n\nEnter the same or new name: ";
		getline(cin, name);
		cin.ignore();//get new name

		cout << "Enter the same or new address: ";
		getline(cin, address);//get new address

		cout << "Enter the same or new phone: ";
		cin >> num;//get new phone

		temp->setname(name); //set name
		temp->setaddress(address); //set address
		temp->setphone(num); //set phone

		cout << endl << endl;

		return;
	}

	else
	{
		temp2 = temp;
		temp = temp->getnext();//get the next patron to check
	}
    }
}



void patrons::delpat(int id)
{
    patron *temp, *temp2;

    if (patcnt == 0 ) return; //if no patrons, quit to menu
    if (head == tail && head->getid() == id)
    {
        head = tail = NULL; //the node is set to NULL
        patcnt = 0; //sount is ddropped to 0
        return;
    }


    temp2 = head;
    temp = head->getnext();
    while (temp != tail) // there is more than one node
    {
        if (temp->getid() == id) //if correct id
        {
            temp2->setnext(temp->getnext());
            delete temp;//delete the patron
            deccount(); //decreasse count by 1
            return;
        }
        else
        {
            temp2 = temp;
            temp = temp->getnext(); //continue until the correct node
        }
    }

    cout << endl << endl;
}

patron* patrons::findpat(int id)
{
    patron *temp;
    temp = head;
    while (temp != NULL)
    {
         if (temp->getid() == id)
             return temp;
        else
        temp = temp->getnext();
    }
    return NULL;

}

void patrons::cleanup() //deletes all nodes (done after saving to a file)
{
    patron *temp;
    temp = head;
    while (temp != NULL)
    {
        patron *temp2;
        temp2 = temp->getnext();
        delete temp; //get rid or nodes
        temp = temp2;
    }
}

void patrons::prtlist()
{
    patron *temp;
    temp = head;
    while (temp != NULL)
    {
        patron *temp2;
        temp2 = temp->getnext();
	temp->print();//go to patron.print
        temp = temp2;
    }
}

void patrons::prtlabels()
{
	patron *temp;
	temp = head;
	while (temp != NULL)
	{
		patron *temp2;
		temp2 = temp->getnext();

		temp->prtlabels();//go to patron.prtlabels

		temp = temp2;
	}
}


void patrons::load()
{
	ifstream in;

	int id, num;
	string name, address;

	in.open("patrons"); //opens a file for patrons

	if(in.fail())
	{
		cout << "Could not open loading file! Exiting to main." << endl; //error message
		return;
		//exit(EXIT_FAILURE); //exits the prgram if the file cannot open
	}

	while(!in.eof())// while not the end of the file
	{
		patron *temp = new patron(); // initialise new patron

		in >> id; //reads in id

		in.ignore();
		getline(in, name); //reads in name

		in.ignore();
		getline(in, address); //reads in name

		in >> num;

		temp->setid(id); //set id

		temp->setname(name); //set name

		temp->setaddress(address); //set address

		temp->setphone(num); //set phone

		if(patcnt == 0)
		{
			head = tail = temp; //says there is one node
		}
		else
		{
			tail->setnext(temp); //sets the next node to be temp

			tail = temp;
		}
		patcnt++; //add one to pat counter
	}

	in.close(); //close instream file

	return;
}


void patrons::save(){
	patron *temp;

	ofstream out; //out file = out

	out.open("patrons"); //open save file

	if(out.fail()) //if file open fails
	{
		cout << "Could not open patron file! Exiting now." << endl; //error message
		exit(EXIT_FAILURE);
	}

	temp = gethead(); //gets head of node

	while(temp != NULL)
	{
		out << temp->getid() << endl; //print out id

		out << temp->getname() << endl; //print out name

		out << temp->getaddress() << endl; //print out address

		out << temp->getphone() << endl; //print out phone

		temp = temp->getnext(); //go to next node
	}

	out.close(); //close out stream file

	return;
}
