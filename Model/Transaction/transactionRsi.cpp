#include "transactionRsi.h"
#include "etudiant.h"
#include "connexion.h"
//-----------------------------------------------------------
transactionRsi::transactionRsi()
{
}
//-----------------------------------------------------------
void transactionRsi::insertNom()
{
    String nom = this->getNom();
    String parcours = "RSI";
    String sql = "INSERT INTO etudiant (nom, parcours) VALUES('" + nom + "', '" + parcours + "')";
    connexion *connex = new connexion(sql);
    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::insertNote()
{
    int id = this->getId();
    float reseaux = this->getReseaux();
    float commutation = this->getCommutation();

    // Calculer la moyenne
    Rsi rsi;
    rsi.setId(id);
    rsi.setReseaux(reseaux);
    rsi.setCommutation(commutation);
    float moyenne = rsi.calcMoyenne();

    // Ajouter la moyenne et attribuer une mention
    Etudiant etudiant;
    etudiant.setMoyenne(moyenne);
    etudiant.attribuerMention();

    // Récupérer le parcours de l'étudiant
    String sql = "SELECT parcours FROM etudiant WHERE id = '" + IntToStr(id) + "'";
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    String parcours = Form1->Query1->FieldByName("parcours")->AsString;
    delete connex;

    // Vérifier si l'étudiant appartient au parcours RSI
    if (parcours != "RSI")
    {
        ShowMessage("Erreur : Les notes ne peuvent être ajoutées que pour les étudiants du parcours RSI.");
        return; // Quitter la fonction si le parcours n'est pas RSI
    }

    // Insérer les données dans la base de données
    sql = "INSERT INTO rsi (id_etudiant, reseaux, commutation, moyenne, mention) VALUES ('" + IntToStr(id) + "', '" + FloatToStr(reseaux) + "' , '" + FloatToStr(commutation) + "', '" + FloatToStr(moyenne) + "', '" + etudiant.getMention() + "')";

    connex = new connexion(sql);
    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::updateNote()
{
    int id = this->getId();
    float reseaux = this->getReseaux();
    float commutation = this->getCommutation();

    // Calculer la moyenne
    Rsi rsi;
    rsi.setId(id);
    rsi.setReseaux(reseaux);
    rsi.setCommutation(commutation);
    float moyenne = rsi.calcMoyenne();

    // Ajouter la moyenne et attribuer une mention
    Etudiant etudiant;
    etudiant.setMoyenne(moyenne);
    etudiant.attribuerMention();

    // Mettre à jour les données dans la base de données
    String sql = "SELECT parcours FROM etudiant WHERE id = '" + IntToStr(id) + "'";
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    String parcours = Form1->Query1->FieldByName("parcours")->AsString;

    if (parcours != "RSI")
    {
        ShowMessage("Erreur : Les notes ne peuvent être modifiées que pour les étudiants du parcours RSI.");
        delete connex;
        return; // Quitter la fonction si le parcours n'est pas RSI
    }
    sql = "UPDATE rsi SET reseaux = '" + FloatToStr(reseaux) + "', commutation = '" + FloatToStr(commutation) + "', moyenne = '" + FloatToStr(moyenne) + "', mention = '" + etudiant.getMention() + "' WHERE id_etudiant = '" + IntToStr(id) + "'";

    connex = new connexion(sql);
    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::selectId(int *id, int *dim)
{
    // condition RSI et n'a pas de note
    String sql = "SELECT e.id FROM etudiant e LEFT JOIN rsi r ON e.id = r.id_etudiant WHERE e.parcours = 'RSI' AND r.id_etudiant IS NULL";
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    int i = 0;
    while (Form1->Query1->Eof == false)
    {
        id[i] = StrToInt(Form1->Query1->FieldByName("id")->AsString);
        Form1->Query1->Next();
        i++;
    }
    *dim = i;
    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::selectIdModif(int *id, int *dim)
{
    String sql = "SELECT e.id FROM etudiant e WHERE e.parcours = 'RSI'";
    connexion *connex = new connexion(sql);
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
//-----------------------------------------------------------
void transactionRsi::selectNom(int id, String *nom)
{
    String sql = "SELECT nom FROM etudiant WHERE id = " + IntToStr(id);
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;
    while (Form1->Query1->Eof == false)
    {
        *nom = Form1->Query1->FieldByName("nom")->AsString;
        Form1->Query1->Next();
    }
    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::selectNote(int id, float *reseaux, float *commutation)
{
    String sql = "SELECT reseaux, commutation FROM rsi WHERE id_etudiant = " + IntToStr(id);
    connexion *connex = new connexion(sql);
    Form1->Query1->Active = true;

    if (!Form1->Query1->Eof)
    {
        // Récupérer les valeurs des colonnes reseaux et commutation
        *reseaux = Form1->Query1->FieldByName("reseaux")->AsFloat;
        *commutation = Form1->Query1->FieldByName("commutation")->AsFloat;
    }

    delete connex;
}
//-----------------------------------------------------------
void transactionRsi::supprEtudiant(int id)
{
    // Supprimer l'étudiant de la table 'etudiant'
    String sqlEtudiant = "DELETE FROM etudiant WHERE id = " + IntToStr(id);
    connexion *connexEtudiant = new connexion(sqlEtudiant);
    delete connexEtudiant;

    // Supprimer les notes de l'étudiant de la table 'rsi'
    String sqlNotes = "DELETE FROM rsi WHERE id_etudiant = " + IntToStr(id);
    connexion *connexNotes = new connexion(sqlNotes);
    delete connexNotes;
}
