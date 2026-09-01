class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        // id[i][j] = bit number of litter at (i,j)
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litter = 0;

        // Find starting position and assign bit to each litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                else if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        // No litter
        if (litter == 0)
            return 0;

        int totalMasks = 1 << litter;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        /*
            mask = 1 means litter is NOT collected
            mask = 0 means litter is collected
        */

        int startMask = totalMasks - 1;

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, startMask});

        visited[sr][sc][energy][startMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot move without energy
                if (currEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Boundary
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Every move normally costs 1 energy
                    int nextEnergy = currEnergy - 1;

                    // R resets energy
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    }

                    int nextMask = mask;

                    // If we reach litter
                    if (classroom[nr][nc] == 'L') {

                        int bit = id[nr][nc];

                        // Mark litter as collected
                        nextMask &= ~(1 << bit);
                    }

                    // New state
                    if (!visited[nr][nc][nextEnergy][nextMask]) {

                        visited[nr][nc][nextEnergy][nextMask] = true;

                        q.push({
                            nr,
                            nc,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};