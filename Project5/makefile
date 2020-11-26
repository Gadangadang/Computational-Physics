all: compile execute

compile:
	g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_a.x CodeBase/main_a.cpp CodeBase/Finance.cpp   -larmadillo -llapack -lblas
execute:
	CodeBase/./main_a.x
	python3 Codebase/Variance.py
	python3 Codebase/histo.py
