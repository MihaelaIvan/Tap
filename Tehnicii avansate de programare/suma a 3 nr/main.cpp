#include <iostream>
#include <fstream>
#include <map>
using namespace std;
void sum1(int a[100],int n, int s)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
           for(k=j+1;k<n;k++)
             if(a[i]+a[j]+a[k]==s)
                {cout<<i<<" "<<j<<" "<<k;
                 return;
                 }
    cout<<"Nu exista 3 nr a caror suma este "<<s<<endl;
}
struct date
{
    int val;
    int index;
};
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
void sum2(date A[100],int n,int s)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
   {

    j=i+1;
    k=n-1;
    while(j<k)
        {if(A[i].val+A[j].val+A[k].val==s)
             {cout<<A[i].index<<" "<<A[j].index<<" "<<A[k].index;
              return;}
         else
            if(A[i].val+A[j].val+A[k].val<s)
                     j++;
                  else
                    k--;
        }
   }
    cout<<"Nu exista 3 nr a caror suma este "<<s<<endl;
}
void sum3(int a[100],int n, int s)
{
        map<int,int>h;
        for(int i=0;i<n;i++)
           h.insert({a[i],i});
        for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
            if(h.find(s-a[i]-a[j])!=h.end()&&h.find(s-a[i]-a[j])->second!=i&&h.find(s-a[i]-a[j])->second!=j)
              {cout<<i<<" "<<j<<" "<<h.find(s-a[i]-a[j])->second;
              return;
              }

}
int main()
{
    fstream f("date.in");
    int a[100],i,j,k,sum,n;
    f>>n;
    cout<<"Nr de elemente este:"<<n<<endl;
    for(i=0;i<n;i++)
        f>>a[i];
    cout<<"Cele "<<n<<" elemente sunt:";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    f>>sum;
    cout<<"Suma este:"<<sum<<endl;
    cout<<"Varianta O(n^3)"<<endl;
    sum1(a,n,sum);
    cout<<endl;
    cout<<"Varianata O(n^2logn)"<<endl;
    date A[100];
    for(i=0;i<n;i++)
       {
           A[i].index=i;
           A[i].val=a[i];
       }
    quickSort(A,0,n-1);
    /*cout<<"Afisare dupa soratare:"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i].val<<"  "<<A[i].index<<endl;*/
    sum2(A,n,sum);
    cout<<endl;
    cout<<"Varianta O(n^2)"<<endl;
    sum3(a,n,sum);
    return 0;
}
