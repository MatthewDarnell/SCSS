CC ?= clang
CFLAGS = -Wall -O3
DEFS =
INCLUDES = -Isrc -Isrc/include
LIBS =

SRCS =	src/main.c \
        src/lfsr.c

all: $(SRCS)
	 $(CC) $(CFLAGS) $(DEFS) $(INCLUDES) $(SRCS) $(LIBS) -o project2

clean:
	rm project2
