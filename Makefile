CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES= DBinterface.cpp MechPart.cpp DBdemo.cpp
value_typeS=$(SOURCES:.cpp=.o)
EXECUTABLE=DBdemo

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(value_typeS)
	$(CC) $(LDFLAGS) $(value_typeS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
