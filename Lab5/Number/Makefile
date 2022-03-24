CXX=g++

all: dir main 

clean:
	rm -rf ./out

dir:
	mkdir -p ./out

main: Number.o main.o
	${CXX} -o ./out/main ./out/main.o ./out/Number.o

main.o:
	${CXX} -c -o ./out/main.o main.cc
Number.o:
	${CXX} -c -o ./out/Number.o Number.cc
