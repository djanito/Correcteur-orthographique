#include<CUnit/Basic.h>
#include"mot.h"
int init_success(void){ 
    return 0 ; 
}

int clean_success(void){ 
    return 0 ; 
}

void testMot_genererMot(void){
  Mot motFinal;
  char chaine[] = "eau";
  motFinal = Mot_genererMot(chaine);
  
  CU_ASSERT_TRUE(Mot_longueur(motFinal) == 3 && Mot_obtenirContenu(motFinal) == chaine) ;
}

void testMot_sontEgaux(void){
  Mot mot1;
  Mot mot2;
  char chaine[] = "eau";
  unsigned int resultat;
  mot1 = Mot_genererMot(chaine);
  mot2 = Mot_genererMot(chaine);
  resultat = Mot_sontEgaux(mot1, mot2);
  CU_ASSERT_TRUE(resultat == 1) ;
}

int main(int argc, char** argv){
  
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests du TAD Mot", init_success, clean_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if  (  (NULL == CU_add_test(pSuite, "Generer Mot",testMot_genererMot ))
	|| (NULL == CU_add_test(pSuite, "Mots sont égaux", testMot_sontEgaux))
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
