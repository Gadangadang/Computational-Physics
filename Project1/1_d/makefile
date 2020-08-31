all: compile execute

compile:
	c++ -O3 -o main.x main.cpp  -larmadillo -llapack -lblas

execute:
	./main.x 7
	python Plotte_code.py
