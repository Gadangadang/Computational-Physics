Grade: Passed

### Part 1
I readme gir dere instrukser til å kompilere samme fil til mange forskjellige
navn. Litt forvirret hva dette oppnår. Kompileringen på remote derimot
virker mer fornuftige.

I remove så må dere throw error hvis i < 0 eller i>= size, fordi da prøver man å
fjerne noe som er utenfor listen. Dere trenger også ikke calle shrink i pop, siden
denne calles allerede av remove.

Print er litt rart implementert, den burde bare printe de size første elementene,
ikke capacity.

Insert må calle resize i tilfellet size = capacity, eller blir det ikke nok
plass.

I remove er det ikke riktig å starte på data[i-1]

Flere av testene deres ser ikke ut til å fungere.

### Part 2

Dette var et helt annet dyr. Supert gjort

### Part 3
Supert, fint om dere skriver O(1) istedet for constant cost. På insert middle
kan man også skrive O(n/2) = O(n), men jeg forstår hva dere mener med O(i)

### Part 4

Supert.

### Other
Med unntak av oppgave 1 er alt gjort supert. Flott innsats. Husk å ikke legge
ved compilerte filer. Kall dem gjerne program.o når dere kompilerer, og legg til *.o i git ignore
