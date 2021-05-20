
// Author: Newton Bao
// CECS 282-01 (Monday)
// Program #2 (myDate) 
// Due Date: Sept 28, 2020
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
//guard
#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;
/**
header class file
*/

class myDate /* C++ */
{
public:
//Default Constructor to May 11,1959
 myDate();
//Overloaded Constructor
//@param M The month
//@param D The day
//@param Y The year
 myDate(int M, int D, int Y);
//Method displays the date
 void display();
//Method increases date
//@param N number of days
 void increaseDate(int N);
//Method decreases date
//@param N number of days
 void decreaseDate(int N);
//Methods finds days between two dates
//@param D a date
//@return days number of days
 int daysBetween(myDate D);
//Get month
//@return m month
 int getMonth() const;
//Get day
//@return d day
 int getDay() const;
//Get year
//@return y year
 int getYear() const;
//Finds day of year
//@return d day of the year
 int dayOfYear();
//Method finds day of the week
//@return day of the week
 string dayName();
private:
 int m;
 int d;
 int y;
};

#endif