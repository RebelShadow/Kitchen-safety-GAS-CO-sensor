int buzzer = 8;
int LED1 = 3;
int LED2 = 4;
int MQ2 = A0;
int MQ7 = A1;
int button = 10;

float sensor1Value;
float sensor2Value;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);            //buzzer for noise on pin 8
  pinMode(LED1, OUTPUT);              //led on pin 3
  pinMode(LED2, OUTPUT);              //led on pin 4
  pinMode(MQ2, INPUT);                //analog input for MQ-2 sensor
  pinMode(MQ7, INPUT);                //analog input for MQ-7 sensor
  pinMode(button, INPUT_PULLUP);      //button to reset sensor



  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Sensors warming up!");
  delay(20000); // allow the sensors to warm up

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1Value = analogRead(MQ2);   // read analog input pin 0
  sensor2Value = analogRead(MQ7);   // read analog input pin 1
  
  Serial.print("Sensor1 Value: ");
  Serial.print(sensor1Value);           //prints value of MQ-2 sensor
  Serial.print("\n");
  Serial.print("Sensor2 Value: ");
  Serial.print(sensor2Value);           //prints value of MQ-7 sensor
  Serial.print("\n");
  Serial.println(digitalRead(button));  //prints 1 if the button is pressed else prints 0
  
  while(sensor1Value > 100 )            //while the value of MQ-2 sensor is over 100
  {
    Serial.print(" | GAS detected!");   
    Serial.print("\n");
    tone(buzzer, 440);                  // Send A sound signal...
    digitalWrite(LED1, HIGH);           // Turn the LED on
    delay(300);                         // ...for 300 miiliseconds
    noTone(buzzer);                     // Stop sound...
    digitalWrite(LED1, LOW);            // Turn the LED off
    delay(300);

    if(digitalRead(button)==LOW)        //if button is pressed
      { 
        break;                          //reset the detection
          
      }
  }

  while(sensor2Value > 100)                             //while the value of MQ-2 sensor is over 100
  {
    Serial.print(" | high level of CO detected!");
    Serial.print("\n");
    tone(buzzer, 440);                                  // Send A sound signal...
    digitalWrite(LED2, HIGH);                           // Turn the LED on
    delay(300);                                         // ...for 300 miiliseconds
    noTone(buzzer);                                     // Stop sound...
    digitalWrite(LED2, LOW);                            // Turn the LED off
    delay(300);

    if(digitalRead(button)==LOW)                        //if button is pressed
      {
        break;                                          //reset the detection
      }
  }
}
