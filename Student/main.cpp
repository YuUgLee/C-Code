
// Author: Newton Bao
// CECS 282-01 (Monday)
// Program #3 (Student Struct) 
// Due Date: Oct 12, 2020
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
#include <iostream>
using namespace std;
#include <string.h>
#include <cstring>
#include <iomanip>

class myDate /* C++ */
{
public:
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
//Default Constructor to May 11,1959
 myDate(){
  m=5;
  d=11;
  y=1959;
 }
 //Overloaded Constructor
//@param M The month
//@param D The day
//@param Y The year
  myDate(int M, int D, int Y){
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
//Method prints date to string
 string toString() {
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
   string date=month+" "+to_string(d)+", "+to_string(y);
   return date;
 }

//Methods finds days between two dates
//@param D a date
//@return days number of days
 int daysBetween(myDate D){
   int JD=Greg2Julian(D.getMonth(),D.getDay(),D.getYear());
   int JD1=Greg2Julian(m,d,y);
   int days=JD-JD1;
   return days;
 }
//Method finds a randomized date between 1/1/2000 and 12/31/2005
 void random(){
   myDate first=myDate(1,1,2000);
   myDate last=myDate(12,31,2005);
   int JD= (rand() % first.daysBetween(last) + Greg2Julian(1,1,2000));
   Julian2Greg(JD,m,d,y);

 }
  //Get month
 //@return m month
 int getMonth() const{
   return m;
 }
 //Get day
 //@return d day
 int getDay() const{
   return d;
 }
 //Get year
 //@return y year
 int getYear() const{
   return y;
  }
private:
 int m;
 int d;
 int y;
};

struct Student{
char name[20];
int id;
char grade;
myDate bday;
string town;
};

//Populates students
//@param Student pointer array
void populate(Student *stuPtr[]){
srand(time(NULL));
string names[]={"Tom Thumb","Fred Flintstone", "Sponge Bob", };
char grades[]={'A','B','C','D','F'};
string towns[]={"Small Ville", "Bed Rock","Bikini Bottom"};

for (int i=0;i<3;i++){
  stuPtr[i]=new Student;
  strcpy(stuPtr[i]->name,names[i].c_str());
  stuPtr[i]->grade=grades[rand() % 5];
  stuPtr[i]->id=rand() % 8999 +1000;
  stuPtr[i]->town=towns[i];
  myDate bday;
  stuPtr[i]->bday=bday;
  stuPtr[i]->bday.random();
}
}

//Sort by grade
//@param Student pointer array
void sortGrade(Student *stuPtr[]){
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if(stuPtr[j]->grade>stuPtr[i]->grade){
        Student *tmp=stuPtr[i];
        stuPtr[i]=stuPtr[j];
        stuPtr[j]=tmp;
      }
    }
  }
}

//Sort by ID
//@param Student pointer array
void sortID(Student *stuPtr[]){
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if(stuPtr[j]->id>stuPtr[i]->id){
        Student *tmp=stuPtr[i];
        stuPtr[i]=stuPtr[j];
        stuPtr[j]=tmp;
      }
    }
  }
}

//Sort by Name
//@param Student pointer array
void sortName(Student *stuPtr[]){
  int num=0;
  int length=0;
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      num=0;
      if (strlen(stuPtr[j]->name)>strlen(stuPtr[i]->name)){
        length=strlen(stuPtr[i]->name);
      }
      else{
        length=strlen(stuPtr[j]->name);
      }
      while (stuPtr[j]->name[num]==stuPtr[i]->name[num] &&num<length){
        num++;
      }
      if(stuPtr[j]->name[num]>stuPtr[i]->name[num]){
        Student *tmp=stuPtr[i];
        stuPtr[i]=stuPtr[j];
        stuPtr[j]=tmp;
      }
    }
  }
}


//Sort by Town
//@param Student pointer array
void sortTown(Student *stuPtr[]){

  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if(stuPtr[j]->town.compare(stuPtr[i]->town)>0){
        Student *tmp=stuPtr[i];
        stuPtr[i]=stuPtr[j];
        stuPtr[j]=tmp;
      }
    }
  }
}


//Sort by Date
//@param Student pointer array
void sortDate(Student *stuPtr[]){

  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      if(stuPtr[j]->bday.daysBetween(stuPtr[i]->bday)<0){
        Student *tmp=stuPtr[i];
        stuPtr[i]=stuPtr[j];
        stuPtr[j]=tmp;
      }
    }
  }
}

//Prints to console
//@param Student pointer array
void printtoConsole(Student *stuPtr[]){
 for (int i=0;i<1;i++){
    cout<<setw(25)<<left<<"Name";
    cout<<setw(12)<<left<<"Student ID";
    cout<<setw(8)<<"Grade";
    cout<<setw(20)<<"Birthday";
    cout<<setw(20)<<"HomeTown";
    cout<<endl;
  }
  for (int i=0;i<3;i++){
    cout<<setw(25)<<left<<stuPtr[i]->name;
    cout<<setw(12)<<left<<stuPtr[i]->id;
    cout<<setw(8)<<stuPtr[i]->grade;
    cout<<setw(20)<<stuPtr[i]->bday.toString();
    cout<<setw(20)<<stuPtr[i]->town;
    cout<<endl;
  }
}

int main() {
  srand (time(NULL));
  Student *stuPtr[10];
  populate(stuPtr);
  printtoConsole(stuPtr);
  cout<< endl;
  cout<<"1) Display list sorted by Name"<<endl;
  cout<<"2) Display list sorted by Student ID"<<endl;
  cout<<"3) Display list sorted by Grade"<<endl;
  cout<<"4) Display list sorted by Birthday"<<endl;
  cout<<"5) Display list sorted by HomeTown"<<endl;
  cout<<"6) Exit"<<endl;
  int input;
  cin>>input;
  int k=0;
  while (k<1){
  if (input==1){
    sortName(stuPtr);
    printtoConsole(stuPtr);
    cout<< endl;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by HomeTown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>input;
  }
  else if (input==2){
    sortID(stuPtr);
    printtoConsole(stuPtr);
    cout<< endl;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by HomeTown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>input;
  }
  else if (input==3){
    sortGrade(stuPtr);
    printtoConsole(stuPtr);
    cout<< endl;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by HomeTown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>input;
  }
  else if (input==4){
    sortDate(stuPtr);
    printtoConsole(stuPtr);
    cout<< endl;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by HomeTown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>input;
  }
  else if (input==5){
    sortTown(stuPtr);
    printtoConsole(stuPtr);
    cout<< endl;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by HomeTown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>input;
  }
  else if (input==6){
    k=2;
  }
  }
  }