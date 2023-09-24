#define solar_pin A0
#define threshold 440

void setup() {
  pinMode(solar_pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  int Reading = analogRead(solar_pin);

  int BITS[8];

  //Listening for the start bit
  if (Reading > threshold) {
    for (int i =0; i<8 ; i++) {
      if (analogRead(solar_pin) > threshold) {
        BITS[i] = 1 ;
      }
      else {
        BITS[i] = 0;
      }
      delay(10);
    }

    int search_letter = 0;
    for (int j =1; j <8; j++) {
    if (BITS[j] ==1) {
      search_letter = search_letter + (1<<(7-j));
    }
    }
  
    char final_letter=search_letter;
    Serial.print(final_letter);
  
  }
}
