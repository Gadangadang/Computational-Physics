// single linked list
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

struct Node {
	int value;
	Node* next;

	Node(int n) {
		value = n;
		next = nullptr;
	}

	Node(int n, Node* p) {
		value = n;
		next = p;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	Node* current;


public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	LinkedList(vector<int> f) {
		head = nullptr;
		tail = nullptr;
		for (int i : f) {
			//cout << i << endl;
			append(i);
		//	cout << i << endl;
		}
	}

	~LinkedList() {
		Node* next;

		if (head != nullptr) {
			current = head;
			while (current->next != nullptr) {
				next = current->next;
				delete current;
				current = next;
			}
		}

	}

	int length() {
		current = head;
		int count = 0;

		while (current != nullptr) {
			count++;
			current = current->next;
		}
		// cout << "Length of list: " << count << endl; // bruker heller en print etterpå
		return count;
	}

	void append(int val) {
		Node* n = new Node(val);

		if (head != nullptr) {
			tail->next = n;
			tail = n;
		}

		else {
			head = n;
			tail = head;
		}

	}

	void print() {
		current = head;
		cout << "[";
		while (current->next != nullptr) {
			cout << current->value << ", ";
			current = current->next;
		}
		cout << current->value << "]" << endl;
	}

	int& operator[](int index) {
		current = head;
		if (index == -1) {
			int i = 1;
			while (i !=0){
			 current = current->next;
			 if (current->next == nullptr) {
				 i = 0;
			 }
			}
			return current->value;

		}
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->value;
	}

	void remove(int index) { //add out of range check
		if (index == 0) {
			head = head->next;
		}
		else {
			current = head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			Node* rmv = current->next;
			Node* replacer = rmv->next;
			current->next = replacer;
			free(rmv);
		}
	}

	void insert(int value, int index) { //treats 0 as the first index 1, like conventional indexing.
    if (index < 0){
      ("That index is negative!");
			return;
    }


    if (index == 0) {
      Node* n = new Node(value);
      n->value = value;
			n->next = head;
      head = n;
    }

    int L = length();
    if (index >= L){
      append(value);
      cout << "index is bigger than list. Appending value instead" << endl;
			return;
    }
      Node* n = new Node(value);
      n->value = value;
      current = head;
      for (int i = 0; i < index-1; i++) {
        current = current->next;
      }
			n->next = current->next;
			current->next = n;
			return;
        }

	int pop(int index) {
		if (index < 0 or index >= length()) {
			throw range_error("Index out of range");
		}
		else if (index == 0) {
			int a = head->value;
			remove(index);
			return a;
		}
		else {
			current = head;
			for (int i = 0; i < index; i++) {
			current = current->next;
				}
			int a = current->value;
			remove(index);
			return a;
		}
	}

	int pop() {
		int a = tail->value;
		remove(length()-1);
		return a;
	}

};

void Testingfunction() {
	LinkedList list;
	list.append(3);
	list.append(5);
	list.append(7);
	list.append(8);
	list.append(1);
	/* ----------------- testing length() below ---------------------------- */
	cout << "----------------- testing length() below ----------------------------" << endl;
	cout << " " << endl;
	cout << "List implementation is [3, 5, 7, 8, 1]" << endl;
	cout << "Expecting length is 5" << endl;
	cout << "Implementation produced: "<< list.length() << endl;
	cout << " " << endl;
	/* ----------------- testing append(int) below ------------------------- */
	cout << "----------------- testing append(int) below -------------------------" << endl;
	cout << " " << endl;
	LinkedList aptest;
	aptest.append(3);
	aptest.append(5);
	aptest.append(7);
	cout << "Expected output is: 3, 5, 7." << endl;
	cout << "Implementation produced: " << endl;
	aptest.print();
	cout << " " << endl;
	/* ----------------- testing print() below ----------------------------- */
	cout << "----------------- testing print() below -----------------------------" << endl;
	cout << " " << endl;
	cout << "Using the same list as append-test. Expecting 3, 5, 7" << endl;
	cout << "Implementation produced: " << endl;
	aptest.print();
	cout << " " << endl;
	/* ----------------- testing insert(int value, int index) below -------- */
	cout << "----------------- testing insert(int value, int index) below --------" << endl;
	cout << " " << endl;
	cout << "List was: 3, 5, 7." << endl;
	cout << "Expected output is: 3, 3, 5, 7." << endl;
	aptest.insert(3, 1);
	aptest.print();
	cout << " " << endl;
	cout << "Testting for a larger index than list length" << endl;
	cout << " " << endl;
	aptest.insert(3, 6);
	cout << " " << endl;
	cout << "testing for a negative index" << endl;
	cout << " " << endl;
	aptest.insert(3, -5);
	cout << " " << endl;
	/* ----------------- testing remove(int index) below ------------------- */
	cout << "----------------- testing remove(int 0) below -------------------" << endl;
	cout << " " << endl;
	list.print();
	list.remove(0);
	list.print();
	cout << " " << endl;
	/* ----------------- testing pop(int) below ---------------------------- */
	cout << "----------------- testing pop(int) below ----------------------------" << endl;
	cout << " " << endl;
	list.append(1);
	list.append(5);
	list.append(8);
	list.append(2);
	cout << "Current list: ";
	list.print();
	int index = 3;
	cout << "Popping index " << index << endl;
	int x = list.pop(index);
	cout << "popped element: " << x << endl;
	cout << "Updated list: ";
	list.print();

	cout << " " << endl;
	/* ----------------- testing pop() below ------------------------------- */
	cout << "----------------- testing pop() below -------------------------------" << endl;
	cout << " " << endl;
	cout << "Current list: ";
	list.print();
	cout << "Popping" << endl;
	x = list.pop();
	cout << "popped element: " << x << endl;
	cout << "Updated list: ";
	list.print();
	cout << " " << endl;
	/* ----------------- testing LinkedList(vector<int>) below ------------- */
	cout << "----------------- testing LinkedList(vector<int>) below -------------" << endl;
	cout << " " << endl;
	cout << "Input is: LinkedList vlist{1, 2, 5, 6}" << endl;
	cout << "Output is: " << endl;
	LinkedList vlist({1, 2, 5, 6});
	vlist.print();
	cout << " " << endl;


}
int main() {
	Testingfunction();
	return 0;
};
