all: compile run clean

compile:
	g++ main.cpp BST.h BST.cpp linked.h linked.cpp Node.h Node.cpp -o main.out

run:
	./main.out

clean:
	rm -rf ./main.out
