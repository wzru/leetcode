/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
  public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    using uint64    = unsigned long long;
    set<uint64> vis;
    void        stepBack(Robot& robot)
    {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    uint64 hash(int x, int y)
    {
        return ((uint64)x << 32) + (unsigned int)y;
    }
    void dfs(int d, int cx, int cy, Robot& robot)
    {
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int    nd = (d + i) % 4;
            int    nx = cx + dx[nd], ny = cy + dy[nd];
            uint64 h = hash(nx, ny);
            if (!vis.count(h) && robot.move()) {
                vis.insert(h);
                dfs(nd, nx, ny, robot);
                stepBack(robot);
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot)
    {
        vis.insert(hash(0, 0));
        dfs(0, 0, 0, robot);
    }
};