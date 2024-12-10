// COMSC-210 | Lab 21 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <deque>

struct CustomerNode;

/* GLOBAL CONSTANTS */
const string names[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
const string orders[] = { "Coffee", "Tea", "Water", "Soda", "Juice" };

/* FUNCTION PROTOTYPES */
void addNode(CustomerNode* head, CustomerNode* newNode);
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

	CustomerNode* head = nullptr;

	// add 3 customers to the list at the beginning
	addNode(head, createCustomer());
	addNode(head, createCustomer());
	addNode(head, createCustomer());

	for (int i = 0; i < 10; i++) { // simulate 10 rounds

		cout << "Round " << i + 1 << ":" << endl;

		// 50% chance to add a new customer to the list
		if (rand() % 2 == 0) { addNode(head, createCustomer()); }

		// serve customer at the front of the list if there is one
		if (head != nullptr) {

			cout << "Serving " << head->customerName << " a " << head->drinkOrder << endl;

			// remove the first customer from the list
			CustomerNode* temp = head;
			head = head->next;
			delete temp;

		}
	}
}

void addNode(CustomerNode* head, CustomerNode* newNode) {

	if (head == nullptr) { head = newNode; return; } // if the list is empty, add the new node to the head

	CustomerNode* current = head; // start at the head of the list

	while (current->next != nullptr) { current = current->next; } // traverse the list until the end

	current->next = newNode; // add the new node to the end of the list

}

// createCustomer() creates a new customer node with a random name and drink order
// arguments: none
// returns: CustomerNode* - a pointer to the new customer node
CustomerNode* createCustomer() { return new CustomerNode{ names[rand() % 5], orders[rand() % 5], nullptr }; }