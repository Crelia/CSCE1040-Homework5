//Jefferson Crelia
// March 30, 2017

#ifndef borrows_h
#define borrows_h

#include "borrow.h"

class borrows {
	private:
    		int borcnt; //num of borrows
    		borrow* tail;//tail
    		borrow* head;//head
	public:
    		borrows() {borcnt = 0; head = tail = NULL;}//constructor

    		int getcount();//get borrow cont
    		borrow* gettail(); //get tail
   		borrow* gethead(); //get head
    		void inccount();//oincrease coiuht
    		void deccount();//decrease count
    		void settail(borrow*); //set tail node
    		void sethead(borrow*);//set head node
    		void addborrow();//add transaction
    		void delborrow(int, float);//delete transaction
    		borrow *findborrow(int); //find transaction
    		void cleanup();//delete all nodes
    		void prtlist(int);//proint list of all transactions
		void prtfines();// print fines
		void prtoverdues();//porint overdues
		void payfines();//pay fines
		void load(); //load from a file
		void save();// savce to a file
};

#endif /* borrows_h */
