#pragma once

namespace CommonLib {

  class D3DQuery
  {
    public:
      D3DQuery();
      ~D3DQuery();
  };

  static_assert(sizeof(D3DQuery) == 0x1, "D3DQuery has wrong size");
    
} // namespace CommonLib
