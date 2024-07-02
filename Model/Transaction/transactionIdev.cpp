#pragma hdrstop

#include "transactionIdev.h"
#include "etudiant.h"
#include "connexion.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------
transactionIdev::transactionIdev()
{
}
//---------------------------------------------------
void transactionIdev::insertNom()
{
    String nom = this->getNom();
    String parcours = "IDEV" ;
    String sql = "INSERT INTO etudiant (nom, parcours) VALUES('" + nom + "', '" + parcours + "')";
    connexion *connex = new connexion(sql);
    delete connex;
}
//-----------------------------------------------------
void transactionIdev::insertNote()
{
    int id = this->getId();
    float java = this->getJava();
    float php = this->getPhp();
    float cpp = this->getCpp();

    // Calculer la moyenne
    Idev idev;
    idev.setId(id);
    idev.setJava(java);
    idev.setPhp(php);
    idev.setCpp(cpp);
    float moyenne = idev.calcMoyenne();

    // Ajouter la moyenne et attribuer une mention
    Etudiant etudiant;
    etudiant.setMoyenne(moyenne);
    etudiant.attribuerMention();

    // R�cup�rer le parcours de l'�tudiant
    String sql = "SELECT parcours FROM etudiant WHERE id = '" + IntToStr(id) + "'";
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    String parcours = Form1->Query1->FieldByName("parcours")->AsString;
    delete connex;

    // V�rifier si l'�tudiant appartient au parcours IDEV
    if (parcours != "IDEV")
    {
        ShowMessage("Erreur : Les notes ne peuvent �tre ajout�es que pour les �tudiants du parcours IDEV.");
        return; // Quitter la fonction si le parcours n'est pas IDEV
    }

    // Ins�rer les donn�es dans la base de donn�es
     sql = "INSERT INTO idev (id_etudiant, java, php, cplusplus, moyenne, mention) VALUES ('" + IntToStr(id) + "', '" + FloatToStr(java) + "' , '" + FloatToStr(php) + "' , '" + FloatToStr(cpp) + "', '" + FloatToStr(moyenne) + "', '" + etudiant.getMention() + "')";
    connex = new connexion(sql);
    delete connex;
}

//-----------------------------------------------------
void transactionIdev::updateNote()
{
    int id = this->getId();
    float java = this->getJava();
    float php = this->getPhp();
    float cpp = this->getCpp();

    // Calculer la moyenne
    Idev idev;
    idev.setId(id);
    idev.setJava(java);
    idev.setPhp(php);
    idev.setCpp(cpp);
    float moyenne = idev.calcMoyenne();

    // Ajouter la moyenne et attribuer une mention
    Etudiant etudiant;
    etudiant.setMoyenne(moyenne);
    etudiant.attribuerMention();

    // Mettre � jour les donn�es dans la base de donn�es
    String sql = "SELECT parcours FROM etudiant WHERE id = '" + IntToStr(id) + "'";
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    String parcours = Form1->Query1->FieldByName("parcours")->AsString;

    if (parcours != "IDEV")
    {
        ShowMessage("Erreur : Les notes ne peuvent �tre modifi�es que pour les �tudiants du parcours IDEV.");
        delete connex;
        return; // Quitter la fonction si le parcours n'est pas IDEV
    }
    sql = "UPDATE idev SET java = '" + FloatToStr(java) + "', php = '" + FloatToStr(php) + "', cplusplus = '" + FloatToStr(cpp) + "', moyenne = '" + FloatToStr(moyenne) + "', mention = '" + etudiant.getMention() + "' WHERE id_etudiant = '" + IntToStr(id) + "'";

    connex = new connexion(sql);
    delete connex;
}

//-----------------------------------------------------
void transactionIdev::selectId(int* id, int* dim)
{
    // condition IDEV et n'a pas de note
    String sql = "SELECT e.id FROM etudiant e LEFT JOIN idev i ON e.id = i.id_etudiant WHERE e.parcours = 'IDEV' AND i.id_etudiant IS NULL";
    connexion* connex = new connexion(sql);
    Form1->Query1->Active = true;
    int i = 0;
    while (Form1->Query1->Eof==false)
    {
        id[i] = StrToInt(Form1->Query1->FieldByName("id")->AsString);
        Form1->Query1->Next();
        i++;
    }
    *dim = i;
    delete connex;
}
//-----------------------------------------------------
void transactionIdev::selectIdModif(int* id, int* dim)
{
    String sql = "SELECT e.id FROM etudiant e WHERE e.parcours = 'IDEV'";
    connexion* connex = new connexion(sql);
    Form1->Query1->Active = true;
    int i = 0;
    while (!Form1->Query1->Eof)
    {
        id[i] = StrToInt(Form1->Query1->FieldByName("id")->AsString);
        Form1->Query1->Next();
        i++;
    }
    *dim = i;
    delete connex;
}
//---------------------------------------------------
void transactionIdev::selectNom(int id,String*nom)
{
        String sql="SELECT nom FROM etudiant WHERE id = "+IntToStr(id);
        connexion *connex=new connexion(sql);
        Form1->Query1->Active=true;
        while(Form1->Query1->Eof==false)
        {
             *nom=Form1->Query1->FieldByName("nom")->AsString;
             Form1->Query1->Next();
        }
        delete connex;
}
//---------------------------------------------------
void transactionIdev::selectNote(int id, float* java, float* php, float* cpp)
{

    String sql = "SELECT java, php, cplusplus FROM idev WHERE id_etudiant = " + IntToStr(id);
    connexion* connex = new connexion(sql);
    Form1->Query1->Active = true;

    if (!Form1->Query1->Eof)
    {
        // R�cup�rez les valeurs des colonnes java, php et cplusplus
        *java = Form1->Query1->FieldByName("java")->AsFloat;
        *php = Form1->Query1->FieldByName("php")->AsFloat;
        *cpp = Form1->Query1->FieldByName("cplusplus")->AsFloat;
    }

    delete connex;
}
//---------------------------------------------------------
void transactionIdev::supprEtudiant(int id)
{
    // Supprimer l'�tudiant de la table 'etudiant'
    String sqlEtudiant = "DELETE FROM etudiant WHERE id = " + IntToStr(id);
    connexion* connexEtudiant = new connexion(sqlEtudiant);
    delete connexEtudiant;

    // Supprimer les notes de l'�tudiant de la table 'idev'
    String sqlNotes = "DELETE FROM idev WHERE id_etudiant = " + IntToStr(id);
    connexion* connexNotes = new connexion(sqlNotes);
    delete connexNotes;
}

//---------------------------------------------------

