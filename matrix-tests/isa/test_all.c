#include "mma.h"
#include "data_move.h"
#include "load_store.h"
#include "eletwise.h"
#include "cvt.h"
#include "zmv.h"
#include "zmi2c.h"

int main() {
  test_load_store();
  test_data_move();
  test_matmul();
  test_eletwise();
  test_cvt();
  test_zmv();
  test_zmi2c();
  printf("[pass/total]: [%d/%d]\n", pass_cases, test_cases);
}
