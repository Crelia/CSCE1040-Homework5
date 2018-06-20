// Jefferson Crelia
// March 3, 2017

#ifndef catalog_h
#define catalog_h

#include "libitem.h"

class items {
	private:
		int itemcnt;//counter
		item* tail;//tail
		item* head;//head
	public:
		items() { itemcnt = 0; /*head = tail = NULL;*/}

    		int getcount();//get item count
	   	item* gettail();//gets tail node
    		item* gethead();//gets head node
    		void inccount();//increase counter
    		void deccount();//decrease counter
    		void settail(item*);//sewt tail
    		void sethead(item*);//set head
    		void additem();//add an item
		void edititem(int);//edit an item
    		void delitem(int);//delete an item
//    		item *finditem(int);
    		void cleanup();//delete all nodes
    		void prtlist();//print list of all items
		void load();//load to a file
		void save();//save to a file
};

#endif /* catalog_h */
