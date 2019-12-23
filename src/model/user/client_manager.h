#ifndef FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_MANAGER_H


#include <list>
#include <algorithm>
#include "client.h"


using namespace std;


/*!
 * Represents a class that is responsible for managing clients.
 */
class ClientManager {
public:
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

	size_t readPassengerPreference(const vector<std::string> &params, Client *client, size_t i) const;

	size_t readCommercialPreference(const vector<std::string> &params, Client *client, size_t i) const;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_MANAGER_H
