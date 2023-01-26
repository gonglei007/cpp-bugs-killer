#include <iostream>
#include <cstring>
using namespace std;

typedef struct bot_state_s
{
    // ...
    char teamleader[32] = "leader_name";
    bool dead = false;
    // ...
}bot_state_t;

/**
*
*/
void BotTeamAI( bot_state_t* bs ){
    // ...
    bs->teamleader[sizeof( bs->teamleader )] = '\0';
    // ...
}

int main()
{
    bot_state_t bot_state;
    bot_state.dead = true;
//    strcpy(bot_state.teamleader, "leader_name");

    BotTeamAI(&bot_state);
    cout << "teamleader dead?-" << bot_state.dead << endl;  // 看看bot_state.dead输出了什么？
    return 0;
}


