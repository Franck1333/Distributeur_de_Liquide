// Code Arduino simple pour le contrôle d'une pompe avec trois boutons et une LED

#define PUMP_PIN 9            // Broche pour la pompe
//#define LED_PIN 13           // Broche pour la LED
#define LED_PIN LED_BUILTIN  // Broche pour la LED intégrée
#define BUTTON_HOLD_PIN 2    // Bouton pour activer la pompe en continu tant qu'il est maintenu
#define BUTTON_PIN 3         // Bouton pour activer la pompe en continu
#define BUTTON_BURST_PIN 4   // Bouton pour activer la pompe par saccades (4 jets)
#define BUTTON_RANDOM_PIN 5  // Bouton pour activer des jets aléatoires pendant 30 secondes


void setup() {
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_HOLD_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON_BURST_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RANDOM_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Contrôle simple de la pompe prêt"); }

void loop() {
  // Activation continue tant que le bouton est maintenu
  if (digitalRead(BUTTON_HOLD_PIN) == LOW) {
    Serial.println("Pompe activée en mode maintenu.");
    digitalWrite(PUMP_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    while (digitalRead(BUTTON_HOLD_PIN) == LOW); // Attente du relâchement du bouton
    digitalWrite(PUMP_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Pompe désactivée, en mode maintenu.");
    delay(300); // Anti-rebond
  }

  // Activation continue de la pompe
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Pompe activée en continu");
    digitalWrite(PUMP_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    delay(1000); // Pompe active pendant 1 seconde
    digitalWrite(PUMP_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Pompe désactivée");
    delay(300); // Anti-rebond
  }

  // Mode saccades (4 jets)
  if (digitalRead(BUTTON_BURST_PIN) == LOW) {
    Serial.println("Mode saccades activé");
    for (int i = 0; i < 4; i++) {
      digitalWrite(PUMP_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      delay(500); // Durée d'un jet
      digitalWrite(PUMP_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      delay(500); // Pause entre les jets
    }
    Serial.println("Mode saccades terminé");
    delay(300); // Anti-rebond
  }

  // Mode jets aléatoires pendant 30 secondes
  if (digitalRead(BUTTON_RANDOM_PIN) == LOW) {
    Serial.println("Mode jets aléatoires activé");
    unsigned long startTime = millis();
    while (millis() - startTime < 30000) {
      digitalWrite(PUMP_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      delay(random(200, 1000)); // Durée aléatoire du jet
      digitalWrite(PUMP_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      delay(random(200, 1000)); // Pause aléatoire entre les jets
    }
    Serial.println("Mode jets aléatoires terminé");
    delay(300); // Anti-rebond
  }
}
