#ifndef _CHARS_H
#define _CHARS_H

//Special symbols shortcuts
byte char_degree = B11011111;
byte char_key = B00000000;
byte char_black[6] = {
  B11111110,
  B00000001, //need mapping
  B00000010, //need mapping
  B00000011, //need mapping
  B00000100, //need mapping
  B11111111
};

//Special symbols bitmaps
byte map_key[8] = {
  B00100,
  B01010,
  B00100,
  B00100,
  B00110,
  B00111,
  B00100,
  B00000,
};

byte map_black[4][8] = {
  {
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000
  },

  {
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000
  },

  {
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100
  },

  {
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110
  },
};

#endif //_CHARS_H

