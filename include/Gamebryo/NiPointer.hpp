#pragma once

template <typename T>
class NiPointer {
  public:
    NiPointer();
    ~NiPointer();

    T* m_pObject;

    operator T* () const;
    T& operator*() const;
    T* operator->() const;
};

static_assert(sizeof(NiPointer<void*>) == 0x4, "NiPointer has wrong size");
