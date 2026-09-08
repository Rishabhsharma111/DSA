class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int tankcost = 0;   // current journey
        int total = 0;      // entire journey
        int starting = 0;

        for(int i = 0; i < gas.size(); i++) {

            int diff = gas[i] - cost[i];

            // Current starting point
            tankcost += diff;

            // Entire circuit
            total += diff;

            if(tankcost < 0) {

                // Current start failed
                starting = i + 1;

                // Start a new journey
                tankcost = 0;
            }
        }

        // Overall gas is insufficient
        if(total < 0) {
            return -1;
        }

        return starting;
    }
};