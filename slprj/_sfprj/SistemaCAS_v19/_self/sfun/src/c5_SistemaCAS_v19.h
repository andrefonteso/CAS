#ifndef __c5_SistemaCAS_v19_h__
#define __c5_SistemaCAS_v19_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_SistemaCAS_v19InstanceStruct
#define typedef_SFc5_SistemaCAS_v19InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_SistemaCAS_v19;
} SFc5_SistemaCAS_v19InstanceStruct;

#endif                                 /*typedef_SFc5_SistemaCAS_v19InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_SistemaCAS_v19_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_SistemaCAS_v19_get_check_sum(mxArray *plhs[]);
extern void c5_SistemaCAS_v19_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif