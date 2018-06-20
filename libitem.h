#ifndef item_h
#define item_h

#include <string>
using namespace std;

//header for item
class item {
	private:
		int	b_id; //item id
		float	cost;//item price
		item * 	next;//next item

	public:
		item();
		item	(int, float);//constructor
		int	getid();//gives id
		double	getcost();//gives cost
		item *	getnext();//gives next item
		void	setid(int);//sets id
		void	setcost(float);//sets cost
		void	setnext(item *);//sets next item
		virtual void	print();//prints info
		friend ostream& operator<<(ostream& st, item& it);
};

class boitem : public item //virtual function for book
{
	private:
		string name;//name of book
	public:
		boitem (string nm, int id, float co); //constructor
		void setname (string n); //set book name
		string getname();//give book name
    		void print();//print book info
};

class refitem : public item //virtual class for reference
{
        private:
                string name;//name
        public:
                refitem (string nm, int id, float co);//constructor
                void setname(string nm);//sets ref name
                string getname();//gives ref name
                void print();//prints ref info
};

class dvditem : public item //derived class for dvds
{
        private:
                string name;//name
        public:
                dvditem (string nm, int id, float co);//constructor
                void setname(string nm);//sets dvd name
                string getname();//gives dvd name
                void print();//prionts info
};

class cditem : public item //derived class for cds
{
        private:
                string name;//name
        public:
                cditem (string nm, int id, float co);//constructor
                void setname(string nm);//sets name
                string getname();//gives name
                void print();//prints info
};

#endif /* item_h */
