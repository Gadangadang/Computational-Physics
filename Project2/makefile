all: compile execute

compile:
	#g++ -std=c++11 -O3 -Wall -o main_B.x main_B.cpp classtuff.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++11 -O3 -Wall -o unit.x unittest.cpp classtuff.cpp -larmadillo -llapack -lblas
	g++ -std=c++11 -O3 -Wall -o main_C.x main_C.cpp classtuff.cpp  -larmadillo -llapack -lblas
execute:
	#./main.x_B 1
	#./unit.x
	./main_C.x
	
	#python3 Plotte_code.py
