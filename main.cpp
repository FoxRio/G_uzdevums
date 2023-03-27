//
// Created by Dāvis Krasts on 27.03.2023.
//

/*Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā,
cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
 Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai),
 kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G18. Uzrakstīt funkciju, kas izmet no saraksta tos elementus, kuriem vērtība vienāda ar to kārtas numuru.*/

#include <iostream>
using namespace std;

struct elem{
    int num;
    elem *next;
};

void pievienot(elem* &first, elem* &last, int el){
    elem* p = new elem;   /// izveido mezglu
    p->num = el;     /// aizpilda ar nolasīto vērtību
    p->next = NULL; /// norāde uz nākošo - tukša!
    if (first == NULL){
/// ja saraksts tukšs
/// gan pirmais, gan pēdējais norāda uz jauno elementu
        first = last = p;
    }
    else{
/// ja saraksts nav tukšs
/// pieliek galā beidzamajam mezglam
        last->next = p;
/// un jaunais kļūst par beidzamo
        last = p;
    }
}

void izdrukat(elem* first){

    for (elem* p = first; p != NULL; p=p->next){
        cout << p->num << endl;
    }
}

void dzest(elem* &first){
/// saraksta iznīcināšana
    elem* p = first;
    while (p!=NULL) {
        first = first->next;
        delete p;
        p = first;
    }}


void izmestVienados(elem* &first){
    int kartasNr = 0;
    for (elem* p = first; p != NULL; p=p->next){
        if(kartasNr == p->num){
            p->next = p->next->next;

        }
    }



}
int main(){
    elem *first=NULL, *last=NULL, *p;
    int i;
    cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
    cin >> i;
/// ievadīšana, kamēr nav sastapta 0
    while (i != 0)
    {
        pievienot(first, last, i);
        cout << "Ievadiet skaitļu virknes elementu (0, ja gribat beigt): " << endl;
        cin >> i;
    };
    izdrukat(first);

    return 0;
}

