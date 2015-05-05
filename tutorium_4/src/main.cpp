/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.4
 * @desc    Tutorium 4. ISR registrieren. Umgang mit Pulsmessages
 */

#include <iostream>
#include <cstdlib>
#include <sys/neutrino.h>
#include <sys/siginfo.h>
#include "lib/HWaccess.h"

using namespace std;

int isrId = 0;
int isrChannel = 0;
int isrConnection = 0;
struct sigevent isrEvent;

// ISR (c-Function)
const struct sigevent* ISR_DIO(void* arg, int id) {
    struct sigevent* event = (struct sigevent*) arg;
    out8(0x30F, 0);

    event->sigev_notify = SIGEV_PULSE ;
    event->__sigev_un1.__sigev_coid = isrConnection;
    event->__sigev_un2.__st.__sigev_code = 0;
    event->sigev_value.sival_int = 1;
    return event;
}


void registerISR(void){
    out8(0x30F, 0);
    out8(0x30B, 0b11111101);

    SIGEV_PULSE_INIT(&isrEvent, isrConnection, SIGEV_PULSE_PRIO_INHERIT, 0, 0);
    isrId = InterruptAttach(11, ISR_DIO, &isrEvent, sizeof(isrEvent), 0);
    if (isrId == -1) {
        exit(EXIT_FAILURE);
    }
}


void unregisterISR(void){
    if( InterruptDetach(isrId) == -1 ){
        exit(EXIT_FAILURE);
    }
    out8(0x30B, 0b11111111);
    out8(0x30F,0);
}


int main() {
    // Init and Register ISR
    if (ThreadCtl(_NTO_TCTL_IO_PRIV, 0) == -1){
        exit(EXIT_FAILURE);
    }

    if (( isrChannel = ChannelCreate(0)) == -1){
        exit(EXIT_FAILURE);
    }

    if ((isrConnection = ConnectAttach(0, 0, isrChannel, 0, 0)) == -1){
        exit(EXIT_FAILURE);
    }

    // Register Interupt Service Routine
    registerISR();

    struct _pulse pulse;
    
    // Wait for Pulse Message
    do{
        MsgReceivePulse(isrChannel,&pulse,sizeof(pulse),NULL);
        
        // Print received Pulse message Value
        cout << "Got an Interrupt, value: " << pulse.value.sival_int << endl;
    }while(1);

    // Cleanup
    unregisterISR();
    if( ConnectDetach(isrConnection) == -1){
        exit(EXIT_FAILURE);
    }

    if( ChannelDestroy(isrChannel) == -1 ){
        exit(EXIT_FAILURE);
    }

    return 0;
}
