#ifndef FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_MANAGER_H


#include <list>
#include <algorithm>
#include "client.h"

using namespace std;


class ClientManager {
public:
    Client build(string name, string identification_number, string address);

    bool add(Client &client);

    bool remove(Client &client);

    bool has(Client &client) const;

    bool has(const string &identification_number) const;

	Client *get(const string &identification_number);

	/*!
	 * Reads the clients from a file.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace.
	 */
	void read(const std::string &directory);

	/*!
	 * Writes the clients to a file.
	 *
	 * @param directory the directory of the file. The directory should exist. The file name is stored in the file_handling namespace
	 */
	void write(const std::string &directory) const;

private:
    list<Client> clients;

	size_t readPassengerPreference(const vector<std::string> &params, Client *client, size_t i) const;

	size_t readCommercialPreference(const vector<std::string> &params, Client *client, size_t i) const;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
