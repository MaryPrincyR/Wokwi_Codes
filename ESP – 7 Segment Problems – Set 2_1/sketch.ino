//Press any switch & display that number.
//1->1,2->2,4->4 etc

void setup() {
  //7segment display is connected to PORTF
  //switches are connected to port k.

  volatile char *dirf = (char*)0x30;//DDRF – Port F Data Direction Register
  volatile char *dirk = (char*)0x107;//DDRK – Port K Data Direction Register
  volatile char *outf = (char*)0x31;//PORTF – Port F Data Register
  volatile char *ink = (char*)0x106;// PINK – Port K Input Pins Address

  *dirf = 0xFF;//set PORT F as o/p port .
  *dirk = 0x00;//set PORT K as i/p port .

  volatile long button, j;


  while (1)
  {
    button = *ink;
    if ((button & 0x01) == 0x01)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x06;
    }
    else if ((button & 0x02) == 0x02)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x5B;
    }
    else if ((button & 0x04) == 0x04)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x4F;
    }
    else if ((button & 0x08) == 0x08)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x66;
    }
    else if ((button & 0x10) == 0x10)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x6D;
    }
    else if ((button & 0x20) == 0x20)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x7D;
    }
    else if ((button & 0x40) == 0x40)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x07;
    }
    else if ((button & 0x80) == 0x80)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      *outf = 0x7F;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
