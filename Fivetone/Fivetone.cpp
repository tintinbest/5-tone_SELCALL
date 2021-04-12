/*
  5tone.cpp - Bibliothèque pour génération du 5 tons.
  OCM - Quentin PETIT.
*/

#include "Arduino.h"
#include "Fivetone.h"

Fivetone::Fivetone(int protocol, int pin){ //Déclaration de l'objet 5tons.
  pinMode(pin, OUTPUT);
  _protocol = protocol;
  _pin = pin;
}

void Fivetone::setSequence(int sequence[5]){ //Reçoit une sequence sous la forme d'un tableau de int, par exemple : "int seq[5] = {1,9,7,2,3};" et applique cette sequence pour utilisation dans le programme 5 tons.
  for (int i = 0; i < 5; ++i)
  {
    _sequence[i] = sequence[i];
  }
}

void Fivetone::charToSeq(char SeqString[5]){ //Reçoit une sequence sous la forme d'un tableau de char, par exemple :"char seqS1[5] = {'1','8','6','5','5'};" et applique cette sequence mise en forme pour utilisation dans le programme 5 tons. /!\ a préferer par rapport à Fivetone::setSequence /!\

  int tabTone[5];


  if (SeqString[1] == SeqString[0])
  {
    SeqString[1] = 'R';
  }
  if ((SeqString[2] == SeqString[1]) && (SeqString[1] != 'R'))
  {
    SeqString[2] = 'R';
  }
  if ((SeqString[3] == SeqString[2]) && (SeqString[2] != 'R'))
  {
    SeqString[3] = 'R';
  }
  if ((SeqString[4] == SeqString[3]) && (SeqString[3] != 'R'))
  {
    SeqString[4] = 'R';
  }

  for (int i = 0; i < 5; ++i)
  {
    if (SeqString[i] == '0')
    {
      tabTone[i] = 0;
    }
    else if (SeqString[i] == '1')
    {
      tabTone[i] = 1;
    }
    else if (SeqString[i] == '2')
    {
      tabTone[i] = 2;
    }
    else if (SeqString[i] == '3')
    {
      tabTone[i] = 3;
    }else if (SeqString[i] == '4')
    {
      tabTone[i] = 4;
    }else if (SeqString[i] == '5')
    {
      tabTone[i] = 5;
    }else if (SeqString[i] == '6')
    {
      tabTone[i] = 6;
    }else if (SeqString[i] == '7')
    {
      tabTone[i] = 7;
    }else if (SeqString[i] == '8')
    {
      tabTone[i] = 8;
    }else if (SeqString[i] == '9')
    {
      tabTone[i] = 9;
    }else if (SeqString[i] == 'A' ||SeqString[i] == 'G')
    {
      tabTone[i] = 10;
    }else if (SeqString[i] == 'B')
    {
      tabTone[i] = 11;
    }else if (SeqString[i] == 'C')
    {
      tabTone[i] = 12;
    }else if (SeqString[i] == 'D')
    {
      tabTone[i] = 13;
    }else if (SeqString[i] == 'R')
    {
      tabTone[i] = 14;
    }
  }
  for (int i = 0; i < 5; ++i)
  {
    _sequence[i] = tabTone[i];
  }
}

int Fivetone::getSequence(){ //Retourne la sequence sous forme de integer. Pour des raisons de developpement seulement, pas d'utilité dans le programme 5 tons.
  String s0, s1, s2, s3, s4, s5;
  int j;
  s1 = String(_sequence[0]);
  s2 = String(_sequence[1]);
  s3 = String(_sequence[2]);
  s4 = String(_sequence[3]);
  s5 = String(_sequence[4]);
  s0 = s1+s2+s3+s4+s5;
  j = s0.toInt();
  return j;
}

void Fivetone::dispCCIR(){ //Affiche le contrenu du tableau CCIR, pour des raisons de developpement seulement, pas d'utilité dans le programme 5 tons.
  for (int i = 0; i < 16; ++i)
  {
    Serial.println(_ccir[i]);
  }
}

int Fivetone::getProtocol(){ //Retourne l'id du protocole 5 tons (1 : CCIR / 2 : ZVEI1 / 3 : ZVEI2 / 4 : ZVEI3 / 5:EEA)
  return _protocol;
}

void Fivetone::send5tone(){ //Joue les 5 tons en fonction de la sequence selectionnée et du protocole 5 tons choisi.
  Serial.println(_ccir[15]);
  if (_protocol == 1)
  {
    for (int i = 0; i < 5; ++i)
    {
      if (_sequence[i] == 0)
      {
        tone(_pin, _ccir[0], _ccir[15]);
        noTone(_pin);
        delay(_ccir[15]);
      }
      else if (_sequence[i] == 1)
      {
        tone(_pin, _ccir[1],_ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 2)
      {
        tone(_pin, _ccir[2],_ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 3)
      {
        tone(_pin, _ccir[3],_ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 4)
      {
        tone(_pin, _ccir[4],_ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 5)
      {
        tone(_pin, _ccir[5],_ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 6)
      {
        tone(_pin, _ccir[6], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 7)
      {
        tone(_pin, _ccir[7], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 8)
      {
        tone(_pin, _ccir[8], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 9)
      {
        tone(_pin, _ccir[9], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 10)
      {
        tone(_pin, _ccir[10], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 11)
      {
        tone(_pin, _ccir[11], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 12)
      {
        tone(_pin, _ccir[12], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 13)
      {
        tone(_pin, _ccir[13], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 14)
      {
        tone(_pin, _ccir[14], _ccir[15]);
        delay(_ccir[15]);
        noTone(_pin);
      }
      else{
        EXIT_FAILURE;
      }
    }
  }
  else if (_protocol == 2)
  {
    for (int i = 0; i < 5; ++i)
    {
      if (_sequence[i] == 0)
      {
        tone(_pin, _zvei1[0], _zvei1[15]);
        noTone(_pin);
        delay(_zvei1[15]);
      }
      else if (_sequence[i] == 1)
      {
        tone(_pin, _zvei1[1],_zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 2)
      {
        tone(_pin, _zvei1[2],_zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 3)
      {
        tone(_pin, _zvei1[3],_zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 4)
      {
        tone(_pin, _zvei1[4],_zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 5)
      {
        tone(_pin, _zvei1[5],_zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 6)
      {
        tone(_pin, _zvei1[6], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 7)
      {
        tone(_pin, _zvei1[7], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 8)
      {
        tone(_pin, _zvei1[8], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 9)
      {
        tone(_pin, _zvei1[9], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 10)
      {
        tone(_pin, _zvei1[10], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 11)
      {
        tone(_pin, _zvei1[11], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 12)
      {
        tone(_pin, _zvei1[12], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 13)
      {
        tone(_pin, _zvei1[13], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 14)
      {
        tone(_pin, _zvei1[14], _zvei1[15]);
        delay(_zvei1[15]);
        noTone(_pin);
      }
      else{
        EXIT_FAILURE;
      }
    }
  }
  else if (_protocol == 3)
  {
    for (int i = 0; i < 5; ++i)
    {
      if (_sequence[i] == 0)
      {
        tone(_pin, _zvei2[0], _zvei2[15]);
        noTone(_pin);
        delay(_zvei2[15]);
      }
      else if (_sequence[i] == 1)
      {
        tone(_pin, _zvei2[1],_zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 2)
      {
        tone(_pin, _zvei2[2],_zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 3)
      {
        tone(_pin, _zvei2[3],_zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 4)
      {
        tone(_pin, _zvei2[4],_zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 5)
      {
        tone(_pin, _zvei2[5],_zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 6)
      {
        tone(_pin, _zvei2[6], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 7)
      {
        tone(_pin, _zvei2[7], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 8)
      {
        tone(_pin, _zvei2[8], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 9)
      {
        tone(_pin, _zvei2[9], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 10)
      {
        tone(_pin, _zvei2[10], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 11)
      {
        tone(_pin, _zvei2[11], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 12)
      {
        tone(_pin, _zvei2[12], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 13)
      {
        tone(_pin, _zvei2[13], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 14)
      {
        tone(_pin, _zvei2[14], _zvei2[15]);
        delay(_zvei2[15]);
        noTone(_pin);
      }
      else{
        EXIT_FAILURE;
      }
    }
  }
  else if (_protocol == 4)
  {
    for (int i = 0; i < 5; ++i)
    {
      if (_sequence[i] == 0)
      {
        tone(_pin, _zvei3[0], _zvei3[15]);
        noTone(_pin);
        delay(_zvei3[15]);
      }
      else if (_sequence[i] == 1)
      {
        tone(_pin, _zvei3[1],_zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 2)
      {
        tone(_pin, _zvei3[2],_zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 3)
      {
        tone(_pin, _zvei3[3],_zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 4)
      {
        tone(_pin, _zvei3[4],_zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 5)
      {
        tone(_pin, _zvei3[5],_zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 6)
      {
        tone(_pin, _zvei3[6], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 7)
      {
        tone(_pin, _zvei3[7], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 8)
      {
        tone(_pin, _zvei3[8], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 9)
      {
        tone(_pin, _zvei3[9], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 10)
      {
        tone(_pin, _zvei3[10], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 11)
      {
        tone(_pin, _zvei3[11], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 12)
      {
        tone(_pin, _zvei3[12], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 13)
      {
        tone(_pin, _zvei3[13], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 14)
      {
        tone(_pin, _zvei3[14], _zvei3[15]);
        delay(_zvei3[15]);
        noTone(_pin);
      }
      else{
        EXIT_FAILURE;
      }
    }
  }
  else if (_protocol == 5)
  {
    for (int i = 0; i < 5; ++i)
    {
      if (_sequence[i] == 0)
      {
        tone(_pin, _eea[0], _eea[15]);
        noTone(_pin);
        delay(_eea[15]);
      }
      else if (_sequence[i] == 1)
      {
        tone(_pin, _eea[1],_eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 2)
      {
        tone(_pin, _eea[2],_eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 3)
      {
        tone(_pin, _eea[3],_eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 4)
      {
        tone(_pin, _eea[4],_eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 5)
      {
        tone(_pin, _eea[5],_eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 6)
      {
        tone(_pin, _eea[6], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 7)
      {
        tone(_pin, _eea[7], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 8)
      {
        tone(_pin, _eea[8], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 9)
      {
        tone(_pin, _eea[9], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 10)
      {
        tone(_pin, _eea[10], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 11)
      {
        tone(_pin, _eea[11], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 12)
      {
        tone(_pin, _eea[12], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 13)
      {
        tone(_pin, _eea[13], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else if (_sequence[i] == 14)
      {
        tone(_pin, _eea[14], _eea[15]);
        delay(_eea[15]);
        noTone(_pin);
      }
      else{
        EXIT_FAILURE;
      }
    }
  }
}