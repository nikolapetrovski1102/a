#include <iostream>
#include <string>
using namespace std;
struct Jazol
{
string info;
Jazol* next; //pokazhuvach kon sledbenikot
Jazol* prev; //pokazhuvach kon prethodnikot
};
struct Lista
{
Jazol* head;
Jazol* tail; //za da go pamtime krajot
int brel;
void init();
void kreirajLista(int el);
void dodadiPrv(string el);
void dodadiPosleden(string el);
void brishiPrv();
void brishiPosleden();
void brishiNaPozicija(int poz);
void brishiLista();
void rotate_clockwise(int n);

void pechati();
string citajNaPozicija(int poz);
};
void Lista::init()
{
 head = tail = NULL; //kreirame prazna lista, bez jazli
 brel = 0;
}
void Lista::kreirajLista(int el)
{
Jazol* nov = new Jazol;
 nov->info = el;
 nov->next = nov->prev = nov; //jazolot pokazhuva kon sebe
 tail = head = nov;
 brel = 1;
}
void Lista::dodadiPrv(string el)
{
Jazol* nov = new Jazol;
 nov->info = el;
if (head == NULL) //ako listata ne sodrzhi elementi
 {
 nov->next = nov->prev = nov; //jazolot pokazhuva kon sebe
 tail = head = nov;
 }
else
 {
 //formirame 4 vrski
 nov->next = head;
 head->prev = nov;
 head = nov;
 tail->next = head;
 head->prev = tail;
 }
 brel++;
}
void Lista::dodadiPosleden(string el)
{
Jazol* nov = new Jazol;
 nov->info = el;
if (head == NULL) //ako listata ne sodrzhi elementi
 {
 nov->next = nov->prev = nov; //jazolot pokazhuva kon sebe
 tail = head = nov;
 }
else
 {
 //formirame 4 vrski
 tail->next = nov;
 nov->prev = tail;
 tail = nov;
 tail->next = head;
 head->prev = tail;
 }
 brel++;
}
void Lista::brishiPrv()
{
if (head->next == head)
 {
 delete head;
 head = tail = NULL;
 }
if (head != NULL)
 {
 tail->next = head->next; //krajot na listata pokazhuva kon vtoriot jazol

 head->next->prev = tail; //vtoriot jazol pokazhuva kon posledniot
 delete head; //osloboduvame memorija za posledniot jazol

 head = tail->next;//pochetok stanuva vtoriot jazol
 brel--;
 }
}
void Lista::brishiPosleden()
{
if (head->next == head)
 {
 delete head;
 head = tail = NULL;
 }
if (head != NULL)
 {
 tail->prev->next = head; //pretposledniot jazol (tail->prev) pokazhuva kon
 head->prev = tail->prev;//prviot pokazhuva kon pretposledniot jazol
 delete tail; //osloboduvame memorija za prviot jazol
 tail = head->prev; //kraj stanuva pretposledniot jazol
 brel--;
 }
}
void Lista::brishiNaPozicija(int poz) //prviot element e na pozicija 1
{
if (poz > 0 && poz <= brel)
 {
 if (poz == 1) brishiPrv();
 else if (poz == brel) brishiPosleden();
 else
 {
 Jazol* pom = head;
 for (int i = 1; i < poz; i++)
 pom = pom->next; //go dvizhime pokazhuvachot duri ne se
 //pozicionira na jazolot
 pom->next->prev = pom->prev;
 pom->prev->next = pom->next;
 delete pom;
 brel--;
 }
 }
}
string Lista::citajNaPozicija(int poz) //prviot element e na pozicija 1
{
if (poz >= 0 && poz < brel)
 {
 Jazol* pom = head;
 for (int i = 0; i < poz; i++) {
 pom = pom->next;
 }
 return pom->info;
 }
}
void Lista::brishiLista()
{
while (head != NULL)
 brishiPosleden();
}
void Lista::pechati()
{
Jazol* pom = head;
if (head != NULL)
 do
 {
 cout << pom->info << '\t';
 pom = pom->next;
 } while (pom != head);
else { cout << "Listata e prazna"; }
 cout << endl;
}

void Lista::rotate_clockwise(int n)
{
    for (int i = 0; i < n; i++){
        head = head->next;
        tail = tail->next;
    }
}

int main()
{
    Lista lista;
    lista.init();
    
    lista.dodadiPosleden("a");
    lista.dodadiPosleden("b");
    lista.dodadiPosleden("c");
    lista.dodadiPosleden("d");
    lista.dodadiPosleden("e");
    lista.dodadiPosleden("f");
    lista.dodadiPosleden("g");
    lista.dodadiPosleden("h");
    
    lista.pechati();
    
    int n;

    cin >> n;
    
    lista.rotate_clockwise(n);
    
    lista.pechati();
    
    return 0;
}
