@ECHO OFF
REM Variables relevant to the compilation of the program.
SET CXX=g++
SET COBJS=src/main.cpp src/Conditions.cpp src/Display.cpp src/Engine.cpp src/Parachute.cpp src/Simulation.cpp src/ui.cpp src/Vehicle.cpp
SET CXXFLAGS=-I ./include/ -Wall
SET TARGET=RocketrySuite.exe

REM This run a command-prompt command to compile using G++.
ECHO Compiling %COBJS% into %TARGET% using %CXX% with %CXXFLAGS% flag(s)...
CMD /c "%CXX% %CXXFLAGS% %COBJS% -o %TARGET%"

PAUSE

REM This will run the executable automatically.
START %TARGET%