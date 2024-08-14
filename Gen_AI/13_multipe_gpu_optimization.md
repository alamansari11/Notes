# Scaling Model Training Across Multiple GPUs

## Introduction
- It is likely that you will need to scale model training beyond a single GPU, especially for large models.
- Using multiple GPUs offers benefits even for smaller models, such as faster training.

## Distributed Data Parallel (DDP)
- DDP is a popular technique for model replication across multiple GPUs.
- It copies the model onto each GPU and processes data batches in parallel.
- Synchronization step updates the model on each GPU, keeping them identical.
- Requires model weights, parameters, gradients, and optimizer states to fit on a single GPU.

## Modal Sharding: Fully Sharded Data Parallel (FSDP)
- FSDP is useful when your model doesn't fit on a single GPU due to memory constraints.
- It optimizes memory by distributing model states (parameters, gradients, optimizer states) across GPUs with no overlap.
- Based on the ZeRO (Zero Redundancy Optimizer) technique proposed by Microsoft researchers.

## ZeRO Optimization Stages
- ZeRO Stage 1: Distributes only optimizer states across GPUs, reducing memory footprint by up to 4 times.
- ZeRO Stage 2: Distributes gradients across GPUs, further reducing memory usage.
- ZeRO Stage 3: Distributes all components, including model parameters, linearly reducing memory with the number of GPUs.

## FSDP Implementation
- FSDP combines data distribution with model sharding, allowing training of large models that don't fit on a single GPU.
- It synchronizes gradients across GPUs, similar to DDP.
- The sharding factor can be adjusted to balance performance and memory utilization.
- Full sharding offers maximum memory savings but increases GPU communication.

## Performance Comparison: FSDP vs. DDP
- FSDP outperforms DDP for larger models (over 2.28 billion parameters) and handles models that DDP cannot due to memory errors.
- FSDP achieves higher teraflops when lowering model precision to 16-bit.
- Increasing the number of GPUs for an 11 billion parameter model results in a slight decrease in performance due to increased communication volume.

## Conclusion
- FSDP allows seamless scaling of model training across multiple GPUs for both small and large models.
- Training models across GPUs is technically complex and expensive, driving research into achieving better performance with smaller models.