#pragma once
#include <iostream>
#include <sstream> 

class Date
{
  bool leapyear;
  int day;
  int month;
  int year;
  bool leap(int);
  int maxday();
public:
  Date(int d, int m, int y) : leapyear(leap(y)), day(d), month(m), year(y) {};
  Date& operator+=(int);
  std::string operator-(Date&);
  friend 
    std::ostream& operator<<(std::ostream&, const Date&);
};
