/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "alg_projection.h"
#include "alg_projection_emxAPI.h"
#include "alg_projection_terminate.h"
#include "alg_projection_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static emxArray_real32_T *argInit_1xUnbounded_real32_T(void);

static float argInit_real32_T(void);

static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void);

static void main_alg_projection(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *argInit_1xUnbounded_real32_T(void)
{
  emxArray_real32_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real32_T(1, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx1] = argInit_real32_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real32_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real32_T(2, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real32_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_alg_projection(void)
{
  emxArray_real32_T *P;
  emxArray_real32_T *U;
  emxArray_real32_T *d;
  emxArray_real32_T *target;
  float output;
  /* Initialize function 'alg_projection' input arguments. */
  /* Initialize function input argument 'target'. */
  target = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'P'. */
  P = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'U'. */
  U = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'd'. */
  d = argInit_1xUnbounded_real32_T();
  /* Call the entry-point 'alg_projection'. */
  output = alg_projection(target, P, U, argInit_real32_T(), d);
  emxDestroyArray_real32_T(d);
  emxDestroyArray_real32_T(U);
  emxDestroyArray_real32_T(P);
  emxDestroyArray_real32_T(target);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_alg_projection();
  /* Terminate the application.
You do not need to do this more than one time. */
  alg_projection_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
