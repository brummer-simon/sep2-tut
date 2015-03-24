/*
 * @file    Context.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. Context Klasse fuer Statemaschines.
 *          Delegiert Methodenaufrufe an den aktuellen State
 *          und haelt die Daten die von den States 
 *          manipuliert werden.
 */
#ifndef CONTEXT_CPP_
#define CONTEXT_CPP_

#include "Transitions.h"
#include "Dispatcher.cpp"

class Context: public Transitions{

private:
	Transitions* state_;

public:
	Context(): state_(NULL){
		printf("Context()\n");
	}

	virtual ~Context(){
		printf("~Context()\n");

		// On cleanup: Remove yourself from all Events
		Dispatcher* dsp = Dispatcher::getInstance();
		dsp->remListeners(this, TRANSITION1);
		dsp->remListeners(this, TRANSITION2);
		dsp->remListeners(this, TRANSITION3);

		// Delete Inner Object too!
		if(state_ != NULL){
			delete state_;
			state_ = NULL;
		}
	}

	virtual void setState(Transitions* state){
		state_ = state;
	}

	virtual void Transition1(void){
		state_->Transition1();
	}

	virtual void Transition2(void){
		state_->Transition2();
	}

	virtual void Transition3(void){
		state_->Transition3();
	}

private:
	Context(const Context& other);
	Context& operator=(const Context& other);
};

#endif


