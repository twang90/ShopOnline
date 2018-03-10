CC = g++

SRCS = src/Client.cc \
	 src/main.cc \
	../utils/src/Comm.cc \
	../utils/src/ClientComm.cc \
	../utils/src/Message.cc

OBJS = $(SRCS:.cc=.o)

CFLAGS += -Wall -std=c++11 -g -O2
LFLAGS =
LIBS = 
INCLUDES = -Iinclude/ -I../utils/include/

TARGETS = client

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm *.o $(TARGETS) *~ src/*~ $(OBJS) || true