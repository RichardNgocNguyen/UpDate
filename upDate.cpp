#include "upDate.h"
#include <iostream>

using namespace std;

int upDate::count = 0;
void J2G(int JD, int &year, int &month, int &day){
  int I, J, K, L, N;
  L= JD+68569;
  N= 4*L/146097;
  L= L-(146097*N+3)/4;
  I= 4000*(L+1)/1461001;
  L= L-1461*I/4+31;
  J= 80*L/2447;
  K= L-2447*J/80;
  L= J/11;
  J= J+2-12*L;
  I= 100*(N-49)+I+L;
  year = I;
  month = J;
  day = K;
}
int G2J(int year, int month, int day){
  int I = year;
  int J = month;
  int K = day;
  int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
  return JD;
}
int upDate::julian(){
  int jul = G2J(dptr[2],dptr[0],dptr[1]);
  return jul;
}
upDate::upDate(const upDate &d){
  count++;
  dptr = new int[3];
  dptr[0] = d.dptr[0];
  dptr[1] = d.dptr[1];
  dptr[2] = d.dptr[2];
}
upDate::upDate(int J) {
  count++;
  int m, d, y = 0;
  J2G(J, y, m, d);
  dptr[0] = m;
  dptr[1] = d;
  dptr[2] = y;
}
upDate::upDate(){
  count++;
  month = 5;
  day = 11;
  year = 1959;
  dptr = new int[3];
  dptr[0] = month; 
  dptr[1] = day;
  dptr[2] = year;
}
upDate::upDate(int M, int D, int Y){
  count++;
  month = M;
  day = D;
  year = Y;
  int month1 = M;
  int day1 = D;
  int year1 = Y;
  int date = G2J(year, month, day);
  J2G(date, year, month, day);
  dptr = new int[3];
  if (month1 != month || day1 != day || year1 != year){
    dptr[0] = 5; 
    dptr[1] = 11;
    dptr[2] = 1959;
  }
  else{
    dptr[0] = month; 
    dptr[1] = day;
    dptr[2] = year;
    }
 
}
upDate::~upDate(){
  count--;
  delete []dptr;
}
void upDate::setDate(int M, int D, int Y){
  dptr[0] = M;
  dptr[1] = D;
  dptr[2] = Y;
}
int upDate::GetDateCount(){
  return count;
}
int upDate::getMonth(){
  return dptr[0];
}
int upDate::getDay(){
  return dptr[1];
}
int upDate::getYear(){
  return dptr[2];
}
string upDate::getMonthName(){
  if (month == 1) {
    return "January";
  }
  else if (month == 2) {
    return "Feburary";
  }
  else if (month == 3) {
    return "March";
  }
  else if (month == 4) {
    return "April";
  }
  else if (month == 5) {
    return "May";
  }
  else if (month == 6) {
    return "June";
  }
  else if (month == 7) {
    return "July";
  }
  else if (month == 8) {
    return "August";
  }
  else if (month == 9) {
    return "September";
  }
  else if (month == 10) {
    return "October";
  }
  else if (month == 11) {
    return "November";
  }
  else {
    return "December";
  }
}
ostream& operator<<(ostream& out, const upDate& d){

  return out << d.dptr[0] << '/' << d.dptr[1] << '/' << d.dptr[2];
  
}
upDate upDate::operator++(int){
  dptr[1]++;
  int Jul = G2J(dptr[2], dptr[1], dptr[0]);
  J2G(Jul,dptr[2], dptr[1], dptr[0]);
  return *this;
}
upDate upDate::operator--(int){
  int Jul = G2J(dptr[2], dptr[1], dptr[0]) - 1;
  J2G(Jul,dptr[2], dptr[1], dptr[0]);
  return *this;
}
upDate& upDate::operator++(){
  dptr[1]++;
  return *this;
}
upDate& upDate::operator--(){
  dptr[1]--;
  return *this;
}
upDate operator+(upDate d,int n){
  int m1 = d.dptr[0];
  int d1 = d.dptr[1] + n;
  int y1 = d.dptr[2];
  int Jul = G2J(y1,m1,d1);
  J2G(Jul,y1,m1,d1);
  upDate date(m1,d1,y1);
  return date;
}
upDate operator-(upDate d,int n){
  int m1 = d.dptr[0];
  int d1 = d.dptr[1];
  int y1 = d.dptr[2];
  int Jul = G2J(y1,m1,d1) - n;
  J2G(Jul,y1,m1,d1);
  upDate date(m1,d1,y1);
  return date;
}
upDate operator+(int n, upDate d){
  int m1 = d.dptr[0];
  int d1 = d.dptr[1] + n;
  int y1 = d.dptr[2];
  int Jul = G2J(y1,m1,d1);
  J2G(Jul,y1,m1,d1);
  upDate date(m1,d1,y1);
  return date;
}
upDate operator-(int n, upDate d){
  int m1 = d.dptr[0];
  int d1 = d.dptr[1];
  int y1 = d.dptr[2];
  int Jul = G2J(y1,m1,d1) - n;
  J2G(Jul,y1,m1,d1);
  upDate date(m1,d1,y1);
  return date;
}
int operator+(upDate d1, upDate d2){
  int jul1 = G2J(d1.dptr[2], d1.dptr[1], d1.dptr[0]);
  int jul2 = G2J(d1.dptr[2], d1.dptr[1], d1.dptr[0]);
  int f = jul1 + jul2;
  return f;
}
int operator-(upDate d1, upDate d2){
  int f = 0;
  int jul1 = G2J(d1.dptr[2], d1.dptr[0], d1.dptr[1]);
  int jul2 = G2J(d2.dptr[2], d2.dptr[0], d2.dptr[1]);
  if (jul1 >= jul2){
    f = jul1 - jul2;
    }
  else{
    f = jul2 - jul1;
  }
  return f;
}

bool operator==(upDate d1, upDate d2){
  if (d1.julian() == d2.julian()){
    return true;
  }
  else{
    return false;
  }
}

bool operator>(upDate d1, upDate d2){
  if (d1.julian() > d2.julian()){
    return true;
  }
  else{
    return false;
  }
}

bool operator<(upDate d1, upDate d2){
  if (d1.julian() < d2.julian()){
    return true;
  }
  else{
    return false;
  }
}

upDate upDate::operator=(upDate c){
  dptr[0] = c.dptr[0];
  dptr[1] = c.dptr[1];
  dptr[2] = c.dptr[2];
  return *this;
}
