all: compile execute

compile:
	g++ -std=c++11 -O3 -Wall -o main.x main.cpp classtuff.cpp  -larmadillo -llapack -lblas
	g++ -std=c++11 -O3 -Wall -o unit.x unittest.cpp classtuff.cpp -larmadillo -llapack -lblas
execute:
	./main.x 1
	./unit.x
	#python3 Plotte_code.py
