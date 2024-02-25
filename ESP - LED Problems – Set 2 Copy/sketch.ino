/*ESP - LED Problems – Set 2*/

void setup() {
  // put your setup code here, to run once:
  volatile char *DIR_F = (char*)0x30;//DDRF – Port F Data Direction Register
  *DIR_F = 0xFF;// set PORT F as output register
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long int i;
  volatile char *OUT_F = (char*)0x31; // PORTF – Port F Data Register

  //Blink First LED (With Delay)
  /* *OUT_F = 0x01;
    for(i=0;i<300000;i++);
    OUT_F=0x00;
    for(i=0;i<300000;i++);

    //Blink all the 8 LEDs (with delay)
    OUT_F = 0xFF;
    for(i=0;i<300000;i++);
    OUT_F=0x00;
    for(i=0;i<300000;i++);

    //Glow the LEDs one by one (Do not off the LED)
    OUT_F = 0x01;
    for(i=0;i<300000;i++);
    OUT_F=0x03;
    for(i=0;i<300000;i++);
    OUT_F = 0x07;
    for(i=0;i<300000;i++);
    OUT_F=0x0F;
    for(i=0;i<300000;i++);
    OUT_F = 0x1F;
    for(i=0;i<300000;i++);
    OUT_F=0x3F;
    for(i=0;i<300000;i++);
    OUT_F = 0x7F;
    for(i=0;i<300000;i++);
    OUT_F=0xFF;
    for(i=0;i<300000;i++);
    OUT_F=0x00;
    for(i=0;i<300000;i++);

    //Glow the LEDs one by one(at a time one LED should glow)
    OUT_F = 0x01;
    for(i=0;i<300000;i++);
    OUT_F=0x02;
    for(i=0;i<300000;i++);
    OUT_F = 0x04;
    for(i=0;i<300000;i++);
    OUT_F=0x08;
    for(i=0;i<300000;i++);
    OUT_F = 0x10;
    for(i=0;i<300000;i++);
    OUT_F=0x20;
    for(i=0;i<300000;i++);
    OUT_F = 0x40;
    for(i=0;i<300000;i++);
    OUT_F=0x80;
    for(i=0;i<300000;i++);
    OUT_F=0x00;
    for(i=0;i<300000;i++);

    //Glow the EVEN LEDs one by one (Do not off the LED)
    OUT_F = 0x01;
    for(i=0;i<300000;i++);
    OUT_F=0x05;
    for(i=0;i<300000;i++);
    OUT_F = 0x15;
    for(i=0;i<300000;i++);
    OUT_F=0x55;
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);

    //Glow the ODD LEDs one by one (Do not off the LED)
    OUT_F = 0x02;
    for(i=0;i<300000;i++);
    OUT_F=0x0A;
    for(i=0;i<300000;i++);
    OUT_F = 0x2A;
    for(i=0;i<300000;i++);
    OUT_F=0xAA;
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);

    //Glow 0 to 3 LEDs (one by one)
    OUT_F = 0x01;
    for(i=0;i<300000;i++);
    OUT_F=0x03;
    for(i=0;i<300000;i++);
    OUT_F = 0x07;
    for(i=0;i<300000;i++);
    OUT_F=0x0F;
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);

    //Glow 4 to 7 LEDs (one by one)
    OUT_F = 0x10;
    for(i=0;i<300000;i++);
    OUT_F=0x30;
    for(i=0;i<300000;i++);
    OUT_F = 0x70;
    for(i=0;i<300000;i++);
    OUT_F=0xF0;
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);

    //Glow 3 to 0 LEDs (one by one)
    OUT_F = 0x08;
    for(i=0;i<300000;i++);
    OUT_F=0x0C;
    for(i=0;i<300000;i++);
    OUT_F = 0x0E;
    for(i=0;i<300000;i++);
    OUT_F=0x0F;
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);*/

  //Glow 7 to 4 LEDs (one by one)
  *OUT_F = 0x80;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xC0;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xE0;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xF0;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
}
