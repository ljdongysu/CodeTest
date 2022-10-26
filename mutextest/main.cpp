// deadlockResolved.cpp

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>




enum ErrorCode {
    // 0x0l xxxx05 - self_test
    SELF_TEST_NO_ERROR = 0x05000000,
    SELF_TEST_CLOUD_START_FAILED = 0x05020001,
    SELF_TEST_VCU_START_FAILED = 0x05020002,
    SELF_TEST_CAN_START_FAILED = 0x05020003,
    SELF_TEST_COPROCESSOR_START_FAILED = 0x05020004,
    SELF_TEST_IMSEE_START_FAILED = 0x05020005,
    SELF_TEST_LASER_START_FAILED = 0x05020006,
    SELF_TEST_TOF_START_FAILED = 0x05020007,

    SELF_TEST_ENDCODER_RATE_ABNORMAL = 0x05020011,
    SELF_TEST_VELOCITY_RATE_ABNORMAL = 0x05020012,
    SELF_TEST_IMG_RATE_ABNORMAL = 0x05020013,
    SELF_TEST_IMGSIGMA_RATE_ABNORMAL = 0x05020014,
    SELF_TEST_IMU_RATE_ABNORMAL = 0x05020015,
    SELF_TEST_ULTRA_RATE_ABNORMAL = 0x05020016,
    SELF_TEST_LASERSCAN_RATE_ABNORMAL = 0x05020017,
    SELF_TEST_TOF_RATE_ABNORMAL = 0x05020018,

    SELF_TEST_UI_NOT_CONNECTED = 0x05020020,

    SELF_TEST_DISK_ALMOST_FULL = 0x05020030,

    // self calibration
    SELF_CALIBRATION_SUCCESS = 0x0133004B,
    SELF_CALIBRATION_FAILURE = 0x0133004C,
    SELF_CALIBRATION_NO_MORE_IMAGES = 0x0133004E,
    SELF_CALIBRATION_LESS_CACHE_IMAGES = 0x0132004D,
    SELF_CALIBRATION_NO_REGISTER_CALLBACK_FUNCTION = 0x0133004F,

    //slam
    SLAM_TEST_NO_ERROR = 0x12000000,
    SLAM_ONLINE_CALIB_FAILED = 0x123301F5,
    SLAM_REV_SAME_IMG = 0x12320065,
    SLAM_REV_SAME_IMU = 0x12320079,
    SLAM_REV_SAME_ODM = 0x1232008D,
    SLAM_REV_SAME_LASER = 0x123200A1,

    SLAM_REV_IMU_LOSS = 0x1232007A,
    SLAM_REV_ODM_LOSS = 0x1232008E,
    SLAM_REV_LASER_LOSS = 0x123200A2,

    SLAM_REV_IMU_LOSS_LONG_TIME = 0x1222007B,
    SLAM_REV_ODM_LOSS_LONG_TIME = 0x1222008F,
    SLAM_REV_LASER_LOSS_LONG_TIME = 0x122200A3,

    SLAM_ONLY_IMU = 0x122200C9,
    SLAM_LACK_MEMORY = 12230051,
    SLAM_LACK_CPU = 12230052,

    SLAM_MODULE_PARAM_READ_FAILED = 0x12220001,
    SLAM_ODM_PARAM_READ_FAILED = 0x12220002,
    SLAM_MAP_READ_FAILED = 0x12220033,

    SLAM_REV_IMU_ABNORMAL = 0x1232007C,
    SLAM_REV_ODM_ABNORMAL = 0x12320090,
    SLAM_REV_LASER_ABNORMAL = 0x123200A4,

    SLAM_LACK_RESULT_CALLBACK_PTR = 0x1222003D,
    SLAM_LACK_MAP_CALLBACK_PTR = 0x1222003E,
    SLAM_LACK_SENTI_MAP_CALLBACK_PTR = 0x1222003F,

    SLAM_INIT_FAILED_NO_MARKER_POSE = 0x12220040,
    SLAM_FINAL_FAILED_NO_MARKER_POSE = 0x12220041,

    SLAM_MODI_MAP_FAILED_LOSS_KEY_DATA = 0x12230040,
    SLAM_REV_MAP_DATA_EMPTY = 0x12230041,

    SLAM_REV_IMU_DELAY = 0x1232007D,
    SLAM_REV_ODM_DELAY = 0x12320091,
    SLAM_REV_LASER_DELAY = 0x123200A5,

    SLAM_REV_IMU_LOSS_ODM_LOSS = 0x1232007E,
    SLAM_REV_IMU_LOSS_LASER_LOSS = 0x1232007F,
    SLAM_REV_ODM_LOSS_LASER_LOSS = 0x12320092,
    SLAM_REV_ODM_LOSS_LASER_LOSS_IMU_LOSS = 0x12320093,

    SLAM_REV_IMU_LOSS_LONG_ODM_LOSS = 0x12320080,
    SLAM_REV_IMU_LOSS_LONG_LASER_LOSS = 0x12320081,
    SLAM_REV_IMU_LOSS_LONG_ODM_LOSS_LONG = 0x12320082,
    SLAM_REV_IMU_LOSS_LONG_LASER_LOSS_LONG = 0x12320083,
    SLAM_REV_IMU_LOSS_LONG_LASER_LOSS_ODM_LOSS = 0x12320084,
    SLAM_REV_IMU_LOSS_LONG_LASER_LOSS_LONG_ODM_LOSS = 0x12320085,
    SLAM_REV_IMU_LOSS_LONG_ODM_LOSS_LONG_LASER_LOSS = 0x12320086,
    SLAM_REV_ODM_LOSS_LONG_LASER_LOSS_LONG = 0x12320094,
    SLAM_REV_ODM_LOSS_LONG_IMU_LOSS = 0x12320095,
    SLAM_REV_ODM_LOSS_LONG_LASER_LOSS = 0x12320096,
    SLAM_REV_ODM_LOSS_LONG_LASER_LOSS_IMU_LOSS = 0x12320097,
    SLAM_REV_ODM_LOSS_LONG_LASER_LOSS_LONG_IMU_LOSS = 0x12320098,
    SLAM_REV_LASER_LOSS_LONG_IMU_LOSS = 0x123200A6,
    SLAM_REV_LASER_LOSS_LONG_ODM_LOSS = 0x123200A7,
    SLAM_REV_LASER_LOSS_LONG_ODM_LOSS_IMU_LOSS = 0x123200A8,
    SLAM_REV_LASER_LOSS_LONG_ODM_LOSS_LONG_IMU_LOSS_LONG = 0x123200A9,

    SLAM_ROBOT_FALL_DOWN = 0x1223012D,
    SLAM_UNDERGROUND_ANGLE_ERROR = 0x1223012E,

    SLAM_RELOCAL_MODI_TOO_MANY = 0x12230141,
    SLAM_RELOCAL_FAILED_OVER_TIME = 0x12230142,

    SLAM_BIG_EMPTY_SURROUNDINGS = 0x12330155,
    SLAM_LONG_CORRIDOR = 0x12330156,

    SLAM_UNCERTAIN_SURROUNDING_BAD_PERCISION = 0x12230157,
    SLAM_LASER_OVER_EXPOSURE = 0x12230158,

    SLAM_SURROUNDING_EXIT_GLASS = 0x12330159,
    SLAM_SURROUNDING_EXIT_MIRROR = 0x1233015A,

    SLAM_ROBOT_SLIPPING = 0x12330169,

    //dl
    DL_INVALID_IMAGE = 0x04220033,
    DL_LACK_IMAGE = 0x04320034,
    DL_LACK_IMAGE_HEAVY = 0x04220035,
    DL_ERROR_IMAGE = 0x04220036,
    DL_LACK_LIDAR = 0x04320065
};

void test1();

ErrorCode ErrorCode1(const std::string &name)
{
    //TODO add other lack image exception
    if (name == "1") return ErrorCode::DL_LACK_IMAGE;
    else if (name == "2") return ErrorCode::DL_LACK_LIDAR;
}
int main()
{
    ErrorCode errorMessageCode = ErrorCode1("1");
    std::cout<<std::to_string(errorMessageCode)<<std::endl;
    errorMessageCode = ErrorCode1("2");
    std::cout<<std::to_string(errorMessageCode)<<std::endl;
    errorMessageCode = ErrorCode1("3");
    std::cout<<std::to_string(errorMessageCode)<<std::endl;

    std::cout<<std::to_string( 0x04320065)<<std::endl;
    test1();
}

std::vector<int> a;
struct CriticalData{
    std::mutex mut;
};
std::mutex mutex1;
void deadLock(CriticalData& a, CriticalData& b){

    std::unique_lock<std::mutex>guard1(a.mut,std::defer_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" <<  std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::unique_lock<std::mutex>guard2(b.mut,std::defer_lock);
    std::cout << "    Thread: " << std::this_thread::get_id() << " second mutex" <<  std::endl;

    std::cout << "        Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;
    std::lock(guard1,guard2);
    // do something with a and b
}

void test1()
{
    while (true)
    {
        try
        {
            a.resize(1);
//            std::lock_guard<std::mutex> lockGuard(mutex1);
            mutex1.lock();
            std::cout << "test1\n";
            a.at(0) = 10;
            mutex1.unlock();
        }
        catch (...)
        {
            std::cout<<"test1 exceptoin!\n"<<std::endl;
        }
    }
}

void test2()
{
    while (true)
    {
        {
            a.resize(1);

//            std::lock_guard<std::mutex> lockGuard(mutex1);
            mutex1.lock();
            a.at(2) = 100;
            std::cout << "test2\n";
            mutex1.unlock();
        }
        sleep(1);

    }
}

//int main(){
//
////    std::cout << std::endl;
////
////    CriticalData c1;
////    CriticalData c2;
////
////    std::thread t1([&]{deadLock(c1,c2);});
////    std::thread t2([&]{deadLock(c2,c1);});
////
////    t1.join();
////    t2.join();
////
////    std::cout << std::endl;
//
//    std::cout << std::endl;
//
//    CriticalData c1;
//    CriticalData c2;
//
//    std::thread t1([&]{test1();});
//    std::thread t2([&]{test2();});
//
//    t1.join();
//    t2.join();
//
//    std::cout << std::endl;
//
//}
