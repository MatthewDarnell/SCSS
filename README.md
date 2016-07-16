# Simple Content Scrambling System (SCSS)

SCSS is a simple Content Scrambling System simulator written in C.

  - simulates the crypto system used to encrypt DVD data
  - 40-bit key
  - no dependencies
  - 4 encryption modes

### Version
0.2.0

### Building

```sh
$ make
```
I prefer clang as my compiler, but you can run `CC=gcc make`

### Running

```sh
$ ./scss plaintext_file encrypted_output_file encrypt [mode]

$ ./scss encrypted_input plaintext_output_file decrypt [mode]
```

Available Modes: ``[ecb, cbc, ofb, cfb]``


Be sure to set your key in ```main.c```

The default key is:
```c
BYTE key[40] = {
1,0,0,0,0,0,0,1,0,0,
1,0,0,0,0,1,0,0,0,0,
1,0,0,0,0,0,0,1,0,0,
1,0,0,0,0,0,0,1,0,0
};
```

The default initialization vector is:
```c
unsigned char initialization_vector = 0xa2;
```

Using the same key, mode, and initialization vector on an encrypted file will output the original plaintext


### Development

Ceased

License
----

MIT
