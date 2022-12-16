#include<CUnit/Basic.h>
#include"listeDeMot.h"
#include"mot.h"
#define TRUE 1
#define FALSE 0

int init_success(void){ 
    return 0 ; 
}

int clean_success(void){ 
    return 0 ; 
}

void testAjouter(void){
  Mot motAAjouter ;
  Mot motAttendu;
  char chaine[] = "eau";
  ListeDeMot listeInit ;
  unsigned int indice = 0;
  listeInit = ListeDeMot_liste();
  motAAjouter = Mot_genererMot(chaine);
  motAttendu = Mot_genererMot(chaine);
  ListeDeMot_ajouter(&listeInit,motAAjouter);
  CU_ASSERT_TRUE(Mot_sontEgaux(ListeDeMot_obtenir(listeInit,indice), motAttendu)) ;
}

void testSupprimer(void){
  Mot motAAjouter;
  char chaine[] = "eau";
  ListeDeMot listeInit ;
  unsigned int indice = 0;
  listeInit = ListeDeMot_liste();
  motAAjouter = Mot_genererMot(chaine);
  ListeDeMot_ajouter(&listeInit,motAAjouter);
  ListeDeMot_supprimer(&listeInit,indice);
  CU_ASSERT_TRUE(ListeDeMot_estVide(listeInit)) ;
}

void testEstPresent(void){
  Mot motDansLaListe;
  Mot motATrouver;
  char chaine[] = "eau";
  ListeDeMot liste ;
  unsigned int resultat = 0;
  liste = ListeDeMot_liste();
  motDansLaListe = Mot_genererMot(chaine);
  motATrouver =  Mot_genererMot(chaine);
  ListeDeMot_ajouter(&liste,motDansLaListe);
  resultat = ListeDeMot_estPresent(liste, motATrouver);
  CU_ASSERT_TRUE(resultat == 1) ;
}

int main(int argc, char** argv){
  
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests de liste de mot", init_success, clean_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if  (  (NULL == CU_add_test(pSuite, "Ajouter", testAjouter))
	 || (NULL == CU_add_test(pSuite, "Supprimer", testSupprimer))
    	 || (NULL == CU_add_test(pSuite, "Est Present", testEstPresent))
      ){
      CU_cleanup_registry() ;
      return CU_get_error() ;
    }

  CU_basic_set_mode(CU_BRM_VERBOSE) ;
  CU_basic_run_tests() ;
  printf("\n") ;
  CU_basic_show_failures(CU_get_failure_list()) ;
  printf("\n\n") ;

  CU_cleanup_registry() ;
  return CU_get_error() ;
  return 0 ;
}
