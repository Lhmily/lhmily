//
// Created by lhmily on 2019/10/20.
//

#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class LeetCode {
public:



    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        ListNode *my_l1 = l1;
        ListNode *my_l2 = l2;
        ListNode *ret = NULL;
        ListNode *tail = NULL;
        bool is_add = false;
        while (true) {
            int cur = 0;
            if (is_add) {
                ++cur;
            }
            if (NULL != my_l1) {
                cur += my_l1->val;
                my_l1 = my_l1->next;
            }
            if (NULL != my_l2) {
                cur += my_l2->val;
                my_l2 = my_l2->next;
            }
            is_add = (cur >= 10);
            ListNode *tmp = new ListNode(cur % 10);
            if (NULL == ret) {
                ret = tmp;
            } else {
                tail->next = tmp;
            }
            tail = tmp;
            if (!is_add && NULL == my_l1 && NULL == my_l2) {
                break;
            }
        }
        return ret;
    }


    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); ++i) {
            maps[nums[i]] = i;
        }
        vector<int> ret;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            if ((it = maps.find(target - nums[i])) != maps.end()) {
                int j = it->second;
                if (i != j) {
                    ret.push_back(i < j ? i : j);
                    ret.push_back(i < j ? j : i);
                    break;
                }
            }
        }
        return ret;
    }

    int lengthOfLongestSubstring(const string &s) {
        unordered_set<char> set;
        unordered_set<char>::iterator it;
        int ret = 0;
        int l = 0;
        for (char i : s) {
            while (set.find(i) != set.end()) {
                if ((it = set.find(s.at(l))) != set.end()) {
                    set.erase(it);
                }
                ++l;
            }
            set.insert(i);
            if (ret < set.size()) {
                ret = set.size();
            }
        }
        return ret;
    }
};

