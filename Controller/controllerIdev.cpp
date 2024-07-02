//---------------------------------------------------------------------------

#pragma hdrstop

#include "controllerIdev.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------
controllerIdev::controllerIdev()
{

}
//-------------------------------------------------
void controllerIdev::insertionNom(String nom)
{
    transactionIdev *idev = new transactionIdev();
    idev->setNom(nom);
    idev->insertNom();
    delete idev;
}
//-------------------------------------------------
void controllerIdev::insertionNote(int id , float java , float php , float cpp)
{
    transactionIdev *idev = new transactionIdev();
    idev->setId(id);
    idev->setJava(java);
    idev->setPhp(php);
    idev->setCpp(cpp);
    idev->insertNote();
    delete idev;
}
//-------------------------------------------------
void controllerIdev::selectionId(int*id,int*dim)
{
    transactionIdev *idev = new transactionIdev();
    idev->selectId(id,dim);
    delete idev;
}
//-------------------------------------------------
void controllerIdev::selectionIdModif(int*id, int*dim)
{
   transactionIdev *idev = new transactionIdev();
   idev->selectIdModif(id,dim);
   delete idev;
}
//-------------------------------------------------
void controllerIdev::selectionNom(int id, String*nom)
{
   transactionIdev *idev = new transactionIdev();
   idev->selectNom(id,nom);
   delete idev;

}
//-------------------------------------------------
void controllerIdev::selectionNote(int id, float*java, float*php, float*cpp)
{
    transactionIdev *idev = new transactionIdev();
    idev->selectNote(id,java,php,cpp);
    delete idev;
}
//-------------------------------------------------
void controllerIdev::updateDesNotes(int id, float java, float php, float cpp)
{
    transactionIdev *idev = new transactionIdev();
    idev->setId(id);
    idev->setJava(java);
    idev->setPhp(php);
    idev->setCpp(cpp);
    idev->updateNote();
    delete idev;
}
//-------------------------------------------------
void controllerIdev::supprimerEtudiant(int id)
{
    transactionIdev *idev = new transactionIdev();
    idev->supprEtudiant(id);
    delete idev;
}

