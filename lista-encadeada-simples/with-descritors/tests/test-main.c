#include "../les-descritor.h"
#include "minunit.h"
#include <stdio.h>

int tests_run = 0;

// Tests for: Inicializar_LS

static char *initialize_list_test() {
  Tdescritorno_ls desc;

  mu_assert("error: initialize list failed", Inicializar_LS(&desc) == 0);
  return 0;
}

// Tests for: Obter_dado_LS

static char *empty_list_test() {
  Tdescritorno_ls desc;
  int pos;
  int dado;

  mu_assert("error: get data from empty list",
            Obter_dado_LS(desc, pos, &dado) == 1);
  return 0;
}

static char *given_position_above_list_size_test() {
  Tdescritorno_ls desc;
  Inicializar_LS(&desc);
  int pos = 1;
  int dado;

  Inserir_inicio_LS(&desc, 3);

  mu_assert("error: get data from position above list size",
            Obter_dado_LS(desc, pos, &dado) == 2);
  return 0;
}

static char *given_valid_position_return_data_test() {
  Tdescritorno_ls desc;
  Inicializar_LS(&desc);

  Inserir_inicio_LS(&desc, 7);
  Inserir_inicio_LS(&desc, 9);

  int dado;
  int pos = 0;
  mu_assert("error: get data from valid position",
            Obter_dado_LS(desc, pos, &dado) == 0);
  mu_assert("error: get data from valid position", dado == 9);

  pos = 1;
  mu_assert("error: get data from valid position",
            Obter_dado_LS(desc, pos, &dado) == 0);
  mu_assert("error: get data from valid position", dado == 7);
  return 0;
}

// UNIT TESTS RUNNER

static char *all_tests() {
  // Inicializar_LS
  mu_run_test(initialize_list_test);
  // Obter_dado_LS
  mu_run_test(empty_list_test);
  mu_run_test(given_position_above_list_size_test);
  mu_run_test(given_valid_position_return_data_test);

  return 0;
}

int main(int argc, char **argv) {
  clearConsole();
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n\n", tests_run);

  return result != 0;
}