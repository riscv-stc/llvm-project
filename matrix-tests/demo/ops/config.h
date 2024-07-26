#ifndef MATRIX_TEST_DEMO_OPS_CONFIG_H_
#define MATRIX_TEST_DEMO_OPS_CONFIG_H_

typedef struct {
  int kernel_size[2]; /// [H, W]
  int stride[2];      /// [H, W]
  int dilation[2];    /// [H, W]
  int padding[4];     /// [Top, Bottom, Left, Right]
  int in_shape[3];    /// [H, W, C]
  int out_shape[3];   /// [H, W, C]
} Conv2dConfig, Pool2dConfig;

/**
 * @brief Determine the length of the H(W)-dimension in the output tensor
 * subsequent to the convolution operation.
 *
 * @param _l  The length of the H(W)-dimension within the input tensor.
 * @param _p1 Top(Left) padding size
 * @param _p2 Bottom(Right) padding size
 * @param _d  Dilation size in dimension H(W)
 * @param _k  Kernel size in dimension H(W)
 * @param _s  Stride in dimension H(W)
 */
#define calcConv2dOutputLen(_l, _p1, _p2, _d, _k, _s)                          \
  (((_l) + (_p1) + (_p2) - (_d) * ((_k)-1) - 1) / (_s) + 1)

/**
 * @brief Create a default conv2d configuration that adheres to the following
 * conditions: [1] Kernel height equals kernel width. [2] Stride height equals
 * stride width. [3] Dilation is set to one. [4] All four directions - left,
 * right, top, and bottom - are evenly and symmetrically filled with equal
 * lengths. [5] Padding value is set to zero.
 * @param _name Configuration Name
 * @param _cin  Number of channels for input tensor
 * @param _hin  The height of the input tensor
 * @param _win  The width of the input tensor
 * @param _cout Number of channels for output tensor
 * @param _ks   kernel size
 * @param _s    stride
 */
#define createDefaultConv2dConfig(_name, _cin, _hin, _win, _cout, _ks, _s, _p) \
  Conv2dConfig _name = {{_ks, _ks},                                            \
                        {_s, _s},                                              \
                        {1, 1},                                                \
                        {_p, _p, _p, _p},                                      \
                        {_hin, _win, _cin},                                    \
                        {calcConv2dOutputLen(_hin, _p, _p, 1, _ks, _s),        \
                         calcConv2dOutputLen(_win, _p, _p, 1, _ks, _s),        \
                         _cout}};

#define createDefaultPool2dConfig(_name, _cin, _hin, _win, _ks, _s, _p) \
  createDefaultConv2dConfig(_name, _cin, _hin, _win, _cin, _ks, _s, _p)

#endif // MATRIX_TEST_DEMO_OPS_CONFIG_H_