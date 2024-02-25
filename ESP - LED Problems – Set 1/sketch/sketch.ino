/*ESP - LED Problems – Set 1*/

void setup() 
{
  // put your setup code here, to run once:
  volatile char *DIR_F = (char*)0x30;//DDRF register
  *DIR_F = 0xFF;//set PORT_F as output port

}

void loop()
{
  //uncomment and check for each cases
  volatile char *OUT_F = (char*)0x31; // PORTF – Port F Data Register
  //*OUT_F =0x01;//LSB bit only
  //*OUT_F =0x80;//MSB bit only
  //*OUT_F =0x03;//bit 0 and 1 only
  //*OUT_F =0xC0;//bit 6 and 7 only
  //*OUT_F =0x0F;//bit 0 to bit 3
  //*OUT_F =0xF0;//bit 7 to bit 4
  //*OUT_F =0xFF;//all bits ON
  //*OUT_F =0xAA;//all odd number LEDS
  //*OUT_F =0x55;//all even number LEDS
  *OUT_F = 0x9A; //only LEDS 1,3,4,7

}
