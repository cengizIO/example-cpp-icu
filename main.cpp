#include <iostream>
#include <unicode/coll.h>
#include <vector>

using namespace icu_55;
using namespace std;

int compare(const UnicodeString &a, const UnicodeString &b) {
    UErrorCode errorCode = U_ZERO_ERROR;
    Collator *myCollator = Collator::createInstance(Locale("tr", "TR"), errorCode);
    return 1 - myCollator->compare(a, b);
}

int main() {
    vector<UnicodeString> v = {"A", "B", "C", "Ç", "D", "E", "F", "G", "Ğ", "H", "I",
                               "İ", "J", "K", "L", "M", "N", "O", "Ö", "P", "R", "S",
                               "Ş", "T", "U", "Ü", "V", "Y", "Z",
                               "a", "b", "c", "ç", "d", "e", "f", "g", "ğ", "h", "ı",
                               "i", "j", "k", "l", "m", "n", "o", "ö", "p", "r", "s",
                               "ş", "t", "u", "ü", "v", "y", "z"};

    cout << "Default collation order: ";
    sort(v.begin(), v.end());

    for (auto s : v) {
        std::string utf8;
        s.toUTF8String(utf8);
        cout << utf8 << ' ';
    }
    cout << '\n';

    cout << "Turkish collation order: ";
    sort(v.begin(), v.end(), compare);

    for (auto s : v) {
        std::string utf8;
        s.toUTF8String(utf8);
        cout << utf8 << ' ';
    }

    cout << '\n';

    return 0;
}