add_library(person_lib
    ../src/Person.cpp
)

target_include_directories(person_lib PUBLIC
    ../include
)
