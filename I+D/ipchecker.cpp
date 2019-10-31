#include <iostream>
#include <string>
#include <regex>

bool is_ip_valid(const std::string& ip)
{
	// define a regular expression
	const std::regex pattern
	("(\\d{1,3}).(\\d{1,3}).(\\d{1,3}).(\\d{1,3})");

	// try to match the string with the regular expression
	return std::regex_match(ip, pattern);
}

bool less_than_256(const std::string& ip)
{
	std::string s = ip;
	std::string delimiter = ".";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		int i = std::stoi(token);
		if (i > 255)
		{
			return false;
		}
		s.erase(0, pos + delimiter.length());
	}

	return true;
}

int main()
{
	std::string ip;
	std::cout << "Escriba la dirección IP \n";
	std::cin >> ip;

	std::cout << ip << " : " << (is_ip_valid(ip) && less_than_256(ip) ?
		"valido" : "invalido") << std::endl;
}