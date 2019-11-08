#include <iostream>
#include "util/date.h"

int main(int argc, char *argv[]) {
	// TEST CODE: remove it
	Date date;
	std::cout << date.isLeapYear() << std::endl;
	Date date1(21, 12, 2020, 10, 10, 10);
	std::cout << date1.isLeapYear() << std::endl;

}