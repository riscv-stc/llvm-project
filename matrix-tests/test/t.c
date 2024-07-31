#include <riscv_vector.h>
#include <riscv_matrix.h>

int main() {
  const int8_t i8_src[] = {72, 28, -48, 105, 2, -30, 43, 42, 116, 45, -44, -117};
  int8_t i8_buffer[20];
  msettype(E8, M1, BA);
  msettilemi(3);
  msettileki(4);
  vsetvl_e8m1(12);
  vint8m1_t i8_v1 = mlae8_v(i8_src, 4 * sizeof(int8_t));
  mint8m1_t i8_m1 = mmvar_m_v(i8_v1, 0);
  msae8_m(i8_m1, i8_buffer, 4 * sizeof(int8_t));
  // EXCEPT_I8_ARRAY_EQ(i8_src, i8_buffer, 12, "MMVAR.M.V INT8  ");
}
