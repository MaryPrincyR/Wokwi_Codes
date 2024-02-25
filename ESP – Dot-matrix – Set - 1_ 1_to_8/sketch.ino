//ESP – Dot-matrix – Problems Set - 1: 1_to_8

void setup()
{
  //Rows are connected to PORTL and columns are connected to PORTF
  volatile char *dirf = (char*)0x30;
  volatile char *dirl = (char*)0x10A;
  volatile char *outf = (char*)0x31;
  volatile char *outl = (char*)0x10B;

  *dirf = 0xFF;
  *dirl = 0xFF;

  while (1)
  {
    //Display Right most Top LED
    *outl = 0xFE;
    *outf = 0x01;

    delay(500);

    //Display Left most Top LED
    *outl = 0xFE;
    *outf = 0x80;

    delay(500);

    //Display Right most bottom LED
    *outl = 0x7F;
    *outf = 0x01;

    delay(500);

    //Display Left most bottom LED
    *outl = 0x7F;
    *outf = 0x80;

    delay(500);

    //Display Topmost Row all LEDs
    *outl = 0xFE;
    *outf = 0xFF;

    delay(500);

    //Display Bottom most Row all LEDs
    *outl = 0x7F;
    *outf = 0xFF;

    delay(500);

    //Display Left most Column all LEDs
    *outl = 0x00;
    *outf = 0x80;

    delay(500);

    //Display Right most Column all LEDs
    *outl = 0x00;
    *outf = 0x01;

    delay(500);
  }
}

