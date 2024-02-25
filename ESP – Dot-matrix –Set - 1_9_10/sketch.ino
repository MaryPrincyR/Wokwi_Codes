//ESP – Dot-matrix – Problems Set - 1:9_10
//Display diagonal LEDs connecting Left top LED to Right bottom LED.
//Display diagonal LEDs connecting Right top LED to Left bottom LED.

void setup()
{
  // put your setup code here, to run once:
  //Rows are connected to PORTL and columns are connected to PORTF
  volatile char *dirf = (char*)0x30;
  volatile char *dirl = (char*)0x10A;
  volatile char *outf = (char*)0x31;
  volatile char *outl = (char*)0x10B;

  *dirf = 0xFF;
  *dirl = 0xFF;

  char i = 0, a = 0, count = 0;

  //LED display pattern
  volatile char Diagonal[][8] = {
    { 0b10000000,
      0b01000000,
      0b00100000,
      0b00010000,
      0b00001000,
      0b00000100,
      0b00000010,
      0b00000001
    },
    { 0b00000001,
      0b00000010,
      0b00000100,
      0b00001000,
      0b00010000,
      0b00100000,
      0b01000000,
      0b10000000
    }
  };

  while (1)
  {
    for (a = 0; a < 100; a++)
    {
      for (i = 0; i < 8; i++)
      {
        *outl = ~(1 << i);
        *outf = Diagonal[count][i];
        *outl = 0xFF;
        *outf = 0;
      }
    }
    //delay(10);
    count++;
    if (count == 2)  count = 0;
  }
}

