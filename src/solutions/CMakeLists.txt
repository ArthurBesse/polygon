project(polygon)

add_compile_definitions(ABESSE)

add_executable(main_correct_solution main_correct_solution.cpp)
set_target_properties(main_correct_solution PROPERTIES FOLDER "Solutions")
