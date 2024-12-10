// COMSC-210 | Lab 21 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <deque>
#include <vector>

struct CustomerNode;

/* GLOBAL CONSTANTS */
const string names[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
const string orders[] = { "Coffee", "Tea", "Water", "Soda", "Juice" };

/* FUNCTION PROTOTYPES */
void addNode(CustomerNode*& head, CustomerNode* newNode);
CustomerNode* createCustomer();

struct CustomerNode {

	string customerName;
	string drinkOrder;
	CustomerNode* next;

};

// main() is the entry point and driver of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	/* LINKED LIST */
	CustomerNode* booth1Head = nullptr; // create a linked list of customers

	// add 3 customers to the list at the beginning
	for (int i = 0; i < 3; i++)
		addNode(booth1Head, createCustomer());

	/* DEQUE */
	deque<CustomerNode*> booth2; // create a deque to store customers

	// add 3 customers to the deque at the beginning
	for (int i = 0; i < 3; i++)
		booth2.push_back(createCustomer());

	for (int i = 1; i <= 10; i++) { // simulate 10 rounds

		cout << "Round " << i << ":" << endl;

		/* LINKED LIST (BOOTH #1) */
		// 50% chance to add a new customer to the list
		cout << "    Booth #1:" << endl;

		if (rand() % 2 == 0) { addNode(booth1Head, createCustomer()); }

		// serve customer at the front of the list if there is one
		if (booth1Head != nullptr) {

			cout << "        Serving " << booth1Head->customerName << " a " << booth1Head->drinkOrder << endl;

			// remove the first customer from the list
			CustomerNode* temp = booth1Head;
			booth1Head = booth1Head->next;
			delete temp;

		} else {

			cout << "        No customers to serve at booth #1" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}

		/* DEQUE (BOOTH #2) */
		// 50% chance to add a new customer to the deque
		cout << "    Booth #2:" << endl;

		if (rand() % 2 == 0) { booth2.push_back(createCustomer()); }

		// serve customer at the front of the deque if there is one
		if (!booth2.empty()) {

			cout << "        Serving " << booth2.front()->customerName << " a " << booth2.front()->drinkOrder << endl;

			// remove the first customer from the deque
			booth2.pop_front();

		} else {

			cout << "        No customers to serve at booth #2" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}
	}
}

void addNode(CustomerNode*& head, CustomerNode* newNode) {

	if (head == nullptr) { head = newNode; return; } // if the list is empty, add the new node to the head

	CustomerNode* current = head; // start at the head of the list

	while (current->next != nullptr) { current = current->next; } // traverse the list until the end

	current->next = newNode; // add the new node to the end of the list

}

// createCustomer() creates a new customer node with a random name and drink order
// arguments: none
// returns: CustomerNode* - a pointer to the new customer node
CustomerNode* createCustomer() { return new CustomerNode{ names[rand() % 5], orders[rand() % 5], nullptr }; }