srcs := main.cc garage/bembeu.cc garage/dacia.cc garage/mercedes.cc garage/toyota.cc 
blddir := bld 
objs := $(addprefix $(blddir)/,$(srcs:.cc=.o))
exe := $(blddir)/main


CCX=g++
CCXFLAGS=-ggdb

.PHONY: all clean

all: dir main

dir:
	mkdir -p out/garage 

main: garage circuit main.o
	$(CXX) $(CCXFLAGS) -o out/main out/main.o out/Circuit.o ./out/garage/bembeu.o ./out/garage/dacia.o ./out/garage/mercedes.o ./out/garage/toyota.o ./out/garage/cazan.o ./out/garage/mazda.o ./out/garage/ford.o 


garage: bembeu dacia mercedes toyota cazan ford mazda

circuit:
	$(CCX) $(CCXFLAGS) -c -o out/Circuit.o Circuit.cc

bembeu:
	$(CCX) $(CCXFLAGS) -c -o out/garage/bembeu.o garage/bembeu.cc

dacia:
	$(CCX) $(CCXFLAGS) -c -o out/garage/dacia.o garage/dacia.cc

mercedes:
	$(CCX) $(CCXFLAGS) -c -o out/garage/mercedes.o garage/mercedes.cc
toyota:
	$(CCX) $(CCXFLAGS) -c -o  out/garage/toyota.o garage/toyota.cc

cazan:
	$(CCX) $(CCXFLAGS) -c -o  out/garage/cazan.o garage/cazan.cc
ford:
	$(CCX) $(CCXFLAGS) -c -o out/garage/ford.o garage/ford.cc

mazda:
	$(CCX) $(CCXFLAGS) -c -o out/garage/mazda.o garage/mazda.cc

main.o:
	$(CCX) $(CCXFLAGS) -c -o out/main.o main.cc

clean:
	rm -rf out
