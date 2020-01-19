/*
  Creado: Luis del Valle (ldelvalleh@programarfacil.com)
  https://programarfacil.com
*/

// Constantes para definir los pines
// Tener en cuenta que los pines fisicos no se corresponden con los digitales y cambian segun el modelo del arduino
// P. Ej. Nano = I/O digital 4 = patafísica 7
const int pulsIzq = 6; //Pulsador fisico 1 (izq a der)
const int pulsDer = 5; //Pulsador fisico 2 
const int ledIzq = 12; //Direccion izquireda
const int ledDer = 11; //Direccion izquireda

int valorPulsador = 0;

void setup() {
    // Activamos los pines de entrada y salida
    pinMode(pulsIzq, INPUT_PULLUP); //Define D4
    pinMode(pulsDer, INPUT_PULLUP); //Define D4
    pinMode(ledIzq, OUTPUT);
    pinMode(ledDer, OUTPUT);
}

void loop() {
    // Leemos el valor de uno de los
    valorPulsador = digitalRead(pulsIzq);
 
  // Encendemos o apagamos el pin del LED según convenga
  if (valorPulsador == HIGH) {
      digitalWrite(ledIzq, LOW);
  }
  else {
      digitalWrite(ledIzq, HIGH);
  }
  // Encendemos o apagamos el pin del LED según convenga
  if (digitalRead(pulsDer) == HIGH) {
      digitalWrite(ledDer, LOW);
  }
  else {
      digitalWrite(ledDer, HIGH);
  }
}