#include <algorithm> //find(),find_if()
#include <cctype>//isalnum()
#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool not_url_char(char c) {
    static const string URL_ch = "~;/?:@=&-_.+!*'(),";
    //c가 url에 들어갈수 있는 문자인지 확인하면 음수를 반환

    return !(isalnum(c) || find(URL_ch.begin(), URL_ch.end(), c) != URL_ch.end());
}
string::const_iterator URL_end(
    string::const_iterator b,
    string::const_iterator e
) {
    return find_if(b, e, not_url_char);
}
string::const_iterator URL_beg(
    string::const_iterator b,
    string::const_iterator e
) {
    static const string sep = "://";
    typedef string::const_iterator iter;
    //i느느 구분기호를 발견한 위치를 표시
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        //구분 기호가 현재 탐색 범위의 처음 또는 마지막에 있는지 확인 
        if (i != b && i + sep.size() != e) {
            //beg 는 프로토콜 이름의 시작위치를 표시
            iter beg = i; // :위치부터 시작
            while (beg != b && isalpha(beg[-1])) {
                --beg; // 역방행 가기

            }
            //구분 기호 앞뒤로 url의 일부에서 
            //유효한 문자가 하나라도 있는지 확인
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        //발견한 구분 기호는 url 일부가 아니므로 해당구분 기호 이후로 표시하도록 i를 증가 시킴
        i += sep.size();

    }
    return e;
}


vector<string> find_urls(const string& s) {
    vector<string> URL;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    //인수로 전달받은 문자열 전체를 탐색
    while (b != e) {
        // ://의 앞쪽에서 하니 이상의 문자를 탐색
        b = URL_beg(b, e);

        if (b != e) {
            //해당 문자를 찾았다면 url의 나머지를 탐색
            iter after = URL_end(b, e);
            //URL찾으면 저장
            URL.push_back(string(b, after));
            //인수로 전달받은 문자열에서 또 다른 url을 찾기 위해 b를 저장
            b = after;

        }
        
    }
    return URL;
}

int main() {
    string s;
    while (getline(cin, s)) {
        vector <string> v = find_urls(s);

        for (vector<string>::const_iterator i = v.begin();
            i != v.end(); i++) {
            cout << *i << endl;

        }




    }

    return 0;


}