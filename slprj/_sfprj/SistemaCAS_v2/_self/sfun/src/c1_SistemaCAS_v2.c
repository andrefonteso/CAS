/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SistemaCAS_v2_sfun.h"
#include "c1_SistemaCAS_v2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SistemaCAS_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[59] = { "f1", "f2", "cmetro", "c",
  "lambda", "angulo", "d", "de", "a", "ab1", "ab2", "ab3", "ab4", "ab5", "ab6",
  "ab7", "sp1", "sp2", "sp3", "sp4", "sp5", "sp6", "sp7", "nargin", "nargout",
  "sinal", "f", "rr", "T", "D", "S", "pH", "r", "L1", "L2", "ag2", "L3", "ag3",
  "L4", "ag4", "L5", "ag5", "L6", "L7", "sps", "sinal1", "atraso1", "sinal2",
  "atraso2", "sinal3", "atraso3", "sinal4", "atraso4", "sinal5", "atraso5",
  "sinal6", "atraso6", "sinal7", "atraso7" };

/* Function Declarations */
static void initialize_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void initialize_params_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct *
  chartInstance);
static void enable_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void disable_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_SistemaCAS_v2
  (SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_SistemaCAS_v2
  (SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static void set_sim_state_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void sf_gateway_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void initSimStructsc1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_atraso7, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static real_T c1_sqrt(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static void c1_eml_scalar_eg(SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static real_T c1_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  c1_a);
static real_T c1_b_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance,
  real_T c1_a);
static real_T c1_asin(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_b_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static real_T c1_log10(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  c1_x);
static void c1_c_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static real_T c1_c_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance,
  real_T c1_a, real_T c1_b);
static void c1_d_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_SistemaCAS_v2, const char_T
  *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      *c1_x);
static void c1_b_asin(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      *c1_x);
static void c1_b_log10(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  *c1_x);
static void init_dsm_address_info(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_SistemaCAS_v2 = 0U;
}

static void initialize_params_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_SistemaCAS_v2
  (SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_SistemaCAS_v2
  (SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_m_hoistedGlobal;
  real_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_n_hoistedGlobal;
  real_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  uint8_T c1_o_hoistedGlobal;
  uint8_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  real_T *c1_atraso1;
  real_T *c1_atraso2;
  real_T *c1_atraso3;
  real_T *c1_atraso4;
  real_T *c1_atraso5;
  real_T *c1_atraso6;
  real_T *c1_atraso7;
  real_T *c1_sinal1;
  real_T *c1_sinal2;
  real_T *c1_sinal3;
  real_T *c1_sinal4;
  real_T *c1_sinal5;
  real_T *c1_sinal6;
  real_T *c1_sinal7;
  c1_atraso7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_sinal7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_atraso6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_sinal6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_sinal5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_sinal4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_sinal3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_sinal2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_sinal1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(15, 1), false);
  c1_hoistedGlobal = *c1_atraso1;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_atraso2;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_atraso3;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_atraso4;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_atraso5;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_atraso6;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_atraso7;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = *c1_sinal1;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = *c1_sinal2;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = *c1_sinal3;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = *c1_sinal4;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = *c1_sinal5;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = *c1_sinal6;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  c1_n_hoistedGlobal = *c1_sinal7;
  c1_n_u = c1_n_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_o_y);
  c1_o_hoistedGlobal = chartInstance->c1_is_active_c1_SistemaCAS_v2;
  c1_o_u = c1_o_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 14, c1_p_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_atraso1;
  real_T *c1_atraso2;
  real_T *c1_atraso3;
  real_T *c1_atraso4;
  real_T *c1_atraso5;
  real_T *c1_atraso6;
  real_T *c1_atraso7;
  real_T *c1_sinal1;
  real_T *c1_sinal2;
  real_T *c1_sinal3;
  real_T *c1_sinal4;
  real_T *c1_sinal5;
  real_T *c1_sinal6;
  real_T *c1_sinal7;
  c1_atraso7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_sinal7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_atraso6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_sinal6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_sinal5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_sinal4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_sinal3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_sinal2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_sinal1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *c1_atraso1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "atraso1");
  *c1_atraso2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "atraso2");
  *c1_atraso3 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "atraso3");
  *c1_atraso4 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "atraso4");
  *c1_atraso5 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "atraso5");
  *c1_atraso6 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 5)), "atraso6");
  *c1_atraso7 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "atraso7");
  *c1_sinal1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    7)), "sinal1");
  *c1_sinal2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    8)), "sinal2");
  *c1_sinal3 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    9)), "sinal3");
  *c1_sinal4 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    10)), "sinal4");
  *c1_sinal5 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    11)), "sinal5");
  *c1_sinal6 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    12)), "sinal6");
  *c1_sinal7 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    13)), "sinal7");
  chartInstance->c1_is_active_c1_SistemaCAS_v2 = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 14)),
     "is_active_c1_SistemaCAS_v2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_SistemaCAS_v2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  real_T *c1_sinal;
  real_T *c1_f;
  real_T *c1_rr;
  real_T *c1_T;
  real_T *c1_D;
  real_T *c1_S;
  real_T *c1_pH;
  real_T *c1_r;
  real_T *c1_sinal1;
  real_T *c1_L1;
  real_T *c1_L2;
  real_T *c1_ag2;
  real_T *c1_L3;
  real_T *c1_ag3;
  real_T *c1_L4;
  real_T *c1_ag4;
  real_T *c1_L5;
  real_T *c1_ag5;
  real_T *c1_L6;
  real_T *c1_L7;
  real_T *c1_sps;
  real_T *c1_atraso1;
  real_T *c1_sinal2;
  real_T *c1_atraso2;
  real_T *c1_sinal3;
  real_T *c1_atraso3;
  real_T *c1_sinal4;
  real_T *c1_atraso4;
  real_T *c1_sinal5;
  real_T *c1_atraso5;
  real_T *c1_sinal6;
  real_T *c1_atraso6;
  real_T *c1_sinal7;
  real_T *c1_atraso7;
  c1_atraso7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_sinal7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_atraso6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_sinal6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_sinal5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_sinal4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_sinal3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_sinal2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_sps = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c1_L7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_L6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_ag5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_L5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_ag4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_L4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_ag3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_L3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_ag2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_L2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_L1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_sinal1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_pH = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_D = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_rr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_sinal = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_sinal, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_f, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_rr, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_T, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_D, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_S, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_pH, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_r, 7U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_SistemaCAS_v2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SistemaCAS_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c1_sinal1, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_L1, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_L2, 10U);
  _SFD_DATA_RANGE_CHECK(*c1_ag2, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_L3, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_ag3, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_L4, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_ag4, 15U);
  _SFD_DATA_RANGE_CHECK(*c1_L5, 16U);
  _SFD_DATA_RANGE_CHECK(*c1_ag5, 17U);
  _SFD_DATA_RANGE_CHECK(*c1_L6, 18U);
  _SFD_DATA_RANGE_CHECK(*c1_L7, 19U);
  _SFD_DATA_RANGE_CHECK(*c1_sps, 20U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso1, 21U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal2, 22U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso2, 23U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal3, 24U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso3, 25U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal4, 26U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso4, 27U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal5, 28U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso5, 29U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal6, 30U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso6, 31U);
  _SFD_DATA_RANGE_CHECK(*c1_sinal7, 32U);
  _SFD_DATA_RANGE_CHECK(*c1_atraso7, 33U);
}

static void c1_chartstep_c1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_hoistedGlobal;
  real_T c1_j_hoistedGlobal;
  real_T c1_k_hoistedGlobal;
  real_T c1_l_hoistedGlobal;
  real_T c1_m_hoistedGlobal;
  real_T c1_n_hoistedGlobal;
  real_T c1_o_hoistedGlobal;
  real_T c1_p_hoistedGlobal;
  real_T c1_q_hoistedGlobal;
  real_T c1_r_hoistedGlobal;
  real_T c1_s_hoistedGlobal;
  real_T c1_t_hoistedGlobal;
  real_T c1_sinal;
  real_T c1_f;
  real_T c1_rr;
  real_T c1_T;
  real_T c1_D;
  real_T c1_S;
  real_T c1_pH;
  real_T c1_r;
  real_T c1_L1;
  real_T c1_L2;
  real_T c1_ag2;
  real_T c1_L3;
  real_T c1_ag3;
  real_T c1_L4;
  real_T c1_ag4;
  real_T c1_L5;
  real_T c1_ag5;
  real_T c1_L6;
  real_T c1_L7;
  real_T c1_sps;
  uint32_T c1_debug_family_var_map[59];
  real_T c1_f1;
  real_T c1_f2;
  real_T c1_cmetro;
  real_T c1_c;
  real_T c1_lambda;
  real_T c1_angulo;
  real_T c1_d;
  real_T c1_de;
  real_T c1_a;
  real_T c1_ab1;
  real_T c1_ab2;
  real_T c1_ab3;
  real_T c1_ab4;
  real_T c1_ab5;
  real_T c1_ab6;
  real_T c1_ab7;
  real_T c1_sp1;
  real_T c1_sp2;
  real_T c1_sp3;
  real_T c1_sp4;
  real_T c1_sp5;
  real_T c1_sp6;
  real_T c1_sp7;
  real_T c1_nargin = 20.0;
  real_T c1_nargout = 14.0;
  real_T c1_sinal1;
  real_T c1_atraso1;
  real_T c1_sinal2;
  real_T c1_atraso2;
  real_T c1_sinal3;
  real_T c1_atraso3;
  real_T c1_sinal4;
  real_T c1_atraso4;
  real_T c1_sinal5;
  real_T c1_atraso5;
  real_T c1_sinal6;
  real_T c1_atraso6;
  real_T c1_sinal7;
  real_T c1_atraso7;
  real_T c1_A;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_b_A;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_d0;
  real_T c1_c_A;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_c_y;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_d_A;
  real_T c1_B;
  real_T c1_n_x;
  real_T c1_d_y;
  real_T c1_o_x;
  real_T c1_e_y;
  real_T c1_p_x;
  real_T c1_f_y;
  real_T c1_e_A;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_g_y;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_f_A;
  real_T c1_b_B;
  real_T c1_v_x;
  real_T c1_h_y;
  real_T c1_w_x;
  real_T c1_i_y;
  real_T c1_x_x;
  real_T c1_j_y;
  real_T c1_k_y;
  real_T c1_g_A;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_bb_x;
  real_T c1_l_y;
  real_T c1_h_A;
  real_T c1_cb_x;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_m_y;
  real_T c1_i_A;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_hb_x;
  real_T c1_n_y;
  real_T c1_ib_x;
  real_T c1_jb_x;
  real_T c1_j_A;
  real_T c1_c_B;
  real_T c1_kb_x;
  real_T c1_o_y;
  real_T c1_lb_x;
  real_T c1_p_y;
  real_T c1_mb_x;
  real_T c1_q_y;
  real_T c1_r_y;
  real_T c1_k_A;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_pb_x;
  real_T c1_s_y;
  real_T c1_l_A;
  real_T c1_qb_x;
  real_T c1_rb_x;
  real_T c1_sb_x;
  real_T c1_t_y;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_m_A;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_xb_x;
  real_T c1_u_y;
  real_T c1_n_A;
  real_T c1_yb_x;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_v_y;
  real_T c1_o_A;
  real_T c1_cc_x;
  real_T c1_dc_x;
  real_T c1_ec_x;
  real_T c1_w_y;
  real_T c1_p_A;
  real_T c1_fc_x;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_x_y;
  real_T c1_q_A;
  real_T c1_ic_x;
  real_T c1_jc_x;
  real_T c1_kc_x;
  real_T c1_y_y;
  real_T c1_r_A;
  real_T c1_lc_x;
  real_T c1_mc_x;
  real_T c1_nc_x;
  real_T c1_ab_y;
  real_T c1_s_A;
  real_T c1_oc_x;
  real_T c1_pc_x;
  real_T c1_qc_x;
  real_T c1_bb_y;
  real_T c1_t_A;
  real_T c1_d_B;
  real_T c1_rc_x;
  real_T c1_cb_y;
  real_T c1_sc_x;
  real_T c1_db_y;
  real_T c1_tc_x;
  real_T c1_eb_y;
  real_T c1_fb_y;
  real_T c1_u_A;
  real_T c1_e_B;
  real_T c1_uc_x;
  real_T c1_gb_y;
  real_T c1_vc_x;
  real_T c1_hb_y;
  real_T c1_wc_x;
  real_T c1_ib_y;
  real_T c1_jb_y;
  real_T c1_d1;
  real_T c1_v_A;
  real_T c1_f_B;
  real_T c1_xc_x;
  real_T c1_kb_y;
  real_T c1_yc_x;
  real_T c1_lb_y;
  real_T c1_ad_x;
  real_T c1_mb_y;
  real_T c1_nb_y;
  real_T c1_d2;
  real_T c1_w_A;
  real_T c1_g_B;
  real_T c1_bd_x;
  real_T c1_ob_y;
  real_T c1_cd_x;
  real_T c1_pb_y;
  real_T c1_dd_x;
  real_T c1_qb_y;
  real_T c1_rb_y;
  real_T c1_d3;
  real_T c1_x_A;
  real_T c1_h_B;
  real_T c1_ed_x;
  real_T c1_sb_y;
  real_T c1_fd_x;
  real_T c1_tb_y;
  real_T c1_gd_x;
  real_T c1_ub_y;
  real_T c1_vb_y;
  real_T c1_d4;
  real_T c1_y_A;
  real_T c1_i_B;
  real_T c1_hd_x;
  real_T c1_wb_y;
  real_T c1_id_x;
  real_T c1_xb_y;
  real_T c1_jd_x;
  real_T c1_yb_y;
  real_T c1_ac_y;
  real_T c1_d5;
  real_T c1_ab_A;
  real_T c1_j_B;
  real_T c1_kd_x;
  real_T c1_bc_y;
  real_T c1_ld_x;
  real_T c1_cc_y;
  real_T c1_md_x;
  real_T c1_dc_y;
  real_T c1_ec_y;
  real_T c1_d6;
  real_T c1_bb_A;
  real_T c1_k_B;
  real_T c1_nd_x;
  real_T c1_fc_y;
  real_T c1_od_x;
  real_T c1_gc_y;
  real_T c1_pd_x;
  real_T c1_hc_y;
  real_T c1_ic_y;
  real_T c1_d7;
  real_T c1_cb_A;
  real_T c1_qd_x;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_jc_y;
  real_T c1_db_A;
  real_T c1_l_B;
  real_T c1_td_x;
  real_T c1_kc_y;
  real_T c1_ud_x;
  real_T c1_lc_y;
  real_T c1_vd_x;
  real_T c1_mc_y;
  real_T c1_nc_y;
  real_T c1_eb_A;
  real_T c1_wd_x;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_oc_y;
  real_T c1_fb_A;
  real_T c1_m_B;
  real_T c1_ae_x;
  real_T c1_pc_y;
  real_T c1_be_x;
  real_T c1_qc_y;
  real_T c1_ce_x;
  real_T c1_rc_y;
  real_T c1_sc_y;
  real_T c1_gb_A;
  real_T c1_de_x;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_tc_y;
  real_T c1_hb_A;
  real_T c1_n_B;
  real_T c1_ge_x;
  real_T c1_uc_y;
  real_T c1_he_x;
  real_T c1_vc_y;
  real_T c1_ie_x;
  real_T c1_wc_y;
  real_T c1_xc_y;
  real_T c1_ib_A;
  real_T c1_je_x;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_yc_y;
  real_T c1_jb_A;
  real_T c1_o_B;
  real_T c1_me_x;
  real_T c1_ad_y;
  real_T c1_ne_x;
  real_T c1_bd_y;
  real_T c1_oe_x;
  real_T c1_cd_y;
  real_T c1_dd_y;
  real_T c1_kb_A;
  real_T c1_pe_x;
  real_T c1_qe_x;
  real_T c1_re_x;
  real_T c1_ed_y;
  real_T c1_lb_A;
  real_T c1_p_B;
  real_T c1_se_x;
  real_T c1_fd_y;
  real_T c1_te_x;
  real_T c1_gd_y;
  real_T c1_ue_x;
  real_T c1_hd_y;
  real_T c1_id_y;
  real_T c1_mb_A;
  real_T c1_ve_x;
  real_T c1_we_x;
  real_T c1_xe_x;
  real_T c1_jd_y;
  real_T c1_nb_A;
  real_T c1_q_B;
  real_T c1_ye_x;
  real_T c1_kd_y;
  real_T c1_af_x;
  real_T c1_ld_y;
  real_T c1_bf_x;
  real_T c1_md_y;
  real_T c1_nd_y;
  real_T c1_ob_A;
  real_T c1_cf_x;
  real_T c1_df_x;
  real_T c1_ef_x;
  real_T c1_od_y;
  real_T c1_pb_A;
  real_T c1_r_B;
  real_T c1_ff_x;
  real_T c1_pd_y;
  real_T c1_gf_x;
  real_T c1_qd_y;
  real_T c1_hf_x;
  real_T c1_rd_y;
  real_T c1_sd_y;
  real_T c1_qb_A;
  real_T c1_s_B;
  real_T c1_if_x;
  real_T c1_td_y;
  real_T c1_jf_x;
  real_T c1_ud_y;
  real_T c1_kf_x;
  real_T c1_vd_y;
  real_T *c1_b_atraso7;
  real_T *c1_b_sinal7;
  real_T *c1_b_atraso6;
  real_T *c1_b_sinal6;
  real_T *c1_b_atraso5;
  real_T *c1_b_sinal5;
  real_T *c1_b_atraso4;
  real_T *c1_b_sinal4;
  real_T *c1_b_atraso3;
  real_T *c1_b_sinal3;
  real_T *c1_b_atraso2;
  real_T *c1_b_sinal2;
  real_T *c1_b_atraso1;
  real_T *c1_b_sinal1;
  real_T *c1_b_sps;
  real_T *c1_b_L7;
  real_T *c1_b_L6;
  real_T *c1_b_ag5;
  real_T *c1_b_L5;
  real_T *c1_b_ag4;
  real_T *c1_b_L4;
  real_T *c1_b_ag3;
  real_T *c1_b_L3;
  real_T *c1_b_ag2;
  real_T *c1_b_L2;
  real_T *c1_b_L1;
  real_T *c1_b_r;
  real_T *c1_b_pH;
  real_T *c1_b_S;
  real_T *c1_b_D;
  real_T *c1_b_T;
  real_T *c1_b_rr;
  real_T *c1_b_f;
  real_T *c1_b_sinal;
  c1_b_atraso7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c1_b_sinal7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c1_b_atraso6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c1_b_sinal6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c1_b_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c1_b_sinal5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_b_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_b_sinal4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_b_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_b_sinal3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_sinal2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_sps = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
  c1_b_L7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
  c1_b_L6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
  c1_b_ag5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
  c1_b_L5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
  c1_b_ag4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c1_b_L4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c1_b_ag3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c1_b_L3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_b_ag2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_b_L2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_L1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_sinal1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_pH = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_D = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_rr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_sinal = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_sinal;
  c1_b_hoistedGlobal = *c1_b_f;
  c1_c_hoistedGlobal = *c1_b_rr;
  c1_d_hoistedGlobal = *c1_b_T;
  c1_e_hoistedGlobal = *c1_b_D;
  c1_f_hoistedGlobal = *c1_b_S;
  c1_g_hoistedGlobal = *c1_b_pH;
  c1_h_hoistedGlobal = *c1_b_r;
  c1_i_hoistedGlobal = *c1_b_L1;
  c1_j_hoistedGlobal = *c1_b_L2;
  c1_k_hoistedGlobal = *c1_b_ag2;
  c1_l_hoistedGlobal = *c1_b_L3;
  c1_m_hoistedGlobal = *c1_b_ag3;
  c1_n_hoistedGlobal = *c1_b_L4;
  c1_o_hoistedGlobal = *c1_b_ag4;
  c1_p_hoistedGlobal = *c1_b_L5;
  c1_q_hoistedGlobal = *c1_b_ag5;
  c1_r_hoistedGlobal = *c1_b_L6;
  c1_s_hoistedGlobal = *c1_b_L7;
  c1_t_hoistedGlobal = *c1_b_sps;
  c1_sinal = c1_hoistedGlobal;
  c1_f = c1_b_hoistedGlobal;
  c1_rr = c1_c_hoistedGlobal;
  c1_T = c1_d_hoistedGlobal;
  c1_D = c1_e_hoistedGlobal;
  c1_S = c1_f_hoistedGlobal;
  c1_pH = c1_g_hoistedGlobal;
  c1_r = c1_h_hoistedGlobal;
  c1_L1 = c1_i_hoistedGlobal;
  c1_L2 = c1_j_hoistedGlobal;
  c1_ag2 = c1_k_hoistedGlobal;
  c1_L3 = c1_l_hoistedGlobal;
  c1_ag3 = c1_m_hoistedGlobal;
  c1_L4 = c1_n_hoistedGlobal;
  c1_ag4 = c1_o_hoistedGlobal;
  c1_L5 = c1_p_hoistedGlobal;
  c1_ag5 = c1_q_hoistedGlobal;
  c1_L6 = c1_r_hoistedGlobal;
  c1_L7 = c1_s_hoistedGlobal;
  c1_sps = c1_t_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 59U, 59U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f1, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f2, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cmetro, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_lambda, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_angulo, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_de, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_a, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab1, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab2, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab3, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab4, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab5, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab6, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ab7, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp1, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp2, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp3, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp4, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp5, 20U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp6, 21U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sp7, 22U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 23U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_sinal, 25U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_f, 26U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_rr, 27U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_T, 28U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_D, 29U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_S, 30U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_pH, 31U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_r, 32U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L1, 33U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L2, 34U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ag2, 35U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L3, 36U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ag3, 37U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L4, 38U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ag4, 39U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L5, 40U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_ag5, 41U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L6, 42U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_L7, 43U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_sps, 44U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal1, 45U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso1, 46U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal2, 47U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso2, 48U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal3, 49U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso3, 50U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal4, 51U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso4, 52U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal5, 53U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso5, 54U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal6, 55U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso6, 56U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sinal7, 57U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_atraso7, 58U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_A = c1_S;
  c1_x = c1_A;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = c1_c_x / 35.0;
  c1_b_A = c1_T;
  c1_d_x = c1_b_A;
  c1_e_x = c1_d_x;
  c1_f_x = c1_e_x;
  c1_b_y = c1_f_x / 26.0;
  c1_g_x = c1_b_y;
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarExp(c1_h_x);
  c1_d0 = c1_y;
  c1_b_sqrt(chartInstance, &c1_d0);
  c1_f1 = 0.78 * c1_d0 * c1_h_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_c_A = c1_T;
  c1_i_x = c1_c_A;
  c1_j_x = c1_i_x;
  c1_k_x = c1_j_x;
  c1_c_y = c1_k_x / 17.0;
  c1_l_x = c1_c_y;
  c1_m_x = c1_l_x;
  c1_m_x = muDoubleScalarExp(c1_m_x);
  c1_f2 = 42.0 * c1_m_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_cmetro = (((((((1448.96 + 4.591 * c1_T) - 0.053040000000000004 * c1_mpower
                    (chartInstance, c1_T)) + 0.00023740000000000002 *
                   c1_b_mpower(chartInstance, c1_T)) + 1.34 * (c1_S - 35.0)) +
                 0.0163 * c1_D) + 1.6749999999999998E-7 * c1_mpower
                (chartInstance, c1_D)) + -0.010249999999999999 * c1_T * (c1_S -
    35.0)) - 7.139E-13 * c1_T * c1_b_mpower(chartInstance, c1_D);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_c = c1_cmetro * 100.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_d_A = c1_c;
  c1_B = c1_f * 1000.0;
  c1_n_x = c1_d_A;
  c1_d_y = c1_B;
  c1_o_x = c1_n_x;
  c1_e_y = c1_d_y;
  c1_p_x = c1_o_x;
  c1_f_y = c1_e_y;
  c1_lambda = c1_p_x / c1_f_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_angulo = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_d = 2.0 * c1_r;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  c1_de = 3.1415926535897931 * c1_mpower(chartInstance, c1_rr);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  c1_e_A = c1_pH - 8.0;
  c1_q_x = c1_e_A;
  c1_r_x = c1_q_x;
  c1_s_x = c1_r_x;
  c1_g_y = c1_s_x / 0.56;
  c1_t_x = c1_g_y;
  c1_u_x = c1_t_x;
  c1_u_x = muDoubleScalarExp(c1_u_x);
  c1_f_A = 0.106 * (c1_f1 * c1_mpower(chartInstance, c1_f)) * c1_u_x;
  c1_b_B = c1_mpower(chartInstance, c1_f1) + c1_mpower(chartInstance, c1_f);
  c1_v_x = c1_f_A;
  c1_h_y = c1_b_B;
  c1_w_x = c1_v_x;
  c1_i_y = c1_h_y;
  c1_x_x = c1_w_x;
  c1_j_y = c1_i_y;
  c1_k_y = c1_x_x / c1_j_y;
  c1_g_A = c1_T;
  c1_y_x = c1_g_A;
  c1_ab_x = c1_y_x;
  c1_bb_x = c1_ab_x;
  c1_l_y = c1_bb_x / 43.0;
  c1_h_A = c1_S;
  c1_cb_x = c1_h_A;
  c1_db_x = c1_cb_x;
  c1_eb_x = c1_db_x;
  c1_m_y = c1_eb_x / 45.0;
  c1_i_A = c1_D;
  c1_fb_x = c1_i_A;
  c1_gb_x = c1_fb_x;
  c1_hb_x = c1_gb_x;
  c1_n_y = c1_hb_x / 6.0;
  c1_ib_x = -c1_n_y;
  c1_jb_x = c1_ib_x;
  c1_jb_x = muDoubleScalarExp(c1_jb_x);
  c1_j_A = 0.52 * (1.0 + c1_l_y) * c1_m_y * (c1_f2 * c1_mpower(chartInstance,
    c1_f)) * c1_jb_x;
  c1_c_B = c1_mpower(chartInstance, c1_f2) + c1_mpower(chartInstance, c1_f);
  c1_kb_x = c1_j_A;
  c1_o_y = c1_c_B;
  c1_lb_x = c1_kb_x;
  c1_p_y = c1_o_y;
  c1_mb_x = c1_lb_x;
  c1_q_y = c1_p_y;
  c1_r_y = c1_mb_x / c1_q_y;
  c1_k_A = c1_T;
  c1_nb_x = c1_k_A;
  c1_ob_x = c1_nb_x;
  c1_pb_x = c1_ob_x;
  c1_s_y = c1_pb_x / 27.0;
  c1_l_A = c1_D;
  c1_qb_x = c1_l_A;
  c1_rb_x = c1_qb_x;
  c1_sb_x = c1_rb_x;
  c1_t_y = c1_sb_x / 17.0;
  c1_tb_x = -(c1_s_y + c1_t_y);
  c1_ub_x = c1_tb_x;
  c1_ub_x = muDoubleScalarExp(c1_ub_x);
  c1_a = (c1_k_y + c1_r_y) + 0.00049 * c1_mpower(chartInstance, c1_f) * c1_ub_x;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  c1_m_A = c1_L1;
  c1_vb_x = c1_m_A;
  c1_wb_x = c1_vb_x;
  c1_xb_x = c1_wb_x;
  c1_u_y = c1_xb_x / 100000.0;
  c1_ab1 = c1_a * c1_u_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_n_A = c1_L2;
  c1_yb_x = c1_n_A;
  c1_ac_x = c1_yb_x;
  c1_bc_x = c1_ac_x;
  c1_v_y = c1_bc_x / 100000.0;
  c1_ab2 = c1_a * c1_v_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_o_A = c1_L3;
  c1_cc_x = c1_o_A;
  c1_dc_x = c1_cc_x;
  c1_ec_x = c1_dc_x;
  c1_w_y = c1_ec_x / 100000.0;
  c1_ab3 = c1_a * c1_w_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_p_A = c1_L4;
  c1_fc_x = c1_p_A;
  c1_gc_x = c1_fc_x;
  c1_hc_x = c1_gc_x;
  c1_x_y = c1_hc_x / 100000.0;
  c1_ab4 = c1_a * c1_x_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  c1_q_A = c1_L5;
  c1_ic_x = c1_q_A;
  c1_jc_x = c1_ic_x;
  c1_kc_x = c1_jc_x;
  c1_y_y = c1_kc_x / 100000.0;
  c1_ab5 = c1_a * c1_y_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  c1_r_A = c1_L6;
  c1_lc_x = c1_r_A;
  c1_mc_x = c1_lc_x;
  c1_nc_x = c1_mc_x;
  c1_ab_y = c1_nc_x / 100000.0;
  c1_ab6 = c1_a * c1_ab_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_s_A = c1_L7;
  c1_oc_x = c1_s_A;
  c1_pc_x = c1_oc_x;
  c1_qc_x = c1_pc_x;
  c1_bb_y = c1_qc_x / 100000.0;
  c1_ab7 = c1_a * c1_bb_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  if (CV_EML_IF(0, 1, 0, c1_r < c1_lambda)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
    c1_angulo = 1.5707963267948966;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
  if (CV_EML_IF(0, 1, 1, c1_r > c1_lambda)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
    c1_t_A = c1_lambda;
    c1_d_B = c1_d;
    c1_rc_x = c1_t_A;
    c1_cb_y = c1_d_B;
    c1_sc_x = c1_rc_x;
    c1_db_y = c1_cb_y;
    c1_tc_x = c1_sc_x;
    c1_eb_y = c1_db_y;
    c1_fb_y = c1_tc_x / c1_eb_y;
    c1_angulo = c1_fb_y;
    c1_b_asin(chartInstance, &c1_angulo);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
  c1_u_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L1) + c1_de;
  c1_e_B = c1_de;
  c1_uc_x = c1_u_A;
  c1_gb_y = c1_e_B;
  c1_vc_x = c1_uc_x;
  c1_hb_y = c1_gb_y;
  c1_wc_x = c1_vc_x;
  c1_ib_y = c1_hb_y;
  c1_jb_y = c1_wc_x / c1_ib_y;
  c1_d1 = c1_jb_y;
  c1_b_log10(chartInstance, &c1_d1);
  c1_sp1 = 10.0 * c1_d1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  c1_v_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L2) + c1_de;
  c1_f_B = c1_de;
  c1_xc_x = c1_v_A;
  c1_kb_y = c1_f_B;
  c1_yc_x = c1_xc_x;
  c1_lb_y = c1_kb_y;
  c1_ad_x = c1_yc_x;
  c1_mb_y = c1_lb_y;
  c1_nb_y = c1_ad_x / c1_mb_y;
  c1_d2 = c1_nb_y;
  c1_b_log10(chartInstance, &c1_d2);
  c1_sp2 = 10.0 * c1_d2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  c1_w_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L3) + c1_de;
  c1_g_B = c1_de;
  c1_bd_x = c1_w_A;
  c1_ob_y = c1_g_B;
  c1_cd_x = c1_bd_x;
  c1_pb_y = c1_ob_y;
  c1_dd_x = c1_cd_x;
  c1_qb_y = c1_pb_y;
  c1_rb_y = c1_dd_x / c1_qb_y;
  c1_d3 = c1_rb_y;
  c1_b_log10(chartInstance, &c1_d3);
  c1_sp3 = 10.0 * c1_d3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
  c1_x_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L4) + c1_de;
  c1_h_B = c1_de;
  c1_ed_x = c1_x_A;
  c1_sb_y = c1_h_B;
  c1_fd_x = c1_ed_x;
  c1_tb_y = c1_sb_y;
  c1_gd_x = c1_fd_x;
  c1_ub_y = c1_tb_y;
  c1_vb_y = c1_gd_x / c1_ub_y;
  c1_d4 = c1_vb_y;
  c1_b_log10(chartInstance, &c1_d4);
  c1_sp4 = 10.0 * c1_d4;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
  c1_y_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L5) + c1_de;
  c1_i_B = c1_de;
  c1_hd_x = c1_y_A;
  c1_wb_y = c1_i_B;
  c1_id_x = c1_hd_x;
  c1_xb_y = c1_wb_y;
  c1_jd_x = c1_id_x;
  c1_yb_y = c1_xb_y;
  c1_ac_y = c1_jd_x / c1_yb_y;
  c1_d5 = c1_ac_y;
  c1_b_log10(chartInstance, &c1_d5);
  c1_sp5 = 10.0 * c1_d5;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
  c1_ab_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L6) + c1_de;
  c1_j_B = c1_de;
  c1_kd_x = c1_ab_A;
  c1_bc_y = c1_j_B;
  c1_ld_x = c1_kd_x;
  c1_cc_y = c1_bc_y;
  c1_md_x = c1_ld_x;
  c1_dc_y = c1_cc_y;
  c1_ec_y = c1_md_x / c1_dc_y;
  c1_d6 = c1_ec_y;
  c1_b_log10(chartInstance, &c1_d6);
  c1_sp6 = 10.0 * c1_d6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
  c1_bb_A = 2.0 * c1_angulo * c1_mpower(chartInstance, c1_L7) + c1_de;
  c1_k_B = c1_de;
  c1_nd_x = c1_bb_A;
  c1_fc_y = c1_k_B;
  c1_od_x = c1_nd_x;
  c1_gc_y = c1_fc_y;
  c1_pd_x = c1_od_x;
  c1_hc_y = c1_gc_y;
  c1_ic_y = c1_pd_x / c1_hc_y;
  c1_d7 = c1_ic_y;
  c1_b_log10(chartInstance, &c1_d7);
  c1_sp7 = 10.0 * c1_d7;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
  c1_sinal1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
  c1_sinal2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 64);
  c1_sinal3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 65);
  c1_sinal4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 66);
  c1_sinal5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 67);
  c1_sinal6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 68);
  c1_sinal7 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
  c1_atraso1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
  c1_atraso2 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
  c1_atraso3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 73);
  c1_atraso4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
  c1_atraso5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 75);
  c1_atraso6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 76);
  c1_atraso7 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 78);
  c1_cb_A = -(c1_ab1 + c1_sp1);
  c1_qd_x = c1_cb_A;
  c1_rd_x = c1_qd_x;
  c1_sd_x = c1_rd_x;
  c1_jc_y = c1_sd_x / 10.0;
  c1_sinal1 = c1_c_mpower(chartInstance, 10.0, c1_jc_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 79);
  c1_db_A = c1_L1;
  c1_l_B = c1_c;
  c1_td_x = c1_db_A;
  c1_kc_y = c1_l_B;
  c1_ud_x = c1_td_x;
  c1_lc_y = c1_kc_y;
  c1_vd_x = c1_ud_x;
  c1_mc_y = c1_lc_y;
  c1_nc_y = c1_vd_x / c1_mc_y;
  c1_atraso1 = c1_nc_y * c1_sps;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 82);
  c1_eb_A = -(c1_ab2 + c1_sp2);
  c1_wd_x = c1_eb_A;
  c1_xd_x = c1_wd_x;
  c1_yd_x = c1_xd_x;
  c1_oc_y = c1_yd_x / 10.0;
  c1_sinal2 = c1_c_mpower(chartInstance, 10.0, c1_oc_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 83);
  c1_fb_A = c1_L2;
  c1_m_B = c1_c;
  c1_ae_x = c1_fb_A;
  c1_pc_y = c1_m_B;
  c1_be_x = c1_ae_x;
  c1_qc_y = c1_pc_y;
  c1_ce_x = c1_be_x;
  c1_rc_y = c1_qc_y;
  c1_sc_y = c1_ce_x / c1_rc_y;
  c1_atraso2 = c1_sc_y * c1_sps - c1_atraso1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 86);
  c1_gb_A = -(c1_ab3 + c1_sp3);
  c1_de_x = c1_gb_A;
  c1_ee_x = c1_de_x;
  c1_fe_x = c1_ee_x;
  c1_tc_y = c1_fe_x / 10.0;
  c1_sinal3 = c1_c_mpower(chartInstance, 10.0, c1_tc_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 87);
  c1_hb_A = c1_L3;
  c1_n_B = c1_c;
  c1_ge_x = c1_hb_A;
  c1_uc_y = c1_n_B;
  c1_he_x = c1_ge_x;
  c1_vc_y = c1_uc_y;
  c1_ie_x = c1_he_x;
  c1_wc_y = c1_vc_y;
  c1_xc_y = c1_ie_x / c1_wc_y;
  c1_atraso3 = c1_xc_y * c1_sps - c1_atraso1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 90);
  c1_ib_A = -(c1_ab4 + c1_sp4);
  c1_je_x = c1_ib_A;
  c1_ke_x = c1_je_x;
  c1_le_x = c1_ke_x;
  c1_yc_y = c1_le_x / 10.0;
  c1_sinal4 = c1_c_mpower(chartInstance, 10.0, c1_yc_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 91);
  c1_jb_A = c1_L4;
  c1_o_B = c1_c;
  c1_me_x = c1_jb_A;
  c1_ad_y = c1_o_B;
  c1_ne_x = c1_me_x;
  c1_bd_y = c1_ad_y;
  c1_oe_x = c1_ne_x;
  c1_cd_y = c1_bd_y;
  c1_dd_y = c1_oe_x / c1_cd_y;
  c1_atraso4 = c1_dd_y * c1_sps - c1_atraso1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 94);
  c1_kb_A = -(c1_ab5 + c1_sp5);
  c1_pe_x = c1_kb_A;
  c1_qe_x = c1_pe_x;
  c1_re_x = c1_qe_x;
  c1_ed_y = c1_re_x / 10.0;
  c1_sinal5 = c1_c_mpower(chartInstance, 10.0, c1_ed_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 95);
  c1_lb_A = c1_L5;
  c1_p_B = c1_c;
  c1_se_x = c1_lb_A;
  c1_fd_y = c1_p_B;
  c1_te_x = c1_se_x;
  c1_gd_y = c1_fd_y;
  c1_ue_x = c1_te_x;
  c1_hd_y = c1_gd_y;
  c1_id_y = c1_ue_x / c1_hd_y;
  c1_atraso5 = c1_id_y * c1_sps - c1_atraso1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 97);
  if (CV_EML_IF(0, 1, 2, c1_L6 > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 98);
    c1_mb_A = -(c1_ab6 + c1_sp6);
    c1_ve_x = c1_mb_A;
    c1_we_x = c1_ve_x;
    c1_xe_x = c1_we_x;
    c1_jd_y = c1_xe_x / 10.0;
    c1_sinal6 = c1_c_mpower(chartInstance, 10.0, c1_jd_y);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 99);
    c1_nb_A = c1_L6;
    c1_q_B = c1_c;
    c1_ye_x = c1_nb_A;
    c1_kd_y = c1_q_B;
    c1_af_x = c1_ye_x;
    c1_ld_y = c1_kd_y;
    c1_bf_x = c1_af_x;
    c1_md_y = c1_ld_y;
    c1_nd_y = c1_bf_x / c1_md_y;
    c1_atraso6 = c1_nd_y * c1_sps - c1_atraso1;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 101);
  if (CV_EML_IF(0, 1, 3, c1_L7 > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 102);
    c1_ob_A = -(c1_ab7 + c1_sp7);
    c1_cf_x = c1_ob_A;
    c1_df_x = c1_cf_x;
    c1_ef_x = c1_df_x;
    c1_od_y = c1_ef_x / 10.0;
    c1_sinal7 = c1_c_mpower(chartInstance, 10.0, c1_od_y);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 103);
    c1_pb_A = c1_L7;
    c1_r_B = c1_c;
    c1_ff_x = c1_pb_A;
    c1_pd_y = c1_r_B;
    c1_gf_x = c1_ff_x;
    c1_qd_y = c1_pd_y;
    c1_hf_x = c1_gf_x;
    c1_rd_y = c1_qd_y;
    c1_sd_y = c1_hf_x / c1_rd_y;
    c1_atraso7 = c1_sd_y * c1_sps - c1_atraso1;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 106);
  c1_qb_A = c1_atraso1;
  c1_s_B = c1_sps;
  c1_if_x = c1_qb_A;
  c1_td_y = c1_s_B;
  c1_jf_x = c1_if_x;
  c1_ud_y = c1_td_y;
  c1_kf_x = c1_jf_x;
  c1_vd_y = c1_ud_y;
  c1_atraso1 = c1_kf_x / c1_vd_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -106);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_sinal1 = c1_sinal1;
  *c1_b_atraso1 = c1_atraso1;
  *c1_b_sinal2 = c1_sinal2;
  *c1_b_atraso2 = c1_atraso2;
  *c1_b_sinal3 = c1_sinal3;
  *c1_b_atraso3 = c1_atraso3;
  *c1_b_sinal4 = c1_sinal4;
  *c1_b_atraso4 = c1_atraso4;
  *c1_b_sinal5 = c1_sinal5;
  *c1_b_atraso5 = c1_atraso5;
  *c1_b_sinal6 = c1_sinal6;
  *c1_b_atraso6 = c1_atraso6;
  *c1_b_sinal7 = c1_sinal7;
  *c1_b_atraso7 = c1_atraso7;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_SistemaCAS_v2(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_atraso7, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_atraso7), &c1_thisId);
  sf_mex_destroy(&c1_atraso7);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d8;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d8, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d8;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_atraso7;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)chartInstanceVoid;
  c1_atraso7 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_atraso7), &c1_thisId);
  sf_mex_destroy(&c1_atraso7);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_SistemaCAS_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 36, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  const mxArray *c1_rhs23 = NULL;
  const mxArray *c1_lhs23 = NULL;
  const mxArray *c1_rhs24 = NULL;
  const mxArray *c1_lhs24 = NULL;
  const mxArray *c1_rhs25 = NULL;
  const mxArray *c1_lhs25 = NULL;
  const mxArray *c1_rhs26 = NULL;
  const mxArray *c1_lhs26 = NULL;
  const mxArray *c1_rhs27 = NULL;
  const mxArray *c1_lhs27 = NULL;
  const mxArray *c1_rhs28 = NULL;
  const mxArray *c1_lhs28 = NULL;
  const mxArray *c1_rhs29 = NULL;
  const mxArray *c1_lhs29 = NULL;
  const mxArray *c1_rhs30 = NULL;
  const mxArray *c1_lhs30 = NULL;
  const mxArray *c1_rhs31 = NULL;
  const mxArray *c1_lhs31 = NULL;
  const mxArray *c1_rhs32 = NULL;
  const mxArray *c1_lhs32 = NULL;
  const mxArray *c1_rhs33 = NULL;
  const mxArray *c1_lhs33 = NULL;
  const mxArray *c1_rhs34 = NULL;
  const mxArray *c1_lhs34 = NULL;
  const mxArray *c1_rhs35 = NULL;
  const mxArray *c1_lhs35 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("sqrt"), "name", "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286825938U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("exp"), "name", "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837580U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_exp"), "name",
                  "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1301335664U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mpower"), "name", "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717478U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("ismatrix"), "name", "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1331308458U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("power"), "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("floor"), "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c1_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c1_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("asin"), "name", "name", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837570U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c1_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c1_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_asin"), "name",
                  "name", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837576U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c1_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("log10"), "name", "name", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837582U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c1_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c1_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_log10"), "name",
                  "name", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286825928U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c1_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("realmax"), "name", "name", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1307658442U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c1_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_realmax"), "name", "name",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c1_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c1_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c1_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_error"), "name", "name",
                  35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c1_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs35), "lhs", "lhs",
                  35);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
  sf_mex_destroy(&c1_rhs23);
  sf_mex_destroy(&c1_lhs23);
  sf_mex_destroy(&c1_rhs24);
  sf_mex_destroy(&c1_lhs24);
  sf_mex_destroy(&c1_rhs25);
  sf_mex_destroy(&c1_lhs25);
  sf_mex_destroy(&c1_rhs26);
  sf_mex_destroy(&c1_lhs26);
  sf_mex_destroy(&c1_rhs27);
  sf_mex_destroy(&c1_lhs27);
  sf_mex_destroy(&c1_rhs28);
  sf_mex_destroy(&c1_lhs28);
  sf_mex_destroy(&c1_rhs29);
  sf_mex_destroy(&c1_lhs29);
  sf_mex_destroy(&c1_rhs30);
  sf_mex_destroy(&c1_lhs30);
  sf_mex_destroy(&c1_rhs31);
  sf_mex_destroy(&c1_lhs31);
  sf_mex_destroy(&c1_rhs32);
  sf_mex_destroy(&c1_lhs32);
  sf_mex_destroy(&c1_rhs33);
  sf_mex_destroy(&c1_lhs33);
  sf_mex_destroy(&c1_rhs34);
  sf_mex_destroy(&c1_lhs34);
  sf_mex_destroy(&c1_rhs35);
  sf_mex_destroy(&c1_lhs35);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static real_T c1_sqrt(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  int32_T c1_i0;
  static char_T c1_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i1;
  static char_T c1_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  for (c1_i0 = 0; c1_i0 < 30; c1_i0++) {
    c1_u[c1_i0] = c1_cv0[c1_i0];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    c1_b_u[c1_i1] = c1_cv1[c1_i1];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static void c1_eml_scalar_eg(SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  return c1_d_a * c1_d_a;
}

static real_T c1_b_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance,
  real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  real_T c1_ar;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  c1_ar = c1_d_a;
  return muDoubleScalarPower(c1_ar, 3.0);
}

static real_T c1_asin(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_asin(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_b_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  static char_T c1_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i3;
  static char_T c1_cv3[4] = { 'a', 's', 'i', 'n' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  for (c1_i2 = 0; c1_i2 < 30; c1_i2++) {
    c1_u[c1_i2] = c1_cv2[c1_i2];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    c1_b_u[c1_i3] = c1_cv3[c1_i3];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static real_T c1_log10(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_log10(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_c_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  int32_T c1_i4;
  static char_T c1_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i5;
  static char_T c1_cv5[5] = { 'l', 'o', 'g', '1', '0' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  for (c1_i4 = 0; c1_i4 < 30; c1_i4++) {
    c1_u[c1_i4] = c1_cv4[c1_i4];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c1_i5 = 0; c1_i5 < 5; c1_i5++) {
    c1_b_u[c1_i5] = c1_cv5[c1_i5];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c1_y, 14, c1_b_y));
}

static real_T c1_c_mpower(SFc1_SistemaCAS_v2InstanceStruct *chartInstance,
  real_T c1_a, real_T c1_b)
{
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_ar;
  real_T c1_br;
  c1_b_a = c1_a;
  c1_b_b = c1_b;
  c1_c_a = c1_b_a;
  c1_c_b = c1_b_b;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_bk = c1_c_b;
  if (c1_ak < 0.0) {
    c1_x = c1_bk;
    c1_b_x = c1_x;
    c1_b_x = muDoubleScalarFloor(c1_b_x);
    if (c1_b_x != c1_bk) {
      c1_d_eml_error(chartInstance);
    }
  }

  c1_d_a = c1_ak;
  c1_d_b = c1_bk;
  c1_eml_scalar_eg(chartInstance);
  c1_ar = c1_d_a;
  c1_br = c1_d_b;
  return muDoubleScalarPower(c1_ar, c1_br);
}

static void c1_d_eml_error(SFc1_SistemaCAS_v2InstanceStruct *chartInstance)
{
  int32_T c1_i6;
  static char_T c1_cv6[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  for (c1_i6 = 0; c1_i6 < 31; c1_i6++) {
    c1_u[c1_i6] = c1_cv6[c1_i6];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c1_y));
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i7;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i7, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i7;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_SistemaCAS_v2, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_SistemaCAS_v2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_SistemaCAS_v2);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sqrt(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      *c1_x)
{
  if (*c1_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void c1_b_asin(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
                      *c1_x)
{
  boolean_T guard1 = false;
  guard1 = false;
  if (*c1_x < -1.0) {
    guard1 = true;
  } else {
    if (1.0 < *c1_x) {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c1_b_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarAsin(*c1_x);
}

static void c1_b_log10(SFc1_SistemaCAS_v2InstanceStruct *chartInstance, real_T
  *c1_x)
{
  if (*c1_x < 0.0) {
    c1_c_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarLog10(*c1_x);
}

static void init_dsm_address_info(SFc1_SistemaCAS_v2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_SistemaCAS_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1144457784U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3126119438U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2484873121U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1918627648U);
}

mxArray *sf_c1_SistemaCAS_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("K5iRwnJrFlervWHKVporOD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,20,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_SistemaCAS_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_SistemaCAS_v2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_SistemaCAS_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[24],T\"atraso1\",},{M[1],M[26],T\"atraso2\",},{M[1],M[28],T\"atraso3\",},{M[1],M[30],T\"atraso4\",},{M[1],M[32],T\"atraso5\",},{M[1],M[34],T\"atraso6\",},{M[1],M[36],T\"atraso7\",},{M[1],M[5],T\"sinal1\",},{M[1],M[25],T\"sinal2\",},{M[1],M[27],T\"sinal3\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[29],T\"sinal4\",},{M[1],M[31],T\"sinal5\",},{M[1],M[33],T\"sinal6\",},{M[1],M[35],T\"sinal7\",},{M[8],M[0],T\"is_active_c1_SistemaCAS_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_SistemaCAS_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SistemaCAS_v2MachineNumber_,
           1,
           1,
           1,
           0,
           34,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_SistemaCAS_v2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_SistemaCAS_v2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SistemaCAS_v2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"sinal");
          _SFD_SET_DATA_PROPS(1,1,1,0,"f");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rr");
          _SFD_SET_DATA_PROPS(3,1,1,0,"T");
          _SFD_SET_DATA_PROPS(4,1,1,0,"D");
          _SFD_SET_DATA_PROPS(5,1,1,0,"S");
          _SFD_SET_DATA_PROPS(6,1,1,0,"pH");
          _SFD_SET_DATA_PROPS(7,1,1,0,"r");
          _SFD_SET_DATA_PROPS(8,2,0,1,"sinal1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"L1");
          _SFD_SET_DATA_PROPS(10,1,1,0,"L2");
          _SFD_SET_DATA_PROPS(11,1,1,0,"ag2");
          _SFD_SET_DATA_PROPS(12,1,1,0,"L3");
          _SFD_SET_DATA_PROPS(13,1,1,0,"ag3");
          _SFD_SET_DATA_PROPS(14,1,1,0,"L4");
          _SFD_SET_DATA_PROPS(15,1,1,0,"ag4");
          _SFD_SET_DATA_PROPS(16,1,1,0,"L5");
          _SFD_SET_DATA_PROPS(17,1,1,0,"ag5");
          _SFD_SET_DATA_PROPS(18,1,1,0,"L6");
          _SFD_SET_DATA_PROPS(19,1,1,0,"L7");
          _SFD_SET_DATA_PROPS(20,1,1,0,"sps");
          _SFD_SET_DATA_PROPS(21,2,0,1,"atraso1");
          _SFD_SET_DATA_PROPS(22,2,0,1,"sinal2");
          _SFD_SET_DATA_PROPS(23,2,0,1,"atraso2");
          _SFD_SET_DATA_PROPS(24,2,0,1,"sinal3");
          _SFD_SET_DATA_PROPS(25,2,0,1,"atraso3");
          _SFD_SET_DATA_PROPS(26,2,0,1,"sinal4");
          _SFD_SET_DATA_PROPS(27,2,0,1,"atraso4");
          _SFD_SET_DATA_PROPS(28,2,0,1,"sinal5");
          _SFD_SET_DATA_PROPS(29,2,0,1,"atraso5");
          _SFD_SET_DATA_PROPS(30,2,0,1,"sinal6");
          _SFD_SET_DATA_PROPS(31,2,0,1,"atraso6");
          _SFD_SET_DATA_PROPS(32,2,0,1,"sinal7");
          _SFD_SET_DATA_PROPS(33,2,0,1,"atraso7");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",40,-1,2317);
        _SFD_CV_INIT_EML_IF(0,1,0,1142,1156,-1,1180);
        _SFD_CV_INIT_EML_IF(0,1,1,1181,1195,-1,1229);
        _SFD_CV_INIT_EML_IF(0,1,2,2119,2128,-1,2206);
        _SFD_CV_INIT_EML_IF(0,1,3,2207,2216,-1,2294);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_sinal;
          real_T *c1_f;
          real_T *c1_rr;
          real_T *c1_T;
          real_T *c1_D;
          real_T *c1_S;
          real_T *c1_pH;
          real_T *c1_r;
          real_T *c1_sinal1;
          real_T *c1_L1;
          real_T *c1_L2;
          real_T *c1_ag2;
          real_T *c1_L3;
          real_T *c1_ag3;
          real_T *c1_L4;
          real_T *c1_ag4;
          real_T *c1_L5;
          real_T *c1_ag5;
          real_T *c1_L6;
          real_T *c1_L7;
          real_T *c1_sps;
          real_T *c1_atraso1;
          real_T *c1_sinal2;
          real_T *c1_atraso2;
          real_T *c1_sinal3;
          real_T *c1_atraso3;
          real_T *c1_sinal4;
          real_T *c1_atraso4;
          real_T *c1_sinal5;
          real_T *c1_atraso5;
          real_T *c1_sinal6;
          real_T *c1_atraso6;
          real_T *c1_sinal7;
          real_T *c1_atraso7;
          c1_atraso7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c1_sinal7 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c1_atraso6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c1_sinal6 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c1_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c1_sinal5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c1_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c1_sinal4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_sinal3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_sinal2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_sps = (real_T *)ssGetInputPortSignal(chartInstance->S, 19);
          c1_L7 = (real_T *)ssGetInputPortSignal(chartInstance->S, 18);
          c1_L6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 17);
          c1_ag5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 16);
          c1_L5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 15);
          c1_ag4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c1_L4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c1_ag3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c1_L3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_ag2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_L2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_L1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_sinal1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_pH = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_S = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_D = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_rr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_f = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_sinal = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_sinal);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_f);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_rr);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_T);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_D);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_S);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_pH);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_r);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_sinal1);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_L1);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_L2);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_ag2);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_L3);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_ag3);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_L4);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_ag4);
          _SFD_SET_DATA_VALUE_PTR(16U, c1_L5);
          _SFD_SET_DATA_VALUE_PTR(17U, c1_ag5);
          _SFD_SET_DATA_VALUE_PTR(18U, c1_L6);
          _SFD_SET_DATA_VALUE_PTR(19U, c1_L7);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_sps);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_atraso1);
          _SFD_SET_DATA_VALUE_PTR(22U, c1_sinal2);
          _SFD_SET_DATA_VALUE_PTR(23U, c1_atraso2);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_sinal3);
          _SFD_SET_DATA_VALUE_PTR(25U, c1_atraso3);
          _SFD_SET_DATA_VALUE_PTR(26U, c1_sinal4);
          _SFD_SET_DATA_VALUE_PTR(27U, c1_atraso4);
          _SFD_SET_DATA_VALUE_PTR(28U, c1_sinal5);
          _SFD_SET_DATA_VALUE_PTR(29U, c1_atraso5);
          _SFD_SET_DATA_VALUE_PTR(30U, c1_sinal6);
          _SFD_SET_DATA_VALUE_PTR(31U, c1_atraso6);
          _SFD_SET_DATA_VALUE_PTR(32U, c1_sinal7);
          _SFD_SET_DATA_VALUE_PTR(33U, c1_atraso7);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SistemaCAS_v2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GXl19tjTaHwOgUuQV63N3B";
}

static void sf_opaque_initialize_c1_SistemaCAS_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInstanceVar);
  initialize_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_SistemaCAS_v2(void *chartInstanceVar)
{
  enable_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_SistemaCAS_v2(void *chartInstanceVar)
{
  disable_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_SistemaCAS_v2(void *chartInstanceVar)
{
  sf_gateway_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_SistemaCAS_v2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_SistemaCAS_v2
    ((SFc1_SistemaCAS_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_SistemaCAS_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_SistemaCAS_v2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_SistemaCAS_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_SistemaCAS_v2(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_SistemaCAS_v2(S);
}

static void sf_opaque_set_sim_state_c1_SistemaCAS_v2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_SistemaCAS_v2(S, st);
}

static void sf_opaque_terminate_c1_SistemaCAS_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_SistemaCAS_v2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SistemaCAS_v2_optimization_info();
    }

    finalize_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_SistemaCAS_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c1_SistemaCAS_v2((SFc1_SistemaCAS_v2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_SistemaCAS_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SistemaCAS_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,20);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,14);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=14; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 20; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1809497540U));
  ssSetChecksum1(S,(603168803U));
  ssSetChecksum2(S,(2084460937U));
  ssSetChecksum3(S,(2977018448U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_SistemaCAS_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_SistemaCAS_v2(SimStruct *S)
{
  SFc1_SistemaCAS_v2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_SistemaCAS_v2InstanceStruct *)utMalloc(sizeof
    (SFc1_SistemaCAS_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_SistemaCAS_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_SistemaCAS_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_SistemaCAS_v2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_SistemaCAS_v2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_SistemaCAS_v2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_SistemaCAS_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_SistemaCAS_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_SistemaCAS_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_SistemaCAS_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_SistemaCAS_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_SistemaCAS_v2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_SistemaCAS_v2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_SistemaCAS_v2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_SistemaCAS_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_SistemaCAS_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_SistemaCAS_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_SistemaCAS_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
