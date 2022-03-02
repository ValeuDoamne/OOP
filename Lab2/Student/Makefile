
all:
	mkdir -p ./out/
	${CXX} -c -o ./out/Student.o Student.cpp
	${CXX} -c -o ./out/Helper.o Helper.cpp
	${CXX} -c -o ./out/main.o main.cpp
	${CXX} -o ./out/stud ./out/main.o ./out/Helper.o ./out/Student.o
clean:
	rm -rf ./out
