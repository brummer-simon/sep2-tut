/*
 * @file    S1.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. Implementierung von State S1.
 *          Sobald Event "TRANSITION1" auftritt. Wechselt S1 zu S2.
 */
#include "S1.h"
#include "S2.h"
#include "Dispatcher.cpp"
#include <new>

S1::S1(Context* con): State::State(con){
    printf("S1()\n");

	// Start listen on Event Transition1
	Dispatcher* dsp = Dispatcher::getInstance();
	dsp->addListeners( this->con_, TRANSITION1);
}

S1::~S1(){
	printf("~S1()\n");
}

void S1::Transition1(void){
	printf("S1 --T1--> S2\n");

	// Stop listen to Event Transmission1
	Dispatcher* dsp = Dispatcher::getInstance();
	dsp->remListeners( this->con_, TRANSITION1);

	// Move to State S2.
	new (this) S2(this->con_);
}


