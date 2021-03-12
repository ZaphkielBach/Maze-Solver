#define soluzak 11
#define saguzak 10 
#define solyakin A2
#define sagyakin A1
#define onuzak  A0
//////////////////////////
#define BIN1 7 //sol motor
#define BIN2 4 
#define PWMB 6

#define AIN1 3 //sağ motor
#define AIN2 2  
#define PWMA 5

#define renksensor1 A6
#define renksensor2 A7

int yol[4][4];
int i,j,counter;
int m=1;
boolean renk = false;


void setup() {
Serial.begin(9600);   
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT) ;
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(saguzak, INPUT);
  pinMode(soluzak, INPUT);
  pinMode(onuzak, INPUT);
  pinMode(sagyakin, INPUT);
  pinMode(solyakin, INPUT);
 // pinMode(renksensor, INPUT);
  delay(4000);    
}
    
void loop(){
  if(onbos){
    ilerle();
  }
  else if(sagbos()){
    sagadon();
    ilerle();
  }
  else{
   soladon();
   ilerle();
  }
  /////Labirent////
  while(true){
 
   if(sagbos()){
     if(counter%4==0 && yol[i+1][j]==0){
          sagadon();
          ilerle();
     }
     else if(counter%4==1 && yol[i][j-1]==0){
          sagadon();
          ilerle();
     }
     else if(counter%4==2 && yol[i-1][j]==0){
          sagadon();
          ilerle();
     }
     else if(counter%4==3 && yol[i][j+1]==0){
          sagadon();
          ilerle();
     }
   }
   else if(solbos()){
     if(counter%4==0 && yol[i-1][j]==0){
          soladon();
          ilerle();
     }
     else if(counter%4==1 && yol[i][j+1]==0){
          soladon();
          ilerle();
     }
     else if(counter%4==2 && yol[i+1][j]==0){
          soladon();
          ilerle();
     }
     else if(counter%4==3 && yol[i][j-1]==0){
          soladon();
          ilerle();
     }
   }
   else if(onbos()){
       if(counter%4==0 && yol[i][j+1]==0){
            ilerle();
       }
       else if(counter%4==1 && yol[i+1][j]==0){
            ilerle();
       }
       else if(counter%4==2 && yol[i][j-1]==0){
            ilerle();
       }
       else if(counter%4==3 && yol[i-1][j]==0){
            ilerle();
       }
   }
   else if(sagbos()==false && solbos()==false && onbos()==false){
      sagadon();
      sagadon();
     while( yol[i-1][j]!=0 && yol[i][j-1]!=0 && yol[i+1][j]!=0 && yol[i][j+1]!=0 ){
        
        if(sagbos()){
           if(counter%4==0 && yol[i+1][j]>0){
               sagadon();
               silici();
            }
           else if(counter%4==1 && yol[i][j-1]>0){
              sagadon();
              silici();
           }
           else if(counter%4==2 && yol[i-1][j]>0){
             sagadon();
             silici();
           }
           else if(counter%4==3 && yol[i][j+1]>0){
             sagadon();
             silici();
           }
       }
      else if(solbos()){
        if(counter%4==0 && yol[i-1][j]>0){
            soladon();
            silici();
        }
        else if(counter%4==1 && yol[i][j+1]>0){
            soladon();
            silici();
       }
       else if(counter%4==2 && yol[i+1][j]>0){
           soladon();
           silici();
        }
        else if(counter%4==3 && yol[i][j-1]>0){
            soladon();
            silici();
       }
    }
    else if(onbos()){
        if(counter%4==0 && yol[i][j+1]>0){
              silici();
         }
         else if(counter%4==1 && yol[i+1][j]>0){
              silici();
         }
         else if(counter%4==2 && yol[i][j-1]>0){
              silici();
         }
         else if(counter%4==3 && yol[i-1][j]>0){
              silici();
         }
    } 
 }
     
   }
 }
 
 renk=false;
 turntostart();
 renk=false;
 turntostart();
} 


void sagadon(){
  motor(50,-50);
  counter++;
  delay(100);
}
void soladon(){
  motor(-50,50);
  counter--;
  delay(100); 
}
void ilerle(){
  motor(50,50);
  int saniye=0;
  while(saniye<1200){
    if (sagduvar()== false ) {
      motor(40, 55);
      delay(20);
      saniye += 20;
    }
    else if (solduvar()== false) {
      motor(55, 40);
      delay(20);
      saniye += 20;
    }
    else {
      motor(50, 50);
      delay(20);
      saniye += 20;
      if(onduvar==true){
        motor(0,0);
        saniye=1200;
      }
    }
    
  }
  motor(0,0);
  if(counter%4==0){
    yol[i][j]=m;
    m++;
    j++;
  }
  else if(counter%4==1){
    yol[i][j]=m;
    m++;
    i++;
  }
  else if(counter%4==2){
    yol[i][j]=m;
    m++;
    j--;
  }
  else if(counter%4==3){
    yol[i][j]=m;
    m++;
    i--;
  }
  delay(100);
}

void silici(){
  motor(50,50);
   int saniye=0;
  while(saniye<1200){
    if (sagduvar()== false ) {
      motor(40, 55);
      delay(20);
      saniye += 20;
    }
    else if (solduvar()== false) {
      motor(55, 40);
      delay(20);
      saniye += 20;
    }
    else {
      motor(50, 50);
      delay(20);
      saniye += 20;
    }
  }
  motor(0,0);
  if(counter%4==0){
    yol[i][j]=-1;
    j++;
  }
  else if(counter%4==1){
    yol[i][j]=-1;
    i++;
  }
  else if(counter%4==2){
    yol[i][j]=-1;
    j--;
  }
  else if(counter%4==3){
    yol[i][j]=-1;
    i--;
  }
  delay(100);
}

boolean sagbos(){
 return digitalRead(saguzak);

}
boolean solbos(){
 return digitalRead(soluzak);

}
boolean onbos(){
 if(analogRead(onuzak)>500){
   return true; 
 }
 else{
  return false;
 }
}

boolean sagduvar(){
  if( analogRead(sagyakin)>500){
    return true; 
  }
  else{ return false;
  }
}
boolean solduvar(){
   if( analogRead(solyakin)>500){
    return true; 
  }
   else{
    return false;
  }
}
boolean onduvar(){
 if(analogRead(onuzak)>500){
   return true; 
 }
 else{
   return false;
 } 
}
void Renk(){
  if(analogRead(renksensor1)>800 || analogRead(renksensor2)>800){
     renk=true;
  }
  else{
    renk=false;
  }
}
void donus(){
   motor(50,50);
   int saniye=0;
   while(saniye<1200){
    if (sagduvar()== false ) {
      motor(40, 55);
      delay(20);
      saniye += 20;
    }
    else if (solduvar()== false) {
      motor(55, 40);
      delay(20);
      saniye += 20;
    }
    else {
      motor(50, 50);
      delay(20);
      saniye += 20;
    }
  }
   motor(0,0);
  if(counter%4==0){
    j++;
  }
  else if(counter%4==1){
    i++;
  }
  else if(counter%4==2){
    j--;
  }
  else if(counter%4==3){
    i--;
  }
  delay(100);
}

void turntostart(){
  sagadon();
  sagadon();
  ilerle();
      while(renk==false){
        
        if(sagbos()){
           if(counter%4==0 && yol[i+1][j]>0){
               sagadon();
               donus();
            }
           else if(counter%4==1 && yol[i][j-1]>0){
              sagadon();
               donus();
           }
           else if(counter%4==2 && yol[i-1][j]>0){
             sagadon();
             donus();
           }
           else if(counter%4==3 && yol[i][j+1]>0){
             sagadon();
             donus();
           }
       }
      else if(solbos()){
        if(counter%4==0 && yol[i-1][j]>0){
            soladon();
             donus();
        }
        else if(counter%4==1 && yol[i][j+1]>0){
            soladon();
            donus();
       }
       else if(counter%4==2 && yol[i+1][j]>0){
           soladon();
           donus();
        }
        else if(counter%4==3 && yol[i][j-1]>0){
            soladon();
            donus();
       }
    }
    else if(onbos()){
        if(counter%4==0 && yol[i][j+1]>0){
              donus();
         }
         else if(counter%4==1 && yol[i+1][j]>0){
              donus();
         }
         else if(counter%4==2 && yol[i][j-1]>0){
              donus();
         }
         else if(counter%4==3 && yol[i-1][j]>0){
              donus();
         }
    } 
 }
}


////MOTOR//// 
void motor(int pwma, int pwmb) {
  if (pwma < 0) {
    pwma = abs(pwma);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, pwma);
  }
  else if (pwma == 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, 0);
  }
  else {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, pwma);
  }
  if (pwmb < 0) {
    pwmb = abs(pwmb);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, pwmb);
  }
  else if (pwmb == 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, 0);
  }
  else {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, pwmb);
  }
}
