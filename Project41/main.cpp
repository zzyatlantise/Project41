#include<iostream>
using namespace std;

struct Node{

	int curr;
	int value;
	int nex_pos;
	Node * next;
};

class LinkedList {

private:
	Node*head;
	int listLength;
	int ini_addr;

public:
	LinkedList();
	bool insertNode(Node * newNode, int position);
	bool removeNode(int position);
	void printList();
	int getLength();
	int getInitAddr();
	void setInitAddr(int init);
	Node* getHead();
};
LinkedList::LinkedList() {

	head = new Node;
	listLength = 0;

}
bool LinkedList::insertNode(Node * newNode, int position) {

	if (head->next == NULL) {

		head->next = newNode;
		listLength++;
		return true;

	}
	int count = 0;
		Node *p = head;
		Node *q = head;
		while (q) {

			if (count == position) {

				p->next = newNode;
				newNode->next = q;
				listLength++;
				return true;

			}
			p = q;
			q = p->next;
			count++;

		}
		return false;

}

bool LinkedList::removeNode(int position) {

	if (head->next == NULL) {
		return false;
	}
	int count = 0;
	Node *p = new Node;
	Node *q = new Node;
	while (q) {

		if (count == position) {

			p->next = q->next;
			delete q;
			listLength--;
			return true;
		}
		p = q;
		q = p->next;
		count++;

	}
	return false;


}

void LinkedList::printList()
{
	Node * p = head->next;
	Node * q = head->next;
	int count = 0;
	while (q)
	{
		p = q;
		cout << p->value<<endl;
		if (p->nex_pos != -1)
			q = p->next;
		else
			q = NULL;
		count++;
	}
}

int LinkedList::getLength() {
	return listLength;
}

int LinkedList::getInitAddr() {
	return ini_addr;
}
Node* LinkedList::getHead() {
	return head;
}

void LinkedList::setInitAddr(int init) {
	ini_addr = init;
}

LinkedList sort(LinkedList l) {

	LinkedList temp;
	int length = l.getLength();
	int init = l.getInitAddr();
	int k = 0;
	int next = init;
	Node *p = new Node;
	Node *q = new Node;
	while(k<length){
	
		p = l.getHead();
		p = p->next;
		while (p) {

			if (p->curr == next) {

				temp.insertNode(p, k);
				next = p->nex_pos;
				k++;
			}
			if (p->nex_pos == -1)
				p->next = NULL;
			q = p;
			p = q->next;

		}
	
	}
	return temp;

}




int main() {
	
	int N;
	int addr, value, nex_pos;
	LinkedList list;
	int k = 0;
	int init, length, sub;
	cin >> init >> length >> sub;
	while (k<length) {
		cin >> addr >> value >> nex_pos;
		k++;
		Node *temp = new Node;
		temp->curr = addr;
		temp->value = value;
		temp->nex_pos = nex_pos;
		list.insertNode(temp, k);
	}
	//list.printList();
	LinkedList sorted = sort(list);
	sorted.printList();
	cin.get();
	return 0;
}