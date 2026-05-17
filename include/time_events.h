#ifndef GUARD_TIME_EVENTS_H
#define GUARD_TIME_EVENTS_H

void UpdateMirageRnd(u16 days);
bool8 IsMirageIslandPresent(void);
void UpdateBirchState(u16 days);
void RespawnRandomOWItem(void);
void ResetWildOverworldMons(void);
void RestockBerryMasterCellar(void);
void CountBikeDeliveryDays(u16 days);
void ResetDailyTrainers(void);
void ProgressLavarborTunnelState(void);
void TryShowShadyTruck(void);
void CheckRoamingNPCAtLocation(u32 flagId, u8 mapNum, u8 mapGroup);
void ClearRoamingTraderFlags(void);

#endif // GUARD_TIME_EVENTS_H
