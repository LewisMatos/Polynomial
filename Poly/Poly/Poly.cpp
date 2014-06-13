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
	/*
	node* &getNext(){
	return Next;
	}
	*/
	node* getNext(){
		return Next;
	}
	void setNext(node *next){ //
		Next = next;
	}
};



template<typename T>
class Polynomial{
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
	~Polynomial(){}

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
			simpl();
		}

		print();
	}


	//	Polynomial(const Polynomial& src){}

	//	Polyn
	//	Polynomial	operator+(Polynomial& s){}





	//	Polynomial	operator-(){}

	//	Polynomial	operator*(){}

	//	Polynomial	operator=(){}

	//	Polynomial	operator<<(){}



	void simpl(){
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

	}


	void print(){
		node<int>* temp = head;
		while (temp->getNext() != nullptr){
			temp = temp->getNext();
			cout << temp->getCoef() << "^" << temp->getExp() << " ";
		}

	}


	void Delete() //Deletes the element that user asked
	{

		node<int>* current = head;
		node<int>* previous;
		while (current->getNext() != nullptr) { // while current next node is not nullptr
			previous = current; // make previos node be current
			current = current->getNext(); //make current to equal the next node
			previous->setNext(current->getNext()); // skipping over the



		}
	}

};


/*
template<class T>
void print_list(node<T>* p){

while (p){
cout << p->getData() << " ";
p = p->Next();
}
cout << endl;
}

node<int>* make_int_list(int n){
if (n <= 0) return 0;
node<int>* first, *p, *q;
first = p = new node<int>(1);
for (int i = 2; i <= n; i++){
q = new node<int>(i);
p->getNext() = q;
p = q;
}
return first;
}

template<class T>
void print_list_rec(node<T>* p){
if (p == 0) return;
cout << p->getData() << " ";
print_list_rec(p->getNext());
}
/*
template<class T>
void add_at_end(node<T>* &first, node<T>*r){
node<T>* p;
p = first;
while (p->getNext()){
p = p->getNext();
}
p->getNext() = r;
}
*/
void create(ifstream &inFile){
	Polynomial<int> *one;
	Polynomial<int> *two;
	string *line;
	string getl;
	int z = 0;
	while (z < 2){
		getline(inFile, getl);
		line = new string[1];
		if (z % 2 == 0){

			for (int i = 0; i <= 0; i++)
			{
				line[i] = getl;
			}
			one = new Polynomial<int>(line[0]);
			cout << endl;
		}
		else{
			for (int i = 0; i <= 0; i++)
			{
				line[i] = getl;
			}
			two = new Polynomial<int>(line[0]);
			cout << endl;
		}
		line->clear();
		z++;
	}


}

int main(int argc, char *argv[])
{

	/*
	//create and print a list of n integer nodes
	int n;
	cout << "How many nodes? ";
	cin >> n;
	cout << endl;
	print_list<int>(make_int_list(n));
	cout << endl;
	//now do it recursively
	print_list_rec<int>(make_int_list(n));
	cout << endl;
	node<int>* a = make_int_list(9);
	node<int>* b = new node<int>(56);
	add_at_end(a, b);
	cout << endl;
	print_list<int>(a);

	*/

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
