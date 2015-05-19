#ifndef SANDBOX_CPP_ICU_MAIN_H
#define SANDBOX_CPP_ICU_MAIN_H

#include <unicode/coll.h>
#include <vector>

void printVectorItems(const std::vector<UnicodeString> &v);

bool compareAsTrTr(const UnicodeString &a, const UnicodeString &b);

#endif //SANDBOX_CPP_ICU_MAIN_H
