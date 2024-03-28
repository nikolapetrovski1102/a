#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
struct jazol {
int info;
jazol *link;
};
struct KLista {
jazol *head;
jazol *tail;
void init(){
 head = tail = NULL;
 }
void dodadiPrv(int x){
 jazol *nov = new jazol;
 nov->info = x;
 if(head == NULL){
 nov->link = nov;
 head = tail = nov;
 return;
 }
 nov->link = head;
 tail->link = nov;

 head = nov;
 }
void dodadiPosleden(int x){
 jazol *nov = new jazol;
 nov->info = x;
 if(head == NULL){
 nov->link = nov;
 head = tail = nov;
 return;
 }
 nov->link = head;
 tail->link = nov;
 tail = nov;
 }
void brishiPrv(){
 if(head == NULL){
 return;
 }
 if(head == tail){
 delete head;
 head = tail = NULL;
 return;
 }
 jazol *pom = head;
 tail->link = head->link;
 head = head->link;
 delete pom;
 }
void brisiPos(){
 if(head == NULL)
 return;
 if(head == tail){
 delete head;
 head = tail = NULL;
 return;
 }
 jazol *pom = tail;
 jazol *dvizi = head;
 while(dvizi->link != tail)
 dvizi = dvizi->link;
 dvizi->link = head;
 tail = dvizi;
 delete pom;
 }
void brishiLista(){
 while(head != NULL)
 brishiPrv();
 }

void pechati(){
 if(head == NULL)
 return;
 jazol *dvizi = head;
 while(dvizi != tail){
 cout<<"|"<<dvizi->info<<"|->";
 dvizi = dvizi->link;
 }
 cout<<"|"<<tail->info<<"|"<<endl;
 }
void brisiJazol(jazol *pom){
 if (pom == NULL)
 return;
 if(pom->link == NULL){
 return;
 }
 jazol *izol = pom->link;
 if (izol == head)
 brishiPrv();
 else if (izol == tail)
 brisiPos();
 else {
 pom->link = izol->link;
 delete izol;
 }
 }
void duplirajJazol(jazol *pom){
 if(pom == head){
 dodadiPrv(head->info);
 return;
 }
 jazol *dvizi = head;
 while(dvizi->link!=pom){
 dvizi = dvizi->link;
 }
 jazol *nov = new jazol;
 nov->info = pom->info;
 nov->link = pom;
 dvizi->link = nov;
 }
};

    KLista promeni(KLista& l1, KLista& l2){
        // Ni treba brojac za da ja izminvame pomalata lista
        int brojac = 0;
        KLista isti, neIsti;
        isti.init();
        neIsti.init();

        // 10 2 5 7 13
        // 5 2 7 7
        // Ako brojacot vrti do 5 ke se sporeduva 13 so 5 posto e kruzna lista
        // 10 
        while (brojac != 4){
            if (l1.head->info == l2.head->info){
                isti.dodadiPosleden(l1.head->info); //duplicate
            }
            else{
                neIsti.dodadiPosleden(l2.head->info);
            }
            isti.dodadiPosleden(l1.head->info); // keep
            l1.head = l1.head->link;
            l2.head = l2.head->link;
            brojac++;
        }

        // se dodava poseldnata brojka sto ostanala
        isti.dodadiPosleden(l1.head->info);

        l1.brishiLista();
        l2.brishiLista();

        l1 = isti; // vrednostite na isti ke bidat vrednostite na l1
        l2 = neIsti; // vrednostite na isti ke bidat vrednostite na l1

    }

int main(){
KLista L1, L2;
L1.init();
L2.init();
L1.dodadiPrv(10);
L1.dodadiPosleden(2);
L1.dodadiPosleden(5);
L1.dodadiPosleden(7);
L1.dodadiPosleden(13);
L2.dodadiPosleden(7);
L2.dodadiPrv(7);
L2.dodadiPrv(2);
L2.dodadiPrv(5);
promeni(L1, L2);
L1.pechati();
L2.pechati();
L1.brishiLista();
L2.brishiLista();
return 0;
}
