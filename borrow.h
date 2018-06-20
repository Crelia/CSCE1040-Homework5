#ifndef borrow_h
#define borrow_h

//header for borow
class borrow {
	private:
		int 		borrow_id; //id
		int 		itemloc; //location of itrem
		int 		patloc; //location of patron
		time_t		date; //date
		borrow* 	next; //next node
		float		fines; //fines
	public:
		borrow();
		borrow(int, int, int, time_t, float); //constructor
		int getid();//gives id
    		int getpatid();// gives pat id
    		int getitemid();//gives item id
    		borrow* getnext(); //get next node
		time_t getdate(); //get date
		float getfines(); //get gines
    		void setid(int); //set id
    		void setpatid(int); //set pat id
    		void setitemid(int);//set item id
    		void setnext(borrow*); //set encxt nose
		void setdate(time_t); //set date
		void setfines(float); //set fines
    		void print();//print info
};

#endif /* borrow_h */
