
//============================================================================
// Name        : tutorium_2-constructors.cpp
// Author      : Simon Brummer
// Description : Constructor Special. Explanation of the "great Three".
//============================================================================
#include <iostream>
#include <stdio.h>
using namespace std;

/* Declaration: This goes into usually .h-File */
class Obj{
private:
	string* pName_;

public:
	Obj();
	Obj(string name);
	Obj(const Obj& other);
	Obj& operator=(const Obj& other);
	virtual ~Obj();
};

/* Implementation: This goes into usually .cpp-File */
// Default Constructor
Obj::Obj() {
	this->pName_ = new string("NO_NAME");
	printf("Name: %s, Func: Obj()\n", this->pName_->c_str());
};

// Custom Constructor
Obj::Obj(string name){
	this->pName_ = new string(name);
	printf("Name: %s, Func: Obj(string name)\n", this->pName_->c_str());
};

// Copy Constructor
Obj::Obj(const Obj& other){
	this->pName_ = new string( *(other.pName_) );
	printf("Name: %s, Func: Obj(const Obj& other)\n", this->pName_->c_str());
};

// Assign Operator
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
	printf("Name: %s, Func: ~Obj\n", this->pName_->c_str());
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

int main() {
	// Constructors
	Obj no_name;        // Obj() call.
	//Obj a("A");         // Obj(string name) call.
	//Obj b("b");		  // Obj(string name) call.
	//Obj a_cpy(a);       // Obj(const Obj& other) call. Copy Constructor

	// Assignment
	//b.operator =(a);
	//b = a;

	// Copy Constructor and Call by Value
	//call_by_val(no_name);
	//call_by_ref(no_name);
	return 0;
}
