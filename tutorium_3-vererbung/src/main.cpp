/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Tutorium 3. Vererbung, dynamische Bindung und Keyword virtual.
 *          Aufrufen der Methoden einer Superklasse(wg. moeglicher Mehrfachvererbung)
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* Implementation Superclass */
class Super_Class{
  private:
	int super_int_;

  public:
	Super_Class(): super_int_(0){
		printf("Super_Class()\n");
	}

	Super_Class(int i): super_int_(i){
		printf("Super_Class(int)\n");
	}

	Super_Class(const Super_Class& other): super_int_(other.super_int_){
		printf("Super_Class(const Super_Class&)\n");
	}

	Super_Class& operator=(const Super_Class& other){
		printf("Super_Class& operator=(const Super_Class&)\n");
		if( this != &other){
			super_int_ = other.super_int_;
		}
		return *this;
	}

	virtual ~Super_Class(){
		printf("~Super_Class()\n");
	}

	string to_string_non_virtual(void) const {
		ostringstream os;
		os << "[Super_Class: super_int_=" << super_int_ << "]";
		return os.str();

	}

	virtual string to_string_virtual(void) const {
		ostringstream os;
		os << "[Super_Class: super_int_=" << super_int_ << "]";
		return os.str();
	}
};

/* Implementation Inherited Class */
class Base_Class: public Super_Class{
  private:
	int base_int_;

  public:
	Base_Class(): base_int_(0){
		printf("Base_Class()\n");
	}

	Base_Class(int super_int): Super_Class(super_int), base_int_(0){
		printf("Base_Class(int)\n");
	}

	Base_Class(int super_int, int base_int): Super_Class(super_int), base_int_(base_int){
		printf("Base_Class(int,int)\n");
	}

	Base_Class(const Base_Class& other): Super_Class(other), base_int_(other.base_int_) {
		printf("Base_Class(const Base_Class&)\n");
	}

	Base_Class& operator=(const Base_Class& other){
		printf("Base_Class& operator=(const Base_Class&)\n");
		if( this != &other){
			Super_Class::operator=(other);
			base_int_ = other.base_int_;
		}
		return *this;
	}

	virtual ~Base_Class(){
		printf("~Base_Class()\n");
	}

	string to_string_non_virtual(void) const {
		ostringstream os;
		os << "[Base_Class: base_int_=" << base_int_ << Super_Class::to_string_non_virtual() <<"]";
		return os.str();
	}

	virtual string to_string_virtual(void) const {
		ostringstream os;
		os << "[Base_Class: base_int_=" << base_int_ << Super_Class::to_string_virtual() <<"]";
		return os.str();
	}
};

/* Main Function */
int main(int argc, char** args){
	// Hier nur heapallokierte Objekte, da es bei stackallokierten
	// Objekten keine dynamische Bindung gibt bzw. nicht formulierbar ist.

	printf("Konstruktoren Aufrufe\n");
	Super_Class* super = new Super_Class(1);
	Super_Class* base  = new Base_Class(1,2);

	printf("\n\nVirtuelle Funktionen\n");
	printf("%s\n", super->to_string_virtual().c_str() );
	printf("%s\n", base->to_string_virtual().c_str() );

	printf("\n\nNicht - Virtuelle Funktionen\n");
	printf("%s\n", super->to_string_non_virtual().c_str() );
	printf("%s\n", base->to_string_non_virtual().c_str() );

	printf("\n\nDestruktoren Aufrufe\n");
	delete super;
	delete base;

	return 0;
}


