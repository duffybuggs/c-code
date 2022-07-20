/*
 * File: alg_projection_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/* Include Files */
#include "alg_projection_initialize.h"
#include "alg_projection_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void alg_projection_initialize(void)
{
  rt_InitInfAndNaN();
  v = 3.0E+8F;
  isInitialized_alg_projection = true;
}

/*
 * File trailer for alg_projection_initialize.c
 *
 * [EOF]
 */
