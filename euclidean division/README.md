
# Euclidean division

[See details in Wiki](https://en.wikipedia.org/wiki/Euclidean_division)

![alt Division theorem](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-04-16.png)

![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-07-27.png)

## Dividend >= 0 and divisor > 0
In this case, there is no problem. As you see, the mathematical results match with the C++ and Python results or any other langage.
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

### Python results
```python
print(17 // 7, 17 % 7)
print(divmod(17,7))
```
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-34-00.png)

## Dividend <= 0 and divisor > 0
Python give a correct answer.

C++, Pascal (may be other langages) give **wrong answers** (see mathematical results for this section.)

### Mathematical results
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-43-52.png)

### C++ results
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << -17 / 7  <<" " << -17 % 7 << '\n';
    
    lldiv_t res = lldiv(-17, 7);
    cout << res.quot << " " << res.rem << '\n';

    return 0;
}
```
