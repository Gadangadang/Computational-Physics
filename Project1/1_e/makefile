all: compile execute

compile:
	c++ -O3 -o main.x main2.cpp  -larmadillo -llapack -lblas

execute:
	./main.x 3
	python3 Plotte_code.py
