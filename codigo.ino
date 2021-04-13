int valvula = 0;
int bomba = 1;
int n1 = 2;
int n2 = 3;
int n3 = 4;
const int buttonN1 = 5;   
const int buttonN2 = 6;
const int buttonN3 = 7;
int buttonStateN1 = 0;
int buttonStateN2 = 0;
int buttonStateN3 = 0;
int i = 0;

int nivel = 0;

void setup()
{
  pinMode(buttonN1, INPUT);    
  pinMode(buttonN2, INPUT);    
  pinMode(buttonN3, INPUT);    

  pinMode(valvula, OUTPUT);
  pinMode(bomba, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
}

void loop()
{
  buttonStateN1 = digitalRead(buttonN1);
  buttonStateN2 = digitalRead(buttonN2);
  buttonStateN3 = digitalRead(buttonN3);
	if(buttonStateN3 == HIGH)
      encherN3();
  	else if(buttonStateN2 == HIGH)
      encherN2();
  	else if(buttonStateN1 == HIGH)
      encherN1();
}

void encherN3()
{
  	bombaEstado(0);
  	valvulaEstado(1);
  	digitalWrite(n1, LOW);
  	digitalWrite(n2, LOW);
  	digitalWrite(n3, HIGH);
  	i = 0;
}
void encherN2()
{
  if (i == 1){
  	bombaEstado(1);
  	valvulaEstado(0);
	digitalWrite(n1, LOW);
  	digitalWrite(n2, HIGH);
  	digitalWrite(n3, HIGH);
  }
  else{
  	bombaEstado(0);
  	valvulaEstado(1);
	digitalWrite(n1, LOW);
  	digitalWrite(n2, HIGH);
  	digitalWrite(n3, HIGH);}
}
void encherN1()
{
  	bombaEstado(1);
  	valvulaEstado(0);
	digitalWrite(n1, HIGH);
  	digitalWrite(n2, HIGH);
  	digitalWrite(n3, HIGH);
  	i = 1;
}


int bombaEstado(int estado)
{
	if(estado == 0)
      digitalWrite(bomba, LOW);
  	else
      digitalWrite(bomba, HIGH);
}
int valvulaEstado(int estado)
{
	if(estado == 0)
      digitalWrite(valvula, LOW);
  	else
      digitalWrite(valvula, HIGH);
}
