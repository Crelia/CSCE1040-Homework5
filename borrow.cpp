#include <iostream>
#include <string>
#include <time.h>
#include "borrow.h"
#include <time.h>
using namespace std;

//borrow methods
borrow::borrow() {
	borrow_id = itemloc = patloc = 0;
	next = NULL;
	date = time(NULL);
	fines = 0.00;
}//cpmstructor

borrow::borrow(int id, int id2, int id3, time_t  dt, float fi) {borrow_id = id; patloc = id2; itemloc = id3; date = dt; fines = fi;}

int borrow::getid() {return borrow_id;} //gives borrow id

int borrow::getpatid() { return patloc;} //gives patron id

int borrow::getitemid() {return itemloc;} //gives item id

time_t borrow::getdate() {return date;} //gives date

borrow* borrow::getnext() {return next;} //gives next node

float borrow::getfines() {return fines;} //gives gines

void borrow::setid(int id) { borrow_id = id;} //sets id

void borrow::setpatid(int id) {patloc = id;} //sets pat id

void borrow::setitemid(int id) {itemloc = id;} //sets item id

void borrow::setnext(borrow* np) {next = np;} //sets next node

void borrow::setdate(time_t dt) {date = dt;} //sets date

void borrow::setfines(float fi) {fines = fi;}//sets fines

void borrow::print() { //p[rints info
    cout << "Borrow id: " <<borrow_id << "Patron: " << patloc << "Item: " <<itemloc <<endl;
}
