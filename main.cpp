#include <iostream>
#include "main.h"

using namespace icu_55;
using namespace std;

int main() {
    vector<UnicodeString> v = {
            "A", "B", "C", "Ç", "D", "E", "F", "G", "Ğ", "H", "I", "İ", "J", "K",
            "L", "M", "N", "O", "Ö", "P", "R", "S", "Ş", "T", "U", "Ü", "V", "Y",
            "Z", "a", "b", "c", "ç", "d", "e", "f", "g", "ğ", "h", "ı", "i", "j",
            "k", "l", "m", "n", "o", "ö", "p", "r", "s", "ş", "t", "u", "ü", "v",
            "y", "z"
    };

    sort(v.begin(), v.end());

    cout << "Default collation order: " << endl;
    printVectorItems(v);
    cout << endl;

    sort(v.begin(), v.end(), compareAsTrTr);

    cout << "tr_TR collation order: " << endl;
    printVectorItems(v);
    cout << endl;

    return 0;
}

bool compareAsTrTr(const UnicodeString &a, const UnicodeString &b) {
    UErrorCode errorCode = U_ZERO_ERROR;
    Collator *myCollator = Collator::createInstance(Locale("tr", "TR"), errorCode);
    UCollationResult result = myCollator->compare(a, b, errorCode);
    return result == UCollationResult::UCOL_LESS;
}

void printVectorItems(const std::vector<UnicodeString> &v) {
    for (auto s : v) {
        string utf8;
        s.toUTF8String(utf8);
        cout << utf8 << ' ';
    }
}