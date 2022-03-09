CXX=g++


all: out main

out:
	mkdir -p ./out/

main: main.o Math.o
	${CXX} -o ./out/main ./out/Math.o ./out/main.o

main.o:
	${CXX} -c -o ./out/main.o main.cc

Math.o:
	${CXX} -c -o ./out/Math.o Math.cc

clean:
	rm -rf ./out/
