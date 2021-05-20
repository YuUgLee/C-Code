
// Author: Newton Bao
// CECS 282-01 (Monday)
// Program #2 (myDate) 
// Due Date: Sept 28, 2020
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
#include <iostream>
using namespace std;
#include <string>
//Method converts Gregorian date 
//@param month The month
//@param day The day
//@param year The year
//@return JD Julian number
int Greg2Julian(int month, int day, int year){
   int I=year;
   int J= month;
   int K= day;                                                             
   int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  return JD;
}
//Method converts Julian number to Gregorian date
void Julian2Greg(int JD, int & month, int & day, int & year){
   int L=JD+68569;
   int N= 4*L/146097;
   L= L-(146097*N+3)/4;
   int I= 4000*(L+1)/1461001;
   L= L-1461*I/4+31;
   int J= 80*L/2447;
   int K= L-2447*J/80;
   L= J/11;
   J= J+2-12*L;
   I= 100*(N-49)+I+L;
                          
   year= I;
   month= J;
   day= K;
}
//Method validates the date
//@param month The month
//@param day The day
//@param year The year
//@return true if valid
//@return false if invalid
bool valid(int JD, int & month, int & day, int & year){
   int L=JD+68569;
   int N= 4*L/146097;
   L= L-(146097*N+3)/4;
   int I= 4000*(L+1)/1461001;
   L= L-1461*I/4+31;
   int J= 80*L/2447;
   int K= L-2447*J/80;
   L= J/11;
   J= J+2-12*L;
   I= 100*(N-49)+I+L;
   if (I != year || J!=month || K!=day){
     return false;
   }
   return true;
}

#include "myDate.h"
//Default Constructor to May 11,1959
myDate :: myDate(){
  m=5;
  d=11;
  y=1959;
}
//Overloaded Constructor
//@param M The month
//@param D The day
//@param Y The year
 myDate :: myDate(int M, int D, int Y){
    int JD=Greg2Julian(M,D,Y);
    if (valid(JD,M,D,Y)==true){
  m=M;
  d=D;
  y=Y;
    }
    else{
      m=5;
      d=11;
      y=1959;
    }

 }
 //Method displays the date
 void myDate :: display(){
   string month="";
   if (m==1){
     month="January";
   }
   else if (m==2){
     month="February";
   }
   else if (m==3){
     month="March";
   }
   else if (m==4){
     month="April";
   }
   else if (m==5){
     month="May";
   }
   else if (m==6){
     month="June";
   }
   else if (m==7){
     month="July";
   }
   else if (m==8){
     month="August";
   }
   else if (m==9){
     month="September";
   }
   else if (m==10){
     month="October";
   }
   else if (m==11){
     month="November";
   }
   else if (m==12){
     month="December";
   }
   cout<<month<<" "<<d<<", "<<y;
 }
 //Method increases date
 //@param N number of days
 void myDate :: increaseDate(int N){
   d+=N;
   int JD=Greg2Julian(m,d,y);
   Julian2Greg(JD,m,d,y);
 }
 //Method decreases date
 //@param N number of days
 void myDate :: decreaseDate(int N){
    d-=N;
    int JD=Greg2Julian(m,d,y);    
    Julian2Greg(JD,m,d,y);
 }
 //Methods finds days between two dates
 //@param D a date
 //@return days number of days
 int myDate :: daysBetween(myDate D){
   int JD=Greg2Julian(D.getMonth(),D.getDay(),D.getYear());
   int JD1=Greg2Julian(m,d,y);
   int days=JD-JD1;
   return days;
 }
 //Get month
 //@return m month
 int myDate ::  getMonth() const{
   return m;
 }
 //Get day
 //@return d day
 int myDate :: getDay() const{
   return d;
 }
 //Get year
 //@return y year
 int myDate :: getYear() const{
   return y;
  }
 //Finds day of year
 //@return d day of the year
 int myDate :: dayOfYear(){
   int JD=Greg2Julian(1,1,y);
   int JD1=Greg2Julian(m,d,y);
   return JD1-JD+1;
 }
 //Method finds day of the week
 //@return day of the week
  string myDate :: dayName(){
   int JD=Greg2Julian(m,d,y);
   int day=JD%7;
   if (day==0){
     return "Monday";
   }
   else if (day==1){
     return "Tuesday";
   }
   else if (day==2){
     return "Wednesday";
   }
   else if (day==3){
     return "Thursday";
   }
   else if (day==4){
     return "Friday";
   }
   else if (day==5){
     return "Saturday";
   }
   else if (day==6){
     return "Sunday";
   }
   return "";
  }