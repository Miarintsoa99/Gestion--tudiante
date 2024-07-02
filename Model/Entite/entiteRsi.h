#ifndef entiteRsiH
#define entiteRsiH

#include <vcl.h>
#include "entiteEtudiant.h"

class Rsi : public Etudiant
{
private:
    int id;
    float reseaux;
    float commutation;

public:
    // setters
    void setId(int id);
    void setReseaux(float reseaux);
    void setCommutation(float commutation);

    // getters
    int getId();
    float getReseaux();
    float getCommutation();

    // Calcul de la moyenne spécifique à RSI
    float calcMoyenne();
};

#endif

