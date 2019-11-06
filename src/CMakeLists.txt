add_library(feup-aeda-proj1 model/company/company.cpp model/user/i_user.h model/user/user_manager.cpp auth/current_session.cpp model/rental/rental_manager.cpp model/rental/rental_manager.h model/rental/rental.cpp model/rental/rental.h)

add_executable(application main.cpp)

target_include_directories(feup-aeda-proj1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-aeda-proj1 PUBLIC coverage_config gtest_main)