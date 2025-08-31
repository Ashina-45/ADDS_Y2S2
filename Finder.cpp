#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t pos = 0;

    for (size_t i = 1; i <= s2.size(); i++) {
        string prefix = s2.substr(0, i);
        size_t found = s1.find(prefix, pos);

        if (found != string::npos) {
            result.push_back(found);
            pos = found;
        } else {
            while (i <= s2.size()) {
                result.push_back(-1);
                i++;
            }
            break;
        }
    }
    return result;
}
