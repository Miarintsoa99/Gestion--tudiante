#pragma hdrstop

#include "etudiant.h"
#include "controllerIdev.h"
#include "controllerRsi.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

    // StringGrid 
    Query1->SQL->Text = "SELECT etudiant.id, etudiant.nom, idev.java, idev.php, idev.cplusplus, idev.moyenne, idev.mention FROM etudiant INNER JOIN idev ON etudiant.id = idev.id_etudiant";
    Query1->Open();

    // Ou, si vous utilisez un TStringGrid
    int row = 1;
    while (!Query1->Eof) {
        StringGrid1->Cells[0][row] = Query1->FieldByName("id")->AsString;
        StringGrid1->Cells[1][row] = Query1->FieldByName("nom")->AsString;
        StringGrid1->Cells[2][row] = Query1->FieldByName("java")->AsString;
        StringGrid1->Cells[3][row] = Query1->FieldByName("php")->AsString;
        StringGrid1->Cells[4][row] = Query1->FieldByName("cplusplus")->AsString;
        StringGrid1->Cells[5][row] = Query1->FieldByName("moyenne")->AsString;
        StringGrid1->Cells[6][row] = Query1->FieldByName("mention")->AsString;
        Query1->Next();
        row++;
    }

     // StringGrid 2 RSI
    Query2->SQL->Text = "SELECT etudiant.id, etudiant.nom, rsi.reseaux, rsi.commutation, rsi.moyenne, rsi.mention FROM etudiant INNER JOIN rsi ON etudiant.id = rsi.id_etudiant";
    Query2->Open();

    // Remplissage du TStringGrid 2 pour RSI
    row = 1;
    while (!Query2->Eof)
    {
        StringGrid2->Cells[0][row] = Query2->FieldByName("id")->AsString;
        StringGrid2->Cells[1][row] = Query2->FieldByName("nom")->AsString;
        StringGrid2->Cells[2][row] = Query2->FieldByName("reseaux")->AsString;
        StringGrid2->Cells[3][row] = Query2->FieldByName("commutation")->AsString;
        StringGrid2->Cells[4][row] = Query2->FieldByName("moyenne")->AsString;
        StringGrid2->Cells[5][row] = Query2->FieldByName("mention")->AsString;
        Query2->Next();
        row++;
    }
}
//--------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) // Entétes stringGrid 
{
    // Titres des colonnes
    StringGrid1->Cells[0][0] = "ID";
    StringGrid1->Cells[1][0] = "Nom";
    StringGrid1->Cells[2][0] = "Java";
    StringGrid1->Cells[3][0] = "PHP";
    StringGrid1->Cells[4][0] = "C++";
    StringGrid1->Cells[5][0] = "Moyenne";
    StringGrid1->Cells[6][0] = "Mention";

    // Entï¿½tes du TStringGrid 2 pour RSI
    StringGrid2->Cells[0][0] = "ID";
    StringGrid2->Cells[1][0] = "Nom";
    StringGrid2->Cells[2][0] = "Réseaux";
    StringGrid2->Cells[3][0] = "Commutation";
    StringGrid2->Cells[4][0] = "Moyenne";
    StringGrid2->Cells[5][0] = "Mention";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
    // Actualiser le StringGrid
    try {
        Query1->Close();
        Query1->SQL->Text = "SELECT etudiant.id, etudiant.nom, idev.java, idev.php, idev.cplusplus, idev.moyenne, idev.mention FROM etudiant INNER JOIN idev ON etudiant.id = idev.id_etudiant";
        Query1->Open();

        // Remplit les donnés
        int row = 1;
        while (!Query1->Eof) {
            for (int col = 0; col < Query1->FieldCount; ++col) {
                StringGrid1->Cells[col][row] = Query1->Fields->Fields[col]->AsString;
            }
            Query1->Next();
            ++row;
        }
    } catch (Exception &ex) {
        ShowMessage("Erreur lors de l'exécution de la requï¿½te : " + ex.Message);
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::BtnAjoutEtutiantClick(TObject *Sender)    // insertionNom idev 
{
    String nom = Form1->inputNom->Text;

    // Vï¿½rifier si le champ du nom est vide
    if (nom.Trim().IsEmpty()) {
        ShowMessage("Veuillez entrer un nom avant d'ajouter un ï¿½tudiant.");
        return; // Quitter la fonction si le nom est vide
    }

    controllerIdev *idev = new controllerIdev();
    try {
        idev->insertionNom(nom);
    } catch (...) {
        ShowMessage("Erreur lors de l'ajout de l'ï¿½tudiant.");
    }
    delete idev;


    Form1->inputNom->Text = " ";
    
    
}

//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3DropDown(TObject *Sender)  // selection Id idev
{
    Form1->ComboBox3->Clear();
    controllerIdev *idev = new controllerIdev();
    int* id = new int[100];
    int dim;
    idev->selectionId(id, &dim);
    if (dim > 0) {
        // Ajouter chaque ID au ComboBox
        for(int i=0; i<dim; i++)
        {
            Form1->ComboBox3->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    } else {

        Form1->ComboBox3->Items->Add("Aucun ID trouvé ");
    }
    delete idev;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox3Change(TObject *Sender)   // selection Nom idev
{
    String text = Form1->ComboBox3->Text.Trim();

    if (!text.IsEmpty())
    {
        // Tentative de conversion du texte en entier
        int id;
        if (TryStrToInt(text, id))
        {
            String nom;
            controllerIdev *idev = new controllerIdev();
            idev->selectionNom(id, &nom);


            Form1->inputName->Text = nom;

            delete idev;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) // insertion Note idev
{
    // Vï¿½rifier si tous les champs sont vides
    if (Form1->inputJava->Text.Trim().IsEmpty() && 
        Form1->inputPhp->Text.Trim().IsEmpty() &&
        Form1->inputCpp->Text.Trim().IsEmpty()) {
        ShowMessage("Veuillez entrer au moins une note avant d'ajouter.");
        return;
    }
    else
    {
      int id = StrToInt(Form1->ComboBox3->Text);
      float java = StrToFloat(Form1->inputJava->Text);
      float php = StrToFloat(Form1->inputPhp->Text);
     float cpp = StrToFloat(Form1->inputCpp->Text);


      controllerIdev *idev = new controllerIdev();
      try {
        idev->insertionNote(id, java, php, cpp);
        Button11Click(Sender);
     } catch (...) {
        ShowMessage("Erreur lors de l'ajout des notes.");
      }
      delete idev;
      // Rï¿½initialiser les champs de saisie des notes
      Form1->ComboBox3->Text = " ";
      Form1->inputName->Text = " ";
      Form1->inputCpp->Text = " ";
      Form1->inputPhp->Text = " ";
      Form1->inputJava->Text = " ";
    }
}



//---------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)   // button effacer idev
{
        Form1->inputCpp->Text = "0";
        Form1->inputPhp->Text = "0";
        Form1->inputJava->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2DropDown(TObject *Sender)   //  selection ID  modifier idev
{
    Form1->ComboBox2->Clear();
    controllerIdev *idev = new controllerIdev();
    int* id = new int[1000];
    int dim;
    idev->selectionIdModif(id,&dim);
    if (dim > 0) {
        // Ajouter chaque ID au ComboBox
        for(int i=0; i<dim; i++)
        {
            Form1->ComboBox2->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    }
    delete idev;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)   // Selection nom  idev   modifier
{
    String text = Form1->ComboBox2->Text.Trim();

    if (!text.IsEmpty())
    {

        int id;
        if (TryStrToInt(text, id))
        {

            String nom;
            controllerIdev *idev = new controllerIdev();
            idev->selectionNom(id, &nom);

            delete idev;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)       // Mise à jour notes idev
{
    String text = Form1->ComboBox2->Text.Trim();

    if (!text.IsEmpty())
    {
        // Tentative de conversion du texte en entier
        int id;
        if (TryStrToInt(text, id))
        {
            // La conversion a réussi, continuer avec le traitement
            String nom;
            float java = 0;
            float php = 0;
            float cpp = 0;
            controllerIdev *idev = new controllerIdev();
            idev->selectionNom(id, &nom);
            idev->selectionNote(id, &java, &php, &cpp);

            Form1->nomModif->Text = nom ;
            Form1->javaModif->Text = FloatToStr(java) ;
            Form1->phpModif->Text = FloatToStr(php) ;
            Form1->cppModif->Text = FloatToStr(cpp) ;

            delete idev;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)    // button modifier notes idev
{
    int id = StrToInt(Form1->ComboBox2->Text);
    float java = StrToFloat(Form1->javaModif->Text);
    float php = StrToFloat(Form1->phpModif->Text);
    float cpp = StrToFloat(Form1->cppModif->Text);

    controllerIdev *idev = new controllerIdev();
    idev->updateDesNotes(id, java, php, cpp);
    // actualiser les données
    Button11Click(Sender);
    Form1->javaModif->Text= " ";
    Form1->phpModif->Text = " ";
    Form1->cppModif->Text = " ";
    delete idev;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox4DropDown(TObject *Sender)  //  selection ID supprimer idev
{
     Form1->ComboBox4->Clear();
    controllerIdev *idev = new controllerIdev();
    int* id = new int[1000];
    int dim;
    idev->selectionIdModif(id,&dim);
    if (dim > 0) {
        // Ajouter chaque ID au ComboBox
        for(int i=0; i<dim; i++)
        {
            Form1->ComboBox4->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    }
    delete idev;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox4Change(TObject *Sender)  // selection Nom  supprimer idev
{
     String text = Form1->ComboBox4->Text.Trim();

    if (!text.IsEmpty())
    {

        int id;
        if (TryStrToInt(text, id))
        {

            String nom;
            controllerIdev *idev = new controllerIdev();
            idev->selectionNom(id, &nom);


            Form1->nomSuppr->Text = nom;

            delete idev;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)       //  supprimer étudiant idev
{
    int id = StrToInt(Form1->ComboBox4->Text);
    controllerIdev *idev = new controllerIdev();

    try {

        idev->supprimerEtudiant(id);
        ShowMessage("L'étudiant a été supprimé avec succés.");

        // Actualiser les donnï¿½es dans le StringGrid
        Button11Click(Sender);
    } catch (...) {
        ShowMessage("Erreur lors de la suppression de l'étudiant.");
    }

    delete idev;
}

//---------------------------------------------------------------------------




void __fastcall TForm1::ajoutRsiClick(TObject *Sender)  // insertion nom RSI
{
     String nom = Form1->inputNomRsi->Text;
       if (nom.Trim().IsEmpty()) {
        ShowMessage("Veuillez entrer un nom avant d'ajouter un Etudiant.");
        return;
       }

       controllerRsi *rsi = new controllerRsi();
       try {
            rsi->insertionNom(nom);
       } catch(...){
          ShowMessage("Erreur lors de l'ajout de l'étudiant.");
       }
       delete rsi ;

       Form1->inputNomRsi->Text= " ";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1DropDown(TObject *Sender) // selection id RSi
{
     Form1->ComboBox1->Clear();
    controllerRsi *rsi = new controllerRsi();
    int *id = new int[1000];
    int dim;
    rsi->selectionId(id, &dim);
    if (dim > 0)
    {
        // Ajouter chaque ID au ComboBox
        for (int i = 0; i < dim; i++)
        {
            Form1->ComboBox1->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    }
    else
    {
        Form1->ComboBox1->Items->Add("Aucun ID trouvé ");
    }
    delete rsi;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender) // selection de Nom RSI
{
    String text = Form1->ComboBox1->Text.Trim();
    if (!text.IsEmpty())
    {
        // Tentative de conversion du texte en entier
        int id;
        if (TryStrToInt(text, id))
        {
            String nom;
            controllerRsi *rsi = new controllerRsi();
            rsi->selectionNom(id, &nom);

            Form1->inputnomRsiSelect->Text = nom;

            delete rsi;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ajouterNoteClick(TObject *Sender)  // insertionNote   RSI
{
        if (Form1->inputreseaux ->Text.Trim().IsEmpty() &&
        Form1->inputcommutaiton ->Text.Trim().IsEmpty() )
        {
           ShowMessage("Veuillez entrer au moins une note avant d'ajouter.");
           return;
        }

        int id = StrToInt(Form1->ComboBox1->Text);
        float reseaux = StrToFloatDef(Form1->inputreseaux ->Text, 0.0);
        float commutation = StrToFloatDef(Form1->inputcommutaiton ->Text, 0.0);

        controllerRsi *rsi = new controllerRsi();
        try
        {
             rsi->insertionNote(id,reseaux,commutation) ;
             actualiserRsiClick(Sender) ;

        }
        catch (...)
         {
           ShowMessage("Erreur lors de l'ajout des notes.");
         }

         delete rsi;

          Form1->ComboBox1->Text = " ";
          Form1->inputnomRsiSelect->Text = " " ;
          Form1->inputreseaux ->Text = " " ;
          Form1->inputcommutaiton ->Text = " ";


}
//---------------------------------------------------------------------------


void __fastcall TForm1::effacerNoteClick(TObject *Sender) // button effacer champ note rsi 
{
          Form1->inputreseaux ->Text = "0" ;
          Form1->inputcommutaiton ->Text = "0";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox5DropDown(TObject *Sender)   // // sélection ID à modifier RSI
{
    Form1->ComboBox5->Clear();
    controllerRsi *rsi = new controllerRsi();
    int *id = new int[1000];
    int dim;
    rsi->selectionIdModif(id, &dim);
    if (dim > 0)
    {
        // Ajouter chaque ID au ComboBox
        for (int i = 0; i < dim; i++)
        {
            Form1->ComboBox5->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    }
    delete rsi;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox5Change(TObject *Sender) // Sélection du nom RSI
{
    String text = Form1->ComboBox5->Text.Trim();

    if (!text.IsEmpty())
    {
        int id;
        if (TryStrToInt(text, id))
        {
            String nom;
            controllerRsi *rsi = new controllerRsi();
            rsi->selectionNom(id, &nom);
          //  Form1->inputnomRsiModif->Text = nom;
            delete rsi;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::validerIdmodifClick(TObject *Sender) // mise à jour note afficher
{
    String text = Form1->ComboBox5->Text.Trim();

    // Vérifier si le texte n'est pas vide
    if (!text.IsEmpty())
    {

        int id;
        if (TryStrToInt(text, id))
        {

            String nom;
            float reseaux = 0;
            float commutation = 0;
            controllerRsi *rsi = new controllerRsi();
            rsi->selectionNom(id, &nom);
            rsi->selectionNote(id, &reseaux, &commutation);

            // Mettre à jour les champs d'entré e avec les valeurs sélectionnées
            Form1->inputnomRsiModif->Text = nom;
            Form1->rinputeseauxModif->Text = FloatToStr(reseaux);
            Form1->inputcomModif->Text = FloatToStr(commutation);

            delete rsi; // Libérer la mémoire alloué  pour rsi
        }
        else
        {
            // La conversion a é choué , afficher un message d'erreur
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::modifierNoteClick(TObject *Sender) // Bouton modifier notes RSI
{
    int id = StrToInt(Form1->ComboBox5->Text);
    float reseaux = StrToFloat(Form1->rinputeseauxModif->Text);
    float commutation = StrToFloat(Form1->inputcomModif->Text);

    controllerRsi *rsi = new controllerRsi();
    rsi->updateDesNotes(id, reseaux, commutation);
    actualiserRsiClick(Sender) ;
    delete rsi;

   Form1->ComboBox5->Text = "";
   Form1->rinputeseauxModif->Text = "";
   Form1->inputcomModif->Text = "";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox6DropDown(TObject *Sender)  //  selection ID supprimer rsi
{
    Form1->ComboBox6->Clear();
    controllerRsi *rsi = new controllerRsi();
    int *id = new int[1000];
    int dim;
    rsi->selectionIdModif(id, &dim);
    if (dim > 0)
    {
        // Ajouter chaque ID au ComboBox
        for (int i = 0; i < dim; i++)
        {
            Form1->ComboBox6->Items->Add(IntToStr(id[i]));
        }
        delete[] id;
    }
    delete rsi;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox6Change(TObject *Sender)  // selection Nom  supprimer rsi
{
    String text = Form1->ComboBox6->Text.Trim();

    if (!text.IsEmpty())
    {
        int id;
        if (TryStrToInt(text, id))
        {
            String nom;
            controllerRsi *rsi = new controllerRsi();
            rsi->selectionNom(id, &nom);
            Form1->inputnomRsiSuppr->Text = nom;
            delete rsi;
        }
        else
        {
            ShowMessage("Erreur de conversion de texte en entier !");
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SupprRsiClick(TObject *Sender)  // supprimer rsi 
{
    int id = StrToInt(Form1->ComboBox6->Text);
    controllerRsi *rsi = new controllerRsi();

    try
    {
        rsi->supprimerEtudiant(id);
        ShowMessage("L'étudiant a été supprimé avec succés.");
        actualiserRsiClick(Sender) ;
        
    }
    catch (...)
    {
        ShowMessage("Erreur lors de la suppression de l'étudiant.");
    }

    delete rsi;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actualiserRsiClick(TObject *Sender)
{
    try {
        Query2->Close(); // Query2 est votre TQuery pour RSI
        Query2->SQL->Text = "SELECT etudiant.id, etudiant.nom, rsi.reseaux, rsi.commutation, rsi.moyenne, rsi.mention FROM etudiant INNER JOIN rsi ON etudiant.id = rsi.id_etudiant";
        Query2->Open();

        // Remplit les donnï¿½es dans StringGrid2 pour RSI
        int row = 1;
        while (!Query2->Eof) {
            for (int col = 0; col < Query2->FieldCount; ++col) {
                StringGrid2->Cells[col][row] = Query2->Fields->Fields[col]->AsString;
            }
            Query2->Next();
            ++row;
        }
    } catch (Exception &ex) {
        ShowMessage("Erreur lors de l'exécution de la requétte : " + ex.Message);
    }        
}
//---------------------------------------------------------------------------

