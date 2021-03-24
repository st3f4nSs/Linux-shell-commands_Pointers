# Linux-shell-commands_Pointers

1) GREP:
    - am parcurs fiecare linie a matricei(vectorul de pointeri) si am inlocuit toate aparitiile cuvantului
    cautat(citit de la tastatura) cu acelasi cuvant colorat in rosu.

2) CUT:
    - am parcurs fiecare linie a matricei(vectorul de pointeri) am impartit fiecare propozitie in cuvinte
    (functia strtok in functie de delimitatorii ce se gasesc in sirul del) am selectat doar cuvintele care
    au indexul egal cu una dintre valorile din vectorul de int-uri si am afisat outputul dorit.

3) SORT:
    - am sortat liniile matricei in functie de media aritmetica a notelor de pe acea linie(functie de calcul
    a mediei) si am afisat media urmata de notele corespunzatoare.

4) ENCRYPT:
    - am parcurs fiecare linie, am impartit fiecare propozitie(linie) in cuvinte, pe care le-am verificat daca
    sunt numare, in caz afirmativ le afisam, iar daca acele cuvinte nu erau numere le transformam dupa urmatoarea
    regula: ( (cheie + caracter_curent) % 256).
