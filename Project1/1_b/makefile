all: compile execute

compile:
	c++ -O3 -o main.x main.cpp  -larmadillo -llapack -lblas

execute:
	./main.x 4
	python3 Plotte_code.py
