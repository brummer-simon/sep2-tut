/*
 * @file    Transitions.h
 * @author  Simon Brummer
 * @desc    Turotium 6. Transitions-Interface fuer die Statemaschine.
 *          Die Klasse sollte aus selbstschutzgruenden pure virtual sein.
 */
#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

class Transitions{
	public:
	  virtual void Transition1(void) = 0;
	  virtual void Transition2(void) = 0;
	  virtual void Transition3(void) = 0;
	  virtual ~Transitions(void){};
};

#endif
