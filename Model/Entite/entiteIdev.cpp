//---------------------------------------------------------------------------


#pragma hdrstop

#include "entiteIdev.h"
#include <windows.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//--------------------------------------
void Idev::setId(int id)
{
   this->id = id ;
}
//--------------------------------------
void Idev::setJava(float java)
{
    if (java >= 0.00 && java <= 20.00) {
        this->java = java;
    } else {
        MessageBox(NULL, "La note Java doit être comprise entre 0 et 20.", "Erreur", MB_ICONERROR | MB_OK);
    }
}

void Idev::setPhp(float php)
{
    if (php >= 0.00 && php <= 20.00) {
        this->php = php;
    } else {
        MessageBox(NULL, "La note PHP doit être comprise entre 0 et 20.", "Erreur", MB_ICONERROR | MB_OK);
    }
}

void Idev::setCpp(float cplusplus)
{
    if (cplusplus >= 0.00 && cplusplus <= 20.00) {
        this->cplusplus = cplusplus;
    } else {
        MessageBox(NULL, "La note C++ doit être comprise entre 0 et 20.", "Erreur", MB_ICONERROR | MB_OK);
    }
}
//--------------------------------------
int Idev::getId()
{
   return id;
}
//--------------------------------------
float Idev::getJava()
{
    return java;
}
//--------------------------------------
float Idev::getPhp()
{
    return php;
}
//--------------------------------------
float Idev::getCpp()
{
    return cplusplus;
}
//--------------------------------------

//--------------------------------------
float Idev::calcMoyenne()
{
    float moyenne = (this->java*1 + this->php*2 + this->cplusplus*3) / 6.0f;
    this->setMoyenne(moyenne);
    return this->getMoyenne();
}

