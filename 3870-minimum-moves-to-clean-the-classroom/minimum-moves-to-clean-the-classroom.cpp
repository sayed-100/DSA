class Solution {
    int8_t max_e[20][20][1024];
    int litter_idx[20][20];

public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1, k = 0;

        memset(litter_idx, -1, sizeof(litter_idx));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter_idx[r][c] = k++;
                }
            }
        }

        if (k == 0)
            return 0;
        int target_mask = (1 << k) - 1;

        // Reset only the active mask range
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                memset(max_e[r][c], -1, sizeof(int8_t) * (1 << k));
            }
        }

        // State bit-packing: (r << 22) | (c << 17) | (mask << 7) | energy
        queue<uint32_t> q;
        q.push(((uint32_t)sr << 22) | ((uint32_t)sc << 17) | energy);
        max_e[sr][sc][0] = energy;

        int steps = 0;
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                uint32_t state = q.front();
                q.pop();

                int r = (state >> 22) & 0x1F;
                int c = (state >> 17) & 0x1F;
                int mask = (state >> 7) & 0x3FF;
                int curr_e = state & 0x7F;

                if (mask == target_mask)
                    return steps;
                if (curr_e == 0)
                    continue;

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int next_mask = mask;
                    int next_e =
                        (classroom[nr][nc] == 'R') ? energy : curr_e - 1;

                    int l_id = litter_idx[nr][nc];
                    if (l_id != -1) {
                        next_mask |= (1 << l_id);
                    }

                    if (next_e > max_e[nr][nc][next_mask]) {
                        max_e[nr][nc][next_mask] = next_e;
                        q.push(((uint32_t)nr << 22) | ((uint32_t)nc << 17) |
                               ((uint32_t)next_mask << 7) | next_e);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};