/*
    Copyright Matthew Darnell
    Summer 2016, CECS 564 University of Louisville
    Content Scrambling System (CSS) Simulator
*/
#ifndef CIPHER_H_
#define CIPHER_H_
#include <bits.h>
#include "lfsr.h"
void xor(BIT*,BIT*,BIT*);
int encrypt_file(const char *file, struct lfsr *l_17, struct lfsr *l_25, const char *outfile, int *dMode, unsigned char initialization_vector);
int decrypt_file(const char *file, struct lfsr *l_17, struct lfsr *l_25, const char *outfile, int *dMode, unsigned char initialization_vector);
void bit_array_to_unsigned_char(BIT *bits, unsigned char *u8);
#endif
