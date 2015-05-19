/*
 * @file    S1.h
 * @author  Simon Brummer
 * @desc    Tutorium 6. Deklaration von State S1.
 */
#ifndef S1_H_
#define S1_H_

#include "State.cpp"
#include "Context.cpp"


class S1: public State{
public:
	S1(Context* con);
	virtual ~S1();
	virtual void Transition1(void);

private:
	S1(const S1& other);
	S1& operator=(const S1& other);
};
#endif











