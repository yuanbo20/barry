#include "InputConfig.h"
#include "pev.h"
#include "TestSystemLogging.h"
#include "TsDataType.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace rapidjson;
using namespace Timer_15118::Timer_par_15118;
using namespace Timer_15118_2::Timer_par_15118_2;
using namespace Pics_15118::PICS_CMN;
using namespace Pics_15118::PICS_SECC_Tester;
using namespace Pics_15118::PICS_EVCC_Tester;
using namespace Pics_15118_2::PICS_15118_2::PICS_CMN;
using namespace Pics_15118_2::PICS_15118_2::PICS_SECC_Tester;
using namespace Pics_15118_2::PICS_15118_2::PICS_EVCC_Tester;
using namespace Pixit_15118::PIXIT_15118::PIXIT_CMN;
using namespace Pixit_15118::PIXIT_15118::PIXIT_EVCC_Tester;
using namespace Pixit_15118_2::PIXIT_15118_2::PIXIT_CMN;
using namespace Pixit_15118_2::PIXIT_15118_2::PIXIT_SECC_Tester;
using namespace Pixit_15118_2::PIXIT_15118_2::PIXIT_EVCC_Tester;
using namespace DataStructure_PICS_15118;
using namespace DataStructure_PIXIT_15118_2;
using namespace DataStructure_PIXIT_15118;
using namespace DataStructure_HAL_61851;
using namespace urn_iso_15118_2_2013_MsgDataTypes;

std::map<std::string, float *> SLAC_TIMER_MAP = {
    {"TP_EV_vald_state_duration", &Plc::TP_EV_vald_state_duration},
    {"TP_EV_vald_toggle", &Plc::TP_EV_vald_toggle},
    {"TP_EV_SLAC_init", &Plc::TP_EV_SLAC_init}};
std::map<std::string, uint8_t *> SLAC_THRESHOLD_MAP = {
    {"C_EV_vald_nb_toggles", &Plc::C_EV_vald_nb_toggles},
    {"C_EV_match_signalattn_direct", &Plc::C_EV_match_signalattn_direct},
    {"C_EV_match_signalattn_indirect", &Plc::C_EV_match_signalattn_indirect}};
std::map<std::string, float *> TIMER_MAP =
    {
        {"par_TP_EV_vald_state_duration", &par_TP_EV_vald_state_duration},
        {"par_T_conn_max_comm", &par_T_conn_max_comm},
        {"par_CMN_Transmission_Delay", &par_CMN_Transmission_Delay},
        {"par_CMN_HAL_Timeout", &par_CMN_HAL_Timeout},
        {"par_CMN_waitForNextHAL", &par_CMN_waitForNextHAL},
        {"par_CMN_Intern_PTC_Timeout", &par_CMN_Intern_PTC_Timeout},
        {"par_CMN_setKey", &par_CMN_setKey},
        {"par_EVCC_waitForNextTC", &par_EVCC_waitForNextTC},
        {"par_SECC_waitForNextTC", &par_SECC_waitForNextTC},
        {"par_SECC_T_step_X1", &par_SECC_T_step_X1},
        {"par_SECC_Pmax0W", &par_SECC_Pmax0W},
        {"par_V2G_SECC_Sequence_Timeout", &par_V2G_SECC_Sequence_Timeout},
        {"par_V2G_EVCC_Msg_Timeout_SupportedAppProtocolReq", &par_V2G_EVCC_Msg_Timeout_SupportedAppProtocolReq},
        {"par_V2G_EVCC_Msg_Timeout_SessionSetupReq", &par_V2G_EVCC_Msg_Timeout_SessionSetupReq},
        {"par_V2G_EVCC_Msg_Timeout_ServiceDiscoveryReq", &par_V2G_EVCC_Msg_Timeout_ServiceDiscoveryReq},
        {"par_V2G_EVCC_Msg_Timeout_ServiceDetailReq", &par_V2G_EVCC_Msg_Timeout_ServiceDetailReq},
        {"par_V2G_EVCC_Msg_Timeout_PaymentServiceSelectionReq", &par_V2G_EVCC_Msg_Timeout_PaymentServiceSelectionReq},
        {"par_V2G_EVCC_Msg_Timeout_CertificateInstallationReq", &par_V2G_EVCC_Msg_Timeout_CertificateInstallationReq},
        {"par_V2G_EVCC_Msg_Timeout_CertificateUpdateReq", &par_V2G_EVCC_Msg_Timeout_CertificateUpdateReq},
        {"par_V2G_EVCC_Msg_Timeout_PaymentDetailsReq", &par_V2G_EVCC_Msg_Timeout_PaymentDetailsReq},
        {"par_V2G_EVCC_Msg_Timeout_AuthorizationReq", &par_V2G_EVCC_Msg_Timeout_AuthorizationReq},
        {"par_V2G_EVCC_Msg_Timeout_ChargeParameterDiscoveryReq", &par_V2G_EVCC_Msg_Timeout_ChargeParameterDiscoveryReq},
        {"par_V2G_EVCC_Msg_Timeout_PowerDeliveryReq", &par_V2G_EVCC_Msg_Timeout_PowerDeliveryReq},
        {"par_V2G_EVCC_Msg_Timeout_ChargingStatusReq", &par_V2G_EVCC_Msg_Timeout_ChargingStatusReq},
        {"par_V2G_EVCC_Msg_Timeout_MeteringReceiptReq", &par_V2G_EVCC_Msg_Timeout_MeteringReceiptReq},
        {"par_V2G_EVCC_Msg_Timeout_SessionStopReq", &par_V2G_EVCC_Msg_Timeout_SessionStopReq},
        {"par_V2G_EVCC_Msg_Timeout_CableCheckReq", &par_V2G_EVCC_Msg_Timeout_CableCheckReq},
        {"par_V2G_EVCC_Msg_Timeout_PreChargeReq", &par_V2G_EVCC_Msg_Timeout_PreChargeReq},
        {"par_V2G_EVCC_Msg_Timeout_CurrentDemandReq", &par_V2G_EVCC_Msg_Timeout_CurrentDemandReq},
        {"par_V2G_EVCC_Msg_Timeout_WeldingDetectionReq", &par_V2G_EVCC_Msg_Timeout_WeldingDetectionReq},
        {"par_V2G_EVCC_Ongoing_Timeout", &par_V2G_EVCC_Ongoing_Timeout},
        {"par_V2G_EVCC_Ongoing_Performance_Timeout", &par_V2G_EVCC_Ongoing_Performance_Timeout},
        {"par_V2G_EVCC_CommunicationSetup_Timeout", &par_V2G_EVCC_CommunicationSetup_Timeout},
        {"par_V2G_SECC_CommunicationSetup_Performance_Time", &par_V2G_SECC_CommunicationSetup_Performance_Time},
        {"par_V2G_EVCC_CableCheck_Timeout", &par_V2G_EVCC_CableCheck_Timeout},
        {"par_V2G_EVCC_PreCharge_Timeout", &par_V2G_EVCC_PreCharge_Timeout},
        {"par_EVCC_SDP_Timeout", &par_EVCC_SDP_Timeout},
        {"par_SECC_B1_B2_Timeout", &par_SECC_B1_B2_Timeout},
        {"par_SECC_chargingLoop_pause", &par_SECC_chargingLoop_pause},
        {"par_V2G_SECC_CPState_Error_Detection_Timeout", &par_V2G_SECC_CPState_Error_Detection_Timeout},
        {"par_V2G_SECC_CPState_Detection_Timeout", &par_V2G_SECC_CPState_Detection_Timeout},
        {"par_CMN_TCP_Connection_Termination_Timeout", &par_CMN_TCP_Connection_Termination_Timeout}};
std::map<std::string, void *> PICS_MAP =
    {
        {"par_CMN_MaxEntriesSAScheduleTuple", (void *)&par_CMN_MaxEntriesSAScheduleTuple},
        {"PICS_CMN_CMN_CombinedTesting", (void *)&PICS_CMN_CMN_CombinedTesting},
        {"PICS_CMN_CMN_ChargingMode", (void *)&PICS_CMN_CMN_ChargingMode},
        {"PICS_CMN_CMN_IdentificationMode", (void *)&PICS_CMN_CMN_IdentificationMode},
        {"PICS_CMN_CMN_PlugType", (void *)&PICS_CMN_CMN_PlugType},
        {"PICS_CMN_AC_CableCapability", (void *)&PICS_CMN_AC_CableCapability},
        {"PICS_CMN_CMN_WakeUp", (void *)&PICS_CMN_CMN_WakeUp},
        {"PICS_CMN_CMN_EnergyTransferModeAC", (void *)&PICS_CMN_CMN_EnergyTransferModeAC},
        {"PICS_CMN_CMN_EnergyTransferModeDC", (void *)&PICS_CMN_CMN_EnergyTransferModeDC},
        {"PICS_SECC_CMN_Pause", (void *)&PICS_SECC_CMN_Pause},
        {"PICS_SECC_CMN_EIMDone", (void *)&PICS_SECC_CMN_EIMDone},
        {"PICS_EVCC_CMN_PmaxSchedulewithZeroPow", (void *)&PICS_EVCC_CMN_PmaxSchedulewithZeroPow},
        {"PICS_CMN_CMN_V2gtpSdp", (void *)&PICS_CMN_CMN_V2gtpSdp},
        {"PICS_CMN_CMN_V2gtpV2g", (void *)&PICS_CMN_CMN_V2gtpV2g},
        {"PICS_CMN_CMN_Renegotiation", (void *)&PICS_CMN_CMN_Renegotiation},
        {"PICS_CMN_CMN_RenegotiationLoopIndication", (void *)&PICS_CMN_CMN_RenegotiationLoopIndication},
        {"PICS_CMN_CMN_LoopCounter", (void *)&PICS_CMN_CMN_LoopCounter},
        {"PICS_CMN_CMN_InvalidV2gtpDataFields", (void *)&PICS_CMN_CMN_InvalidV2gtpDataFields},
        {"PICS_CMN_CMN_SDPTimeoutsAndInvalidData", (void *)&PICS_CMN_CMN_SDPTimeoutsAndInvalidData},
        {"PICS_CMN_CMN_FailedResponseCodes", (void *)&PICS_CMN_CMN_FailedResponseCodes},
        {"PICS_CMN_CMN_V2gTimeouts", (void *)&PICS_CMN_CMN_V2gTimeouts},
        {"PICS_CMN_CMN_PkiName", (void *)&PICS_CMN_CMN_PkiName},
        {"par_EVRESSSOC", (void *)&par_EVRESSSOC},
        {"PICS_SECC_CMN_EvStateInChargeProgress", (void *)&PICS_SECC_CMN_EvStateInChargeProgress},
        {"PICS_SECC_DC_WeldingDetection", (void *)&PICS_SECC_DC_WeldingDetection},
        {"PICS_SECC_CMN_DepartureTime", (void *)&PICS_SECC_CMN_DepartureTime},
        {"PICS_SECC_CMN_MaxEntriesSAScheduleTuple", (void *)&PICS_SECC_CMN_MaxEntriesSAScheduleTuple},
        {"PICS_EVCC_CMN_ReceiptRequired", (void *)&PICS_EVCC_CMN_ReceiptRequired},
        {"PICS_EVCC_CMN_InvalidStatesAndDutyCycles", (void *)&PICS_EVCC_CMN_InvalidStatesAndDutyCycles},
        {"PICS_EVCC_CMN_InvalidV2GMessages", (void *)&PICS_EVCC_CMN_InvalidV2GMessages},
        {"PICS_CMN_EVCC_SalesTariff", (void *)&PICS_CMN_EVCC_SalesTariff}};
std::map<std::string, void *> PIXIT_MAP =
    {
        {"PIXIT_CMN_CMN_WakeUp", (void *)&PIXIT_CMN_CMN_WakeUp},
        {"PIXIT_EVCC_CMN_Pause", (void *)&PIXIT_EVCC_CMN_Pause},
        {"PIXIT_CMN_CMN_PkiName", (void *)&PIXIT_CMN_CMN_PkiName},
        {"PIXIT_CMN_CMN_Renegotiation", (void *)&PIXIT_CMN_CMN_Renegotiation},
        {"PIXIT_CMN_CMN_MeterReading", (void *)&PIXIT_CMN_CMN_MeterReading},
        {"par_EVTargetVoltage", (void *)&par_EVTargetVoltage},
        {"par_EVTargetCurrent", (void *)&par_EVTargetCurrent},
        {"par_EVBatteryVoltage", (void *)&par_EVBatteryVoltage},
        {"par_EVMaximumVoltageLimit", (void *)&par_EVMaximumVoltageLimit},
        {"par_EVMaximumCurrentLimit", (void *)&par_EVMaximumCurrentLimit},
        {"par_ValidDeviationPerCent", (void *)&par_ValidDeviationPerCent},
        {"par_LoadStartValCurrent", (void *)&par_LoadStartValCurrent},
        {"par_EVBatteryStepSize", (void *)&par_EVBatteryStepSize},
        {"PIXIT_SECC_CMN_VAS", (void *)&PIXIT_SECC_CMN_VAS},
        {"PIXIT_SECC_CMN_ReceiptRequired", (void *)&PIXIT_SECC_CMN_ReceiptRequired},
        {"PIXIT_SECC_CMN_CertificateHandling", (void *)&PIXIT_SECC_CMN_CertificateHandling},
        {"PIXIT_SECC_CMN_SalesTariff", (void *)&PIXIT_SECC_CMN_SalesTariff},
        {"PIXIT_SECC_CMN_TLS", (void *)&PIXIT_SECC_CMN_TLS},
        {"PIXIT_SECC_CMN_VersionNumberMinor", (void *)&PIXIT_SECC_CMN_VersionNumberMinor},
        {"PIXIT_SECC_CMN_InternetAccess", (void *)&PIXIT_SECC_CMN_InternetAccess},
        {"PIXIT_SECC_DC_CableCheckOngoing", (void *)&PIXIT_SECC_DC_CableCheckOngoing},
        {"PIXIT_SECC_CMN_AuthorizationOngoing", (void *)&PIXIT_SECC_CMN_AuthorizationOngoing},
        {"PIXIT_SECC_CMN_ChargeParameterDiscoveryOngoing", (void *)&PIXIT_SECC_CMN_ChargeParameterDiscoveryOngoing},
        {"PIXIT_SECC_CMN_MeterInfo", (void *)&PIXIT_SECC_CMN_MeterInfo},
        {"PIXIT_SECC_CMN_PaymentOption", (void *)&PIXIT_SECC_CMN_PaymentOption},
        {"PIXIT_EVCC_CMN_VAS", (void *)&PIXIT_EVCC_CMN_VAS},
        {"PIXIT_EVCC_DC_WeldingDetection", (void *)&PIXIT_EVCC_DC_WeldingDetection},
        {"PIXIT_EVCC_CMN_TLS", (void *)&PIXIT_EVCC_CMN_TLS},
        {"PIXIT_EVCC_CMN_CertificateHandling", (void *)&PIXIT_EVCC_CMN_CertificateHandling},
        {"PIXIT_EVCC_CMN_DepartureTime", (void *)&PIXIT_EVCC_CMN_DepartureTime},
        {"PIXIT_EVCC_AC_MaxNumberOfPhasesInUse", (void *)&PIXIT_EVCC_AC_MaxNumberOfPhasesInUse},
        {"PIXIT_EVCC_CMN_ChargingProfileOptimization", (void *)&PIXIT_EVCC_CMN_ChargingProfileOptimization},
        {"PIXIT_EVCC_CMN_NewSAScheduleTupleID", (void *)&PIXIT_EVCC_CMN_NewSAScheduleTupleID},
        {"PIXIT_EVCC_CMN_SAScheduleTupleIDMR", (void *)&PIXIT_EVCC_CMN_SAScheduleTupleIDMR}};


int load_config(const std::string &testconfig, const std::string &slac_config) {
  // load json configuration data
  std::ifstream ifs;
  ifs.open(testconfig, std::ios_base::in);
  if (!ifs.good())
  {
    Logging::error(0, "v2g configuration file is not exist");
    Logging::info(0, fmt::format("error {0} : {1}", errno, strerror(errno)));
    return -1;
  }
  IStreamWrapper isw(ifs);
  Document document;
  // dom tree
  document.ParseStream(isw);

  for (auto it = document["timer"].MemberBegin(); it < document["timer"].MemberEnd(); ++it)
  {
    std::string val_name = (*it).name.GetString();
    *(TIMER_MAP[val_name]) = (*it).value.GetFloat();
    Logging::info(0, fmt::format("TIMER {0} : {1}", val_name, *(TIMER_MAP[val_name])));
  }

  for (auto it = document["pics"].MemberBegin(); it < document["pics"].MemberEnd(); ++it)
  {
    std::string val_name = (*it).name.GetString();
    if ((*it).value.IsBool())
    {
      *(static_cast<bool *>(PICS_MAP[val_name])) = (*it).value.GetBool();
      Logging::info(0, fmt::format("PICS BOOL {0} : {1}", val_name, *((bool *)(PICS_MAP[val_name]))));
    }
    else if ((*it).value.IsNumber())
    {
      if (!val_name.compare("PICS_CMN_CMN_ChargingMode"))
      {
        *(static_cast<iso1Part4_ChargingMode *>(PICS_MAP[val_name])) = static_cast<iso1Part4_ChargingMode>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_CMN_IdentificationMode"))
      {
        *(static_cast<iso1Part4_IdentificationMode *>(PICS_MAP[val_name])) = static_cast<iso1Part4_IdentificationMode>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_CMN_PlugType"))
      {
        *(static_cast<iso1Part4_PlugType *>(PICS_MAP[val_name])) = static_cast<iso1Part4_PlugType>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_AC_CableCapability"))
      {
        *(static_cast<iso1Part4_CableCapabilityACType *>(PICS_MAP[val_name])) = static_cast<iso1Part4_CableCapabilityACType>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_SECC_CMN_EIMDone"))
      {
        *(static_cast<iso1Part4_EIMDone *>(PICS_MAP[val_name])) = static_cast<iso1Part4_EIMDone>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_EVCC_CMN_PmaxSchedulewithZeroPow"))
      {
        *(static_cast<iso1Part4_ZeroPow *>(PICS_MAP[val_name])) = static_cast<iso1Part4_ZeroPow>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_CMN_PkiName"))
      {
        *(static_cast<iso1Part4_PkiType *>(PICS_MAP[val_name])) = static_cast<iso1Part4_PkiType>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_SECC_CMN_EvStateInChargeProgress"))
      {
        *(static_cast<IEC_61851_States *>(PICS_MAP[val_name])) = static_cast<IEC_61851_States>((*it).value.GetInt());
      }
      else if (!val_name.compare("par_EVRESSSOC"))
      {
        *(static_cast<int8_t *>(PICS_MAP[val_name])) = static_cast<int8_t>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_CMN_WakeUp"))
      {
        *(static_cast<float *>(PICS_MAP[val_name])) = static_cast<float>((*it).value.GetFloat());
      }
      else if (!val_name.compare("PICS_CMN_CMN_EnergyTransferModeAC"))
      {
        *(static_cast<iso1Part4_EnergyTransferModeType *>(PICS_MAP[val_name])) = static_cast<iso1Part4_EnergyTransferModeType>((*it).value.GetInt());
      }
      else if (!val_name.compare("PICS_CMN_CMN_EnergyTransferModeDC"))
      {
        *(static_cast<iso1Part4_EnergyTransferModeType *>(PICS_MAP[val_name])) = static_cast<iso1Part4_EnergyTransferModeType>((*it).value.GetInt());
      }
      else
      {
        *(static_cast<uint32_t *>(PICS_MAP[val_name])) = static_cast<uint32_t>((*it).value.GetInt());
      }
      if (!val_name.compare("PICS_CMN_CMN_WakeUp")) {
        Logging::info(0, fmt::format("PICS VAL: {0} : {1}", val_name, *(static_cast<float *>(PICS_MAP[val_name]))));
      }
      else {
        Logging::info(0, fmt::format("PICS VAL: {0} : {1}", val_name, *((uint32_t *)(PICS_MAP[val_name]))));
      }
    }
  }

  for (auto it = document["pixit"].MemberBegin(); it < document["pixit"].MemberEnd(); ++it)
  {
    std::string val_name = (*it).name.GetString();
    if ((*it).value.IsBool())
    {
      *(static_cast<bool *>(PIXIT_MAP[val_name])) = (*it).value.GetBool();
      Logging::info(0, fmt::format("PIXIT BOOL {0} : {1}", val_name, *((bool *)(PIXIT_MAP[val_name]))));
    }
    else if ((*it).value.IsNumber())
    {
      if (!val_name.compare("PIXIT_EVCC_CMN_Pause"))
      {
        *(static_cast<iso1Part4_Pause *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_Pause>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_CMN_CMN_PkiName"))
      {
        *(static_cast<iso1Part4_PkiType *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_PkiType>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_CMN_CMN_Renegotiation"))
      {
        *(static_cast<iso1Part4_Renegotiation *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_Renegotiation>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_CMN_CMN_MeterReading"))
      {
        *(static_cast<iso1Part4_MeterReading *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_MeterReading>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_VAS"))
      {
        *(static_cast<iso1Part4_VASSECC *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_VASSECC>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_CertificateHandling"))
      {
        *(static_cast<iso1Part4_CertificateHandlingSECC *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_CertificateHandlingSECC>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_SalesTariff"))
      {
        *(static_cast<iso1Part4_SalesTariff *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_SalesTariff>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_InternetAccess"))
      {
        *(static_cast<iso1Part4_InternetAccess *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_InternetAccess>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_DC_CableCheckOngoing"))
      {
        *(static_cast<iso1Part4_Ongoing *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_Ongoing>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_AuthorizationOngoing"))
      {
        *(static_cast<iso1Part4_Ongoing *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_Ongoing>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_ChargeParameterDiscoveryOngoing"))
      {
        *(static_cast<iso1Part4_Ongoing *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_Ongoing>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_MeterInfo"))
      {
        *(static_cast<iso1Part4_MeterInfo *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_MeterInfo>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_SECC_CMN_PaymentOption"))
      {
        *(static_cast<iso1Part4_PaymentOption *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_PaymentOption>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_VAS"))
      {
        *(static_cast<iso1Part4_VASEVCC *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_VASEVCC>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_DC_WeldingDetection"))
      {
        *(static_cast<iso1Part4_WeldingDetection *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_WeldingDetection>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_TLS"))
      {
        *(static_cast<iso1Part4_TLS *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_TLS>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_CertificateHandling"))
      {
        *(static_cast<iso1Part4_CertificateHandlingEVCC *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_CertificateHandlingEVCC>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_DepartureTime"))
      {
        *(static_cast<iso1Part4_DepartureTime *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_DepartureTime>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_AC_MaxNumberOfPhasesInUse"))
      {
        *(static_cast<iso1Part4_MaxNumberOfPhasesInUse *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_MaxNumberOfPhasesInUse>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_ChargingProfileOptimization"))
      {
        *(static_cast<iso1Part4_ChargingProfileOpt *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_ChargingProfileOpt>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_NewSAScheduleTupleID"))
      {
        *(static_cast<iso1Part4_NewSAScheduleTupleID *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_NewSAScheduleTupleID>((*it).value.GetInt());
      }
      else if (!val_name.compare("PIXIT_EVCC_CMN_SAScheduleTupleIDMR"))
      {
        *(static_cast<iso1Part4_SAScheduleTupleIDMR *>(PIXIT_MAP[val_name])) = static_cast<iso1Part4_SAScheduleTupleIDMR>((*it).value.GetInt());
      }
      else if (!val_name.compare("par_ValidDeviationPerCent"))
      {
        *(static_cast<float *>(PIXIT_MAP[val_name])) = static_cast<float>((*it).value.GetFloat());
      }
      else if (!val_name.compare("par_LoadStartValCurrent"))
      {
        *(static_cast<float *>(PIXIT_MAP[val_name])) = static_cast<float>((*it).value.GetFloat());
      }
      else if (!val_name.compare("PIXIT_CMN_CMN_WakeUp"))
      {
        *(static_cast<float *>(PIXIT_MAP[val_name])) = static_cast<float>((*it).value.GetFloat());
      }
      else
      {
        *(static_cast<int *>(PIXIT_MAP[val_name])) = static_cast<int>((*it).value.GetInt());
      }
      if (!val_name.compare("par_ValidDeviationPerCent") || !val_name.compare("par_LoadStartValCurrent") || !val_name.compare("PIXIT_CMN_CMN_WakeUp")) {
        Logging::info(0, fmt::format("PIXIT VAL: {0} : {1}", val_name, *(static_cast<float *>(PIXIT_MAP[val_name]))));
      }
      else {
        Logging::info(0, fmt::format("PIXIT VAL: {0} : {1}", val_name, *(static_cast<int *>(PIXIT_MAP[val_name]))));
      }
    }
    else if ((*it).value.IsObject())
    {
      auto object = (*it).value.GetObject();
      (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->multiplier = (iso1Part4_UnitMultiplierType)(object["multiplier"].GetInt());
      (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->unit = (iso1Part4_UnitSymbolType)(object["unit"].GetInt());
      (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->value_ = (short)(object["value_"].GetInt());
      Logging::info(0, fmt::format("PIXIT {0}.multiplier: {1}", val_name, (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->multiplier));
      Logging::info(0, fmt::format("PIXIT {0}.unit: {1}", val_name, (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->unit));
      Logging::info(0, fmt::format("PIXIT {0}.value_: {1}", val_name, (static_cast<iso1Part4_PhysicalValueType *>(PIXIT_MAP[val_name]))->value_));
    }
  }

  ifs.close();

  ifs.open(slac_config, std::ios_base::in);
  if (!ifs.good())
  {
    Logging::error(0, "slac configuration file is not exist");
    Logging::info(0, fmt::format("error {0} : {1}", errno, strerror(errno)));
    return -1;
  }
  IStreamWrapper isw2(ifs);
  Document document2;
  // dom tree
  document2.ParseStream(isw2);
  for (auto it = document2["timer"].MemberBegin(); it < document2["timer"].MemberEnd(); ++it)
  {
    std::string val_name = (*it).name.GetString();
    *(SLAC_TIMER_MAP[val_name]) = (*it).value.GetFloat();
    Logging::info(0, fmt::format("TIMER {0} : {1}", val_name, *(SLAC_TIMER_MAP[val_name])));
  }
  for (auto it = document2["threshold"].MemberBegin(); it < document2["threshold"].MemberEnd(); ++it)
  {
    std::string val_name = (*it).name.GetString();
    *(SLAC_THRESHOLD_MAP[val_name]) = (*it).value.GetUint();
    Logging::info(0, fmt::format("THRESHOLD {0} : {1}", val_name, *(SLAC_THRESHOLD_MAP[val_name])));
  }
  ifs.close();
  return 0;
}