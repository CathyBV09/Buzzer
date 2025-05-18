 // LEDs de los segmentos A-G
int ledA = 12;  // seccion A
int ledB = 13;  // seccion B
int ledC = 10;  // seccion C
int ledD = 11;  // seccion D
int ledE = 9;   // seccion E
int ledF = 8;   // seccion F
int ledG = 7;   // seccion G
 
// Pines para los botones
int buttonA = 2;
int buttonB = 3;
int buttonC = 4;
int buttonD = 5;

// Estados de los botones
int EstadoA = 0;
int EstadoB = 0;
int EstadoC = 0;
int EstadoD = 0;

void setup() {
  // Botones como entradas
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonC, INPUT);
  pinMode(buttonD, INPUT);

  // LEDs de los segmentos como salidas
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  // Lectura de los estados de los botones
  EstadoA = digitalRead(buttonA);
  EstadoB = digitalRead(buttonB);
  EstadoC = digitalRead(buttonC);
  EstadoD = digitalRead(buttonD);

  // Determinar que numero mostra en los botones presionados
  int numero = determinarNumero(EstadoA, EstadoB, EstadoC, EstadoD);

  // Mostrar el numero usando los LEDs del display de 7 segmentos
  mostrarNumero(numero);
}

// Funcion para determinar el numero basado en la combinacion de los botones
int determinarNumero(int A, int B, int C, int D) {
  if (A == LOW && B == LOW && C == LOW && D == LOW) return 0; // Ningún botón presionado -> 0
  if (A == HIGH && B == LOW && C == LOW && D == LOW) return 1; // Solo A presionado -> 1
  if (A == LOW && B == HIGH && C == LOW && D == LOW) return 2; // Solo B presionado -> 2
  if (A == LOW && B == LOW && C == LOW && D == HIGH) return 3; // D presionados -> 3 debe ser D
  if (A == LOW && B == LOW && C == HIGH && D == LOW) return 4; // Solo C presionado -> 4 debe ser C
  if (A == HIGH && B == HIGH && C == LOW && D == LOW) return 5; // A y B presionados -> 5 debe ser A y B
  if (A == HIGH && B == LOW && C == LOW && D == HIGH) return 6; // A y D presionados -> 6 debe ser A y D
  if (A == HIGH && B == LOW && C == HIGH && D == LOW) return 7; // A y C presionados -> 7 debe ser A y C
  if (A == LOW && B == HIGH && C == LOW && D == HIGH) return 8; // B y D presionado -> 8 debe ser B y D
  if (A == LOW && B == HIGH && C == HIGH && D == LOW) return 9; // B y C presionados -> 9 debe ser B y C
  if (A == LOW && B == LOW && C == HIGH && D == HIGH) return 10;// C y D FALTA LOS LEDS
  if (A == HIGH && B == HIGH && C == LOW && D == HIGH) return 11;// A, B y D
  if (A == HIGH && B == HIGH && C == HIGH && D == LOW) return 12;// A, B y C
  if (A == HIGH && B == LOW && C == HIGH && D == HIGH) return 13;// A, C Y D
  if (A == LOW && B == HIGH && C == HIGH && D == HIGH) return 14;// B, C y D
  if (A == HIGH && B == HIGH && C == HIGH && D == HIGH) return 15;// A, B, C, D
  return -1; // Combinacion no valida
}

// Funcion para mostrar el numero en los LEDs
void mostrarNumero(int numero) {
  switch (numero) {
    case 0: // Mostrar 0
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      break;
    case 1: // Mostrar 1
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      break;
    case 2: // Mostrar 2
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      break;
    case 3: // Mostrar 3
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      break;
    case 4: // Mostrar 4
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
    case 5: // Mostrar 5
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
    case 6: // Mostrar 6
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
    case 7: // Mostrar 7
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      break;
    case 8: // Mostrar 8
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
    case 9: // Mostrar 9
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
      case 10: // Mostrar 10
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
      case 11: // Mostrar 10
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
      case 12: // Mostrar 10
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      break;
      case 13: // Mostrar 10
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      break;
      case 14: // Mostrar 10
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
      case 15: // Mostrar 10
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      break;
    default: // Apagar todo si la combinacion es invalida
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      break;
  }
}
