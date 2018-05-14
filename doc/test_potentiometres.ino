//les potentiomètres de la télécommande
double pot_camera; //l'avenir nous le dira
double pot_vitesse;
double pot_hauteur;
double pot_direction;

//les moteurs
double mot_gauche;
double mot_droit;
double mot_hauteur;

   
void setup() {
  Serial.begin(9600);
}

void loop() {
  pot_vitesse = analogRead(1);
  pot_hauteur = analogRead(2);
  pot_direction = analogRead(3);
  
  //conversion des valeurs prises par les potentiomètres en valeurs à affecter aux moteurs
  mot_gauche = (1023 + pot_direction - pot_vitesse)/2;
  mot_droit = 1023 - (pot_direction + pot_vitesse)/2;
  mot_hauteur = 1023 - pot_hauteur;
}
