class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int i = 0;
        int j = 0;

        while (j < typed.size()) {

            // Characters match
            if (i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            }

            // Long pressed character
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }

            // Invalid character
            else {
                return false;
            }
        }

        // All characters of name should be matched
        return i == name.size();
    }
};