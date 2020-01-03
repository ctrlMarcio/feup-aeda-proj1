#include <iostream>
#include <algorithm>
#include "io_util.h"
#include "string_util.h"

using namespace std;

list<string> affirmative_answers = {"Y", "yes", "y", "aye", "si", "sim", "s", "1"};
list<string> negative_answers = {"N", "no", "n", "nah", "nope", "nao", "não", "0", "-1"};

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

Date io_util::askDate(const string &question) {
	Date ans;
	string option;

	cout << question << " (dd/MM/yyyy hh:mm.ss, time is optional) ";

	try {
		int day, month, year, hour, minute, second;

		getline(cin, option);

		vector<string> complete_vector = string_util::split(option, " ");
		string date = complete_vector.at(0);
		try {
			string time = complete_vector.at(1);

			vector<string> hour_vector = string_util::split(time, ":");
			hour = stoi(hour_vector.at(0));

			try {
				string min_secs = hour_vector.at(1);

				vector<string> min_secs_vector = string_util::split(min_secs, ".");
				minute = stoi(min_secs_vector.at(0));

				try {
					second = stoi(min_secs_vector.at(1));

				} catch (out_of_range &e) {
					second = 0;
				}

			} catch (out_of_range &e) {
				minute = 0;
				second = 0;
			}

		} catch (out_of_range &e) {
			hour = 0;
			minute = 0;
			second = 0;
		}

		vector<string> date_vector = string_util::split(date, "/");

		day = stoi(date_vector.at(0));
		month = stoi(date_vector.at(1));
		year = stoi(date_vector.at(2));

		ans = Date(day, month, year, hour, minute, second);
	} catch (exception &e) {
		cout << "The value is invalid." << endl;
		ans = askDate(question);
	}

	return ans;
}
