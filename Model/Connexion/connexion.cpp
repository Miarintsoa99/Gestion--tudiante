//---------------------------------------------------------------------------


#pragma hdrstop

#include "connexion.h"
#include "etudiant.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//=====================================================================
connexion::connexion(String sq)
{
      Form1->Query1->Close();
      Form1->Query1->SQL->Clear();
      Form1->Query1->SQL->Add(sq);
      Form1->Query1->ExecSQL();
}
//=================================================================
