all: compile execute

compile:
	#g++ -std=c++17 -O2 -flto -Wall -o main.x main.cpp classtuff.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o main_c.x main_c.cpp object.cpp solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o main_f.x main_f.cpp object.cpp solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o main_g.x main_g.cpp object.cpp solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o main_h.x main_h.cpp object.cpp solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o main_i.x main_i.cpp object.cpp solving.cpp  -larmadillo -llapack -lblas
	g++ -std=c++17 -O2 -flto -Wall -o unit.x unittest.cpp solving.cpp object.cpp -larmadillo -llapack -lblas
execute:
	#./main.x
	#python3 Plotte_code.py
	#./main_c.x
	#./main_f.x
	#./main_g.x
	#./main_h.x
	#./main_i.x
	./unit.x
	python3 Plotte_code_MB.py
