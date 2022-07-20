/*
 * File: _coder_alg_projection_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

#ifndef _CODER_ALG_PROJECTION_API_H
#define _CODER_ALG_PROJECTION_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T
struct emxArray_real32_T {
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real32_T */
#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T
typedef struct emxArray_real32_T emxArray_real32_T;
#endif /* typedef_emxArray_real32_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void MEXGlobalSyncInFunction(const emlrtStack *sp);

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);

real32_T alg_projection(emxArray_real32_T *target, emxArray_real32_T *P,
                        emxArray_real32_T *U, real32_T freq,
                        emxArray_real32_T *d);

void alg_projection_api(const mxArray *const prhs[5], const mxArray **plhs);

void alg_projection_atexit(void);

void alg_projection_initialize(void);

void alg_projection_terminate(void);

void alg_projection_xil_shutdown(void);

void alg_projection_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_alg_projection_api.h
 *
 * [EOF]
 */
