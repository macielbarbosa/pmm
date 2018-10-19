#define BOTAO A0
#define IN_1 7
#define IN_2 2
#define POTENCIOMETRO A1
#define ENABLE 3

int estado;
bool direcao = true;
int intensidade;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(POTENCIOMETRO, INPUT);
  pinMode(ENABLE, INPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  estado = 1;
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
}

void loop() {
  intensidade = map(analogRead(POTENCIOMETRO), 0, 1023, 0, 255);
  analogWrite(ENABLE, intensidade);
  // estado 1
  if (estado == 1 && !digitalRead(BOTAO)) {
    digitalWrite(IN_1, direcao ? HIGH : LOW);
    digitalWrite(IN_2, direcao ? LOW : HIGH);
    direcao = !direcao;
    estado = 2;
    delay(50);
  }

  // estado 2
  if (estado == 2 && digitalRead(BOTAO)) {
    estado = 1;
    delay(50);
  }

  // estado 3
  if (estado == 3 && !digitalRead(BOTAO)) {
    estado = 4;
    delay(50);
  }

  // estado 4
  if (estado == 4 && digitalRead(BOTAO)) {
    estado = 1;
    delay(50);
  }
}
