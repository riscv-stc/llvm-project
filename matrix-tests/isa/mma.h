#include "utils.h"
#include <riscv_matrix.h>

static void test_mmau_mm_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint16_t srca[M * K] = {
      208, 66,  43,  170, 13,  4,   233, 225, 38,  156, 105, 105, 129,
      142, 243, 242, 70,  71,  113, 164, 196, 85,  80,  97,  170, 229,
      181, 163, 250, 222, 2,   233, 153, 14,  199, 64,  249, 21,  201,
      143, 147, 118, 13,  24,  220, 144, 29,  66,  21,  197, 148, 213,
      133, 95,  92,  150, 218, 161, 22,  52,  139, 224, 165, 219};
  const uint16_t srcb[K * N] = {
      116, 107, 0,   124, 52,  239, 60,  202, 39,  81,  90,  19,  180,
      200, 185, 20,  60,  221, 237, 72,  199, 163, 233, 226, 159, 91,
      119, 50,  87,  121, 146, 53,  243, 172, 155, 242, 242, 181, 81,
      72,  179, 126, 114, 124, 225, 140, 34,  149, 16,  135, 181, 252,
      218, 90,  4,   112, 200, 96,  42,  38,  227, 29,  234, 224};
  const uint16_t srcc[M * N] = {
      32,  151, 248, 46,  80,  241, 252, 108, 13,  71,  208, 100, 39,
      246, 160, 5,   254, 178, 9,   101, 189, 237, 144, 246, 5,   5,
      3,   24,  115, 22,  26,  4,   123, 231, 150, 210, 44,  84,  109,
      86,  138, 26,  5,   156, 38,  5,   236, 63,  95,  90,  158, 71,
      80,  167, 64,  25,  120, 211, 15,  218, 221, 93,  154, 137};
  const uint16_t answ[M * N] = {
      108947, 108521, 90703,  109596, 152038, 121140, 114552, 140200,
      142553, 145650, 141958, 139844, 231201, 142465, 143972, 151966,
      127522, 117850, 111320, 108284, 159380, 126819, 109536, 107501,
      212553, 185188, 157113, 144023, 264152, 218945, 200890, 191963,
      136615, 153876, 139565, 155924, 196951, 149878, 122739, 155239,
      119288, 96605,  75099,  103674, 140541, 128265, 75695,  91655,
      133757, 132051, 132708, 100574, 192282, 144486, 152822, 120579,
      161588, 141603, 112051, 145809, 219160, 171993, 126518, 166041};
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  muint16_t td = mlc_m(srcc, N * sizeof(uint16_t));
  muint16_t out1 = mmau_mm(td, ts1, ts2);
  muint16_t out2 = mmau_h_mm(td, ts1, ts2);
  msc_m(out1, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(answ, u16_buffer, M * N, "MMAU_MM U16");
}

static void test_mmau_h_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint16_t srca[M * K] = {
      208, 66,  43,  170, 13,  4,   233, 225, 38,  156, 105, 105, 129,
      142, 243, 242, 70,  71,  113, 164, 196, 85,  80,  97,  170, 229,
      181, 163, 250, 222, 2,   233, 153, 14,  199, 64,  249, 21,  201,
      143, 147, 118, 13,  24,  220, 144, 29,  66,  21,  197, 148, 213,
      133, 95,  92,  150, 218, 161, 22,  52,  139, 224, 165, 219};
  const uint16_t srcb[K * N] = {
      116, 107, 0,   124, 52,  239, 60,  202, 39,  81,  90,  19,  180,
      200, 185, 20,  60,  221, 237, 72,  199, 163, 233, 226, 159, 91,
      119, 50,  87,  121, 146, 53,  243, 172, 155, 242, 242, 181, 81,
      72,  179, 126, 114, 124, 225, 140, 34,  149, 16,  135, 181, 252,
      218, 90,  4,   112, 200, 96,  42,  38,  227, 29,  234, 224};
  const uint16_t srcc[M * N] = {
      32,  151, 248, 46,  80,  241, 252, 108, 13,  71,  208, 100, 39,
      246, 160, 5,   254, 178, 9,   101, 189, 237, 144, 246, 5,   5,
      3,   24,  115, 22,  26,  4,   123, 231, 150, 210, 44,  84,  109,
      86,  138, 26,  5,   156, 38,  5,   236, 63,  95,  90,  158, 71,
      80,  167, 64,  25,  120, 211, 15,  218, 221, 93,  154, 137};
  const uint16_t answ[M * N] = {
      108947, 108521, 90703,  109596, 152038, 121140, 114552, 140200,
      142553, 145650, 141958, 139844, 231201, 142465, 143972, 151966,
      127522, 117850, 111320, 108284, 159380, 126819, 109536, 107501,
      212553, 185188, 157113, 144023, 264152, 218945, 200890, 191963,
      136615, 153876, 139565, 155924, 196951, 149878, 122739, 155239,
      119288, 96605,  75099,  103674, 140541, 128265, 75695,  91655,
      133757, 132051, 132708, 100574, 192282, 144486, 152822, 120579,
      161588, 141603, 112051, 145809, 219160, 171993, 126518, 166041};
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  muint16_t td = mlc_m(srcc, N * sizeof(uint16_t));
  muint16_t out = mmau_h_mm(td, ts1, ts2);
  msc_m(out, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(answ, u16_buffer, M * N, "MMAU_H_MM U16");
}

static void test_mmau_mm_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {238, 181, 20,  69,  11,  134, 90,  250,
                                245, 148, 213, 147, 201, 1,   231, 158};
  const uint32_t srcb[K * N] = {55,  225, 218, 4,   184, 224, 159, 130,
                                206, 248, 104, 144, 161, 159, 244, 46};
  const uint32_t srcc[M * N] = {234, 70, 176, 185, 22, 209, 244, 70,
                                208, 6,  214, 136, 84, 54,  196, 155};
  const uint32_t answ[M * N] = {61857, 110095, 99755,  30721,  84073,  94770,
                                94308, 41994,  108460, 164480, 135176, 57790,
                                84347, 127913, 106749, 41621};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  muint32_t out = mmau_mm(td, ts1, ts2);
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MMAU_MM U32");
}

static void test_mmau_w_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {238, 181, 20,  69,  11,  134, 90,  250,
                                245, 148, 213, 147, 201, 1,   231, 158};
  const uint32_t srcb[K * N] = {55,  225, 218, 4,   184, 224, 159, 130,
                                206, 248, 104, 144, 161, 159, 244, 46};
  const uint32_t srcc[M * N] = {234, 70, 176, 185, 22, 209, 244, 70,
                                208, 6,  214, 136, 84, 54,  196, 155};
  const uint32_t answ[M * N] = {61857, 110095, 99755,  30721,  84073,  94770,
                                94308, 41994,  108460, 164480, 135176, 57790,
                                84347, 127913, 106749, 41621};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  muint32_t out = mmau_w_mm(td, ts1, ts2);
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MMAU_W_MM U32");
}

static void test_mmau_mm_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint64_t srca[M * K] = {14391, 1245, 40420, 53528};
  const uint64_t srcb[K * N] = {9135, 64269, 23780, 11522};
  const uint64_t srcc[M * N] = {25000, 60873, 42933, 25391};
  const uint64_t answ[M * N] = {161092885, 939300942, 1642175473, 3214527987};
  muint64_t ts1 = mla_m(srca, K * sizeof(uint64_t));
  muint64_t ts2 = mlb_m(srcb, N * sizeof(uint64_t));
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  muint64_t out = mmau_mm(td, ts1, ts2);
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MMAU_MM U64");
}

static void test_mmau_dw_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint64_t srca[M * K] = {14391, 1245, 40420, 53528};
  const uint64_t srcb[K * N] = {9135, 64269, 23780, 11522};
  const uint64_t srcc[M * N] = {25000, 60873, 42933, 25391};
  const uint64_t answ[M * N] = {161092885, 939300942, 1642175473, 3214527987};
  muint64_t ts1 = mla_m(srca, K * sizeof(uint64_t));
  muint64_t ts2 = mlb_m(srcb, N * sizeof(uint64_t));
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  muint64_t out = mmau_dw_mm(td, ts1, ts2);
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MMAU_DW_MM U64");
}

static void test_mwmau_mm_u16() {
  const uint16_t srca[] = {
      207, 276, 314, 481, 223, 394, 454, 246, 38,  387, 319, 186, 10,
      113, 91,  55,  634, 267, 638, 380, 497, 453, 7,   612, 70,  456,
      300, 24,  245, 142, 89,  87,  121, 76,  572, 160, 38,  638, 266,
      330, 292, 553, 231, 137, 484, 78,  129, 301, 404, 446, 141, 33,
      488, 594, 50,  356, 214, 99,  209, 439, 434, 420, 361, 443};
  const uint16_t srcb[] = {
      278, 600, 286, 315, 220, 98,  217, 350, 185, 104, 188, 506, 217,
      126, 167, 536, 649, 277, 209, 555, 160, 38,  298, 354, 544, 84,
      328, 88,  176, 648, 340, 470, 372, 649, 56,  568, 31,  422, 592,
      351, 595, 210, 527, 614, 345, 112, 267, 509, 613, 524, 235, 319,
      306, 112, 123, 195, 123, 169, 628, 590, 649, 629, 467, 199};
  const uint32_t srcc[] = {
      634, 222, 583, 579, 644, 389, 114, 111, 529, 64,  88,  291, 212,
      210, 402, 383, 390, 236, 405, 571, 258, 365, 534, 91,  155, 201,
      301, 56,  556, 35,  477, 91,  370, 149, 161, 636, 602, 182, 622,
      595, 564, 281, 108, 623, 258, 439, 483, 520, 210, 458, 258, 530,
      50,  394, 555, 552, 4,   133, 71,  284, 161, 530, 241, 51};
  const uint32_t answ[] = {
      1200636, 787445,  816371,  1080584, 682393, 722887,  756175,  974026,
      524406,  254298,  327427,  538037,  279163, 247009,  304548,  511178,
      1380805, 1141829, 1142451, 1646664, 937659, 1012825, 1203865, 1297732,
      552619,  424905,  340726,  727523,  307414, 275288,  423909,  579428,
      1103730, 606333,  829187,  1101617, 680248, 471886,  644097,  816989,
      751050,  757449,  568352,  1054227, 522308, 613048,  735404,  839932,
      913897,  858887,  815627,  1302515, 680482, 624912,  835839,  1000660,
      1139398, 867495,  876243,  1153336, 735755, 875657,  895106,  932997};
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I16();
  muint32_t out = mwmau_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MWMAU_MM U16");
}

static void test_mwmau_h_mm() {
  const uint16_t srca[] = {
      207, 276, 314, 481, 223, 394, 454, 246, 38,  387, 319, 186, 10,
      113, 91,  55,  634, 267, 638, 380, 497, 453, 7,   612, 70,  456,
      300, 24,  245, 142, 89,  87,  121, 76,  572, 160, 38,  638, 266,
      330, 292, 553, 231, 137, 484, 78,  129, 301, 404, 446, 141, 33,
      488, 594, 50,  356, 214, 99,  209, 439, 434, 420, 361, 443};
  const uint16_t srcb[] = {
      278, 600, 286, 315, 220, 98,  217, 350, 185, 104, 188, 506, 217,
      126, 167, 536, 649, 277, 209, 555, 160, 38,  298, 354, 544, 84,
      328, 88,  176, 648, 340, 470, 372, 649, 56,  568, 31,  422, 592,
      351, 595, 210, 527, 614, 345, 112, 267, 509, 613, 524, 235, 319,
      306, 112, 123, 195, 123, 169, 628, 590, 649, 629, 467, 199};
  const uint32_t srcc[] = {
      634, 222, 583, 579, 644, 389, 114, 111, 529, 64,  88,  291, 212,
      210, 402, 383, 390, 236, 405, 571, 258, 365, 534, 91,  155, 201,
      301, 56,  556, 35,  477, 91,  370, 149, 161, 636, 602, 182, 622,
      595, 564, 281, 108, 623, 258, 439, 483, 520, 210, 458, 258, 530,
      50,  394, 555, 552, 4,   133, 71,  284, 161, 530, 241, 51};
  const uint32_t answ[] = {
      1200636, 787445,  816371,  1080584, 682393, 722887,  756175,  974026,
      524406,  254298,  327427,  538037,  279163, 247009,  304548,  511178,
      1380805, 1141829, 1142451, 1646664, 937659, 1012825, 1203865, 1297732,
      552619,  424905,  340726,  727523,  307414, 275288,  423909,  579428,
      1103730, 606333,  829187,  1101617, 680248, 471886,  644097,  816989,
      751050,  757449,  568352,  1054227, 522308, 613048,  735404,  839932,
      913897,  858887,  815627,  1302515, 680482, 624912,  835839,  1000660,
      1139398, 867495,  876243,  1153336, 735755, 875657,  895106,  932997};
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I16();
  muint32_t out = mwmau_h_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MWMAU_H_MM U16");
}

static void test_mwmau_mm_u32() {
  const uint32_t srca[] = {2764122, 1309319, 1812133, 3230723, 2600417, 958145,
                           2378788, 3849494, 1597472, 1800079, 1712762, 2994173,
                           3340083, 3169616, 2940502, 3276396};
  const uint32_t srcb[] = {4013434, 368355,  2725374, 4022529, 2959577, 468963,
                           1840815, 3719006, 3375165, 1910329, 3249879, 456564,
                           3123229, 1920612, 2146579, 398876};
  const uint64_t srcc[] = {358354,  2944962, 186453,  1162571, 2795321, 3093719,
                           3864105, 2534928, 2005847, 573859,  3221782, 2264342,
                           4021749, 1191813, 2721822, 3034236};
  const uint64_t answ[] = {
      31175187612877, 11298938854702, 22767695601590, 18104139842383,
      33323961998110, 13344866322969, 24844896580916, 16645142066567,
      26871165151625, 10455191333070, 19660822440660, 15096673531820,
      42943543744717, 14626781812996, 31526973313446, 27872807771863};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  SET_MBA0_I64();
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  SET_MBA0_I32();
  muint64_t out = mwmau_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MWMAU_MM U32");
}

static void test_mwmau_w_mm() {
  const uint32_t srca[] = {2764122, 1309319, 1812133, 3230723, 2600417, 958145,
                           2378788, 3849494, 1597472, 1800079, 1712762, 2994173,
                           3340083, 3169616, 2940502, 3276396};
  const uint32_t srcb[] = {4013434, 368355,  2725374, 4022529, 2959577, 468963,
                           1840815, 3719006, 3375165, 1910329, 3249879, 456564,
                           3123229, 1920612, 2146579, 398876};
  const uint64_t srcc[] = {358354,  2944962, 186453,  1162571, 2795321, 3093719,
                           3864105, 2534928, 2005847, 573859,  3221782, 2264342,
                           4021749, 1191813, 2721822, 3034236};
  const uint64_t answ[] = {
      31175187612877, 11298938854702, 22767695601590, 18104139842383,
      33323961998110, 13344866322969, 24844896580916, 16645142066567,
      26871165151625, 10455191333070, 19660822440660, 15096673531820,
      42943543744717, 14626781812996, 31526973313446, 27872807771863};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  SET_MBA0_I64();
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  SET_MBA0_I32();
  muint64_t out = mwmau_w_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MWMAU_MM U32");
}

static void test_mqmau_mm_u8() {
  const uint8_t srca[] = {143, 19,  1,  143, 210, 252, 70,  79,
                          35,  226, 86, 175, 10,  137, 251, 63};
  const uint8_t srcb[] = {26,  24,  31,  240, 6,   99, 34, 126,
                          224, 141, 104, 183, 157, 42, 24, 242};
  const uint32_t srcc[] = {227, 29,  189, 222, 65,  74,  193, 88,
                           162, 130, 72,  15,  167, 227, 69,  241};
  const uint32_t answ[] = {26734, 11489,  8804,  71725, 35120, 43250,
                           24447, 114168, 49167, 42820, 21985, 94979,
                           67364, 52067,  32653, 81082};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint8_t ts1 = mla_m(srca, K * sizeof(uint8_t));
  muint8_t ts2 = mlb_m(srcb, N * sizeof(uint8_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I8();
  muint32_t out = mqmau_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MQMAU_MM U8");
}

static void test_mqmau_b_mm() {
  const uint8_t srca[] = {143, 19,  1,  143, 210, 252, 70,  79,
                          35,  226, 86, 175, 10,  137, 251, 63};
  const uint8_t srcb[] = {26,  24,  31,  240, 6,   99, 34, 126,
                          224, 141, 104, 183, 157, 42, 24, 242};
  const uint32_t srcc[] = {227, 29,  189, 222, 65,  74,  193, 88,
                           162, 130, 72,  15,  167, 227, 69,  241};
  const uint32_t answ[] = {26734, 11489,  8804,  71725, 35120, 43250,
                           24447, 114168, 49167, 42820, 21985, 94979,
                           67364, 52067,  32653, 81082};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  SET_MBA0_I8();
  muint8_t ts1 = mla_m(srca, K * sizeof(uint8_t));
  muint8_t ts2 = mlb_m(srcb, N * sizeof(uint8_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I8();
  muint32_t out = mqmau_b_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MQMAU_MM U8");
}

static void test_mma_mm_i16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int16_t srca[M * K] = {
      -125, 52,   -37,  21,  104, 99,   77,   42,   -33, 35,   11,  6,    45,
      -123, -39,  24,   66,  -39, 22,   -30,  98,   -9,  -127, -21, -68,  -82,
      7,    -56,  -117, -16, -5,  -108, -122, -57,  1,   55,   -89, -105, 37,
      110,  -109, -86,  44,  79,  -64,  -108, 111,  87,  -57,  -43, 103,  -29,
      -65,  61,   23,   -72, 91,  65,   79,   -128, 39,  -112, 79,  41};
  const int16_t srcb[K * N] = {
      -101, 99,  14,   -9,   -127, -113, 69,   123,  50,   4,   11,   72,   85,
      102,  -25, 111,  -95,  -101, 29,   -122, 100,  -53,  115, -119, -126, -90,
      18,   -69, -24,  95,   93,   41,   20,   -54,  -62,  97,  -56,  12,   -2,
      110,  35,  79,   -127, 88,   120,  -72,  -121, -128, -21, -107, -124, 112,
      82,   44,  -118, 100,  -127, -103, -34,  -27,  87,   60,  -14,  104};
  const int16_t srcc[M * N] = {
      41,  -64, -89, -54, 79,   110,  -29,  12,   -128, 104, 99,  -99, -47,
      -6,  -18, 98,  -74, 108,  -104, -120, -102, 90,   61,  62,  -9,  124,
      -11, -11, 7,   -77, -15,  112,  53,   31,   -113, 28,  -86, -55, 79,
      -47, 116, 5,   57,  96,   34,   -111, 95,   -91,  19,  33,  -62, 59,
      119, 47,  -98, -39, -121, 117,  -4,   77,   -95,  20,  88,  108};
  const int16_t answ[M * N] = {
      14729,  -20744, -31959, 34170,  32194,  23523,  -34117, 6509,
      -2480,  -15120, 17300,  -10513, -10315, 16400,  17712,  18151,
      -21,    16713,  12018,  -9079,  -27688, -20386, 21503,  -2949,
      20071,  14110,  10908,  -12694, -1457,  -13400, -2788,  -43037,
      -17702, -36104, 9096,   -23594, 14331,  27809,  5293,   -454,
      -25749, -48598, 1245,   -21563, 16366,  25719,  6011,   1891,
      6991,   -291,   -2989,  -9506,  21281,  -14592, -2765,  -45415,
      -7445,  -10703, 2588,   4800,   -734,   -5512,  5501,   34657};
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  mint16_t td = mlc_m(srcc, N * sizeof(int16_t));
  mint16_t out = mma_mm(td, ts1, ts2);
  msc_m(out, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(answ, i16_buffer, M * N, "MMA_MM I16");
}

static void test_mma_h_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int16_t srca[M * K] = {
      -125, 52,   -37,  21,  104, 99,   77,   42,   -33, 35,   11,  6,    45,
      -123, -39,  24,   66,  -39, 22,   -30,  98,   -9,  -127, -21, -68,  -82,
      7,    -56,  -117, -16, -5,  -108, -122, -57,  1,   55,   -89, -105, 37,
      110,  -109, -86,  44,  79,  -64,  -108, 111,  87,  -57,  -43, 103,  -29,
      -65,  61,   23,   -72, 91,  65,   79,   -128, 39,  -112, 79,  41};
  const int16_t srcb[K * N] = {
      -101, 99,  14,   -9,   -127, -113, 69,   123,  50,   4,   11,   72,   85,
      102,  -25, 111,  -95,  -101, 29,   -122, 100,  -53,  115, -119, -126, -90,
      18,   -69, -24,  95,   93,   41,   20,   -54,  -62,  97,  -56,  12,   -2,
      110,  35,  79,   -127, 88,   120,  -72,  -121, -128, -21, -107, -124, 112,
      82,   44,  -118, 100,  -127, -103, -34,  -27,  87,   60,  -14,  104};
  const int16_t srcc[M * N] = {
      41,  -64, -89, -54, 79,   110,  -29,  12,   -128, 104, 99,  -99, -47,
      -6,  -18, 98,  -74, 108,  -104, -120, -102, 90,   61,  62,  -9,  124,
      -11, -11, 7,   -77, -15,  112,  53,   31,   -113, 28,  -86, -55, 79,
      -47, 116, 5,   57,  96,   34,   -111, 95,   -91,  19,  33,  -62, 59,
      119, 47,  -98, -39, -121, 117,  -4,   77,   -95,  20,  88,  108};
  const int16_t answ[M * N] = {
      14729,  -20744, -31959, 34170,  32194,  23523,  -34117, 6509,
      -2480,  -15120, 17300,  -10513, -10315, 16400,  17712,  18151,
      -21,    16713,  12018,  -9079,  -27688, -20386, 21503,  -2949,
      20071,  14110,  10908,  -12694, -1457,  -13400, -2788,  -43037,
      -17702, -36104, 9096,   -23594, 14331,  27809,  5293,   -454,
      -25749, -48598, 1245,   -21563, 16366,  25719,  6011,   1891,
      6991,   -291,   -2989,  -9506,  21281,  -14592, -2765,  -45415,
      -7445,  -10703, 2588,   4800,   -734,   -5512,  5501,   34657};
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  mint16_t td = mlc_m(srcc, N * sizeof(int16_t));
  mint16_t out = mma_h_mm(td, ts1, ts2);
  msc_m(out, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(answ, i16_buffer, M * N, "MMA_H_MM I16");
}

static void test_mma_mm_i32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {-305,  395,   645,   -198,  -285, -545,
                               1801,  -1778, -1468, -3240, 1036, 2531,
                               -3189, 234,   -1211, -53};
  const int32_t srcb[K * N] = {587,   -2209, 747,   -1307, 960, -1254,
                               1786,  1884,  2782,  -1499, 130, 2542,
                               -3220, 642,   -1282, -2025};
  const int32_t srcc[M * N] = {2011,  1920,  -1644, 492,  1857,  3191,
                               -2955, -2098, -22,   1078, -2114, -1070,
                               -3148, -2687, 2807,  708};
  const int32_t answ[M * N] = {2634126,  -913636,  813677,   3183847,
                               10046904, -2524989, 1324306,  7522209,
                               -9239806, 7378788,  -9995412, -6678317,
                               -4848793, 8529641,  -2050936, 1638550};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  mint32_t out = mma_mm(td, ts1, ts2);
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MMA_MM I32");
}

static void test_mma_w_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {-305,  395,   645,   -198,  -285, -545,
                               1801,  -1778, -1468, -3240, 1036, 2531,
                               -3189, 234,   -1211, -53};
  const int32_t srcb[K * N] = {587,   -2209, 747,   -1307, 960, -1254,
                               1786,  1884,  2782,  -1499, 130, 2542,
                               -3220, 642,   -1282, -2025};
  const int32_t srcc[M * N] = {2011,  1920,  -1644, 492,  1857,  3191,
                               -2955, -2098, -22,   1078, -2114, -1070,
                               -3148, -2687, 2807,  708};
  const int32_t answ[M * N] = {2634126,  -913636,  813677,   3183847,
                               10046904, -2524989, 1324306,  7522209,
                               -9239806, 7378788,  -9995412, -6678317,
                               -4848793, 8529641,  -2050936, 1638550};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  mint32_t out = mma_w_mm(td, ts1, ts2);
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MMA_W_MM I32");
}

static void test_mma_mm_i64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int64_t srca[M * K] = {35551, -252170, -259333, -172483};
  const int64_t srcb[K * N] = {-287985, -269782, 177886, 207879};
  const int64_t srcc[M * N] = {-25052, -298411, -173686, -3544};
  const int64_t answ[M * N] = {-55095692407, -62012165723, 44001529381,
                               34107778305};
  mint64_t ts1 = mla_m(srca, K * sizeof(int64_t));
  mint64_t ts2 = mlb_m(srcb, N * sizeof(int64_t));
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  mint64_t out = mma_mm(td, ts1, ts2);
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MMA_MM I64");
}

static void test_mma_dw_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int64_t srca[M * K] = {35551, -252170, -259333, -172483};
  const int64_t srcb[K * N] = {-287985, -269782, 177886, 207879};
  const int64_t srcc[M * N] = {-25052, -298411, -173686, -3544};
  const int64_t answ[M * N] = {-55095692407, -62012165723, 44001529381,
                               34107778305};
  mint64_t ts1 = mla_m(srca, K * sizeof(int64_t));
  mint64_t ts2 = mlb_m(srcb, N * sizeof(int64_t));
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  mint64_t out = mma_dw_mm(td, ts1, ts2);
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MMA_DW_MM I64");
}

static void test_msmau_mm_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint16_t srca[M * K] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t srcb[K * N] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t srcc[M * N] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t answ[M * N] = {
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535};
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  muint16_t td = mlc_m(srcc, N * sizeof(uint16_t));
  muint16_t out1 = msmau_mm(td, ts1, ts2);
  muint16_t out2 = msmau_h_mm(td, ts1, ts2);
  msc_m(out1, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(answ, u16_buffer, M * N, "MSMAU_MM U16");
}

static void test_msmau_h_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint16_t srca[M * K] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t srcb[K * N] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t srcc[M * N] = {
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
  const uint16_t answ[M * N] = {
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535,
      65535, 65535, 65535, 65535};
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  muint16_t td = mlc_m(srcc, N * sizeof(uint16_t));
  muint16_t out = msmau_h_mm(td, ts1, ts2);
  msc_m(out, u16_buffer, N * sizeof(uint16_t));
  EXCEPT_U16_ARRAY_EQ(answ, u16_buffer, M * N, "MSMAU_H_MM U16");
}

static void test_msmau_mm_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcb[K * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcc[M * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t answ[M * N] = {4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  muint32_t out = msmau_mm(td, ts1, ts2);
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSMAU_MM U32");
}

static void test_msmau_w_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcb[K * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcc[M * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t answ[M * N] = {4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  muint32_t out = msmau_w_mm(td, ts1, ts2);
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSMAU_W_MM U32");
}

static void test_msmau_mm_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint64_t srca[M * K] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcb[K * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcc[M * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t answ[M * N] = {18446744073709551615, 18446744073709551615,
                                18446744073709551615, 18446744073709551615};
  muint64_t ts1 = mla_m(srca, K * sizeof(uint64_t));
  muint64_t ts2 = mlb_m(srcb, N * sizeof(uint64_t));
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  muint64_t out = msmau_mm(td, ts1, ts2);
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MSMAU_MM U64");
}

static void test_msmau_dw_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint64_t srca[M * K] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcb[K * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcc[M * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t answ[M * N] = {18446744073709551615, 18446744073709551615,
                                18446744073709551615, 18446744073709551615};
  muint64_t ts1 = mla_m(srca, K * sizeof(uint64_t));
  muint64_t ts2 = mlb_m(srcb, N * sizeof(uint64_t));
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  muint64_t out = msmau_dw_mm(td, ts1, ts2);
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MSMAU_DW_MM U64");
}

static void test_mswmau_mm_u16() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const uint16_t srca[M * K] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint16_t srcb[K * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcc[M * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t answ[M * N] = {4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I16();
  muint32_t out = mswmau_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSWMAU_MM U16");
}

static void test_mswmau_h_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint16_t srca[M * K] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint16_t srcb[K * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t srcc[M * N] = {65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535, 65535, 65535,
                                65535, 65535, 65535, 65535};
  const uint32_t answ[M * N] = {4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295,
                                4294967295, 4294967295, 4294967295, 4294967295};
  muint16_t ts1 = mla_m(srca, K * sizeof(uint16_t));
  muint16_t ts2 = mlb_m(srcb, N * sizeof(uint16_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I16();
  muint32_t out = mswmau_h_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSWMAU_H_MM U16");
}

static void test_mswmau_mm_u32() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint32_t srcb[K * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcc[M * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t answ[M * N] = {18446744073709551615, 18446744073709551615,
                                18446744073709551615, 18446744073709551615};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  SET_MBA0_I64();
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  SET_MBA0_I32();
  muint64_t out = mswmau_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MSWMAU_MM U32");
}

static void test_mswmau_w_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const uint32_t srca[M * K] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint32_t srcb[K * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t srcc[M * N] = {4294967295, 4294967295, 4294967295, 4294967295};
  const uint64_t answ[M * N] = {18446744073709551615, 18446744073709551615,
                                18446744073709551615, 18446744073709551615};
  muint32_t ts1 = mla_m(srca, K * sizeof(uint32_t));
  muint32_t ts2 = mlb_m(srcb, N * sizeof(uint32_t));
  SET_MBA0_I64();
  muint64_t td = mlc_m(srcc, N * sizeof(uint64_t));
  SET_MBA0_I32();
  muint64_t out = mswmau_w_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, u64_buffer, N * sizeof(uint64_t));
  EXCEPT_U64_ARRAY_EQ(answ, u64_buffer, M * N, "MSWMAU_DW_MM U32");
}

static void test_msqmau_mm_u8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const uint8_t srca[M * K] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint8_t srcb[K * N] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint32_t srcc[M * N] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint32_t answ[M * N] = {
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint8_t ts1 = mla_m(srca, K * sizeof(uint8_t));
  muint8_t ts2 = mlb_m(srcb, N * sizeof(uint8_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I8();
  muint32_t md = msqmau_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSQMAU_B_MM U8");
}

static void test_msqmau_b_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const uint8_t srca[M * K] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint8_t srcb[K * N] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint32_t srcc[M * N] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
  const uint32_t answ[M * N] = {
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455,
      520455, 520455, 520455, 520455, 520455, 520455, 520455, 520455};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  muint8_t ts1 = mla_m(srca, K * sizeof(uint8_t));
  muint8_t ts2 = mlb_m(srcb, N * sizeof(uint8_t));
  SET_MBA0_I32();
  muint32_t td = mlc_m(srcc, N * sizeof(uint32_t));
  SET_MBA0_I8();
  muint32_t md = msqmau_b_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, u32_buffer, N * sizeof(uint32_t));
  EXCEPT_U32_ARRAY_EQ(answ, u32_buffer, M * N, "MSQMAU_MM U8");
}

static void test_mwma_mm_i16() {
  const int16_t srca[] = {122, -96, 125, 1,   -77, -69, -92, -110,
                          -84, 22,  35,  -29, 71,  -54, -15, -110};
  const int16_t srcb[] = {-52, 90,  50,  35, 118, -104, -57,  48,
                          -5,  -29, 105, 88, 61,  -32,  -120, -117};
  const int32_t srcc[] = {75, -111, -104, 5,  -116, 39, -51, 89,
                          16, -46,  44,   21, 114,  67, -58, -59};
  const int32_t answ[] = {-18161, 17196, 24473, 10550, -10504, 6473,
                          3572,   -1144, 5036,  -9981, 1745,   4610,
                          -16585, 16028, 18195, 11384};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I16();
  mint32_t out = mwma_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MWMA_MM I16");
}

static void test_mwma_h_mm() {
  const int16_t srca[] = {122, -96, 125, 1,   -77, -69, -92, -110,
                          -84, 22,  35,  -29, 71,  -54, -15, -110};
  const int16_t srcb[] = {-52, 90,  50,  35, 118, -104, -57,  48,
                          -5,  -29, 105, 88, 61,  -32,  -120, -117};
  const int32_t srcc[] = {75, -111, -104, 5,  -116, 39, -51, 89,
                          16, -46,  44,   21, 114,  67, -58, -59};
  const int32_t answ[] = {-18161, 17196, 24473, 10550, -10504, 6473,
                          3572,   -1144, 5036,  -9981, 1745,   4610,
                          -16585, 16028, 18195, 11384};
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I16();
  mint32_t out = mwma_h_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MWMA_MM I16");
}

static void test_mwma_mm_i32() {
  const int32_t srca[] = {105245845, -176467869, 1297292938, -1763276622};
  const int32_t srcb[] = {1605484669, -561961007, -510067211, 257670523};
  const int64_t srcc[] = {-1967009290, -1707721152, -2083406524, -1291471706};
  const int64_t answ[] = {258981062428384374, -104614630844412554,
                          2982173509882602240, -1183372456488353578};
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  SET_MBA0_I64();
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  SET_MBA0_I32();
  mint64_t out = mwma_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MWMA_H_MM I32");
}

static void test_mwma_w_mm() {
  const int32_t srca[] = {105245845, -176467869, 1297292938, -1763276622};
  const int32_t srcb[] = {1605484669, -561961007, -510067211, 257670523};
  const int64_t srcc[] = {-1967009290, -1707721152, -2083406524, -1291471706};
  const int64_t answ[] = {258981062428384374, -104614630844412554,
                          2982173509882602240, -1183372456488353578};
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  SET_MBA0_I64();
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  SET_MBA0_I32();
  mint64_t out = mwma_w_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MWMA_W_MM I32");
}

static void test_mqma_mm_i8() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const int8_t srca[M * K] = {77,  -29, 25,  86, -73, 125, -97, -121,
                              118, 93,  -60, 65, 101, -31, 82,  43};
  const int8_t srcb[K * N] = {16, 97,  -82, 73, -57, -125, -124, 27,
                              80, 107, -24, 69, -22, -55,  39,   7};
  const int32_t srcc[M * N] = {-22, -121, 91,   -85, -116, -21, -56, 126,
                               72,  -40,  -102, -56, 43,   15,  -36, -117};
  const int32_t answ[M * N] = {2971,   8918,  127,   7080,   -13507, -26451,
                               -11961, -9368, -9571, -10214, -17335, 7384,
                               9040,   20096, -4765, 12378};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint8_t ts1 = mla_m(srca, K * sizeof(int8_t));
  mint8_t ts2 = mlb_m(srcb, N * sizeof(int8_t));
  SET_MBA0_I8();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I8();
  mint32_t md = mqma_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MQMA_MM I8");
}

static void test_mqma_b_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const int8_t srca[M * K] = {77,  -29, 25,  86, -73, 125, -97, -121,
                              118, 93,  -60, 65, 101, -31, 82,  43};
  const int8_t srcb[K * N] = {16, 97,  -82, 73, -57, -125, -124, 27,
                              80, 107, -24, 69, -22, -55,  39,   7};
  const int32_t srcc[M * N] = {-22, -121, 91,   -85, -116, -21, -56, 126,
                               72,  -40,  -102, -56, 43,   15,  -36, -117};
  const int32_t answ[M * N] = {2971,   8918,  127,   7080,   -13507, -26451,
                               -11961, -9368, -9571, -10214, -17335, 7384,
                               9040,   20096, -4765, 12378};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint8_t ts1 = mla_m(srca, K * sizeof(int8_t));
  mint8_t ts2 = mlb_m(srcb, N * sizeof(int8_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I8();
  mint32_t md = mqma_b_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MQMA_B_MM I8");
}

static void test_mfma_mm_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const fp16_t srca[M * K] = {
      -0.4791228,  -5.50058298, -2.07270458, 5.3226858,   -8.84389546,
      4.59407695,  6.5989989,   -3.14833659, 5.81934332,  8.27158019,
      -7.44617388, 3.45992688,  4.65601025,  -1.30384156, -6.16177024,
      -2.78090041, -5.02383668, 2.47596348,  -2.01387443, 6.29004664,
      9.39431268,  0.01367022,  -1.1863497,  -2.91107541, 7.97764859,
      5.20841543,  -6.92063255, -1.59031739, -1.63604836, 5.33806209,
      -1.77626059, -6.37831689, -8.63225568, -6.51750765, 4.07559851,
      8.82386443,  -0.96819769, -2.65136036, 7.01084136,  -8.91837203,
      3.34552436,  -7.10714317, -4.92892601, -1.69535171, -0.44200629,
      4.95106719,  3.1458187,   1.2355903,   5.10646997,  3.48436152,
      0.71208435,  8.18292857,  -8.59622791, -1.60706513, -5.45765094,
      -1.78489762, 7.15678721,  -3.33436914, 6.6050622,   -0.54018179,
      6.62988256,  1.88233015,  -2.58375522, -5.98121322};
  const fp16_t srcb[K * N] = {
      -7.09247889, 0.09991281,  9.71906561,  -3.01612009, 9.19340953,
      9.54288417,  -9.91204777, 6.88476914,  -8.07182731, -4.45583986,
      0.07357176,  7.51683337,  3.30242458,  -4.26903074, -1.62946192,
      2.74305551,  5.8407685,   8.64020195,  -1.70596265, 1.11948438,
      -0.60827231, 2.710995,    -5.54557408, 6.26212106,  9.22451442,
      0.08672065,  -0.7108666,  8.5726977,   8.94694825,  -0.97666864,
      0.48978224,  -9.80966056, -3.21427914, -5.39927878, -3.55575748,
      -4.52220854, 9.98265771,  5.73339337,  -4.21182337, -0.78817531,
      6.93726156,  -0.72896213, 2.75900982,  5.41802047,  -0.91040382,
      -3.06361928, -3.51136412, -2.40916743, 3.64698973,  2.47729373,
      -9.05774253, -8.48844017, -4.126127,   9.52703889,  1.90001698,
      -9.51317452, 9.4533237,   -4.48583695, 1.73332576,  1.42924847,
      0.62548777,  7.19749661,  1.22851512,  -9.70041731};
  const fp16_t srcc[M * N] = {
      4.4160154,   3.5332977,   -4.19579848, 3.07497555,  1.20030683,
      3.41173536,  2.01856532,  -2.06981731, 2.41305312,  -0.77042081,
      -8.49611319, -6.30986548, -9.72178782, -4.91703216, 2.55078244,
      6.00616738,  -7.68156249, 9.33716417,  -6.00531342, -1.50450808,
      -8.36759781, -1.03462902, 3.64356792,  6.91081309,  -1.49179717,
      0.04204007,  9.76100764,  4.71724232,  -0.26571138, 2.65151656,
      -8.72104956, -3.52638119, 6.97061847,  8.35415848,  0.14319908,
      6.08000407,  9.08252654,  -3.40035253, 1.62632946,  -8.3082222,
      8.78537245,  6.96326183,  -3.82118672, -4.85217052, 4.37744263,
      4.15808431,  7.11142754,  -7.14811029, 4.68388129,  5.54947351,
      4.32283561,  6.07252715,  -7.86587985, -9.6808525,  -2.00948736,
      -9.59864288, 3.049945,    4.92879451,  6.27233823,  3.5829288,
      -3.26062172, 1.89711464,  -5.06760085, 3.4590756};
  const fp16_t answ[M * N] = {
      143.80824244, 85.42047692,  -30.61214998,  10.85229756,   -94.1527624,
      -13.06716935, 59.61981715,  -121.98474951, -189.97398697, -128.06072475,
      89.75293632,  79.84894886,  177.93038264,  -56.29081881,  -55.77700838,
      73.25616628,  -7.72265771,  -59.66488837,  -83.35231337,  47.42819173,
      107.96655256, -49.58482491, 18.20886036,   -63.11248645,  -179.69029879,
      -53.14832541, 126.19470112, 40.70740029,   62.40523473,   -49.22649626,
      -81.74674374, 105.14691544, 151.98248402,  137.04644802,  -180.29246723,
      -18.91261389, -57.09065993, -50.3482864,   95.28206144,   -119.68716505,
      56.91821513,  -2.74028875,  26.66440639,   -84.53077827,  -21.63374975,
      75.87926478,  4.00632367,   -71.33697747,  -0.31131816,   39.46757565,
      119.64992428, 161.75181043, 60.41833493,   -91.09096793,  -28.95737817,
      39.18428904,  -61.41659078, 60.78478557,   59.35502654,   -46.70304584,
      114.06239061, 67.44158298,  -154.25685373, 163.0858631};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat16_t ts1 = mla_m(srca, K * sizeof(fp16_t));
  mfloat16_t ts2 = mlb_m(srcb, N * sizeof(fp16_t));
  mfloat16_t td = mlc_m(srcc, N * sizeof(fp16_t));
  mfloat16_t md = mfma_mm(td, ts1, ts2);
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(answ, f16_buffer, M * N, "MFMA_MM F16");
}

static void test_mfma_hf_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const fp16_t srca[M * K] = {-8.49   ,  7.375  , -9.78   ,  2.316  , -3.537  ,  3.861  ,
       -1.833  ,  4.164  ,  5.215  , -1.823  ,  2.617  , -7.957  ,
        8.05   , -2.498  , -3.033  , -0.773  ,  6.71   ,  6.527  ,
        2.371  ,  1.755  , -3.758  ,  0.719  , -7.754  , -6.79   ,
       -5.016  ,  0.9453 , -9.27   , -5.223  ,  5.832  , -3.346  ,
       -3.451  ,  9.3    , -5.17   , -0.3423 , -5.996  , -1.961  ,
       -1.094  ,  1.426  ,  4.47   ,  3.406  , -0.9204 ,  2.547  ,
        8.86   , -8.86   , -1.318  , -5.164  , -1.76   ,  5.08   ,
        4.273  , -1.892  , -1.775  ,  1.707  , -7.914  , -7.035  ,
        5.848  ,  0.5786 ,  7.117  , -8.13   ,  6.59   , -0.1672 ,
       -3.45   ,  2.309  ,  8.66   , -0.01075};
  const fp16_t srcb[K * N] = {-0.03464,  9.46   ,  1.27   ,  1.537  , -0.8257 ,  0.7495 ,
       -2.086  , -3.127  ,  2.15   ,  4.953  , -3.246  ,  3.23   ,
        7.586  , -5.02   , -6.605  , -5.094  , -8.83   ,  8.81   ,
       -9.79   ,  2.135  ,  4.242  , -6.402  ,  7.13   , -5.04   ,
        2.855  , -8.016  ,  6.04   ,  5.18   , -8.92   , -9.81   ,
        6.215  ,  2.668  ,  1.997  ,  6.09   , -9.266  , -9.055  ,
       -1.384  ,  6.656  , -7.055  ,  3.041  , -0.7163 ,  1.268  ,
       -1.096  , -7.344  ,  1.6455 , -1.47   , -8.64   ,  3.486  ,
        6.82   ,  1.106  ,  5.86   ,  7.008  , -0.152  ,  5.945  ,
        3.285  ,  2.965  , -7.34   , -4.42   , -5.35   ,  5.23   ,
       -2.576  , -1.436  ,  7.87   ,  4.4    };
  const fp16_t srcc[M * N] = {-6.33   ,  4.277  , -9.91   ,  4.375  , -1.512  ,  5.6    ,
        8.56   , -7.07   ,  2.46   , -9.09   , -5.598  , -8.875  ,
       -6.36   , -7.117  , -7.05   , -3.861  ,  6.31   , -7.51   ,
       -4.918  ,  8.92   , -6.367  ,  1.386  ,  0.068  ,  5.797  ,
        0.957  , -9.     ,  8.3    , -4.973  ,  7.63   , -5.71   ,
        7.1    ,  7.82   ,  1.676  , -8.27   ,  0.04953,  7.69   ,
        2.121  ,  2.947  ,  8.01   ,  4.562  ,  8.734  ,  9.51   ,
       -7.297  ,  6.395  , -1.759  , -9.2    , -2.316  , -2.695  ,
       -8.41   ,  2.129  ,  6.434  ,  9.99   ,  6.67   ,  1.204  ,
        7.65   ,  0.515  ,  1.645  ,  4.21   ,  0.529  , -2.316  ,
        9.02   , -2.12   ,  6.562  ,  8.3};
  const fp16_t answ[M * N] = {4.9875e+01, -1.8138e+02,  6.0656e+01,  1.8875e+01,  8.5938e-02,
       -4.4000e+01, -5.9438e+01,  5.2969e+01, -4.4625e+01,  1.6388e+02,
       -1.5225e+02, -1.2219e+02,  4.4812e+01,  1.0756e+02, -8.7938e+01,
       -4.1938e+01, -6.8789e+00,  9.4625e+01, -5.2695e+00, -6.6250e+00,
        5.7062e+01, -1.2119e+02, -8.7875e+01, -1.1744e+02, -7.6133e+00,
       -1.0531e+02, -6.2250e+01, -6.0281e+01, -1.0812e+01,  1.0631e+02,
       -3.7656e+01,  8.8188e+01,  5.0750e+01, -1.1100e+02,  5.8000e+01,
        2.4234e+01, -9.7344e+00,  7.0688e+01,  3.0117e+00,  7.7312e+01,
       -1.3750e+02,  1.2350e+02, -1.7650e+02,  5.0344e+01,  1.1544e+02,
       -1.1406e+01,  7.9000e+01, -8.5938e+01,  3.2781e+01, -4.9344e+01,
        1.5788e+02,  1.8288e+02, -3.7000e+01,  1.1621e-01,  1.4950e+02,
       -1.8422e+01, -2.4172e+01,  8.2188e+01,  5.0656e+01,  7.0438e+01,
       -2.1812e+01,  2.8609e+01,  1.2412e+02,  1.7000e+01};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat16_t ts1 = mla_m(srca, K * sizeof(fp16_t));
  mfloat16_t ts2 = mlb_m(srcb, N * sizeof(fp16_t));
  mfloat16_t td = mlc_m(srcc, N * sizeof(fp16_t));
  mfloat16_t md = mfma_hf_mm(td, ts1, ts2);
  msc_m(md, f16_buffer, N * sizeof(fp16_t));
  EXCEPT_F16_ARRAY_LAX_EQ(answ, f16_buffer, M * N, "MFMA_HF_MM F16");
}

static void test_mfma_mm_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const fp32_t srca[M * K] = {
      -5.34885166, 6.16785248,  -7.26699666, 0.14651779,
      8.19912576,  -8.63250377, 3.91576816,  4.41981897,
      -4.48925631, 3.43411467,  -2.32028295, 5.94571373,
      -0.47454845, 2.03920741,  4.70682747,  3.91456475};
  const fp32_t srcb[K * N] = {
      -3.95257826, -2.50797606, 9.48594782,  -8.56341197,
      -5.82663771, 8.8571014,   -0.4917598,  7.27449921,
      -9.81293363, 6.61441964,  -0.32218291, 8.2296347,
      -0.90938265, 8.41664582,  -9.60522396, -2.67690141};
  const fp32_t srcc[M * N] = {
      2.45799581,  -9.71701749, 4.88672314,  -1.12097252,
      -2.06165708, 6.77666127,  -6.45624556, -6.50973189,
      2.06477969,  2.60530323,  -2.81386979, 9.32479738,
      5.5899842,   5.49460706,  9.91244396,  -0.01402747};
  const fp32_t answ[M * N] = {
      58.83922389,  11.49329227,  -47.95134065,  29.35454425,
      -26.61535101, -27.14492648, 31.85040729,   -119.12544345,
      17.16142818,  78.976194,    -103.44983688, 37.73844246,
      -54.16367156, 88.82666709,  -34.70862854,  47.14050587};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat32_t ts1 = mla_m(srca, K * sizeof(fp32_t));
  mfloat32_t ts2 = mlb_m(srcb, N * sizeof(fp32_t));
  mfloat32_t td = mlc_m(srcc, N * sizeof(fp32_t));
  mfloat32_t md = mfma_mm(td, ts1, ts2);
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(answ, f32_buffer, M * N, "MFMA_MM F32");
}

static void test_mfma_f_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const fp32_t srca[M * K] = {
      -5.34885166, 6.16785248,  -7.26699666, 0.14651779,
      8.19912576,  -8.63250377, 3.91576816,  4.41981897,
      -4.48925631, 3.43411467,  -2.32028295, 5.94571373,
      -0.47454845, 2.03920741,  4.70682747,  3.91456475};
  const fp32_t srcb[K * N] = {
      -3.95257826, -2.50797606, 9.48594782,  -8.56341197,
      -5.82663771, 8.8571014,   -0.4917598,  7.27449921,
      -9.81293363, 6.61441964,  -0.32218291, 8.2296347,
      -0.90938265, 8.41664582,  -9.60522396, -2.67690141};
  const fp32_t srcc[M * N] = {
      2.45799581,  -9.71701749, 4.88672314,  -1.12097252,
      -2.06165708, 6.77666127,  -6.45624556, -6.50973189,
      2.06477969,  2.60530323,  -2.81386979, 9.32479738,
      5.5899842,   5.49460706,  9.91244396,  -0.01402747};
  const fp32_t answ[M * N] = {
      58.83922389,  11.49329227,  -47.95134065,  29.35454425,
      -26.61535101, -27.14492648, 31.85040729,   -119.12544345,
      17.16142818,  78.976194,    -103.44983688, 37.73844246,
      -54.16367156, 88.82666709,  -34.70862854,  47.14050587};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat32_t ts1 = mla_m(srca, K * sizeof(fp32_t));
  mfloat32_t ts2 = mlb_m(srcb, N * sizeof(fp32_t));
  mfloat32_t td = mlc_m(srcc, N * sizeof(fp32_t));
  mfloat32_t md = mfma_f_mm(td, ts1, ts2);
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(answ, f32_buffer, M * N, "MFMA_F_MM F32");
}

static void test_mfma_mm_f64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  const fp64_t srca[M * K] = {2.0406242 ,  3.47746435, -2.19977962,  5.88766014};
  const fp64_t srcb[K * N] = {-4.25256405,  8.1988843 , -2.47396121, -3.65000794};
  const fp64_t srcc[M * N] = {0.28387359, -9.78701986,  1.10523382,  9.09192871};
  const fp64_t answ[M * N] = {-16.99712345,  -5.74895065,  -4.10590526, -30.43381614};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat64_t ts1 = mla_m(srca, K * sizeof(fp64_t));
  mfloat64_t ts2 = mlb_m(srcb, N * sizeof(fp64_t));
  mfloat64_t td = mlc_m(srcc, N * sizeof(fp64_t));
  mfloat64_t md = mfma_mm(td, ts1, ts2);
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(answ, f64_buffer, M * N, "MFMA_MM F64");
}

static void test_mfma_d_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  const fp64_t srca[M * K] = {29.85753658, 4.49153633, -5.29235246,
                              -37.02611251};
  const fp64_t srcb[K * N] = {-9.41284212, -37.21474673, 10.62728676,
                              14.81828622};
  const fp64_t srcc[M * N] = {14.58113795, -16.52390582, -28.99705716,
                              18.38146756};
  const fp64_t answ[M * N] = {-218.73029554, -1061.10769684, -372.66809429,
                              -333.328509};
  SET_MBA0_F64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat64_t ts1 = mla_m(srca, K * sizeof(fp64_t));
  mfloat64_t ts2 = mlb_m(srcb, N * sizeof(fp64_t));
  mfloat64_t td = mlc_m(srcc, N * sizeof(fp64_t));
  mfloat64_t md = mfma_d_mm(td, ts1, ts2);
  msc_m(md, f64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(answ, f64_buffer, M * N, "MFMA_DW_MM F64");
}

static void test_mfwma_mm_f16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const fp16_t srca[M * K] = {
      -1.672e+00, 6.590e+00,  5.496e+00,  4.566e+00,  -4.863e+00, -1.420e+00,
      9.492e+00,  -8.727e+00, -1.831e+00, 2.918e+00,  8.641e+00,  -5.566e-01,
      -3.691e+00, 2.070e+00,  1.010e+00,  -9.516e+00, 7.793e+00,  -8.258e+00,
      9.914e+00,  5.418e+00,  6.641e+00,  3.236e+00,  2.961e+00,  -7.367e+00,
      1.273e-01,  1.928e+00,  6.352e+00,  7.941e+00,  3.756e+00,  8.695e+00,
      5.812e+00,  -2.459e+00, -9.508e+00, -4.020e+00, -7.359e+00, 1.431e-01,
      -3.748e+00, -9.234e+00, 5.016e+00,  6.016e+00,  9.148e+00,  6.438e+00,
      -4.051e+00, -3.941e+00, 8.484e+00,  5.034e-01,  3.117e+00,  -1.848e-01,
      -7.559e+00, 2.131e+00,  8.656e+00,  -7.957e+00, 5.996e+00,  2.703e+00,
      -3.375e+00, 5.160e+00,  2.914e-03,  3.871e+00,  -7.156e+00, 9.977e+00,
      -8.656e+00, -1.669e+00, -4.477e+00, -2.135e+00};
  const fp16_t srcb[K * N] = {
      1.484,  -1.692, 6.008,  -9.016, -5.645,  1.574,  0.1078, 7.566,
      3.291,  -4.414, 4.137,  -1.847, 3.535,   -9.04,  -9.88,  3.281,
      -8.99,  -9.56,  -1.234, 5.86,   4.566,   6.18,   3.926,  -2.883,
      -7.44,  8.99,   -1.302, 0.1448, 0.12085, 5.812,  -8.01,  -5.047,
      2.588,  -0.751, -3.979, 1.309,  -1.48,   -2.738, 7.094,  -7.793,
      -8.234, 6.65,   4.46,   7.12,   0.5,     4.707,  6.613,  -7.402,
      -8.72,  5.547,  -0.073, 8.14,   -4.45,   -6.207, -2.9,   -4.293,
      -2.836, -3.867, -4.4,   -1.222, -0.8057, -5.52,  -8.,    4.457};
  const fp32_t srcc[M * N] = {
      3.555,   3.158,  4.543,  2.715,  2.36,    9.72,    8.516,    4.484,
      -1.8125, -4.773, 2.195,  -5.703, -3.385,  -0.0777, 2.809,    4.14,
      5.785,   7.62,   5.742,  0.236,  -0.3367, -7.57,   0.4524,   -6.617,
      2.64,    1.548,  -8.77,  -2.604, 5.133,   3.393,   -0.08624, -7.688,
      -8.305,  -4.402, -2.271, -9.14,  0.322,   2.578,   -3.799,   9.73,
      -4.332,  4.04,   6.695,  1.852,  -9.72,   4.402,   -8.69,    4.64,
      4.844,   -0.461, -1.356, -9.26,  -8.9,    -6.05,   9.68,     -6.055,
      8.62,    -9.836, 0.0679, 7.652,  9.99,    -2.338,  7.074,    -3.164};
  const fp32_t answ[M * N] = {
      -119.56, 46.,    59.72,  109.94, 32.03,  3.91,    -73.4,  -56.7,
      -76.9,   -43.25, 59.03,  85.75,  66.3,   86.94,   72.9,   -55.56,
      -153.8,  46.25,  19.31,  68.94,  -43.06, 191.4,   197.4,  -151.9,
      -212.6,  100.25, 16.03,  148.2,  16.1,   79.7,    29.17,  -188.2,
      35.,     47.06,  -120.2, 3.719,  -20.03, -118.25, -145.4, 47.94,
      87.4,    -21.6,  67.5,   -76.5,  -83.6,  -126.5,  0.289,  42.5,
      -9.94,   -176.6, -72.56, 97.9,   83.25,  -41.22,  114.44, -70.3,
      47.9,    110.06, 48.66,  -97.06, 25.81,  31.84,   -181.5, 69.3};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat16_t ts1 = mla_m(srca, K * sizeof(fp16_t));
  mfloat16_t ts2 = mlb_m(srcb, N * sizeof(fp16_t));
  SET_MBA0_F32();
  mfloat32_t td = mlc_m(srcc, N * sizeof(fp32_t));
  SET_MBA0_F16F32();
  mfloat32_t md = mfwma_mm(td, ts1, ts2);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(answ, f32_buffer, M * N, "MFWMA_MM F16");
}

static void test_mfwma_hf_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const fp16_t srca[M * K] = {
      -1.672e+00, 6.590e+00,  5.496e+00,  4.566e+00,  -4.863e+00, -1.420e+00,
      9.492e+00,  -8.727e+00, -1.831e+00, 2.918e+00,  8.641e+00,  -5.566e-01,
      -3.691e+00, 2.070e+00,  1.010e+00,  -9.516e+00, 7.793e+00,  -8.258e+00,
      9.914e+00,  5.418e+00,  6.641e+00,  3.236e+00,  2.961e+00,  -7.367e+00,
      1.273e-01,  1.928e+00,  6.352e+00,  7.941e+00,  3.756e+00,  8.695e+00,
      5.812e+00,  -2.459e+00, -9.508e+00, -4.020e+00, -7.359e+00, 1.431e-01,
      -3.748e+00, -9.234e+00, 5.016e+00,  6.016e+00,  9.148e+00,  6.438e+00,
      -4.051e+00, -3.941e+00, 8.484e+00,  5.034e-01,  3.117e+00,  -1.848e-01,
      -7.559e+00, 2.131e+00,  8.656e+00,  -7.957e+00, 5.996e+00,  2.703e+00,
      -3.375e+00, 5.160e+00,  2.914e-03,  3.871e+00,  -7.156e+00, 9.977e+00,
      -8.656e+00, -1.669e+00, -4.477e+00, -2.135e+00};
  const fp16_t srcb[K * N] = {
      1.484,  -1.692, 6.008,  -9.016, -5.645,  1.574,  0.1078, 7.566,
      3.291,  -4.414, 4.137,  -1.847, 3.535,   -9.04,  -9.88,  3.281,
      -8.99,  -9.56,  -1.234, 5.86,   4.566,   6.18,   3.926,  -2.883,
      -7.44,  8.99,   -1.302, 0.1448, 0.12085, 5.812,  -8.01,  -5.047,
      2.588,  -0.751, -3.979, 1.309,  -1.48,   -2.738, 7.094,  -7.793,
      -8.234, 6.65,   4.46,   7.12,   0.5,     4.707,  6.613,  -7.402,
      -8.72,  5.547,  -0.073, 8.14,   -4.45,   -6.207, -2.9,   -4.293,
      -2.836, -3.867, -4.4,   -1.222, -0.8057, -5.52,  -8.,    4.457};
  const fp32_t srcc[M * N] = {
      3.555,   3.158,  4.543,  2.715,  2.36,    9.72,    8.516,    4.484,
      -1.8125, -4.773, 2.195,  -5.703, -3.385,  -0.0777, 2.809,    4.14,
      5.785,   7.62,   5.742,  0.236,  -0.3367, -7.57,   0.4524,   -6.617,
      2.64,    1.548,  -8.77,  -2.604, 5.133,   3.393,   -0.08624, -7.688,
      -8.305,  -4.402, -2.271, -9.14,  0.322,   2.578,   -3.799,   9.73,
      -4.332,  4.04,   6.695,  1.852,  -9.72,   4.402,   -8.69,    4.64,
      4.844,   -0.461, -1.356, -9.26,  -8.9,    -6.05,   9.68,     -6.055,
      8.62,    -9.836, 0.0679, 7.652,  9.99,    -2.338,  7.074,    -3.164};
  const fp32_t answ[M * N] = {
      -119.56, 46.,    59.72,  109.94, 32.03,  3.91,    -73.4,  -56.7,
      -76.9,   -43.25, 59.03,  85.75,  66.3,   86.94,   72.9,   -55.56,
      -153.8,  46.25,  19.31,  68.94,  -43.06, 191.4,   197.4,  -151.9,
      -212.6,  100.25, 16.03,  148.2,  16.1,   79.7,    29.17,  -188.2,
      35.,     47.06,  -120.2, 3.719,  -20.03, -118.25, -145.4, 47.94,
      87.4,    -21.6,  67.5,   -76.5,  -83.6,  -126.5,  0.289,  42.5,
      -9.94,   -176.6, -72.56, 97.9,   83.25,  -41.22,  114.44, -70.3,
      47.9,    110.06, 48.66,  -97.06, 25.81,  31.84,   -181.5, 69.3};
  SET_MBA0_F16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat16_t ts1 = mla_m(srca, K * sizeof(fp16_t));
  mfloat16_t ts2 = mlb_m(srcb, N * sizeof(fp16_t));
  SET_MBA0_F32();
  mfloat32_t td = mlc_m(srcc, N * sizeof(fp32_t));
  SET_MBA0_F16F32();
  mfloat32_t md = mfwma_hf_mm(td, ts1, ts2);
  SET_MBA0_F32();
  msc_m(md, f32_buffer, N * sizeof(fp32_t));
  EXCEPT_F32_ARRAY_LAX_EQ(answ, f32_buffer, M * N, "MFWMA_MM F16");
}

static void test_mfwma_mm_f32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const fp32_t srca[M * K] = {-17.82614,  -14.510797, 0.09860674, 1.8632965,
                              -14.723708, -0.9304912, 17.473011,  -3.0280242,
                              -5.570245,  9.965738,   17.950687,  15.345987,
                              8.361184,   -17.70233,  5.099757,   -6.0134964};
  const fp32_t srcb[K * N] = {3.9243686,  18.965876,  -6.4208,    -19.18329,
                              -19.144321, -8.0320835, 16.95228,   -0.93569124,
                              -17.24605,  12.073369,  -8.731799,  16.855682,
                              1.6661981,  -5.471339,  -17.458914, -17.961107};
  const fp64_t srcc[M * N] = {-16.55721,  -18.168474, -2.0822563, -1.1843222,
                              6.0576477,  -19.82576,  3.2576487,  -19.074722,
                              -16.556284, 11.965289,  16.142801,  4.886782,
                              7.889533,   13.956632,  -6.7203884, -17.072788};
  const fp64_t answ[M * N] = {192.68983, -248.7091,  -167.0074,  322.55255,
                              -340.2957, -64.07453,  -17.683125, 613.1513,
                              -513.2123, -40.962757, -203.81584, 129.35773,
                              281.63065, 409.19354,  -300.0417,  33.065052};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat32_t ts1 = mla_m(srca, K * sizeof(fp32_t));
  mfloat32_t ts2 = mlb_m(srcb, N * sizeof(fp32_t));
  SET_MBA0_F64();
  mfloat64_t td = mlc_m(srcc, N * sizeof(fp64_t));
  SET_MBA0_F32F64();
  mfloat64_t md = mfwma_mm(td, ts1, ts2);
  SET_MBA0_F64();
  msc_m(md, u64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(answ, u64_buffer, M * N, "MFWMA_MM U32");
}

static void test_mfwma_f_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const fp32_t srca[M * K] = {-17.82614,  -14.510797, 0.09860674, 1.8632965,
                              -14.723708, -0.9304912, 17.473011,  -3.0280242,
                              -5.570245,  9.965738,   17.950687,  15.345987,
                              8.361184,   -17.70233,  5.099757,   -6.0134964};
  const fp32_t srcb[K * N] = {3.9243686,  18.965876,  -6.4208,    -19.18329,
                              -19.144321, -8.0320835, 16.95228,   -0.93569124,
                              -17.24605,  12.073369,  -8.731799,  16.855682,
                              1.6661981,  -5.471339,  -17.458914, -17.961107};
  const fp64_t srcc[M * N] = {-16.55721,  -18.168474, -2.0822563, -1.1843222,
                              6.0576477,  -19.82576,  3.2576487,  -19.074722,
                              -16.556284, 11.965289,  16.142801,  4.886782,
                              7.889533,   13.956632,  -6.7203884, -17.072788};
  const fp64_t answ[M * N] = {192.68983, -248.7091,  -167.0074,  322.55255,
                              -340.2957, -64.07453,  -17.683125, 613.1513,
                              -513.2123, -40.962757, -203.81584, 129.35773,
                              281.63065, 409.19354,  -300.0417,  33.065052};
  SET_MBA0_F32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mfloat32_t ts1 = mla_m(srca, K * sizeof(fp32_t));
  mfloat32_t ts2 = mlb_m(srcb, N * sizeof(fp32_t));
  SET_MBA0_F64();
  mfloat64_t td = mlc_m(srcc, N * sizeof(fp64_t));
  SET_MBA0_F32F64();
  mfloat64_t md = mfwma_f_mm(td, ts1, ts2);
  SET_MBA0_F64();
  msc_m(md, u64_buffer, N * sizeof(fp64_t));
  EXCEPT_F64_ARRAY_LAX_EQ(answ, u64_buffer, M * N, "MFWMA_F_MM U32");
}

static void test_msma_mm_u16() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int16_t srca[M * K] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t srcb[K * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t srcc[M * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t answ[M * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  mint16_t td = mlc_m(srcc, N * sizeof(int16_t));
  mint16_t out1 = msma_mm(td, ts1, ts2);
  mint16_t out2 = msma_h_mm(td, ts1, ts2);
  msc_m(out1, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(answ, i16_buffer, M * N, "MSMA_MM I16");
}

static void test_msma_h_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int16_t srca[M * K] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t srcb[K * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t srcc[M * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  const int16_t answ[M * N] = {
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
      32767, 32767, 32767, 32767};
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  mint16_t td = mlc_m(srcc, N * sizeof(int16_t));
  mint16_t out = msma_h_mm(td, ts1, ts2);
  msc_m(out, i16_buffer, N * sizeof(int16_t));
  EXCEPT_I16_ARRAY_EQ(answ, i16_buffer, M * N, "MSMA_H_MM I16");
}

static void test_msma_mm_u32() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t srcb[K * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t srcc[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t answ[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  mint32_t out = msma_mm(td, ts1, ts2);
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSMA_MM I32");
}

static void test_msma_w_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t srcb[K * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t srcc[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  const int32_t answ[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  mint32_t out = msma_w_mm(td, ts1, ts2);
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSMA_W_MM I32");
}

static void test_msma_mm_u64() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I64();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int64_t srca[M * K] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t srcb[K * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t srcc[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t answ[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  mint64_t ts1 = mla_m(srca, K * sizeof(int64_t));
  mint64_t ts2 = mlb_m(srcb, N * sizeof(int64_t));
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  mint64_t out = msma_mm(td, ts1, ts2);
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MSMA_MM I64");
}

static void test_msma_dw_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int64_t srca[M * K] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t srcb[K * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t srcc[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  const int64_t answ[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  mint64_t ts1 = mla_m(srca, K * sizeof(int64_t));
  mint64_t ts2 = mlb_m(srcb, N * sizeof(int64_t));
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  mint64_t out = msma_dw_mm(td, ts1, ts2);
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MSMA_DW_MM");
}

static void test_mswma_mm_u16() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  const int16_t srca[M * K] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int16_t srcb[K * N] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int32_t srcc[M * N] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int32_t answ[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I16();
  mint32_t out = mswma_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSWMA_MM I16");
}

static void test_mswma_h_mm() {
  const size_t M = 4;
  const size_t K = 4;
  const size_t N = 4;
  SET_MBA0_I16();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int16_t srca[M * K] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int16_t srcb[K * N] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int32_t srcc[M * N] = {-32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768, -32768, -32768,
                               -32768, -32768, -32768, -32768};
  const int32_t answ[M * N] = {2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647,
                               2147483647, 2147483647, 2147483647, 2147483647};
  mint16_t ts1 = mla_m(srca, K * sizeof(int16_t));
  mint16_t ts2 = mlb_m(srcb, N * sizeof(int16_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I16();
  mint32_t out = mswma_h_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(out, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSWMA_H_MM");
}

static void test_mswma_mm_u32() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {-2147483648, -2147483648, -2147483648,
                               -2147483648};
  const int32_t srcb[K * N] = {-2147483648, -2147483648, -2147483648,
                               -2147483648};
  const int64_t srcc[M * N] = {2147483647, 2147483647, 2147483647, 2147483647};
  const int64_t answ[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  SET_MBA0_I64();
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  SET_MBA0_I32();
  mint64_t out = mswma_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MSWMA_MM I32");
}

static void test_mswma_w_mm() {
  const size_t M = 2;
  const size_t K = 2;
  const size_t N = 2;
  SET_MBA0_I32();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  const int32_t srca[M * K] = {-2147483648, -2147483648, -2147483648,
                               -2147483648};
  const int32_t srcb[K * N] = {-2147483648, -2147483648, -2147483648,
                               -2147483648};
  const int64_t srcc[M * N] = {2147483647, 2147483647, 2147483647, 2147483647};
  const int64_t answ[M * N] = {9223372036854775807, 9223372036854775807,
                               9223372036854775807, 9223372036854775807};
  mint32_t ts1 = mla_m(srca, K * sizeof(int32_t));
  mint32_t ts2 = mlb_m(srcb, N * sizeof(int32_t));
  SET_MBA0_I64();
  mint64_t td = mlc_m(srcc, N * sizeof(int64_t));
  SET_MBA0_I32();
  mint64_t out = mswma_w_mm(td, ts1, ts2);
  SET_MBA0_I64();
  msc_m(out, i64_buffer, N * sizeof(int64_t));
  EXCEPT_I64_ARRAY_EQ(answ, i64_buffer, M * N, "MSWMA_DW_MM");
}

static void test_msqma_mm_i8() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const int8_t srca[M * K] = {
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128};
  const int8_t srcb[K * N] = {
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128};
  const int32_t srcc[M * N] = {
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127};
  const int32_t answ[M * N] = {
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint8_t ts1 = mla_m(srca, K * sizeof(int8_t));
  mint8_t ts2 = mlb_m(srcb, N * sizeof(int8_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I8();
  mint32_t md = msqma_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSQMA_B_MM I8");
}

static void test_msqma_b_mm() {
  const size_t M = 8;
  const size_t K = 8;
  const size_t N = 8;
  const int8_t srca[M * K] = {
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128};
  const int8_t srcb[K * N] = {
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
      -128, -128, -128, -128, -128, -128, -128, -128, -128};
  const int32_t srcc[M * N] = {
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127,
      127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127};
  const int32_t answ[M * N] = {
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199,
      131199, 131199, 131199, 131199, 131199, 131199, 131199, 131199};
  SET_MBA0_I8();
  msettilem(M);
  msettilek(K);
  msettilen(N);
  mint8_t ts1 = mla_m(srca, K * sizeof(int8_t));
  mint8_t ts2 = mlb_m(srcb, N * sizeof(int8_t));
  SET_MBA0_I32();
  mint32_t td = mlc_m(srcc, N * sizeof(int32_t));
  SET_MBA0_I8();
  mint32_t md = msqma_b_mm(td, ts1, ts2);
  SET_MBA0_I32();
  msc_m(md, i32_buffer, N * sizeof(int32_t));
  EXCEPT_I32_ARRAY_EQ(answ, i32_buffer, M * N, "MSQMA_MM I8");
}

static void test_mfwma_mm() {
  test_mfwma_mm_f16();
  test_mfwma_hf_mm();
  test_mfwma_mm_f32();
  test_mfwma_f_mm();
}

static void test_mfma_mm() {
  test_mfma_mm_f16();
  // test_mfma_hf_mm();
  // test_mfma_mm_f32();
  // test_mfma_f_mm();
  test_mfma_mm_f64();
  test_mfma_d_mm();
}

static void test_mwma_mm() {
  test_mwma_mm_i16();
  test_mwma_mm_i32();
  test_mwma_h_mm();
  test_mwma_w_mm();
}

static void test_msmau_mm() {
  test_msmau_mm_u16();
  test_msmau_h_mm();
  test_msmau_mm_u32();
  test_msmau_w_mm();
  test_msmau_mm_u64();
  test_msmau_dw_mm();
}

static void test_mmau_mm() {
  test_mmau_mm_u16();
  test_mmau_h_mm();
  test_mmau_mm_u32();
  test_mmau_w_mm();
  test_mmau_mm_u64();
  test_mmau_dw_mm();
}

static void test_mwmau_mm() {
  test_mwmau_mm_u16();
  test_mwmau_h_mm();
  test_mwmau_mm_u32();
  test_mwmau_w_mm();
}

static void test_mswmau_mm() {
  test_mswmau_mm_u16();
  test_mswmau_h_mm();
  test_mswmau_mm_u32();
  test_mswmau_w_mm();
}

static void test_mqmau_mm() {
  test_mqmau_mm_u8();
  test_mqmau_b_mm();
}

static void test_mma_mm() {
  test_mma_mm_i16();
  test_mma_h_mm();
  test_mma_mm_i32();
  test_mma_w_mm();
  test_mma_mm_i64();
  test_mma_dw_mm();
}

static void test_msqmau_mm() {
  test_msqmau_mm_u8();
  test_msqmau_b_mm();
}

static void test_mqma_mm() {
  test_mqma_mm_i8();
  test_mqma_b_mm();
}

static void test_msma_mm() {
  test_msma_mm_u16();
  test_msma_h_mm();
  test_msma_mm_u32();
  test_msma_w_mm();
  test_msma_mm_u64();
  test_msma_dw_mm();
}

static void test_mswma_mm() {
  test_mswma_mm_u16();
  test_mswma_h_mm();
  test_mswma_mm_u32();
  test_mswma_w_mm();
}

static void test_msqma_mm() {
  test_msqma_mm_i8();
  test_msqma_b_mm();
}

static void test_matmul() {
  test_mmau_mm();
  test_mwmau_mm();
  test_mqmau_mm();
  test_msmau_mm();
  test_mswmau_mm();
  test_mma_mm();
  test_msqmau_mm();
  test_mwma_mm();
  test_mqma_mm();
  test_msma_mm();
  test_mswma_mm();
  test_msqma_mm();
  test_mfma_mm();
  test_mfwma_mm();
}