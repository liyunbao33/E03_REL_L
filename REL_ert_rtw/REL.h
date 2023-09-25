/*
 * File: REL.h
 *
 * Code generated for Simulink model 'REL'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Sep 25 19:55:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_REL_h_
#define RTW_HEADER_REL_h_
#ifndef REL_COMMON_INCLUDES_
#define REL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* REL_COMMON_INCLUDES_ */

#include "REL_types.h"
#include "Rte_Type.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S3>/FLDoorRlsDriver' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_active_c19_DoorRlsDriver; /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_c19_DoorRlsDriver;        /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Normal;                   /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_MainProgress;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Release;                  /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Step2_Open;               /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_MainProgress_c;           /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Release_a;                /* '<S3>/FLDoorRlsDriver' */
  uint8_T is_Step2_Open_f;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T SL_e_CycleCount;             /* '<S3>/FLDoorRlsDriver' */
  uint8_T SL_e_DoorRlsDelayTime;       /* '<S3>/FLDoorRlsDriver' */
  boolean_T SO_b_DoorRlsReq_prev;      /* '<S3>/FLDoorRlsDriver' */
  boolean_T SO_b_DoorRlsReq_start;     /* '<S3>/FLDoorRlsDriver' */
} DW_FLDoorRlsDriver_REL_T;

/* Block states (default storage) for system '<S3>/FLDoorRlsReq' */
typedef struct {
  uint8_T is_active_c5_DoorRlsReq;     /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid;                  /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq;                   /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger;                  /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_SwValid_n;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_RlsReq_l;                 /* '<S3>/FLDoorRlsReq' */
  uint8_T is_Trigger_k;                /* '<S3>/FLDoorRlsReq' */
  uint8_T is_DoorLock_c;               /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i1;          /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i2;          /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i3;          /* '<S3>/FLDoorRlsReq' */
  uint8_T temporalCounter_i4;          /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid;       /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid;      /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_prev;    /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorInBtnSts_start;   /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_prev;  /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorInBtnValid_start; /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_prev;   /* '<S3>/FLDoorRlsReq' */
  boolean_T SI_b_DoorHndBtnSts_start;  /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_prev; /* '<S3>/FLDoorRlsReq' */
  boolean_T SL_b_DoorHndBtnValid_start;/* '<S3>/FLDoorRlsReq' */
} DW_FLDoorRlsReq_REL_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T SO_e_DoorRlsDelayTime;       /* '<S3>/RLDoorRlsReq' */
  uint8_T SO_e_DoorRlsDelayTime_c;     /* '<S3>/FLDoorRlsReq' */
  boolean_T SO_b_DoorRlsReq;           /* '<S3>/RLDoorRlsReq' */
  boolean_T SO_b_DoorRlsReq_l;         /* '<S3>/FLDoorRlsReq' */
  Mot_Cmd_E SO_e_MotorCmd;             /* '<S3>/RLDoorRlsDriver' */
  Mot_Cmd_E SO_e_MotorCmd_j;           /* '<S3>/FLDoorRlsDriver' */
} B_REL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<S3>/DoorSwSts' */
  uint8_T is_active_c23_REL;           /* '<S3>/DoorSwSts' */
  uint8_T is_c23_REL;                  /* '<S3>/DoorSwSts' */
  uint8_T is_active_c3_REL;            /* '<S3>/DoorRatSts' */
  boolean_T SI_b_CrashSts_start;       /* '<S3>/DoorSwSts' */
  DW_FLDoorRlsReq_REL_T sf_RLDoorRlsReq;/* '<S3>/RLDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_RLDoorRlsDriver;/* '<S3>/RLDoorRlsDriver' */
  DW_FLDoorRlsReq_REL_T sf_FLDoorRlsReq;/* '<S3>/FLDoorRlsReq' */
  DW_FLDoorRlsDriver_REL_T sf_FLDoorRlsDriver;/* '<S3>/FLDoorRlsDriver' */
} DW_REL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const HndPos_Sts_E DataTypeConversion15;/* '<S3>/Data Type Conversion15' */
  const HndPos_Sts_E DataTypeConversion17;/* '<S3>/Data Type Conversion17' */
  const Gear_Posn_E DataTypeConversion14;/* '<S3>/Data Type Conversion14' */
} ConstB_REL_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  UInt8 VeINP_CAN_PowerMode_sig_VeINP_C;
                  /* '<Root>/VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig' */
  Boolean VbOUT_SP_FLDoorAjarSts_flg_VbOU;
            /* '<Root>/VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg' */
  Boolean VbOUT_SP_RLDoorAjarSts_flg_VbOU;
            /* '<Root>/VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg' */
  Boolean VbINP_HWA_FLDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg' */
  Boolean VbINP_HWA_RLDoorButton_flg_VbIN;
            /* '<Root>/VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg' */
  Boolean VbINP_HWA_FLDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg' */
  Boolean VbINP_HWA_RLDoorHandleSW_flg_Vb;
        /* '<Root>/VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg' */
  UInt8 VmOUT_DLK_LockSrc_enum_VmOUT_DL;
                    /* '<Root>/VmOUT_DLK_LockSrc_enum_VmOUT_DLK_LockSrc_enum' */
  Boolean VbOUT_DLK_FLUnlock_flg_VbOUT_DL;
                    /* '<Root>/VbOUT_DLK_FLUnlock_flg_VbOUT_DLK_FLUnlock_flg' */
  Boolean VbOUT_DLK_RLUnlock_flg_VbOUT_DL;
                    /* '<Root>/VbOUT_DLK_RLUnlock_flg_VbOUT_DLK_RLUnlock_flg' */
  UInt8 VeOUT_SP_EspVehSpd_kmh_VeOUT_SP;
                    /* '<Root>/VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh' */
  Boolean VbINP_CAN_EspVehSpdVld_flg_VbIN;
            /* '<Root>/VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg' */
  Boolean VbOUT_SP_CrashOutpSts_flg_VbOUT;
              /* '<Root>/VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg' */
  UInt8 VeINP_HWA_LRChildrenProtectSwit;
  /* '<Root>/VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig' */
  Boolean VbOUT_HWA_FLDoorFullOpen_flg_Vb;
        /* '<Root>/VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg' */
  Boolean VbOUT_HWA_RLDoorFullOpen_flg_Vb;
        /* '<Root>/VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg' */
  UInt8 VeOUT_DLK_LHFDoorLockSts_sig_Ve;
        /* '<Root>/VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig' */
  UInt8 VeOUT_DLK_LHRDoorLockSts_sig_Ve;
        /* '<Root>/VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig' */
} ExtU_REL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Boolean VbOUT_REL_FLLockReleaseInsdSW_f;
  /* '<Root>/VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg' */
  Boolean VbOUT_REL_FLLockReleaseOutsdSW_;
  /* '<Root>/VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg' */
  Boolean VbOUT_REL_FLDoorOpenSwitch_flg_;
    /* '<Root>/VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg' */
  Boolean VbOUT_REL_FLDoorAjarSwitch_flg_;
    /* '<Root>/VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg' */
  UInt8 VeOUT_REL_FLReleaseLatchStatus_;
  /* '<Root>/VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig' */
  Boolean VbOUT_REL_RLLockReleaseInsdSW_f;
  /* '<Root>/VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg' */
  Boolean VbOUT_REL_RLLockReleaseOutsdSW_;
  /* '<Root>/VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg' */
  Boolean VbOUT_REL_RLDoorOpenSwitch_flg_;
    /* '<Root>/VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg' */
  Boolean VbOUT_REL_RLDoorAjarSwitch_flg_;
    /* '<Root>/VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg' */
  UInt8 VeOUT_REL_RLChildrenProtectSwit;
  /* '<Root>/VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig' */
  UInt8 VeOUT_REL_RLReleaseLatchStatus_;
  /* '<Root>/VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig' */
  UInt8 VeOUT_REL_HandleSwitchStsFL_sig;
  /* '<Root>/VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig' */
  UInt8 VeOUT_REL_HandleSwitchStsRR_sig;
  /* '<Root>/VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig' */
  Boolean VbOUT_REL_FLDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg' */
  Boolean VbOUT_REL_FLDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg' */
  Boolean VbOUT_REL_RLDoorMotorA_flg_VbOU;
            /* '<Root>/VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg' */
  Boolean VbOUT_REL_RLDoorMotorB_flg_VbOU;
            /* '<Root>/VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg' */
} ExtY_REL_T;

/* Real-time Model Data Structure */
struct tag_RTM_REL_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_REL_T REL_B;

/* Block states (default storage) */
extern DW_REL_T REL_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_REL_T REL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_REL_T REL_Y;
extern const ConstB_REL_T REL_ConstB;  /* constant block i/o */

/* Model entry point functions */
extern void REL_initialize(void);
extern void REL_terminate(void);

/* Exported entry point function */
extern void REL_Step(void);

/* Real-time Model object */
extern RT_MODEL_REL_T *const REL_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion3' : Unused code path elimination
 * Block '<S3>/Data Type Conversion6' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'REL'
 * '<S1>'   : 'REL/REL_Init'
 * '<S2>'   : 'REL/REL_Step_sys'
 * '<S3>'   : 'REL/REL_Step_sys/REL'
 * '<S4>'   : 'REL/REL_Step_sys/REL/DoorRatSts'
 * '<S5>'   : 'REL/REL_Step_sys/REL/DoorSwSts'
 * '<S6>'   : 'REL/REL_Step_sys/REL/FLDoorRlsDriver'
 * '<S7>'   : 'REL/REL_Step_sys/REL/FLDoorRlsReq'
 * '<S8>'   : 'REL/REL_Step_sys/REL/OFF '
 * '<S9>'   : 'REL/REL_Step_sys/REL/RLDoorRlsDriver'
 * '<S10>'  : 'REL/REL_Step_sys/REL/RLDoorRlsReq'
 * '<S11>'  : 'REL/REL_Step_sys/REL/Recycle Bin'
 */
#endif                                 /* RTW_HEADER_REL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */