# H19_project2_andergv_orjanstr
Project 2 for andergv (andergv@mail.uio.no) and orjanstr (orjanstr@mail.uio.no)  

For oppgave 1a: g++ array_list.cpp // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1b: g++ array_list.cpp -o test1 // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1c: g++ array_list.cpp -o 1ctest // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1d: g++ array_list.cpp -o 1d // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1e: g++ array_list.cpp -o 1e // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1f: g++ array_list.cpp -o 1f // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1g: g++ array_list.cpp -o 1g // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1h: g++ array_list.cpp -o 1h // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1i: g++ array_list.cpp -o 1i // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 1j: g++ array_list.cpp -o 1j // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)   
For oppgave 2d: g++ array_list.cpp -o 2d // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)   
For oppgave 4c: g++ array_list.cpp -o 4c // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  
For oppgave 4g: g++ array_list.cpp -o 4g // kompilatoren kjørte uten feil (kompilert på Linux Ubuntu)  

Brukte kommandoene under for å sjekke at oppgaven kompilerte for ifi datamskiner. Jeg var koblet til med remote access.  

g++ array_list.cpp -o opg1ificompile -std=c++11
g++ linked_list.cpp -o opg2ificompile -std=c++11
g++ circular_linked_list.cpp -o opg4ificompile -std=c++11

Alle tre filene kompilerte uten feilmeldinger. De tre filene er lagt til repositoriet, og er identiske til henhodsvis 1j, 2d og 4g

Det er ikke kompilert programmer for oppgaver 2a, 2b, 2c, 4a, 4b, 4d, 4e, 4f. Fordi disse oppgavene ikke ber programmet gjøre noe. Jeg har heller kompilert og kjørt kode i oppgavene etter (2d, 4c, 4g) fordi man blir spurt om at programmet skal gjøre noe. Alle oppgavene er besvart og dette vises ved at de kjørbare programmene gjør det oppgaven spør om og at kildekoden er produktet av ALLE deloppgavene.

I oppgave 4g. Med antall mennesker 68, og tellinger 7. Får vi som svar at person nr. 68 overlever. Man kan kjøre "4g" filen for å bekrefte dette, eller kompilere circular_linked_list.cpp som er tilsvarende kildekode.  


TASK 3:

--- LinkedList ---

Get element i by index:
  We only loop through from 0 to i, and the operation inside the loop is not dependent on i, so we have x operations inside a loop of length i. This means that we have a linear algorithm O(i). Note that it is only linear with the index, and not with the actual size of the list.

Insert at front:
  In the insert method, we check to see what index we are working with. We first check i<0 before we get to i == 0. Once we've arrived at i==0, we create a new node n, assign a value to it, set head to n->next and finally making the newly implemented node the new head of the list. These are all operations that are not dependent on the length of the list, nor the size of the index. So here we have a constant cost.

Insert at back:
  Since we use a tail here, we avoid having to loop through the entire list in order to get to the final node. We just perform x amount of operations in the form of if and else, moving some nexts, reassigning the tail. So we actually end up having a constant cost here as well. The cost is not dependent on the index or the size of the list since we only change one node, the tail.

Insert into middle:
  In order to get to a node in the middle (say index i), we unfortunately have to loop through the list. However, once we're there, we only need to perfom x amount of operations in order to insert a new node (just move some nexts basically). So we perform x amount of operations in a loop from 0 to i-1, meaning we have a linear cost here O(i).

Remove from front:
  When removing from front, we basically just set head to become its next node. So first we check if the index is 0, and then we make the second node the head. So that's only a few operations not dependent on n or i. It is a constant cost.

Remove from middle:
  When removing from the middle, we need to loop through the list in order to get to element i, where we will perform a set of x operations. So here we have a linear cost O(i), same as with insert.

Remove from back:
  Here it is the same as removing from the middle, really, only that the index in this case is n, so we get a linear cost O(n).

Print:
  In printing, we obviously need to loop through every single element in the entire list, and printing them together with some brackets before and after the loop. So since we're looping through the entire thing, printing along and updating current along the way (operations which are not dependent on the size of the list), we end up with a linear cost.

--- ArrayList ---

Get element i by index:
  Here we only do a few checks to see if the index actually fits, and return data[i] if it does. The amount of operations here does not depend on the size of the list, nor the desired index. We have a constant cost.

Insert at front:
  When inserting in the front, we need to increase the size of the allocated space, and then push every element one "notch" to the right. So we need to actually loop through the entire list and move every element one by one. At least that's what we chose to do. So in our case, we have a linear cost, dependent on the size of the list. O(n).

Insert at back:
  The actual insertion here is not dependent on the size of the list, but we have a special case where we don't have enough allocated space, so we need to resize. This resize method loops through the entire list, copying element by element to a temporary list. So we have two cases here. If we have enough allocated space available: We just add another element to the end, meaning we have a constant cost. If we don't have enough allocated space, we will need to resize, meaning we need to loop through the entire list. So in this case we have a linear cost O(n).

Remove from front:
  When removing an element from the front, we need to push all the other elements one notch to the left, meaning that we need to loop through the entire list. So where we have a linear cost dependent on the size of the list O(n).

Remove from middle:
  Removing from the middle is pretty much the same as removing from the front, except that we don't move as many elements. The cost is, however, still dependent on the length of the list (since we need to loop through n - i elements). So again we have a linear cost O(n).

Remove from back:
  When removing from the back, we use out shrink to fit method, which loops through the list, copying element by element in the same fashion as the resize method. So once again we have a linear cost dependent on the size of the list O(n).

print:
  Printing is the same as always, a loop that goes through every element and prints it. A linear cost O(n).
