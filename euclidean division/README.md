
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
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-46-50.png)

C++ answer ***does not match*** with the mathematical computing.

(How to rectify?)

### Python results
```python
print(-17 // 7, -17 % 7)
print(divmod(-17,7))
```
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2018-49-18.png)

Python answer math with the maths.

## Dividend >= 0 and divisor < 0
C++ gives right answers.

Python (may be other languages) give wrong quotient and remainder.

### Mathematical results
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2019-00-04.png)

### C++ results
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << 17 / -7  <<" " << 17 % -7 << '\n';
    
    lldiv_t res = lldiv(17, -7);
    cout << res.quot << " " << res.rem << '\n';

    return 0;
}
```
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2019-07-03.png)

C++ answer match with the maths.

### Python results
```python
print(17 // -7, 17 % -7)
print(divmod(17,-7))
```
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-01%2019-07-14.png)

Python results ***does not match***.

(How to rectify?)

## Dividend <= 0 and divisor < 0

C++, Python, ... (may be other languages), all give wrong results.

(How to rectify?)

### Mathematical results
![alt](https://github.com/Mourad-NOUAILI/data-structures-turorial/blob/main/euclidean%20division/Screenshot%20from%202020-12-02%2021-06-07.png)

### C++ results
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << -17 / -7  <<" " << -17 % -7 << '\n';
    
    lldiv_t res = lldiv(-17, -7);
    cout << res.quot << " " << res.rem << '\n';

    return 0;
}
```

### Python results
```python
print(-17 // -7, -17 % -7)
print(divmod(-17,-7))
```
![alt](./screenshot%20from%202020-12-02%2021-12-59.png)
