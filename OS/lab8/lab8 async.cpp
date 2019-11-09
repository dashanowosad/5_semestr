#include <future>
  #include <iostream>
  #include <thread>

	int z = 0;
  int main(int argc, char* argv[]) {
      int count = 100;

      auto future1 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future1 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future2 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future2 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future3 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future3 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future4 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future4 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future5 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future5 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future6 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future6 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future7 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future7 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future8 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future8 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future9 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future9 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
     auto future10 = std::async(std::launch::async, [&count] {
          for(int i=0; i<count; ++i) {
          	z+=20;
            std::cout << "Future10 " << z << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });

    return 0;
}
