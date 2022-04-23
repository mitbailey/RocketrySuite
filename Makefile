CXX = g++
CC = gcc
CPPOBJS =
CCOBJS = src/main.o src/input_output.o src/Conditions.o src/Engine.o src/Parachute.o src/Simulation.o src/Vehicle.o
COBJS =
EDCXXFLAGS = -I ./ -I ./include/ -Wall -pthread $(CXXFLAGS)
EDCCFLAGS = -std=c++11 -I ./ -I ./include/ -Wall -pthread $(CXXFLAGS)
EDCFLAGS = $(CFLAGS)
EDLDFLAGS := -lpthread -lm $(LDFLAGS)
TARGET = sim.out

all: $(COBJS) $(CCOBJS) $(CPPOBJS)
	$(CXX) $(EDCXXFLAGS) $(EDCCFLAGS) $(COBJS) $(CCOBJS) $(CPPOBJS) -o $(TARGET) $(EDLDFLAGS)
	# ./$(TARGET)

%.o: %.cpp
	$(CXX) $(EDCXXFLAGS) -o $@ -c $<

%.o: %.cc
	$(CXX) $(EDCCFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(EDCFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) src/*.o