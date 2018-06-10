#ifndef __c6_SistemaCAS_v15_h__
#define __c6_SistemaCAS_v15_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_SistemaCAS_v15InstanceStruct
#define typedef_SFc6_SistemaCAS_v15InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_SistemaCAS_v15;
} SFc6_SistemaCAS_v15InstanceStruct;

#endif                                 /*typedef_SFc6_SistemaCAS_v15InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_SistemaCAS_v15_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_SistemaCAS_v15_get_check_sum(mxArray *plhs[]);
extern void c6_SistemaCAS_v15_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
