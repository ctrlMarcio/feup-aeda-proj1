#include <vector>
#include <string>
#include "string_util.h"

std::vector<std::string> string_util::split(const std::string &string, const std::string &delimiter) {
	std::string aux = string;
	std::string token;
	size_t pos = 0;
	std::vector<std::string> res;

	while ((pos = aux.find(delimiter)) != std::string::npos) {
		token = aux.substr(0, pos);
		res.push_back(token);
		aux.erase(0, pos + delimiter.length());
	}
	res.push_back(aux);

	return res;
}