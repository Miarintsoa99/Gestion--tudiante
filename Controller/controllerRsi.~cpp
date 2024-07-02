//---------------------------------------------------------------------------

#pragma hdrstop

#include "controllerRsi.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
controllerRsi::controllerRsi()
{
}
//---------------------------------------------------------------------------
void controllerRsi::insertionNom(String nom)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->setNom(nom);
    rsi->insertNom();
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::insertionNote(int id, float reseaux, float commutation)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->setId(id);
    rsi->setReseaux(reseaux);
    rsi->setCommutation(commutation);
    rsi->insertNote();
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::selectionId(int *id, int *dim)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->selectId(id, dim);
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::selectionIdModif(int *id, int *dim)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->selectIdModif(id, dim);
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::selectionNom(int id, String *nom)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->selectNom(id, nom);
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::selectionNote(int id, float *reseaux, float *commutation)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->selectNote(id, reseaux, commutation);
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::updateDesNotes(int id, float reseaux, float commutation)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->setId(id);
    rsi->setReseaux(reseaux);
    rsi->setCommutation(commutation);
    rsi->updateNote();
    delete rsi;
}
//---------------------------------------------------------------------------
void controllerRsi::supprimerEtudiant(int id)
{
    transactionRsi *rsi = new transactionRsi();
    rsi->supprEtudiant(id);
    delete rsi;
}
//---------------------------------------------------------------------------
