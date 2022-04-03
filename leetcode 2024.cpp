class Solution {
public:
    int maxConsecutiveChar(string& answerKey, int k, char ch) {
        int n = answerKey.length();
        int left, right, sum;
        for (left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            if (sum > k) {
                sum -= answerKey[left++] != ch;
            }
        }
        return right-left;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                   maxConsecutiveChar(answerKey, k, 'F'));
    }
};
