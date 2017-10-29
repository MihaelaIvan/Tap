#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n,i,a[100],jucator1=0,jucator2=0,x,sump=0,sumi=0;
    ifstream f("date.in");
    f>>n;
    if(n%2==1)
    {
        cout<<"Nr de elemente de pe tabla NU este par!!";
        return 0;
    }
    ///citire date
    for(i=1; i<=n; i++)
        f>>a[i];
    cout << "Tabla de joc este:"<<endl;
    for(i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    ///se calculeaza suma elementelor de pe pozitii impare si suma elemntelor de pozitii pare
    for(i=1; i<=n; i++)
        if(i%2==0)
            sump+=a[i];
        else
            sumi+=a[i];
    /*cout<<"Suma pare:"<<sump<<endl;
    cout<<"Suma impare:"<<sumi<<endl;*/ ///Afisare pt verificare
    cout<<"Jucatorul 1 este programul!"<<endl;
    cout<<"Dvs. sunteti jucatorul 2!"<<endl;
    if(sump>sumi)
    {
        int s,d;///s si d reprezinta capetele de pe tabla de joc, respectiv stanga si dreapta
        s=1;///le initializam
        d=n;
        while(s<d)
        {
            cout<<"Jucatorul 1 a ales:";
            if(s%2==0)///cauta sa vada care dintre cele doua capete e par si pe acela il alege
            {
                cout<<a[s]<<endl;
                jucator1=jucator1+a[s];///adaug nr ales la suma jucatorului 1
                s++;
            }
            else if(d%2==0)
            {
                cout<<a[d]<<endl;
                jucator1=jucator1+a[d];///adaug nr la suma jucatorului 1
                d--;
            }
            cout<<"Este randul dvs.!"<<endl;
            if(s!=d)
                cout<<"Aveti de ales intre "<<a[s]<<" si "<<a[d]<<".";
            else
                cout<<"V-a ramas de ales valoarea:"<<a[s]<<".";
            cout<<"Varianta dvs este:";
            cin>>x;
            if(x!=a[s]&&x!=a[d])///test de verificare a valorii introduse
            {
                cout<<"Ati ales o valoare inexistenta!"<<endl;
                return 0;
            }
            if(x==a[s])///valoarea aleasa se adauga la suma jucatorului 2
            {
                jucator2=jucator2+a[s];
                s++;
            }
            else if(x==a[d])
            {
                jucator2=jucator2+a[d];
                d--;
            }
        }
    }
    else///cazul in care suma elem de pe pozitii impare este mai mare
    {
        int s,d;
        s=1;
        d=n;
        while(s< d)
        {
            cout<<"Jucatorul 1 a ales:";
            if(s%2==1)///verific daca e impar
            {
                cout<<a[s]<<endl;
                jucator1=jucator1+a[s];///adaug nr la suma juc 1
                s++;
            }
            else if(d%2==1)///verific daca e impar
            {
                cout<<a[d]<<endl;
                jucator1=jucator1+a[d];///adaug nr la suma jucatorului 2
                d--;
            }
            cout<<"Este randul dvs.!"<<endl;///jucatorul 2 alege
            if(s!=d)
                cout<<"Aveti de ales intre "<<a[s]<<" si "<<a[d]<<".";
            else
                cout<<"V-a ramas de ales valoare:"<<a[s]<<".";
            cout<<"Varianta dvs este:";
            cin>>x;
            if(x!=a[s]&&x!=a[d])
            {
                cout<<"Ati ales o valoare inexistenta!"<<endl;
                return 0;
            }
            if(x==a[s])
            {
                jucator2=jucator2+a[s];
                s++;

            }
            else if(x==a[d])
            {
                jucator2=jucator2+a[d];
                d--;
            }
        }
    }
    cout<<"Jucatorul 1 a acumlat suma:"<<jucator1<<endl;
    cout<<"Jucatorul 2 a acumlat suma:"<<jucator2<<endl;
    if(jucator1>=jucator2)
        cout<<"Ati pierdut!!";
    return 0;
}
