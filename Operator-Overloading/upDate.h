
#ifndef UPDATE_H
#define UPDATE_H
#include<iostream>
using namespace std;
class upDate{
  public:
    /*
    Default constructor
    **/
    upDate();
    /*
    Overload constructor
    @param M - months
    @param D - days
    @param Y - years
    **/
    upDate(int M, int D, int Y);
    /*
    Copy constructor
    **/
    upDate(const upDate&d1);
    /*
    Converts julian number to Gregorian date
    @param JD - julian number
    **/
    static upDate toGreg(int JD);
    /*
    Sets custom date
    @param M - months
    @param D - days
    @param Y - years
    **/
    void setDate(int M, int D, int Y);
    /*
    Overload Operator =
    @param d1- upDate object
    @return *this
  `**/
    const upDate operator =(const upDate&d1);
    /*
    Friend function Overload Operator +
    @param num- Number being added
    @param d1- upDate object
    @return d1.toGreg(julian) - julian number
    **/
    friend const upDate operator +(int num, const upDate&d1);
    /*
    Overload Operator +
    @param num- Number being added
    @return toGreg(julian) - julian number
    **/
    const upDate operator +(int num) const;
    /*
    Overload Operator -
    @param d1- upDate object
    @return this->julian() - d1.julian() - julian number
    **/
    const int operator -(const upDate&d1) const;
    /*
    Overload Operator -
    @param num- number being subrtracted
    @return toGreg(julian) - julian number
    **/
    const upDate operator -(int num) const;
    /*
    ostream
    @param output- output of cout
    @param d1- upDate object
    @return output
    **/
    friend ostream &operator<<(ostream &output, const upDate &d1 );
    /*
    Deconstructor
    **/
    ~upDate();
    /*
    Get month
    @return date[0] - months
    **/
    int getMonth( )const;
    /*
    Get day
    @return date[1] - days
    **/
    int getDay( )const;
    /*
    Get year
    @return date[2] - years
    **/
    int getYear( )const;
    /*
    Converts date to julian 
    @return JD- julian number
    **/
    double julian() const;
    /*
    Get name of month
    @return month
    **/
    string getMonthName( );
    /*
    Get number of upDate objects
    @return numdates- number of upDate objects
    **/
    static int GetDateCount();
    /*
    Operator ++
    @return *this
    **/
    upDate& operator ++();
    /*
    Overload Operator ++
    @param n - number
    @return temp - Incremented total
    **/
    upDate operator ++(int n);
    /*
    Operator --
    @return *this
    **/
    upDate& operator --();
    /*
    Overload Operator --
    @param n - number
    @return temp - Decremented total
    **/
    upDate operator --(int n);
    /*
    Operator >
    @param d1- upDate object
    @return true if greater than else false
    **/
    const bool operator >(const upDate & d1) const;
    /*
    Operator <
    @param d1- upDate object
    @return true if less than else false
    **/
    const bool operator <(const upDate & d1) const;
    /*
    Operator >=
    @param d1- upDate object
    @return true if greater than or equal to else false
    **/
    const bool operator >=(const upDate & d1) const;
    /*
    Operator <=
    @param d1- upDate object
    @return true if less than or equal to else false
    **/
    const bool operator <=(const upDate & d1) const;
    /*
    Operator ==
    @param d1- upDate object
    @return true if equal to else false
    **/
    const bool operator ==(const upDate & d1) const;
    
  private:
    int* date;
    static int numdates;



};

#endif