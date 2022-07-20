/*
 * File: alg_projection_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

#ifndef ALG_PROJECTION_EMXUTIL_H
#define ALG_PROJECTION_EMXUTIL_H

/* Include Files */
#include "alg_projection_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int oldNumel);

extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);

extern void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for alg_projection_emxutil.h
 *
 * [EOF]
 */
