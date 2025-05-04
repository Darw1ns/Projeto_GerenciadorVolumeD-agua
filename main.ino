// C++ code
//

#define trigPin 9  // Pino digital 9, usado para emitir o pulso de som so sensor Ultrassonico
#define echoPin 8  // Pino digital 8, usado para ler o tempo de retorno do pulso de som do sensor
#define motorPin 7 // Pino digital 7, usado para controlar o motor
long duracao;
int distancia;

// Função para configurar o sensor ultrassônico
void sensorSonico(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Emite um sinal alto por 10 microssegundos para mediar a distancia
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o tempo de retorno do sinal no pino Echopin
  duracao = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em centímetros
  distancia = duracao * 0.034 / 2;
  
  // Imprime a distancia no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(60000) // Aguarda 1 minuto antes da proxima medição
 }

// Função para ligar e desligar o motor dependendo da distância medida
void interruptorMotor(){
  // Verifica se a distancia é maior ou igual a 150 cm
  if (distancia >= 150){
    digitalWrite(motorPin, HIGH); // Liga o motor
  } else {
    digitalWrite(motorPin, LOW); // Desliga o motor
  }
}


void setup()
{
  // Configura os pinos como saída ou entrada
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorSonico(); // Chama a função para medir a distância
  interruptorMotor(); // Chama a função para controlar o motor
}