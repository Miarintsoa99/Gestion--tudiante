#ifndef entiteIdevH
#define entiteIdevH

#include <vcl.h>
#include "entiteEtudiant.h"
//---------------------------------------------------------------------------
class Idev : public Etudiant
{
    private :
              int id ;
              float java ;
              float php;
              float cplusplus ;

    public :
            // setters
            void setId(int id);
            void setJava(float java);
            void setPhp(float php);
            void setCpp (float cplusplus);

            //getters
            int getId();
            float getJava();
            float getPhp();
            float getCpp();

            float calcMoyenne();

};

#endif

