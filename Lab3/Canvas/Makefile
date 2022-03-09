
all: dir main

dir:
	mkdir -p ./out/

main: main.o Canvas.o
	${CXX} -o ./out/main ./out/main.o ./out/Canvas.o

main.o:
	${CXX} -c -o ./out/main.o main.cc

Canvas.o:
	${CXX} -c -o ./out/Canvas.o Canvas.cpp

clean:
	rm -rf ./out/
