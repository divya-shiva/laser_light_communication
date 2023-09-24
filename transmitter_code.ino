const int LaserPin = 4;  
void setup() {
  pinMode (LaserPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("");
  Serial.print("Waiting for message now:");Serial.println();
  while(Serial.available()==0){}
  String message = Serial.readString();
  Serial.print("Transmitting now:");Serial.println();
  int messageSize=message.length()-1;
  //Serial.println(message);
  //Serial.println(messageSize);
  char myText[messageSize];
  message.toCharArray(myText,messageSize+1);
  //Serial.println(myText);

  int length = sizeof(myText);
 int ar[length];
 int m;
 int bits[8];
 for (int i =0 ; i<length ; i++ ) {
  ar[i]= int(myText[i]);
 }
  for (int n =0 ; n<length ; n++ ){
  m=ar[n];
  int z;
  int bin[7];
  int newbin[7];
  for(z=0;z<8;z++){
    bin[z] = m%2;
    m = m /2 ; 
  }
  
  for (int j= 7 ; j>=0 ; j-- ){
    newbin[7-j] = bin[j] ;
  }
  for( int p=0 ; p<8 ; p++ ){
      if (newbin[p] == 1){
       bits[p] = 1 ;
      }
      if ( newbin[p] == 0){
       bits[p] = 0 ;
      }
  }

  bits[0] = 1;
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(LaserPin, bits[i]);
    Serial.print(bits[i]);
    delay(10);
  }

  digitalWrite(LaserPin, LOW);
  delay(100);
  }
}
