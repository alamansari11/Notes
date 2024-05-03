# Study Notes: Training Large Language Models

## Introduction
- **Objective**:
  - Understand the training process of Large Language Models (LLMs).
  - Explore different model architectures and their pre-training objectives.

## Model Selection and Pre-Training

### 1. Scope Definition
- **Task Specificity**:
  - Define the application's purpose and function.
  - Determine the required functionality of the LLM within the application.

### 2. Model Selection
- **Existing Models vs. Training from Scratch**:
  - Consider task complexity and resource availability.
  - Explore model hubs for curated models and model cards for details.

### 3. Pre-Training Overview
- **Initial Training Phase**:
  - Known as pre-training.
  - LLM learns from vast amounts of unstructured textual data.

## Pre-Training Objectives and Model Architectures

### 1. Autoencoding Models (Encoder-Only)
- **Objective**:
  - Pre-trained using masked language modeling.
  - Capture bi-directional representations of input sequences.
- **Tasks**:
  - Sentence classification, named entity recognition.
- **Examples**:
  - BERT, RoBERTa.

### 2. Autoregressive Models (Decoder-Only)
- **Objective**:
  - Pre-trained using causal language modeling.
  - Predict next token based on previous sequence.
- **Tasks**:
  - Text generation.
- **Examples**:
  - GPT, BLOOM.

### 3. Sequence-to-Sequence Models (Encoder-Decoder)
- **Objective**:
  - Varies based on model.
  - Typically use span corruption for encoder and autoregressive decoding for decoder.
- **Tasks**:
  - Translation, summarization, question-answering.
- **Examples**:
  - T5, BART.

## Considerations for Model Selection

### 1. Task Suitability
- **Match Task to Model**:
  - Choose model architecture based on task requirements.
  - Autoencoding for classification, autoregressive for generation, sequence-to-sequence for translation.

### 2. Model Size and Capability
- **Performance Scaling**:
  - Larger models tend to perform better across tasks.
  - Increased capability with larger parameter size.

### 3. Challenges of Training Large Models
- **Resource Intensive**:
  - Training larger models is computationally expensive.
  - Feasibility constraints due to cost and infrastructure requirements.

## Conclusion
- **Informed Model Selection**:
  - Understand pre-training objectives and model architectures.
  - Consider task requirements and resource constraints.
  - Balance between model capability and feasibility.

Understanding the nuances of model architectures and pre-training objectives enables informed decision-making in selecting the appropriate model for your application. Consider task specificity, model capabilities, and training challenges when making your choice.