/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Beispiel implementation der Singletonvarianten:
 *          - Gov Singleton
 *          - Meyers Singleton
 *          - DCLP Singleton
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

/* Begin GOVSingleton */
// Declaration
class GOFSingleton {
private:
    static GOFSingleton* instance_;

private:
    GOFSingleton();
	GOFSingleton(const GOFSingleton& other);
	GOFSingleton& operator=(const GOFSingleton& other);
	~GOFSingleton();

public:
    static GOFSingleton* getInstance();
	void method(void);
};

// Implementation
GOFSingleton* GOFSingleton::instance_ = 0;

GOFSingleton* GOFSingleton::getInstance(){
	if( !instance_ ){
		instance_ = new GOFSingleton();
	}
	return instance_;
}

GOFSingleton::GOFSingleton(){
	printf("ctor GOF Singleton\n");
}

GOFSingleton::~GOFSingleton(){
	printf("dtor GOF Singleton\n");
}

void GOFSingleton::method(){
	printf("method called\n");
}
/* End GOV-Singleton */


/* Begin Meyers-Singleton */
// Declaration
class MeyersSingleton {
private:
    MeyersSingleton();
    MeyersSingleton(const MeyersSingleton& other);
    MeyersSingleton& operator=(const MeyersSingleton& other);
    ~MeyersSingleton();

public:
    static MeyersSingleton* getInstance();
    void method(void);
};

// Implementation
MeyersSingleton* MeyersSingleton::getInstance(){
	static MeyersSingleton instance;
	return &instance;
}

MeyersSingleton::MeyersSingleton(){
	printf("ctor Meyers Singleton\n");
}

MeyersSingleton::~MeyersSingleton(){
	printf("dtor Meyers Singleton\n");
}

void MeyersSingleton::method(){
	printf("method called\n");
}
/* End Meyers-Singleton */


/* Begin DCLP-Singleton */
// Declaration
class DCLPSingleton {
private:
    static DCLPSingleton* instance_;

private:
    DCLPSingleton();
    DCLPSingleton(const DCLPSingleton& other);
    DCLPSingleton& operator=(const DCLPSingleton& other);
    virtual ~DCLPSingleton();

public:
    static DCLPSingleton* getInstance();
    void method(void);
};

// Implementation
DCLPSingleton* DCLPSingleton::instance_ = 0;

DCLPSingleton* DCLPSingleton::getInstance(){
	static pthread_mutex_t mtx_ =  PTHREAD_MUTEX_INITIALIZER;

	if( !instance_ ){
		pthread_mutex_lock(&mtx_);
		if( !instance_ ){
		    instance_ = new DCLPSingleton();
		}
		pthread_mutex_unlock(&mtx_);
	}
	return instance_;
}

DCLPSingleton::DCLPSingleton(){
	printf("ctor DCLP Singleton\n");
}

DCLPSingleton::~DCLPSingleton(){
	printf("dtor DCLP Singleton\n");
}

void DCLPSingleton::method(){
	printf("method called\n");
}
/* End DCLP Singleton */


// Main Function and Demo Code
int main() {
	GOFSingleton*    gov  = GOFSingleton::getInstance();
	MeyersSingleton* mey  = MeyersSingleton::getInstance();
	DCLPSingleton*   dclp = DCLPSingleton::getInstance();

	gov->method();
	mey->method();
	dclp->method();

	return 0;
}
