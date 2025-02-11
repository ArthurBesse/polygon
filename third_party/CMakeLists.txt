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