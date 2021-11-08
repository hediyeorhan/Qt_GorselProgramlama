#include <iostream>

using namespace std;

class SmartPhone
{
private: int id;
public:
    string marka;
    string model;
    int hafiza;
    int count = 0;

    SmartPhone(string marka, string model, int hafiza)
    {
        this->id = ++count;
        this->marka = marka;
        this->model = model;
        this->hafiza = hafiza;
    }

    void bilgileriYazdir()
    {
        cout<< "ID : "<<id<<" -- MARKA : "<<marka<<" -- MODEL : "<<model<<" -- HAFIZA : "<<hafiza<<endl;
    }

    void hafizaDegerlendir()
    {
        if (this->hafiza >= 16)
            cout<<"Hafiza durumu yeterli."<<endl;
        else
            cout<<"Yetersiz hafiza !!"<<endl;

    }

};


class Samsung:public SmartPhone
{
private: int id;
public :
    int hiz;
    int kamera;
    int count=0;

    Samsung(string marka, string model, int hafiza, int hiz, int kamera):SmartPhone(marka, model, hafiza)
    {
        this->id = count++;
        this->hiz = hiz;
        this->kamera = kamera;
    }

    void hizDegerlendir()
    {
        cout<<"Telefonun mevcut hizi : "<<hiz<<endl;

    }

    void kameraDegerlendir()
    {
        cout<<"Telefonun mevcut kamera durumu : "<<kamera<<endl;
    }

};

int main()
{
    SmartPhone s1 = SmartPhone("Huawei", "Mate 20 Lite", 32);
    SmartPhone s2 = SmartPhone("Iphone", "5", 16);

    s1.bilgileriYazdir();
    s2.bilgileriYazdir();

    s1.hafizaDegerlendir();
    s2.hafizaDegerlendir();

    Samsung ss1 = Samsung("Samsung", "S5", 32, 16, 16);
    ss1.kameraDegerlendir();
    ss1.hizDegerlendir();
    ss1.hafizaDegerlendir();
}

