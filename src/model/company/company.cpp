#include "company.h"

Company::Company() = default;

UserManager &Company::getUserManager() {
    return user_manager;
}
