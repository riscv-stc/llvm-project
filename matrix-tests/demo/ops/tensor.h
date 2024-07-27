#ifndef _TENSOR_H_
#define _TENSOR_H_

typedef struct {
  void *data;
  int shape[4]; // Feature Map: [N, H, W, C], Weight: [H, W, Cin, Cout]
  int size;
} Tensor;

#define create_tensor2d(_name, _data, d1, d2)                                  \
  Tensor _name = {                                                             \
      .data = (void *)_data, .shape = {1, d1, d2, 1}, .size = (d1 * d2)}

#define create_tensor3d(_name, _data, d1, d2, d3)                              \
  Tensor _name = {                                                             \
      .data = (void *)_data, .shape = {1, d1, d2, d3}, .size = (d1 * d2 * d3)}

#define create_tensor4d(_name, _data, d1, d2, d3, d4)                          \
  Tensor _name = {.data = (void *)_data,                                       \
                  .shape = {d1, d2, d3, d4},                                   \
                  .size = (d1 * d2 * d3 * d4)}

#define INCBIN(var, binfile, section)                                          \
  __asm__(".section " section ", \"a\", @progbits\n\t"                         \
          ".type " #var ", @object\n\t"                                        \
          ".global " #var "\n\t"                                               \
          ".align 8\n" #var ":\n\t"                                            \
          ".incbin \"" binfile "\""                                            \
          "\n\t"                                                               \
          ".align 8\n")

#endif // _TENSOR_H_