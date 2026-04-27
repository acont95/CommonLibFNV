#pragma once

namespace CommonLib {

  class BaseFormComponent {
    public:

      virtual ~BaseFormComponent();
  };

  static_assert(sizeof(BaseFormComponent) == 0x4, "BaseFormComponent has wrong size");
  
} // namespace CommonLib
