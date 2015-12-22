#include <Arduino.h>
#include <LiquidCrystal.h>
#include "linear.h"

//Pin config
#define RELAY80_PIN   0    //80m band relay
#define RELAY40_PIN   1    //40m band relay
#define RELAY20_PIN   2    //20m-15m band relay
#define RELAY10_PIN   3    //12m-10m band relay
#define BIAS_PIN      4    //amplificator bias relay
#define BANDSW_PIN    10   //band momentaneous switch
#define REARM_PIN     11   //rearm momentaneous switch
#define YD0_PIN       12   //Yaesu band interface pin D0
#define YD1_PIN       13   //Yaesu band interface pin D1
#define YD2_PIN       14   //Yaesu band interface pin D2
#define YD3_PIN       15   //Yaesu band interface pin D3
#define YTX_PIN       16   //Yaesu transmitting state pin
#define LCD7_PIN      18   //LCD Data bus line 7
#define LCD6_PIN      19   //LCD Data bus line 6
#define LCD5_PIN      20   //LCD Data bus line 5
#define LCD4_PIN      21   //LCD Data bus line 4
#define LCDR_PIN      22   //LCD Register Selection pin
#define LCDE_PIN      23   //LCD Enable pin

//LCD Positions
#define TX_MSG  "TX" //Transmitting icon
#define TX_POSX 0
#define TX_POSY 0
#define WARNING_MSG "WARNING" //Harmful stats warning
#define WARNING_POSX  0  
#define WARNING_POSY  3
#define LOCKED_MSG "LOCKED" //Locked status
#define LOCKED_POSX 13
#define LOCKED_POSY 3

//Macros
#define BLANK(num) ({int i;for(i=0; i<num; i++){lcd->print(" ");}})

//Globals
LiquidCrystal *lcd;
boolean locked=false;
Stats stats;

void pinSetup(){    
  pinMode(RELAY80_PIN, OUTPUT);
  pinMode(RELAY40_PIN, OUTPUT);
  pinMode(RELAY20_PIN, OUTPUT);
  pinMode(RELAY10_PIN, OUTPUT);
  pinMode(BIAS_PIN, OUTPUT);  
  pinMode(BANDSW_PIN, INPUT_PULLUP);
  pinMode(REARM_PIN, INPUT_PULLUP);
  pinMode(YD0_PIN, INPUT);
  pinMode(YD1_PIN, INPUT);
  pinMode(YD2_PIN, INPUT);
  pinMode(YD3_PIN, INPUT);
}

void lcdSetup(){
  lcd = new LiquidCrystal(LCDR_PIN, LCDE_PIN, LCD4_PIN, LCD5_PIN, LCD6_PIN, LCD7_PIN);
  lcd->begin(20, 4); //AGM-2004D-201 has 20 rows and 4 lines
  lcd->setCursor(0, 0);
  lcd->print("Initial data");
}

boolean statsOk(Stats *stats){
  return false;
}

void readSensors(Stats *stats){
  stats->temp=0;
  stats->pwrin=0;
  stats->pwrout=0;
  stats->swr=0;
}

void updateReadings(Stats *stats){
  return;
}

void bias(boolean run){
  if(run){
    digitalWrite(BIAS_PIN, HIGH); 
    lcd->setCursor(TX_POSX, TX_POSY);           
    lcd->print(TX_MSG);
  }else{
    digitalWrite(BIAS_PIN, LOW);
    lcd->setCursor(TX_POSX, TX_POSY);            
    BLANK(sizeof(TX_MSG));
  }
}

void warning(boolean run){
  if(run){
    bias(false);
    lcd->setCursor(WARNING_POSX, WARNING_POSY);
    lcd->print(WARNING_MSG);
  }else{
    lcd->setCursor(WARNING_POSX, WARNING_POSY);
    BLANK(sizeof(WARNING_MSG));
  }
}

void linearSetup() {
  pinSetup();
  lcdSetup();
}

void linearLoop() {
  readSensors(&stats); 
  if(statsOk(&stats)){
    warning(false);
    if(!locked && digitalRead(YTX_PIN))
      bias(true);
    else
      bias(false);
  }else{
    warning(true);  
    locked=true;
  }
  
  lcd->setCursor(LOCKED_POSX, LOCKED_POSY);
  if(locked)
    lcd->print(LOCKED_MSG);
  else
    BLANK(sizeof(LOCKED_MSG));  
  
  updateReadings(&stats);
}

