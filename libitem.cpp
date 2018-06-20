#include <iostream>
#include <string>
#include "libitem.h"
using namespace std;

//item methods
item::item() {
        b_id = cost = 0;
        next = NULL;
}

item::item (int id, float co)  {b_id = id; cost = co;} //declaration of constructor

int item::getid()  {return b_id;} //gives the item id when called

double item::getcost() {return cost;} //gives the cost of the item when called

item * item::getnext() {return next;} //gives the next node

void item::setid(int id) {b_id = id;} //sets the item id

void item::setcost(float co) {cost = co;} //sets the items cost

void item::setnext(item *np) {next = np;} //sets the value of next

void item::print() {
    cout << "Item ID: " << b_id << endl;
    cout << "Cost: " << cost << endl << endl;
} //prints item info







boitem::boitem (string nm, int id, float co):item (id, co) //declaration of constructor
{
	name = nm;
}

void boitem::setname(string nm) {name =  nm;}
string boitem::getname () {return name;} //fives the name when called
void boitem::print ()
{
	item::print();
	cout << "Name: " << name << endl;
} //prints the items information







refitem::refitem (string nm, int id, float co):item (id, co) //declaration of constructor
{
        name = nm;
}

void refitem::setname(string nm) {name =  nm;}
string refitem::getname () {return name;} //fives the name when called
void refitem::print ()
{
        item::print();
        cout << "Name: " << name << endl;
} //prints the items information





dvditem::dvditem (string nm, int id, float co):item (id, co) //declaration of constructor
{
        name = nm;
}

void dvditem::setname(string nm) {name =  nm;}
string dvditem::getname () {return name;} //fives the name when called
void dvditem::print ()
{
        item::print();
        cout << "Name: " << name << endl;
} //prints the items information






cditem::cditem (string nm, int id, float co):item (id, co) //declaration of constructor
{
        name = nm;
}

void cditem::setname(string nm) {name =  nm;}
string cditem::getname () {return name;} //fives the name when called
void cditem::print ()
{
        item::print();
        cout << "Name: " << name << endl;
} //prints the items information



ostream& operator<<(ostream& st, item& it)
{
	it.print();
	return st;
}
