//ESP – 7 Segment Problems – Set 3
//2. Display 0.0 to 9.9 in loop with delay
//Do not forget to change the default common anode to common cathode type in diagram.json.

void setup() {
  // put your setup code here, to run once:
  volatile char *DIR_F = (char*)0x30;//DDRF – Port F Data Direction Register
  *DIR_F = 0xFF;// set PORT F as output register
  volatile char *DIR_K = (char*)0x107;//DDRK – Port K Data Direction Register
  *DIR_K = 0xFF;// set PORT K as output register
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char i, k;
  volatile long int j;
  volatile char *OUT_F = (char*)0x31;// PORTF – Port F Data Register
  volatile char *OUT_K = (char*)0x108;//PORTK – Port K Data Register

  for (i = 0; i < 10; i++)
  {
    for (k = 0; k < 10; k++) {
      if (i == 0) {
        *OUT_F = 0xBF; //0.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }

      else if (i == 1) {
        *OUT_F = 0xB0; //1.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 2) {
        *OUT_F = 0xDB; //2.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 3) {
        *OUT_F = 0xCF; //3.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 4) {
        *OUT_F = 0xE6; //4.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 5) {
        *OUT_F = 0xED; //5.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 6) {
        *OUT_F = 0xFD; //6.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 7) {
        *OUT_F = 0x87; //7.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 8) {
        *OUT_F = 0xFF; //8.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
      else if (i == 9) {
        *OUT_F = 0xE7; //9.
        if (k == 0) {
          *OUT_K = 0x3F; //0
          for (j = 0; j < 500000; j++);
        }
        else if (k == 1) {
          *OUT_K = 0x30; //1
          for (j = 0; j < 500000; j++);
        }
        else if (k == 2) {
          *OUT_K = 0x5B; //2
          for (j = 0; j < 500000; j++);
        }
        else if (k == 3) {
          *OUT_K = 0x4F; //3
          for (j = 0; j < 500000; j++);
        }
        else if (k == 4) {
          *OUT_K = 0x66; //4
          for (j = 0; j < 500000; j++);
        }
        else if (k == 5) {
          *OUT_K = 0x6D; //5
          for (j = 0; j < 500000; j++);
        }
        else if (k == 6) {
          *OUT_K = 0x7D; //6
          for (j = 0; j < 500000; j++);
        }
        else if (k == 7) {
          *OUT_K = 0x07; //7
          for (j = 0; j < 500000; j++);
        }
        else if (k == 8) {
          *OUT_K = 0x7F; //8
          for (j = 0; j < 500000; j++);
        }
        else if (k == 9) {
          *OUT_K = 0x67; //9
          for (j = 0; j < 500000; j++);
        }
      }
    }
  }
}



