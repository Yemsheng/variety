// 智能指针小试



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

    boost::weak_ptr<TC> weak_pc = test_pc2;
    std::cout<<"weak_pc use_count = "<<weak_pc.use_count()<<std::endl;
    // 本以为也有 weak_pc->print_str(3)
    // weak_ptr,没有重载->和* 呵呵, 也没有get(),呵呵呵
    // Compared to shared_ptr, weak_ptr provides a very limited subset of operations
    // http://www.boost.org/doc/libs/1_54_0/libs/smart_ptr/weak_ptr.htm

    boost::shared_ptr<TC> test_pc3 = test_pc2;
    test_pc3->print_str(4);
    std::cout<<"test_pc3 use_count = "<<test_pc3.use_count()<<std::endl;

    return 0;
}
