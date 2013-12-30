

#include <iostream>
#include <string>
#include <boost/smart_ptr.hpp>

class TC {
public:
    TC(std::string strParam):str(strParam){
        std::cout<<"TC constructor"<<std::endl;
    }
    ~TC(){
        std::cout<<"~TC destructor"<<std::endl;
    }
    void print_str(int flag=0){
        std::cout<<flag<<" "<<str<<std::endl;
    }

private:
    std::string str;

};


boost::shared_ptr<TC> func_test(){
    boost::shared_ptr<TC> test_pc(new TC("hello world"));
    test_pc->print_str(1);
    std::cout<<"use_count = "<<test_pc.use_count()<<std::endl;
    return test_pc;
}

int main(){
    boost::shared_ptr<TC> test_pc2 = func_test();
    test_pc2->print_str(2);
    std::cout<<"test_pc2 use_count = "<<test_pc2.use_count()<<std::endl;

    boost::shared_ptr<TC> test_pc3 = test_pc2;
    test_pc3->print_str(3);
    std::cout<<"test_pc3 use_count = "<<test_pc3.use_count()<<std::endl;

    return 0;
}
