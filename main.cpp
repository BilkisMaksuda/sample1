#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define MAX 100000

using namespace std;

void print();
void clear_screen(void);
void view(int n,int A[]);
void insert(int n, int A[]);
void search(int n,int A[]);
void deletee(int n, int A[]);
void sort(int n,int A[]);
void sort1(int n,int A[]);
void FindingLocation(int n, int A[]);
void operation(int A[],int x,int n);

int main()
{
    int n,i,x;
    cout << "Enter the size of n :" << "\n";
    cin >> n;
    int *A = (int*)malloc(MAX * sizeof(int));
    //dynamically memory allocation
    if(A == 0)
        cout << "unable to allocate memory" << "\n" ;


    cout << "Enter array elements :" << "\n";
    for(i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    while(1)
    {
        print();
        cout << "\n\nplease enter a number from above : " << "\n";
        cin >> x;
        operation(A,x,n);
        clear_screen();

    }

    return 0;
}

void print()
{
    cout << "\n\nfollow the following guidelines:" << "\n";
    cout << "0.Exit" << "\n";
    cout << "1.View all elements" << "\n";
    cout << "2.Insert new element" << "\n";
    cout << "3.Search an element" << "\n";
    cout << "4.Delete an element (user should input item to be searched and delete)" << "\n";
    cout << "5.Sort elements in ascending order" << "\n";
    cout << "6.Sort elements in descending order"<< "\n";
    cout << "7.Find memory location of an element (user should input index number)."<< "\n" ;
}


void view(int n,int A[])
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << A[i] << "\n";
    }
}


void insert(int n, int A[])
{
    int a,i,l;
    cout << "Enter a location where you want to insert a value :";
    cin >> l;
    cout << "Enter a number for inserting :";
    cin >> a;
    for(i = n; i >= l; i--)
    {
        A[i+1] = A[i];
    }
    A[l] = a;
    cout << "final array :\n";
    for(i = 0; i < n + 1; i++)
    {
        cout << A[i] << "\n";
    }
}


void search(int n,int A[])

{
    int s,i, L = 0;
    cout << "Enter a element for searching :";
    cin >> s;
    for( i = 1; i <= n; i++)
    {
        if(s == A[i])
        {
            L = i;
        }
    }

    if ( L == 0)
        cout << "Item is not in the array" << "\n";
    else
        cout << "Item found and location : " << L << "\n";
}


void deletee(int n, int A[])
{
    int l, i;
    cout << "Enter a location where you want to delete a value :";
    cin >> l;
    if(l > n)
        cout << "Deletion is not possible " << "\n";
    else
    {
        for(i = l; i <= n-1; i++)
        {
            A[i] = A[i+1];
        }

        cout << "Final array :" << "\n";
        for(i = 0; i < n-1; i++)
        {
            cout << A[i] << "\n";
        }
        cout << "\n" ;
    }
}

void sort(int n,int A[])
{
    int i,j,t;
    for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (A[j] > A[j+1])
      {
        t= A[j];
        A[j]= A[j+1];
        A[j+1] = t;
      }
    }
  }
    cout << "The numbers arranged in ascending order :" << "\n" ;
    for(i = 0; i < n; i++)
        cout << A[i] << "\n";
}

void sort1(int n,int A[])
{
    int i,j,t;
    for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (A[j] < A[j+1])
      {
        t= A[j];
        A[j]= A[j+1];
        A[j+1] = t;
      }
    }
  }
    cout << "The numbers arranged in descending order :" << "\n";
    for(i = 0; i < n; i++)
        cout << A[i] << "\n";
}
void FindingLocation(int n, int A[])
{
    cout<<"Enter the index what for you want to know memory location: ";
    int x; cin>>x;
    if(x<1 || x>n) cout<<"Sorry! No such index is present!"<<endl;
    else cout<<"Desired memory location is = "<< &A[x]<<endl;
}


void clear_screen(void)
{
    cout << "\n\npress any key to clear the screen  : ";
    getch();
    system("cls");
}
void operation(int A[],int x,int n)
{


    if(x < 0 || x > 7)
        cout << "invalid keyword" << "\n";
    else
    {
        if(x == 0)
            exit(0);
        else if (x == 1)
            view(n,A);
        else if(x == 2)
            insert(n,A);
        else if(x == 3  )
            search(n,A);
        else if (x == 4)
            deletee(n,A);
        else if(x == 5)
            sort(n,A);
        else if(x == 6)
            sort1(n,A);
        else if(x == 7)
            FindingLocation(n,A);

    }
}





