#include "Header.h"

int main()
{
  int Day, Month, Year, increase;
  std::cout << "Enter first date (day month year): ";
  std::cin >> Day >> Month >> Year;

  Date date(Day, Month, Year);
  std::cout << "Date = " << date << std::endl;

  std::cout << "Increase date by : ";
  std::cin  >> increase;
  date += increase;

  std::cout << "Date = " << date << std::endl;

  std::cout << "Enter second date (day month year): ";
  std::cin  >> Day >> Month >> Year;
  Date date2(Day, Month, Year);

  std::cout << "Date2 = " << date2 << std::endl;
  std::cout << "Date1 - Date2 = " << date - date2 << std::endl;
  return 0;
}