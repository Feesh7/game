#pragma once

#include "cbase.h"
#include "mom_replay_base.h"
#include "mom_replay_entity.h"

class CMomReplayV1 :
    public CMomReplayBase
{
public:
    CMomReplayV1();
    CMomReplayV1(CBinaryReader* reader);
    virtual ~CMomReplayV1() OVERRIDE;

public:
    virtual uint8 GetVersion() OVERRIDE { return 1; }
    virtual CMomRunStats* GetRunStats() OVERRIDE;
    virtual int32 GetFrameCount() OVERRIDE;
    virtual CReplayFrame* GetFrame(int32 index) OVERRIDE;
    virtual void AddFrame(const CReplayFrame& frame) OVERRIDE;
    virtual bool SetFrame(int32 index, const CReplayFrame& frame) OVERRIDE;
    virtual CMomRunStats* CreateRunStats(uint8 stages) OVERRIDE;
    virtual void RemoveFrames(int num) OVERRIDE;
    virtual void Start(bool firstperson) OVERRIDE;

public:
    virtual void Serialize(CBinaryWriter* writer) OVERRIDE;

private:
    void Deserialize(CBinaryReader* reader);

protected:
    CMomRunStats* m_pRunStats;
    CUtlVector<CReplayFrame> m_rgFrames;
};