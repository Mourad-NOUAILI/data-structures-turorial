#include "sll.cpp"


int main() {

    sll<int> my_sll;

    for (int i = 1 ; i <= 10 ; ++i)
        my_sll.add_back(i*2);


    //my_sll.display();
    std::cout << my_sll.size() << '\n';
    my_sll.add_at(-50, 0);
    std::cout << my_sll.size() << '\n';
    my_sll.display();

    /*std::cout << my_sll.peak_first() << '\n';
    std::cout << my_sll.peak_last() << '\n';

    std::cout << my_sll.peak_at(0) << '\n';
    std::cout << my_sll.peak_at(my_sll.size()-1) << '\n';
    std::cout << my_sll.peak_at(5) << '\n';*/

    //std::cout << "+++" << my_sll.pop_first() << '\n';

    //my_sll.display();

    /*my_sll.clear();

    my_sll.display();*/
    std::cout << my_sll.size() << '\n';
    //std::cout << my_sll.pop_at(11) << '\n';

    if (my_sll.contains(21))
        std::cout << "ok";
    else
        std::cout << "no";

    my_sll.display();

    return 0;
}