project(third_party)

find_package(Python3 REQUIRED)
set(PYTHON_PACKAGE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/polygon-cli")
set(PYTHON_PACKAGE_NAME "polygon_cli")

execute_process(
    COMMAND ${Python3_EXECUTABLE} -c 
    "import importlib.util; exit(1 if importlib.util.find_spec('${PYTHON_PACKAGE_NAME}') else 0)"
    RESULT_VARIABLE PACKAGE_FOUND
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# If not installed, install it from source
if (PACKAGE_FOUND)
    message(STATUS "Python package '${PYTHON_PACKAGE_NAME}' is already installed.")
else()
    message(STATUS "Installing '${PYTHON_PACKAGE_NAME}' from '${PYTHON_PACKAGE_PATH}'...")
    execute_process(
		COMMAND ${Python3_EXECUTABLE} -m pip install setuptools requests colorama prettytable pyyaml
        COMMAND ${Python3_EXECUTABLE} -m pip install -e ${PYTHON_PACKAGE_PATH}
		WORKING_DIRECTORY ${PYTHON_PACKAGE_PATH}
        RESULT_VARIABLE PIP_INSTALL_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (PIP_INSTALL_RESULT)
        message(FATAL_ERROR "Failed to install '${PYTHON_PACKAGE_NAME}' from source.")
    endif()
endif()

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/.polygon-cli/testlib.h
    COMMAND polygon-cli init ${PROBLEM_ID}
    COMMAND polygon-cli update
	COMMAND polygon-cli add resource src/cmdparser.h
	COMMAND polygon-cli add solution src/solutions/main_correct_solution.cpp
	COMMAND polygon-cli add source src/generators/main_generator.cpp
	COMMAND polygon-cli add validator src/validators/main_validator.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Initializing and updating Polygon problem"
    VERBATIM
)

add_custom_target(polygon_init
    DEPENDS ${CMAKE_SOURCE_DIR}/.polygon-cli/testlib.h
)