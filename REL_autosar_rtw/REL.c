/*
 * File: REL.c
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 10:01:18 2023
 *
 * Target selection: autosar.tlc
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
#define REL_IN_Checking                ((uint8)1U)
#define REL_IN_Delay                   ((uint8)2U)
#define REL_IN_ElectricDoor            ((uint8)1U)
#define REL_IN_Fail                    ((uint8)1U)
#define REL_IN_Fail1                   ((uint8)2U)
#define REL_IN_Ice_Break               ((uint8)3U)
#define REL_IN_Idle                    ((uint8)1U)
#define REL_IN_Idle_m                  ((uint8)4U)
#define REL_IN_LastCheck               ((uint8)2U)
#define REL_IN_LastCheck_p             ((uint8)5U)
#define REL_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define REL_IN_NonElectricDoor         ((uint8)2U)
#define REL_IN_Normal                  ((uint8)1U)
#define REL_IN_PowerOn                 ((uint8)2U)
#define REL_IN_Release                 ((uint8)2U)
#define REL_IN_Reset                   ((uint8)3U)
#define REL_IN_Step1_Ajar              ((uint8)4U)
#define REL_IN_Step2_Open              ((uint8)5U)
#define REL_IN_Success                 ((uint8)6U)

/* Named constants for Chart: '<S3>/FLDoorRlsReq' */
#define REL_IN_DoorLock                ((uint8)1U)
#define REL_IN_DoorUnlock              ((uint8)2U)
#define REL_IN_DoorUnlock_e            ((uint8)1U)
#define REL_IN_Error                   ((uint8)3U)
#define REL_IN_Idle_p                  ((uint8)1U)
#define REL_IN_NO_ACTIVE_CHILD_e       ((uint8)0U)
#define REL_IN_Once                    ((uint8)2U)
#define REL_IN_Release_f               ((uint8)4U)
#define REL_IN_Release_fe              ((uint8)2U)
#define REL_IN_Trigger                 ((uint8)2U)
#define REL_IN_Twice                   ((uint8)3U)
#define REL_IN_UnlockFail              ((uint8)1U)
#define REL_IN_UnlockReq               ((uint8)2U)
#define REL_IN_UnlockSuccess           ((uint8)3U)

/* Named constants for Chart: '<S3>/DoorSwSts' */
#define REL_IN_Crash                   ((uint8)1U)
#define REL_IN_NoCrash                 ((uint8)2U)

/* Block signals (default storage) */
B_REL_T REL_B;

/* Block states (default storage) */
DW_REL_T REL_DW;

/* Forward declaration for local functions */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  boolean rtu_SI_b_CinchHome, uint8 rtu_SI_e_DoorRlsDelayTime, boolean
  *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T
  *localDW);

/* Forward declaration for local functions */
static float64 REL_GetDoorRatSts(float64 ajar, float64 open);
static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input);

/* Function for Chart: '<S3>/FLDoorRlsDriver' */
static void REL_Normal(Boolean rtu_SI_b_DoorAjar, Boolean rtu_SI_b_DoorOpen,
  boolean rtu_SI_b_CinchHome, uint8 rtu_SI_e_DoorRlsDelayTime, boolean
  *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T
  *localDW)
{
  if (localDW->is_Normal == REL_IN_ElectricDoor) {
    if (localDW->is_MainProgress_i == REL_IN_Idle) {
      if ((localDW->SO_b_DoorRlsReq_prev != localDW->SO_b_DoorRlsReq_start) &&
          localDW->SO_b_DoorRlsReq_start) {
        localDW->SL_e_DoorRlsDelayTime = rtu_SI_e_DoorRlsDelayTime;
        localDW->is_MainProgress_i = REL_IN_Release;
        localDW->SL_e_CycleCount = 0U;
        *rty_SO_e_MotorPwm = 100U;
        localDW->is_Release_j = REL_IN_Delay;
        localDW->temporalCounter_i1 = 0U;
      }
    } else {
      /* case IN_Release: */
      switch (localDW->is_Release_j) {
       case REL_IN_Checking:
        {
          if ((localDW->temporalCounter_i1 >= 5) && rtu_SI_b_DoorAjar) {
            localDW->is_Release_j = REL_IN_Step2_Open;
            localDW->is_Step2_Open_g = REL_IN_Idle_m;
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
              localDW->is_Release_j = REL_IN_Step1_Ajar;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_b_MotorA = true;
              *rty_SO_b_MotorB = false;
              *rty_SO_e_MotorCmd = Rls;
            } else if ((localDW->temporalCounter_i1 >= 5) && tmp_0 &&
                       (localDW->SL_e_CycleCount >= 2)) {
              localDW->is_Release_j = REL_IN_Reset;
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
          localDW->is_Release_j = REL_IN_Step1_Ajar;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = true;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Rls;
        }
        break;

       case REL_IN_Reset:
        if (localDW->temporalCounter_i1 >= 30) {
          localDW->is_Release_j = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_MainProgress_i = REL_IN_Idle;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          *rty_SO_e_MotorPwm = 0U;
        }
        break;

       case REL_IN_Step1_Ajar:
        {
          if (localDW->temporalCounter_i1 >= 30) {
            sint32 tmp;
            localDW->is_Release_j = REL_IN_Checking;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = false;
            *rty_SO_e_MotorCmd = Stop;
            tmp = localDW->SL_e_CycleCount + 1;
            if (localDW->SL_e_CycleCount + 1 > 255) {
              tmp = 255;
            }

            localDW->SL_e_CycleCount = (uint8)tmp;
          }
        }
        break;

       default:
        /* case IN_Step2_Open: */
        switch (localDW->is_Step2_Open_g) {
         case REL_IN_Fail:
          localDW->is_Step2_Open_g = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_j = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Fail1:
          localDW->is_Step2_Open_g = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_j = REL_IN_Reset;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = true;
          *rty_SO_e_MotorCmd = Reset;
          *rty_SO_e_MotorPwm = 100U;
          break;

         case REL_IN_Ice_Break:
          if ((localDW->temporalCounter_i1 < 600) && (!rtu_SI_b_CinchHome)) {
            localDW->is_Step2_Open_g = REL_IN_Success;
            *rty_SO_b_Error = false;
          } else if ((localDW->temporalCounter_i1 >= 600) && rtu_SI_b_CinchHome)
          {
            localDW->is_Step2_Open_g = REL_IN_Fail1;
            *rty_SO_b_Error = true;
          }
          break;

         case REL_IN_Idle_m:
          if ((localDW->temporalCounter_i1 < 270) && rtu_SI_b_DoorOpen) {
            localDW->is_Step2_Open_g = REL_IN_NO_ACTIVE_CHILD;
            localDW->is_Release_j = REL_IN_Reset;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_MotorA = false;
            *rty_SO_b_MotorB = true;
            *rty_SO_e_MotorCmd = Reset;
            *rty_SO_e_MotorPwm = 100U;
          } else if (localDW->temporalCounter_i1 >= 300) {
            localDW->is_Step2_Open_g = REL_IN_LastCheck_p;
          }
          break;

         case REL_IN_LastCheck_p:
          if (!rtu_SI_b_CinchHome) {
            localDW->is_Step2_Open_g = REL_IN_Fail;
            *rty_SO_b_Error = true;
          } else {
            localDW->is_Step2_Open_g = REL_IN_Ice_Break;
            localDW->temporalCounter_i1 = 0U;
          }
          break;

         default:
          /* case IN_Success: */
          localDW->is_Step2_Open_g = REL_IN_NO_ACTIVE_CHILD;
          localDW->is_Release_j = REL_IN_Reset;
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
          sint32 tmp;
          localDW->is_Release = REL_IN_Checking;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_b_MotorA = false;
          *rty_SO_b_MotorB = false;
          *rty_SO_e_MotorCmd = Stop;
          tmp = localDW->SL_e_CycleCount + 1;
          if (localDW->SL_e_CycleCount + 1 > 255) {
            tmp = 255;
          }

          localDW->SL_e_CycleCount = (uint8)tmp;
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
void REL_FLDoorRlsDriver_Init(boolean *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB,
  Mot_Cmd_E *rty_SO_e_MotorCmd, boolean *rty_SO_b_Error, uint8
  *rty_SO_e_MotorPwm)
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
void REL_FLDoorRlsDriver(boolean rtu_SO_b_DoorRlsReq, Boolean rtu_SI_b_DoorAjar,
  Boolean rtu_SI_b_DoorOpen, boolean rtu_SI_b_CinchHome, boolean
  rtu_SI_b_ElecDoorCfg, uint8 rtu_SI_e_DoorRlsDelayTime, boolean
  *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB, Mot_Cmd_E *rty_SO_e_MotorCmd,
  boolean *rty_SO_b_Error, uint8 *rty_SO_e_MotorPwm, DW_FLDoorRlsDriver_REL_T
  *localDW)
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
      localDW->is_MainProgress_i = REL_IN_Idle;
      *rty_SO_b_MotorA = false;
      *rty_SO_b_MotorB = false;
      *rty_SO_e_MotorCmd = Stop;
      *rty_SO_e_MotorPwm = 0U;
    }
  }

  /* End of Chart: '<S3>/FLDoorRlsDriver' */
}

/*
 * System initialize for atomic system:
 *    '<S3>/FLDoorRlsReq'
 *    '<S3>/RLDoorRlsReq'
 */
void REL_FLDoorRlsReq_Init(boolean *rty_SO_b_DoorRlsReq, uint8
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
                      rtu_SI_m_DoorRatSts, boolean rtu_SI_b_DoorInBtnSts,
                      boolean rtu_SI_b_DoorHndBtnSts, Child_Sts_E
                      rtu_SI_m_ChildLckSts, boolean *rty_SO_b_DoorRlsReq, uint8 *
                      rty_SO_e_DoorRlsDelayTime, Unlock_Req_E
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
            localDW->is_Trigger = REL_IN_Release_f;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_b_DoorRlsReq = true;
            *rty_SO_e_DoorRlsDelayTime = 50U;
          }
          break;
        }
        break;

       case REL_IN_DoorUnlock:
        if (rtu_SI_m_DoorRatSts != Rat_Unlock) {
          localDW->is_Trigger = REL_IN_Release_f;
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
        localDW->is_Trigger_h = REL_IN_Release_fe;
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
static float64 REL_GetDoorRatSts(float64 ajar, float64 open)
{
  float64 status;
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

static uint8 REL_safe_cast_to_Rat_Sts_E(uint8 input)
{
  uint8 output;

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
  /* local block i/o variables */
  UInt8 rtb_TmpSignalConversionAtVeOUT_;
  Boolean rtb_TmpSignalConversionAtVbINP_;
  Rat_Sts_E rtb_SO_m_FLDoorRatSts;
  Rat_Sts_E rtb_SO_m_RLDoorRatSts;
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  Unlock_Req_E SO_m_UnlockReq;
  uint8 SO_e_MotorPwm;
  uint8 SO_e_MotorPwm_l;
  boolean SO_b_Error;

  /* Inport: '<Root>/VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig
    (&SO_e_MotorPwm);

  /* SignalConversion generated from: '<S2>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg'
   */
  (void)Rte_Read_VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg
    (&REL_B.VbOUT_HWA_RLDoorFullOpen_flg_Vb);

  /* SignalConversion generated from: '<S2>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg'
   */
  (void)Rte_Read_VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg
    (&REL_B.VbOUT_HWA_FLDoorFullOpen_flg_Vb);

  /* Inport: '<Root>/VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig' */
  (void)
    Rte_Read_VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig
    (&tmpRead_0);

  /* Inport: '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  (void)Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg(&SO_b_Error);

  /* SignalConversion generated from: '<S2>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg'
   */
  (void)Rte_Read_VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg
    (&REL_B.VbOUT_SP_RLDoorAjarSts_flg_VbOU);

  /* SignalConversion generated from: '<S2>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg_read' incorporates:
   *  Inport: '<Root>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg'
   */
  (void)Rte_Read_VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg
    (&REL_B.VbOUT_SP_FLDoorAjarSts_flg_VbOU);

  /* Inport: '<Root>/VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig' */
  (void)Rte_Read_VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  REL_DW.E03_REL_L = 0U;

  /* Outport: '<Root>/VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)
    Rte_Write_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig
    (tmpRead_0);

  /* SignalConversion generated from: '<S2>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh_read' incorporates:
   *  Inport: '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh'
   */
  (void)Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh
    (&rtb_TmpSignalConversionAtVeOUT_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg'
   */
  (void)Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg
    (&rtb_TmpSignalConversionAtVbINP_);

  /* Chart: '<S3>/DoorRatSts' */
  if (REL_DW.is_active_c3_REL == 0U) {
    float64 tmp;
    REL_DW.is_active_c3_REL = 1U;
    tmp = REL_GetDoorRatSts((float64)REL_B.VbOUT_SP_FLDoorAjarSts_flg_VbOU,
      (float64)REL_B.VbOUT_HWA_FLDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.VbOUT_SP_RLDoorAjarSts_flg_VbOU,
      (float64)REL_B.VbOUT_HWA_RLDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  } else {
    float64 tmp;
    tmp = REL_GetDoorRatSts((float64)REL_B.VbOUT_SP_FLDoorAjarSts_flg_VbOU,
      (float64)REL_B.VbOUT_HWA_FLDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_FLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }

    tmp = REL_GetDoorRatSts((float64)REL_B.VbOUT_SP_RLDoorAjarSts_flg_VbOU,
      (float64)REL_B.VbOUT_HWA_RLDoorFullOpen_flg_Vb);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E((uint8)(sint32)tmp);
      } else {
        rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(0);
      }
    } else {
      rtb_SO_m_RLDoorRatSts = REL_safe_cast_to_Rat_Sts_E(MAX_uint8_T);
    }
  }

  /* End of Chart: '<S3>/DoorRatSts' */

  /* Chart: '<S3>/DoorSwSts' */
  if (REL_DW.temporalCounter_i1 < 1023U) {
    REL_DW.temporalCounter_i1++;
  }

  REL_DW.SI_b_CrashSts_prev = REL_DW.SI_b_CrashSts_start;
  REL_DW.SI_b_CrashSts_start = SO_b_Error;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
    (&REL_B.SL_b_FLDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
    (&REL_B.SL_b_RLDoorInBtnSts);

  /* Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg
    (&REL_B.SL_b_FLDoorHndBtnSts);

  /* Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  (void)Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg
    (&REL_B.SL_b_RLDoorHndBtnSts);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/DoorSwSts' incorporates:
   *  Inport: '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg'
   *  Inport: '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg'
   */
  if (REL_DW.is_active_c23_REL == 0U) {
    REL_DW.SI_b_CrashSts_prev = SO_b_Error;
    REL_DW.is_active_c23_REL = 1U;
    REL_DW.is_c23_REL = REL_IN_NoCrash;
  } else if (REL_DW.is_c23_REL == REL_IN_Crash) {
    if (REL_DW.temporalCounter_i1 >= 600) {
      REL_DW.is_c23_REL = REL_IN_NoCrash;
    } else {
      REL_B.SL_b_FLDoorInBtnSts = false;
      REL_B.SL_b_RLDoorInBtnSts = false;
      REL_B.SL_b_FLDoorHndBtnSts = false;
      REL_B.SL_b_RLDoorHndBtnSts = false;
    }

    /* case IN_NoCrash: */
  } else if ((REL_DW.SI_b_CrashSts_prev != REL_DW.SI_b_CrashSts_start) &&
             REL_DW.SI_b_CrashSts_start) {
    REL_DW.is_c23_REL = REL_IN_Crash;
    REL_DW.temporalCounter_i1 = 0U;
    REL_B.SL_b_FLDoorInBtnSts = false;
    REL_B.SL_b_RLDoorInBtnSts = false;
    REL_B.SL_b_FLDoorHndBtnSts = false;
    REL_B.SL_b_RLDoorHndBtnSts = false;
  }

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Inport: '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig' */
  (void)Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig
    (&SO_e_MotorPwm_l);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Chart: '<S3>/RLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  REL_FLDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, SO_e_MotorPwm,
                   rtb_SO_m_RLDoorRatSts, REL_B.SL_b_RLDoorInBtnSts,
                   REL_B.SL_b_RLDoorHndBtnSts, tmpRead_0, &REL_B.SO_b_DoorRlsReq,
                   &REL_B.SO_e_DoorRlsDelayTime, &SO_m_UnlockReq,
                   &REL_DW.sf_RLDoorRlsReq);

  /* Chart: '<S3>/RLDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant3'
   */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq,
                      REL_B.VbOUT_SP_RLDoorAjarSts_flg_VbOU,
                      REL_B.VbOUT_HWA_RLDoorFullOpen_flg_Vb, false, false,
                      REL_B.SO_e_DoorRlsDelayTime, &REL_B.SO_b_MotorA,
                      &REL_B.SO_b_MotorB, &REL_B.SO_e_MotorCmd, &SO_b_Error,
                      &SO_e_MotorPwm, &REL_DW.sf_RLDoorRlsDriver);

  /* Chart: '<S3>/FLDoorRlsReq' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion12'
   */
  REL_FLDoorRlsReq(rtb_TmpSignalConversionAtVeOUT_,
                   rtb_TmpSignalConversionAtVbINP_, SO_e_MotorPwm_l,
                   rtb_SO_m_FLDoorRatSts, REL_B.SL_b_FLDoorInBtnSts,
                   REL_B.SL_b_FLDoorHndBtnSts, Child_Unlock,
                   &REL_B.SO_b_DoorRlsReq_o, &REL_B.SO_e_DoorRlsDelayTime_b,
                   &SO_m_UnlockReq, &REL_DW.sf_FLDoorRlsReq);

  /* Chart: '<S3>/FLDoorRlsDriver' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  REL_FLDoorRlsDriver(REL_B.SO_b_DoorRlsReq_o,
                      REL_B.VbOUT_SP_FLDoorAjarSts_flg_VbOU,
                      REL_B.VbOUT_HWA_FLDoorFullOpen_flg_Vb, false, false,
                      REL_B.SO_e_DoorRlsDelayTime_b, &REL_B.SO_b_MotorA_m,
                      &REL_B.SO_b_MotorB_d, &REL_B.SO_e_MotorCmd_m, &SO_b_Error,
                      &SO_e_MotorPwm_l, &REL_DW.sf_FLDoorRlsDriver);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg
    (REL_B.SL_b_FLDoorInBtnSts);

  /* Outport: '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg
    (REL_B.SL_b_FLDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg
    (REL_B.VbOUT_HWA_FLDoorFullOpen_flg_Vb);

  /* Outport: '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg
    (REL_B.VbOUT_SP_FLDoorAjarSts_flg_VbOU);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   */
  (void)
    Rte_Write_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig
    (REL_B.SO_e_MotorCmd_m);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg
    (REL_B.SL_b_RLDoorInBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' */
  (void)
    Rte_Write_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg
    (REL_B.SL_b_RLDoorHndBtnSts);

  /* Outport: '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg
    (REL_B.VbOUT_HWA_RLDoorFullOpen_flg_Vb);

  /* Outport: '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg
    (REL_B.VbOUT_SP_RLDoorAjarSts_flg_VbOU);

  /* RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
   *  SubSystem: '<Root>/REL_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)
    Rte_Write_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig
    (REL_B.SO_e_MotorCmd);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig(0U);

  /* Outport: '<Root>/VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig' */
  (void)
    Rte_Write_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig(0U);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
    (REL_B.SO_b_MotorA_m);

  /* Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
    (REL_B.SO_b_MotorB_d);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
    (REL_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
    (REL_B.SO_b_MotorB);

  /* Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq_o);

  /* Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
  (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
    (REL_B.SO_b_DoorRlsReq);
}

/* Model initialize function */
void REL_Init(void)
{
  {
    Unlock_Req_E SO_m_UnlockReq_l;
    uint8 SO_e_MotorPwm_l;
    boolean SO_b_Error_b;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' incorporates:
     *  SubSystem: '<Root>/REL_Step_sys'
     */

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA_m, &REL_B.SO_b_MotorB_d,
      &REL_B.SO_e_MotorCmd_m, &SO_b_Error_b, &SO_e_MotorPwm_l);

    /* SystemInitialize for Chart: '<S3>/FLDoorRlsReq' */
    REL_FLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq_o,
                          &REL_B.SO_e_DoorRlsDelayTime_b, &SO_m_UnlockReq_l);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsDriver' */
    REL_FLDoorRlsDriver_Init(&REL_B.SO_b_MotorA, &REL_B.SO_b_MotorB,
      &REL_B.SO_e_MotorCmd, &SO_b_Error_b, &SO_e_MotorPwm_l);

    /* SystemInitialize for Chart: '<S3>/RLDoorRlsReq' */
    REL_FLDoorRlsReq_Init(&REL_B.SO_b_DoorRlsReq, &REL_B.SO_e_DoorRlsDelayTime,
                          &SO_m_UnlockReq_l);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/REL_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
      (REL_B.SO_b_MotorA_m);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
      (REL_B.SO_b_MotorB_d);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
      (REL_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
      (REL_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq_o);

    /* SystemInitialize for Outport: '<Root>/VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg' */
    (void)Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
      (REL_B.SO_b_DoorRlsReq);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
