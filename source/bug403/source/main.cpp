#include <iostream>
#include <cstring>
using namespace std;

typedef struct itemInfo_s
{
    // ...
    int data[5] = {1, 2, 3, 4, 5};
    // ...
}itemInfo_t;

itemInfo_t  gItemInfo;

void CG_RegisterItemVisuals( int itemNum ) {
//	...
	itemInfo_t*	itemInfo = &gItemInfo;
//	...
	memset( itemInfo, 0, sizeof( &itemInfo ) );
//	...
}

/**
* 输出itemInfo的内容。
*/
void printItemInfo(itemInfo_t itemInfo)
{
    for(int i=0; i<5; ++i)
    {
        cout<<itemInfo.data[i];
    }
}

int main()
{
    CG_RegisterItemVisuals(10);
    cout << "CG_RegisterItemVisuals处理完毕后，gItemInfo的data内容是-";
    printItemInfo(gItemInfo); // 为什么会这样？
    cout << endl;
    return 0;
}


