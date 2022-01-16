class Solution {
public:
    bool isSubsequence(string s, string t) {
        // �ж� t �Ƿ��� s ��������

        int n = s.size(), m = t.size();
        
        // ��� t ���ȴ��� s��һ������������
        if(m > n) return false;

        // ��¼��ǰ s ��ƥ�䵽���ĸ�λ��
        int i = 0;
        for(char ch : t) {
            while(i < n && s[i] != ch) i++;
            if(i >= n) return false;

            // ��ʱ s[i] = ch���´�Ҫ�� s[i + 1] ��ʼƥ��
            i++;
        }

        return true;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        // �����ġ��ֵ����С������ǰ�棬����һ���ҵ������ǽ��
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });

        for(string &t : dictionary) {
            if(isSubsequence(s, t)) return t;
        }

        // ���û�ҵ�
        return "";
    }
};
