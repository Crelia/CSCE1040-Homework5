#ifndef patron_h
#define patron_h

#include <string>
using namespace std;

//header for patron
class patron {
	private:
		int			patid; //patron id
		string			name; //patrons name
		string			address; //patrons address
		patron *		next; //next
		int			phone; //patrons number
		//float			fines;
	public:
		patron();
		patron(int, string, string, int); //constructor
		int			getid(); //gives id
		string			getname();//gives name
		string			getaddress(); //gives address
		patron *		getnext();//gives next node
		int			getphone();//gives phoone
		//float			getfines();
		void			setid(int id);//sets id
		void			setname(string nm);//sets name
		void			setaddress(string ad);//sets addrress
		void			setnext(patron*);//sets next patron
		void			setphone(int num);//sets phone
		//void			setfines(float fi);
		double			balance;//compute balance
		int			numofitems;
		int			status;
		void			print();//print patron info
		void			prtlabels();//print label info
};
 #endif /* patron_h */
