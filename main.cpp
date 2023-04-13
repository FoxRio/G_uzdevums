
/*Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
 Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai),
 kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G18. Uzrakstīt funkciju, kas izmet no saraksta tos elementus, kuriem vērtība vienāda ar to kārtas numuru.*/

//Autors: Dāvis Krasts, dk22052
// Izveidots: 05.04.2023
#include <iostream>
using namespace std;

struct elem{
    int num;
    elem *next;
};
/*
 * void pievienot(elem* &first, elem* &last, int el);
 *  Funkcija pievienot(&first, &last, el)-
 *  pievieno saistītā saraksta , kas norādīts ar first un last, beigās jaunu elementu ar vērtību el
 *
 *
 * */
void pievienot(elem* &first, elem* &last, int el){
    elem* p = new elem;
    p->num = el;
    p->next = NULL;
    if (first == NULL){
        first = last = p;
    }
    else{ // ja saraksts nav tukšs
        last->next = p;
        last = p;
    }
}
/*
 * void izdrukat(elem* first);
 * Funkcija izdrukat(first)-
 * izdrukā saistīto sarakstu uz kura sākumu norāda first.
 * */
void izdrukat(elem* first){
    if(first){
        for (elem* p = first; p != NULL; p=p->next){
            cout << p->num << ' ';
        }
        cout << endl;}
    else{
        cout << "ir tukšs!" << endl;
    }
}
/*
 * void dzest(elem* &first);
 * Funkcija dzest(&first)-
 * Izdzēš saistīto sarakstu uz kuru norāda first.
 * */
void dzest(elem* &first){
    elem* p = first;
    while (p!=NULL) {
        first = first->next;
        delete p;
        p = first;
    }}

/* void izmestVienados(elem* &first);
 * Funkcija izmestVienados(&first)-
 *  no saistītā saraksta, uz kura sākumu norāda first izmet tos elementus,
 *  kuru kārtas numurs ir vienāds ar elementā saglabāto vērtību
 * */
void izmestVienados(elem* &first){
    int kartasNr = 0;
    while (first and first->num == kartasNr) { // Dzēšana, ja jādzēš virkens pirmais elements
        elem *temp = first;
        first=first->next;
        delete temp;
        temp = NULL;
        kartasNr++;
    }
    if (first == NULL){
        return;
    }
    elem *p=first;
    kartasNr++;
    elem *nakamais = p->next;
    while (nakamais) {
        while(nakamais and nakamais->num!= kartasNr) {
            p=p->next;
            nakamais=nakamais->next;
            kartasNr++;
        }
        if (nakamais!=NULL) {
            p->next = nakamais->next;
            delete nakamais;
            nakamais=p->next;
            kartasNr++;
        }
    }
}


int main(){
    int ok;

    do{
        elem *first=NULL, *last=NULL, *p;
        int i;
        cout << "Ievadiet skaitļu virknes elementu (-1, ja gribat beigt): " << endl;
        cin >> i;

        while (i != -1)// ievadīšana, kamēr nav sastapts -1
        {
            pievienot(first, last, i);
            cout << "Ievadiet skaitļu virknes elementu (-1, ja gribat beigt): " << endl;
            cin >> i;
        }
        cout << "Sākotnējais saraksts: ";
        izdrukat(first);
        izmestVienados(first);
        cout << endl<< "Iegūtais saraksts: ";
        izdrukat(first);
        dzest(first);
        cout << " Vai turpināt (1) vai beigt (0)?" << endl;

        cin >> ok;

    } while (ok == 1);
    return 0;
}

/*                                      TESTA PLĀNS
 *
 *            Ievade                        Sagaidītais rezultāts
 *
 *          0 1 2 3 4                           Tukšs saraksts!
 *
 *          1 1 2 3 4                               1
 *
 *          0 1 33 3 4 4                            33 4
 *
 *          2 4 6 9 11                              2 4 6 9 11
 * */


