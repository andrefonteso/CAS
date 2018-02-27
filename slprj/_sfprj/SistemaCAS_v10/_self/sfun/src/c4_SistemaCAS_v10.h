#ifndef __c4_SistemaCAS_v10_h__
#define __c4_SistemaCAS_v10_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_SistemaCAS_v10InstanceStruct
#define typedef_SFc4_SistemaCAS_v10InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_SistemaCAS_v10;
} SFc4_SistemaCAS_v10InstanceStruct;

#endif                                 /*typedef_SFc4_SistemaCAS_v10InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_SistemaCAS_v10_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_SistemaCAS_v10_get_check_sum(mxArray *plhs[]);
extern void c4_SistemaCAS_v10_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
