#ifndef __c4_SistemaCAS_v21_h__
#define __c4_SistemaCAS_v21_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_SistemaCAS_v21InstanceStruct
#define typedef_SFc4_SistemaCAS_v21InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_SistemaCAS_v21;
} SFc4_SistemaCAS_v21InstanceStruct;

#endif                                 /*typedef_SFc4_SistemaCAS_v21InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_SistemaCAS_v21_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
extern void c4_SistemaCAS_v21_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
