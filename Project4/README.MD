# Project 4

Here are the instructions for operating the numerical machinery.

## preamble:
Due to the nature of the solution there are different mains for different tasks. This is because our solver class is very general, and therefore requires specialized input for different solutions. Therefore, all code is inside the 'CodeBase' folder and you will execute the different aspects by editing and running the makefile. Its intended to run only one main_X at a time. We have not tested with multiple mains, but it should work.

To run main_f.x, you will need to have OpenMP installed. More information on OpenMP can be found at https://openmp.llvm.org/ and https://www.openmp.org/. 

For unix operating systems this can be done using homebrew:
```
brew install libomp
```
When compiling with OpenMP, iOS differs from other unix based operating systems, as well as Windows. 

For Windows/Linux:
```
g++ -fopenmp -o test.cpp
```

For iOS:
```
g++ -Xpreprocessor -fopenmp -lomp -o test.cpp
```

### Makefile setup
The contents of the makefile look like this:
```
all: compile execute

compile:
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_c.x CodeBase/main_c.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_d.x CodeBase/main_d.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -flto -Wall -o CodeBase/main_e.x CodeBase/main_e.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O3 -fopenmp -Wall -o CodeBase/main_f.x CodeBase/main_f.cpp CodeBase/solver.cpp   -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/unit.x CodeBase/Unittest.cpp CodeBase/solver.cpp -larmadillo -llapack -lblas
	# Mac computers needs this instead: -Xpreprocessor -fopenmp -lomp
execute:
	#CodeBase/./main_c.x
	#CodeBase/./main_d.x
	#CodeBase/./main_e.x
	#CodeBase/./main_f.x
	#CodeBase/./unit.x
	#python3 CodeBase/plot_ac.py
	#python3 CodeBase/plott_code_histo.py
	#python3 Codebase/tcfind.py
```
### Instructions for running code
a makefile comment is a '#' character. to run the makefile open a terminal and type 'make all' to execute.

To run task c):
  - uncomment the main_c line under the 'compile' section
  - uncomment the main_c line under the 'execute' section

Expected result for c):
  - 


To run task d):
  - uncomment the main_d line under the 'compile' section
  - uncomment the main_d line under the 'execute' section

Expected result for d):



To run task e):
  - uncomment the main_e line under the 'compile' section
  - uncomment the main_e line under the 'execute' section
 
Expected result for e):
  


To run task f):
  - uncomment the main_f line under the 'compile' section
  - uncomment the main_f line under the 'execute' section

Expected result for f):



To run task g):
  - uncomment the main_f line under the 'compile' section
  - uncomment the main_f.x line under the 'execute' section
  - uncumment the tcfind.py line under the 'execute' section

Expected result for g):
  - Plot showing the heat capacity as function of temperature for L = 40 with a univariate spline interpolation
  - Plot showing the heat capacity as function of temperature for L = 60 with a univariate spline interpolation
  - Plot showing the heat capacity as function of temperature for L = 80 with a univariate spline interpolation
  - Plot showing the heat capacity as function of temperature for L = 100 with a univariate spline interpolation
  - Plot showing the univariate spline interpolation functions for all four L grids as function of temperature
  - Terminal statement with residue for the four interpolation functions
  - Critical temperature for L = &infin;


#### Example Use


```

```


General example for an 
```



```
