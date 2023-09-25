/*
 * File: REL_private.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.131
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 19:05:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_private_h_
#define RTW_HEADER_REL_private_h_
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL.h"

extern void REL_FLDoorRlsDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm);
extern void REL_FLDoorRlsDriver(boolean_T rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, boolean_T rtu_SI_b_CinchHome,
  boolean_T rtu_SI_b_ElecDoorCfg, uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW);

#endif                                 /* RTW_HEADER_REL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
