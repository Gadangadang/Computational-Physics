all: compile execute

compile:
	g++ -std=c++11 -o main.x main.cpp  -larmadillo -llapack -lblas

execute:
	./main.x 3
	python3 Plotte_code.py
