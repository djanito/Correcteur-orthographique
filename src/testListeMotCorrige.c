#include<CUnit/Basic.h>
#include"listeDeMotCorrige.h"
#include "motCorrige.h"
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
  ListeDeMotCorrige listeMotCorrige;
  MotCorrige motCorrige;
  Mot mot;
  char  chaine [] = "eau";
  unsigned int indice = 0;
  mot =  Mot_genererMot(chaine);
  motCorrige = Un_motCorrige();
  MotCorrige_fixerMot(&motCorrige,mot);
  ListeDeMotCorrige_ajouter(&listeMotCorrige, motCorrige);
  CU_ASSERT_TRUE(Mot_sontEgaux(MotCorrige_obtenirMot(ListeDeMotCorrige_obtenir(listeMotCorrige, indice)),mot)) ;
}

void testInserer(void){
  ListeDeMotCorrige listeMotCorrige;
  MotCorrige motCorrige0;
  MotCorrige motCorrige1;
  Mot mot0;
  Mot mot1;
  char  chaine0 [] = "eau";
  char  chaine1 [] = "douce";
  unsigned int indice = 0;
  mot0 =  Mot_genererMot(chaine0);
  mot1 =  Mot_genererMot(chaine1);
  motCorrige0 = Un_motCorrige();
  motCorrige1 = Un_motCorrige();
  MotCorrige_fixerMot(&motCorrige0,mot0);
  MotCorrige_fixerMot(&motCorrige1,mot1);
  listeMotCorrige = ListeDeMotCorrige_liste();
  ListeDeMotCorrige_ajouter(&listeMotCorrige, motCorrige0);
  ListeDeMotCorrige_inserer(&listeMotCorrige,motCorrige1,indice);
  CU_ASSERT_TRUE(Mot_sontEgaux(MotCorrige_obtenirMot(ListeDeMotCorrige_obtenir(listeMotCorrige, indice)),mot1)) ;
}

int main(int argc, char** argv){
  
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests Liste de Mot Corrige", init_success, clean_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if  (  (NULL == CU_add_test(pSuite, "Ajouter", testAjouter))
	  || (NULL == CU_add_test(pSuite, "Inserer",  testInserer))
	  
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
