// LinkedListDemo - Main Program
/*******************************/
// Author: SENG1120 Staff
// Course: SENG1120
// Program Description: This program demonstrates the basic functionality of a linked list that stores student names and scores. 
// It will demo the functions of a basic linked list.
// The program adds content to a linked list, removes individual nodes, among other functionalities.

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "EToll.h"
using namespace std;

// Add Content to Linked List
void initialize(LinkedList &l1, LinkedList &l2)
{
	EToll c("BYC567", "Car", 5.00);
	l1.addToTail(c);						// .addToTail() function
	c.set_all("U2KT30", "Car", 5.00);
	l1.addToTail(c);
	c.set_all("P23SHW", "Light Truck", 8.00);
	l1.addToTail(c);
	c.set_all("BY12PH", "Car", 8.00);
	l1.addToTail(c);
	c.set_all("PNG890", "Truck", 12.00);
	l1.addToTail(c);
	c.set_all("QWER45", "Truck", 12.00);
	l1.addToTail(c);
	c.set_all("ERTC20", "Car", 5.00);
	l1.addToTail(c);
	c.set_all("OYTCO7", "Car", 5.00);
	l1.addToTail(c);
	
	c.set_all("GFV349", "Car", 5.00);
	l2.addToHead(c);						// .addToHead() function
	c.set_all("NIO324", "Truck", 12.00);
	l2.addToHead(c);
	c.set_all("DTYR33", "Truck", 12.00);
	l2.addToHead(c);
	c.set_all("PNG890", "Light Truck", 12.00);
	l2.addToHead(c);
	c.set_all("IFTN98", "Motorcycle", 3.00);
	l2.addToHead(c);
	c.set_all("GFCU49", "Car", 5.00);
	l2.addToHead(c);
}

// Entry Point
int main()
{
	// create three linked lists
	LinkedList tollBooth1;
	LinkedList tollBooth2;
	LinkedList dailyReport;
	
	// add data
	initialize(tollBooth1, tollBooth2);

	cout << "Start lists:" << endl;
	cout << "Booth 1: " << tollBooth1 << endl;		// stream insertion operator (ie: operator <<)
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily total: " << dailyReport << endl;
	
	cout << "=====================================================" << endl;
	cout << "Removing vehicle 'NIO324' from Booth 2." << endl;
	tollBooth2.remove("NIO324");					// .remove() function
	cout << "Removing vehicle 'BYC567' from Booth 1." << endl;
	tollBooth1.remove("BYC567");
	cout << "Removing vehicle 'GFV349' from Booth 2." << endl;
	tollBooth2.remove("GFV349");
	
	cout << "Concatenating the two lists onto list 'Daily Report'." << endl << endl;
	dailyReport += tollBooth1;						// concatenation operator (ie: operator +=)
	dailyReport += tollBooth2;
	cout << "=====================================================" << endl;
	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily report: " << dailyReport  << endl << endl;

	cout << "=====================================================" << endl;
	cout << "Detailed report for the day: " << endl;
	cout << "Number of vehicles of type 'Car': ";
	cout << dailyReport.count("Car") << endl;		// .count() function
	cout << "Number of vehicles of type 'Motorcycle': ";
	cout << dailyReport.count("Motorcycle") << endl;
	cout << "Number of vehicles of type 'Light Truck': ";
	cout << dailyReport.count("Light Truck") << endl;
	cout << "Number of vehicles of type 'Truck': ";
	cout << dailyReport.count("Truck") << endl;
	cout << "Total charged: ";
	cout << dailyReport.totalIncome() << endl << endl;  	// .totalIncome() function
	
	cout << "=====================================================" << endl;
	cout << "Removing the contents of both booths from the daily report: " << endl;
	dailyReport -= tollBooth1;						// remove overlap (ie: operator -=)
	dailyReport -= tollBooth2;

	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl;
	cout << "Daily report: " << dailyReport  << endl << endl;
	
	//For bonus question, uncomment this section
	cout << "=====BONUS QUESTION======" << endl;
	cout << "Ordering the two toll booths." << endl;
	tollBooth1.order();
	tollBooth2.order();
	cout << "Booth 1: " << tollBooth1 << endl;
	cout << "Booth 2: " << tollBooth2 << endl << endl;
		
	cout << "The program has finished." << endl;
	return 0;
}
