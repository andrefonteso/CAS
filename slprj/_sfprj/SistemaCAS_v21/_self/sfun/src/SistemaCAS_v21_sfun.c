/* Include files */

#include "SistemaCAS_v21_sfun.h"
#include "SistemaCAS_v21_sfun_debug_macros.h"
#include "c1_SistemaCAS_v21.h"
#include "c2_SistemaCAS_v21.h"
#include "c3_SistemaCAS_v21.h"
#include "c4_SistemaCAS_v21.h"
#include "c5_SistemaCAS_v21.h"
#include "c6_SistemaCAS_v21.h"
#include "c9_SistemaCAS_v21.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _SistemaCAS_v21MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void SistemaCAS_v21_initializer(void)
{
}

void SistemaCAS_v21_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_SistemaCAS_v21_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_SistemaCAS_v21_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_SistemaCAS_v21_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1211009823U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1856003375U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(145642781U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4142848229U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(504864114U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(719991255U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(617029366U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3633543134U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c1_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c2_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c3_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c4_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c5_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c6_SistemaCAS_v21_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_SistemaCAS_v21_get_check_sum(mxArray *plhs[]);
          sf_c9_SistemaCAS_v21_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(948031757U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3107181897U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(596060070U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1956949388U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_SistemaCAS_v21_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(aiChksum, "8f3IlEjl1xkz9JoXMw5fkB") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c1_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "9YwwWltZpOCh47Ma5OHXgG") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c2_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "c4iNzyqaKsl3w2nZrnPCGH") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c3_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "pEHcMZvjZJhtabXdYAiQiB") == 0) {
          extern mxArray *sf_c4_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c4_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "dZfOdnQwomXb8RSlabsPfE") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c5_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "bogPVQW52ale0zOoAyEoB") == 0) {
          extern mxArray *sf_c6_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c6_SistemaCAS_v21_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "R6B5JUObOrogWuUWHsDHQE") == 0) {
          extern mxArray *sf_c9_SistemaCAS_v21_get_autoinheritance_info(void);
          plhs[0] = sf_c9_SistemaCAS_v21_get_autoinheritance_info();
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

unsigned int sf_SistemaCAS_v21_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_SistemaCAS_v21_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_SistemaCAS_v21_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_SistemaCAS_v21_get_eml_resolved_functions_info();
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

unsigned int sf_SistemaCAS_v21_third_party_uses_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "iCim7vQYkNukMhShhdQFFG") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c1_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "wCogUrZmGn6LhSvbs5EVMB") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c2_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "wsxyDEhH9c1J1oVNkbUsY") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c3_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "RuP3UzUk1T3Z8HZLaTS24B") == 0) {
          extern mxArray *sf_c4_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c4_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "k7zK6VDAW95UeTpPan303C") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c5_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "HMmHWC1Gr2iEdfwJRMrPTB") == 0) {
          extern mxArray *sf_c6_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c6_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fJrYrPc07iJ9Xxb5L3uJJH") == 0) {
          extern mxArray *sf_c9_SistemaCAS_v21_third_party_uses_info(void);
          plhs[0] = sf_c9_SistemaCAS_v21_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_SistemaCAS_v21_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "iCim7vQYkNukMhShhdQFFG") == 0) {
          extern mxArray *sf_c1_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "wCogUrZmGn6LhSvbs5EVMB") == 0) {
          extern mxArray *sf_c2_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "wsxyDEhH9c1J1oVNkbUsY") == 0) {
          extern mxArray *sf_c3_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "RuP3UzUk1T3Z8HZLaTS24B") == 0) {
          extern mxArray *sf_c4_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "k7zK6VDAW95UeTpPan303C") == 0) {
          extern mxArray *sf_c5_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "HMmHWC1Gr2iEdfwJRMrPTB") == 0) {
          extern mxArray *sf_c6_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "fJrYrPc07iJ9Xxb5L3uJJH") == 0) {
          extern mxArray *sf_c9_SistemaCAS_v21_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_SistemaCAS_v21_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void SistemaCAS_v21_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _SistemaCAS_v21MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "SistemaCAS_v21","sfun",0,7,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _SistemaCAS_v21MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _SistemaCAS_v21MachineNumber_,0);
}

void SistemaCAS_v21_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_SistemaCAS_v21_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("SistemaCAS_v21",
      "SistemaCAS_v21");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_SistemaCAS_v21_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
