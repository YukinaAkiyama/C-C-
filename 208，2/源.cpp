//
//  main.cpp
//  208_2
//
//  Created by MacKenia on 2021/5/26.
//
//
//

#include "time.h"
using namespace std;
int main() {
    // insert code here...
    try {
        mlitime a(666, 66);
    }
    catch (mlitime::overflowhour)
    {
        cout << "����Сʱ����2359��" << endl;
    }
    catch (mlitime::overflowsec)
    {
        cout << "�����볬��59��" << endl;
    }
    return 0;
}