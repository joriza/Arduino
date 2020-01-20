//Al presionar un pulsador endender un led por tiempo determinado


#define ON HIGH                 // Cambiar para logica positiva/negativa
#define OF LOW                  // Cambiar para logica positiva/negativa
byte Pinentrada=10;
byte Pinled=7;
unsigned long T_Control=0;      // Para controlar el tiempo consumido
unsigned long T_Apagar=3000;    // Tiempo de funcionamiento
bool EstadoPin=false;           
bool AnteriorEstadoPin=false;
void setup()
{
  pinMode(Pinled, OUTPUT);     
  pinMode(Pinentrada, INPUT);
  digitalWrite (Pinled, OF);
}
void loop()
{
  EstadoPin=digitalRead(Pinentrada);    // Leer pin
  if (AnteriorEstadoPin != EstadoPin)   // Estado ha variado?
  {
    T_Control=millis()+T_Apagar;        // Valor de millis para apagar
    digitalWrite (Pinled, ON);          // Encender         
  }
  AnteriorEstadoPin=EstadoPin;
  if (millis()>T_Control && T_Control>0)// Finalozo el tiempo y lo estamos controlando?
  {
    digitalWrite (Pinled, OF);          // Apagar
    T_Control=0;                        // Dejamos de controlar
  }
}


