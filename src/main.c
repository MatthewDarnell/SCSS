/*
    Copyright Matthew Darnell
    Summer 2016, CECS 564 University of Louisville
    Content Scrambling System (CSS) Simulator
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lfsr.h>
#include <cipher.h>

int main(int argc, char *argv[])
{
    if(argc < 3){
        fprintf(stderr, "Usage:\n./scss </path/to/plaintext> </path/to/output-encrypted>\n./scss </path/to/encrypted> </path/to/output-decrypted>\n");
        return -1;
    }

    const char  *inputFile   = argv[1],
                *outputFile  = argv[2];

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
    encrypt_file(inputFile, &l_17, &l_25, outputFile);
    return 0;
}
