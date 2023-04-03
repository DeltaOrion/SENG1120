CC=g++
CFLAGS=-c -Wall -std=c++98
LDFLAGS=
SOURCES= TollStackDemo.cpp TollStack.h LStack.h LinkedList.h Node.h EToll.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
