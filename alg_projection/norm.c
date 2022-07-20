/*
 * File: norm.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/* Include Files */
#include "norm.h"
#include "alg_projection_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 * Return Type  : float
 */
float b_norm(const emxArray_real32_T *x)
{
  float absxk;
  float scale;
  float t;
  float y;
  int k;
  int kend;
  if (x->size[1] == 0) {
    y = 0.0F;
  } else {
    y = 0.0F;
    if (x->size[1] == 1) {
      y = (float)fabs(x->data[0]);
    } else {
      scale = 1.29246971E-26F;
      kend = x->size[1];
      for (k = 0; k < kend; k++) {
        absxk = (float)fabs(x->data[k]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * (float)sqrt(y);
    }
  }
  return y;
}

/*
 * File trailer for norm.c
 *
 * [EOF]
 */
