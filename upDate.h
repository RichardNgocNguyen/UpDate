#ifndef UPDATE_H
#define UPDATE_H

#include <string>
using namespace std;

class upDate {
  private:
    int *dptr;
    static int count;
    int month;
    int day;
    int year;

  public:
    upDate(int J);
    upDate(const upDate &d);

    upDate();
    upDate(int M, int D, int Y);
    ~upDate();

    void setDate(int M, int D, int Y);
    static int GetDateCount();
    int getMonth();
    int getDay();
    int getYear();
    string getMonthName();
  
    int julian();
    friend std::ostream& operator<<(std::ostream& os, const upDate& d);
    upDate operator++(int);
    upDate operator--(int);

    upDate& operator++();
    upDate& operator--();

    friend upDate operator+(upDate d, int);
    friend upDate operator+(int n, upDate d);

    friend upDate operator-(upDate d, int);
    friend upDate operator-(int n, upDate d);

    friend int operator+(upDate d1, upDate d2);
    friend int operator-(upDate d1, upDate d2);

    friend bool operator==(upDate d1, upDate d2);
    friend bool operator>(upDate d1, upDate d2);
    friend bool operator<(upDate d1, upDate d2);
    upDate operator=(upDate c);
    
    
};

#endif