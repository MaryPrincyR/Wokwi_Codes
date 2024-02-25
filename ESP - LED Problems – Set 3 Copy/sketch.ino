/*ESP - LED Problems – Set 3*/

void setup() {
  // put your setup code here, to run once:
  volatile char *DIR_F = (char*)0x30;//DDRF – Port F Data Direction Register
  *DIR_F = 0xFF;// set PORT F as output register
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long int i;
  volatile char *OUT_F = (char*)0x31; // PORTF – Port F Data Register

  //Glow the LEDs in following order
  //3,7 delay – 2,6 delay – 1,5 delay – 0,4 delay
  /**OUT_F = 0x88;//3,7
    for(i=0;i<300000;i++);
    OUT_F = 0x44;//2,6
    for(i=0;i<300000;i++);
    OUT_F = 0x22;//1,5
    for(i=0;i<300000;i++);
    OUT_F = 0x11;//0,4
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //0,4 delay – 1,5 delay – 2,6 delay – 3,7 delay
    OUT_F = 0x11;//0,4
    for(i=0;i<300000;i++);
    OUT_F = 0x22;//1,5
    for(i=0;i<300000;i++);
    OUT_F = 0x44;//2,6
    for(i=0;i<300000;i++);
    OUT_F = 0x88;//3,7
    for(i=0;i<300000;i++);

    //Glow 0 to 7 LEDs with delay and 7 to 0 LEDs with delay
    OUT_F = 0x01;//0
    for(i=0;i<300000;i++);
    OUT_F = 0x02;//1
    for(i=0;i<300000;i++);
    OUT_F = 0x04;//2
    for(i=0;i<300000;i++);
    OUT_F = 0x08;//3
    for(i=0;i<300000;i++);
    OUT_F = 0x10;//4
    for(i=0;i<300000;i++);
    OUT_F = 0x20;//5
    for(i=0;i<300000;i++);
    OUT_F = 0x40;//6
    for(i=0;i<300000;i++);
    OUT_F = 0x80;//7
    for(i=0;i<300000;i++);
    OUT_F = 0x40;//6
    for(i=0;i<300000;i++);
    OUT_F = 0x20;//5
    for(i=0;i<300000;i++);
    OUT_F = 0x10;//4
    for(i=0;i<300000;i++);
    OUT_F = 0x08;//3
    for(i=0;i<300000;i++);
    OUT_F = 0x04;//2
    for(i=0;i<300000;i++);
    OUT_F = 0x02;//1
    for(i=0;i<300000;i++);
    OUT_F = 0x01;//0
    for(i=0;i<300000;i++);

    //Glow 0,2,1,3,4,6,5,7 LEDs with delay
    OUT_F = 0x01;//0
    for(i=0;i<300000;i++);
    OUT_F = 0x04;//2
    for(i=0;i<300000;i++);
    OUT_F = 0x02;//1
    for(i=0;i<300000;i++);
    OUT_F = 0x08;//3
    for(i=0;i<300000;i++);
    OUT_F = 0x10;//4
    for(i=0;i<300000;i++);
    OUT_F = 0x40;//6
    for(i=0;i<300000;i++);
    OUT_F = 0x20;//5
    for(i=0;i<300000;i++);
    OUT_F = 0x80;//7
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //0,1 delay – 6,7, delay – 2,3, delay – 4,5, delay
    OUT_F = 0x03;//0,1
    for(i=0;i<300000;i++);
    OUT_F = 0xC0;//6,7
    for(i=0;i<300000;i++);
    OUT_F = 0x0C;//2,3
    for(i=0;i<300000;i++);
    OUT_F = 0x30;//4,5
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //4,5 delay – 2,3, delay – 6,7, delay – 0,1, delay
    OUT_F = 0x30;//4,5
    for(i=0;i<300000;i++);
    OUT_F = 0x0C;//2,3
    for(i=0;i<300000;i++);
    OUT_F = 0xC0;//6,7
    for(i=0;i<300000;i++);
    OUT_F = 0x03;//0,1
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //0,1,2 delay – 5,6,7, delay – 3,4, delay
    OUT_F = 0x07;//0,1,2
    for(i=0;i<300000;i++);
    OUT_F = 0xE0;//5,6,7
    for(i=0;i<300000;i++);
    OUT_F = 0x18;//3,4
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //3,4 delay – 5,6,7, delay – 0,1,2, delay
    OUT_F = 0x18;//3,4
    for(i=0;i<300000;i++);
    OUT_F = 0xE0;//5,6,7
    for(i=0;i<300000;i++);
    OUT_F = 0x07;//0,1,2
    for(i=0;i<300000;i++);

    //Glow the LEDs in following order
    //0 then 0,1 then 0,1, 2…... then 0,1,2,3,4,5,6,7 with delay
    OUT_F = 0x01;//0
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x03;//0,1
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x07;//0,1,2
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x0F;//0,1,2,3
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x1F;//0,1,2,3,4
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x3F;//0,1,2,3,4,5
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0x7F;//0,1,2,3,4,5,6
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);
    OUT_F = 0xFF;//0,1,2,3,4,5,6,7
    for(i=0;i<300000;i++);
    OUT_F = 0x00;
    for(i=0;i<300000;i++);*/

  //Glow the LEDs in following order
  //7 then 7,6 then 7,6, 5…... then 7,6,5,4,3,2,1,0 with delay
  *OUT_F = 0x80;//7
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xC0;//7,6
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xE0;//7,6,5
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xF0;//7,6,5,4
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xF8;//7,6,5,4,3
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xFC;//7,6,5,4,3,2
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xFE;//7,6,5,4,3,2,1
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);
  *OUT_F = 0xFF;//7,6,5,4,3,2,1,0
  for (i = 0; i < 300000; i++);
  *OUT_F = 0x00;
  for (i = 0; i < 300000; i++);

}

