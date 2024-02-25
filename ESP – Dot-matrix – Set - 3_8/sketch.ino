//ESP – Dot-matrix – Problems Set - 3_8
//Display revolving text “Welcome” Bottom to Top

void setup()
{
  //ROWS are connected to PORTK and COLUMNS are connected to PORTF.

  volatile char *dirf = (char*)0x30;//DDRF
  volatile char *dirl = (char*)0x10A;//DDRL
  volatile char *outf = (char*)0x31;//PORTF
  volatile char *outl = (char*)0x10B;//PORTL

  *dirf = 0xff;
  *dirl = 0xff;

  volatile long a, b;
  char i, j, count = 0;

  //LED display pattern
  volatile char pattern[][24] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, //W
      0b00000000,
      0b11000011,
      0b11000011,
      0b11000011,
      0b11000011,
      0b11011011,
      0b11100111,
      0b11100111,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //e
      0b00000000,
      0b00000000,
      0b00000000,
      0b01111110,
      0b11000011,
      0b11001110,
      0b01100000,
      0b00111111,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //l
      0b00110000,
      0b00110000,
      0b00110000,
      0b00110000,
      0b00110000,
      0b00110000,
      0b00011110,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //c
      0b00000000,
      0b00000000,
      0b00000000,
      0b00111111,
      0b01111111,
      0b11100000,
      0b11111111,
      0b00111111,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //o
      0b00000000,
      0b00000000,
      0b00000000,
      0b00111100,
      0b01100110,
      0b11100111,
      0b01100110,
      0b00111100,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //m
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b11100110,
      0b11011011,
      0b11000011,
      0b11000011,
      0, 0, 0, 0, 0, 0, 0, 0
    },
    { 0, 0, 0, 0, 0, 0, 0, 0, //e
      0b00000000,
      0b00000000,
      0b00000000,
      0b01111110,
      0b11000011,
      0b11001100,
      0b01100000,
      0b00111111,
      0, 0, 0, 0, 0, 0, 0, 0
    }
  };

  while (1)
  {
    for (i = 0; i < 25 ; i++)
    {
      for (a = 0; a < 1000; a++)//execute 1000 times for the eye to catch
      {
        for (j = 0; j < 8; j++)
        {
          *outf = (pattern[count][i + j]);
          *outl = ~(1 << j);
          *outf = 0;
          *outl = 0xFF;
        }
      }

      for (b = 0; b < 30000; b++);//delay

    }

    count++;
    if (count > 6) count = 0;
  }
}

