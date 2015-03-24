/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Uebung zu Konstruktoren und Speicherallokation nach RIAA.
 *          UML Diagram als PDF im Projektpfad
 */

#include <iostream>
#include <stdio.h>
using namespace std;

/* Usually in .h-File */
class Inner{
public:
	Inner();
	Inner(const Inner& other);
	Inner& operator=(const Inner& other);
	virtual ~Inner();
};

Inner::Inner(){
	printf("Inner()\n");
}
Inner::Inner(const Inner& other){
	printf("Inner(const Inner& other)\n");
}
Inner& Inner::operator=(const Inner& other){
	printf("operator(const Inner& other)\n");
	return *this;
}
Inner::~Inner(){
	printf("~Inner()\n");
}


class Outer{
private:
	Inner* inner;

public:
	Outer();
	Outer(const Outer& other);
	Outer& operator=(const Outer& other);
	virtual ~Outer();
};

Outer::Outer(){
	printf("Outer()\n");
	inner = new Inner();
}

Outer::Outer(const Outer& other){
	printf("Outer(const Outer& other)\n");
	inner = new Inner( *(other.inner) );
}

Outer& Outer::operator=(const Outer& other){
	printf("operator=(const Outer& other)\n");
	if(this != &other){
		delete inner;
		inner = new Inner( *(other.inner) );
	}
	return *this;
}

Outer::~Outer(){
	printf("~Outer()\n");
	delete inner;
}

// Democode
void call_by_val(Outer a){
	printf("call_by_val\n");
}

void call_by_ref(Outer& a){
	printf("call_by_ref\n");
}

int main() {
	Outer a;
	Outer b;

	printf("\n--Before call_by_val(Outer a) \n");
	call_by_val(a);
	printf("\n--Before call_by_ref(Outer& a) \n");
	call_by_ref(a);
	printf("\n--Before operator= \n");
	a = b;
	printf("\n--Before Stack Cleanup\n");

	return 0;
}
