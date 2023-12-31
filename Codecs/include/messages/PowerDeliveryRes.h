

#ifndef EVCC_POWERDELIVERYRES_H
#define EVCC_POWERDELIVERYRES_H

#include "../V2gExiMessage.h"

class PowerDeliveryRes : public V2gExiMessage
{
public:
  PowerDeliveryRes();
  PowerDeliveryRes(std::shared_ptr<V2gExiMessage> &msg);
  virtual ~PowerDeliveryRes();

  responseCodeType getResponseCode();
  void setResponseCode(responseCodeType code);

  AC_EVSEStatusType *getACEVSEStatus();
  void setACEVSEStatus(AC_EVSEStatusType *status);

  DC_EVSEStatusType *getDCEVSEStatus();
  void setDCEVSEStatus(DC_EVSEStatusType *status);

  EVSEStatusType *getEVSEStatus();
  void setEVSEStatus(EVSEStatusType *status);

  void dumpMsg(void) override;
  comparision_indicate_flag pAC_EVSEStatus_flag = omit;
  comparision_indicate_flag pDC_EVSEStatus_flag = omit;
  comparision_indicate_flag pEVSEStatus_flag = omit;
  comparision_indicate_flag mResponseCode_flag = specific;

  bool operator==(PowerDeliveryRes &object_compare)
  {
    bool arr_result[4] = {true, true, true, true};
    bool final_result = true;
    AC_EVSEStatusType *pAC_EVSEStatusCmp = object_compare.getACEVSEStatus();
    DC_EVSEStatusType *pDC_EVSEStatusCmp = object_compare.getDCEVSEStatus();
    EVSEStatusType *pEVSEStatusCmp = object_compare.getEVSEStatus();

    switch (this->pAC_EVSEStatus_flag)
    {
    case specific:
      if ((pAC_EVSEStatusCmp != nullptr) && (this->pAC_EVSEStatus != nullptr))
      {
        arr_result[0] = (0 == memcmp(pAC_EVSEStatusCmp, this->pAC_EVSEStatus, sizeof(AC_EVSEStatusType)));
      }
      else
      {
        arr_result[0] = false;
      }
      break;
    case has_value:
      if (pAC_EVSEStatusCmp == nullptr)
      {
        arr_result[0] = false;
      }
      break;
    case omit:
    default:
      break;
    }
    switch (this->pDC_EVSEStatus_flag)
    {
    case specific:
      if ((pDC_EVSEStatusCmp != nullptr) && (this->pDC_EVSEStatus != nullptr))
      {
        arr_result[1] = (0 == memcmp(pDC_EVSEStatusCmp, this->pDC_EVSEStatus, sizeof(DC_EVSEStatusType)));
      }
      else
      {
        arr_result[1] = false;
      }
      break;
    case has_value:
      if (pDC_EVSEStatusCmp == nullptr)
      {
        arr_result[1] = false;
      }
      break;
    case omit:
    default:
      break;
    }
    switch (this->pEVSEStatus_flag)
    {
    case specific:
      if ((pEVSEStatusCmp != nullptr) && (this->pEVSEStatus != nullptr))
      {
        arr_result[2] = (0 == memcmp(pEVSEStatusCmp, this->pEVSEStatus, sizeof(DC_EVSEStatusType)));
      }
      else
      {
        arr_result[2] = false;
      }
      break;
    case has_value:
      if (pEVSEStatusCmp == nullptr)
      {
        arr_result[2] = false;
      }
      break;
    case omit:
    default:
      break;
    }
    switch (this->mResponseCode_flag)
    {
    case specific:
      if (this->mResponseCode != object_compare.getResponseCode())
      {
        arr_result[3] = false;
      }
      break;
    case has_value:
      if (object_compare.getResponseCode() > 25)
      {
        arr_result[3] = false;
      }
      break;
    case omit:
    default:
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      if (arr_result[i] == false)
      {
        final_result = false;
        break;
      }
    }
    return final_result;
  }

private:
  AC_EVSEStatusType *pAC_EVSEStatus = nullptr;
  DC_EVSEStatusType *pDC_EVSEStatus = nullptr;
  EVSEStatusType *pEVSEStatus = nullptr;
  responseCodeType mResponseCode = (responseCodeType)26;
};

#endif //EVCC_POWERDELIVERYRES_H
