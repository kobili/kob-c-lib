#include "hashing.h"

uint32_t fnv_hash_32(void* data, int n_bytes) {
    uint32_t hash = 2166136261;
    int fnv_prime = 16777619;

    uint8_t *bytes = (uint8_t *)data;

    for (int i = 0; i < n_bytes; i++) {
        uint8_t octet = bytes[i];
        hash = hash ^ octet;
        hash = hash * fnv_prime;
    }

    return hash;
}
