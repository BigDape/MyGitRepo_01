#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        return isLastOrder(sequence,0,sequence.size()-1);
    }
private:
    bool isLastOrder(vector<int>& sequence, int b, int e)
    {
        if (b == e)
            return true;
        int mid = b;
        while (sequence[mid++]<sequence[e]&&mid<e);
        int tmp = mid;
        while (sequence[tmp++]<sequence[e]&&tmp<e);
        if (tmp < e) return false;
        if (mid == b || mid == e)
        {
            return isLastOrder(sequence,b,e-1);
        }
        else
        {
            return (isLastOrder(sequence, b, mid - 1) && isLastOrder(sequence, mid, e - 1));
        }
    }
};