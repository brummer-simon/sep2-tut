//============================================================================
// Name        : tutorium_2-constructors.cpp
// Author      : Simon Brummer
// Description : Constructor Special. Explanation of the "great Three".
//               Difference Call by Value and Call by Reference
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;

/* Declaration: This goes into usually .h-File */
class Obj{
private:
	string* pName_;

public:
	Obj();                            // Constructor
	Obj(string name);                 // Constructor with Parameter
	Obj(const Obj& other);            // Copy Constructor
	Obj& operator=(const Obj& other); // Assignment Operator
	virtual ~Obj();                   // Destructor
};

/* Implementation: This goes into usually .cpp-File */
// Constructor
Obj::Obj() {
	this->pName_ = new string("NO_NAME");
	printf("Name: %s, Func: Obj()\n", this->pName_->c_str());
};

// Constructor with Parameter
Obj::Obj(string name){
	this->pName_ = new string(name);
	printf("Name: %s, Func: Obj(string name)\n", this->pName_->c_str());
};

// Copy Constructor
Obj::Obj(const Obj& other){
	this->pName_ = new string( *(other.pName_) );
	printf("Name: %s, Func: Obj(const Obj& other)\n", this->pName_->c_str());
};

// Assignment Operator
Obj& Obj::operator=(const Obj& other){
	printf("Name: %s, Func: operator=(const Obj& other)\n", this->pName_->c_str());
	if(this != &other){
		delete this->pName_;
		this->pName_ = new string( *(other.pName_) );
	}
	return *this;
};

// Destructor
Obj::~Obj(){
	printf("Name: %s, Func: ~Obj()\n", this->pName_->c_str());
	delete this->pName_;
};


/* Demo Code */
// Call by Value: Copy Constructor is called.
void call_by_val(Obj obj){
	printf("Func: call_by_val(Obj obj)\n");
}

// Call by Reference: No Constructor is called
void call_by_ref(Obj& obj){
	printf("Func: call_by_ref(Obj& obj)\n");
}

int main(void) {
	// Constructors
	//Obj no_name;        // Obj() call.
	Obj a("A");         // Obj(string name) call.
	Obj b("B");		  // Obj(string name) call.
	//Obj a_cpy(a);       // Obj(const Obj& other) call. Copy Constructor

	// Assignment
	b.operator =(a);
	b = a;

	// Copy Constructor and Call by Value
	//call_by_val(no_name);
	//call_by_ref(no_name);
	return 0;
}











