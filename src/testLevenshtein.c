#include<CUnit/Basic.h>
#include"levenshtein.h"
#define TRUE 1
#define FALSE 0

int init_success(void){ 
    return 0 ; 
}

int clean_success(void){ 
    return 0 ; 
}

void testLevenshtein(void){
  const char a = 'a';
  const char b = 'b';
  size_t taille = 0;
  taille = levenshtein(&a,&b);
  CU_ASSERT_TRUE(taille == 1) ;
}

void testDamerauLevenshtein(void){
  const char a = 'a';
  const char b = 'b';
  size_t taille = 0;
  taille = damerau_levenshtein(&a,&b);
  CU_ASSERT_TRUE(taille == 1) ;
}


int main(int argc, char** argv){
  
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests des tris", init_success, clean_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if  (  (NULL == CU_add_test(pSuite, "Levenshtein", testLevenshtein))
     || (NULL == CU_add_test(pSuite, "Damerau Levenshtein", testDamerauLevenshtein))
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
