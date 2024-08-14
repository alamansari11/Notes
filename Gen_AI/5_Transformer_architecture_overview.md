[previous](./4_Evolution_from_RNNs_to_transformer.md)

[next](./6_Transformer_prediction_process.md)
# Transformer Architecture Overview

## Transformer Revolution

- **Performance Leap**:
    - Transformer architecture enhanced natural language task performance.
    - Significantly advanced regenerative capability.

## Self-Attention Mechanism

- **Key Feature**:
    - Learns relevance and context of all words in a sentence.
    - Applies attention weights to relationships between all words.
    - Captures contextual dependencies across the input sequence.

## Model Workflow Overview

- **Components**:
    - **Encoder** and **Decoder**: Distinct parts of the transformer architecture.
    - **Similarities**: Shared functionalities and operations.

## Tokenization and Embedding

- **Tokenization**: Converts words into numerical representations.
- **Embedding Layer**: Maps tokens into a trainable vector space.
- **Vector Representation**: Encodes meaning and context of tokens.

## Positional Encoding

- **Preserving Word Order**:
    - Positional encoding maintains information about word position in the sentence.
    - Ensures relevance of word position is retained during processing.

## Self-Attention Layer

- **Analysis of Relationships**:
    - Examines relationships between tokens in the input sequence.
    - Captures contextual dependencies for better understanding.

## Multi-Headed Self-Attention

- **Parallel Learning**:
    - Multiple sets of self-attention weights learned independently.
    - Each head focuses on different aspects of language.

## Output Processing

- **Fully-Connected Feed-Forward Network**:
    - Processes output through a network to produce logits.
    - Logits normalized into probability scores for each word using a softmax layer.

## Final Selection

- **Varying Final Selection**:
    - Various methods available to select the most likely token from the probability scores.

Understanding the transformer architecture's components and operations is crucial for grasping its capabilities in natural language processing tasks. Let's delve deeper into each aspect to gain a comprehensive understanding.