CC ?= clang
CFLAGS = -Wall -O3
DEFS =
INCLUDES = -Isrc -Isrc/include
LIBS =
TARGET = scss
SRCS =	src/main.c \
        src/lfsr.c \
		src/adder.c

all: $(SRCS)
	 $(CC) $(CFLAGS) $(DEFS) $(INCLUDES) $(SRCS) $(LIBS) -o $(TARGET)

clean:
	rm $(TARGET)
