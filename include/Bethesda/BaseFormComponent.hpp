#pragma once

class BaseFormComponent {
  public:
    BaseFormComponent();
    ~BaseFormComponent();

    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(BaseFormComponent* apComponent);
    virtual bool CompareComponent(BaseFormComponent* apComponent);
};

static_assert(sizeof(BaseFormComponent) == 0x4, "BaseFormComponent has wrong size");
