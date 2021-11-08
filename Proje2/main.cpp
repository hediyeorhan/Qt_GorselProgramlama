#include "dialog.h"
#include <QApplication>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Calisan
{
public: // erişim belirteci ayarladık
    string Ad;
    string Firma;
    int Yas;
    Calisan(string Ad, string Firma, int Yas)
    {
        this->Ad  = Ad;
        this->Firma = Firma;
        this->Yas = Yas;
    }

    void bilgileriYazdir()
    {
        cout<<"Calisanin Adi : "<<Ad<<endl;
        cout<<"Calisanin Firmasi : "<<Firma<<endl;
        cout<<"Calisanin Yasi : "<<Yas<<endl;
    }
};

class Calisan2
{// bir erişim belirteç belirtmediğimiz için private olarak algıladı !!!
    string Ad;
    string Firma;
    int Yas;
public:
    Calisan2(string Ad, string Firma, int Yas)
    {
        this->Ad  = Ad;
        this->Firma = Firma;
        this->Yas = Yas;
    }
    void setAd(string Ad)
    {
        this->Ad = Ad;
    }
    string getAd()
    {
        return Ad;
    }
    void setFirma(string Firma)
    {
        this->Firma = Firma;
    }
    string getFirma()
    {
        return Firma;
    }
    void setYas(int Yas)
    {
        this->Yas = Yas;
    }
    int getYas()
    {
        return Yas;
    }

    void bilgileriYazdir()
    {
        cout<<"Calisanin Adi : "<<Ad<<endl;
        cout<<"Calisanin Firmasi : "<<Firma<<endl;
        cout<<"Calisanin Yasi : "<<Yas<<endl;
    }
};

class AbstractCalisan
{
    virtual void ZamAlsinmi()=0;  //-> Abstract fonksiyon --> Anahtar kelime **** "virtual"
};

class Calisan3:AbstractCalisan
{// bir erişim belirteç belirtmediğimiz için private olarak algıladı !!!
    string Ad;
    string Firma;
    int Yas;
public:
    Calisan3(string Ad, string Firma, int Yas)
    {
        this->Ad  = Ad;
        this->Firma = Firma;
        this->Yas = Yas;
    }
    void setAd(string Ad)
    {
        this->Ad = Ad;
    }
    string getAd()
    {
        return Ad;
    }
    void setFirma(string Firma)
    {
        this->Firma = Firma;
    }
    string getFirma()
    {
        return Firma;
    }
    void setYas(int Yas)
    {
        this->Yas = Yas;
    }
    int getYas()
    {
        return Yas;
    }
    void ZamAlsinmi()
    {
        if(Yas>30)
            cout<<"Zam orani yuzde 20"<<endl;
        else
            cout<<"Zam orani yuzde 10"<<endl;
    }

    void bilgileriYazdir()
    {
        cout<<"Calisanin Adi : "<<Ad<<endl;
        cout<<"Calisanin Firmasi : "<<Firma<<endl;
        cout<<"Calisanin Yasi : "<<Yas<<endl;
    }
};

class Yazilimci:public Calisan3
{
public:
    string progdil;
    Yazilimci(string Ad, string Firma, int Yas, string progdil):Calisan3(Ad, Firma, Yas)
    {
        this->progdil = progdil;
    }
};

int main(int argc, char *argv[])
{
    // private, protected, public --> Erişim Belirteçleri --> Kapsülleme
    int x;
    /*
    Calisan c1;
    c1.Ad = "Hediye";
    c1.Firma = "Necmettin Erbakan Universitesi";
    c1.Yas = 21;
    c1.bilgileriYazdir();
*/
    // Türkçe karakter console ekranında okunmuyor !!

/*
    Calisan c2 = Calisan("Hediye", "NEU", 21);

    c2.bilgileriYazdir();*/

    /*
    Calisan2 c3 = Calisan2("Hediye", "NEU", 21);
    c3.bilgileriYazdir();
    cout<<"\n-------------------------\n"<<endl;
    c3.setAd("Hediye Orhan");
    c3.bilgileriYazdir();
*/
    /*
    Calisan3 c4 = Calisan3("Hediye", "NEU", 21);
    c4.ZamAlsinmi();
*/

    Yazilimci y1 = Yazilimci("Hediye Orhan", "NEU", 21 , "C++");
    y1.bilgileriYazdir(); // -- > HATAYA BAK!! --> buldum miras alınan sınıfın başına public ekliyoruz.!!

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}
