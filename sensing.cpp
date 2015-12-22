#include "sensing.h"

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


