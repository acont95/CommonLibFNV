#pragma once
#include "Bethesda/BSNiNode.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/BSMultiBound.hpp"


class BSMultiBoundNode : BSNiNode
{
  public:
    BSMultiBoundNode();
    ~BSMultiBoundNode();

    NiPointer<BSMultiBound> spMultiBound;
    BSCullingProcess::BSCPCullingType CullingMode;
};
