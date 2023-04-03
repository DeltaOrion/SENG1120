//LinkedListDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of a Stack that stores instances of EToll. This version of the demo uses the extended class TollStack. 

#include <iostream>
#include <cstdlib>
#include "EToll.h"
#include "TollStack.h"
using namespace std;

void initialize(TollStack<EToll> &l1, TollStack<EToll> &l2)
{
    EToll c("BYC567", "Car", 5.00);
    l1.push(c);
	c.set_all("U2KT30", "Car", 5.00);
	l1.push(c);
	c.set_all("P23SHW", "Light Truck", 8.00);
	l1.push(c);
	c.set_all("BY12PH", "Car", 8.00);
	l1.push(c);
	c.set_all("PNG890", "Truck", 12.00);
	l1.push(c);
	c.set_all("QWER45", "Truck", 12.00);
	l1.push(c);
	c.set_all("ERTC20", "Car", 5.00);
	l1.push(c);
	c.set_all("OYTCO7", "Car", 5.00);
	l1.push(c);
	
	c.set_all("GFV349", "Car", 5.00);
	l2.push(c);
	c.set_all("NIO324", "Truck", 12.00);
	l2.push(c);
	c.set_all("DTYR33", "Truck", 12.00);
	l2.push(c);
	c.set_all("UTW951", "Light Truck", 8.00);
	l2.push(c);
	c.set_all("IFTN98", "Motorcycle", 3.00);
	l2.push(c);
	c.set_all("GFCU49", "Car", 5.00);
	l2.push(c);
}

int main()
{
	TollStack<EToll> tollBooth1;
	TollStack<EToll> tollBooth2;
	TollStack<EToll> dailyReport;
	initialize(tollBooth1, tollBooth2);

	
	cout << "Start lists:" << endl;
	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily total: " << dailyReport << endl;
	
	cout << "=====================================================" << endl;
	cout << "Removing vehicle 'NIO324' from Booth 2." << endl;
	tollBooth2.remove("NIO324");
	cout << "Removing vehicle 'BYC567' from Booth 1." << endl;
	tollBooth1.remove("BYC567");
	cout << "Removing vehicle 'GFV349' from Booth 2." << endl;
	tollBooth2.remove("GFV349");
	
	cout << "Concatenating the two lists onto list 'Daily Report'." << endl << endl;
	dailyReport += tollBooth1;
	dailyReport += tollBooth2;
	cout << "=====================================================" << endl;
	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily report: " << dailyReport << endl << endl;
	
	cout << "=====================================================" << endl;
	cout << "Detailed report for the day: " << endl;
	cout << "Number of vehicles of type 'Car': ";
	cout << dailyReport.count("Car") << endl;
	cout << "Number of vehicles of type 'Motorcycle': ";
	cout << dailyReport.count("Motorcycle") << endl;
	cout << "Number of vehicles of type 'Light Truck': ";
	cout << dailyReport.count("Light Truck") << endl;
	cout << "Number of vehicles of type 'Truck': ";
	cout << dailyReport.count("Truck") << endl;
	cout << "Total charged: ";
	cout << dailyReport.totalIncome() << endl << endl;
	
	cout << "=====================================================" << endl;
	cout << "Removing the contents of both booths from the daily report: " << endl;
	dailyReport -= tollBooth1;
	dailyReport -= tollBooth2;

	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily report: " << dailyReport  << endl << endl;
	
	cout << "The program has finished." << endl;
	return 0;
	
}
