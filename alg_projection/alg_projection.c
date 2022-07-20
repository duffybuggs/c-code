/*
 * File: alg_projection.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/* Include Files */
#include "alg_projection.h"
#include "alg_projection_data.h"
#include "alg_projection_emxutil.h"
#include "alg_projection_initialize.h"
#include "alg_projection_types.h"
#include "minOrMax.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real32_T *target
 *                const emxArray_real32_T *P
 *                const emxArray_real32_T *U
 *                float freq
 *                const emxArray_real32_T *d
 * Return Type  : float
 */
float alg_projection(const emxArray_real32_T *target,
                     const emxArray_real32_T *P, const emxArray_real32_T *U,
                     float freq, const emxArray_real32_T *d)
{
  emxArray_real32_T *B;
  emxArray_real32_T *b_P;
  emxArray_real32_T *b_rx_p;
  emxArray_real32_T *dis_p;
  emxArray_real32_T *rx_p;
  float absxk;
  float fcnOutput;
  float output;
  float scale;
  float t;
  float y_tmp;
  int boffset;
  int j;
  int k;
  int lastBlockLength;
  int nblocks;
  int xblockoffset;
  if (!isInitialized_alg_projection) {
    alg_projection_initialize();
  }
  emxInit_real32_T(&rx_p, 2);
  emxInit_real32_T(&dis_p, 2);
  emxInit_real32_T(&b_rx_p, 2);
  emxInit_real32_T(&b_P, 2);
  if (d->size[1] == 1.0F) {
    /* ******************* normal projection algorithm ********************** */
    /*  Obtain the projected points with plane norm. */
    /*  hui.chen@kaust.edu.sa */
    absxk = (float)fabs(freq);
    y_tmp = absxk * absxk;
    /* t0 = -(f*p')/(norm(f)^2); */
    j = b_rx_p->size[0] * b_rx_p->size[1];
    b_rx_p->size[0] = target->size[0];
    b_rx_p->size[1] = target->size[1];
    emxEnsureCapacity_real32_T(b_rx_p, j);
    boffset = target->size[1];
    for (j = 0; j < boffset; j++) {
      xblockoffset = target->size[0];
      for (nblocks = 0; nblocks < xblockoffset; nblocks++) {
        b_rx_p->data[nblocks + b_rx_p->size[0] * j] =
            target->data[nblocks + target->size[0] * j] +
            freq *
                (-(target->data[j + target->size[0] * nblocks] * freq) / y_tmp);
      }
    }
    j = dis_p->size[0] * dis_p->size[1];
    dis_p->size[0] = 1;
    dis_p->size[1] = (int)(float)P->size[0];
    emxEnsureCapacity_real32_T(dis_p, j);
    boffset = (int)(float)P->size[0];
    for (j = 0; j < boffset; j++) {
      dis_p->data[j] = 0.0F;
    }
    if (P->size[0] == 1.0F) {
      boffset = P->size[1];
      j = b_rx_p->size[0] * b_rx_p->size[1];
      b_rx_p->size[0] = 1;
      b_rx_p->size[1] = P->size[1];
      emxEnsureCapacity_real32_T(b_rx_p, j);
      for (j = 0; j < boffset; j++) {
        b_rx_p->data[j] = P->data[j] - b_rx_p->data[j];
      }
      if (b_rx_p->size[1] == 0) {
        fcnOutput = 0.0F;
      } else {
        xblockoffset = b_rx_p->size[1];
        fcnOutput = 0.0F;
        if (b_rx_p->size[1] == 1) {
          fcnOutput = (float)fabs(b_rx_p->data[0]);
        } else {
          scale = 1.29246971E-26F;
          for (k = 0; k < xblockoffset; k++) {
            absxk = (float)fabs(b_rx_p->data[k]);
            if (absxk > scale) {
              t = scale / absxk;
              fcnOutput = fcnOutput * t * t + 1.0F;
              scale = absxk;
            } else {
              t = absxk / scale;
              fcnOutput += t * t;
            }
          }
          fcnOutput = scale * (float)sqrt(fcnOutput);
        }
      }
      j = dis_p->size[0] * dis_p->size[1];
      dis_p->size[0] = 1;
      dis_p->size[1] = 1;
      emxEnsureCapacity_real32_T(dis_p, j);
      dis_p->data[0] = fcnOutput;
    } else {
      if ((P->size[0] == 0) || (P->size[1] == 0)) {
        boffset = 0;
      } else {
        xblockoffset = P->size[0];
        boffset = P->size[1];
        if (xblockoffset > boffset) {
          boffset = xblockoffset;
        }
      }
      j = (int)(float)boffset;
      for (xblockoffset = 0; xblockoffset < j; xblockoffset++) {
        boffset = P->size[1];
        nblocks = b_P->size[0] * b_P->size[1];
        b_P->size[0] = 1;
        b_P->size[1] = P->size[1];
        emxEnsureCapacity_real32_T(b_P, nblocks);
        for (nblocks = 0; nblocks < boffset; nblocks++) {
          b_P->data[nblocks] = P->data[((int)((float)xblockoffset + 1.0F) +
                                        P->size[0] * nblocks) -
                                       1] -
                               b_rx_p->data[b_rx_p->size[0] * nblocks];
        }
        dis_p->data[(int)((float)xblockoffset + 1.0F) - 1] = b_norm(b_P);
      }
    }
    minimum(dis_p, &scale, &lastBlockLength);
    j = dis_p->size[0] * dis_p->size[1];
    dis_p->size[0] = target->size[0];
    dis_p->size[1] = target->size[1];
    emxEnsureCapacity_real32_T(dis_p, j);
    boffset = target->size[1];
    for (j = 0; j < boffset; j++) {
      xblockoffset = target->size[0];
      for (nblocks = 0; nblocks < xblockoffset; nblocks++) {
        dis_p->data[nblocks + j] =
            target->data[nblocks + target->size[0] * j] +
            U->data[((int)(float)lastBlockLength + U->size[0] * j) - 1];
      }
    }
    /*  Obtain the projected points with plane norm. */
    /*  hui.chen@kaust.edu.sa */
    /* t0 = -(f*p')/(norm(f)^2); */
    t = dis_p->data[0] + freq * (-(dis_p->data[0] * freq) / y_tmp);
    if (dis_p->size[1] == 0) {
      scale = 0.0F;
    } else {
      if (dis_p->size[1] <= 1024) {
        boffset = dis_p->size[1];
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        boffset = 1024;
        nblocks = dis_p->size[1] / 1024;
        lastBlockLength = dis_p->size[1] - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      scale = dis_p->data[0];
      for (k = 2; k <= boffset; k++) {
        scale += dis_p->data[k - 1];
      }
      for (j = 2; j <= nblocks; j++) {
        xblockoffset = (j - 1) << 10;
        absxk = dis_p->data[xblockoffset];
        if (j == nblocks) {
          boffset = lastBlockLength;
        } else {
          boffset = 1024;
        }
        for (k = 2; k <= boffset; k++) {
          absxk += dis_p->data[(xblockoffset + k) - 1];
        }
        scale += absxk;
      }
    }
    fcnOutput = scale / (float)dis_p->size[1];
    if (fcnOutput < 0.0F) {
      fcnOutput = -1.0F;
    } else if (fcnOutput > 0.0F) {
      fcnOutput = 1.0F;
    } else if (fcnOutput == 0.0F) {
      fcnOutput = 0.0F;
    }
    j = b_P->size[0] * b_P->size[1];
    b_P->size[0] = 1;
    b_P->size[1] = dis_p->size[1];
    emxEnsureCapacity_real32_T(b_P, j);
    boffset = dis_p->size[1];
    for (j = 0; j < boffset; j++) {
      b_P->data[j] = t - dis_p->data[j];
    }
    j = rx_p->size[0] * rx_p->size[1];
    rx_p->size[0] = 1;
    rx_p->size[1] = 1;
    emxEnsureCapacity_real32_T(rx_p, j);
    for (j = 0; j < 1; j++) {
      rx_p->data[0] = d->data[0] * 2.0F * 3.14159274F * freq / v;
    }
    output = (float)asin(fcnOutput * b_norm(b_P) / b_norm(rx_p)) * 180.0F /
             3.14159274F;
  } else {
    /*  Obtain the projected points with plane norm. */
    /*  hui.chen@kaust.edu.sa */
    j = b_rx_p->size[0] * b_rx_p->size[1];
    b_rx_p->size[0] = target->size[1];
    b_rx_p->size[1] = target->size[0];
    emxEnsureCapacity_real32_T(b_rx_p, j);
    boffset = target->size[0];
    for (j = 0; j < boffset; j++) {
      xblockoffset = target->size[1];
      for (nblocks = 0; nblocks < xblockoffset; nblocks++) {
        b_rx_p->data[nblocks + b_rx_p->size[0] * j] =
            target->data[j + target->size[0] * nblocks];
      }
    }
    emxInit_real32_T(&B, 2);
    absxk = b_norm(d);
    scale = absxk * absxk;
    /* t0 = -(f*p')/(norm(f)^2); */
    xblockoffset = b_rx_p->size[0];
    j = B->size[0] * B->size[1];
    B->size[0] = b_rx_p->size[0];
    B->size[1] = d->size[1];
    emxEnsureCapacity_real32_T(B, j);
    boffset = d->size[1];
    for (j = 0; j < boffset; j++) {
      for (nblocks = 0; nblocks < xblockoffset; nblocks++) {
        B->data[nblocks + B->size[0] * j] =
            -(b_rx_p->data[nblocks] * d->data[j]) / scale;
      }
    }
    xblockoffset = d->size[1];
    nblocks = B->size[1];
    j = rx_p->size[0] * rx_p->size[1];
    rx_p->size[0] = 1;
    rx_p->size[1] = B->size[1];
    emxEnsureCapacity_real32_T(rx_p, j);
    for (j = 0; j < nblocks; j++) {
      boffset = j * B->size[0];
      rx_p->data[j] = 0.0F;
      for (k = 0; k < xblockoffset; k++) {
        rx_p->data[j] += d->data[k] * B->data[boffset + k];
      }
    }
    emxFree_real32_T(&B);
    boffset = target->size[0] * target->size[1];
    j = rx_p->size[0] * rx_p->size[1];
    rx_p->size[0] = target->size[0];
    rx_p->size[1] = target->size[1];
    emxEnsureCapacity_real32_T(rx_p, j);
    for (j = 0; j < boffset; j++) {
      rx_p->data[j] += target->data[j];
    }
    j = dis_p->size[0] * dis_p->size[1];
    dis_p->size[0] = 1;
    dis_p->size[1] = (int)(float)P->size[0];
    emxEnsureCapacity_real32_T(dis_p, j);
    boffset = (int)(float)P->size[0];
    for (j = 0; j < boffset; j++) {
      dis_p->data[j] = 0.0F;
    }
    if (P->size[0] == 1.0F) {
      j = b_P->size[0] * b_P->size[1];
      b_P->size[0] = 1;
      b_P->size[1] = P->size[1];
      emxEnsureCapacity_real32_T(b_P, j);
      boffset = P->size[1];
      for (j = 0; j < boffset; j++) {
        b_P->data[j] = P->data[j] - rx_p->data[j];
      }
      j = dis_p->size[0] * dis_p->size[1];
      dis_p->size[0] = 1;
      dis_p->size[1] = 1;
      emxEnsureCapacity_real32_T(dis_p, j);
      dis_p->data[0] = b_norm(b_P);
    } else {
      if ((P->size[0] == 0) || (P->size[1] == 0)) {
        boffset = 0;
      } else {
        xblockoffset = P->size[0];
        boffset = P->size[1];
        if (xblockoffset > boffset) {
          boffset = xblockoffset;
        }
      }
      j = (int)(float)boffset;
      for (xblockoffset = 0; xblockoffset < j; xblockoffset++) {
        boffset = P->size[1];
        nblocks = b_P->size[0] * b_P->size[1];
        b_P->size[0] = 1;
        b_P->size[1] = P->size[1];
        emxEnsureCapacity_real32_T(b_P, nblocks);
        for (nblocks = 0; nblocks < boffset; nblocks++) {
          b_P->data[nblocks] = P->data[((int)((float)xblockoffset + 1.0F) +
                                        P->size[0] * nblocks) -
                                       1] -
                               rx_p->data[nblocks];
        }
        dis_p->data[(int)((float)xblockoffset + 1.0F) - 1] = b_norm(b_P);
      }
    }
    minimum(dis_p, &scale, &lastBlockLength);
    j = dis_p->size[0] * dis_p->size[1];
    dis_p->size[0] = 1;
    dis_p->size[1] = d->size[1];
    emxEnsureCapacity_real32_T(dis_p, j);
    boffset = d->size[1];
    for (j = 0; j < boffset; j++) {
      dis_p->data[j] = d->data[j] / absxk;
    }
    xblockoffset = d->size[1];
    nblocks = b_rx_p->size[1];
    j = rx_p->size[0] * rx_p->size[1];
    rx_p->size[0] = 1;
    rx_p->size[1] = b_rx_p->size[1];
    emxEnsureCapacity_real32_T(rx_p, j);
    for (j = 0; j < nblocks; j++) {
      boffset = j * b_rx_p->size[0];
      rx_p->data[j] = 0.0F;
      for (k = 0; k < xblockoffset; k++) {
        rx_p->data[j] += d->data[k] * b_rx_p->data[boffset + k];
      }
    }
    scale = dis_p->data[0];
    j = dis_p->size[0] * dis_p->size[1];
    dis_p->size[0] = 1;
    dis_p->size[1] = rx_p->size[1];
    emxEnsureCapacity_real32_T(dis_p, j);
    boffset = rx_p->size[1];
    for (j = 0; j < boffset; j++) {
      dis_p->data[j] =
          (scale * (rx_p->data[j] / absxk) +
           U->data[((int)(float)lastBlockLength + U->size[0] * j) - 1]) +
          P->data[((int)(float)lastBlockLength + P->size[0] * j) - 1];
    }
    output = (float)asin(dis_p->data[0] * v / 2.0F / 3.14159274F / freq /
                         d->data[0]) *
             180.0F / 3.14159274F;
  }
  emxFree_real32_T(&b_P);
  emxFree_real32_T(&b_rx_p);
  emxFree_real32_T(&dis_p);
  emxFree_real32_T(&rx_p);
  return output;
}

/*
 * File trailer for alg_projection.c
 *
 * [EOF]
 */
