
// Definición de pines del driver de motor H-Bridge para Motor 1
int motorPin1 = 2;    // Pin de control 1 del motor
int motorPin2 = 3;    // Pin de control 2 del motor
int enablePin = 9;    // Pin de habilitación del motor (PWM)

// Definición de pines del driver de motor H-Bridge para Motor 2
int motorPin3 = 4;    // Pin de control 1 del Motor 2
int motorPin4 = 5;    // Pin de control 2 del Motor 2

// Variable para almacenar el valor de señal del receptor (simulación)
int valorSenalReceptor = 0;

int señal_Mando = A5;
int angulo = 10;

void setup() {
  // Configurar los pines del driver de motor H-Bridge como salidas
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Inicializar el puerto serial para depuración
  Serial.begin(9600);  // Velocidad de comunicación serial

  // Mensaje inicial
  Serial.println("Control de motor DC con Arduino y receptor de señal.");
}

void loop() {
  // Leer valor de señal simulada del receptor (simulado con valor aleatorio entre 0 y 1023)
  valorSenalReceptor = analogRead(A0);  // Leer señal del pin analógico A0 (simulación)

  // Ajustar la señal del receptor para detener los motores entre 505 y 520
  if (valorSenalReceptor >= 505 && valorSenalReceptor <= 520) {
    analogWrite(enablePin, 0); // Detener el motor al escribir 0 en el pin de habilitación
  } else {
    // Mapear el valor de la señal del receptor al rango de velocidad (0 - 255)
    int velocidadMotor = map(valorSenalReceptor, 0, 1023, 0, 255);

    // Resetear los valores de velocidad a partir de 520
    if (valorSenalReceptor > 520) {
      velocidadMotor = map(valorSenalReceptor, 520, 1023, 0, 255); // 520 a 1023 mapeados a 0 a 255
    } else if (valorSenalReceptor < 505) {
      velocidadMotor = map(valorSenalReceptor, 0, 505, 255, 0);   // 0 a 505 mapeados a 255 a 0
    }

    // Determinar la dirección del motor según el valor de la señal del receptor
    boolean direccionAdelante = (valorSenalReceptor >= 512); // Adelante si la señal es mayor o igual a 512

    // Controlar la dirección del motor
    if (direccionAdelante) {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
    } else {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
    }

     // Controlar la dirección del motor
    if (direccionAdelante) {
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
    } else {
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
    }
    
    // Controlar la velocidad del motor mediante PWM en el pin de habilitación (enablePin)
    analogWrite(enablePin, 150);

    // Mostrar información en el puerto serial (para depuración)
    Serial.print("Valor de señal del receptor: ");
    Serial.println(valorSenalReceptor);
    Serial.print("Dirección del motor: ");
    Serial.println(direccionAdelante ? "Adelante" : "Reversa");
    Serial.print("Velocidad del motor: ");
    Serial.println(velocidadMotor);
  }

  // Esperar un breve tiempo antes de la próxima lectura
  delay(100);  // Ajustar según la velocidad de respuesta deseada
}

