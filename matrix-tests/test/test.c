#include <riscv_matrix.h>
#include <stdio.h>

char a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
char b[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
char c[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() {
	float fa = 7.0;
	printf("hello riscv matrix clang %f ==================== \n", fa);

	msettype(E8, M1, BA);
	msettilemi(3);
	msettileni(3);
	msettileki(3);

        mint8m1_t m1 = mlce8_m1((const int8_t *)a, 3);
        mint8m1_t m2 = mlce8_m1((const int8_t *)b, 3);
        mint8m1_t mo = madd_mm(m1, m2);
        msce8_m(mo, (int8_t *)c, 3);

        for (int i = 0; i < 9; i++) {
          printf("out: %d\n", c[i]);
        }

        return 0;
}
