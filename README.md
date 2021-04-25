# lanParty

	Aplicatia organizeaza echipele participante ale unui concurs, creeaza jocuri, le afiseaza
	in fisiere dupa care scrie castigatorii in fisiere pe care ii rearanjeaza in alte jocuri.
	Procedura se repeta pana ramane o echipa care e desemnata castigatoare.
	Structuri de date folosite: arrays, lists, queue, maps, stacks

Functia main se afla in fisierul lanParty.cpp. Prima data deschid fisierele de care ma folosesc.
Citesc din fisierul cerinta cerintele in variabila cc in care am alocat spatiu de 5*sizeof(int).
Verific daca fisierele au fost deschise corect. Am facut cate un if pentru fiecare cerinta.
	
Citirea din fisierul d.in  se face la crearea listei de echipe.
In constructorul care primeste parametru fisierul de intrare citesc numarul de echipe dupa care
folosind un for creez obiecte de tip Team.
In constructorul clasei Team am implementat citirea informatiilor necesare pentru creareea unei
echipe. Adica numele echipei, numarul de playeri, numele playerilor si punctele fiecarui player.

In restul programului am folosit aceleasi echipe create la cerinta 1 la citirea din fisier fara
a aloca memorie pentru altele si a le copia. Adica lucrez cu aceleasi zone de memorie.Exceptie face
cand raman cu 8 echipe in stiva de castigatori. In acest caz creez o alta lista in care copiez
informatia echipelor din stiva de castigori. Am facut acest lucru deoarece daca nu o faceam echipele
ar fi fost sterse si nu mai puteam sa continui cu restul rundelor si de asemenea nu as mai fi putut
folosi arborii deoarece nu aveam cu ce echipa.

In clasa Team am adaugat pe langa pointeri catre echipa urmatoare si vectorul de playeri alocat
dinamic si numarul de playeri din echipa si o variabila pentru stocarea punctelor echipei. Am facut
acest lucru deoarece este mai eficient decat daca as fi trecut prin vectorul de playeri si sa fac
media aritmetica a punctelor playerilor de fiecare daca cand aveam  nevoie de punctele echipei. Mai
ales ca la arbori folosesc foarte mult comparatia de puncte.

Ma folosesc de pointerul de tip List: cap_Delete pentru a memora memoria primului nod in cazul
in care acesta se afla printre echipele eliminate. Daca da il sterg.

In Coada nu am implementat pointeri catre tail si head dar am respectat principiul FIFO al cozii
pe care l-am invatat la SDA anul trecut.

Nu am implementat destructori decat la acele clase la care era nevoie.
In destructorii de la List, Stiva si Coada nu am sters memoria echipei deoarece am specificat
mai sus ca folosesc aceleasi echipe create in cerinta 1.

Fac eliberarea memoriei ale nodurilor stivelor si cozii dupa citirea fiecarui nod.
La cerinta 3 apelez functiile create in lanParty.cpp: playRound() si write_Stiva, pe care le explic
mai jos, pentru a se juca meciurile si pentru si afisarea lor cat si a stivelor in fisier. Folosindu-ma
de ultimul parametru verific daca stiva data ca parametru este de castigatori caz in car o afisez si
creez noile meciuri in coada dupa care sterg nodurile iar daca stiva e de pierzatori sterg si meciurile 
si nodurile.

Nu am creat clasa diferita pentru meciuri deoarece am considerat un meci un nod al cozii prin
definirea de 2 atribute de tip pointeri la obiecte de tip Team, acestea formand un meci.

Pentru cerinta 4 m-am folosit de lista create cu cele 8 echipe create la cerinta 3.

Ordinea de adaugare in arborele AVL este aceeasi ordine in care am afisat TOP 8 echipe. Am facut acest
lucru astfel: la afisarea arborelui BST am creat o lista pentru AVL in care le-am pus in ordine astfel
ca la crearea arborelui AVL adaugarea a fost facuta in ordinea perfecta.
