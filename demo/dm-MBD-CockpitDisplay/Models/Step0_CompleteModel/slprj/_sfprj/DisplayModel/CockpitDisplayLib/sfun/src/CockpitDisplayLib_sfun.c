/* Include files */

#include "CockpitDisplayLib_sfun.h"
#include "CockpitDisplayLib_sfun_debug_macros.h"
#include "c1_CockpitDisplayLib.h"
#include "c2_CockpitDisplayLib.h"
#include "c8_CockpitDisplayLib.h"
#include "c9_CockpitDisplayLib.h"
#include "c10_CockpitDisplayLib.h"
#include "c11_CockpitDisplayLib.h"
#include "c13_CockpitDisplayLib.h"
#include "c15_CockpitDisplayLib.h"
#include "c16_CockpitDisplayLib.h"
#include "c17_CockpitDisplayLib.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CockpitDisplayLibMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void CockpitDisplayLib_initializer(void)
{
}

void CockpitDisplayLib_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CockpitDisplayLib_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_CockpitDisplayLib_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_CockpitDisplayLib_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"CockpitDisplayLib")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3104501519U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4291157001U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1228195792U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(932205614U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 1:
            {
              extern void sf_c1_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c1_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 2:
            {
              extern void sf_c2_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c2_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 8:
            {
              extern void sf_c8_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c8_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 9:
            {
              extern void sf_c9_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c9_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 10:
            {
              extern void sf_c10_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c10_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 11:
            {
              extern void sf_c11_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c11_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 13:
            {
              extern void sf_c13_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c13_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 15:
            {
              extern void sf_c15_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c15_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 16:
            {
              extern void sf_c16_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c16_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           case 17:
            {
              extern void sf_c17_CockpitDisplayLib_get_check_sum(mxArray *plhs[]);
              sf_c17_CockpitDisplayLib_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CockpitDisplayLib_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "y4KOtv65EZLx6U726DZS3D") == 0) {
          extern mxArray *sf_c1_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "5jAOQk4juO8aVBnsmzFU9F") == 0) {
          extern mxArray *sf_c2_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c2_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "VeOZWBYCQVOfFOQUR4GAlG") == 0) {
          extern mxArray *sf_c8_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c8_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "PjiImBEceHz4RH0xs85hnB") == 0) {
          extern mxArray *sf_c9_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c9_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "gZJsOEUOtbqEgiMD5K1cCD") == 0) {
          extern mxArray *sf_c10_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c10_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "H3iaA84uWqbTxdRmgqMByD") == 0) {
          extern mxArray *sf_c11_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c11_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "xE9GjW6QHKjATtJnr1iNhH") == 0) {
          extern mxArray *sf_c13_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c13_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "NLmHEqAWVEIWwhxL91q5QE") == 0) {
          extern mxArray *sf_c15_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c15_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "U0DCBEjgkCVZMuNZ5m9noH") == 0) {
          extern mxArray *sf_c16_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c16_CockpitDisplayLib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "drqumRl6SabqoYXYurJV4") == 0) {
          extern mxArray *sf_c17_CockpitDisplayLib_get_autoinheritance_info(void);
          plhs[0] = sf_c17_CockpitDisplayLib_get_autoinheritance_info();
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

unsigned int sf_CockpitDisplayLib_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_CockpitDisplayLib_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_CockpitDisplayLib_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_CockpitDisplayLib_get_eml_resolved_functions_info();
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

unsigned int sf_CockpitDisplayLib_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "xYNtpxs0GdL4m1YB5d4fWE") == 0) {
          extern mxArray *sf_c1_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c1_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "jIlAUuERun6KqKxBRRYll") == 0) {
          extern mxArray *sf_c2_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c2_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "31OuPFq24rIt3N0fUFKCLC") == 0) {
          extern mxArray *sf_c8_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c8_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "4jLo8WmUvbXQ3AUIW2WggH") == 0) {
          extern mxArray *sf_c9_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c9_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "myeDCvYTHGgXDZUtF9JxqF") == 0) {
          extern mxArray *sf_c10_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c10_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "uMC4rCRI0p7zfPKoXb5HBH") == 0) {
          extern mxArray *sf_c11_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c11_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "iPTVwMnyHmZh7eYYogrSEF") == 0) {
          extern mxArray *sf_c13_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c13_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "AbIUuPVKjGrpISYpajZ2R") == 0) {
          extern mxArray *sf_c15_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c15_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "c4SvDWIK6I6oUDbOkTJD2F") == 0) {
          extern mxArray *sf_c16_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c16_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "mvMe3DCpbcbBaSqi2sy4a") == 0) {
          extern mxArray *sf_c17_CockpitDisplayLib_third_party_uses_info(void);
          plhs[0] = sf_c17_CockpitDisplayLib_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_CockpitDisplayLib_updateBuildInfo_args_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "xYNtpxs0GdL4m1YB5d4fWE") == 0) {
          extern mxArray *sf_c1_CockpitDisplayLib_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "jIlAUuERun6KqKxBRRYll") == 0) {
          extern mxArray *sf_c2_CockpitDisplayLib_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "31OuPFq24rIt3N0fUFKCLC") == 0) {
          extern mxArray *sf_c8_CockpitDisplayLib_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "4jLo8WmUvbXQ3AUIW2WggH") == 0) {
          extern mxArray *sf_c9_CockpitDisplayLib_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "myeDCvYTHGgXDZUtF9JxqF") == 0) {
          extern mxArray *sf_c10_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "uMC4rCRI0p7zfPKoXb5HBH") == 0) {
          extern mxArray *sf_c11_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "iPTVwMnyHmZh7eYYogrSEF") == 0) {
          extern mxArray *sf_c13_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c13_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "AbIUuPVKjGrpISYpajZ2R") == 0) {
          extern mxArray *sf_c15_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "c4SvDWIK6I6oUDbOkTJD2F") == 0) {
          extern mxArray *sf_c16_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c16_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "mvMe3DCpbcbBaSqi2sy4a") == 0) {
          extern mxArray *sf_c17_CockpitDisplayLib_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c17_CockpitDisplayLib_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void CockpitDisplayLib_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _CockpitDisplayLibMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "CockpitDisplayLib","sfun",1,10,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _CockpitDisplayLibMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _CockpitDisplayLibMachineNumber_,0);
}

void CockpitDisplayLib_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CockpitDisplayLib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CockpitDisplayLib", "DisplayModel");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CockpitDisplayLib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
