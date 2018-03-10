CC = G++

SRCS = src/Server.cc src/Comm.cc src/main.cc

OBJS = $(SRCS:.cc=.o)

CFLAGS = -Wall -std=c++11 -g -O2
LFLAGS =
LIBS = 
INCLUDES = -Iinclude/

TARGETS = server

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm src/*.o $(TARGETS) src/*~ include/*~ *~ || true