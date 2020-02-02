#include "pch.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

std::string operator<< (std::string input, int range){
	return input.substr(range) + input.substr(0, range);
}
std::string operator>>(std::string input, int range) {
	return  input.substr(input.size() - range, range) + input.substr(0, input.size() - range);
}

int main()
{
	std::string input = "LET IT SNOW"; 
	std::cout << std::quoted(input << 3) << '\n'; // " IT SNOWLET"
	std::cout << std::quoted(input >>10) <<'\n'; // "ET IT SNOWL"
}
