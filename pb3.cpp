#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;
struct curs
{
    int start,fin,index;
};

struct sala{
    int id,disp;
};
int nr_sali = 0;
///functia de comparare care ajuta la sortare
int cmp(const void *a,const void *b)
{
    curs *A=(curs *)a;
    curs *B=(curs *)b;
    return A->start-B->start;

}
///functia de comparare pt heap
class cmp2{

public:
    bool operator ()(const sala a, const sala b)
    {
        return(a.disp > b.disp);
    }

};
int main()
{
    int n,i;
    curs s[100];
    ifstream f("date.in");
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>s[i].start>>s[i].fin;
        s[i].index = i+1;
    }
    ///sortare crescator dupa timpul de inceput
    qsort(s,n,sizeof(curs),cmp);
    cout<<"Dupa sortare:";
    for(i=0;i<n;i++)
        cout<<s[i].index<<" ";
    cout<<endl;

    priority_queue<sala,vector<sala>,cmp2> q;
    vector< vector<int> > m;///in aceasta structura memorez salile cu activitatile lor(e ca o matrice)

    sala aux;///decalar o sala auxiliara in care memorez id-ul salii curente(in cazul de fata prima sala),si timpul final
    aux.id =nr_sali++;
    aux.disp=s[0].fin;

    m.push_back(vector<int>());
    m[0].push_back(s[0].index);///inainte m[0].push_back(0);(adaug in vectorul de vectori pe prima poztie in prima sala prima cativitate

    q.push(aux);///adaug prima sala in heap

    for(i=1;i<n;i++)
    {
        sala minim = q.top();///extrag vf heap ului = val cea mai mica
        cout<<minim.disp<<endl;
        if(s[i].start > minim.disp)///daca urmatoarea activitate incepe dupa timpul de terminare al ultimei activitati din sala respectiva atunci o adaug in aceasta sala
        {

            q.pop();
            sala aux;
            aux.id = minim.id;///vor fi in aceasi sala => vor avea acelasi id
            aux.disp = s[i].fin;
            q.push(aux);
            m[aux.id].push_back(s[i].index);///adaug activitatea in matrice la sala cu id ul corespunzator

        }
        else
        {
            sala aux;
            aux.id = nr_sali++;///daca nu e indeplinita conditia deschid o noua sala
            aux.disp = s[i].fin;
            q.push(aux);
            m.push_back(vector<int>());
            m[m.size()-1].push_back(s[i].index);
        }
    }
    cout<<"Afisare sali:"<<endl;
    for(i=0;i<m.size();i++)
    {
        cout<<"Sala "<<i+1<<":";
        for(int j =0;j<m[i ].size();j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}
