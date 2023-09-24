name ?= graphic

all: compile link

compile:
	g++ -c $(name).cpp -I"../SFML-2.5.1/include" -DSFML_STATIC -o ./output/$(name).o

link:
	g++ ./output/$(name).o -o ./output/$(name) -L"../SFML-2.5.1/lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main
	./output/$(name).exe

clean: 
	del /Q output\$(name).o output\$(name).exe

clean_all:
	del /Q output\*.o output\*.exe
	
