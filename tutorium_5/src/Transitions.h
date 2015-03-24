/*
 * @file    Transitions.h
 * @author  Simon Brummer
 * @desc    Transitions-Interface fuer die kuenftige Statemaschine.
 *          Die Klasse sollte aus selbstschutzgruenden pure virtual sein.
 */
#ifndef TRANSITIONS_H_
#define TRANSITIONS_H_

class Transitions{
	public:
	  virtual void Transition1(void) = 0;
	  virtual void Transition2(void) = 0;
	  virtual void Transition3(void) = 0;
};

#endif
