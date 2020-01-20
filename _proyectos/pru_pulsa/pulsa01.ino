#define ON HIGH                 // Cambiar para logica positiva/negativa
#define OF LOW                  // Cambiar para logica positiva/negativa

/*
Manejo de 6 pulsadores
para ejemplificar las acciones de un sillon odontologico
4 para los movimientos fisicos
1 para la Luz
1 para el agua
Falta corregir / agregar

Que solo funcione 1 cosa a la vez de las que consumen mucho
Tiempo de bacha y valor
Posicion cero, salida paciente


Los limites de carrera para seguridad
Efecto rebote en los botones
El agua carga por un tiempo determinado, que se pueda frenar.
que cuente las vueltas
  y las tome como limite de carrera
al menos 3 memorias para la posicion del sillon

*/


// Constantes para definir los pines
// Tener en cuenta que los pines fisicos no se corresponden con los digitales y cambian segun el modelo del arduino
// P. Ej. Nano = I/O digital 4 = patafísica 7
const int pulsIzq = 7; //Pulsador fisico 1 (izq a der)
const int pulsDer = 6; //Pulsador fisico 2 
const int pulsArr = 5; //Pulsador fisico
const int pulsAba = 4; //Pulsador fisico
const int pulsLuz = 3; //Pulsador fisico
const int pulsAgu = 2; //Pulsador fisico
const int ledIzq = A0; //Direccion izquireda
const int ledDer = A1; //Direccion derecha
const int ledArr = A2; //Direccion 
const int ledAba = A3; //Direccion 
const int ledLuz = A4; //Direccion 
const int ledAgu = A5; //Direccion 

int valorPulsador = 0;  //variable intermedia para verificar si se oprimio un pulsador
bool estado = false ; //Estado de la iluminacion

//Definiciones para el manejo del agua
unsigned long T_Control=0;      // Para controlar el tiempo consumido
unsigned long T_Apagar=3000;    // Tiempo de funcionamiento
bool EstadoPin=false;           
bool AnteriorEstadoPin=false;

void setup() {
  // Activamos los pines de entrada y salida
  pinMode(pulsIzq, INPUT_PULLUP); //Define D4
  pinMode(pulsDer, INPUT_PULLUP); 
  pinMode(pulsArr, INPUT_PULLUP); 
  pinMode(pulsAba, INPUT_PULLUP); 
  pinMode(pulsLuz, INPUT_PULLUP); 
  pinMode(pulsAgu, INPUT_PULLUP); 
  pinMode(ledIzq, OUTPUT);
  pinMode(ledDer, OUTPUT);
  pinMode(ledArr, OUTPUT);
  pinMode(ledAba, OUTPUT);
  pinMode(ledLuz, OUTPUT);
  pinMode(ledAgu, OUTPUT);
  // incializamos estados
  digitalWrite(ledLuz , LOW) ; // Apagamos Luz al comenzar
  digitalWrite(ledAgu , LOW) ; // Apagamos Agua al comenzar
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
  // Pulsador direccion derecha
  if (digitalRead(pulsDer) == HIGH) {
      digitalWrite(ledDer, LOW);
  }
  else {
      digitalWrite(ledDer, HIGH);
  }

  if (digitalRead(pulsArr) == HIGH) {
      digitalWrite(ledArr, LOW);
  }
  else {
      digitalWrite(ledArr, HIGH);
  }

  if (digitalRead(pulsAba) == HIGH) {
      digitalWrite(ledAba, LOW);
  }
  else {
      digitalWrite(ledAba, HIGH);
  }

  //Verifica estado de ledLuz
  bool  valor =  digitalRead(pulsLuz) ;                 //leemos el botón: false  =  LOW
  if ( valor == false )                               // esto es que han pulsado el botón
    {
      estado = ! estado ;                       // cambiamos el estado
      digitalWrite(ledLuz, estado) ;            // escribimos el nuevo valor
      delay(500) ; //Para suavizar el rebote
    }

  //Funcionamiento del cargador de agua
  EstadoPin=digitalRead(pulsAgu);    // Leer pin
  if (AnteriorEstadoPin != EstadoPin)   // Estado ha variado?
  {
    T_Control=millis()+T_Apagar;        // Valor de millis para apagar
    digitalWrite (ledAgu, ON);          // Encender         
  }
  AnteriorEstadoPin=EstadoPin;
  if (millis()>T_Control && T_Control>0)// Finalozo el tiempo y lo estamos controlando?
  {
    digitalWrite (ledAgu, OF);          // Apagar
    T_Control=0;                        // Dejamos de controlar
  }

}