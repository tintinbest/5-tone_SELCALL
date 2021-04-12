/*
  5tone.h - Bibliothèque pour génération du 5 tons.
  OCM - Quentin PETIT.
*/
#ifndef Fivetone_h
#define Fivetone_h

#include "Arduino.h"

class Fivetone
{
  public:
    Fivetone(int protocol, int pin);
    void send5tone();
    void setSequence(int sequence[5]);
    int getProtocol();
    int getSequence();
    void dispCCIR();
    void charToSeq(char SeqString[5]);
    
  private:
    int _pin;
    int _protocol;
    int _ccir[16] = {1981, 1124, 1197, 1275, 1358, 1446, 1540, 1640, 1747, 1860, 2400, 930, 2247, 991, 2110, 100}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,R,Dureé
    int _zvei1[16] = {2400, 1060, 1160, 1270, 1400, 1530, 1670, 1830, 2000, 2200, 2800, 810, 970, 885, 2600, 70}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,R,Dureé
    int _zvei2[16] = {2400, 1060, 1160, 1270, 1400, 1530, 1670, 1830, 2000, 2200, 885, 810, 2800, 2600, 970, 70}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,R,Dureé
    int _zvei3[16] = {2200, 970, 1060, 1160, 1270, 1400, 1530, 1670, 1830, 2000, 885, 2800, 810, 2600, 2400, 70}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,R,Dureé
    int _eea[16] = {1981, 1124, 1197, 1275, 1358, 1446, 1540, 1640, 1747, 1860, 1055, 930, 2247, 991, 2110, 40}; //0,1,2,3,4,5,6,7,8,9,A,B,C,D,R,Dureé
    int _sequence[5];
};

#endif