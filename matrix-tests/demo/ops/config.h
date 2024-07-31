#ifndef _CONFIG_H_
#define _CONFIG_H_

typedef struct {
  int stride[2];      // [H, W]
  int padding[4];     // [T, B, L, R]
  int dilation[2];    // [H, W]
  int kernel_size[2]; // [H, W]
} Conv2dConfig, Pool2dConfig;

#define create_conv2d_default_config(_name, _s, _p, _d, _k)                    \
  Conv2dConfig _name = {.stride = {_s, _s},                                    \
                        .padding = {_p, _p, _p, _p},                           \
                        .dilation = {_d, _d},                                  \
                        .kernel_size = {_k, _k}};

#endif // _CONFIG_H_