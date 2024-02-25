//Press switch 7 & display from 0 to 9 and 9 to 0 one time.

int display_number(uint8_t num);
void setup()
{
  // put your setup code here, to run once:
  //7segment display is connected to PORTF
  //switches are connected to port k.

  volatile char *dirf = (char*)0x30;//DDRF – Port F Data Direction Register
  volatile char *dirk = (char*)0x107;//DDRK – Port K Data Direction Register
  volatile char *outf = (char*)0x31;//PORTF – Port F Data Register
  volatile char *ink = (char*)0x106;// PINK – Port K Input Pins Address

  *dirf = 0xFF;//set PORT F as o/p port .
  *dirk = 0x00;//set PORT K as i/p port .

  volatile long button, i, j;

  while (1)
  {
    button = *ink;
    if ((button & 0x40) == 0x40)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing

      for (i = 0; i < 10; i++)
      {
        *outf = display_number(i);
        for (j = 0; j < 300000; j++);
      }
      for (i = 9; i >= 0; i--)
      {
        *outf = display_number(i);
        for (j = 0; j < 300000; j++);
      }


    }
  }
}

int display_number(uint8_t num)
{
  long int x;
  long seven_segment[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
  x = seven_segment[num];
  return x;
}
