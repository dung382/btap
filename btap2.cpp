#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct MH
{
    string Mamh;
    string Tenmh;
    int SoTinChi;
    int SoTietDaDay;
};
void Input(MH *p, int n)
{
    cout << "nhap thong tin mon hoc :" << endl;
    getchar();
    for(int i = 0; i < n; i++)
    {
        cout << "nhap ma mon hoc :";
        getline(cin, (p+i)->Mamh);
        cout << "nhap ten mon hoc :";
        getline(cin, (p+i)->Tenmh);
        cout << "nhap so tin chi : ";
        cin >> (p+i)->SoTinChi;
        cout << "nhap so tiet da day :";
        cin >> (p+i)->SoTietDaDay;
    }
}
void Output( MH *p, int n)
{
    cout << "======== THONG TIN MON HOC ========";
    for(int i = 0; i < n; i++)
    {
        cout << "ma mon hoc :" << (p+i)->Mamh 
             << "ten mon hoc :" << (p+i)->Tenmh
             << "so tin chi :"  << (p+i)->SoTinChi
             << "so tiet da day :" << (p+i)->SoTietDaDay; 
    }
}
void SelectionSort(MH *p,int n)
{
    for(int i = 0; i < n-1; i++)
    {
        MH min = *(p+i);
        for(int j = i+1; j < n; i++)
        {
            if((p+i)->SoTietDaDay > (p+j)->SoTietDaDay)
            {
                min = *(p+j);
            }
        }
    }
}
void MergeSort(MH *p, int n, int l, int r)
{
    l=0;
    r = n-1;
    int X;
    cout << "nhap so can tim :";
    cin >> X;
    while()
}
int main()
{

}