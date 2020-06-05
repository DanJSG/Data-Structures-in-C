#ifndef HASHES_H_INCLUDED
#define HASHES_H_INCLUDED

int hashcode(const unsigned char* str);
uint32_t fnv1a_32(const unsigned char* str);

#endif //HASHES_H_INCLUDED
