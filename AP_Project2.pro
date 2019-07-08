#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T15:23:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AP_Project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login_signup.cpp \
    login_signup2.cpp \
    cashierpage.cpp \
    managerpage.cpp \
    allproducts.cpp \
    addproduct.cpp \
    adddiscount_code.cpp \
    addiscount_pro.cpp \
    productmain.cpp \
    showcategory.cpp \
    editproducts.cpp \
    basket.cpp \
    buycredit.cpp \
    man_users.cpp \
    addsale.cpp \
    cash_saleee.cpp

HEADERS += \
        mainwindow.h \
    login_signup.h \
    login_signup2.h \
    cashierpage.h \
    managerpage.h \
    allproducts.h \
    addproduct.h \
    adddiscount_code.h \
    addiscount_pro.h \
    productmain.h \
    codes.h \
    showcategory.h \
    editproducts.h \
    managers.h \
    users.h \
    basket.h \
    basket_product.h \
    buycredit.h \
    man_users.h \
    saleitem.h \
    addsale.h \
    cash_saleee.h

FORMS += \
        mainwindow.ui \
    login_signup.ui \
    login_signup2.ui \
    cashierpage.ui \
    managerpage.ui \
    allproducts.ui \
    addproduct.ui \
    adddiscount_code.ui \
    addiscount_pro.ui \
    showcategory.ui \
    editproducts.ui \
    basket.ui \
    buycredit.ui \
    man_users.ui \
    addsale.ui \
    cash_saleee.ui
