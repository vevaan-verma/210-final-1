// COMSC-210 | Final #1 | Vevaan Verma
using namespace std;
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <set>

/* STRUCTURE DEFINITIONS */
struct Booth1Customer;
struct Booth2Customer;
struct Booth3Customer;
struct Booth4Customer;

/* DATA ARRAYS */
const string names[] = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Heidi", "Ivan", "Judy", "Kevin", "Linda", "Mallory", "Nancy", "Oscar", "Peggy", "Quentin", "Randy", "Steve", "Tina", "Ursula", "Victor", "Wendy", "Xander", "Yvonne", "Zelda" };
const string drinkOrders[] = { "Coffee", "Tea", "Water", "Soda", "Juice", "Smoothie", "Milkshake", "Iced Coffee", "Iced Tea", "Lemonade" };
const string muffinOrders[] = { "Blueberry", "Chocolate Chip", "Banana Nut", "Pumpkin Spice", "Lemon Poppy", "Apple Cinnamon", "Cranberry Orange", "Double Chocolate", "Raspberry", "Strawberry" };
const string braceletNames[] = { "Best Friends", "Sisters", "BFFs", "Soulmates", "Twins", "Cousins", "Mother-Daughter", "Father-Son", "Grandma-Granddaughter", "Grandpa-Grandson" };
const string weekndVinyls[] = { "The Noise EP", "House of Balloons", "Thursday", "Echoes of Silence", "Kiss Land", "Beauty Behind the Madness", "Starboy", "My Dear Melancholy,", "After Hours", "Dawn FM", "Live at SoFi Stadium", "The Idol Soundtrack", "Hurry Up Tomorrow" };

/* FUNCTION PROTOTYPES */
void addNode(Booth1Customer*& head, Booth1Customer* newNode);
Booth1Customer* createBooth1Customer();
Booth2Customer* createBooth2Customer();
Booth3Customer* createBooth3Customer();

struct Booth1Customer {

	string customerName;
	string drinkOrder;
	Booth1Customer* next;

};

struct Booth2Customer {

	string customerName;
	string muffinOrder;

};

struct Booth3Customer {

	string customerName;
	string braceletName;

};

struct Booth4Customer {

	string customerName;
	string vinylOrder;

};

// main() is the entry point and driver of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0)); // seed the random number generator

	/* LINKED LIST */
	Booth1Customer* booth1Head = nullptr; // create a linked list of customers

	// add 3 customers to the list at the beginning
	for (int i = 0; i < 3; i++)
		addNode(booth1Head, createBooth1Customer());

	/* DEQUE */
	deque<Booth2Customer*> booth2; // create a deque to store customers

	// add 3 customers to the deque at the beginning
	for (int i = 0; i < 3; i++)
		booth2.push_back(createBooth2Customer());

	/* VECTOR */
	vector<Booth3Customer*> booth3; // create a vector to store customers

	// add 3 customers to the vector at the beginning
	for (int i = 0; i < 3; i++)
		booth3.push_back(createBooth3Customer());

	/* SET */
	set<Booth4Customer*> booth4; // create a set to store customers

	// add 3 customers to the set at the beginning
	for (int i = 0; i < 3; i++)
		booth4.insert(new Booth4Customer{ names[rand() % 5], weekndVinyls[rand() % 5] });

	for (int i = 1; i <= 10; i++) { // simulate 10 rounds

		cout << "Round " << i << ":" << endl;

		/* LINKED LIST (BOOTH #1) */
		// 50% chance to add a new customer to the list
		cout << "    Booth #1:" << endl;

		if (rand() % 2 == 0) { addNode(booth1Head, createBooth1Customer()); }

		// serve customer at the front of the list if there is one
		if (booth1Head != nullptr) {

			cout << "        Serving " << booth1Head->customerName << " a " << booth1Head->drinkOrder << endl;

			// remove the first customer from the list
			Booth1Customer* temp = booth1Head;
			booth1Head = booth1Head->next;
			delete temp;

		} else {

			cout << "        No customers to serve at booth #1" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}

		/* DEQUE (BOOTH #2) */
		// 50% chance to add a new customer to the deque
		cout << "    Booth #2:" << endl;

		if (rand() % 2 == 0) { booth2.push_back(createBooth2Customer()); }

		// serve customer at the front of the deque if there is one
		if (!booth2.empty()) {

			cout << "        Serving " << booth2.front()->customerName << " a " << booth2.front()->muffinOrder << " Muffin" << endl;

			// remove the first customer from the deque
			booth2.pop_front();

		} else {

			cout << "        No customers to serve at booth #2" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}

		/* VECTOR (BOOTH #3) */
		// 50% chance to add a new customer to the vector
		cout << "    Booth #3:" << endl;

		if (rand() % 2 == 0) { booth3.push_back(createBooth3Customer()); }

		// serve customer at the front of the vector if there is one
		if (!booth3.empty()) {

			cout << "        Selling " << booth3.front()->customerName << " a " << booth3.front()->braceletName << " Friendship Bracelet" << endl;

			// remove the first customer from the vector
			booth3.erase(booth3.begin());

		} else {

			cout << "        No customers to serve at booth #3" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}

		/* SET (BOOTH #4) */
		// 50% chance to add a new customer
		cout << "    Booth #4:" << endl;

		if (rand() % 2 == 0) { booth4.insert(new Booth4Customer{ names[rand() % 5], weekndVinyls[rand() % 5] }); }

		// serve customer at the front of the set if there is one
		if (!booth4.empty()) {

			Booth4Customer* customer = *booth4.begin();
			cout << "        Selling " << customer->customerName << " a " << customer->vinylOrder << " Vinyl" << endl;

			// remove the first customer from the set
			booth4.erase(booth4.begin());
			delete customer; // free the memory allocated for the customer

		} else {

			cout << "        No customers to serve at booth #4" << endl; // output a message if there are no customers to serve for better formatting / clarity

		}

		cout << endl; // output a blank line at the end of each round for formatting purposes

	}
}

void addNode(Booth1Customer*& head, Booth1Customer* newNode) {

	if (head == nullptr) { head = newNode; return; } // if the list is empty, add the new node to the head

	Booth1Customer* current = head; // start at the head of the list

	while (current->next != nullptr) { current = current->next; } // traverse the list until the end

	current->next = newNode; // add the new node to the end of the list

}

// createBooth1Customer() creates a new Booth1Customer object with random values
// arguments: none
// returns: Booth1Customer* - a pointer to the new Booth1Customer object
Booth1Customer* createBooth1Customer() { return new Booth1Customer{ names[rand() % 5], drinkOrders[rand() % 5], nullptr }; }

// createBooth2Customer() creates a new Booth2Customer object with random values
// arguments: none
// returns: Booth2Customer* - a pointer to the new Booth2Customer object
Booth2Customer* createBooth2Customer() { return new Booth2Customer{ names[rand() % 5], muffinOrders[rand() % 5] }; }

// createBooth3Customer() creates a new Booth3Customer object with random values
// arguments: none
// returns: Booth3Customer* - a pointer to the new Booth3Customer object
Booth3Customer* createBooth3Customer() { return new Booth3Customer{ names[rand() % 5], braceletNames[rand() % 5] }; }

// createBooth4Customer() creates a new Booth4Customer object with random values
// arguments: none
// returns: Booth4Customer* - a pointer to the new Booth4Customer object
Booth4Customer* createBooth4Customer() { return new Booth4Customer{ names[rand() % 5], weekndVinyls[rand() % 5] }; }
