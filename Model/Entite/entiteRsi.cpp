#include "entiteRsi.h"
#include <windows.h>

// D�finition des m�thodes de la classe Rsi
//-----------------------------------------------------------
void Rsi::setId(int id)
{
    this->id = id;
}
//-----------------------------------------------------------
void Rsi::setReseaux(float reseaux)
{
    if (reseaux >= 0.00 && reseaux <= 20.00)
    {
        this->reseaux = reseaux;
    }
    else
    {
        MessageBox(NULL, "La note R�seaux doit �tre comprise entre 0 et 20.", "Erreur", MB_ICONERROR | MB_OK);
    }
}
//-----------------------------------------------------------
void Rsi::setCommutation(float commutation)
{
    if (commutation >= 0.00 && commutation <= 20.00)
    {
        this->commutation = commutation;
    }
    else
    {
        MessageBox(NULL, "La note Commutation doit �tre comprise entre 0 et 20.", "Erreur", MB_ICONERROR | MB_OK);
    }
}
//-----------------------------------------------------------
int Rsi::getId()
{
    return id;
}

float Rsi::getReseaux()
{
    return reseaux;
}

float Rsi::getCommutation()
{
    return commutation;
}

float Rsi::calcMoyenne()
{
    float moyenne = (this->reseaux*1 + this->commutation*2) / 3.0f;
    this->setMoyenne(moyenne);
    return this->getMoyenne();
}
//-----------------------------------------------------------
