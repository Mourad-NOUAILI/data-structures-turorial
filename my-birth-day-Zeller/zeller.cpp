#include <bits/stdc++.h>

int main(){
    std::string date;
    std::cin >> date;

    // Regular expression for the date (it don't check if the year is leap or not )
    std::regex re("^([1-9]|0[1-9]|[12][0-9]|3[0-1])\\/([1-9]|0[1-9]|1[0-2])\\/(\\d{4})$");
    std::smatch matches;

    if (!std::regex_search (date, matches, re )) {
        std::cout << "Date must be valid format (dd/mm/yyyy)\n";
        return 0;
    }

    // Extract year(ssaa), day(q) and month(m)
    int ssaa = stoi(matches[3]);
    int q = stoi(matches[1]);
    int m = stoi(matches[2]);

    if (ssaa < 1583) {
        std::cout << "No need to go so back\n";
        return 0;
    }

    // Check i the year is leap or not
    bool is_leap = ssaa %4 == 0 && (ssaa %100 != 0 || ssaa % 400 == 0);
    if (is_leap && q > 30 ){
        std::cout << "It don't exist\n";
        return 0;
    }
    else if (!is_leap && q > 28) {
        std::cout << "It don't exist\n";
        return 0;
    }

    // Every things is good 
    if (m == 1 or m == 2) {
        m += 12;
        ssaa--;
    }
    
    int ss = ssaa / 100;
    int aa = ssaa % 100;

    int z = q + trunc(2.6*(m+1)) + aa + aa / 4 + ss / 4 - 2 * ss;

    // If we keep this formula, program could gives wrong answers for z < 0
    // int day_rank = z % 7;

    // The right formula to compute the remainder is:
    int day_rank = ((z % 7) + 7) % 7;

    std::string days_of_week[7] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

    std::cout << days_of_week[day_rank] << '\n';

    return 0;
}