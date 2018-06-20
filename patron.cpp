#include <iostream>
#include <ctime>
#include <map>
#include "patron.h"
using namespace std;

//patron methods
patron::patron() {
	patid = phone = 0;
	name=address= "";
	next = NULL;
}

patron::patron(int id, string nm, string ad, int num/*float fi*/) {patid = id; nm = name; ad = address; num = phone;/*fi = fines;*/}

int patron::getid() {return patid;} //gives id

string patron::getname() {return name;} //gives name

string patron::getaddress() {return address;} //gives address

patron* patron::getnext() {return next;} //gives next node

int patron::getphone() {return phone;} //gives nuymber

//float patron::getfines() {return fines;}

void patron::setid(int id) {patid = id;} // sets id

void patron::setname(string nm) {name = nm;} //sets name

void patron::setaddress(string ad) {address = ad;} //sets address

void patron::setnext(patron* np) {next = np;} //sets next

void patron::setphone(int num) {phone = num;} //sets number

//void patron::setfines(float fi) {
//	fines = fi;
//}

void patron::print() { //prints patron information
    cout << "Patron: " << patid << endl;
    cout << "Name: " << getname() << endl;
    cout << "Number: " << getphone() << endl;

    cout << endl << endl;
}

void patron::prtlabels() {//prints mailing laber information
    cout << endl << endl;
    cout << getname() << endl;
    cout << getaddress() << endl;
    cout << endl << endl;
}
