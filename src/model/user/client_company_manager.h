#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_MANAGER_H


#include <list>
#include <algorithm>
#include "client_company.h"


using namespace std;


/*!
 * Represents a class that is responsible for managing client company.
 */
class ClientCompanyManager {
public:
    /*!
     * Establishes a new instance of a ClientCompany given its information.
     *
     * @param name the name
     * @param identification_number the identification_number
     * @param address the address
     * @return the instance
     */
	static ClientCompany build(string name, string identification_number, string address);

    /*!
     * Adds a client company to the list.
     *
     * @param client the client company
     * @return true, if the client company is added successfully. false, otherwise
     */
    bool add(ClientCompany &client);

    /*!
     * Removes a client company from the list.
     *
     * @param client the client company
     * @return true, if the client company is removed successfully. false, otherwise
     */
    bool remove(ClientCompany &client);

    /*!
     * Verifies if a client company is in the list or not.
     *
     * @param client the client company
     * @return true, if the client company is in the list. false, otherwise
     */
    bool has(ClientCompany &client) const;

    /*!
     * Verifies if a client company is in the list or not.
     *
     * @param identification_number the identification number of the client company
     * @return true, if the client company is in the list. false, otherwise
     */
    bool has(const string &identification_number) const;

    /*!
     * Gets a specific client company given a identification number.
     *
     * @param identification_number the identification number
     * @return a pointer to the client company
     */
	ClientCompany *get(const string &identification_number);

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
