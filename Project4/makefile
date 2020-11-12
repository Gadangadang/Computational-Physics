all: compile execute

compile:
	g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_c.x CodeBase/main_c.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas

execute:
	CodeBase/./main_c.x 10000 2 2.0 1.0 0.01
