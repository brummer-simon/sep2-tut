/**
 * @file    Blink_Thread.h
 * @author  Simon Brummer
 * @version 0.1
 *
 * Headerfile zur Demoklasse fuer das SEP2 Tutorium. Es wird folgendes gezeigt:
 * - Ableiten von Klassen
 * - Sichtbarkeitsregeln fuer Variablen und Methoden
 * - Konstruktorenarten
 * - Doxygenkompatible Kommentare.
 */

#ifndef BLINK_THREAD_H_
#define BLINK_THREAD_H_

#include <stdint.h>
#include <pthread.h>
#include "lib/HAWThread.h"

using namespace thread;

class Blink_Thread: public HAWThread {
    /* Variablen deklarationen */
    private:
        uint16_t const times_ ;      ///< Anzahl der Blinkvorgaenge.

        uint16_t ioControlAddress_;  ///< Registeradresse IO Controlregister.
        uint16_t registerAddress_ ;  ///< Registeradresse mit gruener Lampe.

        uint8_t ioControlBitmask_ ;  ///< Setzen der Richtungsbits.
        uint8_t greenLightBitmask_;  ///< Bitmaske zum Ansteuern der gruenen Lampe.

        static pthread_mutex_t mtx_; ///< Synchronisationsmutex.

    /* Methoden deklarationen */
    public:
        Blink_Thread(uint16_t times); ///< Standard Konstruktor. Offentlich Aufrufbar.
        virtual ~Blink_Thread();      ///< Standard Dekonstruktor.

    private:
        Blink_Thread(const Blink_Thread& b);      ///< Copy-Konstruktor. Privat, deshalb kann dieses Objekt nicht als "Call-by-value" uebergeben werden.
        Blink_Thread& operator=(Blink_Thread& b); ///< Zuweisungskonstruktor. Objekt kann nicht an eine gleichartige Referenz zugewiesen werden da private.

        virtual void execute(void*); ///< Geerbt aus HAWThread. Muss implementiert werden.
        virtual void shutdown();     ///< Geerbt aus HAWThread. Muss implementiert werden.

        uint8_t turnGreenOn() const;   ///< Einfache Methode, const versichert das diese Methode keine Instanzvariable veraendert.
        uint8_t turnGreenOff() const;  ///< Schaltet gruenes Licht aus.
};

#endif
