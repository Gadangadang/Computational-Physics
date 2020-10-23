# Project 3

Here are the instructions for operating the numerical machinery.

## preamble: 
Due to the nature of the solution there are different mains for different tasks. This is because our solver class is very general, and therefore requires specialized input for different solutions. Therefore, all code is inside the 'CodeBase' folder and you will execute the different aspects by editing and running the makefile. Its intended to run only one main_X at a time. We have not tested with multiple mains, but it should work.

### Makefile setup
The contents of the makefile look like this:
```
compile:
  	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_a.x CodeBase/main_a.cpp CodeBase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_c.x CodeBase/main_c.cpp CodeBase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_f.x CodeBase/main_f.cpp Codebase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_g.x CodeBase/main_g.cpp CodeBase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_h.x CodeBase/main_h.cpp CodeBase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/main_i.x CodeBase/main_i.cpp CodeBase/object.cpp CodeBase/solving.cpp  -larmadillo -llapack -lblas
	#g++ -std=c++17 -O2 -flto -Wall -o CodeBase/unit.x CodeBase/unittest.cpp CodeBase/solving.cpp CodeBase/object.cpp -larmadillo -llapack -lblas
execute:
	#CodeBase/./main_a.x
	#python3 CodeBase/Plotte_code.py
	#CodeBase/./main_c.x
	#CodeBase/./main_f.x
	#CodeBase/./main_g.x
	#CodeBase/./main_h.x
	#CodeBase/./main_i.x
	#CodeBase/./unit.x
	#python3 CodeBase/Plotte_code_MB.py
```
### Instructions for running code
a makefile comment is a '#' character. to run the makefile open a terminal and type 'make all' to execute.

To run task a):
  - uncomment the main_a line under the 'compile' section
  - uncomment the main_a.x line under the 'execute' section
  - uncomment the Plotte_code.py line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section
 
Expected result for a):
 - there should be a plot for the Earth-Sun-system solved using the Forward-Euler
 - there should be a more accurate plot of the same system using the Velocity-Verlet-solver
  
  
To run task c):
  - uncomment the main_c line under the 'compile' section
  - uncomment the main_c.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section
 
Expected result for c):
 - there should be a plot for the Earth-Sun-system 
 - Testing for the tdelta times were done manually by changing the 'IntegrationPoints' value in line 25 in main_c.cpp


To run task d):
  - uncomment the main_c line under the 'compile' section
  - uncomment the main_c.x line under the 'execute' section

Expected result for d):
- there will be a print called 'Area of the first time-interval' and 'Area of the second time interval' these are computations of Keplers law.
- Example Run: "Area of the first time interval is =9.85778, Area of the second time interval is =9.91112"


To run task e):
  - uncomment the main_e line under the 'compile' section
  - uncomment the main_e.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section

Expected result for e):
  - There should be a plot of the orbit, and a printed statement saying Beta = 3.


To run task f):
  - uncomment the main_f line under the 'compile' section
  - uncomment the main_f.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section

Expected result for f):
- There should be a plot of the planet exiting the system
- There should be a print called 'V_esc' which is the display velocity  
- Example Run "V_esc = 8.88577"


To run task g):
  - uncomment the main_g line under the 'compile' section
  - uncomment the main_g.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section

Expected result for g):
  - A plot showing the orbits of jupyter and Earth around the Sun.


To run task h):
  - uncomment the main_h line under the 'compile' section
  - uncomment the main_h.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section

Expected result for h):
  -  A plot showing the orbits of all the planetary objects.


To run task i):
  - uncomment the main_i line under the 'compile' section
  - uncomment the main_i.x line under the 'execute' section
  - uncomment the Plotte_code_MB.py line under the 'execute' section

Expected result for i):
  - A plot of Mercury orbiting the Sun
  - A print of the change in degrees after a century as "Perihilion angle = "
  - Example Run: "Perihilion angle =-1.02577"

#### Example Use
As mentioned previously, we have an object class which mostly stores variables, and one function, but the solver class is the biggest part of the project, and this section will be devoted to showing how to use the class, and an example derived from a), which solves for an Earth-Sun orbit, which also fixes the Sun at origo.

There are two different solvers in the class, but this example will focus on the Verlet function because its the one in use most of the time, and the Euler solver is built to the same spec. The Verlet function has eight different parameters that govern how it operates. A user calls only the solver.add function, to load the planets, and the solver function. Everything else is done 'behind the scenes'. The Verlet parameters are:
- int dimension: sets the dimension of the solution. It should stay at 3
- int integration_points: Number of integration points
- double final_time: the number of years to simulate. Should be given as a whole number
- int print_number: ??
- double epsilon: ??
- double beta: The Beta variable given in 3e) to variate gravity force. Should stay as 2
- int fixed: Should be 0 for fixing the Sun in origo, otherwise 1 to simulate the center of mass at origo.
- int alpha: input 1 to add the extra relativistic considerations given in i), otherwise it should be 0.

```
int main(int argc, char const *argv[]) {

  int Dimension = 3;


  int IntegrationPoints = 15000;
  double FinalTime = 150.0;

  double earth_mass = 3.003e-6;
  double sun_mass = 1.0;

  vec pos(3); pos = {1,0,0};

  double beta = 2;
  int alpha =0;
  cout << "Beta " << beta << endl;

  object planet1(earth_mass,1.,0.0,0.0,0,6.3,0);
  object planet2(sun_mass, 0,0,0,0,0,0);

  solving binary_forward;
  binary_forward.add(planet1); binary_forward.add(planet2);
  binary_forward.VelocityVerlet(Dimension,IntegrationPoints,FinalTime,1,0., beta,0,alpha);
  return 0;
}


```