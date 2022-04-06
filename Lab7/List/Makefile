
CCX=g++

all: out main 

clean:
	rm -rf ./out

out:
	mkdir -p ./out

main: main.o
	$(CCX) -o ./out/main ./out/main.o
main.o: 
	$(CCX) -c -o ./out/main.o main.cc
