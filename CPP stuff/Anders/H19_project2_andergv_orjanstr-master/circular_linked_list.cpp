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

class CircLinkedList {
private:
    int size = 0;
    Node* head;
    Node* tail;
    Node* current;

public:
  CircLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;

  }

  CircLinkedList(int y) {
    size = 0;
		head = nullptr;
		tail = nullptr;
		for (int i = 1; i <= y; i++) {
			append(i);
		}
	}

  void append(int val) { //
    Node* n = new Node(val);

    if (head != nullptr) {
      n->next = head;
      tail->next = n;
      tail = n;
      size++;
    }

    else {
      head = n;
      tail = head;
      size++;
    }

  }

  int& operator[](int index) {
		/*
		Hvordan bruke denne: 	(*this)[3] = 'verdien';
		Lar deg referere fra innsiden av klassen
		*/
    if (size <= 0) {
      throw range_error("List is empty!");
    }
    if (index < 0) {
      throw range_error("Index is negative!");
    }
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    return current->value;
  }

  void print() {
		current = head;
		cout << "[";
    int i = 0;
		while (i < 1) {
			cout << current->value << ", ";
			current = current->next;
      if (current->next == head) {
        i++;
      }
		}
		cout << current->value << "]" << endl;
	}

  vector<int> josephus_sequence(int k) {
    vector<int> f;
		int l;
		Node *Pcur = head;
		Node *Prev;
		for (int j = 0; j < size; j++) {
			int b = k;
			for (int i = 0; i < b-1; i++) {
				Prev = Pcur;
				Pcur = Pcur->next;
			}
			int l = Pcur->value;
			Prev->next = Pcur->next;
			free(Pcur);
			Pcur = Prev->next;
			// cout << "Killed nr: " << l << endl;
			f.push_back(l);
		}
    return f;
  }

};

int last_man_standing(int n, int k){
  CircLinkedList jlist(n);
	//jlist.print();
  vector<int> u = (jlist.josephus_sequence(k));
  return u.back();
}

int main() {
  int n ;
	cout << "How many people in attendance?: " << endl;
	cin >> n;
  int k ;
	cout << "How many counts?: " << endl;
	cin >> k;
  cout << "With " << n << " people in attendance. You should be at place number " << endl;
	cout << " " << endl;
	cout << last_man_standing(n, k) << " to survive" << endl;

	/* // For oppgave 4c
	CircLinkedList clist;
	clist.append(0);
	clist.append(2);
	clist.append(4);
	clist.print();
	*/
  return 0;
}
