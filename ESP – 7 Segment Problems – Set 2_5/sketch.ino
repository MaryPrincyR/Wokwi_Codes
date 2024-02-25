//Display A – F in a loop


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

  volatile long button,  j;
  uint8_t i;
  while (1)
  {
    for (i = 10; i < 16; i++)
    {
      *outf = display_number(i);
      for (j = 0; j < 400000; j++);
    }
  }
}
int display_number(uint8_t num)
{
  long int x;
  //0-9 and A-F
  long seven_segment[] = {0x3F,//0
                          0x06,//1
                          0x5B,//2
                          0x4F,//3
                          0x66,//4
                          0x6D,//5
                          0x7D,//6
                          0x07,//7
                          0x7F,//8
                          0x67,//9
                          0x77,//A
                          0x7F,//B
                          0x39,//C
                          0x3F,//D
                          0x79,//E
                          0x71//F
                         };
  x = seven_segment[num];
  return x;
}


