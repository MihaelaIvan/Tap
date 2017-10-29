#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int tata[100],viz[100],colorat[100],grad[100];
vector<int> *lista_ad;
int exista(int n)
{
    int i;
    for(i=1; i<=n; i++)
        if(grad[i]==1)
            return 1;
    return 0;
}
void DF(int nod)
{
    viz[nod]=1;
    for(int j=0; j<lista_ad[nod].size(); j++)
    {
        int p=lista_ad[nod][j];
        if(viz[p]==0)
        {
            tata[p]=nod;
            DF(p);
        }
    }
}

int main()
{
    ifstream f("date.in");
    int nr_noduri,nr_muchii,i,x,y;
    f>>nr_noduri;
    nr_muchii=nr_noduri-1;
    cout<<"Nr de noduri este:"<<nr_noduri<<endl;
    lista_ad=new vector<int>[nr_noduri+1];
    ///citire date de intrare
    for(i=1; i<=nr_muchii; i++)
    {
        f>>x>>y;
        lista_ad[x].push_back(y);
        lista_ad[y].push_back(x);
        ///se creaza un vector de grad in care se memoreaza pt ficare nod gardul sau
        grad[x]++;
        grad[y]++;
    }
    ///Afisare
    cout<<"Vecinii fiecarui nod sunt:"<<endl;
    for(i=1; i<=nr_noduri; i++)
    {
        cout<<i<<":";
        for(int j=0; j<lista_ad[i].size(); j++)
            cout<<lista_ad[i][j]<<" ";
        cout<<endl;
    }
    int rad;
    rad=1;
    ///se face o parcurgere DF pt a se crea vectorul de tatal frunzei
    DF(rad);
    int index=0,start;
    int neadiacente[100];///in acest vector se memoreaza multimea de puncte neadiacente
    start=index;
    for(i=1; i<=nr_noduri; i++)
        if(grad[i]==1)///adaug primele frunze
        {
            neadiacente[index]=i;
            index++;
            grad[i]=-1;///il marchez cu -1 adica il sterg
        }
    for(i=start;i<index;i++)///verific in nodurile deja adaugate
        {

            if(grad[tata[neadiacente[i]]]!=-1)///daca gardul tatalui este dif de -1 inseamna ca nu a mai fost sters si pot scadea 1 din tatal sau(pt a nu scadea de mai multe ori pt un fiu)
                grad[tata[tata[neadiacente[i]]]]--;
            grad[tata[neadiacente[i]]]=-1;///acum sepoate sterge tatal frun
         }
    start=index;
    while(exista(nr_noduri)==1)
    {
        for(i=1; i<=nr_noduri; i++)
            if(grad[i]==1)///adaug primele frunze
            {
                neadiacente[index]=i;
                index++;
                grad[i]=-1;///il marchez cu -1 adica il sterg
            }
        for(i=start;i<index;i++)///pt nodurile neadiacente
        {

            if(grad[tata[neadiacente[i]]]!=-1)///daca gardul tatalui este dif de -1 inseamna ca nu a mai fost sters si pot scadea 1 din tatal sau(pt a nu scadea de mai multe ori pt un fiu)
                grad[tata[tata[neadiacente[i]]]]--;
            grad[tata[neadiacente[i]]]=-1;///acum il pot "sterge" marchez cu -1
         }
         start=index;

    }
    ///cazul in care prin stergere radacina ramane un nod izolat ea trebuia adaugata la multimea de puncte neadiacente
   if(grad[rad]==0)
   {
       neadiacente[index]=rad;
       index++;
   }
   cout<<"Nr maxim de varfuri neadiacente este:"<<index<<endl;
   cout<<"Multimea este:";
    for( i=0; i<index; i++)
        cout<<neadiacente[i]<<" ";

    return 0;
}
