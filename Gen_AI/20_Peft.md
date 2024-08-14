# Study Notes: Parameter Efficient Fine-Tuning (PEFT)

## Introduction

- **Computational Intensity of LLM Training**:
  - Full fine-tuning entails significant memory requirements beyond model weights.
- **Parameter Efficient Fine-Tuning (PEFT)**:
  - Addresses memory constraints by updating only a subset of parameters.
  - Reduces memory footprint and computational burden compared to full fine-tuning.

## Methods of PEFT

### 1. Selective Methods

- **Fine-tuning Subset of Parameters**:
  - Focuses on specific layers, components, or parameter types.
  - Mixed performance with trade-offs between parameter and compute efficiency.

### 2. Reparameterization Methods

- **Reducing Parameters with Low Rank Transformations**:
  - Creates new low-rank transformations of original network weights.
  - Example: LoRA technique.

### 3. Additive Methods

- **Introduction of New Trainable Components**:
  - Keeps original LLM weights frozen and adds new trainable components.
  - Two Approaches:
    - **Adapter Methods**: Introduce new trainable layers within the architecture, often after attention or feed-forward layers.
    - **Soft Prompt Methods**: Manipulate input or prompt embeddings to enhance performance.

## PEFT in Practice

- **Benefits**:
  - Enables efficient adaptation of the original model to multiple tasks.
  - Reduces memory requirements and inference costs.

- **Trade-offs**:
  - Parameter efficiency, memory efficiency, training speed, model quality, and inference costs must be considered.

## Soft Prompt Methods: Prompt Tuning

- **Manipulating Input for Improved Performance**:
  - Adds trainable parameters to prompt embeddings or retrain embedding weights.
  - Focuses on keeping model architecture fixed while enhancing performance.

## Conclusion

- **PEFT Strategies**:
  - Offer solutions to memory constraints in LLM training.
  - Selective, reparameterization, and additive methods cater to different trade-offs and requirements.
- **Next Steps**:
  - Explore LoRA method in detail to understand memory reduction in PEFT.