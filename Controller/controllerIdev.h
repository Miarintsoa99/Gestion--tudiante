//---------------------------------------------------------------------------

#ifndef controllerIdevH
#define controllerIdevH
#include <StdCtrls.hpp>
#include "transactionIdev.h"
//---------------------------------------------------------------------------
class controllerIdev
{
    public:
        controllerIdev();
        void insertionNom(String);
        void insertionNote(int , float , float , float ) ;
        void updateDesNotes(int , float , float , float);
        
        void selectionId(int* , int*);
        void selectionIdModif(int*, int*);
        void selectionNom(int,String*) ;
        void selectionNote(int , float* , float* , float* );

        void supprimerEtudiant(int );


};

#endif

