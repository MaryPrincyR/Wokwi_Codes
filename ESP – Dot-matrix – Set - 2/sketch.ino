//ESP – Dot-matrix – Problems Set - 2
//Display Character A,B,1,2,a,q,$,#,α,Ω
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

  char i = 0, count = 0;
  volatile long a = 0;
  
  //LED display pattern
  volatile char pattern[][8] = {
    { 0b01111110,//A
      0b11111111,
      0b11000011,
      0b11111111,
      0b11111111,
      0b11000011,
      0b11000011,
      0b11000011
    },
    { 0b01111110,//B
      0b11000011,
      0b11000011,
      0b11111110,
      0b11111110,
      0b11000011,
      0b11000011,
      0b01111110
    },
    { 0b00011110,//1
      0b00110110,
      0b01100110,
      0b00000110,
      0b00000110,
      0b00000110,
      0b00000110,
      0b00000110
    },
    { 0b01111110,//2
      0b11111111,
      0b00000111,
      0b00001110,
      0b00011100,
      0b00111000,
      0b11111111,
      0b11111111
    },
    { 0b01111110,//a
      0b11111111,
      0b00000011,
      0b01111111,
      0b11000011,
      0b11000011,
      0b01111111,
      0b00000011,
    },
    { 0b00000001,//q
      0b01111111,
      0b11000011,
      0b11000011,
      0b00111111,
      0b00000011,
      0b00000011,
      0b00000011,
    },
    { 0b00011000,//$
      0b11111111,
      0b11000000,
      0b11111111,
      0b01111111,
      0b00000011,
      0b11111111,
      0b00011000,
    },
    { 0b01100110,//#
      0b11111111,
      0b11111111,
      0b01100110,
      0b01100110,
      0b11111111,
      0b11111111,
      0b01100110,
    },
    { 0b00000011,//α
      0b00111110,
      0b11111110,
      0b11000110,
      0b11000100,
      0b01111110,
      0b00111110,
      0b00000011,
    },
    { 0b00111100,//Ω
      0b01111110,
      0b11000011,
      0b11000011,
      0b11000011,
      0b01100110,
      0b11000011,
      0b11000011,
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
    if (count == 10)  count = 0;
  }
}

