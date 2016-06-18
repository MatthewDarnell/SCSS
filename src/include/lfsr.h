/*
    Copyright Matthew Darnell
    2016
    Summer 2016, CECS 564 University of Louisville
    Content Scrambling System (CSS) Simulator
*/
#include <stdint.h>

typedef enum { ZERO=0, ONE=1 } BIT;
typedef int8_t BYTE;

struct lfsr {
  int num_bits;
  BYTE *contents;
  int *taps;
};

void print_lfsr(struct lfsr*);
void setup_lfsr(struct lfsr*, int*, int*);
void init_with_key(struct lfsr* lf_arr[], int, BYTE*);
BIT shift_lfsr(struct lfsr*);
void get_next_byte(struct lfsr*, BIT b[8]);
