#include "dll.cpp"

int main() {
    /*dll<int> my_dll;


    for (int i = 0 ; i <= 10 ; ++i)
        my_dll.add_begin(i);
    
    my_dll.display();

    my_dll.pop(30);

    my_dll.display();*/
    



   /*test*/ 

   dll<std::string> my_dll1;

    
    my_dll1.add_end("m");
    my_dll1.add_end("x");
    my_dll1.add_end("y");
    my_dll1.add_at(0, "z");

 
    my_dll1.display();


    std::cout << my_dll1.contains("z") << "\n";
  
    my_dll1.display();

    return 0;
}
