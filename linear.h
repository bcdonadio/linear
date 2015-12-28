#ifndef _LINEAR_H
#define _LINEAR_H

#include <Arduino.h>

//Types
typedef struct{
	unsigned int temp, pwrin, pwrout, swr;
}Stats;

enum State{RX,TX};
enum Warn{OK,WARN};
enum Lock{FREE,LOCKED};

#define DEBOUNCETIME 10 //in miliseconds
#define ROWS  4
#define COLUMNS 20
#define MAXTEMPREAD 99
#define YD_PINS 4 //number of yaesu band information interface pins

//Pin config
//Digital numbering
const char band[] = {0, 1, 2, 3}; //80m, 40m, 20m-15m and 12m-10m bands' relays
#define BIAS_PIN      4    //amplificator bias relay
#define BANDSW_PIN    10   //band momentaneous switch
#define REARM_PIN     11   //rearm momentaneous switch
const char yd[] = {12, 13, 14, 15}; //Yaesu band information
#define YTX_PIN       16   //Yaesu transmitting state pin
#define LCD7_PIN      18   //LCD Data bus line 7
#define LCD6_PIN      19   //LCD Data bus line 6
#define LCD5_PIN      20   //LCD Data bus line 5
#define LCD4_PIN      21   //LCD Data bus line 4
#define LCDR_PIN      22   //LCD Register Selection pin
#define LCDE_PIN      23   //LCD Enable pin
//Analog numbering
#define TEMP_PIN      6    //Analog temperature reading

#endif //_LINEAR_H
