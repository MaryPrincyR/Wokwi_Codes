//ESP – Dot-matrix – Problems Set - 3_5
//Display revolving text “Welcome” Right to Left

void setup()
{

  // put your setup code here, to run once:

  //ROWS are connected to PORTK and COLUMNS are connected to PORTF.

  volatile char *dirf = (char*)0x30;//DDRF
  volatile char *dirk = (char*)0x107;//DDRK
  volatile char *outf = (char*)0x31;//PORTF
  volatile char *outk = (char*)0x108;//PORTK

  *dirf = 0xff;
  *dirk = 0xff;

  volatile long a, b;
  char i, j, count = 0;

  //LED display pattern
  volatile char pattern[][24] = {

    { 0, 0, 0, 0, 0, 0, 0, 0,
      0b11111111,
      0b11111111,
      0b01100000,
      0b00110000,
      0b00110000,
      0b01100000,
      0b11111111,
      0b11111111,
      0, 0, 0, 0, 0, 0, 0, 0,
    },  // W

    { 0, 0, 0, 0, 0, 0, 0, 0, //e
      0b00000000,
      0b01110000,
      0b11111000,
      0b10101000,
      0b10101000,
      0b10111000,
      0b00110000,
      0b00000000,
      0, 0, 0, 0, 0, 0, 0, 0
    },

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
      0b11111100,
      0b11001100, 
      0b11001100, 
      0b11001100,
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
    for (i = 0; i < 25; i++)
    {
      for (a = 0; a < 1000; a++)//execute 1000 times for the eye to catch
      {
        for (j = 0; j < 8; j++)
        {
          *outk = (pattern[count][i + j]);
          *outf = ~(128 >> j);
          *outf = 0xFF;
          *outk = 0;
        }
      }

      for (b = 0; b < 30000; b++);//delay

    }

    count++;
    if (count > 6) count = 0;
  }
}
