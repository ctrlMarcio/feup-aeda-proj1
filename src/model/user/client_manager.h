#ifndef FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_MANAGER_H


#include <list>
#include <algorithm>
#include <unordered_set>
#include "client.h"
#include "../contract/contract_manager.h"

using namespace std;

/*!
 * The struct that has the hash function of a client.
 */
struct client_hash {
	int operator()(const Client *client) const {
		int res = 0;
		for (char c : client->getIdentificationNumber())
			res = res * 37 + c;

		return res;
	}
};

/*!
 * The struct that has the equality function of two clients.
 */
struct client_eq {
	bool operator()(const Client *client1, const Client *client2) const {
		return *client1 == *client2;
	}
};

/*!
 * Represents a class that is responsible for managing clients.
 */
class ClientManager {
public:
	/*!
	 * The number of days required, without making any contract, to make a client inactive.
	 * I.e., if a client doesn't make a contract for this amount or more of days, it is labeled as inactive.
	 * E.g.: if DAYS_TO_INACTIVITY == 30 and a client doesn't make contracts for 30 days, then it is inactive.
	 */
	static const unsigned long DAYS_TO_INACTIVITY = 30;

	/*!
	 * Establishes a new instance of a Client given its information.
	 *
	 * @param name the name
	 * @param identification_number the identification_number
	 * @param address the address
	 * @return the instance
	 */
	static Client build(string name, string identification_number, string address);

	/*!
	 * Adds a client to the list.
	 *
	 * @param client the client
	 * @return true, if the client is added successfully. false, otherwise
	 */
	bool add(Client &client);

	/*!
	 * Removes a client from the list.
	 *
	 * @param client the client
	 * @return true, if the client is removed successfully. false, otherwise
	 */
	bool remove(Client &client);

	/*!
	 * Verifies if a client is in the list or not.
	 *
	 * @param client the client
	 * @return true, if the client is in the list. false, otherwise
	 */
	bool has(Client &client) const;

	/*!
	 * Verifies if a client is in the list or not.
	 *
	 * @param identification_number the identification number of the client
	 * @return true, if the client is in the list. false, otherwise
	 */
	bool has(const string &identification_number) const;

	/*!
	 * Gets a specific client given a identification number.
	 *
	 * @param identification_number the identification number
	 * @return a pointer to the client
	 */
	Client *get(const string &identification_number);

	/*!
	 * Gets the inactive clients in a vector.
	 *
	 * @return the vector of inactive clients
	 */
	vector<Client> getInactiveClients() const;

	/*!
	 * Updates the inactive clients given the current day.
	 *
	 * @param contract_manager the contract manager to check past contracts of the clients
	 */
	void update(const ContractManager &contract_manager);

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
	/*!
	 * The list of clients.
	 */
	list<Client> clients;

	/*!
	 * The hash set that stores the inactive clients.
	 */
	unordered_set<Client *, client_hash, client_eq> inactive_clients;

	size_t readPassengerPreference(const vector<std::string> &params, Client *client, size_t i) const;

	size_t readCommercialPreference(const vector<std::string> &params, Client *client, size_t i) const;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
