#ifndef MATRIX_TESTS_DEMO_TENSOR_H_
#define MATRIX_TESTS_DEMO_TENSOR_H_

typedef struct {
  void *data;
  int shape[4];
  int size;
} Tensor;

#define createTensor3d(_name, _data, _d1, _d2, _d3)                            \
  Tensor _name = {(void *)(_data), {_d1, _d2, _d3}, _d1 * _d2 * _d3}

#define createTensor4d(_name, _data, _d1, _d2, _d3, _d4)                       \
  Tensor _name = {(void *)(_data), {_d1, _d2, _d3, d4}, _d1 * _d2 * _d3 * _d4}

#define INCBIN(var, binfile, section) \
    __asm__(".section " section ", \"a\", @progbits\n\t" \
            ".type " #var ", @object\n\t" \
            ".global " #var "\n\t" \
            ".align 8\n" \
            #var ":\n\t" \
            ".incbin \"" binfile "\"" "\n\t" \
            ".align 8\n")

#endif // MATRIX_TESTS_DEMO_TENSOR_H_