// Copyright 2014 Isis Innovation Limited and the authors of InfiniTAM
#pragma once

#ifndef __METALC__

#include "../CPU/ITMSceneReconstructionEngine_CPU.h"

namespace ITMLib
{
    namespace Engine
    {
        template<class TVoxel, class TIndex>
        class ITMSceneReconstructionEngine_Metal : public ITMSceneReconstructionEngine_CPU<TVoxel,TIndex>
        {};
        
        template<class TVoxel>
        class ITMSceneReconstructionEngine_Metal<TVoxel,ITMVoxelBlockHash> : public ITMSceneReconstructionEngine_CPU<TVoxel,ITMVoxelBlockHash>
        {
        public:
            void IntegrateIntoScene(ITMScene<TVoxel, ITMVoxelBlockHash> *scene, const ITMView *view, const ITMTrackingState *trackingState,
                                    const ITMRenderState *renderState);
            
            ITMSceneReconstructionEngine_Metal(void);
        };
        
        template<class TVoxel>
        class ITMSceneReconstructionEngine_Metal<TVoxel,ITMPlainVoxelArray> : public ITMSceneReconstructionEngine_CPU<TVoxel,ITMPlainVoxelArray>
        { };
    }
}

#endif

struct IntegrateIntoScene_VH_Params
{
    Vector2i rgbImgSize, depthImgSize;
    Matrix4f M_d, M_rgb;
    Vector4f projParams_d, projParams_rgb;
    float _voxelSize, mu, maxW;
};