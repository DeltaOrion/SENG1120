//Course: SENG1120
//Coded by: Alex Mendes 

#ifndef ETOLL_H
#define ETOLL_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class EToll 
{
public:
	
	// Constructors
	EToll();
	EToll(const string, const string, const double);

	// Destructor
    ~EToll();

	// Setters
    void set_licence(const string);
	void set_type(const string);
	void set_charge(const double);
	void set_all(string licence_, string type_, double charge_);

	// Getters
	string get_licence() const;
	string get_type() const;
	double get_charge() const;

//Private member variables
private:
	string licence; // car's licence plate
	string type;	// type of vehicle
	double charge;  // value of toll
};

ostream& operator <<(ostream&, const EToll&);
bool operator == (const EToll& s1, const EToll& s2);

#endif