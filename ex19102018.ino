#define BOTAO A0
#define IN_1 7
#define IN_2 8

int estado;
bool ligado = false;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  estado = 1;
  digitalWrite(IN_1, HIGH);
}

void loop() {
  // estado 1
  if (estado == 1 && !digitalRead(BOTAO)) {
    digitalWrite(IN_1, ligado ? HIGH : LOW);
    ligado = !ligado;
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
