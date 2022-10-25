#include <iostream>
#include <conio.h>
using namespace std;
#define s 20
class matrix
{      int a[s][s], x, y,i,j,k;
      public:
    void get();
    void put();
    matrix operator+(matrix);
    matrix operator-(matrix);
    matrix operator*(matrix);
    matrix transpose();
};    void matrix::get()
{  cout << "Enter order of matrix: \n";
    cin >> x >> y;
    cout << "Enter the matrix :\n";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> a[i][j];
}   void matrix::put()
{
    cout << "The answer is :\n";
    for (int i = 0; i < x; i++)
    {
        cout << "\n\t";
        for (int j = 0; j < y; j++)
        {
            cout << a[i][j] << "  ";
   }  }  }    matrix matrix::operator+(matrix b)
{
    matrix r;
    if ((x != b.x) || (y != b.y))
    {
        cout << "\n\t Matrix addition is not possible the result is incorrect\n\n";
        r.x = 0;
        r.y = 0;
    } else
    {
        r.x = x;
        r.y = y;
    }
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            r.a[i][j] = a[i][j] + b.a[i][j];
    return r;
}    matrix matrix::operator-(matrix b)
{
    matrix r;
    if ((x != b.x) || (y != b.y))
    {
        cout << "\n\tMatrix subtraction is not possible the result is inccorrect\n\n";
        r.x = 0;
        r.y = 0;
    } else
    {
        r.x = x;
        r.y = y;
    }
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            r.a[i][j] = a[i][j] - b.a[i][j];
    return r;
}   matrix matrix::operator*(matrix b)
{
    matrix r;
    if ((x != b.x) || (y != b.y))
    {
        cout << "\n\tMatrix multiplication is not possible the result is incorrect\n\n";
        r.x = 0;
        r.y = 0;
    }    else
    {
        r.x = x;
        r.y = b.y;
    }
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            r.a[i][j] = 0;
    for (i = 0; i < x; i++)
        for (j = 0; j < b.y; j++)
            for (int k = 0; (k < y) || (k < b.x); k++)
                r.a[i][j] += a[i][k] * b.a[k][j];
    return r;
}  matrix matrix::transpose()
{   matrix r;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            r.a[i][j] = a[i][j];
    r.x = x;
    r.y = y;
    return r;
}
int main()
{
    char op;
    matrix a, b, c;
    int t = 1;
    while (t)
    {
        cout << "\tSelect option\n\n1.matrix addition\n\n2.matrix subtraction\n\n3.matrix multiplication\n\n4.matrix transpose\n\n5.Exit";
        op = getch();
        switch(op)
        {
            case '1':
            cout<<"Matrix addition:\n";
            a.get();
            b.get();
            c=a+b;
            c.put();
            break;
            case '2':
            cout<<"Matrix subtraction:\n";
            a.get();
            b.get();
            c=a-b;
            c.put();
            break;
            case '3':
            cout<<"Matrix multiplication:\n";
            a.get();
            b.get();
            c=a*b;
            c.put();
            break;
            case '4':
            cout<<"Matrix Transpose:\n";
            a.get();
            c=a.transpose();
            c.put();
            break;
            case '5':
            cout<<"\n\nPress any key to exit\n";
            t=0;
            break;
            default:
            cout<<"\n\nEnter a valid option\n";
        }  getch();
    }    getch();
    return 0;        }
