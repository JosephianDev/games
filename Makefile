############ MAKEFILE ############

base_folder := C:\\

g++ := $(base_folder)mingw64/bin/g++.exe

include := -I"$(base_folder)OpenGL\include"
lib := -L"$(base_folder)OpenGL\lib"

linking := -lopengl32 -lws2_32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lfreetype -lwinmm -lgdi32 -mwindows

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