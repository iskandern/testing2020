
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
    WeatherMock weatherMock;

    cpr::Response responseUfa;
    cpr::Response responseMoscow;

    WeatherTestCase() {
        responseUfa.text = R"({"list":[{"main": {"temp": -22}}], "status":"ok"})";
        responseMoscow.text = R"({"list":[{"main": {"temp": -10.08}}], "status":"ok"})";

        responseUfa.status_code = 200;
        responseMoscow.status_code = 200;
    }

    virtual ~WeatherTestCase(){ }
};

