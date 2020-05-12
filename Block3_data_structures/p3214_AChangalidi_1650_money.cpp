#include <iostream>
#include <map>
#include <vector>
#include <queue>

#define ll long long

using namespace std;


struct Money {
    string name;
    ll bank;
    int prior;

    Money(string name, ll bank, int prior)
            : name(name), bank(bank), prior(prior) {
    }
};

struct Compare {
    bool operator()(Money const &p1, Money const &p2) {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.bank < p2.bank;
    }
};

map<string, pair<ll, string>> human_money_city;
map<string, pair<ll, int>> city_money_prior;
// массив ответов
map<string, int> city_days;

int main() {
    // n - количество богатеев
    // m - количество дней, о которых есть данные
    // k - количество зарегистрированных перемещений
    int n, m, k;
    cin >> n;

    human_money_city = {};
    city_money_prior = {};
    city_days = {};
    priority_queue<Money, vector<Money>, Compare> money_queue;

    for (int i = 0; i < n; i++) {
        string human_name, city_name;
        ll money;
        cin >> human_name >> city_name >> money;
        human_money_city[human_name].first = money;
        human_money_city[human_name].second = city_name;
        pair<ll, int> &city = city_money_prior[city_name];
        city.first += money;
        money_queue.push(Money(city_name, city.first, ++city.second));
    }


    cin >> m >> k;
    int day_counter = 0;
    for (int i = 0; i < k; i++) {
        int day;
        string human_name, city_name;
        cin >> day >> human_name >> city_name;
        if (day != day_counter) {
            Money p1 = money_queue.top();
            while (p1.prior != city_money_prior[p1.name].second) {
                money_queue.pop();
                p1 = money_queue.top();
            }
            money_queue.pop();
            bool flag = true;
            if (!money_queue.empty()) {
                Money p2 = money_queue.top();
                bool check3 = true;
                while (p2.prior != city_money_prior[p2.name].second) {
                    if (money_queue.size() > 2) {
                        money_queue.pop();
                        p2 = money_queue.top();
                    } else {
                        check3 = false;
                        break;
                    }
                }
                if (check3 and p1.bank == p2.bank) {
                    flag = false;
                }
            }
            money_queue.push(p1);
            while (day != day_counter) {

                if (flag) {
                    city_days[p1.name]++;
                }
                day_counter++;
            }
        }
        pair<ll, string> &human = human_money_city[human_name];
        pair<ll, int> &city = city_money_prior[human.second];
        city.first -= human.first;
        money_queue.push(Money(human.second, city.first, ++city.second));

        human.second = city_name;
        pair<ll, int> &city2 = city_money_prior[human.second];
        city2.first += human.first;
        money_queue.push(Money(city_name, city2.first, ++city2.second));
    }

    if (m != day_counter) {
        Money p1 = money_queue.top();
        while (p1.prior != city_money_prior[p1.name].second) {
            money_queue.pop();
            p1 = money_queue.top();
        }
        money_queue.pop();
        bool flag = true;
        if (!money_queue.empty()) {
            Money p2 = money_queue.top();
            bool check3 = true;
            while (p2.prior != city_money_prior[p2.name].second) {
                if (money_queue.size() > 2) {
                    money_queue.pop();
                    p2 = money_queue.top();
                } else {
                    check3 = false;
                    break;
                }
            }
            if (check3 and p1.bank == p2.bank) {
                flag = false;
            }
        }
        money_queue.push(p1);
        while (m != day_counter) {
            if (flag) {
                city_days[p1.name]++;
            }
            day_counter++;
        }
    }


    // Вывод ответа
    string answer;
    auto it = city_days.begin();
    for (; it != city_days.end(); it++) {
        if (it->second > 0) {
            answer.append(it->first + " " + std::to_string(it->second) + "\n");
        }
    }
    cout << answer;

}