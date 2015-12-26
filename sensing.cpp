#include "sensing.h"

boolean statsOk(Stats *stats){
  if(stats->temp>50)
    return false;

  return true;
}

void readSensors(Stats *stats){
  stats->temp=analogRead(TEMP_PIN);
  stats->pwrin=0;
  stats->pwrout=0;
  stats->swr=0;
}

