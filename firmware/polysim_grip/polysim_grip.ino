#include <Wire.h>

#define BTN_REGISTER 0x01
#define JOYCLIC_REGISTER 0x02
#define X_REGISTER 0x03
#define Y_REGISTER 0x04

int pin_btn = A0;
int pin_led = 2;

int pin_joystick_click = A1;
int pin_x_axis = A2;
int pin_y_axis = A3;

int btn_status = 0;
int joystick_click_status = 0;
int x_value = 0;
int y_value = 0;

byte received_data = 0;

void setup() {

  Wire.begin(0x55); // Initialize I2C (Slave Mode: address=0x55 )
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

  Wire.onReceive(I2C_RxHandler);
  Wire.onRequest(I2C_TxHandler);
  
  //Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  
  pinMode(pin_btn, INPUT_PULLUP);
  pinMode(pin_joystick_click, INPUT_PULLUP);


 //digitalWrite(pin_led, LOW);

 
}

 


void I2C_RxHandler(int numBytes)
{
  
  while(Wire.available()) {  // Read Any Received Data
    received_data = Wire.read();
  }
  
}
 
void I2C_TxHandler(void)
{

  if(received_data == BTN_REGISTER){
    
    Wire.write(btn_status);

    
  }else if(received_data == JOYCLIC_REGISTER){

    Wire.write(joystick_click_status);
    
  }else if(received_data == X_REGISTER){

    Wire.write((byte)(x_value >> 8));   
    Wire.write((byte)(x_value & 0xFF)); 



    
  }else if(received_data == Y_REGISTER){

    Wire.write((byte)(y_value >> 8));   
    Wire.write((byte)(y_value & 0xFF)); 

  }
  
}



void loop() {

    btn_status = analogRead(pin_btn);
    joystick_click_status = analogRead(pin_joystick_click);
    x_value = analogRead(pin_x_axis);
    y_value = analogRead(pin_y_axis);
    
    digitalWrite(pin_led, HIGH);

  //delay(10);
}
