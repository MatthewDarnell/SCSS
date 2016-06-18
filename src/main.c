/*
    Copyright Matthew Darnell
    2016
    Summer 2016, CECS 564 University of Louisville
    Content Scrambling System (CSS) Simulator
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <lfsr.h>

#define trace fprintf(stderr, "%s - line %d\n", __func__, __LINE__);


int main()
{
  struct lfsr l_17, l_25;
  int num_bits_1 = 17,
      num_bits_2 = 25;
  int taps_1[17] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, //x^17 + x^2 + 1
      taps_2[25] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 }; //x^25 + x^21 + x^20 + x^10 + 1
  setup_lfsr(&l_17, &num_bits_1, taps_1);
  setup_lfsr(&l_25, &num_bits_2, taps_2);

  //Some random 40-bit Key
  BYTE key[40] = {
    1,0,0,0,0,0,0,1,0,0,
    1,0,0,0,0,1,0,0,0,0,
    1,0,0,0,0,0,0,1,0,0,
    1,0,0,0,0,0,0,1,0,0
  };

  struct lfsr *init_arr[2] = { &l_17, &l_25 };
  init_with_key(init_arr, 2, key);

  BIT byte_17[8], byte_25[8];
  get_next_byte(&l_17, byte_17);
  get_next_byte(&l_25, byte_25);

  printf("\nlfsr-17 next byte: \n");
  int i;
  for(i=0; i<8; i++){
      printf("%d ", byte_17[i]);
  }
  printf("\nlfsr-25 next byte: \n");
  for(i=0; i<8; i++){
      printf("%d ", byte_25[i]);
  }
  printf("\n");


  return 0;
}
