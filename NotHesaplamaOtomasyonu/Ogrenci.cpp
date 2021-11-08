#include <iostream>
#include <QString>

class Ogrenci
{
public:
    QString ad,soyad;
    int vizenot, finalnot;

    Ogrenci(QString ad, QString soyad, int vizenot, int finalnot)
    {
        this->ad = ad;
        this->soyad = soyad;
        this->vizenot = vizenot;
        this->finalnot = finalnot;
    }

    double GecmeNotuHesapla(int vn, int fn)
    {
        double gn = vn * 0.4 + fn * 0.6;
        return gn;

    }
};
