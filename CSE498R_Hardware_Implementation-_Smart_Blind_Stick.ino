

   #define RED 10                   // Define Digital Pin Number 10 as RED of Nano for Red Alert (stop) LED 
   #define GREEN 9                  // Define Digital Pin Number 9 as GREEN of Nano for Green Alert (go/move) LED 
   #define BUZZER 8                 // Define Digital Pin Number 8 as BUZZER of Nano for Sound (Alert)  


   const int trigPin = 3;           // Fixed Digital Pin Number 3 for sonar trig  
   const int echoPin = 2 ;          // Fixed Digital Pin Number 2 for sonar echo

   
   long duration;      // time duration for sonar 
   int distance;       // distance calculation for sonar
   int sound =1000;    // sound level



    void setup()
  {
    
     pinMode(trigPin, OUTPUT);      // Sets the trigPinas an Output
     pinMode(echoPin, INPUT);      // Sets the echoPinas an Input
     pinMode(RED,OUTPUT);          // sets the digital pin as output
     pinMode(GREEN,OUTPUT);        // sets the digital pin as output
 
     pinMode(BUZZER, OUTPUT);

     
     Serial.begin(9600);         // Begins Serial Communication

     
  }



    void loop()
  {
    
    digitalWrite(trigPin, LOW);    // Clears the trigPin
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);   // sets the trigPinon HIGH state for 10 micro seconds 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);     // Reads the echoPin, returns the sound wave travel time in microseconds 
    distance = duration*0.034/2;           // Calculating the distance

  
  
      if (distance >= 0 &&  distance <=50 )
     {
      
        digitalWrite(RED, HIGH); // sets the RED LED on
        digitalWrite(GREEN, LOW); // sets the GREEN LED off
        sound = 1000 ;

        tone(BUZZER, sound); 
        
        Serial.print("Distance : ");
        Serial.print(distance);
        Serial.println(" cm");
        Serial.println("Please Stop");
        
        delay(150);
        noTone(BUZZER);
      
     }


     else
    {
       digitalWrite(GREEN, HIGH);  // sets the LED on
       digitalWrite(RED, LOW); // sets the RED LED off 
       sound = 100 ;
       tone(BUZZER, sound); 
      
       Serial.print("Distance : ");
       Serial.print(distance);
       Serial.println(" cm");
       Serial.println("Go Ahead");
      
       noTone(BUZZER);
       
      
    }
   
    delay(1000);

    
}
