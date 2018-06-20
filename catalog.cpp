#include <iostream>
#include <fstream>
#include <map>
#include "catalog.h"
#include "libitem.h"

using namespace std;

//items methods

int items::getcount() {return itemcnt;} //give item count

item* items::gettail() {return tail;} //give tail

item* items::gethead() {return head;} //give head

void items::inccount() {itemcnt++;} //increase coubt

void items::deccount() {itemcnt--;} //deccrease count

void items::settail(item* tp) {tail = tp;} //set tail node

void items::sethead(item* hp) {head = hp;} //set head node

void items::additem() //add an item
{
    int id; float co, otype;
    item *temp;
    string nm;

    cout << "Enter new item ID: " << endl;
    cin >> id;
    cin.ignore();//get item id

    cout << "Enter cost: " << endl;
    cin  >> co;//get cost

    cout << "Enter 1 for a book, 2 for a reference, 3 for a DVD, or 4 for a CD: " << endl;
    cin >> otype;
    cin.ignore();//get wehat type of item

    cout << "Enter the date the name of the title of the item: "<< endl;
    cin >> nm;//get name

    if (otype == 1)//if book
    {
	temp = new boitem(nm, id, co);
    }
    if (otype == 2)//if reference
    {
	temp = new refitem(nm, id, co);
    }
    if (otype == 3)//if dvd
    {
	temp = new dvditem(nm, id, co);
    }
    if (otype == 4) //if cd
    {
	temp = new cditem(nm, id, co);
    }

    if (itemcnt == 0)
    {
	head = tail = temp; //set teh head/tail = to temp
    }
    else
    {
	tail->setnext(temp); //add tail and set it equal to temp
	tail = temp;
    }
    inccount(); //increase count

}

void items::edititem(int id) //edit an item
{
    int co, otype;
    string nm;
    item *temp, *temp2;

    if (itemcnt == 0 ) return;//iof there is no count

    cout << "For a book enter 1, for a reference enter 2, for a dvd enter 3, or for a cd enter 4: " << endl;
    cin >> otype;//get whay type of item

}


void items::delitem(int id)
{
    item *temp, *temp2;

    if (head == tail && head->getid() == id) //if only one item
    {
	head = tail = NULL;//set to null
	deccount(); //decrease count
	return;
    }

    temp2 = head;
    temp = head->getnext();
    while (temp != tail) //while not at end
    {
	if (temp->getid() == id)
	{
		temp2->setnext(temp->getnext());
		delete temp; //delete node
		deccount();
		return;
	}
    	else
    	{
		temp2 = temp;
		temp = temp->getnext(); //go to next node
    	}
    }
}

/*item* items::finditem(int id)
{
    cout << "Heres your item: " << endl;
}*/

void items::cleanup()
{
    item *temp;
    temp = head;
    while (temp != NULL)
    {
	item *temp2;
	temp2 = temp->getnext();
	delete temp;
	temp = temp2;//delete all nodes bnasicallyt
    }
}

void items::prtlist()//print list of all items
{
    item *temp;
    temp = head;
    while (temp != NULL)
    {
	item *temp2;
	temp2 = temp->getnext();
	cout << *(temp);
	temp = temp2;
    }
}

void items::load() { //load from a file
	ifstream in;
	int b_id, co;
	string name;
	in.open("items"); //opens a file for patrons
	if(in.fail())
	{
		cout << "Could not open loading file! Bringing you to menu." << endl; //error message
		return;
	}

	while(!in.eof())// while not the end of the file
	{
		item *temp = new item();

		in >> b_id;

		in >> co;

		in.ignore();
		getline(in, name);

		temp->setid(b_id);

		temp->setcost(co);

		//temp->setname(name);

		if(itemcnt == 0)
		{
			head = tail = temp;
		}
		else
		{
			tail->setnext(temp);
			tail = temp;
		}
		itemcnt++;
	}
	in.close();
	return;
}
void items::save() //save to a file
{
	item *temp;

	ofstream out;

	out.open("items"); //open save file

	if(out.fail())
	{
		cout << "Could not open item file! Exiting now." << endl; //error message
		return;
	}

	temp = gethead();

	while(temp != NULL)
	{
		out << temp->getid() << endl;

		out << temp->getcost() << endl;

		// out << temp->getname() << endl;

		temp = temp->getnext();
	}
	out.close();
	return;
}
