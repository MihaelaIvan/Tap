#include <iostream>
#include <fstream>
#include <map>
using namespace std;
struct date
{
    int val;
    int index;
};
void afiseaza1(int a[100],int n, int s)
{
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(a[i]+a[j]==s)
            {
                cout<<i<<" "<<j<<endl;
                return;
            }
    cout<<"Nu exista 2 nr a caror suma este "<<s<<endl;
}
void quickSort(date arr[], int left, int right)
{
    int i = left, j = right;
    date tmp;
    int pivot = arr[(left + right) / 2].val;
    while (i <= j)
    {
        while (arr[i].val < pivot)
            i++;
        while (arr[j].val > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void afiseaza2(date A[100],int n,int s)
{
    int i,j;
    i=0;
    j=n-1;
    while(i<j)
    {
        if(A[i].val+A[j].val==s)
        {
            cout<<A[i].index<<" "<<A[j].index;
            return;
        }
        else if(A[i].val+A[j].val<s)
            i++;
        else
            j--;
    }
    cout<<"Nu exista doua nr a caror suma este "<<s<<endl;
}
void afiseaza3(int a[100],int n,int s)
{
    map<int,int>h;
    for(int i=0; i<n; i++)
        h.insert({a[i],i});
    for(int i=0; i<n; i++)
        if(h.find(s-a[i])!=h.end()&& h.find(s-a[i])->second!=i)
        {
            cout<<i<<" "<<h.find(s-a[i])->second;
            return;
        }
    cout<<"Nu exista 2 nr care sa dea suma "<<s;
}
int main()
{
    int a[100],i,n,sum;
    ifstream f("date.in");
    f>>n;
    cout<<"Nr de elemente este:"<<n<<endl;
    for(i=0; i<n; i++)
        f>>a[i];
    cout<<"Cele "<<n<<" elemente sunt:";
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    f>>sum;
    cout<<"Suma este:"<<sum<<endl;
    cout<<"Varianta O(n^2)"<<endl;
    cout<<"Perechea este:";
    afiseaza1(a,n,sum);
    cout<<"Varianta O(nlogn)"<<endl;
    date A[100];
    for(i=0; i<n; i++)
    {
        A[i].index=i;
        A[i].val=a[i];
    }
    quickSort(A,0,n-1);
    /*cout<<"Afisare dupa soratare:"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i].val<<"  "<<A[i].index<<endl;*/
    cout<<"Perechea este:";
    afiseaza2(A,n,sum);
    cout<<endl;
    cout<<"Varianta O(n)"<<endl;
    cout<<"Perechea este:";
    afiseaza3(a,n,sum);
    return 0;
}
