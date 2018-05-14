#include <VirtualWire.h>

int receiver = 2;


// 3 5 6 9 10 11
int recPOT0 = 3;
int recPOT1 = 5;
int recPOT2 = 6;
int recPOT3 = 9;


int valMOTG;
int valMOTD;
int valMOTH;


int valLED;

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  
  
void setup() {
  Serial.begin(9600);
  
  vw_setup(4000); // Bits per sec
  vw_set_rx_pin(receiver);
  vw_set_ptt_inverted(true); // Required for DR3100

  
  vw_rx_start(); // Start the receiver PLL running
}

void loop() {
  /* THE LOOP */

  
  
  if (vw_get_message(buf, &buflen)) {
    // si on reçoit l'info
    
    Serial.print("message recu");
    
    //valLED1 = buf[0];
    //valLED2 = buf[1];
    
    valMOTG = buf[0];
    valMOTD = buf[1];
    valMOTH = buf[2];
    
    // jaune bleu vert blanc
    
   
    // gauche
    analogWrite(recPOT0, valMOTG);
    // droite
    analogWrite(recPOT1, valMOTD);
    // hauteur
    analogWrite(recPOT2, valMOTH);
  
  } else {
    // sinon 
    Serial.println("no signal");
    
    //digitalWrite(LED, 0);
  }
  /* FIN LOOP */
  
}
