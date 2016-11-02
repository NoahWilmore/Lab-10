# http://stackoverflow.com/a/2394651

LIB     := libCSC2110.a

CC      := g++
CFLAGS  := -Wall
RM      := rm -f
SOURCES := $(wildcard *.cpp)

ifneq ($(OS),Windows_NT)
	SOURCES2 := $(filter-out HighPerformanceCounter.cpp, $(SOURCES))
else
    SOURCES2 := $(SOURCES)	
endif
OBJ     := $(SOURCES2:.cpp=.o)

$(LIB): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(LIB) *.o *.gch .depend *~

rebuild: clean $(LIB)

depend: .depend

.depend: $(SOURCES2)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF ./.depend;

-include .depend
