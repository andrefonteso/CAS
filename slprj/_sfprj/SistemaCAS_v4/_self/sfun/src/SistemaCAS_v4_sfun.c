/* Include files */

#include "SistemaCAS_v4_sfun.h"
#include "SistemaCAS_v4_sfun_debug_macros.h"
#include "c1_SistemaCAS_v4.h"
#include "c2_SistemaCAS_v4.h"
#include "c3_SistemaCAS_v4.h"
#include "c5_SistemaCAS_v4.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SistemaCAS_v4MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void SistemaCAS_v4_initializer(void)
{
}

void SistemaCAS_v4_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SistemaCAS_v4_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SistemaCAS_v4_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SistemaCAS_v4_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SistemaCAS_v4_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_SistemaCAS_v4_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SistemaCAS_v4_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1206581574U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3541018465U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(424088202U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2632197459U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3205472496U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4216611934U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2424397623U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3168936728U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SistemaCAS_v4_get_check_sum(mxArray *plhs[]);
          sf_c1_SistemaCAS_v4_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SistemaCAS_v4_get_check_sum(mxArray *plhs[]);
          sf_c2_SistemaCAS_v4_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SistemaCAS_v4_get_check_sum(mxArray *plhs[]);
          sf_c3_SistemaCAS_v4_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_SistemaCAS_v4_get_check_sum(mxArray *plhs[]);
          sf_c5_SistemaCAS_v4_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2028909556U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2941274745U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4262876117U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1759489780U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SistemaCAS_v4_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "VE0NV655ppExXAevjbQbAB") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v4_get_autoinheritance_info(void);
          plhs[0] = sf_c1_SistemaCAS_v4_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "fzRp9nRshXxUN0xX7e82XC") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v4_get_autoinheritance_info(void);
          plhs[0] = sf_c2_SistemaCAS_v4_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "O3Ox3YVLC0wmA9SliFI1oF") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v4_get_autoinheritance_info(void);
          plhs[0] = sf_c3_SistemaCAS_v4_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "cQasH4ZVSHTZIMF9PZ8AUD") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v4_get_autoinheritance_info(void);
          plhs[0] = sf_c5_SistemaCAS_v4_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SistemaCAS_v4_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_SistemaCAS_v4_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SistemaCAS_v4_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_SistemaCAS_v4_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SistemaCAS_v4_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SistemaCAS_v4_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SistemaCAS_v4_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_SistemaCAS_v4_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_SistemaCAS_v4_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SistemaCAS_v4_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "Id8yMLNwKXuE9XW13cu4E") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v4_third_party_uses_info(void);
          plhs[0] = sf_c1_SistemaCAS_v4_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "HU4HiFfRlVVFGpsYyxfQEE") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v4_third_party_uses_info(void);
          plhs[0] = sf_c2_SistemaCAS_v4_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "3A4OauB4nABXtqc7Nx7FMC") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v4_third_party_uses_info(void);
          plhs[0] = sf_c3_SistemaCAS_v4_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "28U4d2LT2plAldzOB1yoMB") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v4_third_party_uses_info(void);
          plhs[0] = sf_c5_SistemaCAS_v4_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_SistemaCAS_v4_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "Id8yMLNwKXuE9XW13cu4E") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v4_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_SistemaCAS_v4_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "HU4HiFfRlVVFGpsYyxfQEE") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v4_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_SistemaCAS_v4_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "3A4OauB4nABXtqc7Nx7FMC") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v4_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_SistemaCAS_v4_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "28U4d2LT2plAldzOB1yoMB") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v4_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_SistemaCAS_v4_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SistemaCAS_v4_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _SistemaCAS_v4MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "SistemaCAS_v4","sfun",0,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SistemaCAS_v4MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SistemaCAS_v4MachineNumber_,0);
}

void SistemaCAS_v4_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SistemaCAS_v4_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("SistemaCAS_v4",
      "SistemaCAS_v4");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SistemaCAS_v4_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
