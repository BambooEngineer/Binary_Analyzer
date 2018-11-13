int LED = A1; // LEDs and Piezo Buzzer
int led = A0;
int Led = A2;
int buzzer = A5;

int tactile = 12; // Tactile Buttons
int Tactile = 11; 
int s1 = 2; // Switches
int s2 = 3;
int s3 = 4;
int s4 = 5;

int s = 0; // Sensor Values for Switches and Buttons
int ss = 0;
int sss = 0;
int ssss = 0;
int t = 0;
int tt = 0;

int l = 0; // LED values
int ll = 0;
int lll = 0;

int Demulti[3];  // 3 switches = 0 to 2          
boolean b = true; // On/Off switch for Demulti placeholders
int x = 0;

void setup() {
  pinMode(s1, INPUT_PULLUP); 
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP); 
  pinMode(s4, INPUT_PULLUP);
  pinMode(tactile, INPUT_PULLUP);
  pinMode(Tactile, INPUT_PULLUP);
  
  pinMode(buzzer, OUTPUT); // Buzzer and LEDs
  pinMode(led, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  s = digitalRead(s1); // Sensor Values for Switches and Tactiles
  ss = digitalRead(s2);
  sss = digitalRead(s3);
  ssss = digitalRead(s4);
  
  t = digitalRead(tactile);
  tt = digitalRead(Tactile);

  l = digitalRead(led); // LED values
  ll = digitalRead(Led);
  lll = digitalRead(LED);
  
  BinaryA(); // Binary Adder function
  BinaryC(); // Binary Counter function
  Serial.println(ssss);
  
 
}

void BinaryC(){
 
  if(tt == LOW && ssss == LOW){
    x = x + 1;
    delay(1000);
  if(x == 7){
    digitalWrite(Led,HIGH);
    digitalWrite(LED,HIGH);
    digitalWrite(led,HIGH);
    x = 0;
    delay(1000);
    }
  }
if(x == 0){
  digitalWrite(Led,LOW);
  digitalWrite(LED,LOW);
  digitalWrite(led,LOW);
}

if(x == 1){

  digitalWrite(Led,HIGH);
  digitalWrite(LED,LOW);
  digitalWrite(led,LOW);
}

if(x == 2){
    digitalWrite(Led,LOW);
  digitalWrite(LED,HIGH);
  digitalWrite(led,LOW);
}

if(x == 3){
    digitalWrite(Led,HIGH);
  digitalWrite(LED,HIGH);
  digitalWrite(led,LOW);
}

if(x == 4){
    digitalWrite(Led,LOW);
  digitalWrite(LED,LOW);
  digitalWrite(led,HIGH);
}

if(x == 5){
   digitalWrite(Led,HIGH);
  digitalWrite(LED,LOW);
  digitalWrite(led,HIGH);
}

if(x == 6){
    digitalWrite(Led,LOW);
  digitalWrite(LED,HIGH);
  digitalWrite(led,HIGH);
}

}



void BinaryA(){            

  if(b){ 
    Demulti[0] = 0; // Makes Demulti[0-2] Default 0 values
    Demulti[1] = 0;
    Demulti[2] = 0;
  }
  
  if(ssss == LOW){        // If Code Punch Switch is turned on and off
    b = false;            // Default value is removed
    Demulti[0] = s;       // New values are stored
    Demulti[1] = ss; 
    Demulti[2] = sss;
  }
  
  if(t == LOW && ssss == HIGH){     // If Code Check is punched while Code punch switch is off  


       if(Demulti[0] == 0 && Demulti[1] == 0){ // If this is the code
         if(Demulti[2] == 0){
          digitalWrite(led, LOW); // Power on these LEDs
          digitalWrite(LED, LOW);
          digitalWrite(Led, LOW);
          tone(buzzer,1); // Output this sound
          delay(5000);    // For this long
          noTone(buzzer); // Then shut it off for gods sake
          }
        }
      if(Demulti[0] == 0 && Demulti[1] == 0){ 
        if(Demulti[2] == 1){
          digitalWrite(led, LOW); 
          digitalWrite(LED, LOW);
          digitalWrite(Led, HIGH);
          tone(buzzer,1); 
          delay(5000);    
          noTone(buzzer); 
          }
        }

        if(Demulti[0] == 0 && Demulti[1] == 1){ 
         if(Demulti[2] == 0){
          digitalWrite(led, LOW); 
          digitalWrite(LED, HIGH);
          digitalWrite(Led, LOW);
          tone(buzzer,3); 
          delay(5000);    
          noTone(buzzer); 
          }
        }

        if(Demulti[0] == 0 && Demulti[1] == 1){ 
         if(Demulti[2] == 1){
          digitalWrite(led, LOW); 
          digitalWrite(LED, HIGH);
          digitalWrite(Led, HIGH);
          tone(buzzer,5); 
          delay(5000);    
          noTone(buzzer); 
          }
        }

        if(Demulti[0] == 1 && Demulti[1] == 0){ 
         if(Demulti[2] == 0){
          digitalWrite(led, HIGH); 
          digitalWrite(LED, LOW);
          digitalWrite(Led, LOW);
          tone(buzzer,7); 
          delay(5000);   
          noTone(buzzer); 
          }
        }

        if(Demulti[0] == 1 && Demulti[1] == 0){ 
         if(Demulti[2] == 1){
          digitalWrite(led, HIGH); 
          digitalWrite(LED, LOW);
          digitalWrite(Led, HIGH);
          tone(buzzer,9); 
          delay(5000);    
          noTone(buzzer);
          }
        }

        if(Demulti[0] == 1 && Demulti[1] == 1){ 
         if(Demulti[2] == 0){
          digitalWrite(led, HIGH); 
          digitalWrite(LED, HIGH);
          digitalWrite(Led, LOW);
          tone(buzzer,12); 
          delay(5000);    
          noTone(buzzer); 
          }
        }

        if(Demulti[0] == 1 && Demulti[1] == 1){ 
         if(Demulti[2] == 1){
          digitalWrite(led, HIGH); 
          digitalWrite(LED, HIGH);
          digitalWrite(Led, HIGH);
          tone(buzzer,15); 
          delay(5000);    
          noTone(buzzer); 
          }
        }
      }
    
    
  
        
}

