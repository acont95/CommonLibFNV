#pragma once

namespace CommonLib {

  class BaseFormComponent {
    public:
      virtual void InitializeDataComponent();
      virtual void ClearDataComponent();
      virtual void CopyComponent(BaseFormComponent*);
      virtual bool CompareComponent(BaseFormComponent*);
  };

  static_assert(sizeof(BaseFormComponent) == 0x4, "BaseFormComponent has wrong size");
  
} // namespace CommonLib
