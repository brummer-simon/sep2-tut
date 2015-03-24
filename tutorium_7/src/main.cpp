/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 7. Konfiguration QNX Timer.
 *          Dieser Timer sendet alle 2 Sekunden eine Pulse Message
 */
#include <cstdlib>
#include <cstdio>
#include <sys/neutrino.h>

int main(int argc, char** argv){    

    // Message Passing specific Variables
    int channel;  
    int connection; 
    struct _pulse     pulse;

    // Timer specific Variables
    timer_t           timerId;
    struct itimerspec timerSpec;
    struct sigevent   timerEvent;

    // Setup Message Passing Channels and Connections
    if( (channel  = ChannelCreate(0)) == -1){
        exit(EXIT_FAILURE);
    }
    if( (connection = ConnectAttach(0, 0, channel, 0, 0)) == -1){
        exit(EXIT_FAILURE);
    }

    // Setup Event Structure
    SIGEV_PULSE_INIT (&timerEvent, connection, SIGEV_PULSE_PRIO_INHERIT, 0, 0);

    // Create Timer
    if (timer_create (CLOCK_REALTIME, &timerEvent, &timerId) == -1) {
        exit (EXIT_FAILURE);
    }

    // Configure Timer to send every two seconds.
    timerSpec.it_value.tv_sec = 2;      
    timerSpec.it_value.tv_nsec = 0;
    timerSpec.it_interval.tv_sec = 2;
    timerSpec.it_interval.tv_nsec = 0;   
    timer_settime (timerId, 0, &timerSpec, NULL);

    // Loop started by timer.
    while(1){
        MsgReceivePulse(channel, &pulse, sizeof (pulse), NULL);
		printf("Timer sent a Message\n");
    }

    // Cleanup
    if( ConnectDetach(connection) == -1){
        exit(EXIT_FAILURE);
    }

    if( ChannelDestroy(channel) == -1 ){
        exit(EXIT_FAILURE);
    }

    return 0;
}
