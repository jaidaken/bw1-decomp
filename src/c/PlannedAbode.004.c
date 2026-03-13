#include "PlannedAbode.h"
#include "AbodeInfo.h"

enum ABODE_TYPE __fastcall GetAbodeType__12PlannedAbodeFv(struct PlannedMultiMapFixed* this)
{
    return ((struct GAbodeInfo*)GetInfo__12PlannedAbodeFv())->abodeType;
}
