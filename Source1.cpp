#include "Header.h"

bool Date::leap(int Year)
{
  return (
    (Year % 4 == 0 && Year % 100 != 0)
    || Year % 400);
}
int Date::maxday()
{
  int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  if (leapyear)
  {
    days[1] = 29;
  }
  return days[month - 1];
}
Date& Date::operator+=(int Day)
{
  if (day + Day > maxday())
  {
    Day -= maxday() - day;

    if (++month > 12)
    {
      month = 1;
      year++;
    }

    while (Day / maxday())
    {
      if (++month > 12)
      {
        month = 1;
        year++;
      }
      Day -= maxday();
    }
    day = Day;

  }
  else
  {
    day += Day;
  }
  return *this;
}
std::string Date::operator-(Date& date)
{
  int Day, Month, Year;
  if (year >= date.year)
  {
    Year = year - date.year;
    if (month > date.month)
    {
      Month = month - date.month;
      Day = day + date.maxday() - date.day;
      if (Day > date.maxday())
      {
        Day -= date.maxday();
      }
      else
      {
        --Month;
      }
      --Year;
    }
    else
    {
      Month = 12 - month + date.month;
      Day = date.day + maxday() - day;
      if (Day > maxday())
      {
        Day -= maxday();
      }
      else
      {
        --Month;
      }
    }
  }
  else
  {
    Year = date.year - year;
    if (month > date.month)
    {
      Month = 12 - month + date.month;
      Day = day + date.maxday() - date.day;

      if (Day > date.maxday())
      {
        Day -= date.maxday();
      }
      else
      {
        --Month;
      }
      --Year;
    }
    else
    {
      Month = date.month - month;
      Day = maxday() - day + date.day;
      if (Day > maxday())
      {
        Day -= maxday();
      }
      else
      {
        --Month;
      }
    }
  }
  std::string str;
  std::stringstream strStream;
  strStream << Day << " day(s) " << Month << " month " << Year << " year(s)";
  getline(strStream, str);
  return str;
}

std::ostream& operator<<(std::ostream& outStream, const Date& date)
{
  std::string Month[] =
  { "Jan","Feb","Mar",
    "Apr","May","Jun",
    "Jul","Aug","Sep",
    "Oct","Nov","Dec" };
  outStream << date.day << " " << Month[date.month - 1] << " " << date.year;
  return outStream;
}