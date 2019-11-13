#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H


#include <list>
#include <algorithm>
#include "client_company.h"


using namespace std;

class ClientCompanyManager {
public:
    ClientCompany build(string name, string identification_number, string address);

    bool add(ClientCompany &client);

    bool remove(ClientCompany &client);

    bool has(ClientCompany &client) const;

    bool has(const string &identification_number) const;

	/*!
	 * Gets a client given its identification number.
	 *
	 * @param identification_number the identification number
	 * @return the reference to the client
	 */
	ClientCompany &get(const string &identification_number) const;

	/*!
	 * Reads the client companies from a file.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace.
	 */
	void read(const std::string &directory);

	/*!
	 * Writes the client companies to a file.
	 *
	 * @param directory the directory of the file. The directory should exist. The file name is stored in the file_handling namespace
	 */
	void write(const std::string &directory) const;

private:
	/*!
	 * The list of clients.
	 */
	list<ClientCompany> clients;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H
