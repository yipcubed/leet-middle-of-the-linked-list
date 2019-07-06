#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/middle-of-the-linked-list/

// #include "../utils/VectorUtils.hpp"
#include "../utils/ListNode.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return nullptr;
        ListNode* slow = head;
        if (!slow->next) return slow;
        ListNode* fast = head->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            else
                return slow;
        }
        return slow;
    }
};

void test1() {
    auto t1 = new ListNode("1,2,3,4,5");
    cout << "3 ? " << Solution().middleNode(t1) << endl;

    auto t2 = new ListNode("1,2,3,4,5,6");
    cout << "4 ? " << Solution().middleNode(t2) << endl;

    auto t3 = new ListNode("1,2,3");
    cout << "2 ? " << Solution().middleNode(t3) << endl;

    auto t4 = new ListNode("1,2");
    cout << "2 ? " << Solution().middleNode(t4) << endl;

    auto t5 = new ListNode("1");
    cout << "null ? " << Solution().middleNode(t5) << endl;

}

void test2() {

}

void test3() {

}