void setup() {
  // Inicia a comunicação serial para monitorar no computador
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(7,OUTPUT);

}
bool pass = false;
void loop() {

  // Lê um valor analógico de um pino analógico
  float potValue = analogRead(A0);

  // Lê um valor digital de um pino digital
  bool valor_digital = digitalRead(2);
  
  if (valor_digital == 1 && pass == false){
    digitalWrite(7,LOW);
    pass = true;
    delay(250);
  }else
  if (valor_digital == 1 && pass == true){
    digitalWrite(7,HIGH);
    pass = false;
  }
  if (pass == false){
    digitalWrite(7,HIGH);

    // Envia os valores lidos e formatados pera a comunicação serial
  
    Serial.print((int)((potValue/1023)*100));
    Serial.print("/");
    Serial.println(valor_digital);

    delay(250); // Apenas para evitar a sobrecarga da comunicação serial
  }
}
