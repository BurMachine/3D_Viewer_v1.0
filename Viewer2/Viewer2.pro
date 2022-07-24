QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/gryffind_dev/matrix/check.c \
    ../src/gryffind_dev/matrix/determinant.c \
    ../src/gryffind_dev/matrix/s21_calc_complements.c \
    ../src/gryffind_dev/matrix/s21_create_matrix.c \
    ../src/gryffind_dev/matrix/s21_eq_matrix.c \
    ../src/gryffind_dev/matrix/s21_inverse_matrix.c \
    ../src/gryffind_dev/matrix/s21_mult.c \
    ../src/gryffind_dev/matrix/s21_remove_matrix.c \
    ../src/gryffind_dev/matrix/s21_sum_sub.c \
    ../src/gryffind_dev/matrix/s21_transpon.c \
    ../src/gryffind_dev/parsing.c \
    ../src/gryffind_dev/supportFunction.c \
    ../src/translator.c \
    main.cpp \
    mainwindow.cpp \
    widget.cpp

HEADERS += \
    ../src/gryffind_dev/matrix/s21_matrix.h \
    ../src/gryffind_dev/parsing.h \
    ../src/underfile.h \
    mainwindow.h \
    widget.h

FORMS += \
    mainwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../src/gryffind_dev/matrix/Makefile \
    ../src/gryffind_dev/matrix/check.o \
    ../src/gryffind_dev/matrix/determinant.o \
    ../src/gryffind_dev/matrix/libs21_matrix.a \
    ../src/gryffind_dev/matrix/s21_calc_complements.o \
    ../src/gryffind_dev/matrix/s21_create_matrix.o \
    ../src/gryffind_dev/matrix/s21_eq_matrix.o \
    ../src/gryffind_dev/matrix/s21_inverse_matrix.o \
    ../src/gryffind_dev/matrix/s21_matrix.a \
    ../src/gryffind_dev/matrix/s21_mult.o \
    ../src/gryffind_dev/matrix/s21_remove_matrix.o \
    ../src/gryffind_dev/matrix/s21_sum_sub.o \
    ../src/gryffind_dev/matrix/s21_transpon.o
