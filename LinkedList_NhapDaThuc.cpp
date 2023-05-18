#include <bits/stdc++.h>
using namespace std;
struct DONTHUC
{
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0)
    {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC &operator=(const DONTHUC &rhs)
    {
        if (this == &rhs)
            return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};
struct Node
{
    DONTHUC *data;
    Node *next;

    Node(DONTHUC *_data = nullptr)
    {
        this->data = _data;
        this->next = nullptr;
    }
};
struct DATHUC
{
    Node *head;
    Node *tail;
    DATHUC()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};
void Nhap(DATHUC &b, double heso, int somu)
{
    DONTHUC *a = new DONTHUC(heso, somu);
    Node *p = new Node(a);

    if (!b.head)
    {
        b.head = p;
    }
    else
    {
        b.tail->next = p;
    }
    b.tail = p;
}
void Xuat(DATHUC &f)
{
    if (f.head == nullptr)
    {
        cout << "0";
    }
    int dem = 0;
    int n = 0;
    int thinh = 0;
    Node *p = f.head;
    while (p != nullptr)
    {
        if (p != f.head && p != nullptr && p->data->heso > 0 && thinh != 0)
            cout << "+";

        if (p->data->heso == 0) // he so = 0
        {
            p = p->next;
            dem++;
        }
        else if (abs(p->data->heso) == 1 && p->data->somu != 0 && p->data->somu != 1) // he so !0
        {
            if (p->data->heso < 0)
            {
                cout << "-x^" << p->data->somu;
                p = p->next;
                thinh++;
            }
            else
            {
                cout << "x^" << p->data->somu;
                thinh++;
                p = p->next;
            }
        }
        else if (abs(p->data->heso) == 1 && p->data->somu == 1)
        {
            if (p->data->heso < 0)
            {
                cout << "-x";
                thinh++;
                p = p->next;
            }
            else
            {
                cout << "x";
                p = p->next;
                thinh++;
            }
        }
        else if (abs(p->data->heso) == 1 && p->data->somu == 0)
        {
            if (p->data->heso < 0)
            {
                cout << p->data->heso;
                p = p->next;
                thinh++;
            }
            else
            {
                cout << p->data->heso;
                p = p->next;
                thinh++;
            }
        }
        else if (p->data->somu == 0)
        {
            cout << p->data->heso;
            p = p->next;
            thinh++;
        }
        else if (p->data->somu == 1)
        {
            cout << p->data->heso << "x";
            p = p->next;
            thinh++;
        }
        else
        {
            cout << p->data->heso << "x^" << p->data->somu;
            p = p->next;
            thinh++;
        }
        n++;
    }
    if (n == dem)
        cout << "0";
    cout << endl;
}
double TinhDaThuc(DATHUC b, double x)
{
    double sum = 0; 
    Node *p = b.head;
    while (p != nullptr)
    {
        sum = sum + p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return sum;
}
int main()
{
    DATHUC B;
    int N;
    cin >> N;
    for (int test = 0; test < N; test++)
    {
        double heso;
        int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }
    cout << "Da thuc vua nhap la: ";
    Xuat(B);
    double x;
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
