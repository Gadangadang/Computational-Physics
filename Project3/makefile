all: compile execute

compile:
	g++ -std=c++11 -O3 -flto -Wall -o main.x main.cpp classtuff.cpp  -larmadillo -llapack -lblas

execute:
	./main.x
	#python3 Plotte_code.py
