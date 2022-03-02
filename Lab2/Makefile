
all:
	mkdir -p ./out/
	${CXX} -c -o ./out/NumberList.o NumberList.cpp
	${CXX} -c -o ./out/main.o main.cpp
	${CXX} -o ./out/NumberList ./out/main.o ./out/NumberList.o
clean:
	rm -rf ./out
