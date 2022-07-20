/*
 * File: _coder_alg_projection_info.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 20-Jul-2022 15:45:01
 */

/* Include Files */
#include "_coder_alg_projection_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789cc5534d4ec240141e0c126382b072cd056023c6c45d05150960130a0b1d03b50cb4d0"
      "99a933ad819d3730f104eebc864b8fe08ab358e8df48a89010f0252f"
      "d3afdf9b7eef7b9d01899b7a02007004bc784f796bdacda99b59fffd1ef81d8b7c62c93a"
      "15eaf74132dc27d6bdfaab46898dc6b607888a51b8b347b14154622b",
      "130b018638359f516fcef40d132906464d113466085f09540866d4ecb9a4236dd4743060"
      "3a8f3a344510cee34bf00b04bfc935e7d18b9947d6c7017f7ff9503a"
      "872d8e1887ba05cb5473302236877549a9491790a38163aa502ecbb07c2be52537557340"
      "9961eb98e7b1ca6dc46031e7f2b93e65b946ab2641b7a063313a449a",
      "6d5052c0a22f6b435f877ff812795fbf437ca3817e7743fd54acbec770830c4c14e97d6e"
      "a8d715f032bf01bf8dff18cdb08057cd2fb3a69fb87b9a0607e0c5bd"
      "ec99b7ef79c9aef4948fea4ef582f82fbd718cdebae7f138462fbbc09f4deeda23e3a4fd"
      "5429d6ab8fc3f1f5909dca95a80f39a68f4067551f40c0621fdbfefe",
      "0fd99a9fbc", ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1720U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[5] = {"Version", "ResolvedFunctions",
                                    "EntryPoints", "CoverageInfo",
                                    "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"alg_projection"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, (const char_T *)"FullPath",
      emlrtMxCreateString(
          (const char_T
               *)"C:\\Users\\hp\\Documents\\MATLAB\\segula\\PDP\\DOA-AOA-"
                 "algorithms-master\\4 PDP for NULA\\alg_projection.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(738722.63668981486));
  xResult =
      emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, (const char_T *)"Version",
                emlrtMxCreateString((const char_T *)"9.10.0.1602886 (R2021a)"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_alg_projection_info.c
 *
 * [EOF]
 */
