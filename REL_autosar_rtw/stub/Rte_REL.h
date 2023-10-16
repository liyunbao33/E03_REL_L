/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "REL"
   ARXML schema: "4.3"
   File generated on: "16-Oct-2023 17:41:35"  */

#ifndef Rte_REL_h
#define Rte_REL_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg Rte_Write_REL_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg

Std_ReturnType Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg(void);

#define Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg Rte_Write_REL_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg

Std_ReturnType Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg(void);

#define Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg Rte_Read_REL_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg

Std_ReturnType Rte_Read_VbINP_CAN_EspVehSpdVld_flg_VbINP_CAN_EspVehSpdVld_flg
  (Boolean* u);

#define Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg Rte_Read_REL_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg

Std_ReturnType Rte_Read_VbINP_HWA_FLDoorButton_flg_VbINP_HWA_FLDoorButton_flg
  (Boolean* u);

#define Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg Rte_Read_REL_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg

Std_ReturnType
  Rte_Read_VbINP_HWA_FLDoorHandleSW_flg_VbINP_HWA_FLDoorHandleSW_flg(Boolean* u);

#define Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg Rte_Read_REL_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg

Std_ReturnType Rte_Read_VbINP_HWA_RLDoorButton_flg_VbINP_HWA_RLDoorButton_flg
  (Boolean* u);

#define Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg Rte_Read_REL_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg

Std_ReturnType
  Rte_Read_VbINP_HWA_RLDoorHandleSW_flg_VbINP_HWA_RLDoorHandleSW_flg(Boolean* u);

#define Rte_Read_VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg Rte_Read_REL_VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg

Std_ReturnType
  Rte_Read_VbOUT_HWA_FLDoorFullOpen_flg_VbOUT_HWA_FLDoorFullOpen_flg(Boolean* u);

#define Rte_Read_VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg Rte_Read_REL_VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg

Std_ReturnType
  Rte_Read_VbOUT_HWA_RLDoorFullOpen_flg_VbOUT_HWA_RLDoorFullOpen_flg(Boolean* u);

#define Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg Rte_Read_REL_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg

Std_ReturnType Rte_Read_VbOUT_SP_CrashOutpSts_flg_VbOUT_SP_CrashOutpSts_flg
  (Boolean* u);

#define Rte_Read_VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg Rte_Read_REL_VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg

Std_ReturnType Rte_Read_VbOUT_SP_FLDoorAjarSts_flg_VbOUT_SP_FLDoorAjarSts_flg
  (Boolean* u);

#define Rte_Read_VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg Rte_Read_REL_VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg

Std_ReturnType Rte_Read_VbOUT_SP_RLDoorAjarSts_flg_VbOUT_SP_RLDoorAjarSts_flg
  (Boolean* u);

#define Rte_Read_VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig Rte_Read_REL_VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig

Std_ReturnType Rte_Read_VeINP_CAN_PowerMode_sig_VeINP_CAN_PowerMode_sig(UInt8* u);

#define Rte_Read_VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig Rte_Read_REL_VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig

Std_ReturnType
  Rte_Read_VeINP_HWA_LRChildrenProtectSwitch_sig_VeINP_HWA_LRChildrenProtectSwitch_sig
  (UInt8* u);

#define Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig Rte_Read_REL_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig

Std_ReturnType
  Rte_Read_VeOUT_DLK_LHFDoorLockSts_sig_VeOUT_DLK_LHFDoorLockSts_sig(UInt8* u);

#define Rte_Read_VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig Rte_Read_REL_VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig

Std_ReturnType
  Rte_Read_VeOUT_DLK_LHRDoorLockSts_sig_VeOUT_DLK_LHRDoorLockSts_sig(UInt8* u);

#define Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh Rte_Read_REL_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh

Std_ReturnType Rte_Read_VeOUT_SP_EspVehSpd_kmh_VeOUT_SP_EspVehSpd_kmh(UInt8* u);

#define Rte_Write_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg Rte_Write_REL_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg Rte_Invalidate_REL_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLLockReleaseInsdSW_flg_VbOUT_REL_FLLockReleaseInsdSW_flg
  (void);

#define Rte_Write_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg Rte_Write_REL_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg Rte_Invalidate_REL_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLLockReleaseOutsdSW_flg_VbOUT_REL_FLLockReleaseOutsdSW_flg
  (void);

#define Rte_Write_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg Rte_Write_REL_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorOpenSwitch_flg_VbOUT_REL_FLDoorOpenSwitch_flg
  (void);

#define Rte_Write_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg Rte_Write_REL_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorAjarSwitch_flg_VbOUT_REL_FLDoorAjarSwitch_flg
  (void);

#define Rte_Write_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig Rte_Write_REL_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig Rte_Invalidate_REL_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_REL_FLReleaseLatchStatus_sig_VeOUT_REL_FLReleaseLatchStatus_sig
  (void);

#define Rte_Write_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg Rte_Write_REL_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg Rte_Invalidate_REL_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLLockReleaseInsdSW_flg_VbOUT_REL_RLLockReleaseInsdSW_flg
  (void);

#define Rte_Write_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg Rte_Write_REL_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg Rte_Invalidate_REL_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLLockReleaseOutsdSW_flg_VbOUT_REL_RLLockReleaseOutsdSW_flg
  (void);

#define Rte_Write_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg Rte_Write_REL_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorOpenSwitch_flg_VbOUT_REL_RLDoorOpenSwitch_flg
  (void);

#define Rte_Write_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg Rte_Write_REL_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg

Std_ReturnType
  Rte_Write_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorAjarSwitch_flg_VbOUT_REL_RLDoorAjarSwitch_flg
  (void);

#define Rte_Write_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig Rte_Write_REL_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig

Std_ReturnType
  Rte_Write_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig Rte_Invalidate_REL_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_REL_RLChildrenProtectSwitch_sig_VeOUT_REL_RLChildrenProtectSwitch_sig
  (void);

#define Rte_Write_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig Rte_Write_REL_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig

Std_ReturnType
  Rte_Write_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig Rte_Invalidate_REL_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_REL_RLReleaseLatchStatus_sig_VeOUT_REL_RLReleaseLatchStatus_sig
  (void);

#define Rte_Write_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig Rte_Write_REL_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig

Std_ReturnType
  Rte_Write_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig Rte_Invalidate_REL_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_REL_HandleSwitchStsFL_sig_VeOUT_REL_HandleSwitchStsFL_sig
  (void);

#define Rte_Write_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig Rte_Write_REL_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig

Std_ReturnType
  Rte_Write_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig Rte_Invalidate_REL_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_REL_HandleSwitchStsRR_sig_VeOUT_REL_HandleSwitchStsRR_sig
  (void);

#define Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg Rte_Write_REL_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg

Std_ReturnType Rte_Write_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorMotorA_flg_VbOUT_REL_FLDoorMotorA_flg(void);

#define Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg Rte_Write_REL_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg

Std_ReturnType Rte_Write_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorMotorB_flg_VbOUT_REL_FLDoorMotorB_flg(void);

#define Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg Rte_Write_REL_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg

Std_ReturnType Rte_Write_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorMotorA_flg_VbOUT_REL_RLDoorMotorA_flg(void);

#define Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg Rte_Write_REL_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg

Std_ReturnType Rte_Write_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorMotorB_flg_VbOUT_REL_RLDoorMotorB_flg(void);

#define Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg Rte_Write_REL_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg

Std_ReturnType Rte_Write_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg Rte_Invalidate_REL_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_FLDoorRlsReq_flg_VbOUT_REL_FLDoorRlsReq_flg(void);

#define Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg Rte_Write_REL_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg

Std_ReturnType Rte_Write_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg Rte_Invalidate_REL_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_REL_RLDoorRlsReq_flg_VbOUT_REL_RLDoorRlsReq_flg(void);

/* Entry point functions */
extern FUNC(void, REL_CODE) REL_Init(void);
extern FUNC(void, REL_CODE) REL_Step(void);

#endif
