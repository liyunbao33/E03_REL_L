/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct 16 17:53:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "REL.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "REL_types.h"
#include "REL_private.h"

/* Named constants for Chart: '<S3>/FLDoorRlsDriver' */
#define REL_IN_ElectricDoor            ((uint8_T)1U)
#define REL_IN_Idle                    ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define REL_IN_NonElectricDoor         ((uint8_T)2U)
#define REL_IN_Normal                  ((uint8_T)1U)
#define REL_IN_PowerOn                 ((uint8_T)2U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8_T)1U)
#define REL_IN_DoorUnlock              ((uint8_T)2U)
#define REL_IN_DoorUnlock_e            ((uint8_T)1U)
#define REL_IN_Error                   ((uint8_T)3U)
#define REL_IN_Idle_p                  ((uint8_T)1U)
#define REL_IN_NO_ACTIVE_CHILD_e       ((uint8_T)0U)
#define REL_IN_Once                    ((uint8_T)2U)
#define REL_IN_Release                 ((uint8_T)4U)
#define REL_IN_Release_f               ((uint8_T)2U)
#define REL_IN_Trigger                 ((uint8_T)2U)
#define REL_IN_Twice                   ((uint8_T)3U)
#define REL_IN_UnlockFail              ((uint8_T)1U)
#define REL_IN_UnlockReq               ((uint8_T)2U)
#define REL_IN_UnlockSuccess           ((uint8_T)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8_T)1U)
#define REL_IN_NoCrash                 ((uint8_T)2U)

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
static void REL_exit_internal_Normal(DW_FLDoorRlsDriver_REL_T *localDW);
static void REL_Normal(boolean_T rtu_SI_b_ElecDoorCfg, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T
  *localDW);

/* Forward declaration for local functions */
static real_T REL_GetDoorRatSts(real_T ajar, real_T open);
static uint8_T REL_safe_cast_to_Rat_Sts_E(uint8_T input);

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_exit_internal_Normal(DW_FLDoorRlsDriver_REL_T *localDW)
{
  localDW->is_Step2_Open_g = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_Release_j = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_MainProgress_i = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_Step2_Open = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_Release = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_MainProgress = REL_IN_NO_ACTIVE_CHILD;
  localDW->is_Normal = REL_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_Normal(boolean_T rtu_SI_b_ElecDoorCfg, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T
  *localDW)
{
  if (!rtu_SI_b_ElecDoorCfg) {
    /*  非电动门  */
    REL_exit_internal_Normal(localDW);
    localDW->is_Normal = REL_IN_NonElectricDoor;
    localDW->is_MainProgress = REL_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    /*  电动门  */
    REL_exit_internal_Normal(localDW);
    localDW->is_Normal = REL_IN_ElectricDoor;
    localDW->is_MainProgress_i = REL_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 */
void REL_FLDoorRlsDriver_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRlsDriver'
 *    '<S3>/RLDoorRlsDriver'
 */
void REL_FLDoorRlsDriver(boolean_T rtu_SO_b_DoorRlsReq, boolean_T
  rtu_SI_b_ElecDoorCfg, uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
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

    /*  上电释放电机执行一次复位  */
    *rty_SO_e_MotorCmd = 2U;
    *rty_SO_e_MotorPwm = 100U;
  } else if (localDW->is_c19_DoorRlsDriver == REL_IN_Normal) {
    REL_Normal(rtu_SI_b_ElecDoorCfg, rty_SO_e_MotorCmd, rty_SO_e_MotorPwm,
               localDW);

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 30) {
    localDW->is_c19_DoorRlsDriver = REL_IN_Normal;
    localDW->is_Normal = REL_IN_NonElectricDoor;
    localDW->is_MainProgress = REL_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsReq'
 *    '<S3>/RLDoorRlsReq'
 */
void REL_FLDoorRlsReq_Init(boolean_T *rty_SO_b_DoorRlsReq, uint8_T
  *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E *rty_SO_m_UnlockReq)
{
  *rty_SO_b_DoorRlsReq = false;
  *rty_SO_e_DoorRlsDelayTime = 0U;
  *rty_SO_m_UnlockReq = Unlock_Idle;
}

/*
 * Output and update for atomic system:
 *    '<S3>/FLDoorRlsReq'
 *    '<S3>/RLDoorRlsReq'
 */
void REL_FLDoorRlsReq(UInt8 rtu_SI_e_EspVehSpd, Boolean rtu_SI_b_EspVehSpdVld,
                      Door_Sts_E rtu_SI_m_DoorLockSts, Rat_Sts_E
                      rtu_SI_m_DoorRatSts, boolean_T rtu_SI_b_DoorInBtnSts,
                      boolean_T rtu_SI_b_DoorHndBtnSts, Child_Sts_E
                      rtu_SI_m_ChildLckSts, boolean_T *rty_SO_b_DoorRlsReq,
                      uint8_T *rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
                      *rty_SO_m_UnlockReq, DW_FLDoorRlsReq_REL_T *localDW)
{
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->temporalCounter_i2 < 255U) {
    localDW->temporalCounter_i2++;
  }

  if (localDW->temporalCounter_i3 < 7U) {
    localDW->temporalCounter_i3++;
  }

  localDW->SI_b_DoorInBtnSts_prev = localDW->SI_b_DoorInBtnSts_start;
  localDW->SI_b_DoorInBtnSts_start = rtu_SI_b_DoorInBtnSts;
  localDW->SL_b_DoorInBtnValid_prev = localDW->SL_b_DoorInBtnValid_start;
  localDW->SL_b_DoorInBtnValid_start = localDW->SL_b_DoorInBtnValid;
  localDW->SL_b_DoorHndBtnValid_prev = localDW->SL_b_DoorHndBtnValid_start;
  localDW->SL_b_DoorHndBtnValid_start = localDW->SL_b_DoorHndBtnValid;

  /* Chart: '<S3>/FLDoorRlsReq' */
  if (localDW->is_active_c5_DoorRlsReq == 0U) {
    localDW->SI_b_DoorInBtnSts_prev = rtu_SI_b_DoorInBtnSts;
    localDW->is_active_c5_DoorRlsReq = 1U;
    localDW->is_SwValid = REL_IN_Idle_p;
    localDW->SL_b_DoorInBtnValid = false;
    localDW->is_RlsReq = REL_IN_Idle_p;
    localDW->is_RlsReq_f = REL_IN_Idle_p;
    localDW->SL_b_DoorHndBtnValid = rtu_SI_b_DoorHndBtnSts;
  } else {
    switch (localDW->is_SwValid) {
     case REL_IN_Idle_p:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Once;
        localDW->temporalCounter_i2 = 0U;
      }
      break;

     case REL_IN_Once:
      if ((localDW->SI_b_DoorInBtnSts_prev != localDW->SI_b_DoorInBtnSts_start) &&
          localDW->SI_b_DoorInBtnSts_start) {
        localDW->is_SwValid = REL_IN_Twice;
        localDW->temporalCounter_i2 = 0U;
        localDW->SL_b_DoorInBtnValid = true;
      } else if (localDW->temporalCounter_i2 >= 200) {
        localDW->is_SwValid = REL_IN_Idle_p;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;

     default:
      /* case IN_Twice: */
      if (localDW->temporalCounter_i2 >= 3) {
        localDW->is_SwValid = REL_IN_Idle_p;
        localDW->SL_b_DoorInBtnValid = false;
      }
      break;
    }

    if (localDW->is_RlsReq == REL_IN_Idle_p) {
      if ((rtu_SI_e_EspVehSpd < 5) && (!rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_m_ChildLckSts == Child_Unlock) &&
          ((localDW->SL_b_DoorInBtnValid_prev !=
            localDW->SL_b_DoorInBtnValid_start) &&
           localDW->SL_b_DoorInBtnValid_start)) {
        localDW->is_RlsReq = REL_IN_Trigger;
        switch (rtu_SI_m_DoorLockSts) {
         case Door_Lock:
          localDW->is_Trigger = REL_IN_DoorLock;
          localDW->is_DoorLock = REL_IN_UnlockReq;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_m_UnlockReq = Unlock_Req;
          break;

         case Door_Unlock:
          localDW->is_Trigger = REL_IN_DoorUnlock;
          break;

         default:
          localDW->is_Trigger = REL_IN_Error;
          break;
        }
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 5) && (!rtu_SI_b_EspVehSpdVld)) ||
               (rtu_SI_m_ChildLckSts != Child_Unlock) || ((rtu_SI_m_DoorLockSts ==
      Door_Unlock) && (rtu_SI_m_DoorRatSts == Rat_Unlock))) {
      localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_e;
      localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_e;
      localDW->is_RlsReq = REL_IN_Idle_p;
    } else {
      switch (localDW->is_Trigger) {
       case REL_IN_DoorLock:
        switch (localDW->is_DoorLock) {
         case REL_IN_UnlockFail:
          localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RlsReq = REL_IN_Idle_p;
          break;

         case REL_IN_UnlockReq:
          if (rtu_SI_m_DoorLockSts == Door_Unlock) {
            localDW->is_DoorLock = REL_IN_UnlockSuccess;
          } else if ((localDW->temporalCounter_i1 >= 50) &&
                     (rtu_SI_m_DoorLockSts == Door_Lock)) {
            localDW->is_DoorLock = REL_IN_UnlockFail;
          } else if (localDW->temporalCounter_i1 == 5) {
            *rty_SO_m_UnlockReq = Unlock_Idle;
          }
          break;

         default:
          /* case IN_UnlockSuccess: */
          if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
            localDW->is_DoorLock = REL_IN_NO_ACTIVE_CHILD_e;
            localDW->is_Trigger = REL_IN_Release;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_DoorRlsReq = true;
            *rty_SO_e_DoorRlsDelayTime = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger = REL_IN_Release;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_DoorRlsReq = true;
          *rty_SO_e_DoorRlsDelayTime = 50U;
        }
        break;

       case REL_IN_Error:
        localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_e;
        localDW->is_RlsReq = REL_IN_Idle_p;
        break;

       default:
        /* case IN_Release: */
        if (localDW->temporalCounter_i1 >= 5) {
          *rty_SO_b_DoorRlsReq = false;
          *rty_SO_e_DoorRlsDelayTime = 0U;
          localDW->is_Trigger = REL_IN_NO_ACTIVE_CHILD_e;
          localDW->is_RlsReq = REL_IN_Idle_p;
        }
        break;
      }
    }

    if (localDW->is_RlsReq_f == REL_IN_Idle_p) {
      if ((rtu_SI_e_EspVehSpd < 5) && (!rtu_SI_b_EspVehSpdVld) &&
          (rtu_SI_m_DoorLockSts == Door_Unlock) &&
          ((localDW->SL_b_DoorHndBtnValid_prev !=
            localDW->SL_b_DoorHndBtnValid_start) &&
           localDW->SL_b_DoorHndBtnValid_start)) {
        localDW->is_RlsReq_f = REL_IN_Trigger;
        localDW->is_Trigger_h = REL_IN_DoorUnlock_e;
      }

      /* case IN_Trigger: */
    } else if (((rtu_SI_e_EspVehSpd >= 5) && (!rtu_SI_b_EspVehSpdVld)) ||
               (rtu_SI_m_DoorLockSts != Door_Unlock) || (rtu_SI_m_DoorRatSts ==
                Rat_Unlock)) {
      localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_e;
      localDW->is_RlsReq_f = REL_IN_Idle_p;
    } else if (localDW->is_Trigger_h == REL_IN_DoorUnlock_e) {
      if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
        localDW->is_Trigger_h = REL_IN_Release_f;
        localDW->temporalCounter_i3 = 0U;
        *rty_SO_b_DoorRlsReq = true;
        *rty_SO_e_DoorRlsDelayTime = 50U;
      }

      /* case IN_Release: */
    } else if (localDW->temporalCounter_i3 >= 5) {
      *rty_SO_b_DoorRlsReq = false;
      *rty_SO_e_DoorRlsDelayTime = 0U;
      localDW->is_Trigger_h = REL_IN_NO_ACTIVE_CHILD_e;
      localDW->is_RlsReq_f = REL_IN_Idle_p;
    }

    localDW->SL_b_DoorHndBtnValid = rtu_SI_b_DoorHndBtnSts;
  }

  /* End of Chart: '<S3>/FLDoorRlsReq' */
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
  Child_Sts_E rtb_DataTypeConversion2;
  Rat_Sts_E rtb_SO_m_FLDoorRatSts;
  Rat_Sts_E rtb_SO_m_RLDoorRatSts;
  Unlock_Req_E SO_m_UnlockReq_l;
  uint8_T SO_e_MotorPwm_m;
  boolean_T SI_b_CrashSts_prev;

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
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

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg'
   */
  REL_FLDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeOUT_DLK_LHFDoorLockSts_sig_Ve, rtb_SO_m_FLDoorRatSts,
                   REL_Y.VbOUT_REL_FLLockReleaseInsdSW_f,
                   REL_Y.VbOUT_REL_FLLockReleaseOutsdSW_, Child_Unlock,
                   &REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime_b, &SO_m_UnlockReq_l,
                   &REL_DW.sf_FLDoorRlsReq);

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU, false,
                      &REL_Y.VeOUT_REL_FLReleaseLatchStatus_, &SO_e_MotorPwm_m,
                      &REL_DW.sf_FLDoorRlsDriver);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' incorporates:
   *  Constant: '<S4>/Constant'
   *  Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig'
   *  RelationalOperator: '<S4>/Compare'
   */
  REL_Y.VbOUT_REL_FLDoorMotorA_flg_VbOU = (REL_Y.VeOUT_REL_FLReleaseLatchStatus_
    == 1);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' incorporates:
   *  Constant: '<S5>/Constant'
   *  Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig'
   *  RelationalOperator: '<S5>/Compare'
   */
  REL_Y.VbOUT_REL_FLDoorMotorB_flg_VbOU = (REL_Y.VeOUT_REL_FLReleaseLatchStatus_
    == 2);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig'
   */
  rtb_DataTypeConversion2 = REL_U.VeINP_HWA_LRChildrenProtectSwit;

  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   *  Inport: '<Root>/VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig'
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg'
   *  Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg'
   */
  REL_FLDoorRlsReq(REL_U.VeOUT_SP_EspVehSpd_kmh_VeOUT_SP,
                   REL_U.VbINP_CAN_EspVehSpdVld_flg_VbIN,
                   REL_U.VeOUT_DLK_LHRDoorLockSts_sig_Ve, rtb_SO_m_RLDoorRatSts,
                   REL_Y.VbOUT_REL_RLLockReleaseInsdSW_f,
                   REL_Y.VbOUT_REL_RLLockReleaseOutsdSW_,
                   rtb_DataTypeConversion2,
                   &REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                   &REL_B.SO_e_DoorRlsDelayTime, &SO_m_UnlockReq_l,
                   &REL_DW.sf_RLDoorRlsReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Outport: '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg'
   *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
   *  Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig'
   */
  REL_FLDoorRlsDriver(REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU, false,
                      &REL_Y.VeOUT_REL_RLReleaseLatchStatus_, &SO_e_MotorPwm_m,
                      &REL_DW.sf_RLDoorRlsDriver);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' incorporates:
   *  Constant: '<S6>/Constant'
   *  Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig'
   *  RelationalOperator: '<S6>/Compare'
   */
  REL_Y.VbOUT_REL_RLDoorMotorA_flg_VbOU = (REL_Y.VeOUT_REL_RLReleaseLatchStatus_
    == 1);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' incorporates:
   *  Constant: '<S7>/Constant'
   *  Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig'
   *  RelationalOperator: '<S7>/Compare'
   */
  REL_Y.VbOUT_REL_RLDoorMotorB_flg_VbOU = (REL_Y.VeOUT_REL_RLReleaseLatchStatus_
    == 2);

  /* Outport: '<Root>/VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_Y.VeOUT_REL_RLChildrenProtectSwit = rtb_DataTypeConversion2;

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
    Unlock_Req_E SO_m_UnlockReq_l;
    uint8_T SO_e_MotorPwm_m;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_FLReleaseLatchStatus_,
      &SO_e_MotorPwm_m, &REL_B.SO_b_Error_l);

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg'
     */
    REL_FLDoorRlsReq_Init(&REL_Y.VbOUT_REL_FLDoorRlsReq_flg_VbOU,
                          &REL_B.SO_e_DoorRlsDelayTime_b, &SO_m_UnlockReq_l);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' incorporates:
     *  Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig'
     */
    REL_FLDoorRlsDriver_Init(&REL_Y.VeOUT_REL_RLReleaseLatchStatus_,
      &SO_e_MotorPwm_m, &REL_B.SO_b_Error);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' incorporates:
     *  Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg'
     */
    REL_FLDoorRlsReq_Init(&REL_Y.VbOUT_REL_RLDoorRlsReq_flg_VbOU,
                          &REL_B.SO_e_DoorRlsDelayTime, &SO_m_UnlockReq_l);

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
