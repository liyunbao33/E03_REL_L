/*
 * File: REL.c
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

#include "REL.h"
#include "rtwtypes.h"
#include "REL_types.h"
#include "Rte_Type.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_Checking                ((uint8_T)1U)
#define REL_IN_Delay                   ((uint8_T)2U)
#define REL_IN_ElectricDoor            ((uint8_T)1U)
#define REL_IN_Fail                    ((uint8_T)1U)
#define REL_IN_Fail1                   ((uint8_T)2U)
#define REL_IN_Ice_Break               ((uint8_T)3U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_Idle_p                  ((uint8_T)4U)
#define REL_IN_LastCheck               ((uint8_T)2U)
#define REL_IN_LastCheck_l             ((uint8_T)5U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_NonElectricDoor         ((uint8_T)2U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)2U)
#define REL_IN_Reset                   ((uint8_T)3U)
#define REL_IN_Step1_Ajar              ((uint8_T)4U)
#define REL_IN_Step2_Open              ((uint8_T)5U)
#define REL_IN_Success                 ((uint8_T)6U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_o                  ((uint8_T)1U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Press                   ((uint8_T)2U)
#define REL_IN_Release_b               ((uint8_T)4U)
#define REL_IN_Release_bx              ((uint8_T)3U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_UnlockFail              ((uint8_T)1U)
#define REL_IN_UnlockReq               ((uint8_T)2U)
#define REL_IN_UnlockSuccess           ((uint8_T)3U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_REL_T REL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_REL_T REL_Y;

/* Real-time model */
static RT_MODEL_REL_T REL_M_;
RT_MODEL_REL_T *const REL_M = &REL_M_;

/* Forward declaration for local functions */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  boolean_T rtu_SI_b_CinchHome, uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW);

/* Forward declaration for local functions */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open);
static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input);

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  boolean_T rtu_SI_b_CinchHome, uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->is_Normal == REL_IN_ElectricDoor) {
    if (localDW->is_MainProgress_c == REL_IN_Idle) {
      if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
          localDW->SO_b_DoorRlsReq_start) {
        localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
        localDW->is_MainProgress_c = REL_IN_Release;
        localDW->SL_e_CycleCount = 0U;
        *rty_SO_e_MotorPwm = 100U;
        localDW->is_Release_a = REL_IN_Delay;
        localDW->temporalCounter_i1 = 0U;
      }
    } else {
      /* case IN_Release: */
      switch (localDW->is_Release_a) {
       case REL_IN_Checking:
        {
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release_a = REL_IN_Step2_Open;
            localDW->is_Step2_Open_f = REL_IN_Idle_p;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Stop;
          } else {
            Boolean tmp_0;
            tmp_0 = !rtu_SI_b_DoorAjar;
            if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                (localDW->SL_e_CycleCount < 2)) {
              *rty_SO_e_MotorPwm = 100U;
              localDW->is_Release_a = REL_IN_Step1_Ajar;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorCmd = Rls;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 2)) {
              localDW->is_Release_a = REL_IN_Reset;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = false;
              *rty_SO_b_MotorB = true;
              *rty_SO_e_MotorCmd = Reset;
              *rty_SO_e_MotorPwm = 100U;
            }
          }
        }
        break;

       case REL_IN_Delay:
        if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
          localDW->is_Release_a = REL_IN_Step1_Ajar;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Rls;
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release_a = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress_c = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        {
          if (localDW->temporalCounter_i1 >= 30) {
            int32_T tmp;
            localDW->is_Release_a = REL_IN_Checking;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Stop;
            tmp = localDW->SL_e_CycleCount + 1;
            if (localDW->SL_e_CycleCount + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CycleCount = (uint8_T)tmp;
          }
        }
        break;

       default:
        /* case IN_Step2_Open: */
        switch (localDW->is_Step2_Open_f) {
         case REL_IN_Fail:
          localDW->is_Step2_Open_f = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Fail1:
          localDW->is_Step2_Open_f = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Ice_Break:
          if ((localDW->temporalCounter_i1 < 600) && (!rtu_SI_b_CinchHome)) {
            localDW->is_Step2_Open_f = REL_IN_Success;
            *rty_SO_b_Error = false;
          } else if ((localDW->temporalCounter_i1 >= 600) && rtu_SI_b_CinchHome)
          {
            localDW->is_Step2_Open_f = REL_IN_Fail1;
            *rty_SO_b_Error = true;
          }
          break;

         case REL_IN_Idle_p:
          if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorOpen) {
            localDW->is_Step2_Open_f = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release_a = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = Reset;
            *rty_SO_e_MotorPwm = 100U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_Step2_Open_f = REL_IN_LastCheck_l;
          }
          break;

         case REL_IN_LastCheck_l:
          if (!rtu_SI_b_CinchHome) {
            localDW->is_Step2_Open_f = REL_IN_Fail;
            *rty_SO_b_Error = true;
          } else {
            localDW->is_Step2_Open_f = REL_IN_Ice_Break;
            localDW->temporalCounter_i1 = 0U;
          }
          break;

         default:
          /* case IN_Success: */
          localDW->is_Step2_Open_f = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_a = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;
        }
        break;
      }
    }

    /* case IN_NonElectricDoor: */
  } else if (localDW->is_MainProgress == REL_IN_Idle) {
    if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
        localDW->SO_b_DoorRlsReq_start) {
      localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
      localDW->is_MainProgress = REL_IN_Release;
      localDW->SL_e_CycleCount = 0U;
      *rty_SO_e_MotorPwm = 100U;
      localDW->is_Release = REL_IN_Delay;
      localDW->temporalCounter_i1 = 0U;
    }
  } else {
    /* case IN_Release: */
    switch (localDW->is_Release) {
     case REL_IN_Checking:
      {
        if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
          localDW->is_Release = REL_IN_Step2_Open;
          localDW->is_Step2_Open = REL_IN_Idle;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
        } else {
          Boolean tmp_0;
          tmp_0 = !rtu_SI_b_DoorAjar;
          if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
              (localDW->SL_e_CycleCount < 2)) {
            *rty_SO_e_MotorPwm = 100U;
            localDW->is_Release = REL_IN_Step1_Ajar;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = true;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Rls;
          } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                     (localDW->SL_e_CycleCount >= 2)) {
            localDW->is_Release = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = Reset;
            *rty_SO_e_MotorPwm = 100U;
          }
        }
      }
      break;

     case REL_IN_Delay:
      if (localDW->temporalCounter_i1 >= localDW->SL_e_DoorRlsDelayTime) {
        localDW->is_Release = REL_IN_Step1_Ajar;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = true;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorCmd = Rls;
      }
      break;

     case REL_IN_Reset:
      if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_MainProgress = REL_IN_Idle;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = false;
        *rty_SO_e_MotorCmd = Stop;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case REL_IN_Step1_Ajar:
      {
        if (localDW->temporalCounter_i1 >= 30) {
          int32_T tmp;
          localDW->is_Release = REL_IN_Checking;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          tmp = localDW->SL_e_CycleCount + 1;
          if (localDW->SL_e_CycleCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_CycleCount = (uint8_T)tmp;
        }
      }
      break;

     default:
      /* case IN_Step2_Open: */
      if (localDW->is_Step2_Open == REL_IN_Idle) {
        if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorOpen) {
          localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
        } else if (localDW->temporalCounter_i1 >= 300) {
          localDW->is_Step2_Open = REL_IN_LastCheck;
        }
      } else {
        /* case IN_LastCheck: */
        localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
        localDW->is_Release = REL_IN_Reset;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_MotorA = false;
        *rty_SO_b_MotorB = true;
        *rty_SO_e_MotorCmd = Reset;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 */
void REL_FLDoorRlsDriver_Init(boolean_T *rty_SO_b_MotorA, boolean_T
  *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_Error,
  uint8_T *rty_SO_e_MotorPwm)
{
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorCmd = Stop;
  *rty_SO_b_Error = false;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 */
void REL_FLDoorRlsDriver(boolean_T rtu_SO_b_DoorRlsReq, Boolean
  rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen, boolean_T rtu_SI_b_CinchHome,
  boolean_T rtu_SI_b_ElecDoorCfg, uint8_T rtu_SI_e_DoorRlsDelayTime, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean_T *rty_SO_b_Error, uint8_T *rty_SO_e_MotorPwm,
  DW_FLDoorRlsDriver_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SO_b_DoorRlsReq_prev = localDW->SO_b_DoorRlsReq_start;
  localDW->SO_b_DoorRlsReq_start = rtu_SO_b_DoorRlsReq;

  /* Chart: '<S3>/FLDoorRlsDriver' */
  if (localDW->is_active_c19_DoorRlsDriver == 0U) {
    localDW->SO_b_DoorRlsReq_prev = rtu_SO_b_DoorRlsReq;
    localDW->is_active_c19_DoorRlsDriver = 1U;
    localDW->is_c19_DoorRlsDriver = REL_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = true;
    *rty_SO_e_MotorCmd = Reset;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    REL_Normal(rtu_SI_b_DoorAjar, rtu_SI_b_DoorOpen, rtu_SI_b_CinchHome,
               rtu_SI_e_DoorRlsDelayTime, rty_SO_b_MotorA, rty_SO_b_MotorB,
               rty_SO_e_MotorCmd, rty_SO_b_Error, rty_SO_e_MotorPwm, localDW);

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    *rty_SO_b_MotorA = false;
    *rty_SO_b_MotorB = false;
    *rty_SO_e_MotorCmd = Stop;
    *rty_SO_e_MotorPwm = 100U;
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    if (!rtu_SI_b_ElecDoorCfg) {
      localDW->is_Normal = REL_IN_NonElectricDoor;
      localDW->is_MainProgress = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = Stop;
      *rty_SO_e_MotorPwm = 0U;
    } else {
      localDW->is_Normal = REL_IN_ElectricDoor;
      localDW->is_MainProgress_c = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = Stop;
      *rty_SO_e_MotorPwm = 0U;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/* Function for Chart: '<S3>/DoorRatSts' */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open)
{
  real_T status;
  if ((ajar == 0.0) && (open == 0.0)) {
    status = 1.0;
  } else if ((ajar == 1.0) && (open == 0.0)) {
    status = 2.0;
  } else if ((ajar == 1.0) && (open == 1.0)) {
    status = 3.0;
  } else {
    status = 0.0;
  }

  return status;
}

static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input)
{
  uint8_T output;

  /* Initialize output value to default value for Rat_Sts_E (Rat_Invalid) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of Rat_Sts_E */
    output = input;
  }

  return output;
}

/* Model step function for TID1 */
void REL_Step(void)                    /* Explicit Task: REL_Step */
{
  Door_Sts_E rtb_DataTypeConversion13;
  Rat_Sts_E rtb_SO_m_FLDoorRatSts;
  Rat_Sts_E rtb_SO_m_RLDoorRatSts;
  uint8_T SO_e_MotorPwm;
  boolean_T SI_b_CrashSts_prev;
  boolean_T SI_b_DoorHndBtnSts_prev;
  boolean_T SL_b_DoorHndBtnValid_prev;
  boolean_T SL_b_DoorInBtnValid_prev;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion13' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig'
   */
  rtb_DataTypeConversion13 = REL_U.VeOUT_DLK_LHRDoorLockSts_sig_Ve;

  /* Outport: '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg_read'
   */
  REL_Y.VbOUT_REL_FLDoorOpenSwitch_flg_ = REL_U.VbOUT_HWA_FLDoorFullOpen_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg_read'
   */
  REL_Y.VbOUT_REL_FLDoorAjarSwitch_flg_ = REL_U.VbOUT_SP_FLDoorAjarSts_flg_VbOU;

  /* Outport: '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg_read'
   */
  REL_Y.VbOUT_REL_RLDoorOpenSwitch_flg_ = REL_U.VbOUT_HWA_RLDoorFullOpen_flg_Vb;

  /* Outport: '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg' incorporates:
   *  Inport: '<Root>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg'
   *  SignalConversion generated from: '<S2>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg_read'
   */
  REL_Y.VbOUT_REL_RLDoorAjarSwitch_flg_ = REL_U.VbOUT_SP_RLDoorAjarSts_flg_VbOU;

  /* Chart: '<S3>/DoorRatSts' incorporates:
   *  Outport: '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg'
   */
  if (REL_DW.is_active_c3_REL == 0U) {
    real_T tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_FLDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_FLDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_RLDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_RLDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    real_T tmp;
    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_FLDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_FLDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((real_T)REL_Y.VbOUT_REL_RLDoorAjarSwitch_flg_,
      (real_T)REL_Y.VbOUT_REL_RLDoorOpenSwitch_flg_);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8_T)(int32_T)tmp);
      } else {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/DoorRatSts' */

  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg'
   */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = REL_U.VbOUT_SP_CrashOutpSts_flg_VbOUT;
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;

    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
     */
    REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
     */
    REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 600) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;

      /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
       */
      REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f =
        REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

      /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
       */
      REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f =
        REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

      /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
       */
      REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_ =
        REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

      /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' incorporates:
       *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
       */
      REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_ =
        REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;
    } else {
      /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' */
      REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f = false;

      /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' */
      REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f = false;

      /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' */
      REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_ = false;

      /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' */
      REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_ = false;
    }

    /* case IN_NoCrash: */
  } else if ((SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;

    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' */
    REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f = false;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' */
    REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f = false;

    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' */
    REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_ = false;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' */
    REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_ = false;
  } else {
    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
     */
    REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_FLDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
     */
    REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f =
      REL_U.VbINP_HWA_RLDoorButton_flg_VbIN;

    /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_FLDoorHandleSW_flg_Vb;

    /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' incorporates:
     *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
     */
    REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_ =
      REL_U.VbINP_HWA_RLDoorHandleSW_flg_Vb;
  }

  /* End of Chart: '<S3>/DoorSwSts' */

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg'
   */
  if (REL_DW.temporalCounter_i1_i < 63U) {
    REL_DW.temporalCounter_i1_i++;
  }

  if (REL_DW.temporalCounter_i2 < 63U) {
    REL_DW.temporalCounter_i2++;
  }

  if (REL_DW.temporalCounter_i3 < 255U) {
    REL_DW.temporalCounter_i3++;
  }

  if (REL_DW.temporalCounter_i4 < 127U) {
    REL_DW.temporalCounter_i4++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_DoorInBtnSts_start;
  REL_DW.SI_b_DoorInBtnSts_start = REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f;
  SL_b_DoorInBtnValid_prev = REL_DW.SL_b_DoorInBtnValid_start;
  REL_DW.SL_b_DoorInBtnValid_start = REL_DW.SL_b_DoorInBtnValid;
  SI_b_DoorHndBtnSts_prev = REL_DW.SI_b_DoorHndBtnSts_start;
  REL_DW.SI_b_DoorHndBtnSts_start = REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_;
  SL_b_DoorHndBtnValid_prev = REL_DW.SL_b_DoorHndBtnValid_start;
  REL_DW.SL_b_DoorHndBtnValid_start = REL_DW.SL_b_DoorHndBtnValid;
  if (REL_DW.is_active_c5_DoorRlsReq == 0U) {
    REL_DW.is_active_c5_DoorRlsReq = 1U;
    REL_DW.is_SwValid = REL_IN_Idle_o;
    REL_DW.SL_b_DoorInBtnValid = false;
    REL_DW.is_RlsReq = REL_IN_Idle_o;
    REL_DW.is_RlsReq_c = REL_IN_Idle_o;
    REL_DW.is_SwValid_b = REL_IN_Idle_o;
    REL_DW.SL_b_DoorHndBtnValid = false;
  } else {
    switch (REL_DW.is_SwValid) {
     case REL_IN_Idle_o:
      if ((SI_b_CrashSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
          REL_DW.SI_b_DoorInBtnSts_start) {
        REL_DW.is_SwValid = REL_IN_Once;
        REL_DW.temporalCounter_i3 = 0U;
      }
      break;

     case REL_IN_Once:
      if ((SI_b_CrashSts_prev != REL_DW.SI_b_DoorInBtnSts_start) &&
          REL_DW.SI_b_DoorInBtnSts_start) {
        REL_DW.is_SwValid = REL_IN_Twice;
        REL_DW.temporalCounter_i3 = 0U;
        REL_DW.SL_b_DoorInBtnValid = true;
      } else if (REL_DW.temporalCounter_i3 >= 200) {
        REL_DW.is_SwValid = REL_IN_Idle_o;
        REL_DW.SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (REL_DW.temporalCounter_i3 >= 3) {
        REL_DW.is_SwValid = REL_IN_Idle_o;
        REL_DW.SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (REL_DW.is_RlsReq == REL_IN_Idle_o) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_ConstB.DataTypeConversion14 == Gear_P)) &&
          ((SL_b_DoorInBtnValid_prev != REL_DW.SL_b_DoorInBtnValid_start) &&
           REL_DW.SL_b_DoorInBtnValid_start)) {
        REL_DW.is_RlsReq = REL_IN_Trigger;
        switch (rtb_DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger = REL_IN_DoorLock;
          REL_DW.is_DoorLock = REL_IN_UnlockReq;
          REL_DW.temporalCounter_i1_i = 0U;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger = REL_IN_DoorUnlock;
          break;

         default:
          REL_DW.is_Trigger = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_ConstB.DataTypeConversion14 != Gear_P)) ||
               ((rtb_DataTypeConversion13 == Door_Unlock) &&
                (rtb_SO_m_RLDoorRatSts == Rat_Unlock))) {
      REL_DW.is_DoorLock = 0;
      REL_DW.is_Trigger = 0;
      REL_DW.is_RlsReq = REL_IN_Idle_o;
    } else {
      switch (REL_DW.is_Trigger) {
       case REL_IN_DoorLock:
        switch (REL_DW.is_DoorLock) {
         case REL_IN_UnlockFail:
          REL_DW.is_DoorLock = 0;
          REL_DW.is_Trigger = 0;
          REL_DW.is_RlsReq = REL_IN_Idle_o;
          break;

         case REL_IN_UnlockReq:
          if (rtb_DataTypeConversion13 == Door_Unlock) {
            REL_DW.is_DoorLock = REL_IN_UnlockSuccess;
          } else if ((REL_DW.temporalCounter_i1_i >= 50) &&
                     (rtb_DataTypeConversion13 == Door_Lock)) {
            REL_DW.is_DoorLock = REL_IN_UnlockFail;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtb_SO_m_RLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock = 0;
            REL_DW.is_Trigger = REL_IN_Release_b;
            REL_DW.temporalCounter_i1_i = 0U;
            REL_B.SO_b_DoorRlsReq = true;
            REL_B.SO_e_DoorRlsDelayTime = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtb_SO_m_RLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger = REL_IN_Release_b;
          REL_DW.temporalCounter_i1_i = 0U;
          REL_B.SO_b_DoorRlsReq = true;
          REL_B.SO_e_DoorRlsDelayTime = 50U;
        }
        break;

       case REL_IN_Error:
        REL_DW.is_Trigger = 0;
        REL_DW.is_RlsReq = REL_IN_Idle_o;
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i1_i >= 5) {
          REL_B.SO_b_DoorRlsReq = false;
          REL_B.SO_e_DoorRlsDelayTime = 0U;
          REL_DW.is_Trigger = 0;
          REL_DW.is_RlsReq = REL_IN_Idle_o;
        }
        break;
      }
    }

    if (REL_DW.is_RlsReq_c == REL_IN_Idle_o) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_ConstB.DataTypeConversion14 == Gear_P)) &&
          ((SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start) &&
           REL_DW.SL_b_DoorHndBtnValid_start)) {
        REL_DW.is_RlsReq_c = REL_IN_Trigger;
        switch (rtb_DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger_f = REL_IN_DoorLock;
          REL_DW.is_DoorLock_a = REL_IN_UnlockReq;
          REL_DW.temporalCounter_i2 = 0U;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_f = REL_IN_DoorUnlock;
          break;

         default:
          REL_DW.is_Trigger_f = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_ConstB.DataTypeConversion14 != Gear_P)) ||
               ((rtb_DataTypeConversion13 == Door_Unlock) &&
                (rtb_SO_m_RLDoorRatSts == Rat_Unlock))) {
      REL_DW.is_DoorLock_a = 0;
      REL_DW.is_Trigger_f = 0;
      REL_DW.is_RlsReq_c = REL_IN_Idle_o;
    } else {
      switch (REL_DW.is_Trigger_f) {
       case REL_IN_DoorLock:
        switch (REL_DW.is_DoorLock_a) {
         case REL_IN_UnlockFail:
          REL_DW.is_DoorLock_a = 0;
          REL_DW.is_Trigger_f = 0;
          REL_DW.is_RlsReq_c = REL_IN_Idle_o;
          break;

         case REL_IN_UnlockReq:
          if (rtb_DataTypeConversion13 == Door_Unlock) {
            REL_DW.is_DoorLock_a = REL_IN_UnlockSuccess;
          } else if ((REL_DW.temporalCounter_i2 >= 50) &&
                     (rtb_DataTypeConversion13 == Door_Lock)) {
            REL_DW.is_DoorLock_a = REL_IN_UnlockFail;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtb_SO_m_RLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_a = 0;
            REL_DW.is_Trigger_f = REL_IN_Release_b;
            REL_DW.temporalCounter_i2 = 0U;
            REL_B.SO_b_DoorRlsReq = true;
            REL_B.SO_e_DoorRlsDelayTime = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtb_SO_m_RLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_f = REL_IN_Release_b;
          REL_DW.temporalCounter_i2 = 0U;
          REL_B.SO_b_DoorRlsReq = true;
          REL_B.SO_e_DoorRlsDelayTime = 50U;
        }
        break;

       case REL_IN_Error:
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i2 >= 5) {
          REL_B.SO_b_DoorRlsReq = false;
          REL_B.SO_e_DoorRlsDelayTime = 0U;
          REL_DW.is_Trigger_f = 0;
          REL_DW.is_RlsReq_c = REL_IN_Idle_o;
        }
        break;
      }
    }

    switch (REL_DW.is_SwValid_b) {
     case REL_IN_Idle_o:
      if ((SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
          REL_DW.SI_b_DoorHndBtnSts_start) {
        REL_DW.is_SwValid_b = REL_IN_Press;
        REL_DW.temporalCounter_i4 = 0U;
      }
      break;

     case REL_IN_Press:
      if ((SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start) &&
          (!REL_DW.SI_b_DoorHndBtnSts_start)) {
        REL_DW.is_SwValid_b = REL_IN_Release_bx;
        REL_DW.temporalCounter_i4 = 0U;
        REL_DW.SL_b_DoorHndBtnValid = true;
      } else if (REL_DW.temporalCounter_i4 >= 100) {
        REL_DW.is_SwValid_b = REL_IN_Idle_o;
        REL_DW.SL_b_DoorHndBtnValid = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i4 >= 3) {
        REL_DW.is_SwValid_b = REL_IN_Idle_o;
        REL_DW.SL_b_DoorHndBtnValid = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/RLDoorRlsReq' */

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant3'
   *  Outport: '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg'
   */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq,
                      REL_Y.VbOUT_REL_RLDoorAjarSwitch_flg_,
                      REL_Y.VbOUT_REL_RLDoorOpenSwitch_flg_, false, false,
                      REL_B.SO_e_DoorRlsDelayTime,
                      &REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU,
                      &REL_B.SO_e_MotorCmd, &SI_b_CrashSts_prev, &SO_e_MotorPwm,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  REL_Y.VeOUT_REL_RLReleaseLatchStatus_ = REL_B.SO_e_MotorCmd;

  /* DataTypeConversion: '<S3>/Data Type Conversion12' incorporates:
   *  Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig'
   */
  rtb_DataTypeConversion13 = REL_U.VeOUT_DLK_LHFDoorLockSts_sig_Ve;

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg'
   */
  if (REL_DW.temporalCounter_i1_g < 63U) {
    REL_DW.temporalCounter_i1_g++;
  }

  if (REL_DW.temporalCounter_i2_b < 63U) {
    REL_DW.temporalCounter_i2_b++;
  }

  if (REL_DW.temporalCounter_i3_g < 255U) {
    REL_DW.temporalCounter_i3_g++;
  }

  if (REL_DW.temporalCounter_i4_c < 127U) {
    REL_DW.temporalCounter_i4_c++;
  }

  SI_b_CrashSts_prev = REL_DW.SI_b_DoorInBtnSts_start_a;
  REL_DW.SI_b_DoorInBtnSts_start_a = REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f;
  SL_b_DoorInBtnValid_prev = REL_DW.SL_b_DoorInBtnValid_start_c;
  REL_DW.SL_b_DoorInBtnValid_start_c = REL_DW.SL_b_DoorInBtnValid_e;
  SI_b_DoorHndBtnSts_prev = REL_DW.SI_b_DoorHndBtnSts_start_l;
  REL_DW.SI_b_DoorHndBtnSts_start_l = REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_;
  SL_b_DoorHndBtnValid_prev = REL_DW.SL_b_DoorHndBtnValid_start_l;
  REL_DW.SL_b_DoorHndBtnValid_start_l = REL_DW.SL_b_DoorHndBtnValid_g;
  if (REL_DW.is_active_c5_DoorRlsReq_c == 0U) {
    REL_DW.is_active_c5_DoorRlsReq_c = 1U;
    REL_DW.is_SwValid_e = REL_IN_Idle_o;
    REL_DW.SL_b_DoorInBtnValid_e = false;
    REL_DW.is_RlsReq_p = REL_IN_Idle_o;
    REL_DW.is_RlsReq_l = REL_IN_Idle_o;
    REL_DW.is_SwValid_n = REL_IN_Idle_o;
    REL_DW.SL_b_DoorHndBtnValid_g = false;
  } else {
    switch (REL_DW.is_SwValid_e) {
     case REL_IN_Idle_o:
      if ((SI_b_CrashSts_prev != REL_DW.SI_b_DoorInBtnSts_start_a) &&
          REL_DW.SI_b_DoorInBtnSts_start_a) {
        REL_DW.is_SwValid_e = REL_IN_Once;
        REL_DW.temporalCounter_i3_g = 0U;
      }
      break;

     case REL_IN_Once:
      if ((SI_b_CrashSts_prev != REL_DW.SI_b_DoorInBtnSts_start_a) &&
          REL_DW.SI_b_DoorInBtnSts_start_a) {
        REL_DW.is_SwValid_e = REL_IN_Twice;
        REL_DW.temporalCounter_i3_g = 0U;
        REL_DW.SL_b_DoorInBtnValid_e = true;
      } else if (REL_DW.temporalCounter_i3_g >= 200) {
        REL_DW.is_SwValid_e = REL_IN_Idle_o;
        REL_DW.SL_b_DoorInBtnValid_e = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (REL_DW.temporalCounter_i3_g >= 3) {
        REL_DW.is_SwValid_e = REL_IN_Idle_o;
        REL_DW.SL_b_DoorInBtnValid_e = false;
      }
      break;
    }

    if (REL_DW.is_RlsReq_p == REL_IN_Idle_o) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_ConstB.DataTypeConversion14 == Gear_P)) &&
          ((SL_b_DoorInBtnValid_prev != REL_DW.SL_b_DoorInBtnValid_start_c) &&
           REL_DW.SL_b_DoorInBtnValid_start_c)) {
        REL_DW.is_RlsReq_p = REL_IN_Trigger;
        switch (rtb_DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger_n = REL_IN_DoorLock;
          REL_DW.is_DoorLock_g = REL_IN_UnlockReq;
          REL_DW.temporalCounter_i1_g = 0U;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_n = REL_IN_DoorUnlock;
          break;

         default:
          REL_DW.is_Trigger_n = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_ConstB.DataTypeConversion14 != Gear_P)) ||
               ((rtb_DataTypeConversion13 == Door_Unlock) &&
                (rtb_SO_m_FLDoorRatSts == Rat_Unlock))) {
      REL_DW.is_DoorLock_g = 0;
      REL_DW.is_Trigger_n = 0;
      REL_DW.is_RlsReq_p = REL_IN_Idle_o;
    } else {
      switch (REL_DW.is_Trigger_n) {
       case REL_IN_DoorLock:
        switch (REL_DW.is_DoorLock_g) {
         case REL_IN_UnlockFail:
          REL_DW.is_DoorLock_g = 0;
          REL_DW.is_Trigger_n = 0;
          REL_DW.is_RlsReq_p = REL_IN_Idle_o;
          break;

         case REL_IN_UnlockReq:
          if (rtb_DataTypeConversion13 == Door_Unlock) {
            REL_DW.is_DoorLock_g = REL_IN_UnlockSuccess;
          } else if ((REL_DW.temporalCounter_i1_g >= 50) &&
                     (rtb_DataTypeConversion13 == Door_Lock)) {
            REL_DW.is_DoorLock_g = REL_IN_UnlockFail;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtb_SO_m_FLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_g = 0;
            REL_DW.is_Trigger_n = REL_IN_Release_b;
            REL_DW.temporalCounter_i1_g = 0U;
            REL_B.SO_b_DoorRlsReq_l = true;
            REL_B.SO_e_DoorRlsDelayTime_c = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtb_SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_n = REL_IN_Release_b;
          REL_DW.temporalCounter_i1_g = 0U;
          REL_B.SO_b_DoorRlsReq_l = true;
          REL_B.SO_e_DoorRlsDelayTime_c = 50U;
        }
        break;

       case REL_IN_Error:
        REL_DW.is_Trigger_n = 0;
        REL_DW.is_RlsReq_p = REL_IN_Idle_o;
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i1_g >= 5) {
          REL_B.SO_b_DoorRlsReq_l = false;
          REL_B.SO_e_DoorRlsDelayTime_c = 0U;
          REL_DW.is_Trigger_n = 0;
          REL_DW.is_RlsReq_p = REL_IN_Idle_o;
        }
        break;
      }
    }

    if (REL_DW.is_RlsReq_l == REL_IN_Idle_o) {
      if ((((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP <= 0) &&
            (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN)) ||
           (REL_ConstB.DataTypeConversion14 == Gear_P)) &&
          ((SL_b_DoorHndBtnValid_prev != REL_DW.SL_b_DoorHndBtnValid_start_l) &&
           REL_DW.SL_b_DoorHndBtnValid_start_l)) {
        REL_DW.is_RlsReq_l = REL_IN_Trigger;
        switch (rtb_DataTypeConversion13) {
         case Door_Lock:
          REL_DW.is_Trigger_k = REL_IN_DoorLock;
          REL_DW.is_DoorLock_c = REL_IN_UnlockReq;
          REL_DW.temporalCounter_i2_b = 0U;
          break;

         case Door_Unlock:
          REL_DW.is_Trigger_k = REL_IN_DoorUnlock;
          break;

         default:
          REL_DW.is_Trigger_k = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP >= 1) &&
                (!REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN) &&
                (REL_ConstB.DataTypeConversion14 != Gear_P)) ||
               ((rtb_DataTypeConversion13 == Door_Unlock) &&
                (rtb_SO_m_FLDoorRatSts == Rat_Unlock))) {
      REL_DW.is_DoorLock_c = 0;
      REL_DW.is_Trigger_k = 0;
      REL_DW.is_RlsReq_l = REL_IN_Idle_o;
    } else {
      switch (REL_DW.is_Trigger_k) {
       case REL_IN_DoorLock:
        switch (REL_DW.is_DoorLock_c) {
         case REL_IN_UnlockFail:
          REL_DW.is_DoorLock_c = 0;
          REL_DW.is_Trigger_k = 0;
          REL_DW.is_RlsReq_l = REL_IN_Idle_o;
          break;

         case REL_IN_UnlockReq:
          if (rtb_DataTypeConversion13 == Door_Unlock) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockSuccess;
          } else if ((REL_DW.temporalCounter_i2_b >= 50) &&
                     (rtb_DataTypeConversion13 == Door_Lock)) {
            REL_DW.is_DoorLock_c = REL_IN_UnlockFail;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtb_SO_m_FLDoorRatSts != Rat_Unlock) {
            REL_DW.is_DoorLock_c = 0;
            REL_DW.is_Trigger_k = REL_IN_Release_b;
            REL_DW.temporalCounter_i2_b = 0U;
            REL_B.SO_b_DoorRlsReq_l = true;
            REL_B.SO_e_DoorRlsDelayTime_c = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtb_SO_m_FLDoorRatSts != Rat_Unlock) {
          REL_DW.is_Trigger_k = REL_IN_Release_b;
          REL_DW.temporalCounter_i2_b = 0U;
          REL_B.SO_b_DoorRlsReq_l = true;
          REL_B.SO_e_DoorRlsDelayTime_c = 50U;
        }
        break;

       case REL_IN_Error:
        break;

       default:
        /* case IN_Release: */
        if (REL_DW.temporalCounter_i2_b >= 5) {
          REL_B.SO_b_DoorRlsReq_l = false;
          REL_B.SO_e_DoorRlsDelayTime_c = 0U;
          REL_DW.is_Trigger_k = 0;
          REL_DW.is_RlsReq_l = REL_IN_Idle_o;
        }
        break;
      }
    }

    switch (REL_DW.is_SwValid_n) {
     case REL_IN_Idle_o:
      if ((SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start_l) &&
          REL_DW.SI_b_DoorHndBtnSts_start_l) {
        REL_DW.is_SwValid_n = REL_IN_Press;
        REL_DW.temporalCounter_i4_c = 0U;
      }
      break;

     case REL_IN_Press:
      if ((SI_b_DoorHndBtnSts_prev != REL_DW.SI_b_DoorHndBtnSts_start_l) &&
          (!REL_DW.SI_b_DoorHndBtnSts_start_l)) {
        REL_DW.is_SwValid_n = REL_IN_Release_bx;
        REL_DW.temporalCounter_i4_c = 0U;
        REL_DW.SL_b_DoorHndBtnValid_g = true;
      } else if (REL_DW.temporalCounter_i4_c >= 100) {
        REL_DW.is_SwValid_n = REL_IN_Idle_o;
        REL_DW.SL_b_DoorHndBtnValid_g = false;
      }
      break;

     default:
      /* case IN_Release: */
      if (REL_DW.temporalCounter_i4_c >= 3) {
        REL_DW.is_SwValid_n = REL_IN_Idle_o;
        REL_DW.SL_b_DoorHndBtnValid_g = false;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Outport: '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg'
   */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_l,
                      REL_Y.VbOUT_REL_FLDoorAjarSwitch_flg_,
                      REL_Y.VbOUT_REL_FLDoorOpenSwitch_flg_, false, false,
                      REL_B.SO_e_DoorRlsDelayTime_c,
                      &REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
                      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU,
                      &REL_B.SO_e_MotorCmd_j, &SI_b_CrashSts_prev,
                      &SO_e_MotorPwm, &REL_DW.sf_FLDoorRlsDriver);

  /* Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   */
  REL_Y.VeOUT_REL_FLReleaseLatchStatus_ = REL_B.SO_e_MotorCmd_j;

  /* Outport: '<Root>/VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig' incorporates:
   *  Inport: '<Root>/VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig'
   *  SignalConversion generated from: '<S2>/VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig_read'
   */
  REL_Y.VeOUT_REL_RLChildrenProtectSwit = REL_U.VeINP_HWA_LRChildrenProtectSwit;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig' */
  REL_Y.VeOUT_REL_HandleSwitchStsFL_sig = 0U;

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig' */
  REL_Y.VeOUT_REL_HandleSwitchStsRR_sig = 0U;
}

/* Model initialize function */
void REL_initialize(void)
{
  {
    uint8_T SO_e_MotorPwm_e;
    boolean_T SO_b_Error_i;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU, &REL_B.SO_e_MotorCmd_j,
      &SO_b_Error_i, &SO_e_MotorPwm_e);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg'
     *  Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU,
      &REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU, &REL_B.SO_e_MotorCmd,
      &SO_b_Error_i, &SO_e_MotorPwm_e);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */
  }
}

/* Model terminate function */
void REL_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
