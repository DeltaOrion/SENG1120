//Course: SENG1120
//Coded by: Alex Mendes 

#include "EToll.h"
#include <cstdlib>

// Constructors
EToll::EToll()
{
	licence = "";
	type = "";
	charge = 0;
}

EToll::EToll(string licence_, string type_, double charge_)
{
	licence = licence_;
	type = type_;
	charge = charge_;
}

// empty destructor
EToll::~EToll(){}

// Mutator methods (setters)
void EToll::set_licence(const string licence_) {licence = licence_;}
void EToll::set_type(const string type_){ type = type_;}
void EToll::set_charge(const double charge_){ charge = charge_;}
void EToll::set_all(string licence_, string type_, double charge_)
{
	licence = licence_;
	type = type_;
	charge = charge_;
}

// Accessor methods (getters)
string EToll::get_licence() const {return licence;}
string EToll::get_type() const {return type;}
double EToll::get_charge() const {return charge;}

// overloaded ostream operator
ostream& operator <<(ostream& out, const EToll& value)
{
    out << "(" << value.get_licence() << "," << value.get_type() << ") ";
    return out;
}

// overloaded == operator
bool operator == (const EToll& s1, const EToll& s2)
{
    if (s1.get_licence() == s2.get_licence())
		return true;
	else
		return false;
}
