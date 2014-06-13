#include <cstdlib>
#include <iostream>
#include <fstream>
#include<sstream>
#include <string>

using namespace std;

template<class T>
class node{

private:
	T coef;
	T exp;

	node* Next;
public:
	node(){
		exp = 0;
		coef = 0;
		Next = nullptr;
	}
	node(T i){
		coef = i;
		exp = 0;
		Next = nullptr;
	}
	node(T c, T e){
		coef = c;
		exp = e;
		Next = nullptr;
	}

	T getCoef(){
		return coef;
	}

	T getExp(){
		return exp;
	}

	void setCoef(T i){
		coef = i;
	}

	void setExp(T i){
		exp = i;
	}
	node* getNext(){
		return Next;
	}
	void setNext(node *next){ //
		Next = next;
	}
};



template<typename T>
class Polynomial{
	friend ostream& operator<< <T> (ostream& os, const Polynomial<T> s);
	friend class node<T>;
private:
	node<int> *head;
	node<int> *dummy;
	int coef;
	int exp;
	int c;
	int e;

public:
	Polynomial(){
		dummy = new node<int>(9999, 9999);
		head = dummy;
	}

	~Polynomial(){
		node<int> *temp = head;
		while (temp->getNext() != nullptr)
		{
			temp = head->getNext();
			delete head;
			head = temp;
		}
	}

	Polynomial(string equation){
		dummy = new node<int>(9999, 9999);
		head = dummy;

		istringstream s(equation);
		while (s >> coef >> exp){
			if (coef == 0){
				sort(0, 0);
			}
			else{
				sort(coef, exp);
			}
		}

	}

	Polynomial(const Polynomial& src){
		return *this;
	}
	Polynomial& operator=(const Polynomial &s){
		node<int> * tmp = s.head;
		node<int> * two = head;
		if (tmp->getNext() == nullptr){
			s.Delete();
			two = tmp;
		}
		while (tmp->getNext() != nullptr){
			tmp->setNext(two->getNext());
			two->setNext(tmp);
		}
		return *this;
	}


	Polynomial& operator+(const Polynomial &s){
		node<int> * one = s.head;
		node<int> * two = this->head;
		while (one->getNext() != nullptr){
			if (two->getExp() == one->getExp()){
				two->setCoef(two->getCoef() - one->getCoef());
			}
			one = one->getNext();

		}

		return *this;
	}

	Polynomial operator-(const Polynomial s){
		cout << "hello";
		node<int> * one = s.head->getNext();
		node<int> * two = head->getNext();
		node<int> *nNode;
		int c;
		int e;
		while (one != nullptr){
			if (two->getExp() == one->getExp()){
				c = two->getCoef() - one->getCoef();
				e = two->getExp();
				nNode = new node<int>(c, e);
				nNode->setNext(two->getNext());
				two->setNext(nNode);
			}


			one = one->getNext();
			two = two->getNext();

		}

		return *this;
	}

	//	Polynomial	operator*(){}






private:	void simpl(){
	node<int>* tmp = head;
	node<int>* current = head->getNext();
	node<int>* current_next = head->getNext()->getNext();
	node<int>* nNode;

	int c;
	int e;
	while (current_next != nullptr){
		if (current->getExp() == current_next->getExp()){
			c = current->getCoef() + current_next->getCoef();
			e = current->getExp();
			nNode = new node<int>(c, e);
			nNode->setNext(current_next->getNext());
			tmp->setNext(nNode);
		}
		else{
			tmp = tmp->getNext();
			current = current->getNext();
		}
		current_next = current_next->getNext();
	}
}

			void sort(T coef, T exp){
				node<int> *tmp = head;
				node<int> *nNode;
				nNode = new node<int>(coef, exp);
				while (tmp->getNext() != nullptr&& tmp->getNext()->getExp() > nNode->getExp()){
					tmp = tmp->getNext();
				}
				nNode->setNext(tmp->getNext());
				tmp->setNext(nNode);
				simpl();
			}

public:
	void print(){
		node<int>* temp = head;
		while (temp->getNext() != nullptr){
			temp = temp->getNext();
			cout << temp->getCoef() << "^" << temp->getExp() << " ";
		}
	}


	void Delete()
	{
		node<int>* current = head;
		node<int>* previous;
		while (current->getNext() != nullptr) {
			previous = current;
			current = current->getNext();
			previous->setNext(current->getNext());

		}
	}
	node<T>* getHead(){
		return head;
	}

};
template<typename T>
ostream& operator<<(ostream& os, Polynomial<T> *s){
	node<int>* temp = s->getHead();
	while (temp->getNext() != nullptr){
		temp = temp->getNext();
		cout << temp->getCoef() << "^" << temp->getExp() << " ";
	}

	return os;
}


void create(ifstream &inFile){
	Polynomial<int> *one = new Polynomial<int>;
	Polynomial<int> *two = new Polynomial<int>;
	Polynomial<int> * tmp = new Polynomial<int>;
	string *line;
	string getl;
	int z = 0;
	while (z < 2){
		getline(inFile, getl);
		line = new string[1];
		if (z % 2 == 0){
			line[0] = getl;
			one = new Polynomial<int>(line[0]);
			cout << endl;
		}
		else{
			line[0] = getl;
			two = new Polynomial<int>(line[0]);

			//	cout << tmp;
			one - two;

		}

		line->clear();
		z++;
	}

}

int main(int argc, char *argv[])
{



	if (argc != 2)
		cout << "usage: " << argv[0] << " <filename>\n";

	else {
		ifstream inFile(argv[1]);
		ofstream outFile("matrix-out.txt");

		if (!inFile.is_open())
			cout << "Could not open file\n";

		else {
			while (!inFile.eof()){
				create(inFile);
			}
			inFile.close();
		}
	}

	system("PAUSE");
	return 0;
}
