/*
 * @file   S2.h
 * @author Simon Brummer
 * @desc   Tutorium 6. Deklaration von State S2.
 */

#ifndef S2_H_
#define S2_H_

#include "State.cpp"
#include "Context.cpp"

class S2: public State{
public:
	S2(Context* con);
	~S2();

	virtual void Transition1(void);
	virtual void Transition2(void);

private:
	S2(const S2& other);
	S2& operator=(const S2& other);
};

#endif /* S2_H_ */
