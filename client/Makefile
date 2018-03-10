CC = g++

SRCS = src/Client.cc src/main.cc ../comm/src/Comm.cc ../comm/src/ClientComm.cc

OBJS = $(SRCS:.cc=.o)

CFLAGS += -Wall -std=c++11 -g -O2
LFLAGS =
LIBS = 
INCLUDES = -Iinclude/ -I../comm/include/

TARGETS = client

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm *.o $(TARGETS) *~ src/*~ $(OBJS) || true