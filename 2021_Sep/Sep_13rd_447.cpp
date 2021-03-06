//
// Created by smg_nwafu on 2021/9/13.
//
#include <vector>
#include <unordered_map>
#include <dbg.h>

using namespace std;
/**
 * 447. 回旋镖的数量(中等)
 */
class Solution{
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        unordered_map<int,int> map;
        for (auto& p : points) {
            map.clear();
            for(auto& q : points){
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                /*
                 * 在这个地方进行了优化，m*(m-1) = 2 * (0 + 1 + …… + m -1)
                 */
                count += 2 * map[dis]++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> points = {{0,0},{1,0},{2,0}};
    dbg(solution.numberOfBoomerangs(points));
}