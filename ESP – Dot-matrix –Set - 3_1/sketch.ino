//ESP – Dot-matrix – Problems Set - 3_1
//Display Characters A to E one by one in one second interval

void setup()
{
  // put your setup code here, to run once:
  volatile char *dirf = (char*)0x30;//DDRF
  volatile char *dirl = (char*)0x10A;//DDRL
  volatile char *outf = (char*)0x31;//PORTF
  volatile char *outl = (char*)0x10B;//PORTL

  //set PORTF and PORTL as o/p ports
  *dirf = 0xFF;
  *dirl = 0xFF;

  char i = 0, count = 0;
  volatile long a = 0;

  //LED display pattern
  volatile char pattern[][8] = {
    { 0b01111110,//A
      0b11111111,
      0b11000011,
      0b11000011,
      0b11111111,
      0b11000011,
      0b11000011,
      0b11000011
    },
    { 0b11111110,//B
      0b11111111,
      0b11000011,
      0b11111110,
      0b11000011,
      0b11000011,
      0b11111111,
      0b11111110
    },
    { 0b01111111,//C
      0b11111111,
      0b11000000,
      0b11000000,
      0b11000000,
      0b11000000,
      0b11111111,
      0b01111111
    },
    { 0b11111110,//D
      0b11111111,
      0b11000011,
      0b11000011,
      0b11000011,
      0b11000011,
      0b11111111,
      0b11111110
    },
    { 0b01111111,//E
      0b11111111,
      0b11000000,
      0b11111111,
      0b11111111,
      0b11000000,
      0b11111111,
      0b01111111
    }
  };
  while (1)
  {
    for (a = 0; a < 20000; a++)
    {
      for (i = 0; i < 8; i++)
      {
        *outl = ~(1 << i);//row
        *outf = pattern[count][i];//column
        *outl = 0xFF;
        *outf = 0;
      }
    }
    for (a = 0; a < 45000; a++);//delay
    count++;
    if (count == 5)  count = 0;
  }
}

