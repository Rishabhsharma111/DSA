class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++) {

            // Check left side
            if ((i == 0 || flowerbed[i - 1] == 0) &&

                // Current position should be empty
                flowerbed[i] == 0 &&

                // Check right side
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
};