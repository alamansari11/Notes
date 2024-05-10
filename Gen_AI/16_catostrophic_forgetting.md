# Study Notes: Avoiding Catastrophic Forgetting in Fine-tuning

## Introduction: Tailoring LLMs to Specific Tasks

- **Customization Requirement**:
  - While LLMs excel at diverse tasks, some applications may require optimization for a single task.

## Single Task Fine-tuning

- **Purpose**:
  - Improve model performance on a specific task, e.g., summarization.
- **Data Requirement**:
  - Achieve good results with relatively few examples (500-1,000).
- **Potential Issue**:
  - **Catastrophic Forgetting**:
    - Full fine-tuning may degrade performance on other tasks due to weight modification.

## Avoiding Catastrophic Forgetting

1. **Assessing Impact**:
   - Evaluate whether forgetting impacts the use case's requirements.
2. **Multitask Fine-tuning**:
   - Train on multiple tasks simultaneously to maintain generalized capabilities.
   - Requires substantial data (50-100,000 examples) and compute resources.
3. **Parameter Efficient Fine-tuning (PEFT)**:
   - Preserve most pre-trained weights and train task-specific adapter layers.
   - Shows greater resilience to catastrophic forgetting.

## Next Steps

- **Exploring Multitask Fine-tuning**:
  - In-depth discussion on training across multiple tasks simultaneously.
- **Introduction to PEFT**:
  - Techniques preserving pre-trained weights while fine-tuning task-specific parameters.
- **Continuation**:
  - Further insights into avoiding catastrophic forgetting in LLM fine-tuning.