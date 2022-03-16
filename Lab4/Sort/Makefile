CXX=g++

all: dir main 

clean:
	rm -rf ./out

dir:
	mkdir -p ./out


main: main.o Sort.o
	${CXX} -o ./out/main ./out/main.o ./out/Sort.o

main.o:
	${CXX} -c -o ./out/main.o main.cpp

Sort.o:
	${CXX} -c -o ./out/Sort.o Sort.cpp
