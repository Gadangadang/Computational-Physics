all: compile execute

compile:
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_a.x CodeBase/main_a.cpp CodeBase/Finance.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_c.x CodeBase/main_c.cpp CodeBase/Finance.cpp   -larmadillo -llapack -lblas
	g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_d.x CodeBase/main_d.cpp CodeBase/Finance.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_e.x CodeBase/main_e.cpp CodeBase/Finance.cpp   -larmadillo -llapack -lblas

execute:
	#CodeBase/./main_a.x
	#CodeBase/./main_c.x
	CodeBase/./main_d.x
	#CodeBase/./main_e.x
	python3 Codebase/Variance.py
	python3 Codebase/histo.py
	python3 Codebase/Omega.py
	#python3 Codebase/diff_savings.py
