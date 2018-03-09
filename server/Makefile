CC = G++

SRCS = src/server.c

OBJS = $(SRCS:.c=.o)

CFLAGS += -Wall -std=c++11 -g -O2
LFLAGS =
LIBS = 
INCLUDES = -Iinclude/

TARGETS = server

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm *.o $(TARGETS) *~ || true