#include <algorithm> //find(),find_if()
#include <cctype>//isalnum()
#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool not_url_char(char c) {
    static const string URL_ch = "~;/?:@=&-_.+!*'(),";
    //c�� url�� ���� �ִ� �������� Ȯ���ϸ� ������ ��ȯ

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
    //i���� ���б�ȣ�� �߰��� ��ġ�� ǥ��
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        //���� ��ȣ�� ���� Ž�� ������ ó�� �Ǵ� �������� �ִ��� Ȯ�� 
        if (i != b && i + sep.size() != e) {
            //beg �� �������� �̸��� ������ġ�� ǥ��
            iter beg = i; // :��ġ���� ����
            while (beg != b && isalpha(beg[-1])) {
                --beg; // ������ ����

            }
            //���� ��ȣ �յڷ� url�� �Ϻο��� 
            //��ȿ�� ���ڰ� �ϳ��� �ִ��� Ȯ��
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        //�߰��� ���� ��ȣ�� url �Ϻΰ� �ƴϹǷ� �ش籸�� ��ȣ ���ķ� ǥ���ϵ��� i�� ���� ��Ŵ
        i += sep.size();

    }
    return e;
}


vector<string> find_urls(const string& s) {
    vector<string> URL;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    //�μ��� ���޹��� ���ڿ� ��ü�� Ž��
    while (b != e) {
        // ://�� ���ʿ��� �ϴ� �̻��� ���ڸ� Ž��
        b = URL_beg(b, e);

        if (b != e) {
            //�ش� ���ڸ� ã�Ҵٸ� url�� �������� Ž��
            iter after = URL_end(b, e);
            //URLã���� ����
            URL.push_back(string(b, after));
            //�μ��� ���޹��� ���ڿ����� �� �ٸ� url�� ã�� ���� b�� ����
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