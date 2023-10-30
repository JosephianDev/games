############ MAKEFILE ############

base_folder := C:/mingw64

g++ := $(base_folder)/bin/g++.exe

include := -I"$(base_folder)/include"
lib := -L"$(base_folder)/lib"

linking := -lopengl32 -lglfw -lglew32 -mwindows
# ALTRE LIBRERIE DA INSERIRE PIU' AVANTI
# -lopenal32 -lws2_32 -lwinmm -lgdi32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lfreetype

cc := $(g++) -c
target := main

all: compile link start

compile:
	$(cc) $(target).cpp $(include)

link:
	$(g++) $(target).o -o $(target) $(lib) $(linking)

start:
	./$(target)

clean:
	rm -f $(target) *.o

#	prova:
#		echo $(include)