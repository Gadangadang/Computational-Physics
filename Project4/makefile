all: compile execute

compile:
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_c.x CodeBase/main_c.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_d.x CodeBase/main_d.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_e.x CodeBase/main_e.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	g++ -std=c++17 -O3 -fopenmp -Wall -o CodeBase/main_f.x CodeBase/main_f.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -Xpreprocessor -fopenmp -lomp -flto -Wall -o CodeBase/main_g.x CodeBase/main_g.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	# Mac computers needs this instead: -Xpreprocessor -fopenmp -lomp
execute:
	#CodeBase/./main_c.x 100000 10 1.0 2.5 0.05
	#CodeBase/./main_d.x
	#CodeBase/./main_e.x
	CodeBase/./main_f.x 10000 40 2.0 2.5 0.05
	#Codebase/./main_g.x
	#python3 CodeBase/Plotte_code_MB.py
	#python3 CodeBase/plott_code_histo.py
