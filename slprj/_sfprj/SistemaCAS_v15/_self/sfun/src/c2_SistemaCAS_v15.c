/* Include files */

#include <stddef.h>
#include "blas.h"
#include "SistemaCAS_v15_sfun.h"
#include "c2_SistemaCAS_v15.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "SistemaCAS_v15_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[19] = { "W", "L", "D", "T", "S", "pH",
  "Dm", "C", "i", "nargin", "nargout", "parametros_aquario",
  "parametros_ambientais", "atraso1", "atraso2", "atraso3", "atraso4", "atraso5",
  "caminhos" };

/* Function Declarations */
static void initialize_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void initialize_params_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance);
static void enable_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void disable_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance);
static void set_sim_state_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void sf_gateway_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void c2_chartstep_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void initSimStructsc2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct *chartInstance,
  const mxArray *c2_caminhos, const char_T *c2_identifier, real_T c2_y[5]);
static void c2_b_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_atraso5, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u);
static real_T c2_mpower(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
  c2_a);
static void c2_eml_scalar_eg(SFc2_SistemaCAS_v15InstanceStruct *chartInstance);
static real_T c2_sqrt(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      c2_x);
static void c2_eml_error(SFc2_SistemaCAS_v15InstanceStruct *chartInstance);
static real_T c2_mean(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      c2_x[2]);
static real_T c2_b_mpower(SFc2_SistemaCAS_v15InstanceStruct *chartInstance,
  real_T c2_a);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SistemaCAS_v15, const char_T *
  c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      *c2_x);
static void init_dsm_address_info(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_SistemaCAS_v15 = 0U;
}

static void initialize_params_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_SistemaCAS_v15
  (SFc2_SistemaCAS_v15InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i0;
  real_T c2_f_u[5];
  const mxArray *c2_g_y = NULL;
  uint8_T c2_f_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T *c2_atraso1;
  real_T *c2_atraso2;
  real_T *c2_atraso3;
  real_T *c2_atraso4;
  real_T *c2_atraso5;
  real_T (*c2_caminhos)[5];
  c2_caminhos = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(7, 1), false);
  c2_hoistedGlobal = *c2_atraso1;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_atraso2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_atraso3;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_atraso4;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_atraso5;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i0 = 0; c2_i0 < 5; c2_i0++) {
    c2_f_u[c2_i0] = (*c2_caminhos)[c2_i0];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_f_hoistedGlobal = chartInstance->c2_is_active_c2_SistemaCAS_v15;
  c2_g_u = c2_f_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[5];
  int32_T c2_i1;
  real_T *c2_atraso1;
  real_T *c2_atraso2;
  real_T *c2_atraso3;
  real_T *c2_atraso4;
  real_T *c2_atraso5;
  real_T (*c2_caminhos)[5];
  c2_caminhos = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_atraso1 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "atraso1");
  *c2_atraso2 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "atraso2");
  *c2_atraso3 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 2)), "atraso3");
  *c2_atraso4 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "atraso4");
  *c2_atraso5 = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "atraso5");
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                      "caminhos", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 5; c2_i1++) {
    (*c2_caminhos)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_SistemaCAS_v15 = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
     "is_active_c2_SistemaCAS_v15");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_SistemaCAS_v15(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T *c2_atraso1;
  real_T *c2_atraso2;
  real_T *c2_atraso3;
  real_T *c2_atraso4;
  real_T *c2_atraso5;
  real_T (*c2_caminhos)[5];
  real_T (*c2_parametros_ambientais)[3];
  real_T (*c2_parametros_aquario)[3];
  c2_caminhos = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_parametros_ambientais = (real_T (*)[3])ssGetInputPortSignal
    (chartInstance->S, 1);
  c2_parametros_aquario = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    0);
  c2_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_SistemaCAS_v15(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_SistemaCAS_v15MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c2_atraso1, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_atraso2, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_atraso3, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_atraso4, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_atraso5, 4U);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_parametros_aquario)[c2_i2], 5U);
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_parametros_ambientais)[c2_i3], 6U);
  }

  for (c2_i4 = 0; c2_i4 < 5; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_caminhos)[c2_i4], 7U);
  }
}

static void c2_chartstep_c2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  int32_T c2_i5;
  real_T c2_parametros_aquario[3];
  int32_T c2_i6;
  real_T c2_parametros_ambientais[3];
  uint32_T c2_debug_family_var_map[19];
  real_T c2_W;
  real_T c2_L;
  real_T c2_D;
  real_T c2_T;
  real_T c2_S;
  real_T c2_pH;
  real_T c2_Dm[5];
  real_T c2_C[5];
  real_T c2_i;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 6.0;
  real_T c2_atraso1;
  real_T c2_atraso2;
  real_T c2_atraso3;
  real_T c2_atraso4;
  real_T c2_atraso5;
  real_T c2_caminhos[5];
  int32_T c2_i7;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  int32_T c2_i8;
  real_T c2_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_y;
  real_T c2_b_y[2];
  real_T c2_b_A;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_y;
  real_T c2_c_A;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_d_y;
  real_T c2_d_A;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_e_y;
  real_T c2_e_A;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_f_y;
  real_T c2_b_D[2];
  int32_T c2_i9;
  int32_T c2_b_i;
  real_T c2_f_A;
  real_T c2_B;
  real_T c2_t_x;
  real_T c2_g_y;
  real_T c2_u_x;
  real_T c2_h_y;
  real_T c2_v_x;
  real_T c2_i_y;
  real_T c2_g_A;
  real_T c2_b_B;
  real_T c2_w_x;
  real_T c2_j_y;
  real_T c2_x_x;
  real_T c2_k_y;
  real_T c2_y_x;
  real_T c2_l_y;
  real_T c2_h_A;
  real_T c2_c_B;
  real_T c2_ab_x;
  real_T c2_m_y;
  real_T c2_bb_x;
  real_T c2_n_y;
  real_T c2_cb_x;
  real_T c2_o_y;
  real_T c2_i_A;
  real_T c2_d_B;
  real_T c2_db_x;
  real_T c2_p_y;
  real_T c2_eb_x;
  real_T c2_q_y;
  real_T c2_fb_x;
  real_T c2_r_y;
  real_T c2_j_A;
  real_T c2_e_B;
  real_T c2_gb_x;
  real_T c2_s_y;
  real_T c2_hb_x;
  real_T c2_t_y;
  real_T c2_ib_x;
  real_T c2_u_y;
  int32_T c2_i10;
  real_T *c2_b_atraso5;
  real_T *c2_b_atraso4;
  real_T *c2_b_atraso3;
  real_T *c2_b_atraso2;
  real_T *c2_b_atraso1;
  real_T (*c2_b_caminhos)[5];
  real_T (*c2_b_parametros_ambientais)[3];
  real_T (*c2_b_parametros_aquario)[3];
  c2_b_caminhos = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_parametros_ambientais = (real_T (*)[3])ssGetInputPortSignal
    (chartInstance->S, 1);
  c2_b_parametros_aquario = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
    0);
  c2_b_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_parametros_aquario[c2_i5] = (*c2_b_parametros_aquario)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_parametros_ambientais[c2_i6] = (*c2_b_parametros_ambientais)[c2_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_W, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_L, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_D, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_T, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_S, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_pH, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Dm, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_C, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_parametros_aquario, 11U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_parametros_ambientais, 12U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_atraso1, 13U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_atraso2, 14U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_atraso3, 15U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_atraso4, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_atraso5, 17U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_caminhos, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_W = c2_parametros_aquario[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_L = c2_parametros_aquario[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_D = c2_parametros_aquario[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_T = c2_parametros_ambientais[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_S = c2_parametros_ambientais[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_pH = c2_parametros_ambientais[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  for (c2_i7 = 0; c2_i7 < 5; c2_i7++) {
    c2_caminhos[c2_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_caminhos[0] = c2_mpower(chartInstance, c2_D) + c2_mpower(chartInstance,
    c2_L);
  c2_b_sqrt(chartInstance, &c2_caminhos[0]);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_x = c2_mpower(chartInstance, c2_W) + c2_mpower(chartInstance, c2_L);
  c2_b_x = c2_x;
  if (c2_b_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_b_x = muDoubleScalarSqrt(c2_b_x);
  c2_caminhos[1] = c2_b_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_caminhos[2] = c2_L;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_caminhos[3] = c2_caminhos[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_c_x = c2_mpower(chartInstance, c2_D) + c2_mpower(chartInstance, c2_L);
  c2_d_x = c2_c_x;
  if (c2_d_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_d_x = muDoubleScalarSqrt(c2_d_x);
  c2_caminhos[4] = c2_d_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  for (c2_i8 = 0; c2_i8 < 5; c2_i8++) {
    c2_Dm[c2_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_A = c2_D;
  c2_e_x = c2_A;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_y = c2_g_x / 2.0;
  c2_b_y[0] = c2_y;
  c2_b_y[1] = 0.0;
  c2_Dm[0] = c2_mean(chartInstance, c2_b_y);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_b_A = c2_D;
  c2_h_x = c2_b_A;
  c2_i_x = c2_h_x;
  c2_j_x = c2_i_x;
  c2_c_y = c2_j_x / 2.0;
  c2_Dm[1] = c2_c_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_c_A = c2_D;
  c2_k_x = c2_c_A;
  c2_l_x = c2_k_x;
  c2_m_x = c2_l_x;
  c2_d_y = c2_m_x / 2.0;
  c2_Dm[2] = c2_d_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_d_A = c2_D;
  c2_n_x = c2_d_A;
  c2_o_x = c2_n_x;
  c2_p_x = c2_o_x;
  c2_e_y = c2_p_x / 2.0;
  c2_Dm[3] = c2_e_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
  c2_e_A = c2_D;
  c2_q_x = c2_e_A;
  c2_r_x = c2_q_x;
  c2_s_x = c2_r_x;
  c2_f_y = c2_s_x / 2.0;
  c2_b_D[0] = c2_D;
  c2_b_D[1] = c2_f_y;
  c2_Dm[4] = c2_mean(chartInstance, c2_b_D);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  for (c2_i9 = 0; c2_i9 < 5; c2_i9++) {
    c2_C[c2_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
  c2_i = 1.0;
  c2_b_i = 0;
  while (c2_b_i < 5) {
    c2_i = 1.0 + (real_T)c2_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
    c2_C[_SFD_EML_ARRAY_BOUNDS_CHECK("C", (int32_T)_SFD_INTEGER_CHECK("i", c2_i),
      1, 5, 1, 0) - 1] = (((((((1448.96 + 4.591 * c2_T) - 0.053040000000000004 *
      c2_mpower(chartInstance, c2_T)) + 0.00023740000000000002 * c2_b_mpower
      (chartInstance, c2_T)) + 1.34 * (c2_S - 35.0)) + 0.0163 *
      c2_Dm[_SFD_EML_ARRAY_BOUNDS_CHECK("Dm", (int32_T)_SFD_INTEGER_CHECK("i",
      c2_i), 1, 5, 1, 0) - 1]) + 1.6749999999999998E-7 * c2_mpower(chartInstance,
      c2_Dm[_SFD_EML_ARRAY_BOUNDS_CHECK("Dm", (int32_T)_SFD_INTEGER_CHECK("i",
      c2_i), 1, 5, 1, 0) - 1])) - 0.010249999999999999 * c2_T * (c2_S - 35.0)) -
      7.139E-13 * c2_T * c2_b_mpower(chartInstance,
      c2_Dm[_SFD_EML_ARRAY_BOUNDS_CHECK("Dm", (int32_T)_SFD_INTEGER_CHECK("i",
      c2_i), 1, 5, 1, 0) - 1]);
    c2_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_f_A = c2_caminhos[0];
  c2_B = c2_C[0];
  c2_t_x = c2_f_A;
  c2_g_y = c2_B;
  c2_u_x = c2_t_x;
  c2_h_y = c2_g_y;
  c2_v_x = c2_u_x;
  c2_i_y = c2_h_y;
  c2_atraso1 = c2_v_x / c2_i_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_g_A = c2_caminhos[1];
  c2_b_B = c2_C[1];
  c2_w_x = c2_g_A;
  c2_j_y = c2_b_B;
  c2_x_x = c2_w_x;
  c2_k_y = c2_j_y;
  c2_y_x = c2_x_x;
  c2_l_y = c2_k_y;
  c2_atraso2 = c2_y_x / c2_l_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
  c2_h_A = c2_caminhos[2];
  c2_c_B = c2_C[2];
  c2_ab_x = c2_h_A;
  c2_m_y = c2_c_B;
  c2_bb_x = c2_ab_x;
  c2_n_y = c2_m_y;
  c2_cb_x = c2_bb_x;
  c2_o_y = c2_n_y;
  c2_atraso3 = c2_cb_x / c2_o_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
  c2_i_A = c2_caminhos[3];
  c2_d_B = c2_C[3];
  c2_db_x = c2_i_A;
  c2_p_y = c2_d_B;
  c2_eb_x = c2_db_x;
  c2_q_y = c2_p_y;
  c2_fb_x = c2_eb_x;
  c2_r_y = c2_q_y;
  c2_atraso4 = c2_fb_x / c2_r_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
  c2_j_A = c2_caminhos[4];
  c2_e_B = c2_C[4];
  c2_gb_x = c2_j_A;
  c2_s_y = c2_e_B;
  c2_hb_x = c2_gb_x;
  c2_t_y = c2_s_y;
  c2_ib_x = c2_hb_x;
  c2_u_y = c2_t_y;
  c2_atraso5 = c2_ib_x / c2_u_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -71);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_atraso1 = c2_atraso1;
  *c2_b_atraso2 = c2_atraso2;
  *c2_b_atraso3 = c2_atraso3;
  *c2_b_atraso4 = c2_atraso4;
  *c2_b_atraso5 = c2_atraso5;
  for (c2_i10 = 0; c2_i10 < 5; c2_i10++) {
    (*c2_b_caminhos)[c2_i10] = c2_caminhos[c2_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_SistemaCAS_v15(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i11;
  real_T c2_b_inData[5];
  int32_T c2_i12;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i11 = 0; c2_i11 < 5; c2_i11++) {
    c2_b_inData[c2_i11] = (*(real_T (*)[5])c2_inData)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 5; c2_i12++) {
    c2_u[c2_i12] = c2_b_inData[c2_i12];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct *chartInstance,
  const mxArray *c2_caminhos, const char_T *c2_identifier, real_T c2_y[5])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_caminhos), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_caminhos);
}

static void c2_b_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv1[5];
  int32_T c2_i13;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c2_i13 = 0; c2_i13 < 5; c2_i13++) {
    c2_y[c2_i13] = c2_dv1[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_caminhos;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i14;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_caminhos = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_caminhos), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_caminhos);
  for (c2_i14 = 0; c2_i14 < 5; c2_i14++) {
    (*(real_T (*)[5])c2_outData)[c2_i14] = c2_y[c2_i14];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_atraso5, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_atraso5), &c2_thisId);
  sf_mex_destroy(&c2_atraso5);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_atraso5;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_atraso5 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_atraso5), &c2_thisId);
  sf_mex_destroy(&c2_atraso5);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i15;
  real_T c2_b_inData[3];
  int32_T c2_i16;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_b_inData[c2_i15] = (*(real_T (*)[3])c2_inData)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_u[c2_i16] = c2_b_inData[c2_i16];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_SistemaCAS_v15_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 40, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  const mxArray *c2_rhs32 = NULL;
  const mxArray *c2_lhs32 = NULL;
  const mxArray *c2_rhs33 = NULL;
  const mxArray *c2_lhs33 = NULL;
  const mxArray *c2_rhs34 = NULL;
  const mxArray *c2_lhs34 = NULL;
  const mxArray *c2_rhs35 = NULL;
  const mxArray *c2_lhs35 = NULL;
  const mxArray *c2_rhs36 = NULL;
  const mxArray *c2_lhs36 = NULL;
  const mxArray *c2_rhs37 = NULL;
  const mxArray *c2_lhs37 = NULL;
  const mxArray *c2_rhs38 = NULL;
  const mxArray *c2_lhs38 = NULL;
  const mxArray *c2_rhs39 = NULL;
  const mxArray *c2_lhs39 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717478U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331308458U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sqrt"), "name", "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343837586U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343837558U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825938U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mean"), "name", "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383880884U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isequal"), "name", "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825958U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286825986U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sum"), "name", "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_assert_valid_dim"), "name",
                  "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assertValidDim"),
                  "name", "name", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c2_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c2_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c2_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c2_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c2_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c2_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c2_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c2_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs39), "lhs", "lhs",
                  39);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
  sf_mex_destroy(&c2_rhs32);
  sf_mex_destroy(&c2_lhs32);
  sf_mex_destroy(&c2_rhs33);
  sf_mex_destroy(&c2_lhs33);
  sf_mex_destroy(&c2_rhs34);
  sf_mex_destroy(&c2_lhs34);
  sf_mex_destroy(&c2_rhs35);
  sf_mex_destroy(&c2_lhs35);
  sf_mex_destroy(&c2_rhs36);
  sf_mex_destroy(&c2_lhs36);
  sf_mex_destroy(&c2_rhs37);
  sf_mex_destroy(&c2_lhs37);
  sf_mex_destroy(&c2_rhs38);
  sf_mex_destroy(&c2_lhs38);
  sf_mex_destroy(&c2_rhs39);
  sf_mex_destroy(&c2_lhs39);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static real_T c2_mpower(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  return c2_d_a * c2_d_a;
}

static void c2_eml_scalar_eg(SFc2_SistemaCAS_v15InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_sqrt(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_SistemaCAS_v15InstanceStruct *chartInstance)
{
  int32_T c2_i17;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i18;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  for (c2_i17 = 0; c2_i17 < 30; c2_i17++) {
    c2_u[c2_i17] = c2_cv0[c2_i17];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    c2_b_u[c2_i18] = c2_cv1[c2_i18];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static real_T c2_mean(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      c2_x[2])
{
  real_T c2_b_y;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  (void)chartInstance;
  c2_b_y = c2_x[0];
  c2_b_y += c2_x[1];
  c2_b_x = c2_b_y;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  return c2_d_x / 2.0;
}

static real_T c2_b_mpower(SFc2_SistemaCAS_v15InstanceStruct *chartInstance,
  real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  real_T c2_ar;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_ar = c2_d_a;
  return muDoubleScalarPower(c2_ar, 3.0);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i19;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i19, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i19;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_SistemaCAS_v15, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_SistemaCAS_v15), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_SistemaCAS_v15);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_SistemaCAS_v15InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_SistemaCAS_v15InstanceStruct *chartInstance, real_T
                      *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void init_dsm_address_info(SFc2_SistemaCAS_v15InstanceStruct
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

void sf_c2_SistemaCAS_v15_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2892247992U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4047637007U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4107420865U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(49817528U);
}

mxArray *sf_c2_SistemaCAS_v15_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QQHBiCn8fa33tC3yS8LCrB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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
      pr[1] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_SistemaCAS_v15_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_SistemaCAS_v15_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_SistemaCAS_v15(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[10],T\"atraso1\",},{M[1],M[11],T\"atraso2\",},{M[1],M[12],T\"atraso3\",},{M[1],M[13],T\"atraso4\",},{M[1],M[14],T\"atraso5\",},{M[1],M[18],T\"caminhos\",},{M[8],M[0],T\"is_active_c2_SistemaCAS_v15\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_SistemaCAS_v15_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _SistemaCAS_v15MachineNumber_,
           2,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_SistemaCAS_v15MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_SistemaCAS_v15MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _SistemaCAS_v15MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"atraso1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"atraso2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"atraso3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"atraso4");
          _SFD_SET_DATA_PROPS(4,2,0,1,"atraso5");
          _SFD_SET_DATA_PROPS(5,1,1,0,"parametros_aquario");
          _SFD_SET_DATA_PROPS(6,1,1,0,"parametros_ambientais");
          _SFD_SET_DATA_PROPS(7,2,0,1,"caminhos");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3038);
        _SFD_CV_INIT_EML_FOR(0,1,0,2284,2296,2555);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_atraso1;
          real_T *c2_atraso2;
          real_T *c2_atraso3;
          real_T *c2_atraso4;
          real_T *c2_atraso5;
          real_T (*c2_parametros_aquario)[3];
          real_T (*c2_parametros_ambientais)[3];
          real_T (*c2_caminhos)[5];
          c2_caminhos = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
          c2_parametros_ambientais = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 1);
          c2_parametros_aquario = (real_T (*)[3])ssGetInputPortSignal
            (chartInstance->S, 0);
          c2_atraso5 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_atraso4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_atraso3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_atraso2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_atraso1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_atraso1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_atraso2);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_atraso3);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_atraso4);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_atraso5);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_parametros_aquario);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_parametros_ambientais);
          _SFD_SET_DATA_VALUE_PTR(7U, *c2_caminhos);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _SistemaCAS_v15MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IQWABEL2LsaVINbtfc8HTE";
}

static void sf_opaque_initialize_c2_SistemaCAS_v15(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar);
  initialize_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_SistemaCAS_v15(void *chartInstanceVar)
{
  enable_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_SistemaCAS_v15(void *chartInstanceVar)
{
  disable_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_SistemaCAS_v15(void *chartInstanceVar)
{
  sf_gateway_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_SistemaCAS_v15(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_SistemaCAS_v15
    ((SFc2_SistemaCAS_v15InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_SistemaCAS_v15();/* state var info */
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

extern void sf_internal_set_sim_state_c2_SistemaCAS_v15(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_SistemaCAS_v15();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_SistemaCAS_v15(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_SistemaCAS_v15(S);
}

static void sf_opaque_set_sim_state_c2_SistemaCAS_v15(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_SistemaCAS_v15(S, st);
}

static void sf_opaque_terminate_c2_SistemaCAS_v15(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_SistemaCAS_v15InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_SistemaCAS_v15_optimization_info();
    }

    finalize_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
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
  initSimStructsc2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_SistemaCAS_v15(SimStruct *S)
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
    initialize_params_c2_SistemaCAS_v15((SFc2_SistemaCAS_v15InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_SistemaCAS_v15(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_SistemaCAS_v15_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2549953304U));
  ssSetChecksum1(S,(3568879587U));
  ssSetChecksum2(S,(88654363U));
  ssSetChecksum3(S,(1253582871U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_SistemaCAS_v15(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_SistemaCAS_v15(SimStruct *S)
{
  SFc2_SistemaCAS_v15InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_SistemaCAS_v15InstanceStruct *)utMalloc(sizeof
    (SFc2_SistemaCAS_v15InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_SistemaCAS_v15InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_SistemaCAS_v15;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_SistemaCAS_v15;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_SistemaCAS_v15;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_SistemaCAS_v15;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_SistemaCAS_v15;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_SistemaCAS_v15;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_SistemaCAS_v15;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_SistemaCAS_v15;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_SistemaCAS_v15;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_SistemaCAS_v15;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_SistemaCAS_v15;
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

void c2_SistemaCAS_v15_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_SistemaCAS_v15(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_SistemaCAS_v15(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_SistemaCAS_v15(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_SistemaCAS_v15_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
