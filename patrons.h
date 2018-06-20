// Jefferson Crelia
// March 3, 2017

#ifndef patrons_h
#define patrons_h

#include <map>
#include "patron.h"
#include <string>

using namespace std;

class patrons {
	private:
		int patcnt; //counter
		patron* tail; //tail
		patron* head; //head
		//typedef map<int, patron*> pattype;
		//pattype patronlist;
	public:
		patrons() {patcnt = 0;} //constructor
		int getcount(); //returns count
		patron* gettail(); //returns tail
		patron* gethead(); //returns head
		void inccount(); //increase count
		void deccount(); //decrease count
		void settail(patron*); //sets tail
		void sethead(patron*); //sets head
		void addpat(); //add patron
		void editpat(int); //edit patron
		void delpat(int); //delete patron
		patron* findpat(int); //find patron
		void cleanup(); //delete everything
		void prtlist(); //print list of patrons
		void prtlabels(); //print mailing labels
		void load(); //load from a file
		void save(); //save to a file
};

#endif /* patrons_h */
