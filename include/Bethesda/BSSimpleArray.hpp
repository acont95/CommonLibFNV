#pragma once
#include <cstdint>

namespace CommonLib {

  template <typename T, std::uint32_t N>
  class BSSimpleArray
  {
    public:
      BSSimpleArray(unsigned int aiInitialSize);
      virtual ~BSSimpleArray();
      virtual T* _Allocate(unsigned int aiSizeInItem);
      virtual void _Deallocate(T* apBuffer);
      virtual T* _Reallocate(T* apBuffer, unsigned int aiNewSizeInItem);

      void _ReallocateBuffer(unsigned int aiNewSize, unsigned int aiCopyCount);
      void _InitialSetup(unsigned int aiReserveSize, unsigned int aiInitialSize);
      void _ConstructItems(T *apFirstAddr, unsigned int aiCount);
      void _DestructItems(T* apFirstAddr, unsigned int aiCount);
      void _MoveItems(T* apDestAddr, T* apSrcAddr, unsigned int aiCount);

      unsigned int Add(const T& aValue);
      unsigned int AddUninitialized();
      void Insert(unsigned int aiIndex, const T& aValue);
      void Remove(unsigned int aiIndex, bool abShrink);
      void RemoveFast(unsigned int aiIndex, unsigned int aiHowMany);
      void RemoveRange(unsigned int aiIndex, unsigned int aiHowMany, bool abShrink);
      void Clear(bool abFreeMemory);
      void SetSize(unsigned int aiNewSize, bool abFreeMemory);
      void SetReservedSize(unsigned int aiReserveSize);
      void Reverse();
      void SortedInsert(const T& aValue, int (*apFunc)(const void* apVal1, const void* apVal2));
      unsigned int Find<K>(const T& aValue, unsigned int aiStartIndex, bool (*apFunc)(const T& aOne, const T& aTwo)) const;
      bool CompareBuffer(BSSimpleArray<T, N>* aDestArray) const;
      void CopyTo(BSSimpleArray<T, N>* aDestArray) const;
      static bool DefaultEqualFunction(const T& aOne, const T& aTwo);
      static int QuickSortFunction(const void* apPtr1, const void* apPtr2);

      T& Get(unsigned int aiIndex) const;
      bool Contains(const T& aValue) const;
      unsigned int GetIdealSize() const;

      T* pBuffer;
      std::uint32_t iSize;
      std::uint32_t iReservedSize;
  };

  static_assert(sizeof(BSSimpleArray<void*, 1024>) == 0x10);
  
} // namespace CommonLib
