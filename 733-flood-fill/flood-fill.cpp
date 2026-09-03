class Solution {
public:

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color
    ) {

        int n = image.size();
        int m = image[0].size();

        // Original color of starting cell
        int originalColor = image[sr][sc];

        // If the color is already the same,
        // no work is required.
        if (originalColor == color)
            return image;


        // 4 directions:
        //       (-1,0)
        //          ↑
        // (0,-1) ← (r,c) → (0,1)
        //          ↓
        //        (1,0)

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};


        // Queue stores {row, column}
        queue<pair<int, int>> q;


        // Start BFS from starting cell
        q.push({sr, sc});


        // Change color immediately.
        // This also works as our "visited" mark.
        image[sr][sc] = color;


        // BFS
        while (!q.empty()) {

            // Get current cell
            auto [r, c] = q.front();
            q.pop();


            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];


                // -----------------------------
                // Boundary check
                // -----------------------------

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m) {

                    continue;
                }


                // -----------------------------
                // Only visit cells having
                // the ORIGINAL color
                // -----------------------------

                if (image[nr][nc] != originalColor) {

                    continue;
                }


                // -----------------------------
                // Change color
                // -----------------------------

                image[nr][nc] = color;


                // Add to queue
                q.push({nr, nc});
            }
        }


        // Return modified image
        return image;
    }
};