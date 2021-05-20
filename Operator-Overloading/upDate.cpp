
#include "upDate.h"
#include <iostream>
using namespace std;
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
//Initialize static variable to 0
int upDate::numdates=0;
  upDate::upDate(){
    date=new int[3];
    date[0]=5;
    date[1]=11;
    date[2]=1959;
    numdates++;

  }
  upDate::upDate(int M, int D, int Y){
    setDate(M,D,Y);
    numdates++;

  }
  upDate::upDate(const upDate&d1){
    date=new int[3];
    this->date[0]=d1.getMonth();
    this->date[1]=d1.getDay();
    this->date[2]=d1.getYear();
    numdates++;
    
  }
  upDate upDate::toGreg (int JD){
    int year, month, day;
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
   return upDate(month,day,year);
}

  void upDate::setDate(int M, int D, int Y){
    date=new int[3];
    int JD=Greg2Julian(M,D,Y);
    if (valid(JD,M,D,Y)==true){
      date[0]=M;
      date[1]=D;
      date[2]=Y; 
    }
    else{
      date[0]=5;
      date[1]=11;
      date[2]=1959;
    }

  }
  const upDate upDate::operator =(const upDate&d1){
    this->date[0]=d1.getMonth();
    this->date[1]=d1.getDay();
    this->date[2]=d1.getYear();
    
    return *this;

  }
  const upDate operator +(int num, const upDate&d1){
    int julian= d1.julian() + num;
    return d1.toGreg(julian);
 
  }

  const upDate upDate::operator +(int num)const{
    int julian= this->julian() + num;
    return toGreg(julian); 
  }
  const int upDate::operator -(const upDate&d1)const{
    return this->julian() - d1.julian();
  }
  const upDate upDate::operator -(int num) const{
    int julian= this->julian() - num;
    return toGreg(julian); 
  }
  ostream &operator<<(ostream &output, const upDate &d1 ){
    output<<d1.date[0] <<"/"<<d1.date[1]<<"/"<<d1.date[2];
    return output;
  }
  upDate::~upDate(){
    delete[] date;
    numdates--;
  }

  int upDate::getMonth( )const{
    return date[0];
  }
  int upDate::getDay( )const{
    return date[1];
  }
  int upDate::getYear( )const{
    return date[2];
  }
  double upDate::julian()const{
   int I=date[2];
   int J= date[0];
   int K= date[1];                                                             
   int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  return JD;
}
  string upDate::getMonthName( ){
    int m=date[0];
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
   return month;

  }
  int upDate::GetDateCount() {
    return numdates;
  }
    upDate& upDate::operator ++(){
      int julian=this->julian() + 1;
      Julian2Greg(julian, date[0],date[1],date[2]);
      return *this;

    }
    upDate upDate::operator ++(int n){
       upDate temp = *this;
       ++*this;
       return temp;
    }
    upDate& upDate::operator --(){
      int julian=this->julian() - 1;
      Julian2Greg(julian, date[0],date[1],date[2]);
      return *this;
    }
    upDate upDate::operator --(int n){
       upDate temp = *this;
       ++*this;
       return temp;
    }
    const bool upDate::operator >(const upDate & d1) const{
      if (this->julian()-d1.julian() > 0){
        return true;

      }
        return false;
    }
    const bool upDate::operator <(const upDate & d1) const{
      if (this->julian()-d1.julian() < 0){
        return true;

      }
        return false;
    }
    const bool upDate::operator >=(const upDate & d1) const{
      if (this->julian()-d1.julian() > 0 || this->julian()==d1.julian()){
        return true;

      }
        return false;
    }
    const bool upDate::operator <=(const upDate & d1) const{
      if (this->julian()-d1.julian() < 0 || this->julian()==d1.julian()){
        return true;

      }
        return false;
    }
    const bool upDate::operator ==(const upDate & d1) const{
      if (this->julian()==d1.julian()){
        return true;

      }
        return false;
    }
    