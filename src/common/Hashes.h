#ifndef HASHES_H_INCLUDED
#define HASHES_H_INCLUDED

/** C implementation of Java's string hashCode() method.
 *  This is a basic, non-cryptographic hash function. */
int hashcode(const unsigned char* str);

/** 32 bit implementation of the FNV-1A hash function.
 *  This hash is not cryptographically secure.*/
uint32_t fnv1a_32(const unsigned char* str);

/** 64 bit implementation of the FNV-1A hash function.
 *  This hash is not cryptographically secure.*/
uint64_t fnv1a_64(const unsigned char* str);

#endif //HASHES_H_INCLUDED
