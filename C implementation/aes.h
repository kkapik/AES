#ifndef AES_H
#define AES_H

#include "string.h"
typedef unsigned char byte;

struct AES {
    byte key[4][4];
    byte expanded_key[11*4][4];
    byte state[4][4];
};

void encrypt(struct AES * aes);
void expand_key(struct AES * aes);
void add_round_key(struct AES * aes, int round);
void sub_bytes(byte state[4][4]);
void shift_rows(byte state[4][4]);
void mix_columns(byte state[4][4]);
void key_schedule_core(byte row[4], int inum);

#endif // AES_H
