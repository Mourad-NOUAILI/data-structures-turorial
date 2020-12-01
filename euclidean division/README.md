
# Euclidean division

[See details in Wiki](https://en.wikipedia.org/wiki/Euclidean_division)

![alt Division theorem](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-04-16.png)

![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-07-27.png)

## Dividend >= 0 and divisor > 0
In this case, there is no problem
### Mathematical results
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-30-50.png)

### C++ results
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << 17 / 7  <<" " << 17 % 7 << '\n';
    
    lldiv_t res = lldiv(17, 7);
    cout << res.quot << " " << res.rem << '\n';

    return 0;
}
```
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-27-51.png)
