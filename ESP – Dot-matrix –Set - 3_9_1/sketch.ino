//ESP – Dot-matrix – Problems Set - 3_9
//Display “Welcome” by odd position entering from Left and Even Position
//entering from Right.

void setup()
{
  volatile char *dirf = (char*)0x30;//DDRF
  volatile char *dirl = (char*)0x10A;//DDRL
  volatile char *outf = (char*)0x31;//PORTF
  volatile char *outl = (char*)0x10B;//PORTL

  *dirf = 0xff;
  *dirl = 0xff;

  volatile long a, b;
  char i, j, count = 0;

  volatile char pattern[][24] = {
    //carefully observe the pattern, it is rotated 
    { 0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b11111111,
      0b11111111,
      0b01100000,
      0b00110000,
      0b00110000,
      0b01100000,
      0b11111111,
      0b11111111,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000
    },  // W

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b00000000,
      0b01110000,
      0b11111000,
      0b10101000,
      0b10101000,
      0b10111000,
      0b00110000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    }, // e

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b00000000,
      0b00000000,
      0b00000000,
      0b01111111,
      0b11111111,
      0b10000000,
      0b00000000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    },  // l

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b00000000,
      0b01110000,
      0b11111000,
      0b10001000,
      0b10011000,
      0b10011000,
      0b00000000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    },  // c

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b00000000,
      0b01110000,
      0b11111000,
      0b10001000,
      0b10001000,
      0b11111000,
      0b01110000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    },  // o

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b11110000,
      0b11111000,
      0b00001000,
      0b11111000,
      0b11110000,
      0b00001000,
      0b11111000,
      0b11110000,
      0, 0, 0, 0, 0, 0, 0, 0
    },  // m

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b00000000,
      0b01110000,
      0b11111000,
      0b10101000,
      0b10101000,
      0b10111000,
      0b00110000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    }  //e
  };

  while (1)
  {
loop: for (i = 24; i >= 0; i--)
    {
      for (a = 0; a < 1000; a++)//execute 1000 times for the eye to catch
      {
        for (j = 0; j < 8; j++)
        {
          *outf = (128 >> j);
          *outl = ~(pattern[count][i + j]);
          *outl = 0xFF;
          *outf = 0;
        }
      }
      for (b = 0; b < 32000; b++);//delay
    }
    count++;
    if (count > 6)
    {
      count = 0;
      goto loop;
    }

    for (i = 0; i < 25; i++)
    {
      for (a = 0; a < 1000; a++)//execute 1000 times for the eye to catch
      {
        for (j = 0; j < 8; j++)
        {
          *outf = (128 >> j);
          *outl = ~(pattern[count][i + j]);
          *outl = 0xFF;
          *outf = 0;
        }
      }
      for (b = 0; b < 32000; b++);//delay
    }
    count++;
  }
}




