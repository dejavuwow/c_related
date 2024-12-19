#include <stdio.h>
#include <stdlib.h>

// 定义网格的最大大小
#define MAXN 505

// 定义瓷砖的四种方向
char dirs[4] = {'U', 'D', 'L', 'R'};
// 定义网格数组，用于存储覆盖方案
char grid[MAXN][MAXN];
// 定义网格的行数和列数
int n, m;

// 检查坐标 (x, y) 是否在网格内
int inGrid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 深度优先搜索函数，用于放置瓷砖
int dfs(int x, int y) {
    // 如果已经遍历完所有单元格，检查是否满足条件（只有右上角单元格未覆盖）
    if (x == n) return y == 0 && grid[n - 1][m - 1] == '.';

    // 如果当前位置是右上角的单元格，跳过
    if (x == 0 && y == m - 1) return dfs(x, y - 1);

    // 如果当前位置已经被覆盖或者越界，则跳过
    if (grid[x][y]!= '.' ||!inGrid(x, y)) return dfs(x + (y == m - 1), y % (m - 1));

    // 尝试四种方向放置瓷砖
    for (int i = 0; i < 4; i++) {
        int nx = x + (i < 2? 0 : (i == 2? -1 : 1));
        int ny = y + (i % 2 == 0? (i == 0? -1 : 1) : 0);
        int nnx = x + (i < 2? (i == 0? 1 : -1) : 0);
        int nny = y + (i % 2 == 0? 0 : (i == 2? 1 : -1));

        // 如果相邻两个单元格都在网格内且未被覆盖
        if (inGrid(nx, ny) && grid[nx][ny] == '.' && inGrid(nnx, nny) && grid[nnx][nny] == '.') {
            grid[x][y] = 'C';
            grid[nx][ny] = dirs[i];
            grid[nnx][nny] = (i < 2? dirs[i + 2] : dirs[i - 2]);

            // 继续放置下一个瓷砖
            if (dfs(x + (y == m - 1), y % (m - 1))) return 1;

            // 如果放置失败，回溯
            grid[x][y] = '.';
            grid[nx][ny] = '.';
            grid[nnx][nny] = '.';
        }
    }

    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &n, &m);

        // 初始化网格
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = '.';
            }
        }

        // 从左上角开始放置瓷砖
        if (dfs(0, 0)) {
            printf("Yes\n");
            for (int i = 0; i < n; i++) {
                printf("%s\n", grid[i]);
            }
        } else {
            printf("No\n");
        }
    }

    return 0;
}
