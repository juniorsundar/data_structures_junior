/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = nullptr;
}

/*
 * Purpose: Destructor for linked list
 * @param none
 * @return none
 */
CountryNetwork::~CountryNetwork()
{
  if (head == nullptr) {
    return;
  } else {
    Country *temp = new Country;
    temp = head;
    while (temp != nullptr){
      temp = head->next;
      delete head;
      head = temp;
    }
    delete temp;
  }
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  Country *inserted = new Country;

  inserted->name = countryName;
  inserted->numberMessages = 0;

  if (previous == nullptr) {
    inserted->next = nullptr;
    head = inserted;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  } else if (previous->next != nullptr) {
    cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    inserted->next = previous->next;
    previous->next = inserted;
  } else if (previous->next == nullptr) {
    cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    inserted->next = nullptr;
    previous->next = inserted;
  }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
  insertCountry(nullptr, "United States");
  insertCountry(searchNetwork("United States"), "Canada");
  insertCountry(searchNetwork("Canada"), "Brazil");
  insertCountry(searchNetwork("Brazil"), "India");
  insertCountry(searchNetwork("India"), "China");
  insertCountry(searchNetwork("China"), "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
  Country* start = head;
  while (start != nullptr && start->name != countryName)
  {
    start = start->next;
  }
  return start;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  if (head == nullptr) {
    cout << "Empty list" << endl;
  } else if (searchNetwork(receiver) == nullptr) {
    cout << "Country not found" << endl;
  } else {
    Country *node;
    
    head->message = message;
    head->numberMessages++;
    node = head;
    cout << node->name << " [# messages recieved: " << node->numberMessages;
    cout << "] recieved: " << node->message << endl;
    
    while (node != searchNetwork(receiver)){
      node = node->next;
      node->message = message;
      node->numberMessages++;
      cout << node->name << " [# messages recieved: " << node->numberMessages;
      cout << "] recieved: " << node->message << endl;
    }
  }
  return;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  Country* temp = head;
  cout << "== CURRENT PATH ==" << endl;
  if (head == nullptr) {
    cout << "nothing in path" << endl;
  } else {
    while(temp->next != nullptr){
      cout<< temp->name <<" -> ";
      temp = temp->next;
    }
    cout <<temp->name<<" -> "<<"NULL"<< endl;
    temp = temp->next;
  }
   cout << "===" << endl;
}
