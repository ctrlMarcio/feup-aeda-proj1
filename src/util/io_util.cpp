#include <iostream>
#include <algorithm>
#include "io_util.h"

using namespace std;

list<string> affirmative_answers = {"yes", "y", "aye", "si", "sim", "s"};
list<string> negative_answers = {"no", "n", "nah", "nope", "nao", "não"};

float io_util::askFloat(const std::string &question) {
	float ans = 0;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		ans = stof(option);
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askFloat(question);
	}

	return ans;
}

double io_util::askDouble(const std::string &question) {
	float ans = 0;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		ans = stod(option);
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askDouble(question);
	}

	return ans;
}

unsigned io_util::askUnsigned(const string &question) {
	unsigned ans = 0;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		ans = stoul(option);
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askUnsigned(question);
	}

	return ans;
}

int io_util::askInt(const string &question) {
	unsigned ans = 0;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		ans = stoi(option);
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askInt(question);
	}

	return ans;
}

bool io_util::askBool(const string &question) {
	bool ans;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		if (find(affirmative_answers.begin(), affirmative_answers.end(), option) != affirmative_answers.end())
			return true;
		if (find(negative_answers.begin(), negative_answers.end(), option) != negative_answers.end())
			return false;

		// The answer is incorrect.
		cout << "The value is invalid." << endl;
		ans = askBool(question);
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askBool(question);
	}

	return ans;
}

string io_util::askString(const string &question) {
	string ans;
	string option;

	cout << question << " ";

	try {
		getline(cin, option);
		ans = option;
	} catch (const exception &e) {
		cout << "The value is invalid." << endl;
		ans = askString(question);
	}

	return ans;
}