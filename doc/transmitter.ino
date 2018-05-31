//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>

// variables envoyées par LoRa
byte controller[6];

// position du transmitter
int transmit = 5;

int traPOT0 = 0;
int traPOT1 = 1;
int traPOT2 = 2;
int traPOT3 = 3;

int LED = 13;

int valPOT0; // camera ?
int valPOT1; // vitesse
int valPOT2; // hauteur
int valPOT3; // direction

double traVal0; // valeur affectée au moteur gauche
double traVal1; // valeur affectée au moteur droit
double traVal2; // valeur affectée au moteur hauteur


int valLED;

boolean sended;

void setup() {
  
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(transmit);
  vw_setup(4000);// speed of data transfer Kbps
  
  Serial.begin(9600);
}

void loop(){
 
   // jaune bleu vert blanc
   
  /* */
  valPOT0 = analogRead(traPOT0); // ?           jaune-->jaune
  valPOT1 = analogRead(traPOT1); // vitesse     bleu-->vert
  valPOT2 = analogRead(traPOT2); // hauteur     vert-->bleu
  valPOT3 = analogRead(traPOT3); // direction   blanc-->bordeau
  
  // TRAITEMENT DES DONN2ES
  
  traVal0 = (1023 + valPOT3 - valPOT1)/2;    // moteur gauche
  traVal1 = 1023 - (valPOT3 + valPOT1)/2;    // moteur droite
  traVal2 = 1023 - valPOT2;                  // moteur hauteur

  // ENVOI DES DONNéS
  
  controller[0] = convPOTtoRC(traVal0);    // gauche
  controller[1] = convPOTtoRC(traVal1);    // droite
  controller[2] = convPOTtoRC(traVal2);    // hauteur

  
  
  Serial.println( "0 : " + (String) controller[0]);
  Serial.println( "1 : " + (String) controller[1]);
  Serial.println( "2 : " + (String) controller[2]);
  Serial.println();
  
  // on envoie le tableau
  vw_send(controller, sizeof(controller));
  // on attend la fin de l'envoie
  vw_wait_tx();
}

/* */
int convPOTtoRC(int valPOT){
  long res = valPOT;
  res = res*255;
  res = res/1023;
  return (int) res;
}
// */
