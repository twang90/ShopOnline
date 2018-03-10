CC = g++

SRCS = src/Server.cc \
	src/main.cc \
	../utils/src/ServerComm.cc \
	../utils/src/Comm.cc \
	../utils/src/Message.cc

OBJS = $(SRCS:.cc=.o)

CFLAGS = -Wall -std=c++11 -g -O2
LFLAGS = 
LIBS = 
INCLUDES = -Iinclude/ -I../utils/include

TARGETS = server

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm $(OBJS) $(TARGETS) src/*~ include/*~ *~ || true