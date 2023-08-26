#include "../les-descritor.h"
#include "minunit.h"
#include <stdio.h>

int tests_run = 0;
Tdescritorno_ls desc;
int pos;
int dado;

void cleanList() { Inicializar2_LS(&desc); }

// Tests for: Inicializar_LS

static char *initialize_list_test() {
  mu_assert("error: initialize list failed", Inicializar_LS(&desc) == 0);
  return 0;
}

// Tests for: Obter_dado_LS

static char *given_empty_list_when_get_data_test() {
  mu_assert("error: get data from empty list",
            Obter_dado_LS(desc, pos, &dado) == 1);
  return 0;
}

static char *given_position_equal_list_size_test() {
  Inserir_inicio_LS(&desc, 3);

  mu_assert("error: get data from position equal list size",
            Obter_dado_LS(desc, 1, &dado) == 2);
  return 0;
}

static char *given_position_above_list_size_test() {
  Inserir_inicio_LS(&desc, 3);

  mu_assert("error: get data from position above list size",
            Obter_dado_LS(desc, 3, &dado) == 2);
  return 0;
}

static char *given_valid_position_return_data_test() {
  Inserir_inicio_LS(&desc, 7);
  Inserir_inicio_LS(&desc, 9);

  mu_assert("error: get data from valid position '0'",
            Obter_dado_LS(desc, 0, &dado) == 0);
  mu_assert("error: get data from valid position", dado == 9);

  mu_assert("error: get data from valid position '1'",
            Obter_dado_LS(desc, 1, &dado) == 0);
  mu_assert("error: get data from valid position '1'", dado == 7);
  return 0;
}

// Tests for: Remover_fim_LS

static char *given_empty_list_when_remove_end_test() {
  mu_assert("error: remove end from empty list", Remover_fim_LS(&desc) == 1);
  return 0;
}

static char *given_valid_list_size_when_remove_end_test() {
  Inserir_inicio_LS(&desc, 12);

  mu_assert("error: remove end valid list size", Remover_fim_LS(&desc) == 0);
  mu_assert("error: remove end valid list size", desc.tam == 0);

  Inserir_inicio_LS(&desc, 75);
  Inserir_inicio_LS(&desc, 34);

  mu_assert("error: remove end valid list size", desc.tam == 2);
  mu_assert("error: remove end valid list size", Remover_fim_LS(&desc) == 0);
  mu_assert("error: remove end valid list size", desc.tam == 1);
  mu_assert("error: remove end valid list size", desc.ult->dado == 75);

  return 0;
}

// Tests for: Remover_meio_LS

static char *given_empty_list_when_remove_position_test() {
  mu_assert("error: remove end valid list size", desc.tam == 0);
  mu_assert("error: remove position from empty list",
            Remover_meio_LS(&desc, 3) == 1);
  return 0;
}

static char *given_position_equal_list_size_when_remove_position_test() {
  Inserir_inicio_LS(&desc, 75);

  mu_assert("error: remove position equal list size",
            Remover_meio_LS(&desc, 1) == 2);
  return 0;
}

static char *given_position_above_list_size_when_remove_position_test() {
  Inserir_inicio_LS(&desc, 12);

  mu_assert("error: remove position above list size",
            Remover_meio_LS(&desc, 5) == 2);
  return 0;
}

static char *given_1_node_and_position_0_when_remove_position_test() {
  Inserir_inicio_LS(&desc, 12);

  mu_assert("error: remove valid position '0'", Remover_meio_LS(&desc, 0) == 0);
  mu_assert("error: remove valid position'0'", desc.tam == 0);

  return 0;
}

static char *given_valid_position_when_remove_position_test() {
  Inserir_inicio_LS(&desc, 54);
  Inserir_inicio_LS(&desc, 32);
  Inserir_inicio_LS(&desc, 87);
  Inserir_inicio_LS(&desc, 76);

  mu_assert("error: remove valid position '2'", Remover_meio_LS(&desc, 2) == 0);
  mu_assert("error: remove valid position '2'", desc.tam == 3);

  return 0;
}

// UNIT TESTS RUNNER

static char *all_tests() {
  // Inicializar_LS
  mu_run_test(initialize_list_test);
  cleanList();

  // Obter_dado_LS
  mu_run_test(given_empty_list_when_get_data_test);
  cleanList();

  mu_run_test(given_position_equal_list_size_test);
  cleanList();

  mu_run_test(given_position_above_list_size_test);
  cleanList();

  mu_run_test(given_valid_position_return_data_test);
  cleanList();

  // Remover_fim_LS
  mu_run_test(given_empty_list_when_remove_end_test);
  cleanList();

  mu_run_test(given_valid_list_size_when_remove_end_test);
  cleanList();

  // Remover_meio_LS
  mu_run_test(given_empty_list_when_remove_position_test);
  cleanList();

  mu_run_test(given_position_equal_list_size_when_remove_position_test);
  cleanList();

  mu_run_test(given_position_above_list_size_when_remove_position_test);
  cleanList();

  mu_run_test(given_1_node_and_position_0_when_remove_position_test);
  cleanList();

  mu_run_test(given_valid_position_when_remove_position_test);
  cleanList();

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