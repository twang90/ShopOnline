CC = g++

SRCS = src/Server.cc src/main.cc ../comm/src/ServerComm.cc ../comm/src/Comm.cc

OBJS = $(SRCS:.cc=.o)

CFLAGS = -Wall -std=c++11 -g -O2
LFLAGS = 
LIBS = 
INCLUDES = -Iinclude/ -I../comm/include

TARGETS = server

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm $(OBJS) $(TARGETS) src/*~ include/*~ *~ || true