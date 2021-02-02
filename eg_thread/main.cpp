#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <atomic>
#include <vector>

// //thread 构造函数示例

// void thread_struct_0()
// {
//     std::cout << "this pid id is:" << std::this_thread::get_id() << std::endl; //获取该线程Id
//     std::cout << "this is no parameter function" << std::endl;
// }

// void thread_struct_1(int para_0, std::string para_1)
// {
//     std::cout << "this pid id is:" << std::this_thread::get_id() << std::endl;
//     std::cout << "this is have parameter function;parameter one:"
//               << para_0 << ";parameter two:" << para_1 << std::endl;
// }

// void thread_struct_2(int &para_0)
// {
//     std::cout << "this pid id is:" << std::this_thread::get_id() << std::endl;
//     std::cout << "this is have & parameter function" << std::endl;
//     para_0++;
// }
// //-------------------------------------------------//

// //互斥锁示例

// // int ticket_num = 20;
// std::atomic<int> ticket_num; //单纯的变量可以通过原子变量来进行互斥写操作
// std::mutex mutex_l;          //互斥锁
// //互斥锁只能将相应的临界区不被其他线程调用，但不能保证里面的变量不被其他线程调用，增加个生产函数查看效果
// void sell_ticket(int num) //买票
// {
//     for (int i = 0; i < num; i++)
//     {
//         // if(mutex_l.try_lock())  //该种上锁方式不会堵塞，当检测有线程占用该锁时返回false
//         mutex_l.lock(); //可以通过注释进行效果比较
//         if (ticket_num > 0)
//         {
//             sleep(1);
//             std::cout << "sell " << 20 - ticket_num + 1 << "th ticket" << std::endl;
//             ticket_num--;
//         }
//         mutex_l.unlock();
//     }
// }

// void product_ticket(int num) //生产票
// {
//     for (int i = 0; i < num; i++)
//     {
//         // mutex_l.lock(); //同一个锁只能等另一个线程释放才会不堵塞,即卖票的时候不能生产票
//         if (ticket_num > 0)
//         {
//             sleep(2);
//             ticket_num++;
//             std::cout << "product one ticket,now ticket num is  " << ticket_num << std::endl;
//         }
//         // mutex_l.unlock();
//     }
// }

// //-----------------------------------------------------------//

// //定时锁示例
// std::timed_mutex mutex_t;
// void save_mode(int num)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         while (!mutex_t.try_lock_for(std::chrono::seconds(1))) //这里没有出现阻塞？？？？？？？
//         {
//             // std::this_thread::sleep_for(std::chrono::seconds(1));
//             std::cout << num << " is waiting for save" << std::endl;
//         }
//         sleep(3);
//         std::cout << num << " get save" << std::endl;
//         mutex_t.unlock();
//     }
// }

// //-----------------------------------------------------------//

int main()
{
    // //thread 构造函数示例
    // int num = 0;
    // std::thread thr_null; //这是空线程b
    // std::thread thr[2];
    // thr[0] = std::thread(&thread_struct_0);
    // thr[1] = std::thread(&thread_struct_1, 0, "hello");
    // std::thread thr_(&thread_struct_1, 1, "bye");
    // std::thread thr_eg(&thread_struct_2, std::ref(num));

    // std::thread thr_old = std::thread(&thread_struct_0);
    // std::thread thr_mv(std::move(thr_old));
    // //thr_old转换到转移到thr_mv，因此不需要join,线程没有增加
    // for (auto &t : thr)
    //     t.join();
    // thr_.join();
    // thr_eg.join();
    // thr_mv.join();

    // std::cout << "num:" << num << std::endl;
    // //-----------------------------------//

    // //互斥锁示例
    // ticket_num = 20;
    // std::thread thr[2]; //两个售票员
    // int num = 10;       //每人分到十张
    // thr[0] = std::thread(&sell_ticket, num);
    // thr[1] = std::thread(&sell_ticket, num);
    // std::thread thr_(&product_ticket, 5);
    // for (auto &t : thr)
    //     t.join();
    // thr_.join();
    // //---------------------------------------//

    //定时锁示例
    // std::thread thr[2];
    // thr[0] = std::thread(&save_mode, 1);
    // thr[1] = std::thread(&save_mode, 2);
    // for (auto &t : thr)
    //     t.join();
    //---------------------------------------//

    return 0;
}
