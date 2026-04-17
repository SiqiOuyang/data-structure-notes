#include <iostream>
#include <string>
#include <cctype>   // isspace
#include <cstring>  // strchr, strncpy, strcmp (也可以完全用string方法，但为了与C逻辑一致，这里保留部分C函数)
using namespace std;

const int MAXN = 105;

string p, s;
string pre, suf;

// 去除首尾空白（原地修改，返回有效长度）
int trim(string& str) {
    int l = 0, r = str.size() - 1;
    while (l <= r && isspace((unsigned char)str[l])) l++;
    while (r >= l && isspace((unsigned char)str[r])) r--;
    int len = r - l + 1;
    str = str.substr(l, len); // 直接截取子串
    return len;
}

int main() {
    // 读入模板字符串
    cin >> p;
    int n;
    cin >> n;
    // 清空输入缓冲区中的换行符，防止影响后续 getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // 找到 '*' 的位置
    size_t star_pos = p.find('*');
    pre = p.substr(0, star_pos);          // 前缀部分
    suf = p.substr(star_pos + 1);         // 后缀部分

    while (n--) {
        getline(cin, s);                  // 读取一行，可能包含空格
        // 去除可能的行尾回车符（getline 已经去掉 '\n'，但Windows下可能有 '\r' 残留，保险起见处理一下）
        if (!s.empty() && s.back() == '\r') s.pop_back();

        int len = trim(s);                // 去除首尾空白，并更新 s 和 len
        int suf_len = suf.size();
        bool ok = (len >= (int)pre.size() + suf_len);
        if (ok) {
            // 检查前缀
            ok &= (s.substr(0, pre.size()) == pre);
            // 检查后缀
            ok &= (s.substr(len - suf_len) == suf);
        }
        cout << (ok ? 'Y' : 'N');
    }
    return 0;
}