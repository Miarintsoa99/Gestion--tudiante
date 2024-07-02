#ifndef entiteEtudiantH
#define entiteEtudiantH

#include <StdCtrls.hpp>
#include <Vcl.h>

class Etudiant
{
   private:
      int id;
      String nom;
      float moyenne;
      String mention;
    

   public:
      // getters et setters
      void setId(int id);
      int getId();

      void setNom(String);
      String getNom();

      void setMoyenne(float moyenne);
      float getMoyenne();

      void setMention(String mention)  ;
      String getMention();

      String attribuerMention();

};

#endif

