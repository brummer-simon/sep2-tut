/* 
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Demoprojekt fuer das erste SE2 Tutorium.
 *          Das Projekt darf gerne die Basis fuer euer eigentliches Projekt sein
 *          da, hier bereits alles Grundlegende Konfiguriert ist.
 */

//#define SIMULATION  // #define Auskommentieren falls mit der Simulation gearbeitet wird.

#include <cstdlib>
#include <iostream>
#include "Blink_Thread.h"
#include "lib/HWaccess.h"

using namespace std;

int main(int argc, char *argv[]) {

    // Baut Verbindung zu Simulation auf
    #ifdef SIMULATION
        IOaccess_open();
    #endif

    cout << "First QNX Demo, let there be light!." << endl;

    Blink_Thread th1(5); // Thread 1, soll 5 mal blinken
    Blink_Thread th2(3); // Thread 2, soll 3 mal blinken

    th1.start(NULL);     // Start Thread 1
    th2.start(NULL);     // Start Thread 2

    th2.join();          // Warten auf das Ende von Thread 1
    th1.join();          // Warten auf das Ende von Thread 2

    #ifdef SIMULATION
       IOaccess_close();
    #endif

    return EXIT_SUCCESS;
}
