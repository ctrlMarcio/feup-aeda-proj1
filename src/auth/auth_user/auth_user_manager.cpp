#include "auth_user_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"

#include <utility>
#include <algorithm>
#include <fstream>
#include <vector>

AuthUser AuthUserManager::build(string identification_number, string user_role) {
    return AuthUser(std::move(identification_number), random_password(8), std::move(user_role));
}

AuthUser AuthUserManager::build(string identification_number, string password, string user_role) {
    return AuthUser(std::move(identification_number), std::move(password), std::move(user_role));
}

bool AuthUserManager::add(AuthUser &user) {
    if (has(user) || has(user.getIdentificationNumber())) return false;
    users.push_back(user);
    return true;
}

bool AuthUserManager::remove(AuthUser &user) {
    if (!has(user) || !has(user.getIdentificationNumber())) return false;
    users.erase(find(users.begin(), users.end(), user));
    return true;
}

bool AuthUserManager::has(AuthUser &user) const {
    return find(users.begin(), users.end(), user) != users.end();
}

bool AuthUserManager::has(const string &identification_number) const {
    return find_if(users.begin(), users.end(), [&identification_number](const AuthUser &user) {
        return user.getIdentificationNumber() == identification_number;
    }) != users.end();
}

AuthUser &AuthUserManager::getUser(const string &identification_number) const {
    auto it = users.begin();

    while (it != users.end()) {
        if ((*it).getIdentificationNumber() == identification_number) {
            return const_cast<AuthUser &>(*it);
        }
        it++;
    }

    return const_cast<AuthUser &>(*users.end());
}

void AuthUserManager::read(const std::string &directory) {
    std::string file_path = directory + "/" + file_handling::auth_user;

    ifstream ifstream;
    ifstream.open(file_path);

    if (!ifstream.is_open())
        throw InvalidFileException(file_path);

    std::string line;
    while (getline(ifstream, line)) {
		line = string_util::removeCarriageReturn(line);

        std::vector<std::string> params = string_util::split(line, file_handling::delimiter);
        std::string identification_number = params[0];
        std::string password = params[1];
        std::string role = params[2];

        AuthUser *user = new AuthUser(identification_number, password, role);
        this->add(*user);
    }

    ifstream.close();
}

void AuthUserManager::write(const std::string &directory) const {
    std::string file_path = directory + "/" + file_handling::auth_user;

    ofstream ofstream;
    ofstream.open(file_path);

    if (!ofstream.is_open())
        throw InvalidFileException(file_path);

    for (const AuthUser &user : users)
        ofstream << user.getIdentificationNumber() << file_handling::delimiter << user.getPassword()
                 << file_handling::delimiter << user.getRole() << std::endl;

    ofstream.close();
}
