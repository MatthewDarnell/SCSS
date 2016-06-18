/*
    Copyright Matthew Darnell
    Summer 2016, CECS 564 University of Louisville
    Content Scrambling System (CSS) Simulator
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <cipher.h>
void encrypt(BIT *plaintext, BIT *keystream, BIT *ciphertext)
{
    int i;
    for(i=0; i<8; i++){
        ciphertext[i] = plaintext[i] ^ keystream[i];
    }
}
