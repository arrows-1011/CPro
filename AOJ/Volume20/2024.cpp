#include <bits/stdc++.h>

using namespace std;

bool is_blackjack(vector<int> &cards)
{
    return (cards[0] == 1 && cards[1] >= 10);
}

int to_num(char ch)
{
    if (ch == 'A') {
        return 1;
    } else if (ch == 'T') {
        return 10;
    } else if (ch == 'J') {
        return 11;
    } else if (ch == 'Q') {
        return 12;
    } else if (ch == 'K') {
        return 13;
    }
    return (ch - '0');
}

int get_point(int c)
{
    return (c >= 10 ? 10 : c);
}

pair<int, int> get_point(vector<int> &cards)
{
    int point = 0, ace_cnt = 0;
    vector<int> ace;
    for (int i = 0; i < (int)cards.size(); i++) {
        if (cards[i] == 1) {
            ace_cnt++;
            point += 11;
        } else {
            point += get_point(cards[i]);
        }
    }
    int jk = 0;
    for (int i = 0; i < ace_cnt; i++) {
        if (point > 21) {
            point -= 10;
            jk++;
        }
    }
    return make_pair(point, ace_cnt - jk);
}

int main()
{
    int N;
    cin >> N;
    while (N--) {
        char ch;
        vector<int> cards;
        int pile[8];
        for (int i = 0; i < 2; i++) {
            cin >> ch;
            cards.push_back(to_num(ch));
        }
        sort(cards.begin(), cards.end());
        for (int i = 0; i < 8; i++) {
            cin >> ch;
            pile[i] = to_num(ch);
        }
        if (is_blackjack(cards)) {
            cout << "blackjack" << endl;
            continue;
        }
        pair<int, int> p;
        int point = 0;
        for (int i = 0; i < 8; i++) {
            p = get_point(cards);
            point = p.first;
            if (point <= 16) {
                cards.push_back(pile[i]);
            } else if (point == 17 && p.second > 0) {
                cards.push_back(pile[i]);
            } else {
                break;
            }
        }
        point = get_point(cards).first;        
        if (point > 21) {
            cout << "bust" << endl;
        } else {
            cout << point << endl;
        }
    }
    return 0;
}
