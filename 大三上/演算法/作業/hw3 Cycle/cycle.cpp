#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int MAX_EDGES = 1000;
const double EPSILON = 1e-10;
struct WeightedCycle
{
    int weight;
    vector<int> nodes;
    // cmp
    bool operator<(const WeightedCycle &other) const
    {
        return (weight == other.weight) ? nodes[0] < other.nodes[0] : weight < other.weight;
    }
};
class Solution
{
public:
    vector<WeightedCycle> findMinimumCycleBasis(const vector<WeightedCycle> &allCycles, int nodeNum, int edgeNum)
    {
        vector<WeightedCycle> basis;
        vector<WeightedCycle> sortedCycles = allCycles;
        sort(sortedCycles.begin(), sortedCycles.end());
        if (allCycles.size() <= 2)
        {
            return sortedCycles;
        }
        vector<vector<int>> matrix;
        basis.push_back(sortedCycles[0]);
        basis.push_back(sortedCycles[1]);
        matrix.push_back(convertToMat(sortedCycles[0].nodes, nodeNum));
        matrix.push_back(convertToMat(sortedCycles[1].nodes, nodeNum));
        for (int i = 2; i < sortedCycles.size(); ++i)
        {
            bool isCyclebasis = false;
            vector<int> newBasisMat = convertToMat(sortedCycles[i].nodes, nodeNum);
            matrix.push_back(newBasisMat);
            int rank = rankOfMatrix(matrix);
            printMatrix(matrix);
            if (rank == matrix.size())
            {
                isCyclebasis = true;
                basis.push_back(sortedCycles[i]);
                if (matrix.size() == edgeNum - nodeNum + 1)
                {
                    return basis;
                }
            }
            if (!isCyclebasis)
            {
                matrix.pop_back();
            }
        }
        return basis;
    }

private:
    vector<int> convertToMat(const vector<int> &nodes, int nodeNum)
    {
        vector<int> vec(nodeNum, 0);
        for (const int node : nodes)
        {
            vec[node] = 1;
        }
        return vec;
    }
    bool isZeroRow(const vector<int> &row)
    {
        for (int val : row)
        {
            if (val != 0)
                return false;
        }
        return true;
    }
    void printMatrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (int val : row)
            {
                cout << val << "\t";
            }
            cout << endl;
        }
    }
    int rankOfMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int rank = 0;

        vector<bool> usedRows(row, false);

        for (int c = 0; c < col; c++)
        {
            int pivot_row = -1;

            for (int r = 0; r < row; r++)
            {
                if (!usedRows[r] && matrix[r][c] == 1)
                {
                    pivot_row = r;
                    break;
                }
            }

            if (pivot_row != -1)
            {
                usedRows[pivot_row] = true;
                rank++;

                for (int r = 0; r < row; r++)
                {
                    if (r != pivot_row && matrix[r][c] == 1)
                    {
                        for (int j = c; j < col; j++)
                        {
                            matrix[r][j] ^= matrix[pivot_row][j];
                        }
                    }
                }
            }
        }
        return rank;
    }
};
int main(int argc, char *argv[])
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    if (argc != 2)
    {
        cout << "使用方式: " << argv[0] << " <檔案名稱>" << endl;
        return 1;
    }
    // 檔案讀取相關
    ifstream inFile(argv[1]);
    if (!inFile.is_open())
    {
        cout << "無法開啟檔案: " << argv[1] << "\n";
        return 1;
    }
    int nodeNum, edgenum, cost, begin, end, i, j;
    inFile >> nodeNum >> edgenum;
    int A[nodeNum][nodeNum], Cost[nodeNum][nodeNum];
    for (i = 0; i < nodeNum; i++)
        for (j = 0; j < nodeNum; j++)
            A[i][j] = 0;
    for (int i = 0; i < edgenum; ++i)
    {
        inFile >> begin >> end >> cost;
        A[begin][end] = 1;
        A[end][begin] = 1;
        Cost[begin][end] = cost;
        Cost[end][begin] = cost;
    }
    inFile.close();
    int r, f;
    int k, c, pre, no;
    int b = 0;
    int s = 0, e = nodeNum, cycle = 0;
    int temp[nodeNum];
    int order[20000][nodeNum];
    int check_re[20000];
    int check_cycle[nodeNum];
    for (i = 0; i < 20000; i++)
        for (j = 0; j < nodeNum; j++)
            order[i][j] = -1;
    for (i = 0; i < nodeNum; i++)
        order[i][0] = i;
    int adde;
    int t;
    int smallest, compare;
    int m, n;
    vector<WeightedCycle> weightedCycles;
    for (no = 1; no < nodeNum; no++)
    {
        adde = 0;
        s = 0;
        for (k = 0; k < e; k++)
        {
            s = s + b;
            b = 0;
            pre = order[s][no - 1];
            for ((i = order[s][0] + 1); i < nodeNum; i++)
            {
                if (A[pre][i] == 1)
                {
                    for (j = 1; j < (no - 1); j++)
                    {
                        if (order[s][j] == i)
                        {
                            j = -1;
                            break;
                        }
                    }
                    if (j != -1)
                        temp[b++] = i;
                }
            }
            c = 0;

            if (b > 0)
            {
                adde = adde + b - 1;
                for (i = e + adde; i > s; i--)
                {
                    for (j = 0; j < no; j++)
                        order[i + b - 1][j] = order[i][j];
                }
                for (i = s; i < (s + b); i++)
                {
                    order[i][no] = temp[c++];
                    for (j = 0; j < no; j++)
                        order[i][j] = order[s][j];
                    if (no > 1 && A[order[i][no]][order[i][0]] == 1)
                    {

                        for (m = 0; m <= no; m++)
                            check_cycle[m] = order[i][m];

                        compare = 0;

                        for (m = 1; m <= no; m++)
                            compare = compare * 10 + check_cycle[m];
                        compare = compare * 10 + check_cycle[0];

                        check_re[i] = 0;
                        for (m = no; m >= 0; m--)
                            check_re[i] = check_re[i] * 10 + check_cycle[m];

                        for (m = 0; m < i; m++)
                        {
                            if (check_re[m] == compare)
                            {
                                m = -1;
                                break;
                            }
                        }
                        if (m != -1)
                        {
                            vector<int> comb;
                            int weight = 0;
                            for (j = 0; j <= no; j++)
                            {
                                comb.push_back(order[i][j]);
                                if (j > 0)
                                {
                                    weight += Cost[order[i][j - 1]][order[i][j]];
                                }
                            }
                            weight += Cost[order[i][no]][order[i][0]];
                            weightedCycles.push_back({weight, comb});
                            cycle++;
                        }
                    }
                }
            }
            else
            {
                for (i = s; i < e + adde; i++)
                {
                    for (j = 0; j <= no; j++)
                        order[i][j] = order[i + 1][j];
                }
                adde--;
            }
        }
        e = e + adde;
    }
    /*-----------------------------------*/
    Solution solution;
    vector<WeightedCycle> result = solution.findMinimumCycleBasis(weightedCycles, nodeNum, edgenum);
    cout << "Minimum Cycle Basis:" << endl;
    int allweight = 0;
    for (const auto &cycle : result)
    {
        allweight += cycle.weight;
        cout << "Weight: " << cycle.weight << " => ";
        for (int node : cycle.nodes)
        {
            cout << setw(2) << node << " ";
        }
        cout << endl;
    }
    cout << "Number of cycles in basis: " << result.size() << endl;
    cout << "Expected number of cycles: " << (edgenum - nodeNum + 1) << endl;
    cout << "All weight: " << allweight << endl;
    cout << cycle << " cycles" << endl;
    return 0;
}