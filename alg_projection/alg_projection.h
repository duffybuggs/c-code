/*
 * File: alg_projection.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

#ifndef ALG_PROJECTION_H
#define ALG_PROJECTION_H

/* Include Files */
#include "alg_projection_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern float alg_projection(const emxArray_real32_T *target,
                            const emxArray_real32_T *P,
                            const emxArray_real32_T *U, float freq,
                            const emxArray_real32_T *d);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for alg_projection.h
 *
 * [EOF]
 */
