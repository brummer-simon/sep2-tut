/*
 * @file    Dispatcher.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. Zum Singleton erweiterer Dispatcher aus Beispiel 5.
 *          Singleton implementation damit sich die States selbst an 
 *          EVENTS als Listener heften koennen.
 */
#ifndef DISPATCHER_CPP_
#define DISPATCHER_CPP_

#include "Transitions.h"
#include <cstdio>
using namespace std;

#define MAXLISTENERS 5

// Events in the System. Each EVENT needs a corresponding Method in class Transactions
enum EVENTS{TRANSITION1,TRANSITION2,TRANSITION3,NEVENTS};

// typedef: Method from Class "Transactions"
typedef void (Transitions::*method_t)(void);

class Dispatcher{
private:
	method_t methods[NEVENTS];
	Transitions* listeners_[NEVENTS][MAXLISTENERS];

private:
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

	virtual ~Dispatcher(){

	}

	Dispatcher(const Dispatcher& other);
	Dispatcher& operator=(const Dispatcher& other);

public:

	static Dispatcher* getInstance(void){
		static Dispatcher instance_;
		return &instance_;
	}

	virtual void addListeners(Transitions* listener, EVENTS event){
		// Add Listener to be called on a specific Event
		for(int i=0; i<MAXLISTENERS; i++){
			if( listeners_[event][i] == NULL || listeners_[event][i] == listener){
				listeners_[event][i] = listener;
				return;
			}
		}
		printf("Sorry, no Space for Listener at requested Event left\n");
	}

	virtual void remListeners(Transitions* listener, EVENTS event){
		// Remove Listener from a specific Event
		for(int i=0; i<MAXLISTENERS; i++){
			if( listeners_[event][i] == listener){
				listeners_[event][i] = NULL;
				return;
			}
		}
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
};

#endif












