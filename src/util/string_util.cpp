#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>
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

std::string string_util::random_password(int length) {
    std::random_device rd;
    std::mt19937 mt(rd());

    const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::stringstream password_stream;

    std::uniform_real_distribution<double> dist(0.0, (double) sizeof(characters) - .01);

    for (int i = 0; i < length; i++) {
        password_stream << characters[(int) dist(mt)];
    }

    return password_stream.str();
}

bool string_util::is_number(const std::string &string) {
    return !string.empty() && std::find_if(string.begin(),
                                           string.end(), [](char c) { return !std::isdigit(c); }) == string.end();
}

std::string string_util::trim(const std::string &string) {
    auto it_b = string.begin();
    for (; *it_b == ' '; it_b++);
    auto it_e = string.end() - 1;
    for (; *it_e == ' '; it_e--);
    int size = it_e + 1 - it_b;
    return string.substr(it_b - string.begin(), size < 0 ? 0 : size);
}

std::string string_util::pad_number(int number, int n) {
    std::string res = std::to_string(number);
    while (res.length() < n)
        res = "0" + res;
    return res;
}

std::string string_util::capitalize(std::string string) {
    string[0] = toupper(string[0]);
    for (int i = 1; i < string.size(); i++)
        string[i] = tolower(string[i]);

    return string;
}

std::string string_util::removeCarriageReturn(std::string string) {
	if (!string.empty() && string.back() == '\r')
		string.erase(string.size() - 1);

	return string;
}
