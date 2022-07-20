/*
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/* Include Files */
#include "minOrMax.h"
#include "alg_projection_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *x
 *                float *ex
 *                int *idx
 * Return Type  : void
 */
void minimum(const emxArray_real32_T *x, float *ex, int *idx)
{
  float f;
  int i;
  int k;
  int last;
  boolean_T exitg1;
  last = x->size[1];
  if (x->size[1] <= 2) {
    if (x->size[1] == 1) {
      *ex = x->data[0];
      *idx = 1;
    } else if ((x->data[0] > x->data[x->size[1] - 1]) ||
               (rtIsNaNF(x->data[0]) && (!rtIsNaNF(x->data[x->size[1] - 1])))) {
      *ex = x->data[x->size[1] - 1];
      *idx = x->size[1];
    } else {
      *ex = x->data[0];
      *idx = 1;
    }
  } else {
    if (!rtIsNaNF(x->data[0])) {
      *idx = 1;
    } else {
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaNF(x->data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x->data[0];
      *idx = 1;
    } else {
      *ex = x->data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        f = x->data[k - 1];
        if (*ex > f) {
          *ex = f;
          *idx = k;
        }
      }
    }
  }
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
