/*
 * @file    Dispatcher.cpp
 * @author  Simon Brummer
 * @desc    Der Dispatcher erhaelt Events und ruft bei eintreffen
 *          eines Events, zu zugehoerigen Methoden der Listener auf, die
 *          sich dafuer Registriert haben.
 */
#ifndef DISPATCHER_CPP_
#define DISPATCHER_CPP_

#include "Transitions.h"
#include <cstdio>
using namespace std;

#define MAXLISTENERS 5

// Events in the System. Each EVENT needs a corresponding Method in class Transactions
enum EVENTS{TRANSITION1,TRANSITION2,TRANSITION3,NEVENTS};

// typedef: Method from Class "Transitions"
typedef void (Transitions::*method_t)(void);

class Dispatcher{
private:
	method_t methods[NEVENTS];
	Transitions* listeners_[NEVENTS][MAXLISTENERS];

public:
	Dispatcher(){
		// Clear Listener Pointer 2Dim Array
		for(int i=0; i<NEVENTS; i++){
			for(int j=0; j<MAXLISTENERS; j++){
				listeners_[i][j] = NULL;
			}
		}

		// Add Method pointer to Call Method Array
		methods[TRANSITION1] = &Transitions::Transition1;
		methods[TRANSITION2] = &Transitions::Transition2;
		methods[TRANSITION3] = &Transitions::Transition3;
	}

	virtual ~Dispatcher(){}

	virtual void addListener(Transitions* listener, EVENTS event){
		// Add Listener to be called on a specific Event
		for(int i=0; i<MAXLISTENERS; i++){
			if( listeners_[event][i] == NULL || listeners_[event][i] == listener){
				listeners_[event][i] = listener;
				return;
			}
		}
		printf("Sorry, no Space for Listener at requested Event left\n");
	}

	virtual void remListener(Transitions* listener, EVENTS event){
		// Remove Listener from a specific Event
		for(int i=0; i<MAXLISTENERS; i++){
			if( listeners_[event][i] == listener){
				listeners_[event][i] = NULL;
				return;
			}
		}
		printf("Sorry, couldn't find Listener at requested Event\n");
	}

	virtual void callListeners(EVENTS event){
		// Call for every registered Listener
		// the Method that corresponds with event.
		for(int i=0; i<MAXLISTENERS; i++){
			if( listeners_[event][i] != NULL){
				(listeners_[event][i]->*methods[event])();
			}
		}
	}


private:
	Dispatcher(const Dispatcher& other);
	Dispatcher& operator=(const Dispatcher& other);
};

#endif
