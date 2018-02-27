/* Include files */

#include "untitled_sfun.h"
#include "untitled_sfun_debug_macros.h"
#include "c1_untitled.h"
#include "c2_untitled.h"
#include "c3_untitled.h"
#include "c4_untitled.h"
#include "c5_untitled.h"
#include "c6_untitled.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _untitledMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void untitled_initializer(void)
{
}

void untitled_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_untitled_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_untitled_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_untitled_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(891698652U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1384717347U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1989006122U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2913025108U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2181060594U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(959401712U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1181572603U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2351801568U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_untitled_get_check_sum(mxArray *plhs[]);
          sf_c1_untitled_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_untitled_get_check_sum(mxArray *plhs[]);
          sf_c2_untitled_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_untitled_get_check_sum(mxArray *plhs[]);
          sf_c3_untitled_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_untitled_get_check_sum(mxArray *plhs[]);
          sf_c4_untitled_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_untitled_get_check_sum(mxArray *plhs[]);
          sf_c5_untitled_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_untitled_get_check_sum(mxArray *plhs[]);
          sf_c6_untitled_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1972292707U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1415434050U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(248862462U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3450539295U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_untitled_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "029rdDV8K9ZxQ49DsrKfbD") == 0) {
          extern mxArray *sf_c1_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c1_untitled_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "4d3De10GUdbwURwik1ZGbC") == 0) {
          extern mxArray *sf_c2_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c2_untitled_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "W5gMPbOeDQlXtqwjome9LH") == 0) {
          extern mxArray *sf_c3_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c3_untitled_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "JZ2SzK9AyrMTRmgiviZWME") == 0) {
          extern mxArray *sf_c4_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c4_untitled_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "4lXSbkM7sIXSQzjcI7e15") == 0) {
          extern mxArray *sf_c5_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c5_untitled_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "VGpd2k8aOFBhGPbWJhXDcC") == 0) {
          extern mxArray *sf_c6_untitled_get_autoinheritance_info(void);
          plhs[0] = sf_c6_untitled_get_autoinheritance_info();
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

unsigned int sf_untitled_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_untitled_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_untitled_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_untitled_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_untitled_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_untitled_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_untitled_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_untitled_get_eml_resolved_functions_info();
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

unsigned int sf_untitled_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "ik4IUR7PCBT9cmkxDj3qa") == 0) {
          extern mxArray *sf_c1_untitled_third_party_uses_info(void);
          plhs[0] = sf_c1_untitled_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "FPhGR0naTRDmWXTnVQ5ajG") == 0) {
          extern mxArray *sf_c2_untitled_third_party_uses_info(void);
          plhs[0] = sf_c2_untitled_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OnlHwmAOoqZJcszNxWOvi") == 0) {
          extern mxArray *sf_c3_untitled_third_party_uses_info(void);
          plhs[0] = sf_c3_untitled_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "0d4fvC7oLZUfdrixaKTF0G") == 0) {
          extern mxArray *sf_c4_untitled_third_party_uses_info(void);
          plhs[0] = sf_c4_untitled_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "WFP8Y4uaR78I3vlkn6l3OE") == 0) {
          extern mxArray *sf_c5_untitled_third_party_uses_info(void);
          plhs[0] = sf_c5_untitled_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "ZHd8ryTgPYfEiwNKyR10uD") == 0) {
          extern mxArray *sf_c6_untitled_third_party_uses_info(void);
          plhs[0] = sf_c6_untitled_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_untitled_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "ik4IUR7PCBT9cmkxDj3qa") == 0) {
          extern mxArray *sf_c1_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "FPhGR0naTRDmWXTnVQ5ajG") == 0) {
          extern mxArray *sf_c2_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "OnlHwmAOoqZJcszNxWOvi") == 0) {
          extern mxArray *sf_c3_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "0d4fvC7oLZUfdrixaKTF0G") == 0) {
          extern mxArray *sf_c4_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "WFP8Y4uaR78I3vlkn6l3OE") == 0) {
          extern mxArray *sf_c5_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "ZHd8ryTgPYfEiwNKyR10uD") == 0) {
          extern mxArray *sf_c6_untitled_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_untitled_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void untitled_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _untitledMachineNumber_ = sf_debug_initialize_machine(debugInstance,"untitled",
    "sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_untitledMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_untitledMachineNumber_,0);
}

void untitled_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_untitled_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("untitled",
      "untitled");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_untitled_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
