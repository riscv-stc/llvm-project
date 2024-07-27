      
#include <riscv_matrix.h>
#include "isa/utils.h"

  float buffer[4];
  float src0[] = {10, 10, 10, 10};
  float src1[] = {1, 1, 1, 1};

int main() {
  msettype(E32, M4, BA);
  msettilemi(2);
  msettileni(2);

  mfloat32m4_t tr0 = mlce32_m4(src0, 8);
  mfloat32m4_t tr1 = mlce32_m4(src1, 8);

// tr0 -> sp; tr1 -> sp
  printf("hello\n");
// sp -> tr0; sp -> tr1

  mfloat32m4_t out = mfadd_mm(tr0, tr1);


  msce32_m(out, buffer, 8);
  for (int i = 0; i < 4; ++i) {
    printf("%f\n", buffer[i]);
  }
  return 0;
}

    
