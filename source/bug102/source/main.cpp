#include <iostream>
using namespace std;

/**
* 检查投票通过率是否超过2/3。
*/
bool CheckVotePassed(int votes, int total)
{
    const int votePassNumber = 2;
    const int voteTotalNum = 3;
    return votes/total > votePassNumber/voteTotalNum;
}

int main()
{
    cout << "投票是否通过:" << CheckVotePassed(40, 50) << endl;
    return 0;
}
