//Press any switch & Display should start from that number till nine and restart from that number
//till 9. Continuous loop

//Connect a Single 7-Segment Display to an 8-bit port.Connect 8 Switches
// to an 8-bit port.

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
    button = *ink;
    if ((button & 0x01) == 0x01)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 1; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x02) == 0x02)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 2; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x04) == 0x04)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 3; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x08) == 0x08)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 4; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x10) == 0x10)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 5; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x20) == 0x20)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 6; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x40) == 0x40)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 7; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }
      }
    }

    else if ((button & 0x80) == 0x80)
    {
      for (j = 0; j < 120000; j++);//a delay for switch debouncing
      while (1)
      {
        for (i = 8; i < 10; i++)
        {
          *outf = display_number(i);
          for (j = 0; j < 300000; j++);
        }

      }
    }
  }
}

int display_number(uint8_t num)
{
  long int x;
  long seven_segment[] = {0x3F,//0
                          0x06,//1
                          0x5B,//2
                          0x4F,//3
                          0x66,//4
                          0x6D,//5
                          0x7D,//6
                          0x07,//7
                          0x7F,//8
                          0x67//9
                         };
  x = seven_segment[num];
  return x;
}

