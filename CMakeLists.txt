cmake_minimum_required(VERSION 3.16)

project(TrainingMachine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TrainingMachine
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        InstructionTable.h InstructionTable.cpp
        Utils.h Utils.cpp
        Instruction.h Instruction.cpp
        InstructionTableView.h InstructionTableView.cpp
        InstructionCompleter.h InstructionCompleter.cpp
        InstructionCellHandler.h InstructionCellHandler.cpp
        resources.qrc
        InstructionInterpreter.h InstructionInterpreter.cpp
        Instructions/IInstruction.h
        Memory.h Memory.cpp
        ExecutionContext.h
        Instructions/ArithmeticInstruction.h
        Instructions/AddInstruction.cpp Instructions/AddInstruction.h
        Instructions/SubtractInstruction.h Instructions/SubtractInstruction.cpp
        Instructions/MultiplyInstruction.h Instructions/MultiplyInstruction.cpp
        Instructions/DivideInstruction.h Instructions/DivideInstruction.cpp
        Instructions/ModuloInstruction.h Instructions/ModuloInstruction.cpp
        Instructions/AssignmentInstruction.h Instructions/AssignmentInstruction.cpp
        Instructions/BranchInstruction.h Instructions/BranchInstruction.cpp
        Instructions/InstructionFactory.h
        Instructions/JumpInstruction.h Instructions/JumpInstruction.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TrainingMachine APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TrainingMachine SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TrainingMachine
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TrainingMachine PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TrainingMachine)
endif()
set_target_properties(TrainingMachine PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TrainingMachine
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TrainingMachine)
endif()
