#include <iostream>
#include <string>
#include <regex>


bool is_email_valid(const std::string& email)
{
	// define a regular expression
	const std::regex pattern
	("(\\w+)((\\.|_)*(\\w*))*@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return std::regex_match(email, pattern);
}

int main()
{
	std::string email1;
	std::cout << "Escriba el email \n";
	std::cin >> email1;

	std::cout << email1 << " : " << (is_email_valid(email1) ?
		"valido" : "invalido") << std::endl;
}