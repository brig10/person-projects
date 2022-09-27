void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

}

void loop() {
  start();
}

void start(){
  // put your main code here, to run repeatedly:
  delay(1000);
  int simon[50];
  for (int i = 0; i < 50; i++){
    simon[i] = -1;
  }
  int idx = 0;
  int del = 1000;

  digitalWrite(0, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);

  while(1){
    delay(1000);
    simon[50] = newSimon(simon, idx, del);
    int i = 0;
    while (i <= idx){
      if (digitalRead(2) == HIGH){
        playerGuess(0, i, simon);
        i++;
      }
      if (digitalRead(3) == HIGH){
        playerGuess(1, i, simon);
        i++;
      }
    }
    del = 0.85*del;
    idx++;
  }
 }

int newSimon(int simon[], int idx, int del){
  if (idx >= 50){
    digitalWrite(0, HIGH);
    delay(1000);
    digitalWrite(1, HIGH);
    delay(1000);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(900);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    delay(800);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(700);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    delay(600);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(500);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    delay(400);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(300);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(100);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    delay(3000);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(1000);
    start();
  }
  randomSeed(millis());
  int n = random(10);
  if (n >= 5){
    simon[idx] = 0;
  }
  if (n < 5){
    simon[idx] = 1;
    }
  for (int i = 0; i < 50; i++){
    if (simon[i] == 0){
      delay(del);
      digitalWrite(0, HIGH);
      delay(del);
      digitalWrite(0, LOW);
    }

    if (simon[i] == 1){
      delay(del);
      digitalWrite(1, HIGH);
      delay(del);
      digitalWrite(1, LOW);
    }
  }
  return simon;
}

void playerGuess(int guess, int i, int simon[]){
  if (guess == 0){
    while (digitalRead(2) == HIGH) digitalWrite(0, HIGH);
    digitalWrite(0, LOW);
  }
  if (guess == 1){
    while (digitalRead(3) == HIGH) digitalWrite(1, HIGH);
    digitalWrite(1, LOW);
  }
 
  if (guess != simon[i]){
    for (int i = 0; i < 10; i++){
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      delay(200);
      digitalWrite(0, LOW);
      digitalWrite(1, LOW);
      delay(200);
    }
    start();
  }
}
