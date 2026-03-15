#pragma once
#include <cstdint>

class NiProcessorAffinity
{
  public:
    NiProcessorAffinity();
    ~NiProcessorAffinity();

    enum Processor : std::int32_t
    {
      PROCESSOR_0 = 0x1,
      PROCESSOR_1 = 0x2,
      PROCESSOR_2 = 0x4,
      PROCESSOR_3 = 0x8,
      PROCESSOR_4 = 0x10,
      PROCESSOR_5 = 0x20,
      PROCESSOR_6 = 0x40,
      PROCESSOR_7 = 0x80,
      PROCESSOR_8 = 0x100,
      PROCESSOR_9 = 0x200,
      PROCESSOR_10 = 0x400,
      PROCESSOR_11 = 0x800,
      PROCESSOR_12 = 0x1000,
      PROCESSOR_13 = 0x2000,
      PROCESSOR_14 = 0x4000,
      PROCESSOR_15 = 0x8000,
      PROCESSOR_16 = 0x10000,
      PROCESSOR_17 = 0x20000,
      PROCESSOR_18 = 0x40000,
      PROCESSOR_19 = 0x80000,
      PROCESSOR_20 = 0x100000,
      PROCESSOR_21 = 0x200000,
      PROCESSOR_22 = 0x400000,
      PROCESSOR_23 = 0x800000,
      PROCESSOR_24 = 0x1000000,
      PROCESSOR_25 = 0x2000000,
      PROCESSOR_26 = 0x4000000,
      PROCESSOR_27 = 0x8000000,
      PROCESSOR_28 = 0x10000000,
      PROCESSOR_29 = 0x20000000,
      PROCESSOR_30 = 0x40000000,
      PROCESSOR_31 = 0x80000000,
      PROCESSOR_XENON_CORE_0_THREAD_0 = 0x1,
      PROCESSOR_XENON_CORE_0_THREAD_1 = 0x2,
      PROCESSOR_XENON_CORE_1_THREAD_0 = 0x4,
      PROCESSOR_XENON_CORE_1_THREAD_1 = 0x8,
      PROCESSOR_XENON_CORE_2_THREAD_0 = 0x10,
      PROCESSOR_XENON_CORE_2_THREAD_1 = 0x20,
      PROCESSOR_XENON_CORE_0 = 0x3,
      PROCESSOR_XENON_CORE_1 = 0xC,
      PROCESSOR_XENON_CORE_2 = 0x30,
      PROCESSOR_DONT_CARE = 0xFFFFFFFF,
    };

    Processor m_eIdealProcessor;
    unsigned int m_uiAffinityMask;
};

static_assert(sizeof(NiProcessorAffinity) == 0x8, "NiProcessorAffinity has wrong size");
