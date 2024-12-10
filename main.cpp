// COMSC-210 | Lab 21 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>

/* GLOBAL CONSTANTS */
const string names[] = { "Alice", "Bob", "Charlie", "David", "Eve" };
const string orders[] = { "Coffee", "Tea", "Water", "Soda", "Juice" };

struct CustomerNode {

	string customerName;
	string drinkOrder;
	CustomerNode* next;

};

// main() is the entry point and driver of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	CustomerNode* head = createCustomer();

}

// createCustomer() creates a new customer node with a random name and drink order
// arguments: none
// returns: CustomerNode* - a pointer to the new customer node
CustomerNode* createCustomer() { return new CustomerNode{ names[rand() % 5], orders[rand() % 5], nullptr }; }