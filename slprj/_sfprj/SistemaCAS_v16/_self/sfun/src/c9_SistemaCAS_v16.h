#ifndef __c9_SistemaCAS_v16_h__
#define __c9_SistemaCAS_v16_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_SistemaCAS_v16InstanceStruct
#define typedef_SFc9_SistemaCAS_v16InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_SistemaCAS_v16;
} SFc9_SistemaCAS_v16InstanceStruct;

#endif                                 /*typedef_SFc9_SistemaCAS_v16InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_SistemaCAS_v16_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_SistemaCAS_v16_get_check_sum(mxArray *plhs[]);
extern void c9_SistemaCAS_v16_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
