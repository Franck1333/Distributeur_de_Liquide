//This example has to be used with any SSD1306 screen Vertical/Horizontal screen with ~1" spec.
//This example use the Adafruits libs.
//AIDE: http://adafruit.github.io/Adafruit_SSD1306/html/index.html
//AIDE: https://projetsdiy.fr/ssd1306-mini-ecran-oled-i2c-128x64-arduino/
//AIDE: https://www.makerguides.com/max7219-led-dot-matrix-display-arduino-tutorial/
//AIDE {Sprite Generator}: https://gurgleapps.com/tools/matrix
//AIDE {Sprite Generator}: https://amperka.github.io/led-matrix-editor/

//------------------------------------------------SCREEN------------------------------------------------
//---DECLARATION_SCREEN---
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET  4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//---DECLARATION_SCREEN---
//------------------------------------------------SCREEN-------------------------------------------------

//------------------------------------------------LED_Avant-------------------------------------------------
const int GroupeLED1 = 5; //Composition LED: 1 et 3.
const int GroupeLED2 = 6; //Composition LED: 2 et 4.

int luminosite = 0;       //Luminositee des LEDs.
int degraderNB = 5;       //Nombre de degrader des LEDs.
//------------------------------------------------LED_Avant-------------------------------------------------

/*
//------------------------------------------------MATRICE------------------------------------------------
//-----DECLARATION_MATRICE-----
//  Include the required Arduino libraries:
//  Declaration des libs necessaires
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
//-----DECLARATION_MATRICE-----

//-----CONFIGURATION_MATRICE-----
//  Define hardware type, size, and output pins:
//  Declaration des infos de la matrice (Type,taille,Pins)
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN 11
//  Setup for software SPI:
//  Declaration specifique au protocole SPI
#define DATA_PIN 10
#define CLK_PIN 12
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
//-----CONFIGURATION_MATRICE-----

//---DESSIN_MATRICE---
//Bitmap
const uint8_t F_Boisson = 5;                            // F mean Frame, number of Frame
const uint8_t W_Boisson = 8;                            // W mean Width, number of data 
const uint8_t PROGMEM Boisson[F_Boisson * W_Boisson] =  // Ma Boisson
{
  0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff,
  0x81, 0x81, 0x81, 0x81, 0x81, 0xbd, 0x81, 0xff,
  0x81, 0x81, 0x81, 0xbd, 0x81, 0xbd, 0x81, 0xff,
  0x81, 0xbd, 0x81, 0xbd, 0x81, 0xbd, 0x81, 0xff,
  0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd, 0xff
};
//---DESSIN_MATRICE---
//------------------------------------------------MATRICE------------------------------------------------
*/

//-------------FONCTION_PRINCIPALE-------------
const int RELAY = 3;   //Pin Signale du Relay
const int BOUTON = 4;  //Pin Signale du Bouton de commande
const int BOUTON2 = 2; //Pin Signale du Bouton de commande secondaire
//-------------FONCTION_PRINCIPALE-------------

void setup() {
  Serial.begin(9600);
  //------------------------------------------------SCREEN------------------------------------------------
  //---INIT_SCREEN---
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  // Clear the buffer
  display.clearDisplay();
  delay(2048);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
  //---INIT_SCREEN---
  //------------------------------------------------SCREEN------------------------------------------------

  /*
  //------------------------------------------------MATRICE------------------------------------------------
  myDisplay.begin();                        //  Initialisation de l'objet "MD_Parola" 
  myDisplay.setIntensity(0);                //  Indication de l'intensité des LEDs (0-15)
  myDisplay.displayClear();                 //  Nettoyage de l'ecran
  
  //Affichage_Matrice_Texte_Scrolling();    //  Lancement d'un texte qui défile
  //Affichage_Sprite();                     //  Lancement d'un dessin animé
  //------------------------------------------------MATRICE------------------------------------------------
  */

  //------------------------------------------------LED_Avant-------------------------------------------------
  pinMode(GroupeLED1, OUTPUT);              //Initialisation du Groupement de LEDs 1
  pinMode(GroupeLED2, OUTPUT);              //Initialisation du Groupement de LEDs 2
  //------------------------------------------------LED_Avant-------------------------------------------------
  
  //---INIT_PIN---
  pinMode(RELAY,OUTPUT);                   //Initialisation du Pin Signale du Relay
  pinMode(BOUTON,OUTPUT);                   //Initialisation du Pin Signale du Bouton de commande
  pinMode(BOUTON2,INPUT);                 //Initialisation du Pin Signale du Bouton de commande secondaire
  //---INIT_PIN---
  
  //HelloWorld();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Outil_Refresh_Annimation();   //  Outil permettant l'actualisation des dessins lancé (MATRICE)
  Tirage();                     //  Fonction principal.
  Tirage_Prolonge(6000);        //  Fonction de Tirage programmable.
}

void HelloWorld(void){
  display.clearDisplay();           //Nettoyage du 'buffer' de l'ecran
  Serial.println("HelloWorld!!!");  //Message visible dans la console
  
  display.setTextColor(WHITE);      // La couleur du texte
  display.setCursor(0,0);           // On va ecrire en x=0, y=0
  display.print("Hello,");          // Un print pour écrire du texte sur l'ecran
  display.println(" world!");       // Un println pour écrire du texte sur l'ecran
  display.display();                // Affichage du Resultat
  }

void Tirage(void){
  bool BOUTON_ETAT = digitalRead(BOUTON);                           //Enregistrement de la Valeur detectee au Pin Signale du Bouton de commande
  Serial.print("Etat Bouton #1: ");
  Serial.println(BOUTON_ETAT);  
  
  if(BOUTON_ETAT == true)                                           //Si le bouton n'est pas actionner alors...
    {
      display.clearDisplay();                                       //Nettoyage du 'buffer' de l'ecran
      Serial.println("Bouton Non Actionner donc Relay OUVERT,");    //Message dans la console serie
      Serial.println("Aucun flux eletrique ne passe.");             //Message dans la console serie
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,0);                        // On va ecrire en x=0, y=0
      display.print("En Attente...");                // Un println pour écrire du texte sur l'ecran
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,10);                       // On va ecrire en x=0, y=10
      display.print("Distrib Dispo...");             // Un println pour écrire du texte sur l'ecran
  
      //Volume de liquide deplacer par la pompe
      //D'apres la doc (https://tinyurl.com/GikfunMiniPompeaAIR), la pompe deplace 1,5 Litre/Minutes
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,20);                       // On va ecrire en x=0, y=20
      display.print("Volume 1,5L/Min");              // Un println pour écrire du texte sur l'ecran
      
      digitalWrite(RELAY,LOW);                       //...Alors le RELAY sera DESACTIVER.
      display.display();                             // Affichage du Resultat
      LED_Respiration();
      delay(250);    
    }
 
  else if (BOUTON_ETAT == false)                                  //Si le bouton est actionner alors... 
    {
      display.clearDisplay();                                     //Nettoyage du 'buffer' de l'ecran
      Serial.println("Bouton Actionner donc Relay FERMER,");      //Message a lire dans la console serie
      Serial.println("Un flux eletrique passe.");                 //Message a lire dans la console serie
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,0);                        // On va ecrire en x=0, y=0
      display.print("En Service...");                // Un println pour écrire du texte sur l'ecran
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,13);                       // On va ecrire en x=0, y=0
      display.print("SVP Patientez...");             // Un println pour écrire du texte sur l'ecran
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,24);                       // On va ecrire en x=0, y=0
      display.print(BOUTON_ETAT);                    // Un println pour écrire du texte sur l'ecran
      
      digitalWrite(RELAY,HIGH);                      //...Alors le RELAY sera ACTIVER.
      display.display();                             // Affichage du Resultat
      LED_bargraph(250);
      delay(250);    
    }
  }

void Tirage_Prolonge(int duree){
  bool BOUTON2_ETAT = digitalRead(BOUTON2);                         //Enregistrement de la Valeur detectee au Pin Signale du Bouton de commande secondaire
  Serial.print("Etat Bouton #2: ");
  Serial.println(BOUTON2_ETAT);  
  
  if(BOUTON2_ETAT == true)                                           //Si le bouton2 est actionner alors...
    {
      display.clearDisplay();                                     //Nettoyage du 'buffer' de l'ecran
      Serial.println("Bouton2 Actionner donc Relay FERMER,");      //Message a lire dans la console serie
      Serial.println("Un flux eletrique passe.");                 //Message a lire dans la console serie
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,0);                        // On va ecrire en x=0, y=0
      display.print("En Service...");                // Un println pour écrire du texte sur l'ecran
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,13);                       // On va ecrire en x=0, y=0
      display.print("SVP Patientez...");             // Un println pour écrire du texte sur l'ecran
  
      display.setTextColor(WHITE);                   // La couleur du texte
      display.setCursor(0,24);                       // On va ecrire en x=0, y=0
      display.print(BOUTON2_ETAT);                    // Un println pour écrire du texte sur l'ecran
      
      digitalWrite(RELAY,HIGH);                      //...Alors le RELAY sera ACTIVER.
      display.display();                            //Affichage du Resultat
      LED_bargraph(512);                             //Jeu de lumière
      
      delay(duree);                                  //Tirage déja programmer pendant 6 secondes.  
    }
  }

/*
//------------------------------------------------MATRICE------------------------------------------------
void Affichage_Sprite(void){
  //Fonction permettant l'affichage d'un dessin animé
  myDisplay.displayClear();                                                                     //  Methode permettant de nettoyer l'ecran
  myDisplay.setSpriteData(Boisson, W_Boisson, F_Boisson, Boisson, W_Boisson, F_Boisson);        //  Methode permettant de selectionner le dessin a afficher et saisir ses specs // setSpriteData(inData, inWidth, inFrames, outData, outWidth, outFrames)
  myDisplay.displayText("", PA_CENTER, 450, 1000,PA_SPRITE, PA_NO_EFFECT);                      //  Methode permettant l'affichage du dessin animé //https://majicdesigns.github.io/MD_Parola/class_m_d___parola.html#a53b4c922a283ce2304a91e970e56c45d
  //myDisplay.displayText("U", PA_CENTER, 50, 1000,PA_SPRITE, PA_SCROLL_UP);                    //  Methode permettant l'affichage du dessin animé //https://majicdesigns.github.io/MD_Parola/class_m_d___parola.html#a53b4c922a283ce2304a91e970e56c45d
  }

void Outil_Refresh_Annimation(void){
  //Pour les animations (Scrollin,Sprite,etc...):
  //On verfie qu'une animation est lancée et une fois que c'est terminer on lance un RESET de l'ecran.
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
    } 
  }
//------------------------------------------------MATRICE------------------------------------------------
*/

void LED_Respiration(void){
  //Effet Respiration sur les LEDs
  //Aide: https://www.arduino.cc/en/tutorial/fade
  
  analogWrite(GroupeLED1, luminosite);
  analogWrite(GroupeLED2, luminosite);
  
  // change the brightness for next time through the loop:
  luminosite = luminosite + degraderNB;
  // reverse the direction of the fading at the ends of the fade:
  if (luminosite <= 0 || luminosite >= 164) {
    degraderNB = -degraderNB;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(32); 
  }

void LED_toutes(int duree){
  //Fonction permettant d'allumer/eteindre les LEDS saisies.

  digitalWrite(GroupeLED1, HIGH);//GroupeLED1 ON
  digitalWrite(GroupeLED2, HIGH);//GroupeLED2 ON

  delay(duree);
  
  digitalWrite(GroupeLED1, LOW); //GroupeLED1 OFF
  digitalWrite(GroupeLED2, LOW); //GroupeLED2 OFF
  }

void LED_bargraph(int choix){
  //Fonction permettant d'utiliser les LEDs d'une facon differente.

  digitalWrite(GroupeLED1, HIGH);//GroupeLED1 ON
  delay(choix);
  digitalWrite(GroupeLED2, HIGH);//GroupeLED2 ON
  delay(choix);
  digitalWrite(GroupeLED1, LOW); //GroupeLED1 OFF
  delay(choix);
  digitalWrite(GroupeLED2, LOW); //GroupeLED2 OFF
  delay(choix);  
  }
