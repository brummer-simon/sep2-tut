/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. Statemaschine wird erzeugt und reagiert 
 *          auf, am Dispatcher eintretende EVENTS. 
 *          Registrierung und abmeldung als Listener 
 *          erfolgt durch die States selbst.
 */
#include "Dispatcher.cpp"
#include "Context.cpp"
#include "S1.h"
using namespace std;

int main() {
	Dispatcher* disp = Dispatcher::getInstance();
	Context* con= new Context();
	con->setState(new S1(con));

	// Register s1 and s2 to listen on Event TRANSITION1
	disp->callListeners(TRANSITION3); // S1 don't react on Event Transmission3
	disp->callListeners(TRANSITION1); // Should move to S2
	disp->callListeners(TRANSITION1); // Should stay in S2
	disp->callListeners(TRANSITION2); // Should move to S1

	delete con;
	return 0;
}


